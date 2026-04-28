//
//  IZMMTSharingViewController.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2024/12/8.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTSharingViewController_h
#define IZMMTSharingViewController_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMConfSharingAspectMode) {
    ZMConfSharingAspectMode_FitToWindow,
    ZMConfSharingAspectMode_Original,
    ZMConfSharingAspectMode_Trustee,
};

typedef NS_ENUM(NSInteger, ZMConfSharingLayoutItemType) {
    ZMConfSharingLayoutItemType_Wallpaper,
    ZMConfSharingLayoutItemType_As,
    ZMConfSharingLayoutItemType_Video,
};

@class ZMShareSource;

/// Protocol for sharing view controller to decouple VideoUI dependency
@protocol IZMMTSharingViewController <NSObject>

@required

/// The main view of the sharing view controller
@property (nonatomic, readonly) ZMMTBaseView *view;

/// Conference session for context
@property (nonatomic, retain, nullable) ZMConfSession *confSession;

///aspect mode
@property (nonatomic, assign) ZMConfSharingAspectMode aspectMode;

/// Start sharing with the specified share source
/// @param zmShareSource The share source to display
- (void)startSharingViewWithShareSource:(ZMShareSource *)zmShareSource;

/// Start sharing view using current/default share source
/// (Convenience method - implementations should handle getting the current share source)
- (void)startSharingView;

/// Stop the current sharing view
- (void)stopSharingView;

/// Lock video rendering (call before view hierarchy changes)
- (void)lockVideo;

/// Unlock video rendering (call after view hierarchy changes)
- (void)unlockVideo;

/// Relayout the sharing view UI
- (void)relayoutUI;

@optional

/// Start sharing with specified frame rate
/// @param zmShareSource The share source to display
/// @param frameRate The video frame rate
- (void)startSharingViewWithShareSource:(ZMShareSource *)zmShareSource frameRate:(int)frameRate;

/// Destroy the render resources
- (void)destroyRender;

/// Check if first frame has been rendered
@property (nonatomic, readonly) BOOL isFirstFrameRendered;

/// Set the share view frame rate
/// @param nFrameRate The frame rate to set
- (void)setShareViewFrameRate:(int)nFrameRate;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTSharingViewController_h */

