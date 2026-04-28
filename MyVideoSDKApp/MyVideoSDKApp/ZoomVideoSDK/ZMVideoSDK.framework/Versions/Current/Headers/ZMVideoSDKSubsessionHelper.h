/**
 * @file ZMVideoSDKSubSessionHelper.h
 * @brief This file declares the interfaces for managing Zoom Video SDK subsessions,
 */


#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKSubSessionUser
 * @brief Represents a user within a subsession.
 */
@interface ZMVideoSDKSubSessionUser : NSObject
/**
 * @brief Gets the subsession user's username.
 */
@property(nonatomic, copy, readonly)NSString* userName;
/**
 * @brief Gets the subsession user's GUID.
 */
@property(nonatomic, copy, readonly)NSString* userGUID;
@end

/**
 * @class ZMVideoSDKSubSessionKit
 * @brief Represents a subsession instance.
 */
@interface ZMVideoSDKSubSessionKit : NSObject
/**
 * @brief Gets the subsession's name.
 */
@property(nonatomic, copy, readonly)NSString* subSessionName;
/**
 * @brief Gets the subsession's ID.
 */
@property(nonatomic, copy, readonly)NSString* subSessionID;
/**
 * @brief Gets the list of users in this subsession.
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionUser. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKSubSessionUser*>* _Nullable)getSubSessionUserList;

/**
 * @brief Joins this subsession.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)joinSubSession;
@end

/**
 * @class ZMVideoSDKSubSessionUserHelpRequestHandler
 * @brief Handler for user help requests in subsessions.
 */
@interface ZMVideoSDKSubSessionUserHelpRequestHandler : NSObject
/**
 * @brief Gets the user's username who sent this request.
 */
@property(nonatomic, copy, readonly)NSString* requestUserName;
/**
 * @brief Gets the subsession's name where the user sent this request.
 */
@property(nonatomic, copy, readonly)NSString* requestSubSessionName;
/**
 * @brief Ignore this request.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note 'onSubSessionUserHelpRequestResult' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)ignore;

/**
 * @brief Joins the subsession where the help request originated.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)joinSubSessionByUserRequest;
@end

/**
 * @class ZMVideoSDKSubSessionManager
 * @brief Manages subsession lifecycle and communication.
 */
@interface ZMVideoSDKSubSessionManager : NSObject
/**
 * @brief Starts subsession.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)startSubSession;

/**
 * @brief Determines if the subsession has started.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (BOOL)isSubSessionStarted;

/**
 * @brief Stops subsession.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)stopSubSession;

/**
 * @brief Broadcast a message to all subsessions.
 * @param message The message to be broadcast.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note 'onBroadcastMessageFromMainSession' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)broadcastMessage:(NSString*)message;
@end

/**
 * @class ZMVideoSDKSubSessionParticipant
 * @brief Interface for subsession participants.
 */
@interface ZMVideoSDKSubSessionParticipant : NSObject
/**
 * @brief Return to main session.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)returnToMainSession;

/**
 * @brief Requests help.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note 'onSubSessionUserHelpRequestResult'is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)requestForHelp;
@end


/**
 * @class ZMVideoSDKSubSessionHelper
 * @brief Helper class for managing subsessions.
 * @note Only available to session hosts and managers.
 */
@interface ZMVideoSDKSubSessionHelper : NSObject

/**
 * @brief Withdraw all committed subsessions and commit the new list.
 * @param subSessionList Create subsession name list.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)commitSubSessionList:(NSArray<NSString*>*)subSessionList;

/**
 * @brief Withdraw all committed subsessions.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)withdrawSubSessionList;

/**
 * @brief Gets the list of commited subsessions.
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionKit. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKSubSessionKit*>* _Nullable)getCommittedSubSessionList;
@end
NS_ASSUME_NONNULL_END
