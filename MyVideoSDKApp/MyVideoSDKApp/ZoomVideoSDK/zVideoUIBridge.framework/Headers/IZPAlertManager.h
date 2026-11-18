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
- (void)showWhiteboardOpenAlertWithCreate:(BOOL)isCreate completion:(void (^)(void))completion;
- (BOOL)showWhiteboardOpenAlertWithCreate:(BOOL)isCreate
                               completion:(void (^)(void))completion
                             cancelAction:(nullable dispatch_block_t)cancelAction;

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
- (void)closeAudioDeviceErrorAlert;
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

- (void)showUnableSaveBORoomsAlertWithCode:(uint32_t)code;
- (void)autoCloseAttendeePromotedToPanelistAlert;

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

// Closed caption / live transcript alerts
- (void)showLiveTranscriptRequestAlert;
- (void)closeLiveTranscriptRequestAlert;
- (void)showDeclineLiveTranscriptRequestAlert;
- (void)closeDeclineLiveTranscriptRequestAlert;
- (BOOL)isLiveTranscriptResponseAlertShowing;
- (void)showLiveTranscriptResponseAlertWithFromUser:(ZMUser *)fromUser bAnonymous:(BOOL)bAnonymous;
- (void)closeLiveTranscriptResponseAlert;

#pragma mark - Remote Support
- (void)showRequestControlAlertWithUser:(ZMUser *)inUser type:(int)inType;
- (void)closeRequestControlAlert;

#pragma mark - Remote Control
- (void)showRemoteControlRequestReceiveAlertWithUser:(ZMUser *)inUser
                                        approveBlock:(void(^)(void))approveBlock
                                        declineBlock:(void(^)(void))declineBlock;
- (BOOL)isRemoteControlRequestReceiveAlertShowing;
- (void)closeRemoteControlRequestReceiveAlert;
- (void)showAccessibilityPrivilegeGrantAlert;

- (void)showChangeCCEditorAlertWithNewUser:(ZMUser *)theUser
                             newEditorName:(nullable NSString *)newEditorName
                             oldEditorName:(nullable NSString *)oldEditorName;
- (void)closeChangeCCEditorAlert;

#pragma mark - Avatar Apply / VideoModel Download
- (void)showAvatarApplyFailedAlert;
- (void)closeAvatarApplyFailedAlert;
- (void)showVideoModelDownloadingAlert;
- (void)closeVideoModelDownloadingAlert;

#pragma mark - Audio Echo Dialog (ZOOM-1119777)
- (void)showAudioEchoSameMeetingDialogWithConnectAction:(nullable dispatch_block_t)connectAction
                                       useComputerAction:(nullable dispatch_block_t)useComputerAction
                                          dismissAction:(nullable dispatch_block_t)dismissAction;
- (void)showAudioEchoGeneralDialogWithUseComputerAction:(nullable dispatch_block_t)useComputerAction
                                              gotItAction:(nullable dispatch_block_t)gotItAction;
- (void)dismissAudioEchoDialogIfShowing;

#pragma mark - Voice Translator
- (void)showAIInterpretationSimulateVoiceDisclaimer;
- (void)showAIInterpretationSimulateVoiceDisclaimerByUser;
- (void)closeAIInterpretationSimulateVoiceDisclaimer;
@end

NS_ASSUME_NONNULL_END

#endif /* IZPAlertManager_h */
