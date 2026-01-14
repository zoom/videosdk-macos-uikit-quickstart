//
//  ZMMTVoiceTranslationHelper.h
//  VideoUIBridge
//
//  Created by martin yu on 2025/8/6.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTVoiceTranslationHelper : ZMBaseHelper
- (BOOL)isAIInterpretationReady;
- (BOOL)isMeetingAIInterpretationStarted;
- (BOOL)isMeetingAIInterpretationOnlyStartedByOthers;
- (BOOL)isAIInterpretationStarted;
- (BOOL)isAIInterpretationFirstFrameReceived;
- (BOOL)isAIInterpreterTranslatingStarted;
- (NSString*)getCurrentLanguage;
- (BOOL)setAIInterpretationSpeakingLanguage:(int)languageID;
- (int)getCurrentAISpeakingLanguageID;
@end

NS_ASSUME_NONNULL_END
