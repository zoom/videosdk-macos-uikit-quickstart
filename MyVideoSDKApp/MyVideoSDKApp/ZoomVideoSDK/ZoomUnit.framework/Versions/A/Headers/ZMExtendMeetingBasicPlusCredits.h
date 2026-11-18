//
//  ZMExtendMeetingBasicPlusCredits.h
//  ZoomUnit
//
//  Created by davies zhao on 2023/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMExtendMeetingBasicPlusCredits : NSObject
@property (nonatomic, assign) NSInteger total;
@property (nonatomic, assign) NSInteger unused;
@property (nonatomic, copy,nullable) NSString *creditsEffectTime;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, copy,nullable) NSString *upgradeUrl;

#pragma mark - Cross-process serialization

/// Flatten into a JSON-safe NSDictionary for IPC transport
/// (e.g. ZMXProcEventPoster userInfo).
- (NSDictionary *)zm_toDictionary;

/// Rebuild a ZMExtendMeetingBasicPlusCredits from the dictionary
/// produced by -zm_toDictionary. Returns nil only if @c dict is nil.
+ (nullable instancetype)zm_fromDictionary:(nullable NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
