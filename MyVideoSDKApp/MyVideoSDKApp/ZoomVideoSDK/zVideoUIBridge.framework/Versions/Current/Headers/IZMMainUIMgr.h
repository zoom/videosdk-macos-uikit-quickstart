//
//  IZMMainUIMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/8/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMainUIMgr_h
#define IZMMainUIMgr_h

/**
 * @router ZMMTShared
 */
@protocol IZMMainUIMgr <ZMRoutableObject>
@property (nonatomic, readonly, assign) BOOL isWindowShowingCaptions;

- (__kindof NSWindow *)confWindow;
- (NSRect)getWindowRect;
- (NSScreen *)getWindowScreen;
- (NSRect)getMainViewRectInScreen;
- (void)relayoutUI;
- (void)updateTouchBar;

- (BOOL)isPreferWallViewMode;
- (BOOL)isPreferDynamicViewMode;
- (BOOL)isPreferBestFitViewMode;
- (BOOL)isPreferSpeakerViewMode;
- (void)preferWallViewMode;
- (void)preferBestFitViewMode;
- (void)preferDynamicViewMode;
- (void)preferSpeakerViewMode;
- (void)restoreVideoViewIfNeeded;

// ToolSuite
- (BOOL)isAble2EnterFullscreen;
- (BOOL)isAble2EnterMinimalVideo;
- (void)enterFullScreen;
- (void)exitFullScreen;
- (void)bringWindowToFront;

- (BOOL)isSpeakerViewMode;
- (BOOL)isWallViewMode;
- (BOOL)isDynamicViewMode;

- (void)onScrollWallView2NextPage;
- (void)onScrollWallView2PrevPage;

- (BOOL)isWindowShowing;

- (BOOL)canMergePopoutWindowToMainWindow;

- (NSString *)accessibilityHelpForTab:(NSView*)view;

- (ZMUserID)getDisplayingRealUserID;
@end

#endif /* IZMMainUIMgr_h */
