/**
 * @file ZMVideoSDKChatHelper.h
 * @brief Interface for chat-related functionalities in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKChatHelper
 * @brief Chat helper interface.
 */
@interface ZMVideoSDKChatHelper : NSObject
    
/**
 * @brief Determines whether chat is disabled.
 * @return YES if chat is disabled. Otherwise, NO.
 */
- (BOOL)isChatDisabled;
    
/**
 * @brief Determines whether private chat is disabled.
 * @return YES if private chat is disabled. Otherwise, NO.
 */
- (BOOL)isPrivateChatDisabled;
    
/**
 * @brief Sends a chat message to a specific user.
 * @param user The receiver.
 * @param msgContent The content of message.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendChatToUser:(ZMVideoSDKUser*)user content:(NSString *)msgContent;
    
/**
 * @brief Sends a chat message to all users.
 * @param msgContent The content of message.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendChatToAll:(NSString *)msgContent;

/**
 * @brief Determines if a specific message supports deletion.
 * @param msgID The message Id.
 * @return YES if the message supports deletion. Otherwise, NO.
 */
- (BOOL)canChatMessageBeDeleted:(NSString *)msgID;

/**
 * @brief Deletes a specific chat message from the Zoom server.
 * @param msgID The message Id.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note This does not delete the message in your user interface.
 */
- (ZMVideoSDKErrors)deleteChatMessage:(NSString *)msgID;

/**
 * @brief Sets participant chat privilege when in session. Only session host or manager can run the function.
 * @param privilege The participant's chat privilege.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)changeChatPrivilege:(ZMVideoSDKChatPrivilegeType)privilege;

/**
 * @brief Gets participant chat privilege when in session.
 * @return The result of participant chat priviledge.
 */
- (ZMVideoSDKChatPrivilegeType)getChatPrivilege;
@end

NS_ASSUME_NONNULL_END
