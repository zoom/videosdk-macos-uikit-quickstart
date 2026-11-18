//
//  ZMMeetingStatusProtocol.h
//  ZoomUnit
//
//  Created by martin yu on 2025/4/8.
//

#ifndef ZMMeetingStatusProtocol_h
#define ZMMeetingStatusProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @poster ZMEventPoster
 */
@protocol ZMMeetingStatusProtocol <NSObject>
@optional
/// Waiting Room
/// - Parameter isInSilentMode: If isInSilentMode is YES, means user goes to the waiting room.
- (void)onMeetingSilentModeChanged:(BOOL)isInSilentMode;
/// Transition
/// If current session is transition session, user starts to join/switch/leave BO.
- (void)onMeetingCurrentSessionChanged;
/// Leave Meeting
/// - Parameter leaveReason: see CMM_ENDMEETING_REASON enum.
- (void)onMeetingWillLeave:(int)leaveReason;
/// Meeting AIC status change
/// - Parameter enable: AIC enable flag.
- (void)onMeetingAICStatusChange:(BOOL)enable;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMeetingStatusProtocol_h */
