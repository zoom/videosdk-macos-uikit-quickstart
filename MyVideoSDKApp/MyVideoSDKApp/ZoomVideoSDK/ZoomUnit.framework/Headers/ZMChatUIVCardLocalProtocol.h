//
//  ZMChatUIVCardLocalProtocol.h
//  ZoomUnit
//
//  ChatUI-free subset of ZMChatUIInterfaceProtocol's vCard methods that the Meeting
//  subprocess needs. Implemented in zChatComponent (ZMChatUIVCardLocalModule) and
//  registered via @routerable, so ZMShareChatUIVCardLocal resolves in BOTH the PT
//  and the Meeting process (the web vCard + these data utils are process-agnostic).
//
//  Declared in ZoomUnit because consumers span VideoUIBridge / VideoUIEx /
//  zChatComponent / ChatUI, which all link ZoomUnit (VideoUIBridge does not link
//  zChatBase). Meeting code previously reached these via
//  ZMSharedFor(ZMChatUIInterfaceProtocol), which is nil in the Meeting subprocess.
//

#import <AppKit/AppKit.h>
#import <ZoomUnit/ZMProfileConfig.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatUIVCardLocalProtocol <NSObject>

@optional

- (nullable NSViewController *)getNewVcardViewController:(NSString *)uid floatConfig:(ZMProfileConfig *)config;
- (nullable NSString *)getJIDWithUserId:(NSString *)userid;
- (BOOL)isUserInvalid:(NSString *)jid meetingGuest:(BOOL)meetingGuest;

@end

#ifndef ZMShareChatUIVCardLocal
#define ZMShareChatUIVCardLocal (id<ZMChatUIVCardLocalProtocol>)ZMSharedFor(ZMChatUIVCardLocalProtocol)
#endif

NS_ASSUME_NONNULL_END
