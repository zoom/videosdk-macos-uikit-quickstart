//
//  IZMMTAvatarViewMgr.h
//  VideoUIBridge
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTAvatarViewProtocol.h>

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTAvatarViewMgr <NSObject>

- (void)registerAvatarView:(NSView<ZMMTAvatarViewProtocol> *)view;
- (void)unregisterAvatarView:(NSView<ZMMTAvatarViewProtocol> *)view;

@end

NS_ASSUME_NONNULL_END
