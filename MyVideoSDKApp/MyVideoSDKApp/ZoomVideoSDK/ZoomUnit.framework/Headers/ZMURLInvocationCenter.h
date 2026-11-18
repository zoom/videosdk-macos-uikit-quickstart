//
//  ZMURLInvocationCenter.h
//  ZoomUnit
//

#import <Foundation/Foundation.h>
#import "ZMURLInvocationConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMURLInvocationDescriptor;
@class ZMURLInvocationRequest;

/// Response-driven callback used by the feature/action URLInvocation model.
/// When a callback is supplied, the center generates (or reuses) a callId and
/// completes the block from -handleResponse:error: exactly once.
typedef void(^ZMURLRequestCallback)(NSString * _Nullable callId,
                                    id _Nullable result,
                                    NSError * _Nullable error);

@interface ZMURLInvocationCenter : NSObject

+ (instancetype)shared;

+ (void)bootstrap;
+ (void)bootstrapWithConfig:(ZMURLInvocationConfig *)config;

@property (nonatomic, assign, readonly) BOOL isBootstrapped;
@property (nonatomic, copy, readonly) ZMURLInvocationConfig *config;

#pragma mark - Registration

/// Register a single @zm_request handler class. Called from the class's +load
/// (emitted by the @zm_request macro) so handlers self-register at image load
/// time, keeping late-loaded modules covered. Idempotent: safe to call
/// repeatedly and safe to combine with the fallback runtime scan.
- (void)registerHandlerClass:(Class)handlerClass;

#pragma mark - Registry queries

@property (nonatomic, assign, readonly) NSUInteger registeredDescriptorCount;
- (NSArray<ZMURLInvocationDescriptor *> *)allDescriptors;
- (NSArray<ZMURLInvocationDescriptor *> *)descriptorsForModule:(NSString *)moduleName;
- (NSArray<ZMURLInvocationDescriptor *> *)descriptorsForFeaturePath:(NSString *)featurePath;

#if defined(ZOOM_DEBUG)
/// A stable, UI-friendly snapshot of registered URL descriptors.
/// Each item contains: url, module, featurePath, action, selector, callable,
/// and unsupportedReason (NSNull when callable).
- (NSArray<NSDictionary<NSString *, id> *> *)registeredURLItems;
#endif

- (nullable ZMURLInvocationDescriptor *)descriptorForFeaturePath:(NSString *)featurePath
                                                          action:(NSString *)actionName;

- (NSString *)dumpRegisteredURLs;

#pragma mark - URL parsing & invocation

/// Parse `zoomus://router/<featurePath>/<actionName>?payload=<json>`.
/// `payload` is optional; when present it may contain `args` and `callId`.
- (ZMURLInvocationRequest *)parseURL:(NSURL *)url
                              source:(ZMURLInvocationSource)source;

/// Invoke a parsed URL. Returns callId when `callback` is non-nil; otherwise
/// returns nil after fire-and-forget local dispatch.
- (nullable NSString *)invokeURL:(NSURL *)url
                          source:(ZMURLInvocationSource)source
                        callback:(nullable ZMURLRequestCallback)callback
                           error:(out NSError * _Nullable * _Nullable)error;

/// Same as above, but lets the caller provide a stable callId / marker. If
/// non-empty, this value overrides payload.callId and is returned in callback.
- (nullable NSString *)invokeURL:(NSURL *)url
                          source:(ZMURLInvocationSource)source
                          callId:(nullable NSString *)callId
                        callback:(nullable ZMURLRequestCallback)callback
                           error:(out NSError * _Nullable * _Nullable)error;

/// Native entry point for callers that already have `<featurePath>/<action>`.
/// `payload` is passed as the action payload dictionary.
- (nullable NSString *)invokePath:(NSString *)path
                          payload:(nullable NSDictionary<NSString *, id> *)payload
                         callback:(nullable ZMURLRequestCallback)callback;

/// Native entry point with caller-provided callId / marker.
- (nullable NSString *)invokePath:(NSString *)path
                          payload:(nullable NSDictionary<NSString *, id> *)payload
                           callId:(nullable NSString *)callId
                         callback:(nullable ZMURLRequestCallback)callback;

/// Complete a pending callback by `response.callId`.
- (BOOL)handleResponse:(NSDictionary *)response
                 error:(out NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
