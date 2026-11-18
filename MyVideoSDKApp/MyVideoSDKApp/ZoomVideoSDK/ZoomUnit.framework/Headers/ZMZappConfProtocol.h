//
//  ZMZappConfProtocol.h
//  zAppUI
//
//  Created by TOTTI on 11/10/21.
//  Copyright © 2021 us.zoom. All rights reserved.
//

#ifndef ZMZappConfProtocol_h
#define ZMZappConfProtocol_h

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import <Prism/ZMBaseMenuItem.h>
#import <Prism/ZMCallbackImpl.h>
#import <Prism/ZMHotkeyConfiguration.h>
#import <Prism/ZMPigment.h>
#import <Prism/ZMRoutableObject.h>
#import <Prism/ZMSizeScaleFactor.h>
#import <ZoomUnit/ZMSidePanelItem.h>
#import <ZoomUnit/ZPZAppAdapter.h>
#import <ZoomUnit/ZMZappVirtualEffectsProtocol.h>

@class ZMZAppsInteractInfo, PZMToastCoordinator, ZMAppearance;
@class ZMZAppConfShareInfo, ZPShareSelectWindowModel, ZMUser;
@class ZMZappDownloadParam, ZMZAppLauncherConfig;
@class ZMBubbleObject;
@protocol ZMSidePanelItem;

@protocol ZMZappConfProtocol <ZMRoutableObject, ZMZappVirtualEffectsProtocol>
// Conf owns a process-local module-loaded flag in both single- and multi-process
// modes. This does not imply that meeting-scoped UI capabilities are ready.
- (BOOL)isZappModuleLoaded;
- (BOOL)isConfZappServiceReady;

@optional
- (BOOL)isAllowUseZapp;
- (BOOL)isSupportMeetingLightMode;
- (ZMAppearance *)meetingDrawingAppearance;
- (void)onJ2cCloudRecordControl:(NSString *)appId state:(ZAppCloudRecordCmd)cmdState;
- (void)showDisableByHostAlert:(BOOL)host;
- (void)showNormalAlertWithString:(NSString *)alertString;
- (void)showUnavailableZappAlert;
- (BOOL)isZAppEnable;
- (BOOL)checkZappCanSendShare:(NSDictionary *)shareParam;
- (BOOL)checkCanSharePureAudio;
- (ZMZAppPromptShareStatusCode)checkCanShowPromptShareScreen:(ZMZAppShareScreenInfo *)shareInfo;
- (void)startSharePureAudio:(NSString *)appId isMono:(BOOL)isMono requestId:(NSString *)reqId;
- (BOOL)checkAndshowAlertWhenAnyoneIsSharing;
- (BOOL)isMultiShareEnable;
- (BOOL)isReceivingComputerAudio;
- (BOOL)isEnableAudioShare;
- (void)UpdateTopBarOriginalSoundItemInMeeting;

- (void)showZappSharePannelByInvitationInfo:(ZMZappConfShareConfigure *)invitationInfo
                                     Window:(NSWindow *)inWindow
                                       type:(ZMZAppInvitationAlertType)type;
- (BOOL)try2ShowMeetingInvitationDialog;
- (BOOL)isMiniMode;
- (BOOL)isConfWindowVisible;
- (BOOL)isSendingShare;
- (BOOL)isFullScreen;
- (BOOL)isInSilentMode;
- (BOOL)isShareEnable;
- (BOOL)isShareDisabledByExternalLimit;
- (BOOL)hasChatPrivilege;
- (BOOL)isChatOff;
- (void)disableZAppInConf;
- (void)enableZAppInConf;
- (void)stopShare;
- (void)updateZappMessageIconWithId:(NSString *)appId iconPath:(NSString *)iconPath;
- (void)onZappMessageUpdated:(NSString *)msgId thumbnailPath:(NSString *)thumbnailPath;
- (void)shareWindowUpdateZappStatusByClose:(NSString *)appId;
- (void)trackShareWindowAppInteraction:(ZAppShareWindowLocation)location event:(ZMZAppViewCtrlActionType)event appId:(NSString *)appId;
- (BOOL)isSelectShareWindowShowing;
- (void)updateZappMessageNameWithHeader:(ZPZAppHeader *)header;
- (void)updateZappMessageNameWithLoginStatus:(BOOL)logined;
- (NSView *)getSidePanelView;
- (NSView *)getHeadViewExpandButton;
- (CGFloat)getSidePanelWidth;
- (BOOL)isSidePanelShow;
- (BOOL)isZappWindowSharing:(NSString *)appName; // will capture share models, use carefully to avoid performance issue
- (BOOL)startZappWindowShare:(NSString *)windowTitle withParam:(NSDictionary *)shareParam;
- (void)popOutAppWindow;
- (void)setAppWindowFrame:(NSRect)windowRect;
- (void)closeAppWindow;
- (void)removeZappsView;
- (PZMToastCoordinator *)getConfToastCoordinator;
- (void)updateSidePanelContentView:(NSView *)contentView;
- (id<ZMSidePanelItem>)getZappSidePanelItem;
- (NSWindow *)getAppPopOutWindow;
- (BOOL)isAppWindowVisibleOrMiniaturized;
- (void)sidePanelContainerMergeBack;
- (void)showZappViewInPanel;
- (BOOL)isZappsViewInSidePanel;
- (void *)getConfZappAPI;
- (void)showUnableScreenRecordingAlert;
- (void)reloadZappShareModel;
- (void)updateZappModelImage:(NSImage *)snapshotImage appId:(NSString *)appId;
- (BOOL)isConfReady;
- (void)getZappHeadById:(NSString *)appId completion:(void (^)(ZPZAppHeader *header, NSError *error))completion;
- (void)onGetZappHeaderInConf:(NSString *)key header:(ZPZAppHeader *)header;
- (void)showMeetingInviteWindow;
- (void)expandSidePanel:(BOOL)isExpand;
- (BOOL)isSidePanelExpand;
- (BOOL)isEnabledShareZoomWindows;
- (BOOL)canShareZoomWindows;
- (void)logMMREvent:(NSDictionary *)param;
- (BOOL)needShowZappButton;
- (BOOL)canUseZappFeature;
- (BOOL)isWebinar;
- (BOOL)isViewOnlyMeeting;
- (BOOL)isReceivingSharing;
- (NSString *)getMySelfName;
- (NSString *)getMySelfEmail;
- (void)onPTLogout;

- (BOOL)isHost:(unsigned int)userId;
- (BOOL)isCohost:(unsigned int)userId;
- (BOOL)amIHostCohost;
- (BOOL)amIHost;
- (BOOL)amIMasterConfHost;
- (NSString *)getUserNameById:(NSUInteger)userId;
- (NSString *)getUserEmailById:(NSUInteger)userId;

- (zappEnableState)getZappEnableState;
- (NSScreen *)getFITScreen;
- (NSImage *)getDisplayAvatarByUserId:(int)inUserId constrainSize:(NSSize)inSize;

- (void)hideAllBODialogs;
- (BOOL)areBODialogsVisible;
- (void)openZAppPushedTip:(NSString *)tipInfo appId:(NSString *)appId;
- (void)closeZAppPushedTip;
- (BOOL)isWebinarOpenZAppPushedTipExists;
- (NSInteger)getConfStatus;
- (BOOL)toggleAudio;
- (BOOL)toggleVideo;
- (BOOL)switchMeetingViewWithType:(ZMZAppSetMeetingViewInfo *)setMeetingViewInfo;
- (NSArray *)getMeetingViewType;
- (BOOL)isInGalleryView;
- (void)closeZappShareViewIfNeed:(NSString *)appId;
- (void)rtmsStatusChange;

#pragma mark - Bullet
- (void)openBulletApp:(NSViewController *)appViewCtrl;
- (void)closeBulletApp;
- (void)onHandleBulletEnableArea:(NSArray<NSValue *> *)array;
- (void)jumpToMsg:(NSString *)msgId;

#pragma mark - Collaborate
- (void)showChange2ShareFromCollaborateAlert:(NSDictionary *)extendShareParam;
- (BOOL)isMySelfForUserId:(unsigned int)userId;
- (BOOL)isMySelfForUniqueJoinIndex:(NSUInteger)uniqueJoinIndex;
- (NSString *)getUserNameOfUniqueJoinIndex:(NSUInteger)uniqueJoinIndex fromBoMaster:(BOOL)fromBoMaster;
- (NSImage *)getUserAvatarOfUniqueJoinIndex:(NSUInteger)uniqueJoinIndex fromBoMaster:(BOOL)fromBoMaster;
- (BOOL)isHostCohostWithUninqueJoinIndex:(NSUInteger)uniqueJoinIndex fromBoMaster:(BOOL)bFromBoMaster;
- (NSRect)getCollaborateWindowFrame;
- (BOOL)isSendingSharingZappCollaborateWindow;
- (BOOL)isSendingAnySharing;
- (BOOL)isSendingComputerAudio;
- (void)stopSendingExistSharing;
- (void)showJoinCollaborateConfTipwithInfo:(ZMZAppToastInfo *)appInfo
                            isPlayTogether:(BOOL)isPlayTogether
                              notiDelegate:(id<ZMZappNotificationDelegate>)notiDelegate;
- (void)reloadTips;
- (void)closeZAppCollborateTipIfNeed;
- (BOOL)isZAppCollaborateTipExisted;
- (void)updateCollaborateTipTitleWithAppId:(ZMZAppCollaborateData *)collaborateData appName:(NSString *)appName;
- (void)onCollaborateStatusChange;
- (BOOL)isCollaborateAppFirstTimeClose;
- (void)setIsCollaborateAppFirstTimeClose:(BOOL)isFirstTimeClose;
- (BOOL)isBOSession;
- (BOOL)isNewBoSession;
// Classic BO join/leave respawns the Conf process. The new process must restore
// the kept-app roster from PT instead of rerunning the local AutoOpen setting.
- (BOOL)isBOTransitionLaunch;
- (BOOL)isDisplayAsHostCoHost:(int)nUserID;
- (void)bringWindowToFront;
- (BOOL)changeCollabPolicy:(ZMZAppCollaborateData *)collaborateData stopRunningCollaboration:(BOOL)needStop;
- (BOOL)isMMRSupprtCollabration:(BOOL)bFromBoMaster;
// new dock
- (void)requestHideToolbarAnimate;

//keep apps in meeting
- (void)updateZAppBadge:(NSUInteger)count;

- (BOOL)canZappJoinGuestMode;
- (void)showUnavailableZappToast:(zappEnableState)type;

@optional
// Avoid Category Build Issues
#pragma mark - Layers
- (BOOL)initPulginView:(NSView *)pluginView
          headerHeight:(CGFloat)headerHeight
            renderType:(ZAppRenderType)renderType
            cutoutType:(ZMZappLayersCutoutType)cutoutType;
- (BOOL)clearPulginView:(ZAppRenderType)renderType;

// Participant
- (BOOL)drawParticipantView:(NSString *)zAppID renderType:(ZAppRenderType)renderType info:(ZMZAppDrawParticipantInfo *)info;

- (BOOL)clearParticipantView:(UInt32)userID zAppID:(NSString *)zAppID renderType:(ZAppRenderType)renderType;

- (void)drawParticipants:(NSArray<id<ZMMTZappPluginModel>> *)participants withAnimation:(BOOL)animation;

- (void)clearParticipants:(NSMutableArray<NSNumber *> *)participantsNodeIds;

// Image
- (BOOL)drawImage:(NSImage *)image
          imageID:(NSString *)imageID
            frame:(CGRect)frame
           zIndex:(NSInteger)zIndex
            appID:(NSString *)appID
       renderType:(ZAppRenderType)renderType;
- (BOOL)clearImage:(NSString *)imageID appID:(NSString *)appID renderType:(ZAppRenderType)renderType;

// VF
- (BOOL)setFilterImage:(NSString *)reqID
                 appID:(NSString *)appID
                 image:(NSImage *)image
                infoID:(NSString *)infoID
                 frame:(CGRect)frame
                zIndex:(NSInteger)zIndex;
- (void)clearVFImageResource;
- (ZMZappLayersCutoutType)getCurrentCutoutType;
- (NSSize)getCurrentVideoSize;

// ZApp video filter / virtual background — conf-local twins of ZMZappPTProtocol
// (conf reads via IZMVirtualEffectsMgr / ZMDownloadViewMgrProtocol / ps, no cross-process)
- (void)downloadAomhostCompletion:(void (^)(BOOL))completion;
- (BOOL)setVideoFilter:(NSString *)filterName imagePath:(NSString *)imagePath thumbPath:(NSString *)thumbPath filterOption:(NSInteger)option;
- (BOOL)couldSelectVideoFilter;
- (void)setZappVBWithPath:(NSString *)filepath imageName:(NSString *)VBimageName isVBGen:(BOOL)isVBGen eventId:(NSString *)reqId;
- (void)selectVBItemById:(NSString *)vbId eventId:(NSString *)reqId;
- (void)OnVirtualBackgroundSet:(NSUInteger)errorCode eventId:(NSString *)eventId;
- (void)selectLastVBItem;
- (void)checkAomHostUpdateCompletion:(void (^)(BOOL, NSUInteger))completion;
- (BOOL)isPTLogin;
// Refreshes Conf-owned video effects after a JS SDK setting change.
- (void)OnRefreshSettingWithType:(ZAppRefreshSettingType)type;
// Stops the Conf preview before an HD change.
- (void)OnHDSettingWillChange;


- (BOOL)drawScreenWithinfo:(ZMLocalShareDrawScreenInfo *)info;
- (BOOL)clearScreen;
- (void)onShowTeamChatStateChange;
- (BOOL)getAudioJoinedState;
- (void)setAudioJoinedState:(BOOL)state;
- (BOOL)getUserMediaAudio;
- (void)setUserMediaAudio:(BOOL)state;
- (void)onSidebarSizeChange:(NSString *)sidebarSize;
- (void)onUserWithIDStatusChanged:(unsigned int)userID;
- (void)onUserWithGUIDStatusChanged:(NSString *)userGuid;
- (BOOL)showCaptions;
- (BOOL)hideCaptions;
- (BOOL)getCaptionsState:(BOOL *)captionsState;
- (void)zmPromptWhiteboard;
- (void)onCaptionsStateChange:(BOOL)captionsState;
- (BOOL)testSpeakerAndMicrophone;
- (void)onWhiteboardShare:(BOOL)isWhiteBoardSharing;

// Camera Mode Related
- (void)stopCameraModeWork;
- (void)startCameraModeWork;
- (void)cameraModeInputSnapshotBuffer:(void *)buffer size:(CGSize)size;
- (BOOL)drawWebView:(NSString *)reqID appID:(NSString *)appID webViewID:(NSString *)webViewID frame:(CGRect)frame zIndex:(NSInteger)zIndex;
- (BOOL)clearWebView:(NSString *)reqID appID:(NSString *)appID;

- (NSString *)getZRCAppId;
- (void)setSidePanelWidth:(CGFloat)panelWidth;

- (BOOL)canOpenZapp;
- (void)updateToolbarZappButton;
- (void)closeAllZappToast;
- (void)cleanShareViewForAppId:(NSString *)appId;
- (void)closeZappShareView;
- (void)updateToastAndZappMessageWithZappState:(BOOL)enable;

- (BOOL)canOpenZappLauncher:(BOOL)openDiscover;
- (NSSize)getCurrentSidePanelSize;

- (void)addParticipantPins:(NSArray *)participantIDs secondaryDisplay:(bool)seconaryDisplay;
- (void)removeParticipantPins:(NSArray *)participantIDs secondaryDisplay:(bool)seconaryDisplay;
- (BOOL)canPinMultipleParticipants;
- (void)addParticipantSpotlight:(NSNumber *)participantId reqId:(NSString *)reqId;
- (void)removeParticipantSpotlights:(NSArray<NSNumber *> *)participantIDs;
- (NSArray<NSNumber *> *)getParticipantSpotlights;
- (NSUInteger)getPinnedUsersCount;
- (void)hideNonVideoParticipants:(BOOL)bHide;
- (BOOL)isWallViewMode;
- (NSNumber *)getTotalGalleryPages;
- (NSNumber *)getCurrentGalleryPage;
- (void)setGalleryPage:(NSUInteger)galleryPage;

- (void)onPumpSnapshot:(NSImage *)image size:(CGSize)size;

//ZOOM-431615
- (void)trackZappJ2CInteraction:(NSString *)appId action:(ZAppOpenAppAction)type;
- (void)trackZappJ2CAuthInteraction:(NSString *)appId result:(BOOL)authResult;
- (void)trackZappActionInteraction:(NSString *)appId action:(NSUInteger)type;
//ZOOM-449731
- (void)trackZappInteraction:(ZMZAppsInteractInfo *)interactInfo;
- (void)trackZappTransfer2ZRInteraction;
- (void)onFailedOpenAppOnZR:(ZMZAppOpenInZRErrorCode)errorCode
                    appName:(nullable NSString *)appName;
- (void)initBundle;
- (void)tryLoadZoomApps:(nullable void (^)(BOOL result))completion;

//ZOOM-464036
- (void)onZappsTimerUpdateIndication:(ZMZAppDynamicIndicatorInfo *)indicatorInfo;
- (void)appTimerRefresh;
- (BOOL)canRemoveTimer:(NSString *)appId;
- (void)removeTimer:(NSString *)appId;
- (void)removeTimerIfNeed:(NSString *)appId;
- (void)updateConfIconWithId:(NSString *)appId iconPath:(NSString *)iconPath;
- (BOOL)isTimerAppEnable;
- (BOOL)isTimerAppEnableOrTimerSetted;
- (BOOL)appTimerNeedShowMenu;
- (BOOL)isZappTimerSelected;
- (ZPZAppHeader *)getTimerAppHeader;
- (NSString *)getTimerAppId;
- (void)appStatusChange;
- (NSArray<ZMBaseMenuItem *> *)getTimerAppMenu;

//ZOOM-494927
- (BOOL)broadcastVoiceToBo:(BOOL)start;
- (BOOL)canBroadcastVoiceToBo:(BOOL)start;

- (void)showAssignAndLeaveWindow:(NSWindow *)window;

// ZOOM-464198
- (NSString *)getBrandingDomain;
#pragma mark - Meeting Profile
- (void)onJ2cGetParticipantProfilePic:(NSString *)reqId appId:(NSString *)appId participantId:(NSString *)participantId;
- (BOOL)isLeavingMeeting;
- (void)setShowAvatar:(BOOL)avatarState;
- (BOOL)isShowAvatar;

- (NSArray *)getVideoOrderList:(ZAppMeetingViewType)viewType;

- (BOOL)isAudioShareEnabled;
- (BOOL)isSharingPureComputerAudio;
// ZOOM-464198
- (BOOL)isMeetingBridgeBundleLatest;

- (BOOL)isPushToTalkEnabled;

- (void)onClosedCaptionSettingChanged:(NSString *)settingKey;

//local share
- (BOOL)isZappWindowLocalSharing:(NSString *)appName;
- (void)stopLocalShare;
- (BOOL)isLocalShareOn;

- (void)onMyAudioTypeChanged;
- (void)onAudioConnectStatusChanged:(NSUInteger)userID;
- (void)onMyVideoStatusChanged;
- (void)onTitlebarMoreButtonClicked;
- (void)onHotkeyValueDidChange:(ZMHotkeyName)hotkeyName;
- (NSData *)getFileDataFromRequest:(NSURLRequest *)request;
- (void)bringScreenShareWindowToFront;
- (void)bringWhiteboardWindowToFront;
- (void)getCurrentShareInfo:(ZMGetCurrentShareInfo *)getCurrentShareInfo;
- (BOOL)IsScreenSaverActive:(int *)isScreenSaverActive;
- (BOOL)GetUserLastInputElapsedTimeSec:(UInt64 *)timeSec;
- (BOOL)DisableScreenSaver;
- (BOOL)EnableScreenSaver;
- (BOOL)isNeedShowAvatarMenuItem;

// File Picker
- (void)zmCloseWebview:(NSString *)webViewID isGoBack:(BOOL)isGoBack;
- (void)zmStartFileScreenShare:(NSString *)webViewID
                       fileURL:(NSString *)fileURL
               isCollaboration:(BOOL)isCollaboration
                      fileName:(NSString *)fileName
                       appName:(NSString *)appName
             completionHandler:(void (^)(ZMZAppPromptShareStatusCode statusCode))completionHandler;

- (void)zmSystemBrowserCollaboration:(NSString *)fileURL completionHandler:(void (^)(ZMZAppPromptShareStatusCode statusCode))completionHandler;

- (void)zmHideWebview:(NSString *)webViewID;
- (void)zmStopFilePicker;
- (NSString *)zmGetFilePickerCollaborateAppWebviewId;
- (void)showLoginUI;
- (void)backToLegacyShare:(NSString *)webViewID;
- (void)showJoinDocCollaborationTip:(BOOL)requestEmail docURL:(NSString *)docURL userID:(UInt64)userID;
- (void)closeFilePickerTips:(UInt64)userID;
- (void)onAttendeeRemoved:(NSString *)jid;

- (BOOL)isAlwaysShowUserName;
- (void)setAlwaysShowUserName:(BOOL)on;

- (NSWindow *)getConfMainWindow;
- (BOOL)isE2EEncMeeting;
- (BOOL)willAutoFullScreenAfterConfReady;
- (void)rtmsButtonClicked:(NSButton *)sender;
- (void)rtmsButtonHoverExited;
- (void)scheduleCloseRTMSPanel;
- (ZMBubbleObject *)getRTMSBubbleObject;
- (NSView *)getRTMSPositionView;
- (void)showConfPoppingUpTip:(NSString *)message;
- (BOOL)isGuestUser:(NSUInteger)userId;
- (BOOL)isGuestUserByIndex:(NSUInteger)ownerIndex;
- (void)showRTMSTips:(NSString *)tips;
- (void)closeRTMSTips;
- (void)showConfToolBar;
- (BOOL)isConfToolBarHidden;
- (void)removeUserByIndex:(NSUInteger)ownerIndex;
- (BOOL)isANNAppActive;
- (BOOL)isAppSignalReady;
- (void)stopLiveStream;
- (BOOL)isLivestreamMenuDisabled;
- (NSInteger)appSignalTipDisplayTimes;
- (void)addAppSignalTipDisplayTimes;

- (void)jumpZappByShareInfo:(ZMZAppConfShareInfo *)shareInfo;
- (void)handleZAppButtonClicked:(id)sender;
- (void)sendingShareDidStopped;
- (void)sendInvitationWithType:(NSInteger)messageType appId:(NSString *)appId receiveId:(int)receiveId receiveName:(NSString *)receiveName;
- (void)cleanAllMirrorApps;
- (void)onMasterConfHostChanged;
- (void)onBOModeratorChanged;
- (void)onUserJoined;
- (void)onUserLeft:(ZMUser *)user;
- (void)windowDidEnterFullScreen;
- (void)windowDidExitFullScreen;
- (void)windowDidResize;
- (void)mainVideoViewSizeDidChanged;
- (void)shareZappBy:(NSDictionary *)shareParam;
- (BOOL)sendAppToSelectedAttendeesWithAppId:(NSString *)appId
                                       name:(NSString *)appName
                             invitationInfo:(ZMZappConfShareConfigure *)invitationInfo
                                  attendees:(NSDictionary *)attendees
                                   menuType:(NSUInteger)menuType;
- (BOOL)sendAppToAllAttendeesWithAppId:(NSString *)appId name:(NSString *)appName invitationInfo:(ZMZappConfShareConfigure *)invitationInfo type:(NSUInteger)type;
- (BOOL)shareVirtualBackground:(NSString *)filePath appId:(NSString *)appId menuType:(ZMZAppSendMenuType)menuType attendees:(nullable NSArray *)attendees;
- (BOOL)needShowAllParticipatesInWebinar:(NSString *)appId;
- (void)setMTShareAppId:(NSString *)appId;
- (void)shareZappInPanel:(NSDictionary *)shareParam;
- (void)onSwitchMinimalVideoMode:(BOOL)toMinimal;
- (BOOL)isZappNewDockShowing;
- (void)windowWillEnterFullScreen;
- (void)setShouldPersistApp:(BOOL)persist;
- (void)setMainWindowWidth:(CGFloat)width;
- (void)OnToggleZappFeature:(NSInteger)state;
- (void)onConfReady;
- (void)onBOConfReady;
- (void)sendingShareDidStarted;
- (void)receiveInvitationFrom:(NSString *)displayName shareInfo:(ZMZAppConfShareInfo *)shareInfo;
- (void)onAllowAttendeeChatStatusChanged;
- (void)onHostChanged:(ZMUser *)theUser;
- (void)onCoHostChanged:(ZMUser *)theUser;
- (ZPShareSelectWindowModel *)getZappPanelShareModel;
- (void)showPushedAppToastIfNeed;
- (BOOL)isCenterCollaborateLayoutStyle;
- (BOOL)isMySelfCollaborateSender;
- (void)switchToCollaborateMode:(NSWindow *)parentWindow frame:(NSRect)frame;
- (void)updateCollaborateWindowLayout:(NSRect)windowRect;
- (void)showJoinCollaborateInvitationIfNeed;
- (nullable NSMutableDictionary *)getCollaborateViewInfoDictOfType:(ZMZappCollaborateViewType)type
                                                             appId:(nullable NSString *)appId
                                                    isPlayTogether:(nullable BOOL *)isPlayTogether;
- (BOOL)isCollaborateShowPlayTogether:(NSString *)appID;
- (void)windowDidStartVideo;
- (void)windowDidStopVideo;
- (void)exitCollaborateModeOfAppId:(nullable NSString *)appId
                           options:(ZMZappExitCollaborateModeOptions)options
                          isFromJs:(BOOL)isFromJs;
- (void)chatMessageReceived:(NSString *)jsonMsg;
- (BOOL)isBulletAppOpened;
- (BOOL)isBulletEnable;
- (void)openBullet;
- (void)closeBullet;
- (NSUInteger)getOpenedAppsCount;
- (BOOL)needShowErrorWebView;
- (void)triggerJSEventOnMeetingViewChanged:(ZAppMeetingViewType)viewType;
- (void)triggerJSEventOnGalleryPageChange:(NSUInteger)newPage totalPage:(NSUInteger)totalPage;
- (void)onStartSendPureComputerAudio:(BOOL)start;

- (BOOL)iszAppSharingByShareAppId;
- (NSString *)getInvitationThumbnailPath:(NSString *)msgId;
- (void)downloadInvitationThumbnail:(NSString *)msgId downloadParam:(ZMZappDownloadParam *)param;
- (NSString *)getConfCurAppId;
- (BOOL)needHideInShareCtrl;
- (void)popOutWindow;
- (void)closePopoverControllerIfNeeded;
- (BOOL)isAppInCollaborateMode:(NSString *)appId;
- (BOOL)isAppCanCollaborate:(NSString *)appId;
- (void)stopAppShare;
- (BOOL)isAppSharing;
- (void)setAppPopWindowSize:(NSSize)size appId:(NSString *)appId;
- (void)onZAppSidePanelResized;
- (void)backupZApp:(id)sender action:(ZMSidePanelWindowAction)action;
- (void)restoreZApp:(id)sender action:(ZMSidePanelWindowAction)action;
- (void)onExpandModeChanged:(BOOL)isExpand;
- (void)onZappViewRemoved;
- (void)setMTPopOut:(BOOL)popOut;
- (void)setNeedPopupAfterExitFullScreen:(BOOL)popOut;
- (void)setMTRestoreZapp:(BOOL)restoreZapp;
- (void)notifyWindowPopoutWithAppId:(NSString *)appId isPopout:(BOOL)isPopout height:(NSInteger)height width:(NSInteger)width;
- (void)onAppWindowRemoved;
- (NSString *)getAppInvitationInfoUrl:(NSString *)appId type:(NSUInteger)linkType;
- (NSImage *)getZappImageByName:(NSString *)name;
- (BOOL)checkAppInstalled:(NSString *)appId completion:(ZMCallbackBlock)completion;
- (void)setBulletChecked:(BOOL)checked;
- (void)closeBulletApp:(BOOL)needClean;
- (BOOL)getTimerData:(NSMutableDictionary<NSString *, ZMZAppDynamicIndicatorInfo *> *)timerData;
- (void)requestPlayTimerAudioFileInPT:(NSUInteger)index;
- (void)showTimerIsUpToastInConf:(NSString *)appId iconPath:(NSString *)iconPath;
- (void)updateTimerIsUpToastInConf:(NSString *)appId iconPath:(NSString *)iconPath;
- (BOOL)isRTMSPanelShowing;
- (BOOL)isRTMSServiceEnabled;
- (ZMMTAppRTMSPermission)getRTMSPermission;
- (void)setRTMSPermission:(ZMMTAppRTMSPermission)permission;
- (BOOL)shouldShowRTMSItemBtn;
- (NSInteger)getRTMSRequestingCount;
- (BOOL)isAnyoneRTMSActive;
- (void)showRTMSAllAppsDisabledAlert;
- (BOOL)hasPSDKInMeeting;
- (BOOL)canUserOperateRtmsAANState;
- (void)showRTMSAANPanelAndScrollToItemWithAppID:(NSString *)appID ownerIndex:(NSUInteger)ownerIndex;
// Public scalar types keep common and SDK-only enums out of this contract.
- (NSArray<ZPZAppHeader *> *)getRTMSAppListForOwner:(UInt32)ownerIndex;
- (void)onRTMSItemReady;
- (void)showAppLauncher:(NSInteger)purpose fromView:(NSView *)positioningView config:(ZMZAppLauncherConfig *)config;
- (void)hideAppLauncher:(NSInteger)purpose;
- (void)sendMeetingChatSessionInfoWithSessionID:(NSString *)sessionID threadID:(NSString *)threadID messageID:(NSString *)messageID;
- (BOOL)isUnifyAppWndFeatureAvaible;
@end

#endif /* ZMZappConfProtocol_h */
