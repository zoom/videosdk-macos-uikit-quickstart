//
//  IZMPostMeetingMgr.h
//  VideoUIBridge
//
//  Created by Davies Zhao on 2026/2/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMShared
 */
@protocol IZMPostMeetingMgr <ZMRoutableObject>

- (void)registerZUIPlatformDelegates;
- (void)unregisterZUIPlatformDelegates;
- (BOOL)checkAndShowUnLoginUserLeaveMeetingWindowForLeaveReason:(NSInteger)leaveReason;
- (void)finalizeZuiPostMeetingLoginOrQuitIfNeeded;
- (BOOL)isNeedShowPostMeetingLimitMarketingNoticeDialogWithGiftCount:(NSUInteger)giftCount;
- (void)showPostMeetingLimitMarketingNoticeDialog;
- (BOOL)canPromptClientUpdateAfterConferenceEnded;

@end

NS_ASSUME_NONNULL_END
