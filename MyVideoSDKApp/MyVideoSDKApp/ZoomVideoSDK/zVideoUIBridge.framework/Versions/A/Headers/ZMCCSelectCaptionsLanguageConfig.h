//
//  ZMCCSelectCaptionsLanguageConfig.h
//  VideoUI
//
//  Created by martin yu on 8/2/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMCCLanguage.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMCCSelectLanguageView, ZMCCSelectLanguageRadioView;

@interface ZMCCSelectCaptionsLanguageConfig : NSObject
@property (nonatomic, assign) CGFloat minHeight;

@property (nonatomic, strong) NSString *title;

@property (nonatomic, assign) BOOL shouldNotShowSpeakingLanguageSection;
@property (nonatomic, strong, nullable) ZMCCLanguage *speakingLanguage;
@property (nonatomic, strong) NSString *speakingSectionTitle;
@property (nonatomic, strong) NSString *speakingSectionDesc;

@property (nonatomic, assign) BOOL shouldShowTranslationSection;
@property (nonatomic, assign) BOOL shouldNotShowTranslationDesc;
@property (nonatomic, strong, nullable) ZMCCLanguage *translationLanguage;
@property (nonatomic, assign) BOOL shouldShowEnableTranslationCheckBox;
@property (nonatomic, assign) BOOL translationEnabled;

@property (nonatomic, assign) BOOL shouldShowDoNotAskAgainCheckBox;
@property (nonatomic, assign) BOOL doNotAskAgain;

@property (nonatomic, assign) BOOL shouldShowFreeTrialIcon;
@property (nonatomic, assign) BOOL shouldShowFreeTrialTip;
@property (nonatomic, assign) BOOL shouldShowUpsellTip;

@property (nonatomic, strong, null_resettable) NSString *confimButtonTitle;

@property (nonatomic, copy) void(^enableTranslationBlock)(ZMCCSelectCaptionsLanguageConfig *aConfig);
@property (nonatomic, copy) void(^confimBlock)(ZMCCSelectCaptionsLanguageConfig *aConfig);
@property (nonatomic, copy) void(^cancelBlock)(ZMCCSelectCaptionsLanguageConfig *aConfig);

@property (nonatomic, assign) BOOL shouldMakeCheckBoxAsFirstResponder;

+ (instancetype)noTranslationConfigForChangeSpeakingLanguage;
+ (instancetype)translationConfigForChangeSpeakingLanguage;
+ (instancetype)translationLanguageConfigForShowCaptions;
+ (instancetype)translationLanguageConfigForStartTrial;
+ (instancetype)noTranslationLanguageConfigForStartTrial;
+ (instancetype)configForTranslationUpsell;

@property (nonatomic, weak) ZMCCSelectLanguageView *selectSpeakingLanguageView;
@property (nonatomic, weak) ZMCCSelectLanguageView *selectTranslationLanguageView;
@property (nonatomic, weak) NSView *freeTrialTipView;
@property (nonatomic, weak) NSView *upsellTipView;
@end

NS_ASSUME_NONNULL_END
