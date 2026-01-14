/**
 * @file ZMVideoSDKAudioSettingHelper.h
 * @brief Interfaces for audio device test and audio setting controls.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKAudioDeviceTestHelper
 * @brief Interface for testing audio input and output devices.
 */
@interface ZMVideoSDKAudioDeviceTestHelper : NSObject
/**
 * @brief Starts the microphone test. This starts recording the input from the mic. Once the recording is complete, stopMicTestRecording must be called to finish the recording.
 * @param deviceID Specify to test a microphone device. If the param is a wrong microphone ID, the SDK returns an error, otherwise the SDK tests the specified device and sets it as selected.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note The SDK will test the default device if no parameter is input.
 */
- (ZMVideoSDKErrors)startMicTestRecording:(NSString *)deviceID;
    
/**
 * @brief Stops the microphone test. Before calling this, successfully start the microphone test by calling startMicTestRecording. Otherwise this returns an error.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopMicTestRecording;
    
/**
 * @brief Plays the microphone recorded sound. Complete a microphone test by successfully executing startMicTestRecording and stopMicTestRecording before calling this. Otherwise this returns an error.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)playMicTestRecording;

/**
 * @brief Starts the speaker test.
 * @param deviceID Specify to test a speaker device. If the param is a wrong speaker ID, the SDK returns an error, otherwise the SDK tests the specified device and sets it as selected.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note The SDK will test the default device if no parameter is input.
 */
- (ZMVideoSDKErrors)startSpeakerTest:(nullable NSString *)deviceID;
    
/**
 * @brief Stops the speaker test. Before calling this, successfully start the speaker test by calling startSpeakerTest. Otherwise this returns an error.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopSpeakerTest;
    
/**
 * @brief Sets the time interval for the audio test.
 * @param timerInterval Usually the SDK sends the mic and speaker volumes every 200 ms by default via onMicSpeakerVolumeChanged:(unsigned int)micVolume speakerVolume:. This function modifies the time interval instead of 200, default is 200 ms. Accepted values between 50 to 1000 milliseconds.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note This interface will stop the mic or speaker test (if there is on ongoing). As a best practice, call it before the audio test.
 */
- (ZMVideoSDKErrors)setTimerInterval:(unsigned int)timerInterval;
@end

/**
 * @class ZMVideoSDKAudioSettingHelper
 * @brief Interface for managing audio settings in Zoom Video SDK.
 */
@interface ZMVideoSDKAudioSettingHelper : NSObject
    
/**
 * @brief Gets the suppress background noise level.
 * @param level The suppress background noise level.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)getSuppressBackgroundNoiseLevel:(ZMVideoSDKSuppressBackgroundNoiseLevel*)level;
    
/**
 * @brief Sets the suppress background noise level.
 * @param level The suppress background noise level.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setSuppressBackgroundNoiseLevel:(ZMVideoSDKSuppressBackgroundNoiseLevel)level;
    
/**
 * @brief Enables or disables the original input of mic.
 * @param bEnable YES to enable the microphone's original input or NO to disable it.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableMicOriginalInput:(BOOL)bEnable;
    
/**
 * @brief Determines whether the microphone's original input is enabled.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)isMicOriginalInputEnable:(BOOL*)bEnable;
    
/**
 * @brief Sets whether to enable the function of high fidelity music mode or not.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableHighFidelityMusicMode:(BOOL)bEnable;

/**
 * @brief Checks whether the high fidelity music mode is enabled or not.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)isHighFidelityMusicModeEnable:(BOOL*)bEnable;

/**
 * @brief Sets whether to disable the function of echo cancellation or not.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableEchoCancellation:(BOOL)bEnable;

/**
 * @brief Checks whether the echo cancellation is enabled or not.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)isEchoCancellationEnable:(BOOL*)bEnable;

/**
 * @brief Sets whether to enable stereo audio.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableStereoAudio:(BOOL)bEnable;

/**
 * @brief Checks whether the stereo audio is enabled or not.
 * @param bEnable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)isStereoAudioEnable:(BOOL*)bEnable;

/**
 * @brief Gets the echo cancellation level.
 * @param level The echo cancellation level.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)getEchoCancellationLevel:(ZMVideoSDKEchoCancellationLevel*)level;

/**
 * @brief Sets the echo cancellation level.
 * @param level The echo cancellation level to be set.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setEchoCancellationLevel:(ZMVideoSDKEchoCancellationLevel)level;

/**
 * @brief Enables or disables the auto adjust input of microphone volume.
 * @param bEnable YES to enable auto adjust input, NO to disable it.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableAutoAdjustMicVolume:(BOOL)bEnable;

/**
 * @brief Determines whether the microphone's original input volume is enabled.
 * @param bEnable YES if enabled, NO otherwise.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)isAutoAdjustMicVolumeEnabled:(BOOL*)bEnable;

@end

NS_ASSUME_NONNULL_END
