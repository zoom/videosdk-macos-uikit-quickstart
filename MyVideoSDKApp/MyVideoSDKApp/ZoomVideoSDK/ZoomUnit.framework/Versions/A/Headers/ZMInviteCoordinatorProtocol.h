//
//  ZMInviteCoordinatorProtocol.h
//  ChatUI
//
//  Created by AI Assistant on 2024/01/01.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMInviteSceneType) {
    ZMInviteSceneTypeMeeting = 0,
    ZMInviteSceneTypeHuddle,
};

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

@class ZMInviteMgr;
@protocol ZMInviteCoordinatorProtocol <NSObject>

/// Initialize module and register event listeners
- (void)initModule;

/// Show invite window for the specified scene
/// @param sceneType The scene type
/// @param windowLevel Optional window level
- (void)showInviteWindowForSceneType:(ZMInviteSceneType)sceneType windowLevel:(nullable NSNumber *)windowLevel;

/// Hide invite window (automatically determines scene type)
- (void)hideInviteWindow;

/// Hide invite window for the specified scene
/// @param sceneType The scene type
- (void)hideInviteWindowForSceneType:(ZMInviteSceneType)sceneType;

/// Update invite UI (automatically determines scene type)
- (void)updateUI;

// MARK: - Configuration
/// Update invite priority list (automatically determines scene type)
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
