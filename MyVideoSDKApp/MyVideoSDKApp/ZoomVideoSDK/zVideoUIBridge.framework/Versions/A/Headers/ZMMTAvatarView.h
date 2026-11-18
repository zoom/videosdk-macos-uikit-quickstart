//
//  ZMMTAvatarView.h
//  VideoUIBridge
//

#import <zVideoUIBridge/ZMMTImageView.h>
#import <zVideoUIBridge/ZMMTAvatarViewProtocol.h>

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAvatarView : ZMMTImageView <ZMMTAvatarViewProtocol>

@property (nonatomic, strong, nullable) ZMUser *user;

- (void)refreshAvatar;

@end

NS_ASSUME_NONNULL_END
