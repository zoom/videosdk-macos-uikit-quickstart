//
//  ZMMTAvatarViewProtocol.h
//  VideoUIBridge
//

#import <Foundation/Foundation.h>

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTAvatarViewProtocol <NSObject>

@property (nonatomic, strong, nullable) ZMUser *user;

- (void)refreshAvatar;

@end

NS_ASSUME_NONNULL_END
