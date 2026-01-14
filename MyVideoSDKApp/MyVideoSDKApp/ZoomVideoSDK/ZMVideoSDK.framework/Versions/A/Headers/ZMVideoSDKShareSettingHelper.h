/**
 * @file ZMVideoSDKShareSettingHelper.h
 * @brief Interface for managing share settings in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKShareSettingHelper
 * @brief Helper class to manage share-related settings.
 */
@interface ZMVideoSDKShareSettingHelper : NSObject

/**
 * @brief Sets screen capture mode.
 * @param captureMode The mode to be set.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setScreenCaptureMode:(ZMVideoSDKScreenCaptureMode)captureMode;

/**
 * @brief Gets the screen capture mode.
 * @param captureMode The screen capture mode.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)getScreenCaptureMode:(ZMVideoSDKScreenCaptureMode*)captureMode;

/**
 * @brief Sets the green border's visibility when sharing the screen.
 * @param bEnable YES to display the green border, NO to hide.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableGreenBorder:(BOOL)bEnable;

/**
 * @brief Determines if the green border is enabled when user shares the screen.
 * @return YES if the green border is enabled. Otherwise, NO.
 */
- (BOOL)isGreenBorderEnabled;
@end

NS_ASSUME_NONNULL_END
