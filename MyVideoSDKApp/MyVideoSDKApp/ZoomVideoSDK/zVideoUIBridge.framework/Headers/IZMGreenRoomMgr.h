//
//  IZMGreenRoomMgr.h
//  zVideoUIBridge
//
//  Created for StudioUI modularization.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMGreenRoomMgr_h
#define IZMGreenRoomMgr_h

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMGreenRoomMgr <ZMRoutableObject>

/// Trigger the transition from backstage to main stage
- (void)onTranstion;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMGreenRoomMgr_h */

