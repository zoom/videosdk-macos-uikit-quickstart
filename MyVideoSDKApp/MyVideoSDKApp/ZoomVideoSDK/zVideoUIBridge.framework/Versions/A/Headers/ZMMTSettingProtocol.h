//
//  ZMMTSettingProtocol.h
//  VideoUI
//
//  Created by martin.yu on 8/17/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#ifndef ZMMTSettingProtocol_h
#define ZMMTSettingProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMMTSettingProtocol <ZMRoutableObject>
@optional

- (BOOL)isImmersiveDisableVB;
- (BOOL)shouldDisableMirror;

- (void)onReactionAwareness:(BOOL)isEnable;

- (void)onVideoPreviewStatusChanged;

- (void)onVideoMaxParticipantsStatusChanged;
- (void)lipsyncStatusNeedChange;

- (void)onLottieStatusChanged:(BOOL)isEnable;

- (void)onCaptionColorChanged:(NSColor *)color;
- (void)onTranslationColorChanged:(NSColor *)color;
- (void)onBackgroundColorChanged:(NSColor *)color;

- (void)openSettingWithSettingsOption:(NSInteger)setting;
- (void)openSettingWithType:(int)type;
- (void)openSettingWithType:(int)type context:(id)context;
- (void)closePTSetting;
- (void)closePTSettingWithContext:(id)context;

- (void)ptWindowStatusChange:(BOOL)status;

- (BOOL)isVideoCutout;
- (BOOL)isVideoEnableAlphaMask;
@end

#endif /* ZMMTSettingProtocol_h */
