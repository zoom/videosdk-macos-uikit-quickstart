//
//  IZMLipsyncMgr.h
//  VideoUIBridge
//
//  Created by vinson.wang on 2025/9/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMLipsyncMgr <ZMRoutableObject>

- (void)toggleAvatar;
- (void)toggleAvatarWithVideoState:(BOOL)isVideoOn;
- (BOOL)isInstalledAvatarPackage;
- (BOOL)isShowAvatar;
- (void)setAvatarStateWithVideoState:(BOOL)avatarState isVideoOn:(BOOL)isVideoOn;

@end

NS_ASSUME_NONNULL_END
