//
//  ZMMTBOBroadcastVioceButton.h
//  VideoUI
//
//  Created by Howie Xu on 1/29/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/IZMMTBOBroadcastVoiceMgr.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTBOBroadcastVioceButton : ZMBackgroundView

@property (nonatomic, strong) ZMButton *voiceActionButton;

- (void)showUIWithBroadcastVoiceStatus:(ZMMTBOBroadcastVoiceStatus)broadcastVoiceStatus;

- (void)startTimer;

- (void)stopTimer;

@end

NS_ASSUME_NONNULL_END
