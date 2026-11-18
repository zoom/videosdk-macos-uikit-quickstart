//
//  IZMMTVoiceTranslationMgr.h
//  VideoUIBridge
//
//  Created by Karen Cao on 7/16/25.
//

#ifndef IZMMTVoiceTranslationMgr_h
#define IZMMTVoiceTranslationMgr_h

/**
 * @router ZMMTShared
 */
@protocol IZMMTVoiceTranslationMgr <ZMRoutableObject>
- (BOOL)isVoiceTranslatePanelShowing;
- (void)openVoiceTranslateSidepanel;
- (void)closeVoiceTranslateSidepanel;
- (void)popupWindowEnabled:(BOOL)enable;
- (BOOL)isPopupWindowEnabled;
- (BOOL)hasReceivedAIInterpretationFirstFrame;
@end

#endif /* IZMMTVoiceTranslationMgr_h */
