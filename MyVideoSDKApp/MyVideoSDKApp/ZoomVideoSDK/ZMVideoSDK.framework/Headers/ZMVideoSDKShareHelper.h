/**
 * @file ZMVideoSDKShareHelper.h
 * @brief Defines interfaces and classes for managing screen and window sharing, share preprocessing, remote control, annotation, and audio sharing features in the Zoom Video SDK.
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ZMVideoSDK/ZMVideoSDKAnnotationHelper.h>
#import <ZMVideoSDK/ZMVideoSDKRemoteControlHelper.h>
#import <ZMVideoSDK/ZMVideoSDKWhiteboardHelper.h>
NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKSharePreprocessParam
 * @brief Parameters for share preprocessing including the type and screen or window identifiers.
 */
@interface ZMVideoSDKSharePreprocessParam : NSObject
/**
 * @brief The share pre-process type.
 */
@property(nonatomic,assign)ZMVideoSDKSharePreprocessType type;
/**
 * @brief The screen ID that to share and pre-process.
 */
@property(nonatomic,assign)CGDirectDisplayID monitorID;
/**
 * @brief The window handle that to share and pre-process.
 */
@property(nonatomic,assign)CGWindowID windowID;
/**
 * @brief The application process ID that to share and pre-process.
 */
@property(nonatomic,assign)pid_t processID;
@end


/**
 * @class ZMVideoSDKSharePreprocessSender
 * @brief Interface to send preprocessed YUV raw data frames back to the SDK.
 */
@interface ZMVideoSDKSharePreprocessSender : NSObject
/**
 * @brief Sends preprocessed data.
 * @param rawdata The processed data object.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendPreprocessedData:(ZMVideoSDKYUVRawDataI420*)rawdata;
@end


/**
 * @protocol ZMVideoSDKSharePreprocessor
 * @brief Protocol to handle preprocessing of raw share data before sending it out. Implement this protocol to receive raw YUV data frames during screen sharing for custom preprocessing.
 */
@protocol ZMVideoSDKSharePreprocessor <NSObject>
/**
 * @brief You receives this callback when calling 'startShareWithPreprocessing' successfully.
 * @param rawdata Get the YUV data address through this object and then pre-process the data.
 * @param sender Use this object to send the processed data out.
 */
- (void)onCapturedRawDataReceived:(ZMVideoSDKYUVRawDataI420*)rawdata sharePreprocessSender:(ZMVideoSDKSharePreprocessSender * _Nonnull)sender;

/**
 * @brief You receives this callback when call 'stopShare' successfully. In this event notification, perform some stop and destroy actions if necessary.
 */
- (void)onShareStopped;
@end


/**
 * @class ZMVideoSDKShareAction
 * @brief Represents the state and control interfaces of a share action in a Zoom session.
 */
@interface ZMVideoSDKShareAction : NSObject
/**
 * @brief Share source ID.
 */
@property (nonatomic, assign, readonly) unsigned int                  shareSourceId;
/**
 * @brief Share status.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareStatus         shareStatus;
/**
 * @brief Share type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareType           shareType;
/**
 * @brief Gets the reason why the share capture is paused.
 * @note If sharing is not paused, it returns @c ZMVideoSDKShare_Capture_Pause_None.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareCapturePauseReason shareCapturePauseReason;

/**
 * @brief The subscribe fail reason.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKSubscribeFailReason subscribeFailReason;
/**
 * @brief Determines whether annotation privilege is enabled.
 */
@property (nonatomic, assign, readonly) BOOL                          isAnnotationPrivilegeEnabled;

/**
 * @brief Gets the share content's size.
 * @return The share content's size.
 */
- (NSSize)getShareSourceContentSize;

/**
 * @brief Gets the share raw data pipe.
 * @return If the function succeeds, it returns the share pipe object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRawDataPipe* _Nullable)getSharePipe;

/**
 * @brief Gets the render canvas object.
 * @return If the function succeeds, it returns the ZMVideoSDKVideoCanvas object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoCanvas* _Nullable)getShareCanvas;

/**
 * @brief Gets the helper class instance to access remote control. Only available for controller side.
 * @return If the function succeeds, it returns the remote control helper object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRemoteControlHelper* _Nullable)getRemoteControlHelper;

/**
 * @brief Gets the list of users I (the controlling user) have agreed to control. Only available for the controlling user.
 * @return If the function succeeds, it returns the list of users I have agreed to control. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getRemoteControlApprovedUserList;

/**
 * @brief Gets back all the authority of remote control. Only available for the user themselves.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)revokeRemoteControl;

/**
 * @brief Gets the controller ID who is currently controlling me (the controlled user). Only available for the controlled user.
 * @return If the function succeeds, it returns the user currently controlling by long-distance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKUser * _Nullable)getCurrentRemoteController;

@end



/**
 * @class ZMVideoSDKShareSender
 * @brief Interface to send video share frame data.
 */
@interface ZMVideoSDKShareSender : NSObject

/**
 * @brief Sends one frame data.
 * @param frameBuffer FrameBuffer YUVI420 buffer.
 * @param width Frame width.
 * @param height Frame height.
 * @param frameLength Buffer length.
 * @param format Raw data format.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendShareFrame:(char* _Nullable)frameBuffer width:(int)width height:(int)height frameLength:(int)frameLength format:(ZMVideoSDKFrameDataFormat)format;
@end


/**
 * @protocol ZMVideoSDKShareSource
 * @brief Protocol for external share source to send raw data.
 */
@protocol ZMVideoSDKShareSource <NSObject>
/**
 * @brief Callback for share source can start send raw data.
 * @param sender The object used to send share data.
 */
- (void)onShareSendStarted:(ZMVideoSDKShareSender* _Nonnull)sender;
/**
 * @brief Callback for share source stop send raw data.
 */
- (void)onShareSendStopped;
@end


/**
 * @class ZMVideoSDKShareAudioSender
 * @brief Interface to send share audio raw data.
 */
@interface ZMVideoSDKShareAudioSender : NSObject
/**
 * @brief Sends audio raw data.
 * @param data The audio data address.
 * @param length The audio data length. It must be even numbers.
 * @param rate The audio data sampling rate.
 * @param channel The channel type. Default type is ZoomVideoSDKAudioChannel_Mono.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note Support sample Rate 44100, 48000, 50000, or 50400.
 */
- (ZMVideoSDKErrors)sendShareAudio:(char * _Nullable)data dataLength:(unsigned int)length sampleRate:(int)rate audioChannel:(ZMVideoSDKAudioChannel)channel;
@end


/**
 * @protocol ZMVideoSDKShareAudioSource
 * @brief Protocol for external share audio source.
 */
@protocol ZMVideoSDKShareAudioSource <NSObject>

/**
 * @brief Callback for audio source to start sending raw data.
 * @param sender The object used to send raw audio data.
 */
- (void)onStartSendAudio:(ZMVideoSDKShareAudioSender * _Nonnull)sender;

/**
 * @brief Callback for audio source to stop sending raw data.
 */
- (void)onStopSendAudio;
@end


/**
 * @class ZMVideoSDKShareOption
 * @brief Configuration options for sharing.
 */
@interface ZMVideoSDKShareOption : NSObject
/**
 * @brief Share option, YES indicates share computer sound when sharing screen or window. Otherwise, NO.
 */
@property (nonatomic, assign, readwrite) BOOL isWithDeviceAudio;

/**
 * @brief Share option, YES indicates optimize the frame rate when sharing screen or window. Otherwise, NO.
 */
@property (nonatomic, assign, readwrite) BOOL isOptimizeForSharedVideo;

@end


/**
 * @class ZMVideoSDKShareHelper
 * @brief Main helper class managing sharing.
 */
@interface ZMVideoSDKShareHelper : NSObject

/**
 * @brief Starts Share a window.
 * @param windowID The App window ID.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note The CGWindowID contains a unique value within the user session representing a window.
 */
- (ZMVideoSDKErrors)startShareView:(CGWindowID)windowID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Starts sharing a specific application process.
 * @param processID The target application's process identifier. Must be valid in the current user session.
 * @param option An optional share settings object containing configuration options for the share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise the method failed.
 * @note The @c processID must be a valid process identifier in the current user session.
 */
- (ZMVideoSDKErrors)startShareApplication:(pid_t)processID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Determines if the application's window ID supports sharing.
 * @param windowID The App window ID to be checked.
 * @return YES if the current application window supports sharing. Otherwise, NO.
 */
- (BOOL)isShareViewValid:(CGWindowID)windowID;

/**
 * @brief Starts share screen.
 * @param monitorID The monitor's ID that you want to display the shared content.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startShareScreen:(CGDirectDisplayID)monitorID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Starts share multi-screen.
 * @param monitorIDs The monitor IDs that you want to display the shared content.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startShareMultiScreen:(NSArray <NSNumber *>*)monitorIDs shareOption:(ZMVideoSDKShareOption* _Nullable)option;
 
/**
 * @brief Starts sharing the computer audio only.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startShareComputerAudio;

/**
 * @brief Stops view or screen share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopShare;
  
/**
 * @brief Pauses share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)pauseShare;

/**
 * @brief Resumes share.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)resumeShare;

/**
 * @brief Determines whether the current user is sharing.
 * @return YES if the current user is sharing. Otherwise, NO.
 */
- (BOOL)isSharingOut;
    
/**
 * @brief Determines whether the current user is sharing the screen.
 * @return YES if the current user is sharing the screen. Otherwise, NO.
 */
- (BOOL)isScreenSharingOut;
    
/**
 * @brief Determines whether other user is sharing.
 * @return YES if another user is sharing. Otherwise, NO.
 */
- (BOOL)isOtherSharing;
    
/**
 * @brief Locks sharing the view or screen. Only the host can call this method.
 * @param lock YES to lock sharing, NO to unlock.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)lockShare:(BOOL)lock;
    
/**
 * @brief Determines whether sharing the view or screen is locked.
 * @return YES if that sharing is locked. Otherwise, NO.
 */
- (BOOL)isShareLocked;

/**
 * @brief Enables or disables participants can share simultaneously.
 * @param enable YES to enable, NO to disable.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @warning When you switch multi share from enable to disable, all sharing will be stopped when session has two or more users is sharing.
 */
- (ZMVideoSDKErrors)enableMultiShare:(BOOL)enable;

/**
 * @brief Determines whether multi share is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isMultiShareEnabled;

/**
 * @brief Enables or disables the computer sound when sharing, the SDK does not support sharing raw data audio, for example, when you've enabled virtual speaker.
 * @param enable YES to enable, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableShareDeviceAudio:(BOOL)enable;

/**
 * @brief Determines if the SDK has enabled share computer sound. This reflects the execution status of 'enableShareDeviceAudio' instead of 'startShareComputerAudio'.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isShareDeviceAudioEnabled;

/**
 * @brief Enables or disables the optimization of frame rate. Enable it when there is video in shared content.
 * @param enable YES indicates to enable, NO disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableOptimizeForSharedVideo:(BOOL)enable;

/**
 * @brief Determines if optimization for video is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isOptimizeForSharedVideoEnabled;

/**
 * @brief Starts sharing a camera feed specified by the cameraID as the second camera.
 * @param cameraID The camera ID.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note This cameraID must be a different camera than the one sending your primary video.
 */
- (ZMVideoSDKErrors)startShare2ndCamera:(NSString* _Nullable)cameraID;

/**
 * @brief Subscribes to the camera's raw data stream that is shared as the second camera.
 * @param dataHandler The callback sink object.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @deprecated Use \link ZMVideoSDKRawDataPipe::subscribe:listener: \endlink instead.
 */
- (ZMVideoSDKErrors)subscribeMyShareCamera:(id<ZMVideoSDKRawDataPipeDelegate> _Nonnull)dataHandler DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe subscribe: listener:] instead");

/**
 * @brief Unsubscribes to the camera's raw data stream that is shared as the second camera.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @deprecated Use \link ZMVideoSDKRawDataPipe::unSubscribe: \endlink instead.
 */
- (ZMVideoSDKErrors)unSubscribeMyShareCamera DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe: unSubscribe:] instead");

/**
 * @brief Shares an external source.
 * @param shareSource External share source.
 * @param audioSource External audio source.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note If audioSource is non-null, it means share user-defined audio at the same time.
 * @deprecated Use \link ZMVideoSDKShareHelper::startSharingExternalSource:audioSource:isPlaying: \endlink instead.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharingExternalSource: audioSource: isPlaying: instead");

/**
 * @brief Shares an external source.
 * @param shareSource External share source.
 * @param audioSource External audio source.
 * @param isPlaying YES to play shared audio raw data, NO not to play.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note If audioSource is non-null, it means share user-defined audio at the same time.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource isPlaying:(BOOL)isPlaying;
/**
 * @brief Starts sharing the pure external audio source.
 * @param audioSource The pointer of external audio source object.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @deprecated Use \link ZMVideoSDKShareHelper::startSharePureAudioSource:isPlaying: \endlink instead.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharePureAudioSource: isPlaying: instead");

/**
 * @brief Starts sharing the pure external audio source.
 * @param audioSource The pointer of external audio source object.
 * @param isPlaying YES to play shared audio raw data, NO not to play.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource isPlaying:(BOOL)isPlaying;

/**
 * @brief Whether annotation feature is supported or not.
 * @return YES if support. Otherwise, NO.
 */
- (BOOL)isAnnotationFeatureSupport;

/**
 * @brief Disables or enables viewer's annotation by the share owner.
 * @param disable YES mean disable, NO, mean enable.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @warning Only the share owner can call this function.
 */
- (ZMVideoSDKErrors)disableViewerAnnotation:(BOOL)disable;

/**
 * @brief Whether annotation on current sharing is disabled or not.
 * @return YES if disable. Otherwise, NO.
 * @warning Only the share owner can call this function.
 */
- (BOOL)isViewerAnnotationDisabled;

/**
 * @brief Creates annotation helper based on shared view.
 * @param view The shared view. Pass the nil returns the helper for self sharing.
 * @return If the function succeeds, it returns the object of ZMVideoSDKAnnotationHelper. Otherwise, this function fails and returns nil.
 * @note This method should be called after onUserShareStatusChanged:user:shareAction: reports ZoomVideoSDKShareStatus_Start.
 * @warning When the share owner not  support the feature of annotate, the others should not do annotate in that case.
 * @warning If the video aspect mode is set to ZMVideoSDKVideoAspect_Full_Filled, this function returns nil.
 */
- (ZMVideoSDKAnnotationHelper* _Nullable)createAnnotationHelper:(NSView* _Nullable)view;

/**
 * @brief Destroys annotation helper.
 * @param helper The object of ZMVideoSDKAnnotationHelper.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)destroyAnnotationHelper:(ZMVideoSDKAnnotationHelper* _Nonnull)helper;

/**
 * @brief Sets the vanishing tool time.
 * @param displayTime The time in milliseconds the tool remains visible before fading.
 * @param vanishingTime The time in milliseconds for the tool to fade out after displayTime.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note This setting only takes effect for the user's own share.
 *       The displayTime can be 0 or up to 15000 milliseconds (15 seconds).
 *       The vanishingTime must be greater than 1000 milliseconds (1 second) and less than or equal to 15000 milliseconds (15 seconds).
 */
- (ZMVideoSDKErrors)setAnnotationVanishingToolTime:(unsigned int)displayTime vanishingTime:(unsigned int)vanishingTime;

 /**
  * @brief Gets the current vanishing tool time settings.
  * @param displayTime [out] The time in milliseconds the tool remains visible before fading.
  * @param vanishingTime [out] The time in milliseconds for the tool to fade out after displayTime.
  * @note This function can only retrieve the timer settings for your own share.
  * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
  */
- (ZMVideoSDKErrors)getAnnotationVanishingToolTime:(unsigned int*)displayTime vanishingTime:(unsigned int*)vanishingTime;

/**
 * @brief Enables or disables local playback of shared audio raw data.
 * @param bPlay YES to play shared audio raw data, NO not to play it.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enablePlaySharingAudioRawdata:(BOOL)bPlay;

/**
 * @brief Starts share preprocessing.
 * @param param The share preprocessing parameters.
 * @param preprocessor Object that handles preprocessing events.
 * @return If the function succeeds, it returns  @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startShareWithPreprocessing:(ZMVideoSDKSharePreprocessParam* _Nonnull)param sharePreprocessor:(id<ZMVideoSDKSharePreprocessor> _Nonnull)preprocessor;

/**
 @brief Returns an instance to manage whiteboard during a video SDK session.
 @return If the function succeeds, it returns the whiteboard helper object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKWhiteboardHelper* _Nullable)getWhiteboardHelper;
@end
NS_ASSUME_NONNULL_END
