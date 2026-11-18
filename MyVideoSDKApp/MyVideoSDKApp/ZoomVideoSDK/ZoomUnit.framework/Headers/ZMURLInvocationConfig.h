//
//  ZMURLInvocationConfig.h
//  ZoomUnit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const ZMURLInvocationDefaultScheme;
extern NSString * const ZMURLInvocationRouterHost;

extern NSString * const ZMURLInvocationModuleNameShared;
extern NSString * const ZMURLInvocationModuleNamePT;
extern NSString * const ZMURLInvocationModuleNameMT;

typedef NS_ENUM(NSInteger, ZMURLInvocationSource) {
    ZMURLInvocationSourceUnknown    = 0,
    ZMURLInvocationSourceInProcess  = 1,
};

/// Configuration object for ZMURLInvocationCenter.
///
/// URL format:
///   <scheme>://router/<module>/<featurePath>?payload={"actionName":"...","args":{...}}
@interface ZMURLInvocationConfig : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *scheme;

+ (instancetype)defaultConfig;
- (instancetype)initWithScheme:(NSString *)scheme NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
