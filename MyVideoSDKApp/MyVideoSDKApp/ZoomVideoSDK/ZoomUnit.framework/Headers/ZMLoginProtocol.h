//
//  ZMLoginProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 7/27/23.
//

#ifndef ZMLoginProtocol_h
#define ZMLoginProtocol_h
@protocol ZMSignOutModel<NSObject>
/**
 Initiator identifier (can be any object)
 */
@property (nonatomic, strong, nullable) id initiator;
/**
 enum LOGOUTOPTION
 {
     PT_LOGOUT_DEFAULT = 0,
     PT_LOGOUT_SWITCHACCOUNT = 1,
     PT_LOGOUT_MANUALLY = 2,
 };
 */
@property(assign) NSInteger logoutOption;
@property(assign) BOOL focesSignOut;
/**
 Sign-out result callback
 - Parameter blocked: YES if sign-out is blocked or cancelled by user, NO if sign-out completed successfully
 */
@property (nonatomic, copy, nullable) void (^onSignOutBlocked)(BOOL blocked);
@end

@protocol ZMLoginProtocol <NSObject>
@optional
- (void)willLogin;//TODO: replaced with priority router center
- (void)didLogin;
- (void)willLogout;
- (void)didLogout;
- (void)loginWindowWillClose;
- (void)webLoginNotification:(NSInteger)result;

- (BOOL)shouldSignOutWithContext:(nullable id<ZMSignOutModel>)context;
@end

#endif /* ZMLoginProtocol_h */
