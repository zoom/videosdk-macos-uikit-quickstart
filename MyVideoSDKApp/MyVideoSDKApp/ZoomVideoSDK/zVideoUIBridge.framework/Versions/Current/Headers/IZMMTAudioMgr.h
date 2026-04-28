//
//  IZMMTAudioMgr.h
//  VideoUI
//
//  Created by Javenlee Li on 2022/10/28.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMConfSession;

/**
 * @router ZMMTShared
 */
@protocol IZMMTAudioMgr <ZMRoutableObject>

@property (nonatomic, assign) BOOL spatialAudioState;
@property (atomic, readonly) BOOL isUsingPushToTalk;
@property (atomic, readonly) BOOL hasUsedTempTalkFeature;

- (void)cleanUp;
- (void)onConfReady;

// for mute/unmute self
- (BOOL)onAudio;
- (BOOL)onMuteAudio;
- (BOOL)onUnmuteAudio;
- (BOOL)onUnmuteAudioFromUI;
- (void)onStartPushToTalk;
- (void)onCancelPushToTalk;

- (BOOL)canMuteAll;
- (BOOL)canUnmuteAll;
- (void)onMuteAllAudio;
- (BOOL)onUnmuteAllAudio;

// for mute/unmute others
- (void)onAudioUser:(ZMUser *)theUser;
- (void)onMuteUser:(ZMUser *)theUser;
- (void)onUnmuteUser:(ZMUser *)theUser;

- (BOOL)isJoinAudio;
- (BOOL)isJoinAudioByTelephone;
- (BOOL)isJoinAudioByVoip;
- (BOOL)isJoinAudioByCallIn;
- (BOOL)isJoinAudioByCallOut;
- (BOOL)isDialIn;
- (BOOL)isJoin3rdPartyTele;
- (BOOL)isHostMuteAll;
- (BOOL)isSelfMuted;
- (BOOL)isMicrophoneAuthorized;

- (void)onMuteOnEntry;

- (BOOL)isSupportVoip;

- (int)getAudioStatusForLocalRecording;
- (int)getAudioStatusForCloudRecording;

- (int)getCurrentSpeakerStatus:(NSString * _Nullable * _Nullable)speakerName;
- (int)getCurrentMicStatus:(NSString * _Nullable * _Nullable)micName;

- (BOOL)needDisableLeaveComputerAudio;
- (BOOL)needDisableSwitchPhoneAudio;
- (BOOL)isShowAudioLogMenuItem;
- (BOOL)isAudioLogEnabled;
- (void)toggleAudioLog;
- (void)onAudioLogStatusChangeCallback;
- (NSString * _Nullable)getCurrentMeetingAudioLogPath;

#pragma mark ZMSettingAudioShareMgr
- (BOOL)isAudioDeviceInstalled;
- (BOOL)needInstallAudioDeviceForShare;
- (BOOL)installAudioDevice;
- (BOOL)isCoreAudioRestart;

#pragma mark audio tip
- (BOOL)needShowJoinAudioTip;

- (BOOL)shouldShowOriginalSoundControl;
- (BOOL)doesMicAlwaysUseOriginalSoundWithDeviceId:(NSString *)inDeviceId;

- (void)closeHostAskUnmuteAlert;
- (BOOL)isCoreAudioRunning;
- (BOOL)isSupportAudioSharePlugin;

- (void)updateAudioErrorTipState;
- (BOOL)checkAudioDeviceError:(NSString * _Nullable * _Nullable)outString;

- (BOOL)unmuteAudioNeedConsent:(ZMUser *)theUser;

#pragma mark - UI
- (void)update;
- (void)updateAudioUI;

#pragma mark - Audio error tip
- (void)updateAudioErrorTip;
- (void)hideAudioErrorTip;
- (void)showAudioErrorTip;

- (void)showUnmuteSelfReminder;

#pragma mark - Cmd
- (void)checkPersonalizedVoiceState;

#pragma mark - Feature
- (void)addAudioFeature:(int)feature;
- (void)releaseAudioFeature:(int)feature;

#pragma mark - IZMMTAudioMgr (Legacy)
#ifdef __cplusplus
- (NSString *)getSystemDeviceName:(SSB_MC_DEVICE_TYPE)type;
#endif

- (void)checkSpeakerVolume;
- (void)cancelSpeakerVolumeCheck;
- (void)microphoneModeChange:(NSInteger)menuTag;

- (void)onMyAudioStatusChange:(int)action trigger:(ZMUser *)user confSession:(ZMConfSession *)session;

#pragma mark - SDK
@optional
- (void)updateAudioStateToSDK:(int)deviceType;
- (void)updateAudioStatusToSDK;

// SpatialAudio
@optional
@property (nonatomic, readonly) BOOL spatialAudioEnabled;
- (BOOL)shouldEnableSpatialAudio;
- (void)updateSpatialAudioEffect;

@end

NS_ASSUME_NONNULL_END
