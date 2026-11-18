//
//  IZMPBOControlMgr.h
//  VideoUI
//
//  Created by Javenlee Li on 2023/2/28.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMultiConfEventDelegate.h>

@class ZMPBORoomModel, ZMPBOUserModel, ZMPBOUserListDataManager;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMPBOControlMgr <ZMRoutableObject>

- (void)onFeatureReady;
- (BOOL)canInvitePBO;
- (BOOL)canBeInvitePBO:(ZMUser *)user;
- (BOOL)inviteToPBO:(ZMUser *)user;
- (BOOL)isInvitedUser:(ZMUser *)user;
- (BOOL)moveOutPBO:(NSInteger)roomID user:(ZMUser *)user;
- (BOOL)closePBO:(NSInteger)roomID;

- (void)onUserRosterChanged:(ZMMTRosterList *)roster session:(ZMConfSession*)session;

- (NSString *)sessionName;

- (ZMPBOUserListDataManager *)getUserListDataManager;

- (NSViewController *)createPBOListController;
- (ZMMTBaseView *)createPBOEmptyView;

@end

@protocol IZMPBOControlRoomUpdateProtocol <NSObject>

@optional
- (void)onRoomAdd:(NSArray<ZMPBORoomModel *> *)rooms;
- (void)onRoomRemove:(NSArray<ZMPBORoomModel *> *)rooms;
- (void)onRoomUpdate:(NSArray<ZMPBORoomModel *> *)rooms;
- (void)onPBORoomCountUpdate:(NSInteger)count;

@end

@protocol IZMPBOControlUserUpdateProtocol <NSObject>

@optional
- (void)onPBOUserAdd:(NSArray<ZMPBOUserModel *> *)users;
- (void)onPBOUserRemove:(NSArray<ZMPBOUserModel *> *)users;
- (void)onPBOUserUpdate:(NSArray<ZMPBOUserModel *> *)users;
- (void)onPBOUserChanged:(NSArray<ZMPBOUserModel *> *)users uniqueJoinIndex:(ZMUserID)uniqueJoinIndex;

- (void)onUserRosterAdd:(NSArray<ZMPBOUserModel *> *)users;
- (void)onUserRosterRemove:(NSArray<ZMPBOUserModel *> *)users;
- (void)onUserRosterUpdate:(NSArray<ZMPBOUserModel *> *)users;

- (void)pboUserAvatarChangedByCoalesce:(NSArray<ZMPBOUserModel *> *)users;

@end

@protocol ZMPBOEventDelegate <ZMMultiConfEventDelegate>
@end

NS_ASSUME_NONNULL_END
