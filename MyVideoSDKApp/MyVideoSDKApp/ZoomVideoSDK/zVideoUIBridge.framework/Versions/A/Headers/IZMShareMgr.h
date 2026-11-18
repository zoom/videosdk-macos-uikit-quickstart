//
//  IZMShareMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMShareMgr_h
#define IZMShareMgr_h

#import <zVideoUIBridge/ZMMTVideoViewController.h>
#import <zVideoUIBridge/IZMMTSharingViewController.h>

NS_ASSUME_NONNULL_BEGIN

enum Support_Center_Share_Type
{
    Support_Center_Share_Type_None,
    Support_Center_Share_Type_Monitor,
    Support_Center_Share_Type_Window,
};

typedef NS_ENUM(NSInteger, ZMSendingShareType){
    ZMSendingShareType_Normal,
    ZMSendingShareType_Slides,
    ZMSendingShareType_WhiteBoard,
    ZMSendingShareType_ZDoc,
};

@protocol IZMSendShareCompatibleStreamMgr <NSObject>
@property (readonly, assign) NSInteger  shareSessionType;

@end

@protocol IZMMTShareCameraMgr <NSObject>
@property (nonatomic, readonly, strong) __kindof ZMMTVideoViewController *viewController;

// Start/Stop methods
- (void)startShareCameraWithDeviceId:(nullable NSString *)deviceId;
- (void)stopShareCamera;

// Camera control
- (void)switchShareCamera;
- (BOOL)isAble2ShowSwitchCamera;
@end

@protocol IZMMTShareVideoMgr <NSObject>
@property (nonatomic, readonly, strong) __kindof ZMMTVideoViewController *viewController;

// Start/Stop methods for ShareSender to call
- (void)startShareVideoFile:(NSString *)filePath;
- (void)stopShareVideoFile;
@end

@protocol IZMMTShareAudioViewController <NSObject>

- (void)requestCustomResourceIdForLocalRecord;
- (void)prepareForRecording:(BOOL)bForce;
- (uint32_t)getResourceIndexForRecording;
- (uint32_t)getBgResourceIndexForRecording;
@end

@protocol IZMMTShareAudioMgr <NSObject>
// ViewController management
- (nullable __kindof ZMMTVideoViewController *)newViewControllerWithType:(ZMMTType)type;
- (nullable __kindof ZMMTVideoViewController *)getViewControllerWithType:(ZMMTType)type;
- (nullable id<IZMMTShareAudioViewController>)getAudioViewControllerWithType:(ZMMTType)type;

// Pure computer audio share control (called from ShareEventSink)
- (void)onStartSendPureComputerAudio;
- (void)onStopSendPureComputerAudio;
- (void)onStartViewPureComputerAudio:(ZMUser *)inUser;
- (void)onStopViewPureComputerAudio:(ZMUser *)inUser;
- (void)tryStartViewPureComputerAudio;
@end

@protocol IZMMTShareAirhostMgr <NSObject>
/// Called when Airhost is published with network information
/// @param ssid Wi-Fi SSID
/// @param serverName Server name
/// @param displayScreen Display screen for the Airhost window (nullable)
- (void)onPublished:(NSString *)ssid
         serverName:(NSString *)serverName
      displayScreen:(NSScreen *)displayScreen;

/// Called when device is connected
- (void)onConnected;
/// Called when device is disconnected
- (void)onDisconnected;
/// Close the Airhost guidance window
- (void)closeWindow;
/// Show the Airhost guidance window
- (void)showWindow;
@end

@protocol IZMMTShareCableMgr <NSObject>
/// Show the trust computer indication window
/// @param displayScreen Display screen for the cable share window
- (void)showWindow:(NSScreen *)displayScreen;
/// Close the trust computer indication window
- (void)closeWindow;
/// Show sync alert with device name
/// @param name Device name
- (void)showSyncAlertWithName:(NSString *)name;
/// Close the sync alert
- (void)closeSyncAlert;
@end

/// Share sending side - Slide control manager (UI only)
@protocol IZMMTSlideControlMgr <NSObject>

@property (nonatomic, weak, nullable) ZMConfSession *confSession;

- (void)cleanUp;

- (BOOL)slideControlWindowIsShowing;
- (void)showSlideControlWindowWithViewFrameInScreen:(NSRect)frame inScreen:(NSScreen *)screen;
- (void)closeSlideControlWindow;

@end

/// Share sending side - Remote control manager
@protocol IZMMTRemoteControlMgr <NSObject>

@property (nonatomic, weak, nullable) ZMConfSession *confSession;

// Lifecycle
- (void)cleanUp;

// High-level actions
- (void)stopRemoteControl;
- (void)grabRemoteControl;
- (void)allowUserRemoteControlByUser:(ZMUser *)inUser;
- (void)forbidUserRemoteControlByUser:(ZMUser *)inUser;
- (void)receiveEvent:(NSEvent *)inEvent;
- (void)gainControl;

// Sink adapter callbacks (B group - kept as direct calls)
- (void)remoteControlRequestReceivedWithUser:(ZMUser *)inUser;
- (void)remoteControlPrivilegeChangedWithUser:(ZMUser *)inUser newControlUser:(ZMUser *)inNewControlUser;
- (void)remoteControlStatusChangedWithUser:(ZMUser *)inUser newControlUser:(ZMUser *)inNewControlUser;

// UI window management
- (BOOL)isRemoteControlWindowShowing;
- (void)showRemoteControlWindow:(NSRect)buttonFrame withScreen:(NSScreen *)screen;
- (void)closeRemoteControlWindow;

// Filter window (C group - kept as direct calls)
- (void)try2UpdateAllIgnoreMouseEventWindows;
- (void)try2UpdateIgnoreMouseEventZoomWindow:(CGWindowID)winID;

@end

/// Share sending side - Annotation (Presenter) manager
@protocol IZMMTAnnotationMgr <NSObject>

@property (nonatomic, weak, nullable) ZMConfSession *confSession;

- (void)cleanUp;

- (void)showBOShareAlertWithTarge:(id)target action:(SEL)action;
- (void)closeBOShareAlert;

@end

/// Share sending side - Remote support receiver (handles support requests from host)
@protocol IZMMTRemoteSupportRecvMgr <NSObject>

@property (nonatomic, weak, nullable) ZMConfSession *confSession;

- (void)cleanUp;
- (void)onSupportCenterResponseRemoteControlWithUser:(ZMUser *)inUser type:(int)inType isApproved:(BOOL)inApproved;
- (void)supportCenterRequestRemoteControlReceivedWithUser:(ZMUser *)inUser type:(int)inType;
- (void)supportCenterRequestRemoteControlInstallServerReceivedWithUser:(ZMUser *)inUser type:(int)inType;
- (void)setAutoShareController:(ZMUser *)inUser;
@end

/// Remote support request sender (host sends support requests to attendees)
@protocol IZMMTRemoteSupportRequestMgr <NSObject>

@property (nonatomic, weak, nullable) ZMConfSession *confSession;

- (void)cleanUp;
- (void)hideUserListWindow;
- (void)onSupportCenterRequestRemoteControlWithType:(int)inType;
- (void)supportCenterResponseRemoteControlReceivedWithUser:(ZMUser *)inUser type:(int)inType isApproved:(BOOL)inApproved;
- (void)userJoinedByUser:(ZMUser *)inUser;
- (void)userLeftByUser:(ZMUser *)inUser;
@end

@protocol IZMSharingSendingMgr <NSObject>
/// Whether private share is enabled
@property (nonatomic, readonly) BOOL isPrivateShareEnabled;
/// Window IDs currently being shared
@property (nonatomic, readonly) NSArray<NSNumber *> *sharingWindowIDs;
/// Send share options with private share setting
- (void)sendShareOptionsWithPrivateShare:(BOOL)isPrivate;
/// Assign private share receivers
- (void)assignPrivateShareReceivers:(NSArray<ZMUser *> *)receivers;
/// Check remote control privilege for private share
- (void)checkRemoteControlPrivilegeForPrivateShare;
@end

/**
 * @router ZMMTShared
 */
@protocol IZMShareMgr <ZMRoutableObject>
@property (nonatomic, readonly, strong) id<IZMMTShareCameraMgr> shareCameraMgr;
@property (nonatomic, readonly, strong) id<IZMMTShareVideoMgr> shareVideoMgr;
@property (nonatomic, readonly, strong) id<IZMMTShareAudioMgr> shareAudioMgr;
@property (nonatomic, readonly, strong) id<IZMSharingSendingMgr> sharingSendingMgr;
@property (nonatomic, readonly, assign) BOOL isEnableShareZoomWindows;

- (BOOL)isMainConfWindowNotVisibleWhileSharing;
- (void)onRemoteForbidded;

- (void)stopShare;
- (void)force2ShowSelections:(int)inType bForced:(BOOL)bForced;
- (NSScreen*)getFITScreen;
- (void)cleanZappShareInfo;
- (void)showFitBarForNotifyWithDelay;
- (void)updateBadge;

- (void)checkAndSetShareSettingType:(int)inType;
- (BOOL)canShowShareSettingMenu;

- (void)showSelectShareWindow;
- (void)closeSelectShareWindow;

// Proctoring mode support
- (void)showStartShareAlertInProctoringMode:(BOOL)fromToolbar;

- (void)shareCameraWithDeviceId:(NSString*)deviceId;

// Share screen/window by ID
- (BOOL)startShareDesktopWithDisplayId:(NSNumber *)displayId;
- (BOOL)startShareWindowWithWindowId:(NSNumber *)windowId;

- (void)onWatermarkStatusChanged;
- (void)onHighFrameRateContentSharingStatusChanged:(BOOL)shareEnable;

- (BOOL)mainWindowVisible;
- (BOOL)mainWindowVisibleInSendingShare;
- (BOOL)isEnableShareZoomWindows;

- (NSScreen*)getSharedScreen;

#pragma mark - ShareViewMgr functionality (formerly ZMMTShareViewMgr)

/// Create share view controller
/// @param type View type
/// @return View controller instance
- (nullable id<IZMMTSharingViewController>)newShareViewControllerWithType:(ZMMTType)type;
- (nullable id<IZMMTSharingViewController>)getShareViewControllerWithType:(ZMMTType)type;

@property (nonatomic, readonly, nullable) ZMShareSource *mainLastShareSource;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMShareMgrProcotol <NSObject>

@optional
- (void)shareSettingTypeChanged:(int)inNewType confSession:(ZMConfSession *)confSession;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMRemoteControlRecvStatusProtocol <NSObject>

@optional
- (void)onRCRecvStatusChanged;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMSlideControlEventProtocol <NSObject>

@optional
- (void)onSlideControlBadgeChanged:(int)badgeCount;
- (void)onSlideControlStopped;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMShareMgr_h */
