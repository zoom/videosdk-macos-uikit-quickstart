//
//  ZMURLExposeMacro.h
//  ZoomUnit
//
//  Convenience macros for featurePath-based URLInvocation registration.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMMacroUtil.h>
#import <ZoomUnit/ZMURLExposable.h>
#import <ZoomUnit/ZMURLInvocationCenter.h>

#pragma mark - @zm_request / @zm_action

// Place both macros inside the target class's @implementation block:
//
//   @implementation ZMJoinMeetingFeatureHandler
//   @zm_request(@"meeting", @"joining-meeting/preview")
//   @zm_action(@"debug", @selector(debugWithPayload:))
//   @end
//
// @zm_request emits a +load so the handler self-registers at image load time
// (keeps late-loaded modules covered; the center's objc_getClassList scan is a
// fallback). moduleName is optional; omitting it defaults to an empty string
// and the URL is routed purely by featurePath.
//
// If the class ALREADY defines its own +load, use @zm_request_selfload instead
// (it emits metadata only, no +load, so there is no duplicate-+load compile
// error). Such a class MUST self-register by calling
// [[ZMURLInvocationCenter shared] registerHandlerClass:self] from its +load.
#define zm_request(...) \
    zm_request_pick(__VA_ARGS__, zm_request_two, zm_request_one)(__VA_ARGS__)

#define zm_request_pick(_1, _2, NAME, ...) NAME

#define zm_request_two(moduleNameExpr, featurePathExpr) \
    zm_request_impl(moduleNameExpr, featurePathExpr, __COUNTER__)

#define zm_request_one(featurePathExpr) \
    zm_request_impl(@"", featurePathExpr, __COUNTER__)

#define zm_request_impl(moduleNameExpr, featurePathExpr, counter) \
    zm_request_impl_(moduleNameExpr, featurePathExpr, counter)

// Metadata + auto +load self-registration.
#define zm_request_impl_(moduleNameExpr, featurePathExpr, counter) \
    zm_request_meta_(moduleNameExpr, featurePathExpr, counter) \
    + (void)load { \
        [[ZMURLInvocationCenter shared] registerHandlerClass:self]; \
    }

// @zm_request_selfload: metadata ONLY, no +load. For classes that already
// define +load and self-register via -registerHandlerClass: from there.
#define zm_request_selfload(...) \
    zm_request_selfload_pick(__VA_ARGS__, zm_request_selfload_two, zm_request_selfload_one)(__VA_ARGS__)

#define zm_request_selfload_pick(_1, _2, NAME, ...) NAME

#define zm_request_selfload_two(moduleNameExpr, featurePathExpr) \
    zm_request_meta(moduleNameExpr, featurePathExpr, __COUNTER__)

#define zm_request_selfload_one(featurePathExpr) \
    zm_request_meta(@"", featurePathExpr, __COUNTER__)

#define zm_request_meta(moduleNameExpr, featurePathExpr, counter) \
    zm_request_meta_(moduleNameExpr, featurePathExpr, counter)

// Shared metadata emission (compatibility_alias + zm_urlRequestInfo getter).
#define zm_request_meta_(moduleNameExpr, featurePathExpr, counter) \
    compatibility_alias ZMURLInvocationRequestMacroAlias_##counter NSObject; \
    + (NSDictionary<NSString *, NSString *> *)zm_urlRequestInfo { \
        return @{ @"moduleName" : (moduleNameExpr), \
                  @"featurePath" : (featurePathExpr) }; \
    }

#define zm_action(actionNameExpr, selectorExpr) \
    zm_action_(actionNameExpr, selectorExpr, __COUNTER__)

#define zm_action_(actionNameExpr, selectorExpr, counter) \
    zm_action__(actionNameExpr, selectorExpr, counter)

#define zm_action__(actionNameExpr, selectorExpr, counter) \
    compatibility_alias ZMURLInvocationActionMacroAlias_##counter NSObject; \
    + (NSDictionary<NSString *, NSString *> *)zm_urlActionInfo_##counter { \
        return @{ @"actionName" : (actionNameExpr), \
                  @"selectorName" : NSStringFromSelector(selectorExpr) }; \
    }

