//
//  IZMMTAudioCompanionMgr.h
//  VideoUIBridge
//
//  Migrated from VideoUI for protocol support.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTAudioCompanionMgr_h
#define IZMMTAudioCompanionMgr_h

@class ZMMTAudioCompanionModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTAudioCompanionDeviceType) {
    ZMMTAudioCompanionDeviceType_Mic,
    ZMMTAudioCompanionDeviceType_Speaker,
};

typedef NS_ENUM(NSUInteger, ZMMTAudioCompanionDisableReason) {
    ZMMTAudioCompanionDisableReason_ZRMuted,            // microphone
    ZMMTAudioCompanionDisableReason_NoDeviceError,      // microphone or speaker
    ZMMTAudioCompanionDisableReason_NetworkIssue,       // microphone or speaker
    ZMMTAudioCompanionDisableReason_NotSameMeeting,     // microphone or speaker
    ZMMTAudioCompanionDisableReason_None,
};

typedef NS_ENUM(NSUInteger, ZMMTAudioCompanionErrorType) {
    ZMMTAudioCompanionErrorType_ExceedMaxNum,           // microphone
    ZMMTAudioCompanionErrorType_DeviceDisconnect,       // microphone or speaker
    ZMMTAudioCompanionErrorType_DeviceIssue,            // microphone or speaker
    ZMMTAudioCompanionErrorType_Generic,                // microphone or speaker
    ZMMTAudioCompanionErrorType_ZRMuted,                // microphone
    ZMMTAudioCompanionErrorType_None,
};

/**
 * @router ZMMTShared
 */
@protocol IZMMTAudioCompanionMgr <ZMRoutableObject>

- (BOOL)inAudioCompanion;

// Microphone
- (BOOL)isMicAvailable;
- (BOOL)isMicMuted:(nullable ZMMTAudioCompanionDisableReason *)reason;
- (void)setMicMuted:(BOOL)muted;
- (void)setMicMuted:(BOOL)muted manual:(BOOL)manual;
- (NSUInteger)getMicLevel;
- (nullable ZMMTAudioCompanionModel *)getSelectedMic;

// Speaker
- (BOOL)isSpeakerAvailable;
- (BOOL)isSpeakerOff:(nullable ZMMTAudioCompanionDisableReason *)reason;
- (void)turnSpeakerOn:(BOOL)enabled;
- (nullable NSArray<ZMMTAudioCompanionModel *> *)getSpeakerList;
- (void)selectSpeakerDevice:(NSString *)identifier;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMMTAudioCompanionProtocol<NSObject>
@optional
- (void)onAudioCompanionReadyChanged;
- (void)onAudioCompanionAbilityChanged:(ZMMTAudioCompanionDeviceType)deviceType;
- (void)onAudioCompanionStateChanged:(ZMMTAudioCompanionDeviceType)deviceType;
- (void)onAudioErrorOccurred:(ZMMTAudioCompanionDeviceType)deviceType
                       error:(ZMMTAudioCompanionErrorType)error
                      device:(ZMMTAudioCompanionModel *)device;
- (void)onAudioCompanionSpeakerListChanged;
- (void)onAudioCOmpanionPoorMicQualityDetected;
@end

NS_ASSUME_NONNULL_END
#endif /* IZMMTAudioCompanionMgr_h */
