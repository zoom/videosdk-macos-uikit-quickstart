//
//  ZMMicrophoneUsageInfo.h
//  AudioUI
//
//  Created by Cooper.Chen on 2025/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMicrophoneUsageAppType) {
    ZMMicrophoneUsageAppTypeAdd = 0,
    ZMMicrophoneUsageAppTypeRemove = 1
};

@interface ZMMicrophoneUsageInfo : NSObject
// Properties based on SSB_MC_MICROPHONE_USAGE_INFO structure
@property (nonatomic, strong) NSArray<NSString *> *appNames;           // app names
@property (nonatomic, strong) NSArray<NSString *> *appIdentifiers;     // bundle IDs
@property (nonatomic, strong) NSArray<NSString *> *allActiveApps;      // all active apps
@property (nonatomic, assign) NSInteger appsTotalNum;                  // all active apps num
@property (nonatomic, assign) NSInteger appsChangeNum;                 // new change apps num
@property (nonatomic, assign) ZMMicrophoneUsageAppType usageType;    // add or remove
@end

NS_ASSUME_NONNULL_END
