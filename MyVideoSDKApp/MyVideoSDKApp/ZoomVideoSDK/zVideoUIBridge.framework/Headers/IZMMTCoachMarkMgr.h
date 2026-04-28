//
//  IZMMTCoachMarkMgr.h
//  VideoUI
//
//  Created by Howie Xu on 12/12/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kCocahMarkAICRecap          @"kCocahMarkAICRecap"

/**
 * @router ZMMTShared
 */
@protocol IZMMTCoachMarkMgr <ZMRoutableObject>
- (BOOL)isCoachMarkAvailableWithIdentifier:(NSString *)identifier;
- (void)onCoachMarkShowingWithIdentifier:(NSString *)identifier;
- (void)markCoachMarkShownWithIdentifier:(NSString *)identifier;
- (NSInteger)getCoachMarkShownCountWithIdentifier:(NSString *)identifier;

- (void)registerCoachMark:(NSString *)kCoachMark
                 priority:(unsigned int)priority
               minVersion:(NSString *)minVersion
               maxVersion:(NSString *)maxVersion
                    count:(unsigned int)count
                    group:(NSString *)group;
- (void)unregisterCoachMark:(NSString *)kCoachMark;

- (void)registerAICRemindStartCoachMark;

- (void)registerAICRecordingCoachMark;

- (void)registerChatWithAICCoachMark;

- (void)registerLiveSummaryCoachMark;

- (void)registerIntroduceNotesAICCoachMark;

// Clips Share
- (void)registerClipsShareCoachMark;

#pragma mark - SignIn
- (void)registerTopBarSignInCoachMark;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMMTCoachMarkProtocol<NSObject>
@optional
- (void)registerCoachMarkIfNeeded;//Trigger in defaultSession did start
- (void)showCoachMarkIfNeeded;//Trigger in after defaultSession did start

- (void)didReceiveCoachMarkTimerWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
