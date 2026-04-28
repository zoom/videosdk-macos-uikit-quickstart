//
//  IZMMTMiniViewMgr.h
//  VideoUIBridge
//
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTMiniViewMgr_h
#define IZMMTMiniViewMgr_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Protocol for MinimalView (mini mode) management
/// Implemented by VideoLayoutUI module, loaded on-demand
/**
 * @router ZMMTShared
 */
@protocol IZMMTMiniViewMgr <ZMRoutableObject>

/// Destroy all video renders in minimal view
- (void)destroyAllRenders;

/// Show minimal view window and start video
- (void)startVideo;

/// Hide minimal view window and stop video
- (void)stopVideo;

@optional
/// Check if minimal view window is currently showing
- (BOOL)isWindowShowing;

#ifdef BUILD_FOR_CLIENT_SDK
- (void)switchMiniVideoMode;
#endif

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTMiniViewMgr_h */
