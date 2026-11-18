//
//  IZMMTArchiveMgr.h
//  VideoUIBridge
//
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTArchiveMgr <ZMRoutableObject>

- (void)showForceLeaveToastWithRemainSeconds:(NSUInteger)remainSeconds;

@end

NS_ASSUME_NONNULL_END
