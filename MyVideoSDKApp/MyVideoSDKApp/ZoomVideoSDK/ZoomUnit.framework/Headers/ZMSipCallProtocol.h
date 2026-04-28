//
//  ZMSipCallProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 6/29/23.
//

#ifndef ZMSipCallProtocol_h
#define ZMSipCallProtocol_h

#import <ZoomUnit/ZMSipContactItemProtocol.h>
#import <ZoomUnit/ZMSipLanguageListProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBuddyAdapter;
@class ZMSipCloudPBX;
@class ZMSipRingtoneCallerIDSettings;
@class ZMSipCallOutInfo;
@class ZMSipCallOutInputParam;
@class ZMSipVerificationCodeParam;
@class ZMPIntegrationInfo;
@class ZMEscrowVoicemailItem;

@protocol ZMSipCallWarningProtocol <ZMRoutableObject>

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)deleagte userJID:(NSString*)jid openVideo:(BOOL)open;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andCancelCallBack:(NSString*)strCancelCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (void)closeWhenDelegateRelease:(id)privateDelegate;

- (void)closeWhenMeetingDeleted:(id)privateDelegate andMeetingNum:(long long)meetingNum;

@end

@protocol ZMSipCallExternalVoicemailAPIProtocol <NSObject>

- (void)updateUIWithCallID:(nonnull NSString *)callID;

@end

@protocol ZMSipCallExternalVoicemailEventProtocol <NSObject>

- (void)onExternalVoicemailChangedToInvalidWithCallIDs:(nonnull NSArray<NSString *> *)callIDs;

- (void)onExternalVoicemailUpdatedWithCallIDs:(nullable NSArray<NSString *> *)callIDs;

@end

@protocol IZMCallUpgradeDialogMgr <ZMRoutableObject>

- (NSUInteger)meetingCountBeforeShowUpgradeDialog;
- (void)addMeetingCount;

@end

@protocol ZMSipCallProtocol <ZMRoutableObject>

- (BOOL)hasSipCall;

@required

@property (nonatomic, readonly, nullable) id<IZMCallUpgradeDialogMgr> callUpgradeDialogMgr;

- (BOOL)isSIPFeatureEnabled;
- (BOOL)isCloudPBXCallEnable;
- (BOOL)isSipPhoneAvailable;

- (BOOL)checkPhoneTabIsVisible;

- (BOOL)isInCallWithAdapter:(ZMBuddyAdapter *)buddy;

- (BOOL)isInCallWithNumber:(NSString *)number;

- (BOOL)isCloudPBXEnable;
// for CloudPBX
- (BOOL)isAllowCallForMac;

- (BOOL)isAvayaEnabled;

- (BOOL)isMitelEnabled;

- (BOOL)isCallPSTNEnable;

- (ZMSipCloudPBX*)getMyPBXConfig;

- (BOOL)try2callPeer:(NSString*)number peerName:(NSString*)peerName numberType:(int)numberType;

- (void)navigate2SipTab;

- (BOOL)isInSIPCall;

- (BOOL)isInSIPCallAndUnhold;

- (BOOL)isInCCIAudio;

- (BOOL)hasCallingoutCall;

- (BOOL)hasIncomingCall;

- (BOOL)hasIncomingOrInCall;

- (BOOL)isEnableSMS;

- (BOOL)isVipSLAExecutiveEnable;

- (BOOL)isVipSLAEnable;

- (BOOL)isTransfering;

- (BOOL)isMitelCallForwardEnable;

- (BOOL)isPSISipCallForwardingInActive;

- (BOOL)showPSICallForwardingSetting;

- (BOOL)showCallForwardingSetting;

- (BOOL)isSipCallForwardingFeatureEnable;

- (BOOL)isSipCallForwardingInActive;

- (BOOL)isWarmTransfering;

- (BOOL)isEnableCallTransfer;

- (BOOL)isInServerConferenceCall;

- (NSInteger)getSipCallCount;

- (NSString*)getTransferCallID;

- (BOOL)isHideCallButtonInIM:(ZMBuddyAdapter *)useradapter;

- (BOOL)isCallButtonEnable:(ZMBuddyAdapter *)useradapter;

- (id <ZMSipContactItem>)getSipContactByID:(NSString *)cloudID;

- (void)selectedSessionWithToNumber:(NSString *)toNumber toName:(NSString *)toName;

- (void)transferCall:(NSString*)callID peerUri:(NSString*)peerUri warmTransfer:(int)transferType andNumberType:(int)type name:(NSString*)name jID:(NSString*)jID;

- (NSString *)isLinkedOrganization:(NSString *)paId;

- (void)requestUpdateHideZRAOption:(BOOL)isOpen;

- (void)handlePhoneDeepLinkWithParams:(NSDictionary <NSString *, NSString *> *)params;

- (BOOL)isBillingFeatureEnable;

- (nullable __kindof NSView<ZMSipCallExternalVoicemailAPIProtocol> *)voicemailConciseCardWithCallID:(nonnull NSString *)callID;

- (nullable NSView *)voicemailConciseCardLoadingView;

- (void)toResponsedKeyDownClickedWhileInDTMF:(NSEvent *)keyEvent;

- (BOOL)isPlayAudioFile;

- (void)pausePlayAudioAndUpdateUI;

- (BOOL)isInIPPhoneCall;

- (void)try2SyncMuteStatus2zzHostDevice;

- (void)unholdActiveCall;

- (BOOL)isPhoneAudioEnable;

- (void)muteCall:(BOOL)isMute;

- (void)acceptFromRevolabsDevice;

- (void)declineFromRevolabsDevice;

- (void)holdActiveCall:(BOOL)bPhoneAction;

- (void)syncDeviceStatusToPhone;

- (void)bringIncomingCallWindowToFront;

- (void)updateDiagnosticCallSessionSummary;

- (BOOL)isPSIPhoneEnabled;

- (BOOL)isCloudPBXActive;

- (BOOL)isConnectSBAServer;

- (void)onAudioDeviceUpdated;

- (void)onAudioDeviceUpdatedForCCI;

- (NSMutableDictionary *)getSwitchInfo;

- (void)showEscrowVoicemailPlaybackWindowWithItems:(NSArray<ZMEscrowVoicemailItem *> *)items;

- (void)onRequestEscrowVoicemailPlayUrlFinish:(NSString *)requestID
                                    isSuccess:(BOOL)isSuccess
                                    errorCode:(NSInteger)errorCode
                                      playUrl:(NSString *)playUrl;

- (void)onVoicemailKBServiceFinishInit:(BOOL)success;
- (void)onEncryptProvisionSuccess;
- (void)onEncryptDeviceApprovalFlowCompleted;

- (BOOL)isEnableIncomingCallNotificationFocusControl;

- (nullable ZMSipRingtoneCallerIDSettings*)getCallerIDListForRingtone;

- (NSInteger)getIncomingCallNotificationBlockType:(bool *)locked;

- (void)setIncomingCallNotificationBlockType:(NSInteger)type;

- (void)requestDeleteCallOutInfo:(NSString *)calloutId;

- (NSArray<ZMSipCallOutInfo *> *)getCallOutInfo;

- (void)setCallOutOption:(BOOL)useCallOut;

- (BOOL)getCallOutOption;

- (void)onRingOutUpdate;

- (BOOL)isEnableCallOutLandline;

- (void)requestUpdateCallOutParam:(ZMSipCallOutInputParam *)callOutParam;

- (void)requestVerificationCodeParam:(ZMSipVerificationCodeParam *)codeParam;

- (ZMPIntegrationInfo *)getSipIntegrationInfo;

- (ZMBuddyAdapter*)getMyUserInfo;

- (BOOL)isLocationPermissionOn;

- (BOOL)isSetDIDEnable;

- (BOOL)isShowEmergencyAddressInSetting;

- (BOOL)isE911CallFeatureEnabled;

- (BOOL)locationAuthorizationStatus;

- (BOOL)isDLROpend;

- (BOOL)isPersonalLocationOpen;

- (BOOL)needShowLocationAccessPermission;

- (BOOL)isLLDPEnable;

- (BOOL)isEmergencyServiceDashboardEnabled;

- (BOOL)isIndiaUser;

- (BOOL)isLocationHelperInstalled;

- (BOOL)isDeployLocationHelperByAdmin;

- (NSString *)getCurrentLocationHelperVersion;

- (BOOL)isTranscriptDefaultLanguageSettingAvailable;

- (nullable NSString *)defaultTranscriptLanguage;

- (nullable id<ZMSipLanguageListProtocol>)transcriptLanguageList;

- (void)requestForUpdateDefaultTranscriptLanguage:(NSString *)language;

- (BOOL)isPreferredTranslationLanguageSettingAvailable;

- (nullable NSString *)preferredTranslationLanguage;

- (nullable id<ZMSipLanguageListProtocol>)translationLanguageList;

- (void)setPreferredTranslationLanguage:(NSString *)language;

- (BOOL)isEnableDisplayAutoAnswerCQCall;

- (BOOL)isShowLocationOptionButton;

- (void)requestOptionalLocation:(int)option
                     address_id:(NSString *)address_id
                     page_index:(int)pageIndex;

- (BOOL)emergencyAddressManagementIsEnable;

- (nullable NSMutableDictionary *)getEmergencyAddressInfo;

- (BOOL)isLaunchExternalAppOrURL:(BOOL *)isMandatory;

- (BOOL)isEnableFax;

- (BOOL)isEnableCallOut;

- (BOOL)isEnableVideomail;

- (NSString *)getDefaultEmergencyOptionAddress;

- (NSUInteger)getCallQueueAutoAnswerPeriodIndex;

- (nullable NSMutableArray *)queryAppAutodialPreferenceWithNowDuration:(BOOL)needNowDuration;

- (BOOL)isRemoteControlEnable;

- (BOOL)isHideZRAOutgoingCallLogsEnable;

- (NSString *)getPreConfiguredURLorCmdForIncomingCall:(BOOL *)isMandatory;

- (BOOL)hasMyGreeting;

- (void)onSipCallForwardingStatusChange;

- (BOOL)isSipLiveTranscriptEnable;

- (BOOL)isSipLiveTranscriptAutoTurnOn;

- (BOOL)isEnableZRADailer;

- (void)emergencyButtonClickInSetting:(NSString *)buttonTitle;

- (void)requestLocationPermissionIfNeeded;

- (NSString *)transcriptLanguageForLocalizedName:(NSString *)localizedName;

- (void)requestForUpdateDefaultTranscriptLanguage:(NSString *)language;

- (void)setCallQueueAutoAnswerPeriodIndex:(NSUInteger)index;

- (void)setLaunchExternalAppOrURL:(BOOL)isLaunch;

- (void)testLaunchExternal;

- (void)showWebRTCWindowController;
- (void)notifyShowPhoneWebView:(BOOL)show;

- (NSInteger)updateSipLiveTranscriptAutoTurnOnState:(BOOL)onState;

- (void)onSettingClickDownloadAndInstallLocationHelper;

- (void)onRestrictFeatureUpdated;

// Greeting Call
- (BOOL)isInGreetingCall;
- (void)endGreetingCall;

// Monitoring Call
- (BOOL)isInMonitoringCallAndNotSupportHold;
- (void)endMonitoringCall;

@end

#ifndef ZMSharedSipCallHelper
#define ZMSharedSipCallHelper ZMSharedFor(ZMSipCallProtocol)
#endif /* ZMSharedSipCallHelper */


NS_ASSUME_NONNULL_END

#endif /* ZMSipCallProtocol_h */
