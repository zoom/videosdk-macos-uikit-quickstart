//
//  ZMMTCustomRecordingInfo.h
//  VideoUI
//
//  Created by Devl on 2023/3/29.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMUser;
@class ZMShareSource;
@class ZMMTVideoMask;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTCustomRecordingType) {
    ZMMTCustomRecording_Video,
    ZMMTCustomRecording_Share,
    ZMMTCustomRecording_Image,
};

@interface ZMMTCustomRecordingInfo : NSObject

@property (nonatomic, assign) ZMMTCustomRecordingType type;
@property (nonatomic, strong) ZMUser *zmUser;
@property (nonatomic, strong) ZMShareSource *zmShareSource;
@property (nonatomic, assign) uint8_t userType;
@property (nonatomic, assign) uint32_t index;
@property (nonatomic, assign) NSRect viewRect;
@property (nonatomic, assign) NSRect asRect;
@property (nonatomic, assign) NSRect asDesRect;
@property (nonatomic, strong) ZMMTVideoMask *videoMask;

+ (instancetype)recordingInfo;

@end

NS_ASSUME_NONNULL_END
