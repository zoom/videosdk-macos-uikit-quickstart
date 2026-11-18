//
//  ZMZappPTProtocol.h
//  zAppUI
//
//  Created by TOTTI on 11/9/21.
//  Copyright © 2021 us.zoom. All rights reserved.
//

#ifndef ZMZappPTProtocol_h
#define ZMZappPTProtocol_h

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import <Prism/ZMCallbackImpl.h>
#import <Prism/ZMRoutableObject.h>
#import <ZoomUnit/ZPZAppAdapter.h>
#import <ZoomUnit/ZMZappVirtualEffectsProtocol.h>

#ifdef __cplusplus
#include <vector>
#include <map>
#include <string>
// NS_ZOOM_APPS is a macro (#define NS_ZOOM_APPS zoom_apps, in zApp/ZappBase.h) —
// spell the real namespace here so these forward decls match regardless of
// whether that macro happens to be defined yet in this translation unit.
// Forward declarations keep ZoomUnit independent of ZappBase.h.
namespace zoom_apps {
enum class AutoOpenSettingType : int;
struct AutoOpenAppInfoForUI;
}
#endif

@class PZMToastCoordinator;

@protocol ZMZappPTProtocol <ZMRoutableObject, ZMZappVirtualEffectsProtocol>
// PT-side Zoom Apps UI instance lifecycle. The concrete implementation is
// owned by ChatUI's ZMZappHelper; external modules should use this façade.
// This reports bundle/module loading only; use role readiness for UI work.
- (BOOL)isZappModuleLoaded;
- (BOOL)isPTZappServiceReady;
- (BOOL)createAppInstance:(ZMAppType)appType rootView:(NSView *)rootView;
- (void)destroyAppInstance:(ZMAppType)appType;
- (NSView *)getMainView;
- (void)showZappShareByAppItem:(NSDictionary *)appItem andSessionId:(NSString *)sessionId andMsgId:(NSString *)msgId onWindow:(NSWindow *)window;
- (void)showSendChatMessage:(NSDictionary *)appMessageItem
                   onWindow:(NSWindow *)window
          completionHandler:(void (^)(BOOL isSuccess, NSArray *infos))completionHandler;
- (void *)getPTZappAPI:(NSInteger)runningEnv;
- (NSString *)getMyJid;
- (BOOL)joinMeetingWithURL:(NSString *)url;
- (void)getZappHeadById:(NSString *)appId completion:(void (^)(ZPZAppHeader *header, NSError *error))completion;
- (void)onGetZappHeaderInPT:(NSString *)key header:(ZPZAppHeader *)header;
- (void)jumpToZappById:(NSString *)appId uuid:(NSString *)uuid;
- (void)showOrPopZoomAppsTab;
- (BOOL)isInMeeting;
- (NSUInteger)getConfStatus;
- (void)startVideoMeeting;
- (void)startNoVideoMeeting;
- (BOOL)isRemeberMeChecked;
- (BOOL)isLoginSnsType_Zoom;
- (void)setZappVBWithPath:(NSString *)filepath imageName:(NSString *)VBimageName isVBGen:(BOOL)isVBGen eventId:(NSString *)reqId;
- (void)selectVBItemById:(NSString *)vbId eventId:(NSString *)reqId;
- (void)selectLastVBItem;
- (void)checkAomHostUpdateCompletion:(void (^)(BOOL, NSUInteger))completion;
- (void)OnRefreshSettingWithType:(ZAppRefreshSettingType)type;
- (void)OnHDSettingWillChange;

- (BOOL)isZAppTabSelected;
- (BOOL)isZappTabPopOut;
- (BOOL)isZAppTabSelectedOrPopOut;
- (BOOL)isLabsTabSelected;
- (BOOL)isLabsTabSelectedOrPopOut;
- (PZMToastCoordinator *)getMainToastCoordinator;
- (BOOL)isIMEnable;
- (BOOL)isZappFeatureEnabled;
- (BOOL)isZappServiceEnabled;
- (void)enableZAppInPT;
- (void)disableZAppInPT;
- (void)selectOrPopOutZappTab;
- (void)toggleMainWindowCompress;
- (BOOL)isMainWindowCompressed;
- (BOOL)isPTLogin;
- (BOOL)needCheckRestoreStatus;
- (void)logEvent:(NSDictionary *)param;
- (BOOL)getWebViewNeedForceUpdate;
- (void)setShouldHandleReopen:(BOOL)reopen;
- (BOOL)isAccountChanged;
- (void)updateCurrentLoginUser:(NSString *)userId;
- (BOOL)sendZappToChatWithSessionIds:(NSArray<NSString *> *)sessionIds zappInfos:(NSDictionary *)zapp;

- (void)showUnavailableZappAlert;
- (zappEnableState)getZappEnableState;

- (void)updateAppBadge:(ZMAppType)appType openedCount:(NSUInteger)count;

- (void)openSignUpUrl;
- (NSWindow *)getMainWindow;
//ZOOM-443598
- (void)trackZappJ2CInteraction:(NSString *)appId action:(ZAppOpenAppAction)type;
- (void)trackZappJ2CAuthInteraction:(NSString *)appId result:(BOOL)authResult;
- (void)trackZappActionInteraction:(NSString *)appId action:(NSUInteger)type;
- (void)trackZappClickAppsIconInteraction;

- (void)trackZappOpen2ZRInteraction:(BOOL)isTransfer;

// setVideoFilter
- (void)downloadAomhostCompletion:(void (^)(BOOL))completion;
- (BOOL)setVideoFilter:(NSString *)filterName imagePath:(NSString *)imagePath thumbPath:(NSString *)thumbPath filterOption:(NSInteger)option;

- (BOOL)couldSelectVideoFilter;

- (void)refreshMirrorSettingUI;

//ZOOM-449731
- (BOOL)isCallStatusIdle;
- (void)getFrequentlyUsedEmojis:(NSMutableArray<NSString *> *)frequentlyUsedEmojis;

// ZOOM-449099
- (BOOL)isSupportOpenApp;
- (NSString *)pairedZRName;
- (void)onZRPairedStatusChanged:(BOOL)paired;

- (void)openAppWithAppId:(NSString *)appId appName:(NSString *)appName runningInMeeting:(BOOL)inMeeting targetUrl:(NSString *)targetUrl;
- (void)openAppSettingMenuWithType:(ZMZappOpenSettingType)type;
- (BOOL)isSettingAppTabSelected;

// Meeting Timer
- (BOOL)try2CheckShowMeetingTimeButton:(BOOL)check;

//topLine
- (NSData *)getFileDataFromRequest:(NSURLRequest *)request;
- (void)playTimerAudioFile:(NSUInteger)index;

- (BOOL)defaultMeetStartWithVideo;
- (void)setDefaultMeetStartWithVideo:(BOOL)needVideo;
- (void)onUpdateSettingWithDatas:(NSArray<ZPZAppHeader *> *)datas;
#ifdef __cplusplus
- (void)onUpdateSettingWithAutoOpenType:(zoom_apps::AutoOpenSettingType)showType forAppId:(NSString *)appId;
#endif
- (void)onRemoveInstalledAppId:(NSString *)appId;
- (void)onUpdateAutoOpenAppId:(NSString *)appId state:(BOOL)state;
- (void)onUpdateAutoOpenData;
- (void)autoOpenManageBtnClick;
- (void)openAutoOpenSettings;
- (void)showZappLoginUI;
- (void)updateCookieClearDate:(NSString *)dateStr;
- (void)markInstallAppsDataFromCallback;

- (void)selectHomeTab;
- (BOOL)isMarketplaceTabVisible;
- (void)selectMarketplaceTab;
- (NSString *)getMarketplaceWebviewId;

- (BOOL)isAppTabSelected:(NSString *)appId;
- (void)selectAppTab:(NSString *)appId;
- (BOOL)isAppTabPopOut:(NSString *)appId;
- (void)popOutAppTab:(NSString *)appId;
- (void)mergeBackAppTab:(NSString *)appId;
- (void)closeAppTabPopOutWindow:(NSString *)appId;
- (void)openDetachedZappTab:(NSString *)appId;
- (void)closeDetachedZappTab:(NSString *)appId;
- (void)notifyAppViewRefreshed:(NSString *)appId;

- (void)onAppTabSelected:(BOOL)selected;
- (void)onLabsTabSelected:(BOOL)selected;

- (void)onZoomLogoutFinished;
- (NSString *)getLaunchTrackingId:(NSString *)appId;
- (void)onToggleZappFeature:(NSInteger)state;
- (void)onWebviewForceUpdate:(NSString *)webViewVersionStr;
- (NSString *)openedNormalAppId;
- (NSString *)openedNormalAppName;
- (BOOL)isAppSupportTransfer2ZRInPT;
- (nullable NSString *)openedNormalAppCurrentURL;
- (void)keepPreviousMeetingInfo;
- (void)handleZappCallIdle;
- (void)handleZappWebinarRoleChange;

- (BOOL)getAutoOpenAppsFeatureEnable;
- (NSArray<ZPZAppHeader *> *)getInstallAppsList;
- (void)clearAppDataBtnClick:(NSWindow *)window;
- (BOOL)getKeepAppsOpenSetting;
- (BOOL)setKeepAppsOpenSetting:(BOOL)bCheck;
- (NSString *)getSettingManageUrl;
- (NSArray<NSString *> *)getAutoOpenAppIdsInMeeting;
- (void)requestConfRealOpenedAppIds;
- (void)cleanAllMirrorAppsInPT;
- (void)restoreMirrorAppsIfNeeded;
- (void)appsTabDidPopOut;
- (void)labsTabDidPopOut;
- (void)openZappByFax:(NSString *)appId invitationId:(NSString *)invitationId;
- (BOOL)checkAppInstalled:(nullable NSString *)appId completion:(ZMCallbackBlock)completion;
- (nullable NSImage *)getZappImageByName:(nonnull NSString *)name;
#ifdef __cplusplus
- (BOOL)setAutoOpenAppInfo:(NSString *)appId type:(zoom_apps::AutoOpenSettingType)type;
- (BOOL)getAutoOpenAppsInfo:(std::vector<zoom_apps::AutoOpenAppInfoForUI>&)appsInfo;
- (NSMutableArray<ZPZAppHeader *> *)sortAutoOpenArray:(NSMutableArray<ZPZAppHeader *> *)array
                                         appsInfoMap:(const std::map<std::string, zoom_apps::AutoOpenAppInfoForUI>&)appsInfoMap;
#endif
@end

#endif /* ZMZappPTProtocol_h */
