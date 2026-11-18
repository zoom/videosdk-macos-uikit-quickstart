//
//  ZMZappInstanceEventsProtocol.h
//  ZoomUnit
//
//  Copyright © 2026 Zoom. All rights reserved.
//

#ifndef ZMZappInstanceEventsProtocol_h
#define ZMZappInstanceEventsProtocol_h

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZPZAppAdapter.h>

#ifdef __cplusplus
namespace zoom_apps {
enum class AutoOpenSettingType : int;
}
#endif

@protocol ZMZappInstanceEventsProtocol <NSObject>
@optional

- (void)onCloseButtonClicked:(ZMAppType)appType;
- (void)onExpandButtonClicked:(ZMAppType)appType isExpand:(BOOL)expand;
- (void)onNotifyAppModuleWillBeDestroyed;
- (void)onGetViewExpandStatus:(ZMAppType)appType isExpand:(BOOL *)expand;
- (void)onNotifyApp:(ZMAppType)appType openedCount:(NSInteger)count;
- (void)updateZoomAppsWithDatas:(NSArray<ZPZAppHeader *> *)datas;
#ifdef __cplusplus
- (void)updateZoomAppsWithAutoOpenType:(zoom_apps::AutoOpenSettingType)showType forAppId:(NSString *)appId;
#endif
- (void)keepAppsLimitTipIfNeeded;
- (void)autoOpenManageBtnClick;
- (void)openAutoOpenSettings;
- (void)updateCookieClearDate:(NSString *)dateStr;
- (void)openAppSettingMenu;
- (void)markInstallAppsDataFromCallback;

@end

#endif /* ZMZappInstanceEventsProtocol_h */
