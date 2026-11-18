//
//  ZMURLInvocationDescriptor.h
//  ZoomUnit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMURLInvocationDescriptor : NSObject

/// Internal namespace declared by @zm_request. It is not part of URL routing.
@property (nonatomic, copy, readonly) NSString *moduleName;

/// External feature path, e.g. "joining-meeting/preview".
@property (nonatomic, copy, readonly) NSString *featurePath;

@property (nonatomic, strong, readonly) Class targetClass;
@property (nonatomic, assign, readonly) SEL selector;
@property (nonatomic, copy, readonly) NSString *selectorName;

/// External action name from @zm_action, used as the final URL path segment.
@property (nonatomic, copy, readonly) NSString *exposedActionName;

@property (nonatomic, assign, readonly) BOOL isInstanceMethod;
@property (nonatomic, copy, readonly, nullable) NSString *typeEncoding;
@property (nonatomic, strong, readonly, nullable) NSMethodSignature *methodSignature;

@property (nonatomic, copy, readonly) NSString *templateURLString;
@property (nonatomic, copy, readonly) NSString *placeholderURLString;

@property (nonatomic, copy, readonly, nullable) NSString *unsupportedReason;
@property (nonatomic, assign, readonly) BOOL isCallable;

@end

NS_ASSUME_NONNULL_END
