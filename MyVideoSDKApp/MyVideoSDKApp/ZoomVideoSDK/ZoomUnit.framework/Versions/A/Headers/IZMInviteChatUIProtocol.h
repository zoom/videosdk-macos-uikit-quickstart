//
//  IZMInviteChatUIProtocol.h
//  ZoomUnit
//
//  Created by Michael Lin on 2025/9/9.
//

#ifndef IZMInviteChatUIProtocol_h
#define IZMInviteChatUIProtocol_h

@protocol IZMInviteChatUIProtocol <NSObject>

@optional
- (void)startChatWithSessionID:(nullable NSString *)sessionID;

// MARK: - ZoomPhone UI Methods
- (nullable NSView *)createPhoneCallDialViewWithFrame:(NSRect)frame;
- (nullable NSView *)createPhoneCallingViewWithFrame:(NSRect)frame;

// MARK: - User Validation Methods
- (BOOL)isUserInvalid:(nullable NSString *)jid meetingGuest:(BOOL)meetingGuest;

@end

#endif /* IZMInviteChatUIProtocol_h */
