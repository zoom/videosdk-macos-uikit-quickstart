//
//  ZMMTCameraControlHelper.h
//  VideoUIBridge
//
//  Camera Control Helper
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMMTConstants.h>

@class ZMConfSession;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTCameraControlHelper : ZMBaseHelper

- (BOOL)isValidSession:(ZMConfSession*)session;
- (ZMUserID)whoControlledMyCamera;
- (ZMUserID)whoControlledTheCameraWithUserID:(ZMUserID)userID;
- (void)revokeCameraControlWithUserID:(ZMUserID)userID;

@end

NS_ASSUME_NONNULL_END
