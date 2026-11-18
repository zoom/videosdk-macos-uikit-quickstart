/**
 * @file ZMVideoSDKCmdChannel.h
 * @brief Interface for command channel to send custom commands or data between users in the same session.
 */

#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;
@class ZMVideoSDKSubSessionUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKCmdChannel
 * @brief The command channel allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
 */
@interface ZMVideoSDKCmdChannel : NSObject
/**
 * @brief Sends custom commands or data to other users in the current session.
 * @param commandContent The custom commands or data, represented in string format.
 * @param user The target user to receive the command. If nil, the command is broadcast to all users.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note This API is rate-limited; overly frequent calls return ZMVideoSDKErrors_Call_Too_Frequently.
 */
- (ZMVideoSDKErrors)sendCommand:(NSString *)commandContent receiveUser:(nullable ZMVideoSDKUser *)user;

/**
 * @brief Sends a command to a user in the main session or a subsession.
 * @param commandContent The custom command or data.
 * @param subSessionUser The target lightweight user, obtained from a subsession user list.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)sendCommandToSubSessionUser:(NSString *)commandContent
                                subSessionUser:(nullable ZMVideoSDKSubSessionUser *)subSessionUser;
@end

NS_ASSUME_NONNULL_END
