//
//  ZMScreenshotCallback.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/11/24.
//

#ifndef ZMScreenshotCallback_h
#define ZMScreenshotCallback_h

@class ZMScreenShotItem;

@protocol ZMScreenshotCallback <NSObject>

@required
- (void)didCaptureScreenshot:(ZMScreenShotItem *)item;
- (NSView*)captureScreenSender;

@optional
- (void)willCaptureScreenshot;
- (BOOL)isMeetingSession;
- (void)meetingChatStartScreenshot:(BOOL)needHideWindow;
- (void)meetingChatScreenshotCompleted:(BOOL)successed;
- (void)captureFailed;
- (void)captureFailedTaskIsRunning;
- (void)captureFailedWithNoPermission;
- (void)captureDownload;
- (void)willCaptureRecord;
- (void)recordDidSucceed;
- (void)recordFailed;
@end

#endif /* ZMScreenshotCallback_h */
