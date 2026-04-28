/**
 * @file ZMVideoSDKRTMSHelper.h
 * @brief This file defines the interfaces for managing real-time media streams
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKRTMSHelper
 * @brief Helper class for managing real-time media streams.
 */
@interface ZMVideoSDKRTMSHelper : NSObject

/**
 * @brief Determines if the session supports the real-time media streams feature.
 * @return YES if the real-time media streams feature is supported. Otherwise, NO.
 */
- (BOOL)isSupportRealTimeMediaStreams;

/**
 * @brief Checks if the current user meets the requirements to start real-time media streams.
 * @note Only the host is permitted to start real-time media streams.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)canStartRealTimeMediaStreams;

/**
 * @brief Starts real-time media streams.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startRealTimeMediaStreams;

/**
 * @brief Pauses real-time media streams.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)pauseRealTimeMediaStreams;

/**
 * @brief Resumes real-time media streams.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)resumeRealTimeMediaStreams;

/**
 * @brief Stops real-time media streams.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopRealTimeMediaStreams;

@end

NS_ASSUME_NONNULL_END
