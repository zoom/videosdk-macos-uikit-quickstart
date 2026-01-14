//
//  ZMPTAlertMgr.h
//  zChatUI
//
//  Created by john on 2018/5/18.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZPAlert.h>
#import <ZoomUnit/IZMPTAlertMgr.h>
#import <ZoomUnit/ZoomUnit.h>

@class ZMPopupAlertViewController;
@class ZMRecaptchaWindowController;

@interface ZMPTAlertMgr : NSObject<ZPAlertDelegate, IZMPTAlertMgr>
{
    ZPAlert* _alert;
    ZMPopupAlertViewController*  _alertController;
    ZMAlertPanel* _alertPanel;
}

@property (nonatomic, weak) id<ZMAlertWindowDelegate> windowDelegate;

@property (nonatomic, strong) ZMAlertPanel *forceBreakPaidAccountHostStartFreeMeetingAlert;
@property (nonatomic, strong) ZMAlertPanel *forceBreakStartFreeMeetingAlert;
@property (nonatomic, strong) ZMAlertPanel *forceBreakPaidAccountAttendeeJoinMeetingAlert;
@property (nonatomic, strong) ZMAlertPanel *sendMessageToAdminAfterStartFailAlert;
@property (nonatomic, strong) ZMRecaptchaWindowController *recaptchaController;
@property (nonatomic, strong) ZMAlertPanel *transcodeAlert;
@property (nonatomic, strong) ZMAlertPanel *unconvertAlert;

+ (ZMPTAlertMgr*)sharedAlertMgr;
- (void)cleanUp;

@end
