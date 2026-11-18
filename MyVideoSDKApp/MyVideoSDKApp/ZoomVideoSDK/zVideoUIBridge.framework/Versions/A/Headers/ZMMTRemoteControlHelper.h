//
//  ZMMTRemoteControlHelper.h
//  VideoUIBridge
//
//  Created by walt.li on 4/15/26.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMShareSource;

@interface ZMMTRemoteControlHelper : ZMBaseHelper

#pragma mark - Privilege Query (generic)

- (BOOL)isSomeoneHasPrivilegeWithUser:(ZMUser *)inUser;
- (BOOL)isSomeoneControllingUser:(ZMUser *)inUser;
- (BOOL)hasPrivilegeWithUser:(ZMUser *)inUser shareSourceUser:(ZMUser *)inShareSourceUser;
- (BOOL)isControllingWithUser:(ZMUser *)inUser shareSourceUser:(ZMUser *)inShareSourceUser;
- (nullable ZMUser *)getHasPrivilegeUserForUser:(ZMUser *)inUser;
- (BOOL)amIHasPrivilegeWithShareSource:(ZMShareSource *)shareSource;
- (BOOL)amIControllingWithShareSource:(ZMShareSource *)shareSource;

#pragma mark - Privilege Query (share sending side - ForMe convenience)

- (BOOL)isSomeoneHasPrivilegeForMe;
- (BOOL)isSomeoneControllingMe;
- (BOOL)isAttendeeHasPrivilegeForMe:(ZMUser *)inUser;
- (nullable ZMUser *)getHasPrivilegeUserForMe;

#pragma mark - Capability Query

- (BOOL)isShareSourceSupportRemoteControl:(ZMShareSource *)shareSource;
- (NSArray<ZMUser *> *)getCanRemoteControlUserArray;

#pragma mark - Control Action

- (void)grabRemoteControlWithShareSource:(ZMShareSource *)shareSource;
- (BOOL)assignPrivilegeWithShareSource:(ZMShareSource *)shareSource user:(ZMUser *)inUser allow:(BOOL)inAllow;
- (void)declineRemoteControlWithShareSource:(ZMShareSource *)shareSource user:(ZMUser *)inUser;

#pragma mark - Capability Query (share sending side - ForMe convenience)

- (BOOL)isMyShareSupportRemoteControl;

#pragma mark - Control Action (share sending side - ForMe convenience)

- (void)grabMyRemoteControl;
- (BOOL)assignMyPrivilegeForUser:(ZMUser *)user allow:(BOOL)allow;
- (void)declineMyRemoteControlForUser:(ZMUser *)user;

#pragma mark - Auto-accept / Copy-paste Settings

- (BOOL)isAutoAcceptRemoteControlEnabled;
- (BOOL)isAutoAcceptRemoteControlFeatureEnabled;
- (BOOL)isCopyPasteRemoteControlDisabled;
- (BOOL)isCopyPasteRemoteControlAllowed;
- (void)enableAutoAcceptRemoteControl:(BOOL)bEnable;
- (void)allowCopyPasteRemoteControl:(BOOL)bAllow;

#pragma mark - Accessibility

- (void)attemptPopupAXTrustedOption;

@end

NS_ASSUME_NONNULL_END
