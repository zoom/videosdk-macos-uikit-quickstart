//
//  IZMPBOMgr.h
//  VideoUI
//
//  Created by Javenlee Li on 2023/2/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMPBOMgr <ZMRoutableObject>

@property (nonatomic, assign) void* eventSink;

/// YES after FeatureMgr has delivered onFeatureCreated for ft_pbo. Plain
/// state query; safe to read multiple times.
@property (nonatomic, readonly) BOOL isFeatureReady;

- (void)onFeaturePrepare;
- (void)onFeatureReady;

/// Called by the on-demand PBO ControlMgr in its launchModule to drain an
/// onFeatureReady event delivered while the ControlMgr was unloaded. Returns
/// YES exactly once per missed delivery; subsequent calls return NO. No-op
/// (returns NO) when the event was already forwarded directly.
- (BOOL)consumePendingFeatureReady;

@end

NS_ASSUME_NONNULL_END
