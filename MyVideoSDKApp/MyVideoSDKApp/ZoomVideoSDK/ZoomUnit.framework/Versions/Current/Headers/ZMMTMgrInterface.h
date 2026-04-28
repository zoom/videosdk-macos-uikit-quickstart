//
//  ZMMTMgrInterface.h
//  ZoomUnit
//
//  Created by Francis Zhuo on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTMgrInterface <NSObject>

- (BOOL)isInMeeting;
- (BOOL)isInWebinar;
- (NSString*)meetingID;

@end

NS_ASSUME_NONNULL_END

