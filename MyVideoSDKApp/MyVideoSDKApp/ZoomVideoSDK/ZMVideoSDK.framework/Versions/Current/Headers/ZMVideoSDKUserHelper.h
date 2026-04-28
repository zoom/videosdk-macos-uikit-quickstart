/**
 * @file ZMVideoSDKUserHelper.h
 * @brief Defines user-related interfaces and functionalities in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>
#import <ZMVideoSDK/ZMVideoSDKVideoCanvas.h>

@class ZMVideoSDKShareAction;

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKVideoStatus
 * @brief ZMVideoSDKVideoStatus provides information on the user's video device (the detected compatible video camera device), and status (whether video is turned on or off).
 */
@interface ZMVideoSDKVideoStatus : NSObject

/**
 * @brief Query if the user's device has a compatible camera. YES : compatible camera detected, NO : no compatible camera detected.
 */
@property (nonatomic, assign, readonly) BOOL isHasVideoDevice;
    
/**
 * @brief Query if the camera is turned on. YES : camera turned on, NO : camera turned off.
 */
@property (nonatomic, assign, readonly) BOOL isOn;
@end

/**
 * @class ZMVideoSDKAudioStatus
 * @brief Audio status interface.
 */
@interface ZMVideoSDKAudioStatus : NSObject
    
/**
 * @brief Gets audio type: VOIP (Voice over IP), Telephony, or None.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKAudioType audioType;
    
/**
 * @brief Determines whether the audio is muted.
 */
@property (nonatomic, assign, readonly) BOOL isMuted;
    
/**
 * @brief Determines whether the user is talking.
 */
@property (nonatomic, assign, readonly) BOOL isTalking;
@end

/**
 * @class ZMVideoSDKQOSStatistics
 * @brief Base QOS statistics for media streams (Audio, Video, Share).
 * @note Common fields only; Send/Receive-specific fields are in ZMVideoSDKQOSSendStatistics and ZMVideoSDKQOSRecvStatistics.
 */
@interface ZMVideoSDKQOSStatistics : NSObject

/**
 * @brief Gets the direction of statistics (send or receive).
 */
@property (nonatomic, assign, readonly) ZMVideoSDKStatisticsDirection direction;

/**
 * @brief Gets the timestamp of the statistics.
 */
@property (nonatomic, assign, readonly) NSInteger timestamp;

/**
 * @brief Gets the name of the codec. For video/share: "h264", "av1". For audio: "silk", "opus", "pcm", "G722", "G729". Valid only during callback execution.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable codecName;

/**
 * @brief Gets the round-trip time in milliseconds.
 */
@property (nonatomic, assign, readonly) NSInteger rtt;

/**
 * @brief Gets the jitter in milliseconds.
 */
@property (nonatomic, assign, readonly) NSInteger jitter;

/**
 * @brief Frame width (sent or received per direction).
 */
@property (nonatomic, assign, readonly) NSInteger width;

/**
 * @brief Frame height (sent or received per direction).
 */
@property (nonatomic, assign, readonly) NSInteger height;

/**
 * @brief Frame rate in FPS (sent or received per direction).
 */
@property (nonatomic, assign, readonly) NSInteger fps;

/**
 * @brief Gets the bits per second.
 */
@property (nonatomic, assign, readonly) NSInteger bps;

/**
 * @brief Gets the total bytes transferred (sent or received per direction).
 */
@property (nonatomic, assign, readonly) NSInteger bytesTransferred;

/**
 * @brief Gets the number of packets lost during transmission.
 */
@property (nonatomic, assign, readonly) NSInteger packetsLost;

/**
 * @brief Gets the total number of packets transferred (sent or received per direction).
 */
@property (nonatomic, assign, readonly) NSInteger packetsTransferred;

/**
 * @brief Gets the network quality level.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKNetworkStatus networkLevel;

/**
 * @brief Gets the statistics type (Audio, Video, or Share).
 */
@property (nonatomic, assign, readonly) ZMVideoSDKDataType statisticsType;

/**
 * @brief Gets the average packet loss ratio in per thousand (e.g. 100 means 10%).
 */
@property (nonatomic, assign, readonly) NSInteger avg_loss;

/**
 * @brief Gets the maximum packet loss ratio in per thousand (e.g. 100 means 10%).
 */
@property (nonatomic, assign, readonly) NSInteger max_loss;

/**
 * @brief Gets the estimated bandwidth in bps.
 */
@property (nonatomic, assign, readonly) NSInteger bandwidth;

@end

/**
 * @class ZMVideoSDKQOSSendStatistics
 * @brief QOS statistics for outbound media stream (sending).
 * @note Inherits common fields from ZMVideoSDKQOSStatistics; adds send-specific properties.
 */
@interface ZMVideoSDKQOSSendStatistics : ZMVideoSDKQOSStatistics

/**
 * @brief Gets the width of the input frame (send only).
 */
@property (nonatomic, assign, readonly) NSInteger frameWidthInput;

/**
 * @brief Gets the height of the input frame (send only).
 */
@property (nonatomic, assign, readonly) NSInteger frameHeightInput;

/**
 * @brief Gets the frame rate of input (send only).
 */
@property (nonatomic, assign, readonly) NSInteger frameRateInput;

/**
 * @brief Gets the total bytes sent.
 */
@property (nonatomic, assign, readonly) NSInteger bytesSent;

/**
 * @brief Gets the total number of packets sent.
 */
@property (nonatomic, assign, readonly) NSInteger packetsSent;

/**
 * @brief Gets the total packet send delay in milliseconds (send only).
 */
@property (nonatomic, assign, readonly) NSInteger totalPacketSendDelay;

/**
 * @brief Gets the total time spent encoding in milliseconds (send only).
 */
@property (nonatomic, assign, readonly) NSInteger totalEncodeTime;

/**
 * @brief Gets the total number of frames encoded (send only).
 */
@property (nonatomic, assign, readonly) NSInteger framesEncoded;

@end

/**
 * @class ZMVideoSDKQOSRecvStatistics
 * @brief QOS statistics for inbound media stream (receiving).
 * @note Inherits common fields from ZMVideoSDKQOSStatistics; adds receive-specific properties.
 */
@interface ZMVideoSDKQOSRecvStatistics : ZMVideoSDKQOSStatistics

/**
 * @brief Gets the total bytes received (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger bytesReceived;

/**
 * @brief Gets the total number of packets received (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger packetsReceived;

/**
 * @brief Gets the estimated playout timestamp (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger estimatedPlayoutTimestamp;

/**
 * @brief Gets the total time spent decoding in milliseconds (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger totalDecodeTime;

/**
 * @brief Gets the total number of frames decoded (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger framesDecoded;

/**
 * @brief Gets the jitter buffer delay in milliseconds (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger jitterBufferDelay;

/**
 * @brief Gets the number of samples emitted from jitter buffer (receive only).
 */
@property (nonatomic, assign, readonly) NSInteger jitterBufferEmittedCount;

@end

/**
 * @class ZMVideoSDKVideoStatisticInfo
 * @brief Video statistic information. Inherits QOS fields (width, height, fps, bps, direction, networkLevel, statisticsType) from ZMVideoSDKQOSStatistics.
 */
@interface ZMVideoSDKVideoStatisticInfo : ZMVideoSDKQOSStatistics

/**
 * @brief Gets video bits per frame. Same as bps.
 * @deprecated Use bps instead.
 */
@property (nonatomic, assign, readonly) int bpf DEPRECATED_MSG_ATTRIBUTE("Use bps instead");

/**
 * @brief Gets video network status. Same as networkLevel.
 * @deprecated Use networkLevel instead.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKNetworkStatus videoNetworkStatus DEPRECATED_MSG_ATTRIBUTE("Use networkLevel instead");
@end

/**
 * @class ZMVideoSDKShareStatisticInfo
 * @brief Share statistic information. Inherits QOS fields (width, height, fps, bps, direction, networkLevel, statisticsType) from ZMVideoSDKQOSStatistics.
 */
@interface ZMVideoSDKShareStatisticInfo : ZMVideoSDKQOSStatistics

/**
 * @brief Gets share bits per frame. Same as bps.
 * @deprecated Use bps instead.
 */
@property (nonatomic, assign, readonly) int bpf DEPRECATED_MSG_ATTRIBUTE("Use bps instead");

/**
 * @brief Gets share network status. Same as networkLevel.
 * @deprecated Use networkLevel instead.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKNetworkStatus shareNetworkStatus DEPRECATED_MSG_ATTRIBUTE("Use networkLevel instead");
@end

/**
 * @class ZMVideoSDKYUVRawDataI420
 * @brief YUV raw data 420 infomation interface.
 */
@interface ZMVideoSDKYUVRawDataI420 : NSObject

/**
 * @brief Gets the YUVI420 Y buffer. The Y component represents the luma or brightness values.
 */
@property (nonatomic, assign, readonly) char* _Nullable yBuffer;

/**
 * @brief Gets the YUVI420 U buffer. The U component represents the chroma values.
 */
@property (nonatomic, assign, readonly) char* _Nullable uBuffer;

/**
 * @brief Gets the YUVI420 V buffer. The V component represents the chroma values.
 */
@property (nonatomic, assign, readonly) char* _Nullable vBuffer;

/**
 * @brief The buffer data.
 */
@property (nonatomic, assign, readonly) char* _Nullable buffer;

/**
 * @brief Gets video alpha mask data buffer.
 */
@property (nonatomic, assign, readonly, nullable) char* alphaBuffer;

/**
 * @brief The buffer length of this data.
 */
@property (nonatomic, assign, readonly) unsigned int bufferLen;

/**
 * @brief Gets the alpha buffer length.
 */
@property (nonatomic, assign, readonly) unsigned int alphaBufferLen;

/**
 * @brief Gets if this data is limited I420 format.
 */
@property (nonatomic, assign, readonly) BOOL isLimitedI420;

/**
 * @brief Query stream width.
 */
@property (nonatomic, assign, readonly) unsigned int streamWidth;

/**
 * @brief Gets the stream height.
 */
@property (nonatomic, assign, readonly) unsigned int streamHeight;

/**
 * @brief Query the video raw data rotation.
 */
@property (nonatomic, assign, readonly) unsigned int rotation;

/**
 * @brief Gets the source_id of current YUV raw data.
 */
@property (nonatomic, assign, readonly) unsigned int resourceID;

/**
 * @brief Millisecond timestamp.
 */
@property (nonatomic, assign, readonly) long long timeStamp;
/**
 * @brief Determines if adding a reference to the raw data buffer is supported.
 * @return YES if adding a reference is supported. Otherwise, NO.
 */
- (BOOL)canAddRef;

/**
 * @brief Increase reference count by 1. Adding a reference ensures that the raw data buffer nots be released.
 * @return YES if the reference count was successfully increased. Otherwise, NO.
 * @note The SDK will hold the raw data buffer until the reference count becomes 0. When finished using the raw data buffer, call releaseRef.
 */
- (BOOL)addRef;

/**
 * @brief Decrease reference count by 1. When finished using the raw data buffer, call releaseRef.
 * @return If the function succeeds, it returns reference count of this object. Otherwise, returns 0.
 */
- (int)releaseRef;
@end


/**
 * @class ZMVideoSDKShareCursorData
 * @brief Represents the cursor position data during screen sharing.
 */
@interface ZMVideoSDKShareCursorData : NSObject

/**
 * @brief The source id of the share cursor.
 */
@property (nonatomic, assign, readonly) unsigned int sourceID;

/**
 * @brief The x value of the coordinate.
 */
@property (nonatomic, assign, readonly) int x;

/**
 * @brief The y value of the coordinate.
 */
@property (nonatomic, assign, readonly) int y;
@end

/**
 * @protocol ZMVideoSDKRawDataPipeDelegate
 * @brief Raw data pipe delegate interface.
 */
@protocol ZMVideoSDKRawDataPipeDelegate <NSObject>
@optional
    
/**
 * @brief Notify if subscribed data received.
 * @param data The pointer of ZMVideoSDKYUVRawDataI420 object.
 */
- (void)onRawDataFrameReceived:(ZMVideoSDKYUVRawDataI420*)data;
    
/**
 * @brief Notify if subscribed data status changed.
 * @param status The rawData status.
 */
- (void)onRawDataStatusChanged:(ZMVideoSDKRawDataStatus)status;

/**
 * @brief Callback when the cursor data of share received.
 * @param info Share cursor data object.
 */
- (void)onShareCursorDataReceived:(ZMVideoSDKShareCursorData *)info;
@end

/**
 * @class ZMVideoSDKRawDataPipe
 * @brief Video or share raw data pipe interface.
 */
@interface ZMVideoSDKRawDataPipe : NSObject

/**
 * @brief Subscribes video or share raw data.
 * @param resolution The subscribe size.
 * @param listener The callback sink object.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribe:(ZMVideoSDKResolution)resolution listener:(id<ZMVideoSDKRawDataPipeDelegate>)listener;
    
/**
 * @brief Unsubscribes video or share raw data.
 * @param listener The callback sink object.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSubscribe:(id<ZMVideoSDKRawDataPipeDelegate>)listener;

/**
 * @brief Gets the raw data data type.
 * @return Share or Video data type.
 */
- (ZMVideoSDKRawDataType)getRawdataType;

/**
 * @brief Gets video status.
 * @return If the function succeeds, it returns pointer of video status object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoStatus* _Nullable)getVideoStatus;

/**
 * @brief Gets video device name.
 * @return If the function succeeds, it returns the video device name. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getVideoDeviceName;

/**
 * @brief Gets share status.
 * @return The current share status.
 */
- (ZMVideoSDKShareStatus)getShareStatus;

/**
 * @brief Gets the reason why the share capture is paused.
 * @return The current pause reason of the ongoing share.
 * @note If sharing is not paused, it returns @c ZMVideoSDKShare_Capture_Pause_None.
 */
- (ZMVideoSDKShareCapturePauseReason)getShareCapturePauseReason;

/**
 * @brief Gets share type.
 * @return The current share type.
 */
- (ZMVideoSDKShareType)getShareType;

/**
 * @brief Gets video statistic information.
 * @return If the function succeeds, it returns the object of ZMVideoSDKVideoStatisticInfo. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoStatisticInfo* _Nullable)getVideoStatisticInfo;
@end

/**
 * @class ZMVideoSDKCameraControlRequestHandler
 * @brief Camera control request handler object interface.
 */
@interface ZMVideoSDKCameraControlRequestHandler : NSObject

/**
 * @brief Approve the remote camera control request.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)approve;

/**
 * @brief Decline the remote camera control request.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)decline;
@end

/**
 * @class ZMVideoSDKRemoteCameraControlHelper
 * @brief Remote camera control helper object interface.
 */
@interface ZMVideoSDKRemoteCameraControlHelper : NSObject

/**
 * @brief Requests to control remote camera.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)requestControlRemoteCamera;

/**
 * @brief Give up control of the remote camera.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)giveUpControlRemoteCamera;

/**
 * @brief Turn the camera to the left.
 * @param range The rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnLeft:(unsigned int)range;

/**
 * @brief Turn the camera to the right.
 * @param range Rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnRight:(unsigned int)range;

/**
 * @brief Turn the camera up.
 * @param range Rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnUp:(unsigned int)range;

/**
 * @brief Turn the camera down.
 * @param range Rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnDown:(unsigned int)range;

/**
 * @brief Zoom the camera in.
 * @param range Rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)zoomIn:(unsigned int)range;

/**
 * @brief Zoom the camera out.
 * @param range Rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)zoomOut:(unsigned int)range;
@end


/**
 * @class ZMVideoSDKUser
 * @brief Zoom Video SDK user information.
 */
@interface ZMVideoSDKUser : NSObject
/**
 * @brief Gets the user's ID.
 * @return If the function succeeds, it returns user ID. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getUserID;

/**
 * @brief Gets the user's custom identity.
 * @return If the function succeeds, it returns custom ID. Otherwise, this function fails and returns nil.
 * @deprecated Use \link getUserKey \endlink instead.
 */
- (NSString* _Nullable)getCustomIdentity DEPRECATED_MSG_ATTRIBUTE("Use -getUserKey instead");

/**
 * @brief Gets the user's key.
 * @return If the function succeeds, it returns the user's key. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getUserKey;

/**
 * @brief Gets the user's name in the session.
 * @return If the function succeeds, it returns user name. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getUserName;

/**
 * @brief Gets the user's reference.
 */
- (NSString* _Nullable)getUserReference;

/**
 * @brief Gets the user's audio status.
 * @return Audio status object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKAudioStatus* _Nullable)getAudioStatus;
    
/**
 * @brief Determines whether the user is the host.
 * @return YES if that the user is the host. Otherwise, NO.
 */
- (BOOL)isHost;
    
/**
 * @brief Determines whether the user is the manager.
 * @return YES if that the user is the manager. Otherwise, NO.
 */
- (BOOL)isManager;
    
/**
 * @brief Gets the user's video statistic information.
 * @return Video statistic information object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoStatisticInfo* _Nullable)getVideoStatisticInfo;
    
/**
 * @brief Gets the user's share statistic information.
 * @return Share statistic information object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKShareStatisticInfo* _Nullable)getShareStatisticInfo;
    
/**
 * @brief Gets the user's video pipe.
 * @return Video pipe object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRawDataPipe* _Nullable)getVideoPipe;

/**
 * @brief Gets the user's video canvas.
 * @return If the function succeeds, it returns a ZMVideoSDKVideoCanvas object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVideoCanvas * _Nullable)getVideoCanvas;

/**
 * @brief Gets the user's share-action list.
 * @return A list of all share action objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKShareAction*>* _Nullable)getShareActionList;

/**
 * @brief Gets the helper class instance to access the remote camera control.
 * @return If the function succeeds, it returns a remote camera control object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKRemoteCameraControlHelper * _Nullable)getRemoteCameraControlHelper;

/**
 * @brief Gets the user's multi-camera stream list.
 * @return A list of all streaming cameras pipe objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKRawDataPipe *>* _Nullable)getMultiCameraStreamList;

/**
 * @brief Sets the user's local volume. This does not affect how other participants hear the user.
 * @param volume Value can be >= 0 and <=10. If volume is 0, the user won't be able to hear the related audio.
 * @param isSharingAudio YES to set the shared audio's volume (such as shared computer audio), NO to set the microphone's volume.
 * @return If the function succeedsful return YES. Otherwise, NO.
 * @deprecated Use \link setUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)setUserVolume:(float)volume isSharingAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -setUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Gets user volume.
 * @param volume The user volume.
 * @param isSharingAudio YES to get the shared audio's volume (such as shared computer audio), NO to get the microphone's volume.
 * @return If the function succeeds return YES. Otherwise, NO.
 * @deprecated Use \link getUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)getUserVolume:(float*)volume isSharingAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -getUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Determines which audio to set, shared audio or microphone.
 * @param isShareAudio YES to check whether to set the shared audio's volume, NO to set the microphone's volume.
 * @return If the function succeeds return YES. Otherwise, NO.
 * @deprecated Use \link canSetUserPlaybackVolume: \endlink instead.
 */
- (BOOL)canSetUserVolume:(BOOL)isShareAudio DEPRECATED_MSG_ATTRIBUTE("Use -canSetUserPlaybackVolume: instead");

/**
 * @brief Sets the user's local volume. This does not affect how other participants hear the user.
 * @param volume Value can between 0 and 10. If 0, the user won't hear the related audio.
 * @param isSharingAudio YES to set the volume of shared audio (such as shared computer audio), NO to set the microphone volume.
 * @return YES if the operation succeeds. Otherwise, NO.
 */
- (BOOL)setUserPlaybackVolume:(float)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Gets the local volume.
 * @param volume The user volume.
 * @param isShareAudio YES to get the volume of shared audio (such as shared computer audio), NO to get the microphone volume.
 * @return YES if the operation succeeds. Otherwise, NO.
 */
- (BOOL)getUserPlaybackVolume:(float*)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Checks whether to set the volume for shared audio or microphone.
 * @param isShareAudio YES to check if to set the shared audio's volume, NO to set the microphone's volume.
 * @return YES if setting the volume of shared audio is supported. Otherwise, NO.
 */
- (BOOL)canSetUserPlaybackVolume:(BOOL)isShareAudio;

/**
 * @brief Gets the current audio level of a remote user.
 * @return The current audio level.
 */
- (unsigned int)getAudioLevel;

/**
 * @brief Determines whether I agree to individual video recording.
 * @return YES if the user has individual video recording consent. Otherwise, NO.
 */
- (BOOL)hasIndividualRecordingConsent;

/**
 * @brief Sends file to current user object.
 * @param filePath The file's local path.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)transferFile:(NSString *)filePath;

/**
 * @brief Check if user is spotlighted.
 * @return YES if that the user is spotlighted. Otherwise, this function returns NO.
 */
- (BOOL)isVideoSpotLighted;

/**
 * @brief Determines whether the user is incoming live stream user.
 * @return YES if that the user special for incoming live stream. Otherwise, NO.
 */
- (BOOL)isIncomingLiveStreamUser;

/**
 * @brief Determines whether the user is in a subsession.
 * @return YES if that the user is currently in a subsession. Otherwise, NO.
 */
- (BOOL)isInSubSession;

/**
 * @brief Gets the user's whiteboard sharing status.
 * @return The whiteboard sharing status.
 */
- (ZMVideoSDKWhiteboardStatus)getWhiteboardStatus;

/**
 * @brief Gets the network quality level of the specified data type for the user.
 * @param type The data type, such as audio, video, or share.
 * @return The current network status level for the specified data type.
 */
- (ZMVideoSDKNetworkStatus)getNetworkLevel:(ZMVideoSDKDataType)type;

/**
 * @brief Gets the user's overall network quality level.
 * @return The overall network status level.
 */
- (ZMVideoSDKNetworkStatus)getOverallNetworkLevel;
@end

/**
 * @class ZMVideoSDKUserHelper
 * @brief User control interface.
 */
@interface ZMVideoSDKUserHelper: NSObject
    
/**
 * @brief Changes a specific user's name.
 * @param name The new user name.
 * @param user User in the session.
 * @return YES if that name change is success. Otherwise, this function returns NO.
 */
- (BOOL)changeName:(NSString*)name user:(ZMVideoSDKUser*)user;
    
/**
 * @brief Assign a user as the session host.
 * @param user User in the session.
 * @return YES if that the user is now the host. Otherwise, this function returns NO.
 */
- (BOOL)makeHost:(ZMVideoSDKUser*)user;
    
/**
 * @brief Assign a user as the session manager.
 * @param user User in the session.
 * @return YES if that the user is now the manager. Otherwise, this function returns NO.
 */
- (BOOL)makeManager:(ZMVideoSDKUser*)user;
    
/**
 * @brief Revoke manager rights from a user.
 * @param user User in the session.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)revokeManager:(ZMVideoSDKUser*)user;
    
/**
 * @brief Removes user from session.
 * @param user User in the session.
 * @return If the function succeeds, it returns YES. Otherwise, this function returns NO.
 */
- (BOOL)removeUser:(ZMVideoSDKUser*)user;

/**
 * @brief Reclaim host permission. Allow the user whose role_type = 1 to reclaim the host role.
 * @return If the function succeeds, it returns YES. Otherwise, this function returns NO.
 */
- (BOOL)reclaimHost;
@end

NS_ASSUME_NONNULL_END

