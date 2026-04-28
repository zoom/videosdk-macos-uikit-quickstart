//
//  IZMMTVideoRenderView.h
//  zVideoUIBridge
//
//  Created by Brace Liu on 12/11/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//
//  Protocol abstraction for ZMMTVideoRenderView
//  Allows StudioUI to use video render view without depending on VideoUI module
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZPConfUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTVideoRender;
@protocol IZMMTVideoRenderView;

// MARK: - Video Render View Delegate Protocol

@protocol IZMMTVideoRenderViewDelegate <NSObject>

@optional
// Powered water mark
- (BOOL)enablePoweredWaterForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;

// Avatar
- (BOOL)enableShowAvatarForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (NSRect)videoRenderView:(NSView<IZMMTVideoRenderView>*)renderView frameForAvatarView:(NSRect)defaultFrame;

// Info view
- (BOOL)enableShowInfoForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (NSRect)videoRenderView:(NSView<IZMMTVideoRenderView>*)renderView frameForInfoView:(NSRect)defaultFrame;
- (NSImage *)videoRenderViewAudioImage:(NSView<IZMMTVideoRenderView> *)renderView;
- (BOOL)isVideoRenderViewPinned:(NSView<IZMMTVideoRenderView> *)renderView;
- (BOOL)isVideoRenderViewSpotlighted:(NSView<IZMMTVideoRenderView> *)renderView;
- (BOOL)canShowVCardWhenClickNameAndIconForVideoRenderView:(NSView<IZMMTVideoRenderView> *)renderView;

// Border
- (BOOL)enableShowBorderForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (ZMMTVideoBorderViewStyle)videoRenderViewBorderViewStyle:(NSView<IZMMTVideoRenderView>*)renderView;

// Personal water mark
- (BOOL)enableShowPersonalWaterMarkForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (nullable NSString *)personalWaterMarkText;
- (CGFloat)waterMarkerOpacityLevel;
- (ZMConfWaterMarkCoverType)waterMarkCoverType;
- (ZMConfWaterMarkPosition)waterMarkPosition;
- (NSEdgeInsets)contentInsetsForWaterMark:(NSView<IZMMTVideoRenderView> *)renderView;

// Name tag
- (BOOL)enableShowNameTagForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (BOOL)nameTagViewShouldShowInfoIcons:(NSView<IZMMTVideoRenderView> *)renderView;
- (CGSize)videoRenderView:(NSView<IZMMTVideoRenderView>*)renderView videoRatio:(CGSize)videoRatio;
- (void)updateTranslatingTagView:(BOOL)isShowBorder;

// Audio connecting
- (BOOL)enableShowAuidoConnectingForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;
- (NSRect)videoRenderView:(NSView<IZMMTVideoRenderView>*)renderView frameForAudioConnectingView:(NSRect)defaultFrame;
- (NSRect)videoRenderView:(NSView<IZMMTVideoRenderView>*)renderView frameForInfoTextField:(NSRect)defaultFrame;
- (BOOL)videoRenderViewNeedShowUserName:(NSView<IZMMTVideoRenderView> *)renderView;

// Visible rect
- (NSRect)visibleRectForVideoRenderView:(NSView<IZMMTVideoRenderView>*)renderView;

@end

// MARK: - Video Render View Protocol

/**
 Protocol for video render view abstraction
 
 This protocol defines the interface for video render views that can be used
 across different modules (StudioUI, VideoUI, etc.) without direct dependencies.
 
 Usage:
 1. Get factory from router: [[ZMRouterCenter shared] objectForProtocol:@protocol(IZMMTVideoRenderViewFactory)]
 2. Create instance: [factory createVideoRenderViewWithFrame:...]
 3. Use through protocol methods
 */
@protocol IZMMTVideoRenderView <NSObject>

@required
// MARK: Basic Properties

/// Whether this is an active video view
@property (nonatomic, assign) BOOL isActive;

/// Delegate for video render view callbacks
@property (nonatomic, weak, nullable) id<IZMMTVideoRenderViewDelegate> delegate;

// MARK: User Management

/**
 Update render view with user
 @param theUser The user to display
 */
- (void)updateWithUser:(ZMUser *)theUser;

/**
 Lock video rendering (before layout changes)
 */
- (void)lockVideo;

/**
 Unlock video rendering (after layout changes)
 */
- (void)unlockVideo;

// MARK: UI Updates

/**
 Update avatar view display
 */
- (void)updateAvatarView;

/**
 Update info view display (name, audio status, etc.)
 */
- (void)updateInfoView;

/**
 Update border view display
 */
- (void)updateBorderView;

/**
 Update powered water mark (SDK version)
 */
- (void)updatePoweredWaterMark;

/**
 Update personal water mark
 */
- (void)updatePersonalWaterMark;

/**
 Update audio connection status
 */
- (void)updateAudioConnectStatus;

// MARK: Water Mark Control

/**
 Show powered water mark
 */
- (void)showPoweredWaterMark;

/**
 Hide powered water mark
 */
- (void)hidePoweredWaterMark;

/**
 Refresh powered water mark display
 */
- (void)refreshPoweredWaterMark;

// MARK: User Name Display

/**
 Set whether to show user name at top
 @param flag YES to show at top, NO otherwise
 */
- (void)setShowUserNameAtTop:(BOOL)flag;

/**
 Set avatar view user name
 @param inUserName User name to display
 */
- (void)setAvatarViewUserName:(NSString*)inUserName;

// MARK: Smart Tag

/**
 Update smart tag view
 @param bForce Force update even if not changed
 */
- (void)updateSmartTagView:(BOOL)bForce;

/**
 Update smart tag drawing
 */
- (void)updateSmartTagDraw;

/**
 Update smart tag position
 */
- (void)updateSmartTagPosition;

/**
 Get active smart tag name
 @return Current active smart tag name
 */
- (NSString *)activeSmartTagName;

// MARK: Layout

/**
 Get frame for audio connecting view
 @return Frame rect for audio connecting view
 */
- (NSRect)frameForAudioConnectingView;

@optional
// MARK: Optional Capabilities

/**
 Check if avatar view should be shown
 @return YES if avatar should be shown
 */
- (BOOL)enableShowAvatarView;

/**
 Check if border view should be shown
 @return YES if border should be shown
 */
- (BOOL)enableShowBorderView;

/**
 Update live button display
 */
- (void)updateLiveButton;

@end

NS_ASSUME_NONNULL_END


