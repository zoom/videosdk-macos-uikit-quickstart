//
//  IZMMTBillingNoticeMgr.h
//  VideoUI
//
//  Created by martin yu on 2024/11/26.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTBillingNoticeMgr_h
#define IZMMTBillingNoticeMgr_h

NS_ASSUME_NONNULL_BEGIN

@class ZMMTBillingNotice;

/**
 * @router ZMMTShared
 */
@protocol IZMMTBillingNoticeMgr <ZMRoutableObject>
@property (nonatomic, assign, readonly) BOOL isCommonCoachmarkShowing;

- (BOOL)requestToReportAICMarketInfoWithEventType:(NSString *)eventType;

// upsell
#ifdef __cplusplus
- (ZMMTBillingNotice * _Nullable)getUpSellToolBarNoticeWithType:(ZUUI::LargeMeetingUpsellPrompt)type;
- (void)onPlistBannerShow:(BOOL)show type:(ZUUI::OnlineBusinessBannerType)type;
#endif
- (ZMTagView *)getPlistBannerView;

// upgrade
- (ZMTagView * _Nullable)getUpgradeBanner:(ZMMTUpgradeEntrance)entrance;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTBillingNoticeMgr_h */
