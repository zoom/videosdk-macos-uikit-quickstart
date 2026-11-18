/**
 * @file ZMVideoSDKBroadcastStreamingViewer.h
 * @brief This file defines the interfaces for broadcast streaming viewer.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAudioHelper.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKSteamingJoinContext
 * @brief Interface for join broadcast streaming params.
 */
@interface ZMVideoSDKSteamingJoinContext : NSObject

/**
 * @brief JWT token.
 */
@property(nonatomic, copy, readwrite, nullable)NSString* token;

/**
 * @brief Broadcast channel ID.
 */
@property(nonatomic, copy, readwrite, nullable)NSString* channelID;

/**
 * @brief The viewer's display name for use when sending chat messages.
 */
@property(nonatomic, copy, readwrite, nullable)NSString* userName;

@end

/**
 * @protocol ZMVideoSDKBroadcastStreamingViewerDelegate
 * @brief Delegate protocol for receiving broadcast streaming viewer interactive callbacks.
 */
@protocol ZMVideoSDKBroadcastStreamingViewerDelegate <NSObject>
@optional

/**
 * @brief Callback event when a chat message is received from the broadcast stream.
 * @param senderName The name of the message sender.
 * @param content The chat message content.
 * @param isSelfSend YES if the message was sent by the current viewer, NO otherwise.
 */
- (void)onStreamingChatMessageReceived:(NSString*)senderName content:(NSString*)content isSelfSend:(BOOL)isSelfSend;

/**
 * @brief Callback event when an emoji reaction is received from the broadcast stream.
 * @param type The emoji reaction type.
 */
- (void)onStreamingEmojiReactionReceived:(ZMVideoSDKEmojiReactionType)type;

/**
 * @brief Callback event when a live transcription message is received from the broadcast stream.
 * @param content The live transcription content.
 */
- (void)onStreamingLiveTranscriptionMsgReceived:(NSString*)content;

@end

/**
 * @protocol ZMVideoSDKBroadcastStreamingVideoDelegate
 * @brief Video callback for broadcast streaming.
 */
@protocol ZMVideoSDKBroadcastStreamingVideoDelegate <NSObject>

/**
 * @brief Called when subscribed video data is received.
 * @param rawData The video data object.
 */
- (void)onVideoFrameReceived:(ZMVideoSDKYUVRawDataI420* __nullable)rawData;

@end

/**
 * @protocol ZMVideoSDKBroadcastStreamingAudioDelegate
 * @brief Audio callback for broadcast streaming.
 */
@protocol ZMVideoSDKBroadcastStreamingAudioDelegate <NSObject>

/**
 * @brief Called when subscribed audio data is received.
 * @param audioRawData The audio data object.
 */
- (void)onAudioRawDataReceived:(ZMVideoSDKAudioRawData* __nullable)audioRawData;

@end

/**
 * @class ZMVideoSDKBroadcastStreamingViewer
 * @brief Broadcast streaming viewer interface.
 */
@interface ZMVideoSDKBroadcastStreamingViewer : NSObject

/**
 * @brief Joins broadcast streaming asynchronously. Result is notified via \link ZMVideoSDKDelegate onStreamingJoinStatusChanged \endlink.
 * @param joinContext The join context containing token and channel ID.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)joinStreaming:(ZMVideoSDKSteamingJoinContext*)joinContext;

/**
 * @brief Leaves broadcast streaming asynchronously. Result is notified through via \link ZMVideoSDKDelegate onStreamingJoinStatusChanged \endlink.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)leaveStreaming;

/**
 * @brief The join status.
 * @return Join status.
 */
- (ZMVideoSDKStreamingJoinStatus)getStreamingJoinStatus;

/**
 * @brief Subscribes to streaming video.
 * @param resolution The desired video resolution. Supported: ZMVideoSDKResolution_180P, ZMVideoSDKResolution_360P, ZMVideoSDKResolution_720P, ZMVideoSDKResolution_1080P.
 * @param delegate The raw video data callback object, see \link ZMVideoSDKBroadcastStreamingVideoDelegate \endlink.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribeVideo:(ZMVideoSDKResolution)resolution broadcastStreamingVideoCallback:(id <ZMVideoSDKBroadcastStreamingVideoDelegate>)delegate;

/**
 * @brief Unsubscribes from streaming video raw data.
 * @param delegate The video raw data callback object.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSubscribeVideo:(id <ZMVideoSDKBroadcastStreamingVideoDelegate>)delegate;

/**
 * @brief Subscribes to streaming audio.
 * @param delegate The raw audio data callback object.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribeAudio:(id <ZMVideoSDKBroadcastStreamingAudioDelegate>)delegate;

/**
 * @brief Unsubscribes from streaming audio raw data.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSubscribeAudio;

/**
 * @brief Adds a listener for broadcast streaming viewer interactive callbacks.
 * @param listener The viewer delegate object.
 */
- (void)addListener:(id<ZMVideoSDKBroadcastStreamingViewerDelegate>)listener;

/**
 * @brief Removes a listener for broadcast streaming viewer interactive callbacks.
 * @param listener The viewer delegate object.
 */
- (void)removeListener:(id<ZMVideoSDKBroadcastStreamingViewerDelegate>)listener;

/**
 * @brief Sends a chat message to all participants in the broadcast stream.
 * @param content The chat message content to send.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendChatToAll:(NSString*)content;

/**
 * @brief Sends an emoji reaction to all participants in the broadcast stream.
 * @param type The emoji reaction type to send.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendEmojiReaction:(ZMVideoSDKEmojiReactionType)type;

/**
 * @brief Determines whether the viewer can subscribe to a translation language for live transcription.
 * @return YES if the viewer can subscribe to a translation language. Otherwise, NO.
 */
- (BOOL)canSubscribeTranslationLanguage;

/**
 * @brief Subscribes to a translation language for live transcription.
 * @param language The translation language to subscribe to.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribeTranslationLanguage:(ZMVideoSDKBroadcastStreamingTranslationLanguage)language;

/**
 * @brief Unsubscribes from the currently subscribed translation language for live transcription.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unsubscribeTranslationLanguage;

@end

NS_ASSUME_NONNULL_END
