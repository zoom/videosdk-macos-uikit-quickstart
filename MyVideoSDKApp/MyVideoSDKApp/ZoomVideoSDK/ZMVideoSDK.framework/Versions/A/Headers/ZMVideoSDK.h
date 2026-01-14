/**
 * @file ZMVideoSDK.h
 * @brief Main header file for the Zoom Video SDK.
 *
 * This file provides the core interfaces for initializing the SDK,
 * managing video sessions, handling audio/video/chat, and accessing helper components.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDelegate.h>
#import <ZMVideoSDK/ZMVideoSDKAudioHelper.h>
#import <ZMVideoSDK/ZMVideoSDKVideoHelper.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>
#import <ZMVideoSDK/ZMVideoSDKShareHelper.h>
#import <ZMVideoSDK/ZMVideoSDKLiveStreamHelper.h>
#import <ZMVideoSDK/ZMVideoSDKChatHelper.h>
#import <ZMVideoSDK/ZMVideoSDKSession.h>
#import <ZMVideoSDK/ZMVideoSDKVideoSourceHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAudioSendRawdata.h>
#import <ZMVideoSDK/ZMVideoSDKChatMessage.h>
#import <ZMVideoSDK/ZMVideoSDKPasswordHandler.h>
#import <ZMVideoSDK/ZMVideoSDKRecordingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKPhoneHelper.h>
#import <ZMVideoSDK/ZMVideoSDKCmdChannel.h>
#import <ZMVideoSDK/ZMVideoSDKAudioSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKNetworkConnectionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKRecordingConsentHandler.h>
#import <ZMVideoSDK/ZMVideoSDKVideoSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKShareSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKVideoCanvas.h>
#import <ZMVideoSDK/ZMVideoSDKCRCHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAnnotationHelper.h>
#import <ZMVideoSDK/ZMVideoSDKLiveTranscriptionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKSubSessionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKBroadcastStreamingController.h>
#import <ZMVideoSDK/ZMVideoSDKBroadcastStreamingViewer.h>
#import <ZMVideoSDK/ZMVideoSDKRTMSHelper.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMVideoSDKExtendParams;

/**
 * @class ZMVideoSDKInitParams
 * @brief Initialization parameters for Zoom Video SDK.
 */
@interface ZMVideoSDKInitParams : NSObject
/**
 * @brief Sets client domain of ZOOM Video SDK.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* domain;

/**
 * @brief Prefix of log file name.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* logFilePrefix;

/**
 * @brief Sets whether to enable default log of which the capacity is less than 5M.
 */
@property (nonatomic, assign, readwrite) BOOL enableLog;

/**
 * @brief Sets audio raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode audioRawDataMemoryMode;

/**
 * @brief Sets video raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode videoRawDataMemoryMode;

/**
 * @brief Sets share raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode shareRawDataMemoryMode;

/**
 * @brief Extended parameters.
 */
@property (retain, nonatomic, nullable) ZMVideoSDKExtendParams *extendParams;
@end

/*!
 * @class ZMVideoSDKExtendParams
 * @brief Extended configuration parameters for Zoom Video SDK.
 */
@interface ZMVideoSDKExtendParams : NSObject
/*!
 * @brief Specify a file path for speaker test.
 * @note Only support mp3 format. The size cannot exceed 1M.
 */
@property (nonatomic, copy, nullable) NSString *speakerTestFilePath;

/**
 * @brief Wrapper type.
 */
@property (nonatomic, assign, readwrite) int wrapperType;

/**
 * @brief Prefer video resolution.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKPreferVideoResolution preferVideoResolution;

/**
 * @brief Disable access keychain.
 */
@property (nonatomic, assign, readwrite) BOOL disableKeychainAccess;
@end


/**
 * @class ZMVideoSDKVideoOption
 * @brief Video configuration options for joining a session.
 */
@interface ZMVideoSDKVideoOption : NSObject
/**
 * @brief Sets local video on or off.
 */
@property (nonatomic, assign, readwrite) BOOL localVideoOn;
@end

/**
 * @class ZMVideoSDKAudioOption
 * @brief Audio configuration options for joining a session.
 */
@interface ZMVideoSDKAudioOption : NSObject
/**
 * @brief Whether to connect local audio or not.
 */
@property (nonatomic, assign, readwrite) BOOL connect;

/**
 * @brief Whether to mute audio or not.
 */
@property (nonatomic, assign, readwrite) BOOL mute;

/**
 * @brief Determines whether my voice is in the mixed audio raw data or not. YES to include. No to exclude.
 */
@property (nonatomic, assign, readwrite) BOOL isMyVoiceInMix;

/**
 * @brief Whether to automatically adjust the speaker's volume or not. If YES, this automaticallies adjust the volume if it is muted or low. If NO it nots.
 */
@property (nonatomic, assign, readwrite) BOOL autoAdjustSpeakerVolume;

@end

/**
 * @class ZMVideoSDKSessionContext
 * @brief Session context information for a Zoom Video SDK session.
 */
@interface ZMVideoSDKSessionContext : NSObject

/**
 * @brief Session name.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* sessionName;

/**
 * @brief Session password (optional).
 */
@property (nonatomic, retain, readwrite, nullable) NSString* sessionPassword;

/**
 * @brief User name(required).
 */
@property (nonatomic, retain, readwrite, nullable) NSString* userName;

/**
 * @brief JWT token to join session.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* token;

/**
 * @brief Video option.
 */
@property (nonatomic, retain, readwrite, nullable) ZMVideoSDKVideoOption* videoOption;

/**
 * @brief Audio option.
 */
@property (nonatomic, retain, readwrite, nullable) ZMVideoSDKAudioOption* audioOption;

/**
 * @brief Sets delegate. (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVideoSourcePreProcessor> preProcessor;
/**
 * @brief Sets delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVideoSource> externalVideoSource;
/**
 * @brief Sets virtual audio delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVirtualAudioMic> virtualAudioMic;
/**
 * @brief Sets virtual audio speaker delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVirtualAudioSpeaker> virtualAudioSpeaker;
/**
 * @brief [Optional] The amount of time in minutes after which an idle session ends.
 * @note When there is only one user remaining in a session, that session is considered idle.
 * @note Default value: 40. If the value is less than 0, the session will stay alive indefinitely.
 */
@property (nonatomic, assign, readwrite) unsigned int sessionIdleTimeoutMins;
/**
 * @brief Whether to automatically load multi streams when entering a session, default value is YES, optional.
 */
@property (nonatomic, assign, readwrite) BOOL autoLoadMutliStream;
@end


/**
 * @class ZMVideoSDK
 * @brief Zoom Video SDK API manager. Main singleton object that controls the video session creation, event callbacks and other main features of video SDK.
 */
@interface ZMVideoSDK : NSObject

/**
 * @brief Returns ZMVideoSDK instance.
 * @return If the function succeeds, it returns ZMVideoSDK instance. Otherwise, this function fails and returns nil.
 */
+ (ZMVideoSDK*)sharedVideoSDK;
    
/**
 * @brief Initializes the Zoom Video SDK with the appropriate parameters.
 * @param params An initialization parameter object containing all required configuration fields.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)initialize:(ZMVideoSDKInitParams*)params;
    
/**
 * @brief Clean up Zoom Video SDK.
 */
- (void)cleanUp;
    
/**
 * @brief Registers a listener for session events.
 * @param listener A listener class that groups together all the callbacks related to a session.
 */
- (void)addListener:(id <ZMVideoSDKDelegate>)listener;
    
/**
 * @brief Unregisters a listener for session events.
 * @param listener A listener class that groups together all the callbacks related to a session.
 */
- (void)removeListener:(id <ZMVideoSDKDelegate>)listener;
    
/**
 * @brief Joins a session with the appropriate ZMVideoSDKSessionContext parameters. When successful, the SDK attempts to join a session. Use the callbacks in the listener to confirm whether the SDK actually joined.
 * @param params A session context object containing all parameters to join the session.
 * @return If the function succeeds, it returns the session object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKSession* _Nullable)joinSession:(ZMVideoSDKSessionContext*)params;
    
/**
 * @brief Leaves a session previously joined through joinSession method call. When successful, the SDK attempts to leave a session. Use the callbacks in the listener to confirm whether the SDK actually left.
 * @param end YES if the host should end the entire session, or NO if the host should just leave the session.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)leaveSession:(BOOL)end;
    
/**
 * @brief Returns the current session information.
 * @return If the function succeeds, it returns a session object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKSession*)getSessionInfo;
    
/**
 @brief Checks if there is an active session between participants.
 @return YES if in session. Otherwise, NO.
 */
- (BOOL)isInSession;
    
/**
 * @brief Returns Zoom SDK internal version.
 * @return If the function succeeds, it returns sdk version. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getSDKVersion;

/**
 * @brief Exports a log file to local disk.
 * @return If the function succeeds, it returns the exported log file path. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)exportLog;

/**
 * @brief Cleans all exported logs.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)cleanAllExportedLogs;

/**
 * @brief Returns an instance to manage audio controls related to the current video SDK session.
 * @return If the function succeeds, it returns  a ZMVideoSDKAudioHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKAudioHelper*)getAudioHelper;
    
/**
 * @brief Returns an instance to manage cameras and video during a video SDK session.
 * @return If the function succeeds, it returns  a ZMVideoSDKVideoHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoHelper*)getVideoHelper;
    
/**
 * @brief Returns an instance to manage users present in a video SDK session.
 * @return If the function succeeds, it returns  a ZMVideoSDKUserHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKUserHelper*)getUserHelper;
    
/**
 * @brief Returns an instance to manage screen sharing during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKShareHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKShareHelper*)getShareHelper;
    
/**
 * @brief Returns an instance to manage live streaming during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKLiveStreamHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKLiveStreamHelper*)getLiveStreamHelper;
    
/**
 * @brief Returns an instance to send and receive chat messages within video SDK session participants.
 * @return If the function succeeds, it returns a ZMVideoSDKChatHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKChatHelper*)getChatHelper;

/**
 * @brief Returns an instance to manage cloud recordings during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKRecordingHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRecordingHelper*)getRecordingHelper;

/**
 * @brief Returns an instance to use command channel features during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKCmdChannel instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKCmdChannel*)getCmdChannel;

/**
 * @brief Returns an instance to manage phone invitations during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKPhoneHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKPhoneHelper*)getPhoneHelper;

/**
 * @brief Returns an instance to manage audio setting during or before a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKAudioSettingHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKAudioSettingHelper*)getAudioSettingHelper;

/**
 * @brief Returns an instance to manage audio device test during or before a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKAudioDeviceTestHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKAudioDeviceTestHelper*)getAudioDeviceTestHelper;

/**
 * @brief Returns an instance to manage network connection during or before a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKNetworkConnectionHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKNetworkConnectionHelper*)getNetworkConnectionHelper;

/**
 * @brief Gets video setting helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKVideoSettingHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoSettingHelper*)getVideoSettingHelper;

/**
 * @brief Gets share setting helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKShareSettingHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKShareSettingHelper*)getShareSettingHelper;

/**
 * @brief Gets crc helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKCRCHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKCRCHelper*)getCRCHelper;

/**
 * @brief Gets live transcription helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKLiveTranscriptionHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKLiveTranscriptionHelper*)getLiveTranscriptionHelper;

/**
 * @brief Gets incoming live stream helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKIncomingLiveStreamHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKIncomingLiveStreamHelper*)getIncomingLiveStreamHelper;

/**
 * @brief Gets the subsession helper object.
 * @return If the function succeeds, it returns a ZMVideoSDKSubSessionHelper instance. Otherwise, this function fails and returns nil.
 * @note Only host and manager can call this interface.
 */
- (ZMVideoSDKSubSessionHelper* _Nullable)getSubSessionHelper;

/**
 * @brief Gets the broadcast streaming controller object.
 * @return The broadcast streaming controller object if available. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKBroadcastStreamingController* _Nullable)getBroadcastStreamingController;

/**
 * @brief Gets the broadcast streaming viewer object.
 * @return The broadcast streaming viewer object if available. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKBroadcastStreamingViewer* _Nullable)getBroadcastStreamingViewer;

/**
 * @brief Returns an instance to manage RTMS (Real-Time Media Streams) during a video SDK session.
 * @return If the function succeeds, it returns a ZMVideoSDKRTMSHelper instance. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRTMSHelper* _Nullable)getRealTimeMediaStreamsHelper;
@end
NS_ASSUME_NONNULL_END
