/**
 * @file ZMVideoSDKAudioHelper.h
 * @brief Provides audio management interfaces for the Zoom Video SDK.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKAudioRawData
 * @brief Represents raw audio data received from the SDK.
 */
@interface ZMVideoSDKAudioRawData : NSObject

/**
 * @brief Buffer data.
 */
@property (nonatomic, assign, readonly, nullable) char* buffer;

/**
 * @brief Buffer length of this data.
 */
@property (nonatomic, assign, readonly) unsigned int bufferLen;

/**
 * @brief Sample rate of this data.
 */
@property (nonatomic, assign, readonly) unsigned int sampleRate;

/**
 * @brief Channel number of this data.
 */
@property (nonatomic, assign, readonly) unsigned int channelNum;
/**
 * @brief Millisecond timestamp.
 */
@property (nonatomic, assign, readonly) long long timeStamp;
/**
 * @brief Determines if adding a reference to the interface pointer is supported.
 * @return If adding a reference is supported, it returns YES. Otherwise, NO.
 * @note If addRef is called, the SDK will try to hold the raw data buffer until the reference becomes 0. When finished using the raw data buffer, call releaseRef to release it.
 */
- (BOOL)canAddRef;

/**
 * @brief Adds one to the reference count.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)addRef;

/**
 * @brief Subtract one from the reference count.
 * @return If the function succeeds, it returns reference count of this object. Otherwise, returns 0.
 */
- (int)releaseRef;

@end


/**
 * @class ZMVideoSDKSpeakerDevice
 * @brief Speaker device interface.
 */
@interface ZMVideoSDKSpeakerDevice : NSObject
    
/**
 * @brief Device ID.
 */
@property (nonatomic, copy, readonly) NSString *deviceId;
    
/**
 * @brief Device name.
 */
@property (nonatomic, copy, readonly) NSString *deviceName;
    
/**
 * @brief Determines if the device is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedDevice;
@end


/**
 * @class ZMVideoSDKMicDevice
 * @brief Represents a microphone device available to the SDK.
 */
@interface ZMVideoSDKMicDevice : NSObject
    
/**
 * @brief Device ID.
 */
@property (nonatomic, copy, readonly) NSString *deviceId;
    
/**
 * @brief Device name.
 */
@property (nonatomic, copy, readonly) NSString *deviceName;
    
/**
 * @brief Determines if the device is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedDevice;
@end

/**
 * @class ZMVideoSDKAudioHelper
 * @brief Provides methods for managing audio in Zoom Video SDK sessions.
 */
@interface ZMVideoSDKAudioHelper : NSObject
    
/**
 * @brief Starts audio with voip.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startAudio;
    
/**
 * @brief Stops audio.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopAudio;
    
/**
 * @brief Mutes user's voip audio. 0 means current user (myself).
 * @param user The pointer of user object.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)muteAudio:(ZMVideoSDKUser*)user;
    
/**
 * @brief UnMute user's voip audio.
 * @param user The pointer of user object.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unMuteAudio:(ZMVideoSDKUser*)user;
    
/*!
 * @brief Allows the others to unmute themselves or not. For host or manager.
 * @param allowUnmute Yes means allow the user to unmute themself, NO otherwise.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)allowAudioUnmutedBySelf:(BOOL)allowUnmute;

/**
 * @brief Mutes all user's VIOP audio except my self.
 * @param allowUnmute Yes means means allow the user to unmute themself, NO otherwise.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)muteAllAudio:(BOOL)allowUnmute;

/**
 * @brief Ask to unmute all user's VOIP audio.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unmuteAllAudio;

/**
 * @brief Gets speaker device list.
 * @return If the function succeeds, it returns speaker device list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKSpeakerDevice *>* _Nullable)getSpeakerList;
    
/**
 * @brief Gets mic device list.
 * @return If the function succeeds, it returns mic device list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKMicDevice *>* _Nullable)getMicList;
    
/**
 * @brief Select one speaker device as default device.
 * @param deviceId Device ID.
 * @param name Device name.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)selectSpeaker:(NSString *)deviceId deviceName:(NSString *)name;
    
/**
 * @brief Select one mic device as default device.
 * @param deviceId Device ID.
 * @param name Device name.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)selectMic:(NSString *)deviceId deviceName:(NSString *)name;
    
/**
 * @brief Subscribes audio raw data.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribe;
    
/**
 * @brief UnSubscribe audio raw data.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSubscribe;
@end

NS_ASSUME_NONNULL_END
