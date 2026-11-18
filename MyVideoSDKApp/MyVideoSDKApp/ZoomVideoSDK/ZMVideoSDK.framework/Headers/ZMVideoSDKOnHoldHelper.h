/**
 * @file ZMVideoSDKOnHoldHelper.h
 * @brief Waiting room helper interfaces.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMVideoSDKUser;

/**
 * @class ZMVideoSDKOnHoldUser
 * @brief OnHold user snapshot.
 */
@interface ZMVideoSDKOnHoldUser : NSObject

/**
 * @brief Gets the OnHold user's ID.
 * @return The user ID.
 */
- (NSString* _Nullable)getUserID;

/**
 * @brief Gets the OnHold user's name.
 * @return The user name.
 */
- (NSString* _Nullable)getUserName;

@end

/**
 * @class ZMVideoSDKOnHoldHelper
 * @brief OnHold helper.
 */
@interface ZMVideoSDKOnHoldHelper : NSObject

/**
 * @brief Determines whether the current session supports OnHold.
 * @return YES if OnHold is supported. Otherwise, NO.
 * @note When the session supports OnHold, older clients that do not support this feature cannot join the session.
 * @note Whether a session supports OnHold is controlled by JWT parameters.
 */
- (BOOL)isSupportHold;

/**
 * @brief Determines whether OnHold is enabled for the current session.
 * @return YES if OnHold is enabled. Otherwise, NO.
 */
- (BOOL)isOnHoldEnabled;

/**
 * @brief Enables or disables OnHold for the current session.
 * @param enable YES to enable OnHold, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @note Only the host or manager can call this method.
 * @note This change only affects future join attempts.
 */
- (ZMVideoSDKErrors)enableHold:(BOOL)enable;

/**
 * @brief Gets the current OnHold user list.
 * @return The OnHold user list.
 */
- (NSArray<ZMVideoSDKOnHoldUser*>* _Nullable)getOnHoldUserList;

/**
 * @brief Admits the specified OnHold user into the session.
 * @param user The OnHold user.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)admit:(ZMVideoSDKOnHoldUser* _Nullable)user;

/**
 * @brief Admits all OnHold users into the session.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)admitAll;

@end

NS_ASSUME_NONNULL_END
