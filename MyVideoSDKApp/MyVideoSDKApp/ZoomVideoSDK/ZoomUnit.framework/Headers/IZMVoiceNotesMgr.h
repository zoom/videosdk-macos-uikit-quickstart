//
//  IZMVoiceNotesMgr.h
//  ZoomUnit
//
//  Created by Francis Zhuo on 2025/12/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMVNTrafficSource) {
    ZMVNTrafficSourceUnknown = 0,
    ZMVNTrafficSourceHomeTabMain = 1,
    ZMVNTrafficSourceHomeTabPlus = 2,
    ZMVNTrafficSourceDeepLink = 3,
    ZMVNTrafficSourceMeetingToolbar  = 4,
    ZMVNTrafficSourceAICPanel = 5,
    ZMVNTrafficSourceAICWorkspace = 6,
    ZMVNTrafficSourceDocsPage = 7,
    ZMVNTrafficSourceHubPage = 8,
    ZMVNTrafficSourceZoomToaster = 9,
    ZMVNTrafficSourceOtherToaster = 10,
    ZMVNTrafficSourceAutoStart = 11,
    ZMVNTrafficSourceMeetingTopbar = 12,
};

/**
 * @router ZMShared
 */
@protocol IZMVoiceNotesMgr <NSObject>
@optional
- (void)restartVoiceNotes:(BOOL)with3pMode;

- (void)notifyWebViewConnectingIfNeeded;
- (void)notifyNotesMeetingPropertyIfNeeded;
- (void)notifyNotesRestartVoiceNotes:(ZMVNTrafficSource)trafficSource with3pMode:(BOOL)with3pMode;
- (void)notifyWebViewTrafficSource;
- (void)notifyNotesViperExReady;
- (void)notifyNotesPTAskStopNotesIfNeeded;

- (void)showReportProblemWindow;
- (void)onVNProcessReady;

- (void)startVoiceNotes:(ZMVNTrafficSource)trafficSource;
- (void)startVoiceNotes:(ZMVNTrafficSource)trafficSource with3pMode:(BOOL)with3pMode;
// coach mark
- (void)registCoachMark;
- (void)unregistCoachMark;
- (BOOL)shouldShowF2fCoachMark;
- (void)markF2fCoachMarkShowing;
- (void)markF2fCoachMarkShown;

- (BOOL)isSupportVoiceNote;
- (BOOL)isEnableVoiceNotes;
// home
- (BOOL)isF2fNeedShowNewBadge;
// event receive
- (void)onCalendarAppReady;

// connecting
- (void)startConfCreate;
- (void)endConfCreate;
- (void)showErrorWithMessage:(NSString *)message errorCode:(int)errorCode;

- (BOOL)isVNConfCConnecting; //conf c
- (BOOL)isVNProcessStaring; //process is starting up
- (BOOL)isVNConfRunning; //on call
- (BOOL)isVNConfRunningWithID:(NSString *)meetingID;
- (void)startVoiceNotesWithID:(NSString *)meetingID passcode:(NSString *)passcode;
- (void)stopVoiceNotes;

- (void)bringWindowToFrontFromPT;
@end

/**
 * @poster ZMEventPoster
 */
@protocol ZMVoiceNotesProtocol
@optional
- (void)onVoiceNotesSettingChanged;
- (void)onVoiceNotesStatusChanged;
- (void)onVoiceNotesRunningStatusChanged;

- (void)onVoiceNotesDetectedMeetingAndStop;
@end

NS_ASSUME_NONNULL_END
