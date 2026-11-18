//
//  IZMMTSettingMgr.h
//  VideoUI
//
//  Created by martin.yu on 10/20/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTSettingMgr <NSObject>

@property (nonatomic, readonly) BOOL isSettingsShowing;
@property (nonatomic, readonly) BOOL isMainSettingsShowing;
@property (nonatomic, readonly) BOOL isCaptionsSettingsShowing;
@property (nonatomic, readonly) BOOL isSettingsPopout;
@property (nonatomic, readonly) BOOL isAudioSettingsShowing;

- (void)openSettings;
- (void)closeSettings; // needBackToMainPage=YES
- (void)closeSettings:(BOOL)needBackToMainPage;

- (void)openSettingsForMainPage;
- (void)openSettingsForAudio;
- (void)openSettingsForVideoEffects;
- (void)openSettingsForChat;
- (void)openSettingsForReactions;
- (void)openSettingsForCaptions;
- (void)openSettingsForLanguage;
- (void)openSettingsForLanguageAdvanced;
- (void)openSettingsForRecording;
- (void)openSettingsForShareScreen;

- (BOOL)canZoomDisplayFontSize;

@end

NS_ASSUME_NONNULL_END
