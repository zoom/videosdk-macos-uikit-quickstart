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

@class ZMMTViewType;

@protocol IZMSharingSendingMgr <NSObject>
/// Whether private share is enabled
@property (nonatomic, readonly) BOOL isPrivateShareEnabled;
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

// ToolSuite
- (void)showShareSettingWindow;
- (void)closeShareSettingWindow;

- (void)showSelectShareWindow;
- (void)closeSelectShareWindow;

// Proctoring mode support
- (void)showStartShareAlertInProctoringMode:(BOOL)fromToolbar;

- (void)shareCameraWithDeviceId:(NSString*)deviceId;

// Share screen/window by ID
- (BOOL)startShareDesktopWithDisplayId:(NSNumber *)displayId;
- (BOOL)startShareWindowWithWindowId:(NSNumber *)windowId;

- (void)onWatermarkStatusChanged;

- (BOOL)mainWindowVisible;
- (BOOL)mainWindowVisibleInSendingShare;
- (BOOL)isEnableShareZoomWindows;

- (NSScreen*)getSharedScreen;

#pragma mark - ShareViewMgr functionality (formerly ZMMTShareViewMgr)

/// Create share view controller
/// @param type View type
/// @return View controller instance
- (nullable id<IZMMTSharingViewController>)newShareViewControllerWithType:(ZMMTType)type;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMShareMgrProcotol <NSObject>

@optional
- (void)shareSettingTypeChanged:(int)inNewType confSession:(ZMConfSession *)confSession;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMShareMgr_h */
