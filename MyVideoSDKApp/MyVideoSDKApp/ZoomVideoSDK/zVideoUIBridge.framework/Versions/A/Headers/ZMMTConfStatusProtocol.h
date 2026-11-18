//
//  ZMMTConfStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/8/15.
//

#ifndef ZMMTConfStatusProtocol_h
#define ZMMTConfStatusProtocol_h

@class ZMConfSession;

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMMTConfStatusProtocol <NSObject>
@optional
- (void)onPSSceneFetchResult:(BOOL)result;
- (void)onPSProducerChanged:(int)result;
- (void)onPSProducerLiving;
- (void)onPSUserWillLived:(NSUInteger)context;
- (void)onPSPublishSceneChanged;
- (void)onAvatarPermissionChanged;
- (void)onSummaryStatusChanged:(ZMConfSession*)session;
- (void)onAllowRequestAICompanionChanged:(ZMConfSession*)session;
- (void)onMyPSLProducerStopped:(int)inReason;
- (void)onPSLVideoSendingInfoHeartBeat:(BOOL)result;

- (void)onExtendMeeting:(BOOL)result;
- (void)onCancelExtendMeeting:(BOOL)result;
- (void)extendStatusOnMMR:(BOOL)result;
- (void)onUserCount1To2Or2To1:(BOOL)result;

- (void)allowAttendeeRaiseHandStatusChanged:(ZMConfSession *)confSession;

- (void)onParticipantUserCountChanged;
- (void)onViewOnlyUserCountChanged;

// AI Sales Assist (ZOOM-1242563) — common-side panel info/status changed; the
// current panel URL is available via ICmmConfStatus::GetAISalesAssistPanelUrl().
// Driven by CMD_CONF_AI_SALES_ASSIST_PANEL_INFO_READY.
- (void)onAISalesAssistPanelInfoReady:(ZMConfSession *)session;

// AI Sales Assist meeting/license state changed. Consumers that read
// ICmmConfStatus::CanStartAISalesAssist() or
// ICmmConfStatus::IsAISalesAssistStartedInMeeting() should refresh here.
// /
// CMD_CONF_AI_SALES_ASSIST_START_RESULT.
- (void)onAISalesAssistStatusChanged:(ZMConfSession *)session;

// Workflows feature state changed. Driven by CMD_CONF_LTTGW_FEATURE_ON_CHANGED.
- (void)onLTTGWFeatureOnChanged:(ZMConfSession *)session;

// The host's "restrict external users from using AI" setting changed (e.g. an
// external user joined/left). When it applies, AI Companion is turned off and
// AI Sales Assist must be closed/hidden too. Driven by
// CMD_CONF_AIC_RESTRICTED_BY_EXTERNAL_USER_CHANGED /
// CMD_CONF_AIC_RESTRICTED_BY_USER. ZOOM-1242563
- (void)onAICRestrictedByExternalUserChanged:(ZMConfSession *)session;

// Meeting/event hub logo finished downloading. Driven by CMD_CONF_MEETING_LOGO_READY.
- (void)onMeetingLogoReady:(ZMConfSession *)session;
@end


#endif /* ZMMTConfStatusProtocol_h */
