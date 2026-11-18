//
//  ZMXProcEventPoster.h
//  ZoomUnit
//
//  One-liner sender for "global notifications" that need to reach every
//  UI process. Each post-site calls a single +postFromPT:/+postToPT: and
//  this class takes care of both:
//    1. Dispatching the matching in-process notification on the caller's
//       side (NSNotificationCenter / ZMEventPosterFor — see
//       +dispatchLocally:userInfo: for the full mapping).
//    2. Publishing the event over ZMXProcEventBus to the peer UI process(es)
//       when multi-process Meeting is enabled; peers receive it via
//       ZMMTXProcEventMgr / ZMPTXProcEventMgr (and future Clips-side mgr)
//       which simply forward back into +dispatchLocally:userInfo: so the
//       processes use a single source of truth for the ID -> in-process
//       action mapping.
//
//  Single-process Meeting builds skip the bus publish (everything is
//  already in the same process image), but the local dispatch still runs
//  so callers see identical observer behaviour regardless of build mode.
//
//  NOTE : +postToMeeting: / +postToMeeting:userInfo: were
//  renamed to +postFromPT: / +postFromPT:userInfo: to align with the
//  hub-direction naming of the underlying ZMXProcEventBus (PT is the IPC
//  hub; UI subprocesses such as Meeting/Clips subscribe to the fromPT
//  fan-out). +postToPT: kept its name — see ZMXProcEventBus.h for the
//  broader rename note covering the SvrId / singleton mapping.
//
//  Copyright (c) Zoom Communications. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMXProcEventDefines.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMXProcEventPosterProtocol<NSObject>
- (void)onXProcEventReceived:(ZMXProcEventID)eventID userInfo:(nullable NSDictionary *)userInfo;
@end

@interface ZMXProcEventPoster : NSObject

/// PT process -> UI subprocess(es) (Meeting / Clips / ...). Dispatches
/// the matching in-process notification locally and, when multi-process
/// Meeting is enabled, also publishes the event on
/// @c +[ZMXProcEventBus fromPTBus] which fans out to every subscribed
/// UI subprocess.
+ (void)postFromPT:(ZMXProcEventID)eventID;
+ (void)postFromPT:(ZMXProcEventID)eventID userInfo:(nullable NSDictionary *)userInfo;

/// UI subprocess (Meeting / Clips / ...) -> PT process. Dispatches the
/// matching in-process notification locally and, when multi-process
/// Meeting is enabled, also publishes the event on
/// @c +[ZMXProcEventBus toPTBus].
+ (void)postToPT:(ZMXProcEventID)eventID;
+ (void)postToPT:(ZMXProcEventID)eventID userInfo:(nullable NSDictionary *)userInfo;

/// Apply an event to the current process only — fans the @c eventID out
/// to the matching @c NSNotificationCenter notification or
/// @c ZMEventPosterFor() protocol method. Intended for the bus-side
/// receive managers (@c ZMMTXProcEventMgr / @c ZMPTXProcEventMgr) to
/// re-broadcast a payload that arrived from a peer UI process; regular
/// senders should use @c +postFromPT: / @c +postToPT: which call this
/// method internally.
+ (void)dispatchLocally:(ZMXProcEventID)eventID userInfo:(nullable NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
