//
//  IZMMTAudioMgr.h
//  VideoUI
//
//  Created by Javenlee Li on 2022/10/28.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTAudioMgr <ZMRoutableObject>
#ifdef __cplusplus
- (NSString *)getSystemDeviceName:(SSB_MC_DEVICE_TYPE)type;
#endif
- (BOOL)isJoinAudio;
- (BOOL)isJoinAudioByVoip;
- (BOOL)isSelfMuted;
- (void)onAudio;

- (void)checkSpeakerVolume;
- (void)cancelSpeakerVolumeCheck;
- (void)microphoneModeChange:(NSInteger)menuTag;

- (void)onMyAudioStatusChange:(int)action trigger:(ZMUser *)user confSession:(ZMConfSession *)session;

//SpatialAudio
@optional
@property(nonatomic, readonly) BOOL spatialAudioEnabled;
- (BOOL)shouldEnableSpatialAudio;
- (void)updateSpatialAudioEffect;
@end

NS_ASSUME_NONNULL_END
