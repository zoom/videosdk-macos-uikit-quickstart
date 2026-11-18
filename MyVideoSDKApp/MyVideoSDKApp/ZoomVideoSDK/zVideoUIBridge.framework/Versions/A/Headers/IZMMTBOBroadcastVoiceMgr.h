//
//  IZMMTBOBroadcastVoiceMgr.h
//  VideoUIBridge
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMRoutableObject;

typedef NS_ENUM(NSInteger, ZMMTBOBroadcastVoiceStatus) {
    ZMMTBOBroadcastVoiceStatusStop = 0,
    ZMMTBOBroadcastVoiceStatusStart,
};

@protocol IZMMTBOBroadcastVoiceMgr <ZMRoutableObject>

- (BOOL)isBroadcastSpeaking;
- (BOOL)checkIsMyBroadcastSpeaking;
- (NSInteger)checkBroadcastVoiceStatus;
- (NSString *)broadcastVoiceNoticeString;

- (BOOL)haveBroadcastVoiceCapacity;

- (void)broadcastVoiceToBo:(BOOL)start;
- (void)onBOBroadcastVoice;

- (void)startBroadcastVoiceByShortcut;
- (void)stopBroadcastVoiceByShortcut;

- (void)onVoiceToBOStatusChanged:(BOOL)start;

- (void)broadcastVoiceIfNeeded;

@end

@protocol ZMMTBOBroadcastDelegate <NSObject>
@optional
- (BOOL)checkIsBroadcastViewShow;
- (BOOL)checkIsBroadcastVoiceTipViewShow;
- (BOOL)checkNeedResponseBOPanelBroadcast;
- (BOOL)checkIsBroadcastVoiceViewShown;
- (void)updateBroadcastVoiceViewWithType:(ZMMTBOBroadcastVoiceStatus)status;
- (void)closeBroadcastVoiceTipView;
- (void)closeBroadcastViewIfNeeded;
- (void)refreshBroadcastVoiceEnableView;
@end

NS_ASSUME_NONNULL_END
