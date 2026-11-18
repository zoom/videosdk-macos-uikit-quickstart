//
//  IZMBreakoutRoomMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/9/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMBreakoutRoomMgr <ZMRoutableObject>
@property (nonatomic, assign) NSUInteger transformAction;
@property (nonatomic, assign) NSUInteger joinOrLeaveReason;

@property (nonatomic, assign) void* eventSink;

/// YES after FeatureMgr has delivered onFeatureCreated for ft_new_bo. Plain
/// state query; safe to read multiple times.
@property (nonatomic, readonly) BOOL isFeatureReady;

- (void)onFeaturePrepare;
- (void)onFeatureReady;

/// Called by the on-demand BO ControlMgr in its launchModule to drain an
/// onFeatureReady event delivered while the ControlMgr was unloaded. Returns
/// YES exactly once per missed delivery; subsequent calls return NO. No-op
/// (returns NO) when the event was already forwarded directly.
- (BOOL)consumePendingFeatureReady;
@end

NS_ASSUME_NONNULL_END
