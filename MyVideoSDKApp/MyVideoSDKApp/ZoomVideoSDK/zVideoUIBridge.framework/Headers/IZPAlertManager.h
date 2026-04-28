//
//  IZPAlertManager.h
//  VideoUI
//
//  Created by martin.yu on 9/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPAlertManager_h
#define IZPAlertManager_h

@class ZMAlertPanel;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTChatMessageModel;

/**
 * @router ZMMTShared
 */
@protocol IZPAlertManager <ZMRoutableObject>
- (void)showAllowSignLanguageInterpreterToTalkAlert;
- (void)closeAllowSignLanguageInterpreterToTalkAlert;

- (void)showZECompanionInterpretationEnableStreamAlertConfirmBlock:(void (^)(void))confirmAction;

- (void)showArchiveAlert;
- (void)closeArchiveAlert;
- (void)showArchiveFailedAlert;
- (void)closeArchiveFailedAlert;

- (void)showPSProducerNoInterChannelAlert;

#pragma mark - Production Studio Alerts

/// Show PS ready opened alert
- (void)showPSReadyOpenedAlert;

/// Show open PS window confirmation alert
/// @param confirmBlock Confirmation callback
- (void)showPSOpenWindowAlertConfirmBlock:(void(^)(void))confirmBlock;

/// Show go to main stage confirmation alert
/// @param isShare Whether to include share
/// @param confirmBlock Confirmation callback
- (void)showPSGoMainStageAlertWithShare:(BOOL)isShare confirmBlock:(void(^)(void))confirmBlock;

/// Show start share confirmation alert
/// @param confirmBlock Confirmation callback
- (void)showPSStartShareAlert:(void(^)(void))confirmBlock;

/// Show join breakout session confirmation alert (will stop live streaming)
/// @param confirmBlock Confirmation callback
- (void)showPSJoinWBOAlertConfirmBlock:(void(^)(void))confirmBlock;

- (ZMAlertPanel *_Nullable)alertPanelWithIdentifier:(nullable NSString *)identifier makeIfNecessary:(BOOL)makeIfNecessary;
- (void)closeAlertPanelWithIdentifier:(nullable NSString *)identifier;
- (void)showQADlpCheckAlertWithConfirm:(void(^)(void))actionConfirm;
- (void)showQADlpBlockAlert;
- (void)closeDLPQACheckAlert;
- (void)closeDLPQABlockAlert;

- (void)showQAConflictAlert;
- (void)showDlpCheckAlertWithConfirm:(void(^)(void))actionConfirm;
- (void)showDlpBlockAlert:(NSString *)policyName;//policyName is useless
- (void)closeDLPAlert;
- (void)closeDLPCheckAlert;

- (void)showWhiteboardBlockShareAlert;
- (void)showWhiteboardBlockGeneralAlertWithContinueAction:(nullable dispatch_block_t)continueAction
                                             cancelAction:(nullable dispatch_block_t)cancelAction;
- (void)showWhiteboardOpenAlertWithCompeletion:(void (^)(void))compeletion;

- (void)showRecordingHostNotInMeetingAlert;

- (void)showRecordingDisclaimer:(BOOL)isCloud expectedZRAValue:(NSNumber *)expectedZRAValue;
- (void)showMiniWindowCannotRecodingAlert;
- (void)closeMiniWindowCannotRecodingAlert;

- (BOOL)showSimuliveAlertIfNeed;
- (BOOL)isStartWebinarBroadcastOrSimuliveAlertShowing; //ZOOM-967444
- (void)showStartWebinarBroadcastOrSimuliveAlert;
- (void)closeStartWebinarBroadcastOrSimuliveAlert;
- (void)showAudioVideoUnavailableAlert; //ZOOM-748835
- (void)closeAudioVideoUnavailableAlert;

- (BOOL)isRequestLiveStreamAlertShowing;
- (void)showRequestLiveStreamAlert:(NSString*)userName reqURL:(NSString*)reqURL reqName:(NSString*)reqName;
- (void)closeRequestLiveStreamAlert;

//ZOOM-267228
- (void)showRemindMeetingIsLivestreamedAlert;
- (void)closeRemindMeetingIsLivestreamedAlert;

//ZOOM-524148
- (void)showRemindMeetingKVSIsLivestreamedDisclaimer:(NSString *)title content:(NSString *)content;
- (void)closeRemindMeetingKVSIsLiveDisclaimer;

- (void)showLivestreamedOnNDIAlertIfNeeded;

- (void)showAudioDeviceErrorAlert:(NSString*)tipString;
- (void)showCoreAudioErrorAlert;

- (void)showAudioControlDisclaimer:(ZMUser *)user;
- (BOOL)isAudioControlDisclaimerShowing:(ZMUser *)user;
- (void)closeAudioControlDisclaimer:(ZMUser *)user;
- (void)closeAllAudioControlDisclaimer;

- (void)showAddToAudioControlGroupAlert:(ZMUser *)user;
- (BOOL)isAddToAudioControlGroupAlertShowing:(ZMUser *)user;
- (void)closeAddToAudioControlGroupAlert:(ZMUser *)user;
- (void)closeAllAddToAudioControlGroupAlert;

- (void)showRequestAudioControlAlert:(ZMUser *)user;
- (void)showForbidUnmuteAudioWhenAudioSharingAlert;

- (void)showBindAudioBeforRaiseHandAlert;

- (void)showWebinarReactionsEnabledAlertConfirmBlock:(void (^)())confirmAction;

- (void)showAddToMeetingChannelAlert:(NSString*)content moreUrl:(nullable NSString *)moreUrl actionBlock:(void (^)(BOOL))actionBlock;
- (void)closeAddToMeetingChannelAlert;

- (void)showChatDeletedByDlpAlert;
- (void)showChatDownloadFileAlert:(id<IZMMTChatMessageModel>)message showCheckBox:(BOOL)showCheckBox action:(void(^)(BOOL))action;

- (void)showBestLayoutConfirmationAlert;
- (void)closeBestLayoutConfirmationAlert;

#pragma mark - Camera control
- (void)showRevokeCameraControllerAlertWithUserID:(ZMUserID)userID;
- (void)closeRevokeCameraControllerAlert;
- (void)showRequestCameraControlAlertWithUserID:(ZMUserID)userID;
- (void)closeRequestCameraControlAlert;

- (void)showGiveCameraControlAlert:(ZMUser *)user;
- (void)closeGiveCameraControlAlert:(ZMUser *)user;
- (void)closeAllGiveCameraControlAlert;
- (BOOL)isGiveCameraControlAlertShowing:(ZMUser *)user;

- (void)showAddToCameraControlGroupAlert:(ZMUser *)user;


#pragma mark - share screen
- (void)showWirediOSShareSyncAlert:(NSString *)name;
- (void)closeWirediOSShareSyncAlert;

#pragma mark - Simple Alert
- (void)showNormalAlertWithString:(NSString *)inString;
- (void)showAICCannotStartAlert:(NSString *)message;
- (void)closeAICCannotStartAlert;

@end

NS_ASSUME_NONNULL_END

#endif /* IZPAlertManager_h */
