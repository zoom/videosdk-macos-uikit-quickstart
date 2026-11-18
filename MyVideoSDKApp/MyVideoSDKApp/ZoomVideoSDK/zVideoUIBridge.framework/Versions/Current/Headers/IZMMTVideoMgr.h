//
//  IZMMTVideoMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMVideoCutoutType){
    ZMVideoCutoutType_None = 0,
    ZMVideoCutoutType_Immersive         = 1ll<<1,
    ZMVideoCutoutType_Zapp_Plugin       = 1ll<<2,
    ZMVideoCutoutType_PresenterLayout   = 1ll<<3,
    ZMVideoCutoutType_SendingShare      = 1ll<<4,
    ZMVideoCutoutType_SendingDocShare   = 1ll<<5,
};

typedef NS_OPTIONS(NSUInteger, ZMVideoMirrorType){
    ZMVideoMirrorType_None              = 0,
    ZMVideoMirrorType_PresenterLayout   = 1ll<<1,
    ZMVideoMirrorType_SendingShare      = 1ll<<2,
    ZMVideoMirrorType_SendingDocShare   = 1ll<<3,
};

typedef NS_OPTIONS(NSUInteger, ZMVideoAlphaMaskType){
    ZMVideoAlphaMaskType_None           = 0,
    ZMVideoAlphaMaskType_PresenterLayout= 1ll<<1,
    ZMVideoAlphaMaskType_SendingShare   = 1ll<<2,
    ZMVideoAlphaMaskType_GalleryPlus    = 1ll<<3,
    ZMVideoAlphaMaskType_Immersive      = 1ll<<4,
    ZMVideoAlphaMaskType_SendingDocShare= 1ll<<5,
    ZMVideoAlphaMaskType_Zapp_Plugin    = 1ll<<6,
};

// Why the floating PiP is currently unavailable: the window shows a
// share/whiteboard/doc, it is in speaker view, the meeting is large, or the
// window is too small to hold the PiP at its minimum size. The PiP merges back
// into the gallery in all of them, and the entry points that would put it back
// are suppressed.
typedef NS_ENUM(NSInteger, ZMSelfViewMinimizeRestriction) {
    ZMSelfViewMinimizeRestrictionNone,
    ZMSelfViewMinimizeRestrictionScreenShare,
    ZMSelfViewMinimizeRestrictionLargeMeeting,
    ZMSelfViewMinimizeRestrictionSpeakerView,
    ZMSelfViewMinimizeRestrictionWindowTooSmall,
    // Views with no self view to float at all -- companion mode, immersive.
    ZMSelfViewMinimizeRestrictionUnsupportedView,
};

typedef NS_ENUM(NSInteger, ZMSelfViewDisplayMode) {
    ZMSelfViewDisplayModeShowInGallery,
    ZMSelfViewDisplayModeHide,
    ZMSelfViewDisplayModeFloatOverGallery,
};

/**
 * @router ZMMTShared
 */
@protocol IZMMTVideoMgr <ZMRoutableObject>
- (void)onAutoStartVideo:(NSInteger)ret session:(ZMConfSession*)session;
- (void)onEnableVBFailed:(ZMConfSession*)session;

- (void)onSendVideoPrivilegeChange;//ZOOM-82229
- (void)onReceiveVideoPrivilegeChange;//ZOOM-82229

- (void)onHostChangedWithUser:(ZMUser*)zmUser;
- (void)onCoHostChangedWithUser:(ZMUser*)zmUser;
- (void)onFocusModeStatusChanged:(ZMConfSession*)session;
- (void)onFocusModeEnding:(ZMConfSession*)session;
- (void)onFocusModeWhiteListChanged:(ZMConfSession*)session;
- (void)resetFocusModeWhiteList:(ZMConfSession*)session;

- (void)onVideoSizeChanged:(ZMUser *)zmUser;

- (BOOL)isMyVideoTurnOn;
- (BOOL)isSupportSmartVirtualBackground;

- (BOOL)onMyVideo;

// Immersive
- (BOOL)isVideoCutout;
- (BOOL)setPortraitRect:(NSRect)rect renderHandle:(void *)handle;
- (void)setVideoReplaceEnabled:(BOOL)enabled;
- (void)setVideoCutoutEnabled:(BOOL)enabled forType:(ZMVideoCutoutType)type;
- (void)setVideoPickColorEnabled:(BOOL)enabled;
- (void)setVideoMirrorDisable:(BOOL)disable forType:(ZMVideoMirrorType)type;
- (BOOL)isVideoMirrorDisable;
- (void)setVideoAlphaMaskEnabled:(BOOL)enable forType:(ZMVideoAlphaMaskType)type;
- (BOOL)isVideoEnableAlphaMask;

- (void)onMyVideoDevideRunStarted:(/*CMM_MY_VIDEO_RUN_TYPE*/NSInteger)runType;

#pragma mark - Self view (Normal / Hidden / Minimized)

// "Hide/Show self view" and "Minimize/Maximize self view" are two exit actions
// of one state (Normal/Hidden/Minimized), so both can never be "on" at once.
// The two getters drive their Layout menu items' titles.
- (void)toggleShowOrNotMyVideo;
- (BOOL)isSelfViewHidden;

// zpref::zPolicy_SelfViewMode's MinimizedExpand state ("Minimize self view" /
// the floating self-view PiP). Used by the Layout menu's toggle item.
- (BOOL)isSelfViewMinimized;
- (BOOL)isSelfViewModeMandatory;
- (void)toggleMinimizeSelfView;

// Local UI-only grid-declutter: hide my redundant tile while the PiP shows it.
// Consult alongside isShowMySelfVideo. Never touches the engine, so it can't
// skew GetSelfViewMode() for other consumers.
- (BOOL)shouldHideSelfTileForGridDeclutterForSession:(ZMConfSession *)session;

// "Nobody else has a video tile." Every "am I alone" gate in this feature goes
// through this, so the PiP, the grid declutter, the tile button and the menus
// can never disagree.
- (BOOL)isAloneInSession:(ZMConfSession *)session;

- (ZMSelfViewMinimizeRestriction)selfViewMinimizeRestriction;

// The same state the toggles above drive, as one 3-way choice for the "Self
// view options" radio submenu. Setting it lands on exactly the requested mode,
// unlike the toggles, which restore whatever was showing before.
- (ZMSelfViewDisplayMode)selfViewDisplayMode;
- (void)setSelfViewDisplayMode:(ZMSelfViewDisplayMode)mode;
@end

NS_ASSUME_NONNULL_END
