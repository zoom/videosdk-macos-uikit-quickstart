//
//  ZMCCLanguage.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 7/28/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef int ZMCCLanguageID;

@interface ZMCCLanguage : NSObject
@property (nonatomic, assign) ZMCCLanguageID ID;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *letterLangCode;
@property (nonatomic, assign, readonly) int logSubEvent;

- (instancetype)initWithLanguageID:(ZMCCLanguageID)languageID;
+ (instancetype)defaultTranslationLanguage;
+ (instancetype)offLanguage;
+ (instancetype)clientLanguage;

+ (nullable ZMCCLanguage *)currentMeetingSpeakingLanguage;
+ (BOOL)isMeetingSpeakingLanguagesAvailable;
+ (nullable NSArray<ZMCCLanguage *> *)availableMeetingSpeakingLanguages;
+ (nullable NSArray<ZMCCLanguage *> *)availableAICSpeakingLanguages;

+ (BOOL)hasTranslationLanguage;
+ (nullable ZMCCLanguage *)currentTranslationLanguage;
+ (nullable ZMCCLanguage *)preferredTranslationLanguage;
+ (BOOL)isTranslationLanguagesAvailable;
+ (nullable NSArray<ZMCCLanguage *> *)availableTranslationLanguages;
+ (nullable NSArray<ZMCCLanguage *> *)recentlyUsedTranslationLanguages;

+ (nullable ZMCCLanguage *)currentRSGWSpeakingLanguage;

+ (ZMCCLanguage *)currentKeyboardLanguage;
@end

NS_ASSUME_NONNULL_END
