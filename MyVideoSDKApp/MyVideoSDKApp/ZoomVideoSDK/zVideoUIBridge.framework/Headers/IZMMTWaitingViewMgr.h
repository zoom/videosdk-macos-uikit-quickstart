//
//  IZMMTWaitingViewMgr.h
//  VideoUIBridge
//
//  Created for MinimalView migration.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#ifndef IZMMTWaitingViewMgr_h
#define IZMMTWaitingViewMgr_h

NS_ASSUME_NONNULL_BEGIN

@class ZMMTWaitingViewController;

/**
 * @router ZMMTShared
 */
@protocol IZMMTWaitingViewMgr <ZMRoutableObject, ZMMTForceUpdateProtocol>

/// Create waiting view controller
/// @param type View type
/// @return View controller instance
- (nullable ZMMTWaitingViewController *)newViewControllerWithType:(ZMMTType)type;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTWaitingViewMgr_h */
