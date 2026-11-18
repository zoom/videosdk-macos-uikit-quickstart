//
//  ZZHostHIDControlProtocol.h
//  ZoomUnit
//
//  Created by javenlee.li on 2022/5/7.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism.h>

typedef enum {
    ZZHostCallStateCalling      = 0,
    ZZHostCallStateInProgress   = 1,
    ZZHostCallStateDisconnected = 2,
    ZZHostCallStateHoldOn       = 3,
    ZZHostCallStateHoldOff      = 4,
    ZZHostCallStateHookOnFail   = 5,
    ZZHostCallStateFlas         = 6
} ZZHostCallState;

typedef enum {
    ZZHostVideoStateUnmute = 0,
    ZZHostVideoStateMute   = 1,
    ZZHostVideoStateBlock  = 2,
} ZZHostVideoState;

@protocol ZZHostHIDControlProtocol <ZMRoutableObject>

- (void)setDeviceMicMuted:(BOOL)isMute;
- (void)setDeviceVideoState:(ZZHostVideoState)state;
- (BOOL)isDeviceMicMuted;
- (BOOL)updateDefaultMicName:(nullable NSString*)micName;
- (BOOL)updateDefaultMicName:(NSString*)micName isBluetooth:(BOOL)bluetooth;
- (BOOL)isUsingExternalDevice;
- (void)syncMeetingAudioStatus2Device;
- (void)setDeviceCallState:(ZZHostCallState)stateData;
- (void)syncDeviceState;
- (void)registerSDKDevice:(NSString *)deviceName;
- (BOOL)isEnableHIDControl:(nullable BOOL*)isMandatory;
- (void)setEnableHIDControl:(BOOL)enable;
- (BOOL)isEnableAirpodsHIDControl:(nullable BOOL*)isMandatory;
- (void)setEnableAirpodsHIDControl:(BOOL)enable;
- (void)resetVideoHIDIfNeed;
- (void)updateDevice;
- (void)handleWebHIDConfigUpdate;
@end
