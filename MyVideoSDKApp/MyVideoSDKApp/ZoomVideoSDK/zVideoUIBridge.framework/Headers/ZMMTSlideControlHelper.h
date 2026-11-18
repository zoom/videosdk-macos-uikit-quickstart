//
//  ZMMTSlideControlHelper.h
//  VideoUIBridge
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMShareSource;

@interface ZMMTSlideControlHelper : ZMBaseHelper

#pragma mark - Privilege Query

- (BOOL)isSomeoneHasMySlidePrivilege;
- (BOOL)hasMySlidePrivilegeForUser:(ZMUser *)user;
- (int)queryMySlidePermissionUsersCount;

#pragma mark - Capability Query

- (BOOL)isEmptyCanSlideControlUserList;
- (BOOL)isUserSupportSlideControl:(ZMUser *)user;
- (BOOL)canGrantMySlidePermission;

#pragma mark - Control Action

- (void)stopAllMySlideControl;
- (BOOL)allowMySlideControlForUser:(ZMUser *)user;
- (BOOL)forbidMySlideControlForUser:(ZMUser *)user;

@end

NS_ASSUME_NONNULL_END
