//
//  ZMUnifyWebViewConfProtocol.h
//  zUnifyWebViewApp
//
//  Created by Patrick Jia on 2026/8/3.
//
#import <Foundation/Foundation.h>

@class NSWindow;
@class NSView;

@protocol ZMUnifyWebViewConfProtocol <NSObject>

- (NSWindow *)getConfMainWindow;

// Screenshot host hooks used by the shared screenshot coordinator.
- (NSView *)captureScreenSender;
- (BOOL)isMeetingSession;
- (void)meetingChatStartScreenshot:(BOOL)needHideWindow;
- (void)meetingChatScreenshotCompleted:(BOOL)successed;

@end
