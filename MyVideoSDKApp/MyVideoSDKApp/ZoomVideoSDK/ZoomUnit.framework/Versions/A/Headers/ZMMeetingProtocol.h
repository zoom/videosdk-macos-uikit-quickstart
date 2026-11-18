//
//  ZMMeetingProtocol.h
//  ZoomUnit
//
//  Created by Davies Zhao on 2025/7/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMeetingProtocol <NSObject>
@optional

- (void)onCallStatusChange:(NSInteger)callStatus;
- (void)didLeaveMeeting;
- (BOOL)onConfStatusChanged:(int)cmd params:(int)ret;

- (void)bringWindowToFrontIfInMeeting;
- (void)bringWindowToFrontByDockIfInMeeting;
@end

NS_ASSUME_NONNULL_END
