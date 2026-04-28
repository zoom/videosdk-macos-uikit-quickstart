//
//  IZMSummaryMgr.h
//  VideoUIBridge
//
//  Migrated from VideoUI.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#ifndef IZMSummaryMgr_h
#define IZMSummaryMgr_h

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMSummaryMgr <ZMRoutableObject>

@optional
@property (nonatomic, retain, readonly) ZMAlertPanel *disclaimerPanel;
- (NSString *)getSmartSummaryPrivicyLink;

- (BOOL)shouldShowFreeAccountAvailableTip;

- (void)updateFreeAccountNewTipTag:(BOOL)isShowed;

- (BOOL)isFreeAccountNewTipDisplayed;

- (void)showRequestEnableSummaryPanelIfNeed;

- (void)showAttendeeRequestStartPanelIfNeed;

- (void)showAdminReceiveRequestPanelIfNeed:(ZMUserID)senderId enableBySelf:(BOOL)isBySelf;

- (void)closeRequestEnableSummaryPanel;

- (void)closeAdminReceiveRequestPanel;

- (void)onReceiveRequestToEnableSummaryMsg:(ZMUserID)senderId;

- (void)onReceiveRequestToStartSummaryMsg:(NSString *)reqId senderId:(ZMUserID)senderId;

- (void)onReceiveStartSummaryRspMsg:(BOOL)bTimeOut decline:(BOOL)decline;

- (void)onSummaryFeatureOnStatusChanged:(BOOL)summaryEnabled;

- (void)showSmartSummaryDisclaimerIfNeed;
- (void)showSmartSummaryDisclaimer;
- (void)closeSmartSummaryDisclaimer;
- (void)closeAllPanel;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMSummaryMgr_h */
