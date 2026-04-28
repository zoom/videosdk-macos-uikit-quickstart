//
//  ZMVideoUIBridgeProtocol.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2026/2/4.
//

#ifndef ZMVideoUIBridgeProtocol_h
#define ZMVideoUIBridgeProtocol_h

#ifdef __OBJC__

// MARK: - Shared
#import <zVideoUIBridge/IZMAuxUIMgr.h>
#import <zVideoUIBridge/IZMClosedCaptionMgr.h>
#import <zVideoUIBridge/IZMConfReactionsMgr.h>
#import <zVideoUIBridge/IZMConfTipMgr.h>
//#import <zVideoUIBridge/IZMFitBar.h>
//#import <zVideoUIBridge/IZMFitMgr.h>
#import <zVideoUIBridge/IZMGreenRoomMgr.h>
#import <zVideoUIBridge/IZMLeaveMeetingMgr.h>
#import <zVideoUIBridge/IZMLipsyncMgr.h>
#import <zVideoUIBridge/IZMMainUIMgr.h>
#import <zVideoUIBridge/IZMMTAIAccessibleMgr.h>
#import <zVideoUIBridge/IZMMTAudioCompanionMgr.h>
#import <zVideoUIBridge/IZMMTAudioMgr.h>
#import <zVideoUIBridge/IZMMTAudioUIMgr.h>
#import <zVideoUIBridge/IZMMTBillingMgr.h>
#import <zVideoUIBridge/IZMMTBillingNoticeMgr.h>
//#import <zVideoUIBridge/IZMMTBOControlMgr.h>
#import <zVideoUIBridge/IZMMTChatMgr.h>
#import <zVideoUIBridge/IZMMTClinicalNoteMgr.h>
#import <zVideoUIBridge/IZMMTClipsShareMgr.h>
#import <zVideoUIBridge/IZMMTCoachMarkMgr.h>
#import <zVideoUIBridge/IZMMTCompanionZEMgr.h>
#import <zVideoUIBridge/IZMMTCustomViewMgr.h>
#import <zVideoUIBridge/IZMMTDynamicViewMgr.h>
#import <zVideoUIBridge/IZMMTFallbackMgr.h>
//#import <zVideoUIBridge/IZMMTGalleryPlusMgr.h>
#import <zVideoUIBridge/IZMMTGroupMgr.h>
#import <zVideoUIBridge/IZMMTImprovedCompanionMgr.h>
#import <zVideoUIBridge/IZMMTIQMgr.h>
//#import <zVideoUIBridge/IZMMTMediaStreamMgr.h>
#import <zVideoUIBridge/IZMMTMiniViewMgr.h>
//#import <zVideoUIBridge/IZMMTMultiShareRequestMgr.h>
#import <zVideoUIBridge/IZMMTMyNotesMgr.h>
#import <zVideoUIBridge/IZMMTNewMeetingInfoMgr.h>
#import <zVideoUIBridge/IZMMTNotesMgr.h>
#import <zVideoUIBridge/IZMMTPinVideoMgr.h>
#import <zVideoUIBridge/IZMMTPlistMgr.h>
//#import <zVideoUIBridge/IZMMTPollingMgr.h>
#import <zVideoUIBridge/IZMMTProctoringModeMgr.h>
#import <zVideoUIBridge/IZMMTQAMgr.h>
//#import <zVideoUIBridge/IZMMTScreenResolutionMgr.h>
#import <zVideoUIBridge/IZMMTSessionLifeMgr.h>
#import <zVideoUIBridge/IZMMTShareViewMgr.h>
#import <zVideoUIBridge/IZMMTShortcutMgr.h>
//#import <zVideoUIBridge/IZMMTSimuliveMgr.h>
#import <zVideoUIBridge/IZMMTSimuliveViewMgr.h>
//#import <zVideoUIBridge/IZMMTStudioMgr.h>
#import <zVideoUIBridge/IZMMTToastMgr.h>
#import <zVideoUIBridge/IZMMTToolbarMgr.h>
#import <zVideoUIBridge/IZMMTVcardMgr.h>
#import <zVideoUIBridge/IZMMTVideoLayoutMgr.h>
#import <zVideoUIBridge/IZMMTVideoMgr.h>
#import <zVideoUIBridge/IZMMTVoiceTranslationMgr.h>
#import <zVideoUIBridge/IZMMTWaitingViewMgr.h>
//#import <zVideoUIBridge/IZMMTWallpaperViewController.h>
#import <zVideoUIBridge/IZMMTWallViewMgr.h>
#import <zVideoUIBridge/IZMMTWhiteboardMgr.h>
#import <zVideoUIBridge/IZMMTWizardMgr.h>
//#import <zVideoUIBridge/IZMPostMeetingMgr.h>
#import <zVideoUIBridge/IZMRecordMgr.h>
#import <zVideoUIBridge/IZMShareMgr.h>
#import <zVideoUIBridge/IZMSummaryMgr.h>
#import <zVideoUIBridge/IZPAlertManager.h>
#import <zVideoUIBridge/IZPConfLayoutMgr.h>
#import <zVideoUIBridge/IZPConfUIMgr.h>
// Shared/Interpretation
#import <zVideoUIBridge/IZMMTInterpretationMgr.h>
//#import <zVideoUIBridge/IZMMTInterpretExMgr.h>
#import <zVideoUIBridge/IZMMTSignInterpretVideoMgr.h>

// MARK: - Protocol
//#import <zVideoUIBridge/IZMFitMenuHelper.h>
//#import <zVideoUIBridge/IZMMEventTrackerProtocol.h>
//#import <zVideoUIBridge/IZMMTAnnotationEventProtocol.h>
#import <zVideoUIBridge/IZMMTEventV2Tracker.h>
//#import <zVideoUIBridge/IZMMTStudioHelper.h>
#import <zVideoUIBridge/IZMMTUserStatusProtocol.h>
//#import <zVideoUIBridge/IZMMTVideoCellView.h>
#import <zVideoUIBridge/IZMMTVideoContentProtocol.h>
#import <zVideoUIBridge/IZMThumbnailVideoCellView.h>
#import <zVideoUIBridge/ZMMTAvatarProtocol.h>
#import <zVideoUIBridge/ZMMTConfStatusProtocol.h>
//#import <zVideoUIBridge/ZMMTGalleryPlusUpdateProtocol.h>
#import <zVideoUIBridge/ZMMTModuleProtocol.h>
#import <zVideoUIBridge/ZMMTOnlineBusinessProtocol.h>
#import <zVideoUIBridge/ZMMTSettingProtocol.h>
#import <zVideoUIBridge/ZMMTShareStatusProtocol.h>
//#import <zVideoUIBridge/ZMMTToolbarTipEventsProtocol.h>
//#import <zVideoUIBridge/ZMMTUIModuleDelegate.h>
//#import <zVideoUIBridge/ZMMTUniversalUIProtocol.h>
#import <zVideoUIBridge/ZMTopbarStatusPortocol.h>
#ifdef __cplusplus
#import <zVideoUIBridge/IZMMTPolicyUpdateProtocol.h>
#endif

// MARK: - Model
//#import <zVideoUIBridge/IZMMTProductionStudioViewController.h>
#import <zVideoUIBridge/IZMMTSharingViewController.h>
#import <zVideoUIBridge/IZMMTVideoRenderView.h>
#import <zVideoUIBridge/IZMMTVideoRenderViewFactory.h>

// MARK: - Other
//#import <zVideoUIBridge/ZMMeetingStatusProtocol.h>

#endif // __OBJC__

#endif // !ZMVideoUIBridgeProtocol_h
