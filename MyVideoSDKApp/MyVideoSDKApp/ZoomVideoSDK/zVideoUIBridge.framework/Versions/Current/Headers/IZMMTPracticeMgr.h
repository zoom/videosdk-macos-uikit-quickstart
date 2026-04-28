//
//  IZMMTPracticeMgr.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2026/3/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTPracticeMgr <ZMRoutableObject>

- (void)updateYouAreInAPracticeSessionTip:(BOOL)ignoreAlert;
- (void)onWebinarPracticeEnd;

@end

NS_ASSUME_NONNULL_END
