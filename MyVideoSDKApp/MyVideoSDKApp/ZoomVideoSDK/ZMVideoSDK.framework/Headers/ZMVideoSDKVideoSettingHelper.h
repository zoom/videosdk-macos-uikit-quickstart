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

/**
 * @brief Enables or disables the face beauty effect for the video stream.
 * @param enable YES to enable the face beauty effect, NO to disable it.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableFaceBeautyEffect:(BOOL)enable;

/**
 * @brief Determines whether the face beauty effect is currently enabled.
 * @return YES if the face beauty effect is enabled. Otherwise, NO.
 */
- (BOOL)isFaceBeautyEffectEnabled;

/**
 * @brief Sets the intensity level of the face beauty effect (the strength value).
 * @param strengthValue The desired face beauty strength value (0-100).
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note The face beauty effect must be enabled before adjusting its strength.
 */
- (ZMVideoSDKErrors)setFaceBeautyStrengthValue:(unsigned int)strengthValue;

/**
 * @brief Retrieves the current intensity level of the face beauty effect (the strength value).
 * @return The current face beauty strength value (0-100).
 * @note A higher value indicates a stronger beauty effect.
 */
- (unsigned int)getFaceBeautyStrengthValue;
@end

NS_ASSUME_NONNULL_END
