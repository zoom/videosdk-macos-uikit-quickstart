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
    ZMVNTrafficSourceAICPanel = 5,
    ZMVNTrafficSourceAICWorkspace = 6,
    ZMVNTrafficSourceDocsPage = 7,
    ZMVNTrafficSourceHubPage = 8,
    ZMVNTrafficSourceZoomToaster = 9,
    ZMVNTrafficSourceOtherToaster = 10,
    ZMVNTrafficSourceAutoStart = 11,
    ZMVNTrafficSourceMeetingTopbar = 12,
    ZMVNTrafficSourceRestart = 13,
    ZMVNTrafficSourceMynotesPage = 14,
    ZMVNTrafficSourceOpenNotesInMeeting = 15,
    ZMVNTrafficSourceOpenNotesInPhone = 16,
};

@class ZMMyNotesModel;
/**
 * @router ZMShared
 */
@protocol IZMVoiceNotesMgr <ZMRoutableObject>
@optional
- (void)restartWithModel:(ZMMyNotesModel*)model;

- (void)startWithModel:(ZMMyNotesModel*)model;
- (void)reservationVoiceNotesWithModel:(ZMMyNotesModel*)model;

- (BOOL)isSupportVoiceNote;
- (BOOL)isEnableVoiceNotes;
// home
- (BOOL)isF2fNeedShowNewBadge;
// event receive
- (void)onCalendarAppReady;

- (ZMMyNotesModel*)runningModel;
- (BOOL)isVNConfCConnecting; //conf c
- (BOOL)isVNProcessStaring; //process is starting up
- (BOOL)isVNConfRunning; //on call
- (void)stopVoiceNotes;

- (nullable NSString*)mynotesAnonymousUrl;

- (void)bringWindowToFrontFromPT;
@end

@class ZMMicrophoneUsageInfo;

/**
 * @poster ZMEventPoster
 */
@protocol ZMVoiceNotesProtocol
@optional
- (void)onVoiceNotesSettingChanged;
- (void)onVoiceNotesStatusChanged;
- (void)onVoiceNotesRunningStatusChanged;

- (void)onUseMicrophoneAppsChange:(ZMMicrophoneUsageInfo *)usageInfo;
@end

NS_ASSUME_NONNULL_END
