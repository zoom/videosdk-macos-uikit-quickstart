//
//  IZMMTWizardMgr.h
//  VideoUIBridge
//
//  Created by Javenlee.Li on 2025/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTWizardMgr <NSObject>

@property (nonatomic, readonly) BOOL isVisible;
@property (nonatomic, readonly) BOOL isInTesting;
@property (nonatomic, readonly) BOOL isTestingMic;
@property (nonatomic, readonly) BOOL isTestingSpeaker;

- (void)startWizard:(BOOL)isFromTestMeeting;
- (void)startAudioWizard;
- (void)stopWizard;

- (void)speakerPlayingFileEndCallback;
- (void)resetVolumLevel:(unsigned int)level;
- (void)resetMicLevel:(unsigned int)level;
- (void)micHasVoice:(int)hasVoice;

- (void)resetMic;
- (void)resetSpeakers;
- (void)changeSpeakerByDeviceID:(NSString *)inDeviceID deviceName:(NSString *)inDeviceName;
- (void)changeMicByDeviceID:(NSString *)inDeviceID deviceName:(NSString *)inDeviceName;
- (void)cameraChangedWithResult:(int)result;
- (void)onMyVideoStateDidChanged;

@end

NS_ASSUME_NONNULL_END
