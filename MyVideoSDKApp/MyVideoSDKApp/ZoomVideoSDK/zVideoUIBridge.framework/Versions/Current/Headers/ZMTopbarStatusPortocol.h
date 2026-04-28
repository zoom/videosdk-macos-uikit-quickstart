//
//  ZMTopbarStatusPortocol.h
//  VideoUI
//
//  Created by Michael Lin on 2024/2/1.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef ZMTopbarStatusPortocol_h
#define ZMTopbarStatusPortocol_h

// NOTE: The order of ZMTopbarItemType determines collapse priority.
// Lower enum value = higher priority to stay visible (collapsed last).
// When space is limited, items with higher enum values are collapsed first.
// This order follows Windows client's BadgesElemType priority.
typedef NS_ENUM(NSUInteger, ZMTopbarItemType) {
    ZMTopbarItemTypeInvalid = 0,
    ZMTopbarItemTypeExtendMeeting,
    ZMTopbarItemTypeSignIn,
    ZMTopbarItemTypeMeetingInfo,
    ZMTopbarItemTypeDisaster,
    ZMTopbarItemTypeIQ,
    ZMTopbarItemTypeTranscript,
    ZMTopbarItemTypeSummary,
    ZMTopbarItemTypeVoiceTranslation,
#ifdef ENABLE_ZAPP
    ZMTopbarItemTypeRTMS,
#endif
    ZMTopbarItemTypeOnAir,
    ZMTopbarItemTypeRecording,
    ZMTopbarItemTypeRecordAction,
    ZMTopbarItemTypeLiveStream,
    ZMTopbarItemTypeMediaStream,
    ZMTopbarItemTypeBackstage,
    ZMTopbarItemTypeWatchBackstagePresenting,
    ZMTopbarItemTypeWatchLiveWebinarFeed,
    ZMTopbarItemTypeArchive,
    ZMTopbarItemTypeAppSignal,
    ZMTopbarItemTypeRemainTime,
    ZMTopbarItemTypeBilling,
    ZMTopbarItemTypeTimer,
    ZMTopbarItemTypeClock,
#ifdef ENABLE_ZAPP
    ZMTopbarItemTypeAppTimer,
#endif
    ZMTopbarItemTypeLID,
#ifdef BUILD_FOR_DOGFOOD
    ZMTopbarItemTypeDogFood,
#endif
    ZMTopbarItemTypeProctoringMode,
    ZMTopbarItemTypeAudioWatermark,
    ZMTopbarItemTypeBandwidth,
    ZMTopbarItemTypeAudioPrivacy,
    ZMTopbarItemTypeGovDomain,
    ZMTopbarItemTypeMilDomain,
    ZMTopbarItemTypeCameraController,
    ZMTopbarItemTypeAudioController,
    ZMTopbarItemTypeFocusMode,
    ZMTopbarItemTypeNDI,
    ZMTopbarItemTypeBOBroadcast,
    ZMTopbarItemTypeOriginalSound,
    ZMTopbarItemTypeGatewaysIcon,
    ZMTopbarItemTypePairZoomRoom,
    ZMTopbarItemTypeNewSimulive,
    ZMTopbarItemTypeCertification,
    ZMTopbarItemTypeMyNotes,
    ZMTopbarItemTypeAIConfig,
    ZMTopbarItemTypeMore,
    ZMTopbarItemTypeViewOptions,
    ZMTopbarItemTypeSeperator,
    ZMTopbarItemTypeSwitchCamera,
    ZMTopbarItemTypeBackToSharing,
};

typedef NS_ENUM(NSUInteger, ZMTopbarStyle) {
    ZMTopbarStyleInvalid = 0,
    ZMTopbarStyleTopbar = 1 << 0,
    ZMTopbarStyleInfoBar = 1 << 1,
    ZMTopbarStyleMoreMenu = 1 << 2,
    ZMTopbarStyleNewUIStyle = ZMTopbarStyleInfoBar|ZMTopbarStyleMoreMenu,
    ZMTopbarStyleAll = ZMTopbarStyleTopbar|ZMTopbarStyleInfoBar|ZMTopbarStyleMoreMenu,
};

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMTopbarStatusPortocol <NSObject>
@optional
- (void)updateTopbarItemWithType:(ZMTopbarItemType)type;

- (void)updateTopbarItemWithType:(ZMTopbarItemType)type andRelayoutUI:(BOOL)relayoutUI;

- (void)updateTopbarUI;
- (void)updateTopbarUIForType:(ZMMTType)type;
- (void)relayoutTopbarUI;
- (void)relayoutTopbarUIForType:(ZMMTType)type;
- (void)refreshAllTopbarItems;
- (void)refreshAllTopbarItemsForType:(ZMMTType)type;

- (void)topbarWithType:(ZMMTType)type style:(ZMTopbarStyle)style appearanceChanged:(BOOL)appearance;

- (void)onTopbarRecordingShownChanged;

- (void)showTopbarAppSignalTip;
- (void)setTopbarRemainTime:(int)remainTime;
- (void)updateTopbarRemainTimeView;
- (void)showTopbarCameraControllerTip;
- (void)showTopbarBroadcastTipAndDismissLater;
- (void)showTopbarAudioControllerTip;

@end

#endif /* ZMTopbarStatusPortocol_h */
