//
//  IZMSDKFeaturesMgr.h
//  VideoUIBridge
//
//  Created by Michael Lin on 2026/2/3.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#ifndef IZMSDKFeaturesMgr_h
#define IZMSDKFeaturesMgr_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMSDKFeaturesMgr <ZMRoutableObject, ZMMTForceUpdateProtocol>

@property (nonatomic, assign) BOOL isPopupMoreFeaturesWindowEnable;

- (BOOL)isMoreFeaturesWebViewAvailable;
- (BOOL)isSDKFeaturesShown;
- (void)restoreSDKFeaturesPanel;
- (void)openSDKFeaturesPanel;
- (void)closeSDKFeaturesPanelWithTip:(BOOL)showTip;
- (void)showTipWithDelay;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMSDKFeaturesMgr_h */
