//
//  ZMMTToolbarTipEvents.h
//  VideoUI
//
//  Created by martin.yu on 4/24/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef ZMMTToolbarTipEventsProtocol_h
#define ZMMTToolbarTipEventsProtocol_h

NS_ASSUME_NONNULL_BEGIN

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMMTToolbarTipEventsProtocol <NSObject>
@optional
- (void)updateToolbarTipPosition;
- (void)hideAllToolbarTips;

- (void)showJoinAudioTip:(BOOL)isFocedPrompt;
- (void)hideJoinAudioTip;

- (void)showSelectAuidoDeviceTipWithTipString:(NSString *)tipString;
- (void)hideSelectAuidoDeviceTip;

- (void)showFitBarCanNotJoinAudioTip;
- (void)hideFitBarCanNotJoinAudioTip;

- (void)showToolbarChatTip;
- (void)hideToolbarChatTip;
- (void)showToolbarEnableChatTip;
- (void)hideToolbarEnableChatTip;
- (void)onChatTipsStateChange:(BOOL)preview;

// source: 0 toolBar, 1 fitBar
- (void)showCCTipWithTipString:(NSString *)tipString source:(int)source;
- (void)hideCCTipWithSource:(int)source;

- (void)showCCChangeLanguageTip;
- (void)hideCCChangeLanguageTip;
- (void)showCCOptionMenu;

- (void)showToolbarBOTip:(NSString*)inTip force:(BOOL)force;
- (void)hideToolbarBOTip;
- (void)showToolbarBOUnassignUserTipWithCount:(int)inCount;
- (void)hideToolbarBOUnassignUserTip;

- (void)showResetOrderTipIfNeed;
- (void)hideResetOrderTip;

- (void)showToolbarAvailableInterpretLanguageTipWithTipString:(NSString *)tipString;
- (void)hideToolbarAvailableInterpretLanguageTip;
//ZOOM-330475
- (void)showToolbarInterpretationMicStateTipWithTipString:(NSString *)tipString enabled:(BOOL)enabled;
- (void)hideToolbarInterpretationMicStateTip;

- (void)toolbarCopyInviteLinkAndNotice;

- (void)showSidecarTip:(NSString*)tip;
- (void)hideSidecarTip;

- (void)showToolbarAICRemindTip;
- (void)hideToolbarAICRemindTip;

- (void)showToolbarAICRecapTip;
- (void)hideToolbarAICRecapTip;

- (void)onAICButtonClicked;

- (void)showToolbarSummaryAccessTip;
- (void)hideToolbarSummaryAccessTip;

- (void)hideRaiseHandTip;


- (void)showToolbarNewBOTipWithTipString:(NSString *)tipString
                        mouseEventAction:(nullable BOOL(^)(ZMBubbleObject *bubbleObj, NSEvent *event))mouseEventAction;
- (void)hideToolbarNewBOTip;

- (void)showToolbarCompanionModeTipWithTipString:(NSString *)tipString
                                mouseEventAction:(nullable BOOL(^)(ZMBubbleObject *bubbleObj, NSEvent *event))mouseEventAction;
- (void)hideToolbarCompanionModeTip;

- (void)hideToolbarClinicalNoteButtonBubbleTip;

// Clips Share
- (void)showClipsShareTip;
- (void)hideClipsShareTip;

- (void)showAudioCompanionMicFTETip;
- (void)showAudioCompanionMicErrorTip:(NSString *)title
                          description:(NSString *)description
                     containLearnMore:(BOOL)learnMore;
- (void)showAudioCompanionMicPoorQualityTip;
- (void)showAudioCompanionSpeakerErrorTip:(NSString *)title
                              description:(NSString *)description
                         containLearnMore:(BOOL)learnMore;

- (void)showLiveSummaryNewTip;
- (void)hideLiveSummaryNewTip;

- (void)showUpSellTip;
- (void)hideUpSellTip;

// source: 0 toolBar, 1 fitBar
- (void)showUSBDeviceTip:(NSString *)deviceName micId:(NSString *)micId spkId:(NSString *)spkId source:(int)source;
- (void)closeUSBDeviceTip;
- (void)refreshUSBDevicePromptSetting;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMTToolbarTipEventsProtocol_h */
