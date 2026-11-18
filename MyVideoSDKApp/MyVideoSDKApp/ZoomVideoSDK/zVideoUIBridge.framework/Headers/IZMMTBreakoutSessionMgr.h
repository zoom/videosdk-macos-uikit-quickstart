//
//  IZMMTBreakoutSessionMgr.h
//  VideoUI
//
//  Created by Howie Xu on 12/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTBreakoutSessionMgr_h
#define IZMMTBreakoutSessionMgr_h

@class ZMBOPollInfoModel;
@class ZMNextBODataMgr;

@protocol IZMBOSessionDataItem <NSObject>

@property (nonatomic, strong) NSString *sessionName;
@property (nonatomic, strong) NSString *sessionBID;
@property (nonatomic, assign, readonly) NSInteger attendeeCount;

@end

@protocol IZMMTBreakoutSessionMgr <ZMRoutableObject>
@property (nonatomic, assign, readonly) BOOL isBoConfReady;

- (BOOL)canEditBO;
- (NSInteger)maxBORoomCount;
- (void)showBOWindowFromPoll:(NSArray<ZMBOPollInfoModel *> *)pollInfoArray;
- (void)onPBOPermissionChanged:(NSInteger)oldPermission newPermission:(NSInteger)newPermission;
- (void)onPBORoomAdd:(NSInteger)roomCount;
- (void)updateCreateSessionDlg;
- (void)closeBroadVoiceIfNeeded;
- (BOOL)isDefaultConfigEnabled;
- (BOOL)isBOInStopping;
- (BOOL)isPBOUILoaded;
- (BOOL)isPBOReady;
/// Called by ZMPBOControlMgr.launchModule once the on-demand BreakoutRoom UI
/// bundle has finished loading mid-meeting, so the toolbar BO button and
/// main BO dialog can re-render against the now-available BO/PBO managers.
- (void)refreshBOUIAfterFeatureReady;
- (void)onPBOAttendeeMovedWithUniqueJoinIndex:(ZMUserID)uniqueJoinIndex
                                       roomID:(NSString *)roomID
                             isUserUnassigned:(BOOL)isUserUnassigned;
- (NSArray<id<IZMBOSessionDataItem>> *)getMovoToRoomsWithUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUnassignedUserWithUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (BOOL)canGetAttendeeByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;

@end

@protocol IZMMTBreakoutSessionProtocol <NSObject>

@optional
- (void)onReachParticipantLimits:(BOOL)reach isNextBO:(BOOL)isNextBO;
- (void)onBOCanReturnMainChanged;

@end

#endif /* IZMMTBreakoutSessionMgr_h */
