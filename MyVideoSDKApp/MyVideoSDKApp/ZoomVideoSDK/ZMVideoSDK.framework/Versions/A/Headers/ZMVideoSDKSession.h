/**
 * @file ZMVideoSDKSession.h
 * @brief Interfaces related to session, file transfer, and statistic info in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMVideoSDKUser;

/**
 * @class ZMFileTransferProgress
 * @brief Represents the progress details of a file transfer.
 */
@interface ZMFileTransferProgress : NSObject
/**
 * @brief The file transfer's completion ratio.
 */
@property(nonatomic, assign, readonly) unsigned int ratio;
/**
 * @brief The file's size transferred so far in bytes.
 */
@property(nonatomic, assign, readonly) unsigned long long completeSize;
/**
 * @brief The file transfer's speed in bits per second.
 */
@property(nonatomic, assign, readonly) unsigned int bitPreSecond;
@end


/**
 * @class ZMVideoSDKFileStatus
 * @brief Represents a file transfer's status, including current state and progress.
 */
@interface ZMVideoSDKFileStatus : NSObject
/**
 * @brief The file transfer's status.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKFileTransferStatus transStatus;
/**
 * @brief The file transfer's progress.
 */
@property(nonatomic, retain, readonly) ZMFileTransferProgress *transProgress;
@end


/**
 * @class ZMVideoSDKSendFile
 * @brief Represents a file being sent in the session.
 */
@interface ZMVideoSDKSendFile : NSObject
/**
 * @brief The file transfer's timestamp.
 */
@property(nonatomic, assign, readonly) time_t timeStamp;
/**
 * @brief Determines whether the file transfer is send to all.
 */
@property(nonatomic, assign, readonly) BOOL isSendToAll;
/**
 * @brief The file size of the file transfer.
 */
@property(nonatomic, assign, readonly) unsigned long long fileSize;
/**
 * @brief The file name of the file transfer.
 */
@property(nonatomic, copy, readonly) NSString *fileName;
/**
 * @brief The file transfer's status.
 */
@property(nonatomic, retain, readonly) ZMVideoSDKFileStatus *status;
/**
 * @brief The file transfer's receiver.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKUser * _Nullable receiver;

/**
 * @brief Cancels the file transfer.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)cancelSend;
@end


/**
 * @class ZMVideoSDKReceiveFile
 * @brief Represents a file being received in the session.
 */
@interface ZMVideoSDKReceiveFile : NSObject
/**
 * @brief The file transfer's timestamp.
 */
@property(nonatomic, assign, readonly) time_t timeStamp;
/**
 * @brief Determines whether the file transfer is send to all.
 */
@property(nonatomic, assign, readonly) BOOL isSendToAll;
/**
 * @brief The file size of the file transfer.
 */
@property(nonatomic, assign, readonly) unsigned long long fileSize;
/**
 * @brief The file name of the file transfer.
 */
@property(nonatomic, copy, readonly) NSString *fileName;
/**
 * @brief The file transfer's status.
 */
@property(nonatomic, retain, readonly) ZMVideoSDKFileStatus *status;
/**
 * @brief The file transfer's sender.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKUser * _Nullable sender;

/**
 * @brief Starts receive the file.
 * @param downloadPath The download path. Pass the complete path, including the file name and file format.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startReceive:(NSString *)downloadPath;
/**
 * @brief Cancels receive the file.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)cancelReceive;
@end


/**
 * @class ZMVideoSDKSessionAudioStatisticInfo
 * @brief Provides audio statistics for the session such as latency, jitter, and packet loss.
 */
@interface ZMVideoSDKSessionAudioStatisticInfo : NSObject

/**
 * @brief Gets the frequency in kilohertz (KHz) sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrequency;

/**
 * @brief Gets the audio latency (delay in network data transfer) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendLatency;

/**
 * @brief Gets the audio jitter (change in latency) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendJitter;

/**
 * @brief Gets the average audio packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossAvg;

/**
 * @brief Gets the maximum audio packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossMax;

/**
 * @brief Gets the frequency in kilohertz (KHz) received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrequency;

/**
 * @brief Gets the audio latency (delay in network data transfer) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvLatency;

/**
 * @brief Gets the audio jitter (change in latency) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvJitter;

/**
 * @brief Gets the average audio packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossAvg;

/**
 * @brief Gets the maximum audio packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossMax;
@end

/**
 * @class ZMVideoSDKSessionASVStatisticInfo
 * @brief Provides video or share statistics such as resolution, FPS, latency, and packet loss.
 */
@interface ZMVideoSDKSessionASVStatisticInfo : NSObject

/**
 * @brief Gets the frame width in pixels sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrameWidth;

/**
 * @brief Gets the frame height in pixels sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrameHeigh;

/**
 * @brief Gets the frame rate in FPS sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFps;

/**
 * @brief Gets the video latency (delay in network data transfer) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendLatency;

/**
 * @brief Gets the video jitter (change in latency) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendJitte;

/**
 * @brief Gets the average video packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossAvg;

/**
 * @brief Gets the maximum video packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossMax;

/**
 * @brief Gets the frame width in pixels received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrameWidth;

/**
 * @brief Gets the frame height in pixels received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrameHeigh;

/**
 * @brief Gets the frame rate in FPS received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFps;

/**
 * @brief Gets the video latency (delay in network data transfer) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvLatency;

/**
 * @brief Gets the video jitter (change in latency) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvJitte;

/**
 * @brief Gets the video average packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossAvg;

/**
 * @brief Gets the maximum video packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossMax;
@end

/**
 * @class ZMVideoSDKSession
 * @brief Provides access to session-level information and operations.
 */
@interface ZMVideoSDKSession : NSObject

/**
 * @brief Gets the current session number.
 * @return If the function succeeds, it returns the current meeting number. Otherwise returns 0.
 */
- (unsigned long long)getSessionNumber;

/**
 * @brief Gets the session's name.
 * @return The session name. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getSessionName;

/**
 * @brief Gets the session's password.
 * @return The session password. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getSessionPassword;

/**
 * @brief Gets the session's phone passcode.
 * @return The session phone passcode. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getSessionPhonePasscode;

/**
 * @brief Gets the session ID.
 * @return The session ID. Otherwise, this function fails and returns nil.
 * @note Only the host can get the session ID.
 */
- (NSString* _Nullable)getSessionID;

/**
 * @brief Gets the host's name.
 * @return The session host name. Otherwise, this function fails and returns nil.
 */
- (NSString* _Nullable)getSessionHostName;

/**
 * @brief Gets the session's host user object.
 * @return If the function succeeds, it returns host user object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKUser* _Nullable)getSessionHost;

/**
 * @brief Gets a list of the session's remote users.
 * @return If the function succeeds, it returns remote users list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getRemoteUsers;

/**
 * @brief The session's user object for myself.
 * @return If the function succeeds, it returns myself object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKUser* _Nullable)getMySelf;

/**
 * @brief Gets the session's audio statistic information.
 * @return If the function succeeds, it returns a session audio statistic information object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKSessionAudioStatisticInfo* _Nullable)getSessionAudioStatisticInfo;

/**
 * @brief Gets the session's video statistic information.
 * @return If the function succeeds, it returns a session video statistic information object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKSessionASVStatisticInfo* _Nullable)getSessionVideoStatisticInfo;

/**
 * @brief Gets the session's screen share statistic information.
 * @return If the function succeeds, it returns a session share statistic information object. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKSessionASVStatisticInfo* _Nullable)getSessionShareStatisticInfo;

/**
 * @brief Determines whether file transfer is enabled.
 * @return YES if file transfer is enabled. Otherwise, NO.
 */
- (BOOL)isFileTransferEnabled;

/**
 * @brief Sends file to all users in current session.
 * @param filePath The file's local path.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)transferFile:(NSString *)filePath;

/**
 * @brief Gets the list of allowed file types in transfer.
 * @return The value of allowed file types in transfer, comma-separated if there are multiple values. Exe files are by default forbidden from being transferred. Otherwise, this function fails and returns nil.
 */
- (NSString * _Nullable)getTransferFileTypeWhiteList;

/**
 * @brief Gets the maximum size for file transfer.
 * @return The maximum number of bytes for file transfer.
 */
- (unsigned long long)getMaxTransferFileSize;

/**
 * @brief Gets the session type of this session.
 * @return The session type.
 */
- (ZMVideoSDKSessionType)getSessionType;
@end

NS_ASSUME_NONNULL_END
