//
//  IZMMTCCEventProtocol.h
//  VideoUIBridge
//
//  Created by martin.yu on 12/27/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTCCEventProtocol_h
#define IZMMTCCEventProtocol_h

@class ZMConfSession;
@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @poster ZMMTEventPoster
 */
@protocol IZMMTCCEventProtocol <NSObject>
@optional
- (void)captionsStatusChanged:(BOOL)enabled session:(ZMConfSession *)session;
- (void)lockSpeakingLanguageStatusChanged:(BOOL)locked session:(ZMConfSession *)session;
- (void)manualCaptionStatusChanged:(BOOL)enabled session:(ZMConfSession *)session;
- (void)textTranslationDidStart:(ZMConfSession *)session;

- (void)onCaptionsBoxPreferredMaxWidthChanged;
- (void)showOriginalAndTranslatedStatusChanged;
- (void)onHideTranslationFeedbackEntrance;

- (void)onBackstageTranslationPromptConfirmed:(ZMConfSession *)session;

- (void)lidErrorStatusChanged:(BOOL)hasLIDError;

/// Posted from `ZMClosedCaptionMgr` when on-demand `launchModule` / `termModule` toggles readiness (`isReady`).
- (void)closedCaptionModuleReadyStateDidChange;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTCCEventProtocol_h */
