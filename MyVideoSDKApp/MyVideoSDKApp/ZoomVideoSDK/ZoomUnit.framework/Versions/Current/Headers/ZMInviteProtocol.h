//
//  ZMInviteProtocol.h
//  ChatUI
//
//  Created by AI Assistant on 2024/01/01.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMInviteType) {
    ZMInviteTypeInvalid = 0,
    ZMInviteTypeContact,
    ZMInviteTypeZoomRoom,
    ZMInviteTypeDeskPhones,
    ZMInviteTypeRoomSystem,
    ZMInviteTypeEmail,
    ZMInviteTypeCallOut,
    ZMInviteTypeZoomPhone,
};

typedef NS_ENUM(NSUInteger, ZMRoomSystemSegmentType) {
    ZMRoomSystemSegmentTypeNone = 0,
    ZMRoomSystemSegmentTypeDialIn,
    ZMRoomSystemSegmentTypeCallOut,
};

@protocol ZMInviteProtocol <NSObject>

/// Initialize module and register event listeners
- (void)initModule;

/// Show the meeting invite window.
/// @param windowLevel Optional window level
- (void)showInviteWindowWithWindowLevel:(nullable NSNumber *)windowLevel;

/// Show the invite window for a Breakout Room.
/// @param boRoomID The target Breakout Room ID, must be within (0, UINT16_MAX]
/// @param roomName The target Breakout Room name
/// @param windowLevel Optional window level
- (void)showInviteWindowForBORoomID:(NSUInteger)boRoomID
                           roomName:(NSString *)roomName
                        windowLevel:(nullable NSNumber *)windowLevel;

/// Hide the meeting invite window.
- (void)hideInviteWindow;

/// Update the meeting invite UI.
- (void)updateUI;

// MARK: - Configuration
/// Update invite priority list.
/// @param priorityList Array of contact/room IDs
/// @param inviteType The invite type
- (void)updateInvitePriorityList:(nullable NSArray<NSString *> *)priorityList 
                   forInviteType:(ZMInviteType)inviteType;

/// Invite by SMS callback (automatically determines scene type)
/// @param meetingNO Meeting number
/// @param requestID Request ID (optional)
/// @param messageID Message ID (optional)
/// @param result Result code
- (void)inviteBySMSCallBackWithMeetingNo:(NSUInteger)meetingNO 
                               requestID:(nullable NSString *)requestID 
                               messageID:(nullable NSString *)messageID 
                                  result:(NSUInteger)result;

/// Used by Client SDK
- (void)selectRoomSystemSegmentType:(ZMRoomSystemSegmentType)segmentType andHideSegmentedControl:(BOOL)hidden;

/// Used by Client SDK
- (nullable NSWindow *)inviteMgrWindow;
@end

NS_ASSUME_NONNULL_END
