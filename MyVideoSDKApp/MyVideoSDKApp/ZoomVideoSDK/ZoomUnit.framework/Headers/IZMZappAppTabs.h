//
//  IZMZappAppTabs.h
//  ZoomUnit
//
//  Copyright © 2026 Zoom. All rights reserved.
//

#ifndef IZMZappAppTabs_h
#define IZMZappAppTabs_h

#import <AppKit/AppKit.h>
#import <Prism/ZMRoutableObject.h>

@class ZPZAppHeader;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZappTabMenuId) {
    ZappTabMenuId_None = 0,
    ZappTabMenuId_Refresh = 1,
    ZappTabMenuId_OpenAppInMeeting = 2,
    ZappTabMenuId_OpenInZR = 3,
    ZappTabMenuId_CloseApp = 4,
};

@interface ZMZappAppTabsMenu : NSObject <NSCopying>

@property (nonatomic, copy) NSString *tab_id;
@property (nonatomic, assign) ZappTabMenuId menu_id;
@property (nonatomic, copy) NSString *menu_name;
@property (nonatomic, strong, nullable) NSImage *menu_icon;
@property (nonatomic, assign) BOOL is_checkable;
@property (nonatomic, assign) BOOL is_checked;

@end

@protocol IZMZappAppTabs <ZMRoutableObject>

- (nullable NSView *)getAppView:(NSString *)tabId;
- (NSArray<ZPZAppHeader *> *)getAppsList;
- (NSArray<ZMZappAppTabsMenu *> *)getAppMenuItems:(NSString *)tabId;
- (void)onAppTabWillRelease:(NSString *)tabId;
- (void)onClickAppsTab:(NSString *)tabId;
- (BOOL)onClickZappMenuItem:(ZappTabMenuId)menuId tabId:(NSString *)tabId;

@end

@protocol IZMZappAppTabsObserver <ZMRoutableObject>

@optional
- (void)onGetAppList:(NSArray<ZPZAppHeader *> *)appList;
- (void)onAppViewRefreshed:(NSString *)tabId;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMZappAppTabs_h */
