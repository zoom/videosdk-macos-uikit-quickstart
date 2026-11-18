//
//  ZMURLInvocationRequest.h
//  ZoomUnit
//
//  Parsed representation of an inbound URL invocation.
//

#import <Foundation/Foundation.h>
#import "ZMURLInvocationConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMURLInvocationDescriptor;

/// Reserved query key used to carry the JSON argument payload.
extern NSString * const ZMURLInvocationQueryKeyPayload;    // @"payload"

/// Argument transport mode encoded by the inbound URL.
typedef NS_ENUM(NSInteger, ZMURLInvocationPayloadMode) {
    /// JSON mode: URL carries
    /// payload={"args":{...},"callId":"optional"}
    ZMURLInvocationPayloadModeJSON = 1,
};

/// Parsed URL invocation request.
@interface ZMURLInvocationRequest : NSObject

@property (nonatomic, copy, readonly) NSURL *originalURL;
@property (nonatomic, assign, readonly) ZMURLInvocationSource source;

/// Path segments before the final action segment, joined by "/".
@property (nonatomic, copy, readonly, nullable) NSString *featurePath;

@property (nonatomic, assign, readonly) ZMURLInvocationPayloadMode payloadMode;

/// Final path segment.
@property (nonatomic, copy, readonly, nullable) NSString *targetActionName;

/// payload.args
@property (nonatomic, copy, readonly) NSDictionary<NSString *, id> *businessQuery;

/// payload.callId
@property (nonatomic, copy, readonly, nullable) NSString *callId;

/// Reserved control parameters (keys starting with "__").
@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *controlQuery;

@property (nonatomic, strong, readonly, nullable) ZMURLInvocationDescriptor *descriptor;

/// Registered feature target used for handle_url:payload: fallback.
@property (nonatomic, assign, readonly, nullable) Class targetClass;
@property (nonatomic, strong, readonly, nullable) NSError *parseError;

@end

NS_ASSUME_NONNULL_END
