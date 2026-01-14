/**
 * @file ZMVideoSDKVideoSettingHelper.h
 * @brief Declares the interface for managing video settings in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKVideoSettingHelper
 * @brief Provides settings-related functions to configure video enhancement options.
 */
@interface ZMVideoSDKVideoSettingHelper : NSObject

/**
 * @brief Enables or disables temporal video denoising. This process reduces noise between frames of video.
 * @param enable YES to enable the temporal de-noise of video, NO to disable it.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableTemporalDeNoise:(BOOL)enable;

/**
 * @brief Query if the option to optimize video quality with de-noise is enabled.
 * @return YES if temporal video denoising is enabled. Otherwise, NO.
 */
- (BOOL)isTemporalDeNoiseEnabled;
@end

NS_ASSUME_NONNULL_END
