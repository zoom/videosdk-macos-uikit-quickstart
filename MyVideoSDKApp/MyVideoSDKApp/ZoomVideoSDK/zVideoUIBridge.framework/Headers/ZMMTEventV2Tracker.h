//
//  ZMMTEventV2Tracker.h
//  VideoUIBridge
//
//  Created by vinson.wang on 2025/3/25.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#import <zVideoUIBridge/ZMConfHelper.h>
#import <zTelemetryBiz/zTelemetryBizInterface.h>
#import <zTelemetryBiz/SnowplowBiz/meetings_v2/meetings_v2_telemetry_interface.h>
#import <zTelemetryBiz/SnowplowBiz/meetings_v2/meetings_v2_telemetry_types.h>
#import <zTelemetryBiz/SnowplowBiz/zoom_apps_v2/zoom_apps_v2_telemetry_interface.h>
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMTFeatureName) {
    ZMMTFeatureNameNotSet = 0,
    ZMMTFeatureNameUnknown,
    ZMMTFeatureNameShare,
    ZMMTFeatureNameVideoLayout,
    ZMMTFeatureNameApps,
    ZMMTFeatureNameChat,
    ZMMTFeatureNameAccount,
    ZMMTFeatureNameBillableHours,
    ZMMTFeatureNameMeetingJoinFlow,
    ZMMTFeatureNameProductionStudio,
    ZMMTFeatureNameTheme,
    // MARK: - Audio Echo Dialog (ZOOM-1119777)
    ZMMTFeatureNameZrCompanion,
    // MARK: - Reaction Redesign Telemetry
    ZMMTFeatureNameReactions,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTFeatureNameBreakoutRooms,
    // MARK: - AWDL in-meeting toast (ZOOM-1242332)
    ZMMTFeatureNameNotice,
};

typedef NS_ENUM(NSInteger, ZMMTEventType) {
    ZMMTEventTypeNotSet = 0,
    ZMMTEventTypeClicked,
    ZMMTEventTypeScreenDisplayed,
    ZMMTEventTypeDragged,
    ZMMTEventTypeKeyboardShortcut,
    // MARK: - Reaction Redesign Telemetry
    ZMMTEventTypePageLoad,
};

typedef NS_ENUM(NSInteger, ZMMTSubFeatureName) {
    ZMMTSubFeatureNameNotSet = 0,
    ZMMTSubFeatureNameClipsShare,
    ZMMTSubFeatureNameAppDiscovery,
    ZMMTSubFeatureNameLogin,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTSubFeatureNameRightPanel,
};

typedef NS_ENUM(NSInteger, ZMMTEventSource) {
    ZMMTEventSourceNotSet = 0,
    ZMMTEventSourceUnknown,
    ZMMTEventSourceSelectShareWindow,
    ZMMTEventSourceShareCallback,
    ZMMTEventSourceClipsFilePicker,
    ZMMTEventSourceClipsPlayer,
    ZMMTEventSourceClipsLoadingToast,
    ZMMTEventSourceWindowTabBar,
    ZMMTEventSourceConfReady,
    ZMMTEventSourceProductionStudioWindow,
    ZMMTEventSourceChatPanel,
    ZMMTEventSourceMainMeetingToolbar,
    ZMMTEventSourcePreviewDialog,
    ZMMTEventSourcePsCloseConfirmWindow,
    ZMMTEventSourcePsTakeoverConfirmWindow,
    ZMMTEventSourceTopBadgeBar,
    // MARK: - Audio Echo Dialog (ZOOM-1119777)
    ZMMTEventSourceUltrasoundFeedbackZrEchoDialog,
    ZMMTEventSourceUltrasoundFeedbackSameMeetingWithZrDialog,
    // MARK: - Reaction Redesign Telemetry
    ZMMTEventSourceQuickReactionPanel,
    // MARK: - Share Picker Refresh (ZOOM-1235865)
    ZMMTEventSourcePermissionSettingWindow,
    ZMMTEventSourceReactionPanel,
    ZMMTEventSourceMorePanel,
    ZMMTEventSourceEffectiveMorePanel,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTEventSourceBreakoutRoomsPanel,
    // MARK: - AWDL in-meeting toast (ZOOM-1242332)
    ZMMTEventSourceTopRightToast,
    ZMMTEventSourceVideoPort,
};

typedef NS_ENUM(NSInteger, ZMMTEventLocation) {
    ZMMTEventLocationNotSet = 0,
    ZMMTEventLocationUnknown,
    ZMMTEventLocationNA,
    ZMMTEventLocationShareButton,
    ZMMTEventLocationPlayButton,
    ZMMTEventLocationProgressBar,
    ZMMTEventLocationVolumeButton,
    ZMMTEventLocationOptimizeButton,
    ZMMTEventLocationSpeedButton,
    ZMMTEventLocationStopButton,
    ZMMTEventLocationMoreButton,
    ZMMTEventLocationChatContextMenu,
    ZMMTEventLocationShowZoomWindowsButton,
    ZMMTEventLocationShowSpecificWindowsButton,
    ZMMTEventLocationPreventRepeatingWindowButton,
    ZMMTEventLocationShowWatermarkButton,
    ZMMTEventLocationAddPresenterButton,
    ZMMTEventLocationAddSpeakerButton,
    ZMMTEventLocationBillableHoursButton,
    ZMMTEventLocationCloseStopButton,
    ZMMTEventLocationDragSourceListView,
    ZMMTEventLocationGalleryViewButton,
    ZMMTEventLocationNotifySpeakerButton,
    ZMMTEventLocationPlusIcon,
    ZMMTEventLocationPreviewScene,
    ZMMTEventLocationSendLiveButton,
    ZMMTEventLocationSignInButton,
    ZMMTEventLocationSpeakerViewButton,
    ZMMTEventLocationTakeOverFirstConfirmButton,
    ZMMTEventLocationTakeOverSecondConfirmButton,
    ZMMTEventLocationViewButton,
    ZMMTEventLocationVideoMenuButton,
    ZMMTEventLocationSelfViewControlButton,
    ZMMTEventLocationAppsDropdown,
    ZMMTEventLocationAccountInfo,
    ZMMTEventLocationAccountInfoJoinButton,
    ZMMTEventLocationAccountInfoMenuJoinAsAnotherAccount,
    ZMMTEventLocationAccountInfoMenuJoinWithoutSignIn,
    // MARK: - Audio Echo Dialog (ZOOM-1119777)
    ZMMTEventLocationPrimaryButton,
    ZMMTEventLocationSecondaryButton,
    ZMMTEventLocationCloseButton,
    // MARK: - Reaction Redesign Telemetry
    ZMMTEventLocationReactionEmojiButtons,
    ZMMTEventLocationReactionPanel,
    ZMMTEventLocationAudibleClapButton,
    ZMMTEventLocationRaiseHandButton,
    ZMMTEventLocationBeRightBackButton,
    ZMMTEventLocationReactionEffectiveEmojiButtons,
    ZMMTEventLocationMixedTab,
    ZMMTEventLocationCoffeeFeedbackButton,
    ZMMTEventLocationAnimatedEmojis,
    ZMMTEventLocationSkinToneButton,
    ZMMTEventLocationFeedbackButtons,
    ZMMTEventLocationFrequentlyUsedEmojis,
    ZMMTEventLocationPopularCustomEmojis,
    ZMMTEventLocationEmojiTab,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTEventLocationPopoutButton,
    ZMMTEventLocationPopinButton,
    // MARK: - Share Picker Refresh (ZOOM-1283469 / ZOOM-1281387 / ZOOM-1286349)
    ZMMTEventLocationShareSelectTile,
    ZMMTEventLocationViewAllButton,
    ZMMTEventLocationCreateButton,
    // MARK: - Files search telemetry (ZOOM-1359130)
    ZMMTEventLocationSearchButton,
    ZMMTEventLocationTemplateEntry,
    ZMMTEventLocationShareSelectSearchBox,
    // MARK: - AWDL in-meeting toast (ZOOM-1242332)
    ZMMTEventLocationLinkButton,
};

typedef NS_ENUM(NSInteger, ZMMTEventName) {
    ZMMTEventNameNotSet = 0,
    ZMMTEventNameUnknown,
    ZMMTEventNameStartShare,
    ZMMTEventNameStartPlay,
    ZMMTEventNameStartShareScreen,
    ZMMTEventNameShareSelectContentDisplayed,
    ZMMTEventNamePlayShare,
    ZMMTEventNamePauseShare,
    ZMMTEventNameChangeProgress,
    ZMMTEventNameChangeClipsVolume,
    ZMMTEventNameChangeVideoShare,
    ZMMTEventNameChangeSpeed,
    ZMMTEventNameStopShare,
    ZMMTEventNameThemeConfig,
    ZMMTEventNameVideoLayoutPreference,
    ZMMTEventNameChangeSelfViewOption,
    ZMMTEventNameChangeShowZoomWindows,
    ZMMTEventNameChangeShowSpecificWindows,
    ZMMTEventNameChangePreventRepeatingWindow,
    ZMMTEventNameShowWatermark,
    ZMMTEventNameAddPresenter,
    ZMMTEventNameAddSpeaker,
    ZMMTEventNameChangeTheme,
    ZMMTEventNameChangeToGalleryView,
    ZMMTEventNameChangeToSpeakerView,
    ZMMTEventNameCloseAndStopLive,
    ZMMTEventNameCreateTask,
    ZMMTEventNameDragAddPresenter,
    ZMMTEventNameDragAddSpeaker,
    ZMMTEventNameLoadFailed,
    ZMMTEventNameLoadSuccess,
    ZMMTEventNameNotifySpeakerWillLive,
    ZMMTEventNameOpenAddAppToChatPage,
    ZMMTEventNameOpenShareLayoutPanel,
    ZMMTEventNamePreventingRepeatingWindowWorking,
    ZMMTEventNameProductionStudio,
    ZMMTEventNameSendLive,
    ZMMTEventNameSignIn,
    ZMMTEventNameStartFromMeetingBeginning,
    ZMMTEventNameStartNow,
    ZMMTEventNameTakeOverFirstConfirm,
    ZMMTEventNameTakeOverSecondConfirm,
    ZMMTEventNameAppSelected,
    ZMMTEventNameShowAccountInfo,
    ZMMTEventNameJoinMeeting,
    ZMMTEventNameJoinAsAnotherAccount,
    ZMMTEventNameJoinWithoutSignIn,
    // MARK: - Audio Echo Dialog (ZOOM-1119777)
    ZMMTEventNameConnectAsCompanion,
    ZMMTEventNameJoinAudio,
    ZMMTEventNamePrimaryButtonClicked,
    ZMMTEventNameCloseButtonClick,
    // MARK: - Reaction Redesign Telemetry
    ZMMTEventNameChooseEmoji,
    ZMMTEventNameRaiseHand,
    ZMMTEventNameLowerHand,
    ZMMTEventNameBeRightBack,
    ZMMTEventNameIAmBack,
    ZMMTEventNameChooseEffectiveEmoji,
    ZMMTEventNameClosePanel,
    ZMMTEventNameCloseEmojiPanel,
    ZMMTEventNameReactMorePanelShow,
    ZMMTEventNameChooseFeedback,
    ZMMTEventNameDeselectFeedback,
    ZMMTEventNameChangeSkinTone,
    // MARK: - Share Picker Refresh (ZOOM-1235865)
    ZMMTEventNamePermissionSettingWindowDisplayed,
    ZMMTEventNameReactionPanelShow,
    ZMMTEventNameAudibleClap,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTEventNamePopOut,
    ZMMTEventNamePopIn,
    ZMMTEventNameOpen,
    // MARK: - Share Picker Refresh (ZOOM-1283469 / ZOOM-1281387 / ZOOM-1286349)
    ZMMTEventNameShareTileSelected,
    ZMMTEventNameOpenHubModal,
    ZMMTEventNameOpenCreateMenu,
    // MARK: - Files search telemetry (ZOOM-1359130)
    ZMMTEventNameOpenSearch,
    ZMMTEventNameSearchFiles,
    ZMMTEventNameCloseSearch,
    // MARK: - AWDL in-meeting toast (ZOOM-1242332)
    ZMMTEventNameShowToast,
    ZMMTEventNameLinkButtonClick,
};

typedef NS_ENUM(NSInteger, ZMMTEventStatus) {
    ZMMTEventStatusNotSet = 0,
    ZMMTEventStatusCheck,
    ZMMTEventStatusUncheck,
    // MARK: - Breakout Rooms Right Panel (ZOOM-1272351)
    ZMMTEventStatusFloating,
    ZMMTEventStatusDocked,
};

typedef NS_ENUM(NSInteger, ZMMTShareContentType) {
    ZMMTShareContentTypeNotSet = 0,
    ZMMTShareContentTypeUnknow,
    ZMMTShareContentTypeApp,
    ZMMTShareContentTypeDesktop,
    ZMMTShareContentTypeWhiteboard,
    ZMMTShareContentTypeAirHost,
    ZMMTShareContentTypeCamera,
    ZMMTShareContentTypeWiredDevice,
    ZMMTShareContentTypeFrame,
    ZMMTShareContentTypePureAudio,
    ZMMTShareContentTypeDropbox,
    ZMMTShareContentTypeOnedriver,
    ZMMTShareContentTypeGoogledriver,
    ZMMTShareContentTypeBox,
    ZMMTShareContentTypeMsSharepoint,
    ZMMTShareContentTypeProcess,
    ZMMTShareContentTypeVideofile,
    ZMMTShareContentTypeZoomapps,
    ZMMTShareContentTypeMacPicker,
    ZMMTShareContentTypeClips,
    ZMMTShareContentTypeZoomDocs,
    ZMMTShareContentTypeZoomNotes,
    ZMMTShareContentTypeZoomWhiteboards,
    ZMMTShareContentTypePptShare,
    ZMMTShareContentTypeBrowserTabChrome,
    ZMMTShareContentTypeBrowserTabEdge,
    // MARK: - Share Picker Refresh (ZOOM-1235865)
    ZMMTShareContentTypeZoomExistingCanvasDocs,
    ZMMTShareContentTypeZoomExistingSlides,
    ZMMTShareContentTypeZoomExistingSheets,
    ZMMTShareContentTypeZoomExistingPaper,
    ZMMTShareContentTypeZoomNewCanvasDocs,
    ZMMTShareContentTypeZoomNewSlides,
    ZMMTShareContentTypeZoomNewSheets,
    ZMMTShareContentTypeZoomNewPaper,
    // MARK: - Icebreakers (ZOOM-1264296)
    ZMMTShareContentTypeIcebreakers,
    ZMMTShareContentTypeZoomExistingWhiteboard,
    ZMMTShareContentTypeZoomNewWhiteboard,
};

typedef NS_ENUM(NSInteger, ZMMTShareResult) {
    ZMMTShareResultNotSet = 0,
    ZMMTShareResultSuccess,
    ZMMTShareResultStartShareServerFailed,
    ZMMTShareResultTimeOut,
    ZMMTShareResultNoPermission,
    ZMMTShareResultUnknown,
};

@interface ZMMTEntity : NSObject
@property(nonatomic, assign) BOOL wallpaper;
@property(nonatomic, assign) BOOL shareOptions;
@property(nonatomic, assign) BOOL shareResult;
@property(nonatomic, assign) BOOL meetingToolbar;
@property(nonatomic, assign) BOOL userStatus;
@property(nonatomic, assign) BOOL themeConfig;
@property(nonatomic, assign) BOOL videoLayoutPreference;
@property(nonatomic, assign) BOOL productionStudioScene;

#ifdef __cplusplus
- (ZUUI::UuiEventTrackInfo)trackInfo;

- (MeetingsV2ThemeConfigEntityParams)themeConfigEntity;
#endif

+ (instancetype)mainToolbar;
@end

@interface ZMMTV2Telemetry : NSObject

@property(nonatomic, assign) ZMMTFeatureName featureName;
@property(nonatomic, assign) ZMMTEventType eventType;
@property(nonatomic, assign) ZMMTEventSource eventSource;
@property(nonatomic, assign) ZMMTEventLocation eventLocation;
@property(nonatomic, assign) ZMMTEventName eventName;
@property(nonatomic, assign) ZMMTSubFeatureName subFeatureName;
@property(nonatomic, assign) ZMMTEventStatus eventStatus;

@property(nonatomic, strong, nullable) NSString * eventTraceSource;
@property(nonatomic, assign) ZMMTShareContentType shareContentType;
@property(nonatomic, assign) ZMMTShareResult shareResult;
@property(nonatomic, strong, nullable) NSString * errorCode;

@property(nonatomic, strong) ZMMTEntity* entity;

+ (instancetype)themeEvent;
+ (instancetype)videoLayoutEvent;
+ (instancetype)productionStudioEvent;
+ (instancetype)chatEvent;
@end

@interface ZMMTEventV2Tracker : NSObject

#ifdef ENABLE_ZAPP
+ (void)trackZappFunnelWithInfo:(ZMZAppsInteractInfo *)info;
#endif

+ (void)trackMeetingEvent:(ZMMTV2Telemetry *)meetingEvent;

+ (void)trackMeetingEventWithTelemetryID:(NSString *)telemetryID;

#ifdef __cplusplus
// ZOOM-1227620: extension point — caller can mutate the underlying C++ params
// (e.g. set per-call entity fields that don't belong on the generic
// ZMMTV2Telemetry payload class) right before the event is submitted.
+ (void)trackMeetingEvent:(ZMMTV2Telemetry *)meetingEvent
                 addition:(nullable void(^)(MeetingsV2InteractionTelemetryParams &params))addition;

+ (e_Interaction_feature_name)convertFeatureName:(ZMMTFeatureName)name;
+ (e_Interaction_event_type)convertEventType:(ZMMTEventType)type;
+ (e_Interaction_sub_feature_name)convertSubFeatureName:(ZMMTSubFeatureName)name;
+ (e_Interaction_event_source)convertEventSource:(ZMMTEventSource)source;
+ (e_Interaction_event_location)convertEventLocation:(ZMMTEventLocation)location;
+ (e_Interaction_event_name)convertEventName:(ZMMTEventName)name;
+ (e_meetings_v2_Interaction_event_status)convertEventStatus:(ZMMTEventStatus)status;
+ (e_meetings_v2_ShareOptionsEntity_share_content_type)convertShareContentType:(ZMMTShareContentType)type;
+ (e_meetings_v2_ShareResultEntity_result)convertShareResult:(ZMMTShareResult)result;
#endif

@end

NS_ASSUME_NONNULL_END
