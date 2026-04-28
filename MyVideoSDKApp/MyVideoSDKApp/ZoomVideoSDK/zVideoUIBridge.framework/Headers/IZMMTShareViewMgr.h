//
//  IZMMTShareViewMgr.h
//  VideoUIBridge
//
//  Created for ShareViewMgr modularization.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#ifndef IZMMTShareViewMgr_h
#define IZMMTShareViewMgr_h

#import <zVideoUIBridge/IZMMTSharingViewController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTShareViewMgr <ZMRoutableObject>

/// Create share view controller
/// @param type View type
/// @return View controller instance
- (nullable id<IZMMTSharingViewController>)newShareViewControllerWithType:(ZMMTType)type;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTShareViewMgr_h */
