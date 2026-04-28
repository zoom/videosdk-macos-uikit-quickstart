//
//  IZMMTAudioUIMgr.h
//  AudioUI
//
//  Created by Javenlee.Li on 2025/3/6.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTAudioUIMgr <ZMRoutableObject>

@property (nonatomic, strong, readonly) NSWindow *infoWindow;
@property (nonatomic, assign) BOOL confirmCloseWithoutAudio;

- (void)onConfReady;
- (void)audioSessionReady;
- (void)onJoinVoip;
- (void)onLeaveVoip;

///coreAudio
- (void)checkCoreAudioProcess;
- (void)killCoreAudioProcess;
- (void)coreAudioDidRestart;
- (BOOL)isCoreAudioRestart;

///audioinfoWindow
- (void)showAudioInfoWindow;
- (void)showAudioInfoWindowWithAvaliablePhone;
- (void)autoShowAudioInfoWindow:(int)choose;
- (void)setAudioInfoWindowPosition:(NSPoint)position;
- (void)showThirdPartWithInfo:(NSString *)info;
- (BOOL)isAudioInfoWindowVisible;
- (BOOL)isAble2ShowAudioInfoWindow;
- (void)makeKeyAndOrderFront;
- (void)closeAudioInfoWindow;
- (void)updateAudioInfoWindow;

///CallStatus
- (void)callOutStatusChange:(int)status;
- (void)pbxCallStatusChange:(int)status;
- (void)sipCallStatusChange:(int)status;

///Device
- (void)onFeedbackErrorDetected;
- (void)checkAudioDeviceState;
- (BOOL)isNeedShowAudioErrAlertAndTip;

///microphone Mode
- (NSString *)microphoneMode;
- (void)livePerformanceStateChange:(int)params;

@end


NS_ASSUME_NONNULL_END
