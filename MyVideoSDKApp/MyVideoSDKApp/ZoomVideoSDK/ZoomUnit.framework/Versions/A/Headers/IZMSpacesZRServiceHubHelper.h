//
//  IZMSpacesZRServiceHubHelper.h
//  ZoomUnit
//
//  Created by Walt.Li on 2025/1/21.
//  Copyright © 2025 Zoom. All rights reserved.
//

#ifndef IZMSpacesZRServiceHubHelper_h
#define IZMSpacesZRServiceHubHelper_h

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMSpacesZRAction) {
    ZMSpacesZRActionNone                              = 0,
    ZMSpacesZRActionJoinFromRoomOnly,  // ZR: idle, ZMC: idle
    ZMSpacesZRActionJoinFromRoomAndJoinAsCompanion,  // ZR: idle, ZMC: idle
        //ZMSpacesZRActionJoinFromMyDeviceOnly,  // ZR: idle, ZMC: idle
    ZMSpacesZRActionConnectAsCompanion,  // ZR: meeting, ZMC: idle
    ZMSpacesZRActionSwitchToMyDeviceOnly,  // 1)ZR: meeting, ZMC: idle; 2)ZR: meeting, ZMC: in companion mode
    ZMSpacesZRActionSwitchToRoomOnly,  // ZR: idle, ZMC: meeting
    ZMSpacesZRActionSwitchToCompanionMode,  // ZR: same meeting, ZMC: same meeting
    ZMSpacesZRActionJoinF2FMeetingFromRoomOnly,
};

@protocol IZMSpacesZRServiceHubHelper <ZMRoutableObject>
- (BOOL)allowPairInPT;
- (BOOL)allowPairInConfBar;
- (BOOL)isPaired;
- (BOOL)isPairedZRInMeeting;
- (BOOL)isPairedZRInMyMeeting;
- (BOOL)isPZR;
- (BOOL)isSupportOpenApp;
- (BOOL)isSupportOpenAppInMeeting;
- (nullable NSString *)roomJid;
- (nullable NSString *)roomName;
- (nullable NSString *)sharingKey;
- (nullable NSString *)resourceId;
- (nullable NSString *)deviceId;
- (nullable NSString *)meetingNumber;
- (nullable NSString *)metingTitle;
- (BOOL)isSupportSwitchComputer;
- (BOOL)isSupportSwitchComputerOnly;
- (BOOL)isSupportConnectCompanionMode;

- (void)openWBOnZR:(NSString *)docId;
- (void)openAppOnZRWithAppId:(NSString *)appId
                     appName:(NSString *)appName
            runningInMeeting:(BOOL)runningInMeeting
                   targetUrl:(nullable NSString *)targetUrl;

- (BOOL)joinMeetingFromZRAndAsCompanion:(NSString *)meetingNumber
                             meetingPwd:(NSString *)meetingPwd
                              vanityUrl:(NSString *)vanityUrl
                                 domain:(NSString *)domain
                    isEventDirectMeeting:(BOOL)isEventDirectMeeting
                  eventDirectMeetingUrl:(NSString *)eventDirectMeetingUrl
                                 isHost:(BOOL)isHost;
//normal entry for room only, not by join button
- (BOOL)joinMeetingOnZROnly:(NSString *)meetingNumber
                 meetingPwd:(NSString *)meetingPwd
                  vanityUrl:(NSString *)vanityUrl
                     isHost:(BOOL)isHost;
- (BOOL)joinMeetingOnZROnly:(NSString *)meetingNumber
                 meetingPwd:(NSString *)meetingPwd
                  vanityUrl:(NSString *)vanityUrl
                     isHost:(BOOL)isHost
               byJoinButton:(BOOL)byJoinButton;
- (BOOL)connectAsCompanion:(NSString *)meetingNumber;
- (BOOL)switchMeetingToZR:(NSString *)meetingNumber;
- (BOOL)switchMeetingToMyDevice:(NSString *)meetingNumber;
- (BOOL)switchToCompanionMode:(NSString *)meetingNumber;

- (void)updateCoachMarkRegistration;
- (void)showCoachMark:(NSView *)view;
- (void)closeCoachMark;

- (BOOL)shouldShowActionInConfToolbar;
- (ZMSpacesZRAction)getActionInConfToolbar;
@end

@protocol ZMSpacesZRServiceHubHelperProtocol <NSObject>

@optional
- (void)onZRServicePairOptionChanged;
- (void)onZRServicePairStatusChanged;
- (void)onZRServicePairedZRConfChanged;
- (void)onZRServiceUpdateMeetingBannerAction;
- (void)onZRServicePairedZRMeetingActionChanged;
- (void)onZRServiceMeetingTopRightPairItemAnimationBegin;
- (void)onZRServiceMeetingTopRightPairItemAnimationEnd;
@end

NS_ASSUME_NONNULL_END
#endif /* IZMSpacesZRServiceHubHelper_h */
