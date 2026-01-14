//
//  ZMZUISettingProtocol.h
//  ZoomSetting
//
//  Created by Javenlee Li on 2025/11/19.
//

#import <Foundation/Foundation.h>

@protocol ZMZUISettingProtocol <NSObject>

@optional
//pt setting
/**
 enum settingTabType {
   kTabGeneral,
   kTabVideo,
   kTabAudo,
   kTabNotification,
   kTabMeetings,
   kTabRecordings,
   kTabShareScreen,
   kTabPhone,
   kTabSipIntegration,
   kTabTeamChat,
   kTabAccessibility,
 };
 */
- (void)ptSettingItemViewWillAppear:(int)settingType;
- (void)ptSettingItemViewWillDisappear:(int)settingType;

//mt setting
/**
 enum MeetingSettingType {
     kMainSettingPage = 0,
     kVideoEffects,
     kAudio,
     kDisplayControl,
     kRecording,
     kShareScreen,
     kAccessibility,
     kSubPageDisplay,
     kSubPageControls,
     kSubPageMyVideo,
     kSubPageParticipantVideo,
     kSubPageReactions,
     kSubPageChat
 };
 */
- (void)mtSettingPageEnter:(int)meetingType;
- (void)mtSettingPageLeave:(int)meetingType;

@end

