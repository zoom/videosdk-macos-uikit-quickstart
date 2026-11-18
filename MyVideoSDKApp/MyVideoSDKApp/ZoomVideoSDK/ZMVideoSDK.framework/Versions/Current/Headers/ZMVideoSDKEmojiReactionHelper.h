/**
 * @file ZMVideoSDKEmojiReactionHelper.h
 * @brief Interface for emoji reaction helper in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKEmojiReactionHelper
 * @brief Emoji reaction helper interface for sending emoji reactions in a session.
 */
@interface ZMVideoSDKEmojiReactionHelper : NSObject

/**
 * @brief Sends an emoji reaction to all participants in the session.
 * @param type The emoji reaction type to send.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendEmojiReaction:(ZMVideoSDKEmojiReactionType)type;

@end

NS_ASSUME_NONNULL_END
