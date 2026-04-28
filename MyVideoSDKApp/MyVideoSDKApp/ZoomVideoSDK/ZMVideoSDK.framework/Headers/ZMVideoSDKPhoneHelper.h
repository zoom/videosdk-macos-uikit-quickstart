/**
 * @file ZMVideoSDKPhoneHelper.h
 * @brief This file defines interfaces for phone-related functionalities in the Zoom Video SDK,
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKDialInNumberInfo
 * @brief Represents dial-in number information for a specific country.
 */
@interface ZMVideoSDKDialInNumberInfo : NSObject
/**
 * @brief The current's country ID information.
 */
@property (nonatomic, copy, readonly) NSString* countryID;
/**
 * @brief The current's country code information.
 */
@property (nonatomic, copy, readonly) NSString* countryCode;
/**
 * @brief The current's country name information.
 */
@property (nonatomic, copy, readonly) NSString* countryName;
/**
 * @brief The country number.
 */
@property (nonatomic, copy, readonly) NSString* number;
/**
 * @brief The display number.
 */
@property (nonatomic, copy, readonly) NSString* displayNumber;
/**
 * @brief The type of dial in number.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKDialInNumType type;
/**
 * @brief Is the dial number an account dedicated number.
 */
@property (nonatomic, assign, readonly) BOOL isDedicateID;
@end


/**
 * @class ZMVideoSDKPhoneSupportCountryInfo
 * @brief Contains information about a country where phone features are supported.
 */
@interface ZMVideoSDKPhoneSupportCountryInfo : NSObject
/**
 * @brief The current's country ID information.
 */
@property (nonatomic, copy, readonly) NSString* countryID;
/**
 * @brief The current's country name information.
 */
@property (nonatomic, copy, readonly) NSString* countryName;
/**
 * @brief The current's country code information.
 */
@property (nonatomic, copy, readonly) NSString* countryCode;
@end


/**
 * @class ZMVideoSDKInvitePhoneUserInfo
 * @brief Represents the information used when inviting a user to join the session via phone.
 * @note languageCode and variantId must be used together (both provided or both nil).
 *       Use getPhoneWelcomeMessageInfoList to retrieve the list of valid language codes and variant IDs.
 *       If provided with an invalid value, invitePhoneUser: returns ZMVideoSDKErrors_Invalid_Parameter.
 */
@interface ZMVideoSDKInvitePhoneUserInfo : NSObject
/**
 * @brief The specified's country code user must be in the support list.
 */
@property (nonatomic, copy, nullable) NSString* countryCode;
/**
 * @brief The phone number of specified user.
 */
@property (nonatomic, copy, nullable) NSString* phoneNumber;
/**
 * @brief The specified's screen name user in the session.
 */
@property (nonatomic, copy, nullable) NSString* name;
/**
 * @brief YES if need press number one to agree to join the session, NO otherwise.
 */
@property (nonatomic, assign) BOOL bPressOne;
/**
 * @brief YES if joining the session, play a greeting prompt tone. NO Otherwise.
 */
@property (nonatomic, assign) BOOL bGreeting;

/**
 * @brief Optional: The welcome message's language code, such as "en-US", "zh-CN".
 */
@property (nonatomic, copy, nullable) NSString* languageCode;
/**
 * @brief Optional: The welcome message's variant ID (e.g., "variant_001").
 */
@property (nonatomic, copy, nullable) NSString* variantId;
@end

/**
 * @class ZMVideoSDKPhoneWelcomeMessageInfo
 * @brief Represents phone welcome message information.
 */
@interface ZMVideoSDKPhoneWelcomeMessageInfo : NSObject
/**
 * @brief The current information's language code, such as "en-US", "zh-CN".
 */
@property (nonatomic, copy, readonly) NSString* languageCode;
/**
 * @brief The current information's language name, such as "English (US)", "Chinese (China)".
 */
@property (nonatomic, copy, readonly) NSString* languageName;
/**
 * @brief The current information's variant ID.
 */
@property (nonatomic, copy, readonly) NSString* variantId;
@end


/**
 * @class ZMVideoSDKPhoneHelper
 * @brief Provides methods for managing phone-related session features such as dial-in and phone invites.
 */
@interface ZMVideoSDKPhoneHelper : NSObject
/**
 * @brief Determines if the session supports join by phone or not.
 * @return YES if join by phone is supported. Otherwise, NO.
 */
- (BOOL)isSupportPhoneFeature;

/**
 * @brief Gets the country information list where the session supports to join by telephone.
 * @return If the function succeeds, it returns the country information array. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKPhoneSupportCountryInfo*>* _Nullable)getSupportCountryInfo;

/**
 * @brief Invite the specified user to join the session by phone.
 * @param countryCode The country code of the specified user must be in the support list.
 * @param phoneNumber The phone number of specified user.
 * @param name The specified's screen name in the session.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @deprecated Use \link ZMVideoSDKPhoneHelper::invitePhoneUser: \endlink instead.
 */
- (ZMVideoSDKErrors)inviteByPhone:(NSString*)countryCode phoneNumber:(NSString*)phoneNumber name:(NSString*)name DEPRECATED_MSG_ATTRIBUTE("Use -invitePhoneUser: instead");

/**
 * @brief Invite the specified user to join the session by phone.
 * @param inviteInfo The info for invite by phone.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)invitePhoneUser:(ZMVideoSDKInvitePhoneUserInfo *)inviteInfo;
/**
 * @brief Cancels the invitation that is being called out by phone.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)cancelInviteByPhone;

/**
 * @brief Gets the phone invitation's status.
 * @return The phone invitation's ZMPhoneStatus.
 */
- (ZMPhoneStatus)getInviteByPhoneStatus;

/**
 * @brief Gets the dial in number list supported by session.
 * @return If the function succeeds, it returns the call-in number list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKDialInNumberInfo *>* _Nullable)getSessionDialInNumbers;

/**
 * @brief Gets the list of multilingual welcome message information.
 * @return If the function succeeds, it returns an NSArray of welcome message information objects. Returns an empty list if no languages are configured. Otherwise, this function fails and returns nil.
 * @note Use this method to query valid language codes and variant IDs before passing them to invitePhoneUser: via ZMVideoSDKInvitePhoneUserInfo.
 *       The welcome messages must be pre-uploaded to the Zoom web portal. Each language may have multiple variants with user-defined identifiers.
 */
- (NSArray<ZMVideoSDKPhoneWelcomeMessageInfo *>* _Nullable)getPhoneWelcomeMessageInfoList;
@end

NS_ASSUME_NONNULL_END
