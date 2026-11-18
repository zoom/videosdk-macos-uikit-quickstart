//
//  IZMMTZrcMgr.h
//  ZoomUnit
//
//  Meeting-side Zoom Room Controller interface. Replaces the older
//  ZMConfZrcProtocol. Includes:
//    - IZMMTZrcMgr : sync read/action API backed by the conf-process
//      C++ zm_service_hub ZR_SERVICE (no IPC at the Obj-C boundary).
//    - ZMMTZrcProtocol : notification sink fired by the conf-side
//      service-hub listener. Mirrors the PT-side
//      ZMSpacesZRServiceHubHelperProtocol so conf subscribers do not
//      depend on the PT-owned helper. [ZOOM-1197031]
//
//  Created by walt.li on 9/16/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTZrcMgr_h
#define IZMMTZrcMgr_h

#import <Foundation/Foundation.h>

// Meeting-side mirror of ZMSpacesZRAction (defined in
// IZMSpacesZRServiceHubHelper.h). Enum values are identical so the
// integer payload carried by the C++ ZR_SERVICE response decodes the
// same way on both sides. Kept here so conf-side callers don't have
// to transitively import the PT-owned helper header. [ZOOM-1197031]
typedef NS_OPTIONS(NSUInteger, ZMMTSpacesZRAction) {
    ZMMTSpacesZRActionNone                              = 0,
    ZMMTSpacesZRActionJoinFromRoomOnly,                 // ZR: idle,    ZMC: idle
    ZMMTSpacesZRActionJoinFromRoomAndJoinAsCompanion,   // ZR: idle,    ZMC: idle
    ZMMTSpacesZRActionConnectAsCompanion,               // ZR: meeting, ZMC: idle
    ZMMTSpacesZRActionSwitchToMyDeviceOnly,             // ZR: meeting, ZMC: idle / companion
    ZMMTSpacesZRActionSwitchToRoomOnly,                 // ZR: idle,    ZMC: meeting
    ZMMTSpacesZRActionSwitchToCompanionMode,            // ZR: same meeting, ZMC: same meeting
    ZMMTSpacesZRActionJoinF2FMeetingFromRoomOnly,
};

@protocol IZMMTZrcMgr <ZMRoutableObject>

@property (assign, readonly) BOOL supportSwitchMeeting;

- (BOOL)canShowRoomControllerButton;
- (void)openZRCApp;

#pragma mark - ZR servicehub (conf-side read/actions)
// Conf-process accessors for the same C++ zm_service_hub ZR_SERVICE
// that PT's ZMSpacesZRServiceHubHelper queries. Implementing them
// locally so conf code does not depend on the PT-owned router target.

- (BOOL)isPaired;
- (BOOL)isPairedZRInMeeting;
- (BOOL)isPairedZRInMyMeeting;
- (BOOL)allowPairInPT;
- (BOOL)allowPairInConfBar;
- (BOOL)isSupportOpenApp;
- (BOOL)isSupportOpenAppInMeeting;
- (nullable NSString *)meetingNumber;
- (nullable NSString *)roomName;
- (nullable NSString *)sharingKey;

- (BOOL)switchMeetingToZR:(NSString *)meetingNumber;
- (BOOL)switchMeetingToMyDevice:(NSString *)meetingNumber;
- (BOOL)switchToCompanionMode:(NSString *)meetingNumber;

- (void)openAppOnZRWithAppId:(NSString *)appId
                     appName:(NSString *)appName
            runningInMeeting:(BOOL)runningInMeeting
                   targetUrl:(nullable NSString *)targetUrl;

- (BOOL)shouldShowActionInConfToolbar;
- (ZMMTSpacesZRAction)getActionInConfToolbar;

@end

#pragma mark - Conf-side ZR notification sink

// Fired by ZMConfZrcMgr's local C++ service-hub listener — keeps conf
// subscribers process-local (no dispatch across PT/Meeting boundary).
// Method signatures intentionally match ZMSpacesZRServiceHubHelperProtocol
// so existing conf-side handlers carry over verbatim.
@protocol ZMMTZrcProtocol <NSObject>
@optional
- (void)onZRServicePairOptionChanged;
- (void)onZRServicePairStatusChanged;
- (void)onZRServicePairedZRConfChanged;
- (void)onZRServiceUpdateMeetingBannerAction;
- (void)onZRServicePairedZRMeetingActionChanged;
- (void)onZRServiceMeetingTopRightPairItemAnimationBegin;
- (void)onZRServiceMeetingTopRightPairItemAnimationEnd;
@end

#endif /* IZMMTZrcMgr_h */
