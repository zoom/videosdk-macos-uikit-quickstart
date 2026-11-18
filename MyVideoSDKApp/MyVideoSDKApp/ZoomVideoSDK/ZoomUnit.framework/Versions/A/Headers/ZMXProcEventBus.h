//
//  ZMXProcEventBus.h
//  ZoomUnit
//
//  URL-relay bridge over the C++ event_bus IPC mesh. Each instance
//  binds to one EventBusSvrId — a unidirectional channel keyed by
//  hub direction (PT is the IPC server and acts as the hub for all
//  UI subprocesses: Meeting, Clips, ...). The +toPTBus aggregates
//  events flowing into PT (fan-in); the +fromPTBus carries events
//  PT broadcasts out (fan-out, 1-to-N).
//
//  Subscriber decodes the envelope and hands the URL to
//  ZMURLInvocationCenter; publisher fires-and-forgets or awaits a
//  reply via @c reverseBus.
//
//  -start is required on the subscriber side AFTER InitEventBus().
//  Publishers do not need -start.
//
//  NOTE : the singletons and their backing service IDs
//  were renamed from a peer-pair naming to a hub-direction naming so the
//  channel can carry events for additional UI subprocesses (Clips, ...):
//    +meetingToPTBus                                  -> +toPTBus
//    +ptToMeetingBus                                  -> +fromPTBus
//    EventBusSvrId::MeetingToPTBridgeService (= 24)   -> XProcUIToPTService
//    EventBusSvrId::PTToMeetingBridgeService (= 25)   -> XProcUIFromPTService
//  Numeric SvrId values are unchanged, so the on-wire IPC contract stays
//  binary-compatible with older clients during the cross-version rollout.
//
//  Copyright (c) Zoom Communications. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Error domain for @c -publishCallToPath:payload:completion: failures.
FOUNDATION_EXPORT NSErrorDomain const ZMXProcEventBusErrorDomain;

typedef NS_ERROR_ENUM(ZMXProcEventBusErrorDomain, ZMXProcEventBusErrorCode) {
    /// event_bus rejected the publish (IPC not connected, envelope
    /// build failed, etc.). Completion fires on the next main runloop.
    ZMXProcEventBusErrorPublishFailed     = -1,
    /// No reply within the default timeout (30 s).
    ZMXProcEventBusErrorTimeout           = -2,
    /// The publishing bus was stopped before the reply arrived.
    ZMXProcEventBusErrorCancelled         = -3,
    /// @c reverseBus is not configured on this bus.
    ZMXProcEventBusErrorReverseBusMissing = -4,
    /// Remote side returned an error. The relayed domain/code/message
    /// are preserved in @c userInfo.
    ZMXProcEventBusErrorRemoteFailure     = -5,
};

/// Completion block for callback-style cross-process calls. Always
/// invoked on the main thread exactly once. @c result is JSON-decoded
/// (NSString / NSNumber / NSArray / NSDictionary / NSNull) or nil.
typedef void(^ZMXProcCallCompletion)(id _Nullable result, NSError * _Nullable error);

@interface ZMXProcEventBus : NSObject

/// Binds the instance to @c serviceId (an @c event_bus::EventBusSvrId
/// value). Must also be whitelisted in @c EventBusUtils.cpp on every
/// peer process.
- (instancetype)initWithServiceId:(uint32_t)serviceId NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) uint32_t serviceId;

/// Bus used to deliver replies for callback-style publishes from
/// @c self. Must be set before @c -publishCallToPath:payload:completion:.
/// The built-in @c +toPTBus / @c +fromPTBus pair is wired
/// automatically. Weak to avoid retain cycles between paired singletons.
@property (nonatomic, weak, nullable) ZMXProcEventBus *reverseBus;

/// Singleton for the "to PT" direction (fan-in). Publish from any UI
/// subprocess (Meeting, Clips, ...); @c -start on the PT side to
/// receive.
+ (instancetype)toPTBus;

/// Singleton for the "from PT" direction (fan-out). Publish from
/// PT-role code; @c -start on every UI subprocess side to receive.
+ (instancetype)fromPTBus;

#pragma mark - Topology-aware subscription helpers

/// PT-side subscriptions. Always starts @c +toPTBus. In single-process
/// Meeting builds also starts @c +fromPTBus locally; in multi-process
/// builds the UI subprocess (Meeting / Clips) owns that bus instead.
/// MUST be called after @c InitEventBus().
+ (void)startPTSideSubscriptions;

/// Meeting subprocess subscriptions. Starts @c +fromPTBus. Only
/// reachable in multi-process builds. MUST be called after
/// @c InitEventBus().
+ (void)startMeetingSideSubscriptions;

/// Clips subprocess subscriptions. Starts @c +fromPTBus. Clips always
/// runs as a separate process (ZoomClips.app, PROCESS_TYPE_PS), so
/// this is unconditional and does not have a 1P/MP gate. MUST be
/// called after @c InitMainboard() — i.e. after the C++ event_bus
/// is up. Functionally identical to
/// @c +startMeetingSideSubscriptions; kept as a distinct entry point
/// so the call site at the Clips bootstrap reads as Clips-owned.
+ (void)startClipsSideSubscriptions;

/// Subscribe the event_bus handler. Idempotent. Required on the
/// receiving side; publishers do not need it.
- (void)start;

- (void)stop;

/// Publish a URL across the bound IPC channel. The receiver dispatches
/// it via @c ZMURLInvocationCenter on its main thread. Returns NO on
/// malformed input or when event_bus is not initialised.
- (BOOL)publishURLString:(NSString *)urlString;

/// Fire-and-forget structured publish. Receiver dispatches via
/// @c -[ZMURLInvocationCenter invokePath:payload:callId:callback:].
/// @c path must contain at least one "/". @c payload must be JSON-safe
/// or nil. Returns NO on validation failure.
- (BOOL)publishCallToPath:(NSString *)path
                  payload:(nullable NSDictionary<NSString *, id> *)payload;

/// Callback-enabled structured publish. @c completion (if non-nil) is
/// GUARANTEED to fire exactly once on the main thread regardless of
/// return value — covering success, timeout, cancelled, publish-
/// failed, reverse-bus-missing, and remote-failure. Default timeout
/// is 30 s. Nil @c completion degrades to fire-and-forget.
- (BOOL)publishCallToPath:(NSString *)path
                  payload:(nullable NSDictionary<NSString *, id> *)payload
               completion:(nullable ZMXProcCallCompletion)completion;

@end

NS_ASSUME_NONNULL_END
