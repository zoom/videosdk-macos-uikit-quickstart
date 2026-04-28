//
//  VideoUIBridge.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/6/17.
//

#import <Foundation/Foundation.h>

//! Project version number for VideoUIBridge.
FOUNDATION_EXPORT double VideoUIBridgeVersionNumber;

//! Project version string for VideoUIBridge.
FOUNDATION_EXPORT const unsigned char VideoUIBridgeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <VideoUIBridge/PublicHeader.h>

#ifdef __OBJC__

#import <zVideoUIBridge/ZMUIConstants.h>
#import <zVideoUIBridge/ZMMTViewType.h>
#import <zVideoUIBridge/ZMMTTransitionModel.h>
#import <zVideoUIBridge/ZMConfSession.h>
#import <zVideoUIBridge/ZMHelperMgr.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMMTAudioHelper.h>
#import <zVideoUIBridge/ZMMTConstants.h>
#import <zVideoUIBridge/ZMNsMenu.h>
#import <zVideoUIBridge/ZMConfAPI.h>
#import <zVideoUIBridge/ZMMTInterpretHelper.h>
#import <zVideoUIBridge/ZMMTVoiceTranslationHelper.h>
#import <zVideoUIBridge/ZMIQConstant.h>
#import <zVideoUIBridge/ZMMTQueriesHelper.h>
#import <zVideoUIBridge/ZMQuerySettingOptions.h>
#import <zVideoUIBridge/ZMAIDynamicNotifier.h>
#import <zVideoUIBridge/ZMMTDynamicLayoutModel.h>
#import <zVideoUIBridge/ZMMTMeetingInfoHelper.h>
#import <zVideoUIBridge/ZMMTClinicalNoteHelper.h>

#import <zVideoUIBridge/NSView+ZmmtKit.h>
#import <zVideoUIBridge/NSWindow+ZmmtKit.h>
#import <zVideoUIBridge/NSColor+ZmmtKit.h>
#import <zVideoUIBridge/NSString+ZmmtKit.h>
#import <zVideoUIBridge/NSAppearance+ZmmtKit.h>
#import <zVideoUIBridge/NSMutableArray+ZMUserHelper.h>
#import <zVideoUIBridge/NSAppearance+ZmmtKit.h>
#import <zVideoUIBridge/ZMMacroForSwift.h>
// Universal UI
#import <zVideoUIBridge/ZMMTAudioUUIHelper.h>

// CommonUI

#import <zVideoUIBridge/ZMMTBaseVideoCellView.h>
#import <zVideoUIBridge/ZMMTRender.h>

#import <zVideoUIBridge/ZMMTThumbnailView.h>
#import <zVideoUIBridge/ZMMTPageVideoView.h>
#import <zVideoUIBridge/ZMMTPaginationWrapper.h>

#import <zVideoUIBridge/ZMMTViewMgr.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>
#import <zVideoUIBridge/ZMMTBaseView.h>
#import <zVideoUIBridge/ZMMTTrackingView.h>

#import <zVideoUIBridge/ZMMTVideoView.h>
#import <zVideoUIBridge/ZMMTVideoViewController.h>
#import <zVideoUIBridge/ZMMTVideoViewMgr.h>

#import <zVideoUIBridge/ZMMTGridView.h>
#import <zVideoUIBridge/ZMMTGridCellView.h>
#import <zVideoUIBridge/ZMMTGridDragView.h>

#import <zVideoUIBridge/ZMTimerMgr.h>

#import <zVideoUIBridge/ZMGuideHelpButton.h>
#import <zVideoUIBridge/ZMMTBadgeView.h>
#import <zVideoUIBridge/ZMMTImageView.h>
#import <zVideoUIBridge/ZMMTLoadingView.h>
#import <zVideoUIBridge/ZMPlistTextField.h>
#import <zVideoUIBridge/ZMMTCustomTextView.h>

#import <zVideoUIBridge/ZPConfEventHandler.h>
#import <zVideoUIBridge/ZMFloatThumbnailHelper.h>

//Session&helper
#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-attributes"
#import <zVideoApp/CmmConfAPI.h>
#import <zVideoApp/CmmShareAPI.h>
#import <zVideoUIBridge/ZMConfHelper.h>
#import <zVideoUIBridge/ZMUser+NameTag.h>
#import <zVideoUIBridge/ZMUser+SmartTag.h>
#import <zVideoUIBridge/ZMShareSource.h>
#import <zVideoUIBridge/ZMSharePort.h>
#import <zVideoUIBridge/ZMRecordHelper.h>
#import <zVideoUIBridge/ZMVideoHelper.h>
#import <zVideoUIBridge/ZMAvatarHelper.h>
#import <zVideoUIBridge/ZMBOHelper.h>
#import <zVideoUIBridge/ZMMTClipsHelper.h>
#import <zVideoUIBridge/IZMMTStudioHelper.h>
#import <zVideoUIBridge/ZMMTCallCenter.h>
#import <zVideoUIBridge/ZMPBOHelper.h>
#import <zVideoUIBridge/ZMMTReactionHelper.h>
#import <zVideoUIBridge/ZMMTShareHelper.h>
#import <zVideoUIBridge/ZMMTSummaryHelper.h>
#import <zVideoUIBridge/ZMMTCameraControlHelper.h>
#import <zVideoUIBridge/ZMMEventTracker.h>
#import <zVideoUIBridge/ZMMTUniversalUIProtocol.h>
#import <zVideoUIBridge/ZMMTQAStatusProtocol.h>
#pragma clang diagnostic pop
#endif

#import <zVideoUIBridge/ZMMTEventV2Tracker.h>

#import <zVideoUIBridge/ZMUser.h>
#import <zVideoUIBridge/ZMUser+Clips.h>
#import <zVideoUIBridge/IZMMTPinVideoMgr.h>
#import <zVideoUIBridge/ZMMTConfigHelper.h>
#import <zVideoUIBridge/ZPConfHelper.h>
#import <zVideoUIBridge/ZMShareSource.h>
#import <zVideoUIBridge/IZMMTShareViewMgr.h>
#import <zVideoUIBridge/IZMMTSharingViewController.h>
#import <zVideoUIBridge/ZMMTUserHelper.h>
#import <zVideoUIBridge/ZMMTArchiveHelper.h>
#import <zVideoUIBridge/ZMMTGRHelper.h>
#import <zVideoUIBridge/ZMMTOnlineBusinessHelper.h>
#import <zVideoUIBridge/ZMMTWindow.h>
#import <zVideoUIBridge/ZMMTSidePanel.h>
#import <zVideoUIBridge/ZMMTSidePanelItem.h>

//protocols
#import <zVideoUIBridge/IZPConfUIMgr.h>
#import <zVideoUIBridge/IZMMainUIMgr.h>
#import <zVideoUIBridge/ZMMTModuleProtocol.h>
#import <zVideoUIBridge/IZMMTSessionLifeMgr.h>
#import <zVideoUIBridge/ZMMTConfStatusProtocol.h>
#import <zVideoUIBridge/IZMMTUserStatusProtocol.h>
#import <zVideoUIBridge/IZMMTInterpretationMgr.h>
#import <zVideoUIBridge/IZMMTSignInterpretVideoMgr.h>
#import <zVideoUIBridge/IZMMTWallViewMgr.h>
#import <zVideoUIBridge/IZMMTDynamicViewMgr.h>
#import <zVideoUIBridge/IZMMTGroupMgr.h>
#import <zVideoUIBridge/IZMMTVideoMgr.h>
#import <zVideoUIBridge/IZMMTPlistMgr.h>
#import <zVideoUIBridge/IZMMTWhiteboardMgr.h>
#import <zVideoUIBridge/IZMMTNotesMgr.h>
#import <zVideoUIBridge/IZMMTClipsShareMgr.h>
#import <zVideoUIBridge/IZMMTCustomViewMgr.h>
#import <zVideoUIBridge/IZPConfLayoutMgr.h>
#import <zVideoUIBridge/IZMMTVideoContentProtocol.h>
#import <zVideoUIBridge/ZMMTShareStatusProtocol.h>
#import <zVideoUIBridge/IZMMTProctoringModeMgr.h>
#import <zVideoUIBridge/IZMMTChatMgr.h>
#import <zVideoUIBridge/IZMMTQAMgr.h>
#import <zVideoUIBridge/IZMMTSimuliveViewMgr.h>
#import <zVideoUIBridge/IZMMTPracticeMgr.h>
#import <zVideoUIBridge/IZMMTBillingMgr.h>
#import <zVideoUIBridge/IZMMTIQMgr.h>
#import <zVideoUIBridge/IZMMTCompanionZEMgr.h>
#import <zVideoUIBridge/IZMClosedCaptionMgr.h>
#import <zVideoUIBridge/IZMMTTranscriptMgr.h>
#import <zVideoUIBridge/IZMConfReactionsMgr.h>
#import <zVideoUIBridge/IZMMTClinicalNoteMgr.h>
#import <zVideoUIBridge/IZPAlertManager.h>
#import <zVideoUIBridge/IZMGreenRoomMgr.h>
#import <zVideoUIBridge/IZMMTTransitionMgr.h>
#import <zVideoUIBridge/IZMMTSidePanelMgr.h>
#import <zVideoUIBridge/ZMMTAvatarProtocol.h>
#import <zVideoUIBridge/IZMMTNewMeetingInfoMgr.h>
#import <zVideoUIBridge/IZMMTDocMgr.h>
#import <zVideoUIBridge/ZMMTBaseView.h>
#import <zVideoUIBridge/IZMMTVoiceTranslationMgr.h>
#import <zVideoUIBridge/IZMMTMyNotesMgr.h>
#import <zVideoUIBridge/IZMMTToastMgr.h>
#import <zVideoUIBridge/ZMMTWindow.h>
#import <zVideoUIBridge/IZMMTWizardMgr.h>
#import <zVideoUIBridge/ZMMTOnlineBusinessProtocol.h>
#import <zVideoUIBridge/ZMMTSettingProtocol.h>
#import <zVideoUIBridge/IZMMTShortcutMgr.h>
#import <zVideoUIBridge/IZMLeaveMeetingMgr.h>
#import <zVideoUIBridge/IZMAuxUIMgr.h>
#import <zVideoUIBridge/IZMMTAudioMgr.h>
#import <zVideoUIBridge/IZMLipsyncMgr.h>
#import <zVideoUIBridge/IZMMTAIAccessibleMgr.h>
#import <zVideoUIBridge/IZMMTVideoLayoutMgr.h>
#import <zVideoUIBridge/IZMMTMiniViewMgr.h>
#import <zVideoUIBridge/IZMMTWaitingViewMgr.h>
#import <zVideoUIBridge/IZMMTVcardMgr.h>
#import <zVideoUIBridge/IZMMTBillingNoticeMgr.h>
#import <zVideoUIBridge/IZMMTCoachMarkMgr.h>
#import <zVideoUIBridge/IZMMTFallbackMgr.h>
#import <zVideoUIBridge/IZMMTAudioUIMgr.h>
#import <zVideoUIBridge/IZMShareMgr.h>
#import <zVideoUIBridge/IZMRecordMgr.h>
#import <zVideoUIBridge/IZMMTAudioCompanionMgr.h>
#import <zVideoUIBridge/IZMSummaryMgr.h>
#import <zVideoUIBridge/IZMMTImprovedCompanionMgr.h>
#import <zVideoUIBridge/IZMMTToolbarMgr.h>
#import <zVideoUIBridge/IZMConfTipMgr.h>
#import <zVideoUIBridge/IZMSDKFeaturesMgr.h>
// Video Render View Protocol (for StudioUI usage)
#import <zVideoUIBridge/IZMMTVideoRenderView.h>
#import <zVideoUIBridge/IZMMTVideoRenderViewFactory.h>

// Video Cell View Protocols
#import <zVideoUIBridge/IZMThumbnailVideoCellView.h>

#ifdef __cplusplus
#import <zVideoUIBridge/IZMMTPolicyUpdateProtocol.h>
#endif//__cplusplus
#import <zVideoUIBridge/ZMTopbarStatusPortocol.h>

//Forward Class
#import <zVideoUIBridge/ZMMTVideoCellView.h>
#endif//__OBJC__