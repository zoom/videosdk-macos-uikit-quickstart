//
//  IZMMTTranscriptMgr.h
//  VideoUIBridge
//
//  Created by Karen Cao on 1/21/26.
//

#ifndef IZMMTTranscriptMgr_h
#define IZMMTTranscriptMgr_h

#ifdef __cplusplus
#include "zVideoApp/CmmLTTAPI.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTTranscriptMgr <NSObject>

@property (nonatomic, assign, readonly) BOOL isFontSizeChangable;

- (void)openNewTranscriptPanel;
- (void)closeNewTranscriptPanel;
- (void)popupWindowEnabled:(BOOL)enable;
- (BOOL)isPopupWindowEnabled;
- (void)onMeetingTranscriptStatusChanged:(ZMConfSession *)session;
- (void)handleNewTranscriptButtonClick;
- (BOOL)isNewTranscriptPanelShowing;
- (void)showSaveTranscriptDialog;
- (void)showPolishTranscriptStartedToast;
- (void)onPolishTranscriptCompleted:(BOOL)isSuccess filepath:(nullable NSString *)filepath;
- (void)showTranscriptSavedTip:(BOOL)isSuccess polishRequested:(BOOL)polishRequested filepath:(NSString *)filepath;
- (void)onEnableMeetingTranscriptionRspReceived:(ZMConfSession *)session userFrom:(nullable ZMUser *)userFrom agree:(BOOL)agree;
- (void)onStopTranscriptionRspReceived:(ZMConfSession *)session userFrom:(nullable ZMUser *)userFrom agree:(BOOL)agree;
- (void)onDisplayEntityUpdated:(NSString *)displayId operation:(NSInteger)operation session:(ZMConfSession *)session;
#ifdef __cplusplus
- (void)onDisplayEntitiesRestructured:(const LTTDisplayChangeInfo&)info session:(ZMConfSession *)session;
#endif
- (BOOL)previousTranscriptNeedShow;
- (void)setPreviousTranscriptNeedShow:(BOOL)value;
@end

NS_ASSUME_NONNULL_END


#endif /* IZMMTTranscriptMgr_h */
