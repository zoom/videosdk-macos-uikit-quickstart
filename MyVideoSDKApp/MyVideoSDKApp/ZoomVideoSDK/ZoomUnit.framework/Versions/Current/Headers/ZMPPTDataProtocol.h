//
//  ZMPPTDataProtocol.h
//  ZCommonUI
//
//  Created by FangJin on 8/7/15.
//  Copyright (c) 2015 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ZMRoomConstants.h"
#import <Zoomkit/zoom_client_conf.h>
@class ZRScreenRenderAllOptions;


@protocol ZMPPTDataProtocol <NSObject>

#ifdef BUILD_FOR_MIMO

typedef enum{
    Prompt_Waiting_Host_Start,
    Prompt_Waiting_Host_Admit,
} PROMPT_WAITING_TYPE;

//ZoomRooms interfaces:
- (BOOL)isMetalRenderEnabled;
- (int)getMetalDeviceCount;
- (BOOL)isMicMutedByExtendedDevice;
- (BOOL)isOptimized4VideoSharing;
- (void)enableOptimizeVideoSharing:(BOOL)enabled;
- (int)getLegalScreenCount;
- (NSArray*)getLegalScreens;
- (NSArray*)getSortedScreens;
- (int)getNSScreenIndexByGeographicalScreenPos:(int)position;
- (NSScreen*)getVideoScreenForGeographicalPostion:(int)position;
- (NSScreen*)getMainVideoScreen;
- (int)getMainVideoScreenPosition;
- (NSString*)abbreviatedRoomName;
- (NSString*)fullRoomName;
- (ZRScreenRenderAllOptions*)getWebScreenRenderOptions;
- (NSString*)getExclusiveCameraName4Video;
- (NSString*)getZoomShareURL;
- (void)onAirHostConnected;
- (void)onAirHostDisconnected;
- (void)onLocalShareStart;
- (void)onLocalShareStop;
- (void)notifyLocalShareStatus:(BOOL)bShare;
- (void)onBlackMagicDataReady:(BOOL)flag;
- (void)startLocalPresentation4AutoHdmi;
- (BOOL)needsStartLocalPresentation4AutoHdmi:(BOOL)newStatus;
- (void)onDirectPresentationDataReady:(NSInteger)type;
- (BOOL)isDirectPresentationCodeAllowedToShow;
- (void)onDirectPresentationPasscodeUpdated;
- (void)dismissScreenSaver;
- (void)disableScreenSaver;
- (void)enableScreenSaver;
- (BOOL)hasPendingPSTNCall;
- (BOOL)isEnteringMeeting;
- (BOOL)doesZRCSupportClosedCaption;
- (BOOL)isInSIPCall;
- (void)onConfObjectsWillDestroy;
- (BOOL)isRoomLoggedOn;
- (BOOL)isJoinOnlyMode;
- (void)onRoomUIAvailabilityUpdated;
- (void)setIsAutoHdmiLocalSharingMeeting:(BOOL)flag;
- (BOOL)isAutoHdmiLocalSharingMeeting;
- (BOOL)doesZRCSupportMuteVideoByOther;
- (BOOL)shouldHideShareInstructionFromTV;
- (void)onSharingStart:(int)sharingType;
- (void)onSharingEnd:(int)sharingType;
- (void)wantsToShowPTInfo:(BOOL)flag;
- (BOOL)isSelfVideoMirrored:(NSString*)deviceId;
- (void)onWallViewStyleUpdate:(int)style;
- (BOOL)doesZRCSupportInitiativeMeetingParticipantList;
- (BOOL)isZRIdleOutOfOperationTime;
- (BOOL)doesZRCSupportMultiShare;
- (BOOL)shouldMeetingStartWithMultiShareSwitchedOn;
- (NSString *)getAirhostShareToken;
- (BOOL)doesZRCSupportSilentMode;
- (void)showWaitingPrompt:(PROMPT_WAITING_TYPE)type isDisplay:(BOOL)bDisplay;
- (BOOL)shouldShowAudioParticipants;
- (BOOL)shouldShowMoreParticipantsInGallery;
- (BOOL)isNDIEnabled;
- (BOOL)isNDISeparateAudio;
- (void)notifyPT2UpdateIndicatorWithType:(ZR_INDICATOR_TYPE)type;
- (CGFloat)getOffsetXOfIndicator:(ZR_INDICATOR_TYPE)type;
- (NSString*)getCustomHDMIText;
- (void)showUserMutedAlert:(BOOL)isShow isVoip:(BOOL)isVoip;
- (void)relayoutMutedAlertOnAllScreens;
- (BOOL)isShowingUserMutedAlert;
- (BOOL)doesZRCSupportRecordingConsent;
- (BOOL)isDirectShareEncryptOptionEnabled;
- (NSData*)getWBCameraImage;
- (BOOL)doesZRCSupportMeetingViewChat;
- (BOOL)doesZRCSupportMeetingAudioTroubleshooting;
- (float)getOffsetBlowTopBannerLeft;
- (float)getOffsetBlowTopBannerRight;
- (BOOL)shouldStopMonitoringCaptureCard;
- (void)checkAndShowWarningForAllDefaultDevices;
- (int)getZRWUserID;
- (void)onZRWLeaveMeeting;
- (BOOL)isDisableMeetingChatNotification;
- (void)notifyInSilentMode:(BOOL)isInSilentMode;
- (BOOL)doesZRCSupportLocalView;
- (BOOL)isInLocalViewPolicy:(int)localScreenType meetingScreenCount:(int)meetingScreenCount;
- (void)stopWBCameraShare;
- (BOOL)isWBCameraSharing;
- (BOOL)doesZRCSupportAdjustShareAudio;
- (BOOL)hasControllerConnected;
- (BOOL)hasWebZRCConnected;
- (BOOL)hasPhoneZRCConnected;
- (BOOL)hasZRAOnlineConnection;
- (BOOL)isMultiZRCConnected;
- (BOOL)doesZRCSupportShowEncryptedMeetingIcon;
- (BOOL)doesZRCSupportsLanguageInterpretationParticipant;
- (BOOL)doesZRCSupportChinaMeetingPrivacy;
- (BOOL)doesZRCSupportMeetingDisclaimer;
- (BOOL)doesZRCSupportsLiveTranscription;
- (BOOL)isDisabledScreenShare;
- (void)usageTrackingScreenSharingSetting:(int)sharingSetting;
- (BOOL)doesZRCSupportWaitingRoomInLocalPresent;
- (void)notifyEnableAdmitGuest:(BOOL)isEnable;
- (BOOL)isTeamsMeetingInProgress;
- (BOOL)doesZRCSupportMultiScreenFloating;
- (BOOL)doesZRCSupportViewOnlyTalk;
- (BOOL)doesZRCSupportBreakoutSession;
- (BOOL)kickOutZRCNotSupportsDeleteMeetingChatMessageFeatrue;
- (BOOL)doesZRCSupportUSBWhiteboardCamera;
- (BOOL)getUsedLengthInTopBannerByPhoneController;
- (BOOL)doesZRCSupportsPrivacyAlert_LiveTranscription;
- (BOOL)doesZRCSupportViewWebinarAttendee;
- (BOOL)doesZRCSupportsPrivacyAlert_LiveStream;
- (BOOL)doesZRCSupportsPrivacyAlert_AllowTalk;
- (BOOL)doesZRCSupportsPrivacyAlert_PromotedToPanelist;
- (BOOL)doesZRCSupportsPrivacyAlert_Archive;
- (BOOL)doesZRCSupportsDisclaimer_JoinAsPanelist;
- (BOOL)doesZRCSupportsNDIUsage;
- (BOOL)getCurrentFixedNotificationType:(int*)type subType:(int*)subType;
- (BOOL)doesZRCSupportAppSignaling;
- (BOOL)doesZRCSupportsConfirmJoinMeetingVideoPreview;
- (BOOL)isScreenLocked;
- (void)updateIncomingShare:(BOOL)hasIncomingShare;
#else

//Zoom client interfaces:


typedef enum
{//[Zoom-20918]
    Event_Status_None = 0,
    Event_Status_Show = 1,//indicate control show or not
    Event_Status_Enable = 2,//indicate control enable or disable
    Event_Status_On = 4,//indicate control is on or off
    
}EVENT_PT_STATUS;

@optional
#endif

@end
