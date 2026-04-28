/**
 * @file ZMVideoSDKLiveTranscriptionHelper.h
 * @brief This file defines interfaces related to live transcription.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKLiveTranscriptionLanguage
 * @brief Represents a language used in live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionLanguage : NSObject

/**
 * @brief The language's ID.
 */
@property (nonatomic, assign, readonly)int languageID;

/**
 * @brief The language's name.
 */
@property (nonatomic, copy, readonly)NSString *languageName;

@end



/**
 * @class ZMVideoSDKLiveTranscriptionMessageInfo
 * @brief Represents a single message information of live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionMessageInfo : NSObject
/**
 * @brief Gets the message ID of the current message.
 */
@property (nonatomic, copy, readonly) NSString *messageID;

/**
 * @brief Gets the speaker's ID.
 */
@property (nonatomic, copy, readonly) NSString *speakerID;

/**
 * @brief Gets the speaker's name.
 */
@property (nonatomic, copy, readonly) NSString *speakerName;

/**
 * @brief Gets the current message's content.
 */
@property (nonatomic, copy, readonly) NSString *messageContent;

/**
 * @brief Gets the time stamp of the current message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 * @brief Gets the current message's type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKLiveTranscriptionOperationType messageType;
@end


/**
 * @class ZMVideoSDKLiveTranscriptionHelper
 * @brief Provides methods for controlling and interacting with live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionHelper : NSObject

/**
 * @brief Query if the user can start live transcription.
 * @return YES if the user can start live transcription. Otherwise, NO.
 */
- (BOOL)canStartLiveTranscription;

/**
 * @brief Gets the current live transcription status.
 * @return The current live transcription status.
 */
- (ZMVideoSDKLiveTranscriptionStatus)getLiveTranscriptionStatus;

/**
 * @brief Starts live transcription.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note If the session allows multi-language transcription, all user can start live transcription. Otherwise only the host can start it.
 */
- (ZMVideoSDKErrors)startLiveTranscription;

/**
 * @brief Stops live transcription.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note If the session allows multi-language transcription, all user can stop live transcription. Otherwise only the host can stop it.
 */
- (ZMVideoSDKErrors)stopLiveTranscription;

/**
 * @brief Gets the available spoken language list in session.
 * @return If the function succeeds, it returns the available spoken language list in a session. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableSpokenLanguages;

/**
 * @brief Sets the current user's spoken language.
 * @param languageID The spoken language ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setSpokenLanguage:(int)languageID;

/**
 * @brief Gets the current user's spoken language.
 * @return The current's spoken language user. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getSpokenLanguage;

/**
 * @brief Gets the list of all available translation languages in a session.
 * @return If the function succeeds, it returns the list of all available translation languages in a session. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableTranslationLanguages;

/**
 * @brief Sets the current user's translation language.
 * @param languageID The translation language ID. If the language ID is set to -1, live translation will be disabled.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note If you call this method before calling startLiveTranscription, it will trigger the onLiveTranscriptionStatus: callback when the translation status changes. If translation is already enabled, calling this method again will not trigger the onLiveTranscriptionStatus: callback.
 */
- (ZMVideoSDKErrors)setTranslationLanguage:(int)languageID;

/**
 * @brief Gets the current user's translation language.
 * @return The current's translation language user. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getTranslationLanguage;

/**
 * @brief Enables or disables to receive original and translated content. If enabled, start live transcription.
 * @param enable Set to YES to receive both spoken language content, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableReceiveSpokenLanguageContent:(BOOL)enable;

/**
 * @brief Determines whether the feature to receive original and translated is available.
 * @return YES if the feature to receive original and translated is available. Otherwise, NO.
 */
- (BOOL)isReceiveSpokenLanguageContentEnabled;

/**
 * @brief Determines whether the view history translation message is available.
 * @return YES if the view history transcription message is available. Otherwise, NO.
 */
- (BOOL)isAllowViewHistoryTranslationMessageEnabled;

/**
 * @brief Gets the list of all history translation messages in a session.
 * @return If the function succeeds, it returns a array of all history translation messages in a session. Otherwise it fails, and it returns nil.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionMessageInfo*>* _Nullable)getHistoryTranslationMessageList;
@end

NS_ASSUME_NONNULL_END
