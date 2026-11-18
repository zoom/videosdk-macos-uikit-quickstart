//
//  ZMURLInvocationError.h
//  ZoomUnit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ZMURLInvocationErrorDomain;

typedef NS_ERROR_ENUM(ZMURLInvocationErrorDomain, ZMURLInvocationErrorCode) {
    ZMURLInvocationErrorUnknown                = 1000,

    /// URL does not match <scheme>://router/<featurePath>/<actionName>.
    ZMURLInvocationErrorMalformedURL             = 1001,

    ZMURLInvocationErrorSchemeMismatch           = 1002,
    ZMURLInvocationErrorHostMismatch             = 1003,

    /// featurePath has no registered target.
    ZMURLInvocationErrorFeatureNotFound          = 1010,

    /// action not found under the resolved feature target.
    ZMURLInvocationErrorActionNotFound           = 1011,

    /// Multiple actions match and cannot be disambiguated.
    ZMURLInvocationErrorAmbiguousAction          = 1012,

    ZMURLInvocationErrorUnsupportedParameterType = 1030,
    ZMURLInvocationErrorBodyDecodingFailed       = 1040,

    /// payload is missing/invalid, or actionName/args shape invalid.
    ZMURLInvocationErrorInvalidPayload           = 1041,

    ZMURLInvocationErrorInvalidExtraArguments    = 1042,
    ZMURLInvocationErrorUnsupportedReturnType    = 1052,
    ZMURLInvocationErrorTargetNotRegistered      = 1050,
    ZMURLInvocationErrorInvocationFailed         = 1051,
    ZMURLInvocationErrorCallTimeout              = 1060,
    ZMURLInvocationErrorCallIdNotFound           = 1061,
};

extern NSError *ZMURLInvocationMakeError(ZMURLInvocationErrorCode code, NSString * _Nullable message);

extern NSError *ZMURLInvocationMakeErrorWithUnderlying(ZMURLInvocationErrorCode code,
                                                       NSString * _Nullable message,
                                                       NSError * _Nullable underlying);

NS_ASSUME_NONNULL_END
