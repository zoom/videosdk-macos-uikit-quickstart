//
//  ZMURLExposable.h
//  ZoomUnit
//
//  Optional contract for URL-routable classes.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMURLExposable <NSObject>
@optional

/// Concrete instance the URL invocation framework should dispatch selectors
/// against.
+ (id)zm_urlSharedTarget;

/// Synthesized by @zm_request inside @implementation.
+ (NSDictionary<NSString *, NSString *> *)zm_urlRequestInfo;

/// Fallback handler when no @zm_action selector matches.
- (id)handle_url:(NSString *)action payload:(NSDictionary *)payload;

@end

NS_ASSUME_NONNULL_END
