//
//  ZMMeetingAssetsInfo.h
//  ZoomUnit
//
//  Created by davies zhao on 2024/8/29.
//

#import <Foundation/Foundation.h>
#import <commonDef/CmmCommonStruct.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMeetingAssetsInfo : NSObject
@property (nonatomic, assign) NSInteger dataAssets;
@property (nonatomic, copy) NSString *meetingChannelID;
@property (nonatomic, copy) NSString *cmcChannelID;
@property (nonatomic, assign) NSInteger meetingNum;
@property (nonatomic, assign) NSInteger occurrenceTime;
@property (nonatomic, copy) NSString *meetingMasterEventID;
@property (nonatomic, assign) BOOL amIHost;
@property (nonatomic, assign) NSInteger leaveReason;
@property (nonatomic, assign) BOOL isWebinar;
@property (nonatomic, assign) BOOL isBillableEnabled;
@property (nonatomic, assign) BOOL isBillableInfoUploaded;

@property (nonatomic, assign) MeetingAssetsInfo assetsInfo;
@property (nonatomic, assign) MeetingInviteesInfo inviteesInfo;
@property (nonatomic, copy) NSString *meetingTopic;

#pragma mark - Cross-process serialization

/// Flatten into a JSON-safe NSDictionary for IPC transport
/// (e.g. ZMXProcEventPoster userInfo). Embedded C++ structs are
/// expanded field-by-field; CString values become NSString and
/// std::vector<MeetingInviteeParams> becomes NSArray<NSDictionary *>.
- (NSDictionary *)zm_toDictionary;

/// Rebuild a ZMMeetingAssetsInfo from the dictionary produced by
/// -zm_toDictionary. Missing keys default to 0 / empty string.
/// Returns nil only if @c dict is nil.
+ (nullable instancetype)zm_fromDictionary:(nullable NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
