/**
 * @file ZMVideoSDKChatMessage.h
 * @brief Interface for chat message object in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMVideoSDKUser;
/**
 * @class ZMVideoSDKChatMessage
 * @brief Represents a chat message within a session.
 */
@interface ZMVideoSDKChatMessage : NSObject

/**
 * @brief Gets the message's send user object.
 * @return The user object.
 */
@property (nonatomic, retain, readonly) ZMVideoSDKUser* sendUser;
    
/**
 * @brief Gets the message's receive user object.
 * @return The user object.
 */
@property (nonatomic, retain, readonly) ZMVideoSDKUser* receiverUser;

/**
 * @brief Content of the message.
 */
@property (nonatomic, copy, readonly) NSString* content;

/**
 * @brief Time stamp of the message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 * @brief Determines if the message is send to all.
 */
@property (nonatomic, assign, readonly) BOOL isChatToAll;

/**
 * @brief Determines if the message is send by yourself.
 */
@property (nonatomic, assign, readonly) BOOL isSelfSend;

/**
 * @brief Gets the message ID of the current message.
 */
@property (nonatomic, copy, readonly) NSString* messageID;

@end
NS_ASSUME_NONNULL_END
