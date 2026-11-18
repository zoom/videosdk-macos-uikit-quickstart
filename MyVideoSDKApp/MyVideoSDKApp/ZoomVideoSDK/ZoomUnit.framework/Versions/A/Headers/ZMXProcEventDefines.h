//
//  ZMXProcEventDefines.h
//  ZoomUnit
//
//  Shared wire contract for the cross-process "global notification" relay
//  riding on ZMXProcEventBus. Both the PT and Meeting relay managers depend
//  on these definitions to agree on payload format.
//
//  Copyright (c) Zoom Communications. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Identifies a relayed notification. Values are grouped by source protocol
/// and must never be renumbered (PT and Meeting ship together; adding cases
/// is always safe).
typedef NS_ENUM(NSInteger, ZMXProcEventID) {
    ZMXProcEventIDNone = 0,

    // ZMLoginProtocol lifecycle (no payload unless noted).
    ZMXProcEventIDLogin_DidLogin             = 1000,
    ZMXProcEventIDLogin_WillLogout           = 1001,
    ZMXProcEventIDLogin_DidLogout            = 1002,
    ZMXProcEventIDLogin_LoginWindowWillClose      = 1003,
    ZMXProcEventIDLogin_LoginWindowDidShow   = 1004,
    
    // Meeting
    ZMXProcEventIDMeeting_ConfUIDidCreate    = 1010,
    ZMXProcEventIDMeeting_RequestPTForceQuitting = 1011,
    // Multi-process relay for kNoti_Conf_Fail. userInfo carries the same
    // dictionary the in-process notification uses (see ZMInteractiveEnum
    // kNoti_Conf_* / kParam_* keys).
    ZMXProcEventIDMeeting_ConfFailed         = 1020,

    // PT-driven Meeting control (PT process -> Meeting subprocess).
    // Multi-process relay for kNoti_PTForceToLeaveCurConf — PT asks the
    // Meeting side (e.g. ZMLeaveMeetingMgr) to leave the current conference.
    ZMXProcEventIDPT_ForceToLeaveCurConf     = 1030,

    // ZMVoiceNotesProtocol relay (PT process -> Meeting subprocess).
    // PT broadcasts MyNotes setting/status changes; userInfo carries the
    // current enable flag under kZMXProcEventKeyMyNotesEnable so Meeting-side
    // listeners can refresh without querying the PT-only IZMVoiceNotesMgr.
    ZMXProcEventIDMyNotes_SettingChanged     = 1040,
    ZMXProcEventIDMyNotes_StatusChanged      = 1041,
    ZMXProcEventIDMyNotes_RunningStatusChanged  = 1042,

    // On-demand download relay (PT process -> UI subprocess(es)). userInfo
    // carries the download fields keyed by ZMDownloadXProcRoute
    // (type/stage/process/result/error*); ZMXProcEventPoster forwards the
    // dictionary opaquely, so ZoomUnit does not depend on the download keys.
    ZMXProcEventIDDownload_Progress          = 1050,
    ZMXProcEventIDDownload_Complete          = 1051,
    ZMXProcEventIDDownload_StateChanged      = 1052,

    // Setting control (UI subprocess -> PT). Multi-process relay for
    // kParam_ConfNotifyPTCloseSetting — a UI subprocess (e.g. Meeting camera
    // control) asks PT to close a setting view. userInfo carries the source
    // tag under kZMXProcEventKeyCloseSettingSource so the PT-side observers
    // can tell which setting tab to close.
    ZMXProcEventIDMeeting_ClosePTSetting     = 1060,

    // Meeting subprocess -> PT relay for post-meeting popups (kNoti_*).
    // userInfo carries the same dictionary the in-process notification used,
    // with kMeetingAssets / kMTNoticeInfo flattened by [obj zm_toDictionary]
    // on the publisher side and rebuilt by dispatchLocally: on the PT side.
    ZMXProcEventIDMeeting_ConfLeavingReason        = 1070,
    ZMXProcEventIDMeeting_WillShowAttitudeFeedback = 1071,
    ZMXProcEventIDMeeting_ConfNotifyPTSendFeedback = 1072,

    // ZMMeetingProtocol relay. Each ID maps 1:1 to a ZMMeetingProtocol
    // method that used to be posted via ZMEventPosterFor(ZMMeetingProtocol)
    // in a single process; dispatchLocally: now re-emits that protocol post
    // on the receiving side so multi-process listeners stay in sync.
    //
    // PT -> UI subprocess (publish via +postFromPT:).
    ZMXProcEventIDMeeting_CallStatusChange                    = 1080,
    ZMXProcEventIDMeeting_DidLeaveMeeting                     = 1081,
    // UI subprocess -> PT (publish via +postToPT:). userInfo carries the
    // raw CONF_CMD / CmmUInt32 pair under kZMXProcEventKeyConfStatusCmd /
    // kZMXProcEventKeyConfStatusParams.
    ZMXProcEventIDMeeting_ConfStatusChanged                   = 1082,
    ZMXProcEventIDMeeting_BringWindowToFrontByDockIfInMeeting = 1085,

    // ZMMeetingStatusProtocol relay. UI subprocess -> PT (publish via
    // +postToPT:). Payload keys mirror the original method arguments.
    ZMXProcEventIDMeetingStatus_CurrentSessionChanged         = 1090,
    ZMXProcEventIDMeetingStatus_WillLeave                     = 1091,
    ZMXProcEventIDMeetingStatus_SilentModeChanged             = 1092,
    ZMXProcEventIDMeetingStatus_AICStatusChanged              = 1093,

    ZMXProcEventIDMeeting_PairCodeStatusChanged               = 1100,
};

#pragma mark - Transport constants

// PT-side and UI-subprocess-side receivers coexist in the same process image
// in single-process Meeting builds (zPTUI + zVideoUI both loaded in the main
// process), so each direction owns a distinct featurePath to avoid a
// ZMURLInvocationCenter registration collision and to keep routing unambiguous.
FOUNDATION_EXPORT NSString * const kZMXProcEventActionPost;           // @"post"
FOUNDATION_EXPORT NSString * const kZMXProcEventFeaturePathToPT;      // @"xproc-event-to-pt"
FOUNDATION_EXPORT NSString * const kZMXProcEventFeaturePathFromPT;    // @"xproc-event-from-pt"
FOUNDATION_EXPORT NSString * const kZMXProcEventPathToPT;             // @"xproc-event-to-pt/post"
FOUNDATION_EXPORT NSString * const kZMXProcEventPathFromPT;           // @"xproc-event-from-pt/post"

#pragma mark - Payload keys

FOUNDATION_EXPORT NSString * const kZMXProcEventKeyID;         // @"id"        — NSNumber(ZMXProcEventID), required
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyUserInfo;   // @"userInfo"  — optional NSDictionary
// PID of the process that ran +[ZMXProcEventPoster publishOn:...]. Set by
// the poster on every cross-process publish; consumed by the receive
// managers (ZMMTXProcEventMgr / ZMPTXProcEventMgr / future Clips-side mgr)
// to suppress IPC self-echo when a publisher's process also subscribes to
// the bus (e.g. 1P-Meeting + Clips topology: PT publishes on fromPTBus
// and is itself subscribed to it; without this guard, PT would re-run
// +dispatchLocally:userInfo: on top of the in-process dispatch already
// performed by +postFromPT: / +postToPT:, causing a double-fire).
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyOriginPid;  // @"originPid" — NSNumber(pid_t), set by poster

#pragma mark - Common userInfo keys

FOUNDATION_EXPORT NSString * const kZMXProcEventKeyResult;     // @"result"    — generic integer result
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyMyNotesEnable;      // @"isEnableVoiceNotes" — MyNotes relay enable flag
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyMyNotesRunning; // @"isVNConfRunning"    — MyNotes relay VN conf running flag
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyCloseSettingSource; // @"closeSettingSource" — source tag posted as the notification object
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyCallStatus;         // @"callStatus"         — NSNumber(NSInteger), PT call-status code
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyConfStatusCmd;      // @"confStatusCmd"      — NSNumber(int), CONF_CMD value
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyConfStatusParams;   // @"confStatusParams"   — NSNumber(int), CONF_CMD params
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyLeaveReason;        // @"leaveReason"        — NSNumber(int), CMM_ENDMEETING_REASON
FOUNDATION_EXPORT NSString * const kZMXProcEventKeySilentMode;         // @"silentMode"         — NSNumber(BOOL)
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyAICEnable;          // @"aicEnable"          — NSNumber(BOOL)
FOUNDATION_EXPORT NSString * const kZMXProcEventKeyPairCodeStatus;     // @"pairCodeStatus"     — NSNumber(unsigned long), CONF_CMD ret

#pragma mark - Notification names (poster -> in-process observers)

// Posted by +[ZMXProcEventPoster dispatchLocally:userInfo:] for the download
// relay events. object is nil; userInfo is the opaque download payload the PT
// side published (keyed by ZMDownloadXProcRoute). Observed by
// ZMDownloadXProcChildAdapter in the child processes.
FOUNDATION_EXPORT NSString * const kZMXProcEventNotiDownloadProgress;  // @"ZMXProcEventNotiDownloadProgress"
FOUNDATION_EXPORT NSString * const kZMXProcEventNotiDownloadComplete;  // @"ZMXProcEventNotiDownloadComplete"
FOUNDATION_EXPORT NSString * const kZMXProcEventNotiDownloadStateChanged;

NS_ASSUME_NONNULL_END
