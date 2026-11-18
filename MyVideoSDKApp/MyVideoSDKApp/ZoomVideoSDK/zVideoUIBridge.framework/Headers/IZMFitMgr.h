//
//  IZMFitMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMFitMgr_h
#define IZMFitMgr_h

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMFitBarComponentTag) {
    ZMFitBarComponentTagNone = 0,
    ZMFitBarComponentTagAudio,
    ZMFitBarComponentTagAudioSetting,
    ZMFitBarComponentTagAudioCompanionMic,
    ZMFitBarComponentTagAudioCompanionSpeaker,
    ZMFitBarComponentTagVideo,
    ZMFitBarComponentTagSecurity,
    ZMFitBarComponentTagParticipant,
    ZMFitBarComponentTagChat,
    ZMFitBarComponentTagQA,
    ZMFitBarComponentTagPolling,
    ZMFitBarComponentTagBroadcast,
    ZMFitBarComponentTagShare,
    ZMFitBarComponentTagPauseShare,
    ZMFitBarComponentTagShareLayout,
    ZMFitBarComponentTagAnnotate,
    ZMFitBarComponentTagRemoteControl,
    ZMFitBarComponentTagSlideControl,
    ZMFitBarComponentTagMore,
    ZMFitBarComponentTagMoreFeatures,
    ZMFitBarComponentTagInterpretation,
    ZMFitBarComponentTagReactions,
    ZMFitBarComponentTagRaiseHand,
    ZMFitBarComponentTagRecord,
    ZMFitBarComponentTagTranscript,
    ZMFitBarComponentTagClosedCaption,
    ZMFitBarComponentTagZoomIQ,
    ZMFitBarComponentTagCertifications,
    ZMFitBarComponentTagBO,
    ZMFitBarComponentTagWebinarBO,
    ZMFitBarComponentTagGreenRoom,
    ZMFitBarComponentTagSupport,
    ZMFitBarComponentTagSidecar,
    ZMFitBarComponentTagBilling,
    ZMFitBarComponentTagLivestream,
    ZMFitBarComponentTagRoomController,
    ZMFitBarComponentTagZoomApp,
    ZMFitBarComponentTagImprovedCompanion,
    ZMFitBarComponentTagEnterCompanion,
    ZMFitBarComponentTagLeaveCompanion,
};

/**
 * @router ZMMTShared
 */
@protocol IZMFitMgr <ZMRoutableObject>

- (void)updateComponentWithTag:(ZMFitBarComponentTag)tag;
- (void)updateComponentWithTag:(ZMFitBarComponentTag)tag needRelayout:(BOOL)needRelayout;
- (void)updateAudio;
- (void)updateInterpretationButton;
- (void)setRemainTime:(int)inTime;
- (void)updateRemainTimeView;
- (void)updateQA;
- (void)updateRoomControllerButton;
- (void)updateBOBroadcastViewAndRelayout;
- (void)updateLiveStreamIndicator;

// ToolSuite
- (void)showToolbarWindow;
- (void)hideToolbarWindow;

- (BOOL)isToolbarShowing;
- (void)closeReactionsMenu;
- (BOOL)isReactionsMenuShowing;
- (void)showMoreEmojiMenu;

- (void)showCCTip:(NSString *)tipString;
- (void)hideCCTip;
- (void)updateLIDIndicator;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMFitMgr_h */
