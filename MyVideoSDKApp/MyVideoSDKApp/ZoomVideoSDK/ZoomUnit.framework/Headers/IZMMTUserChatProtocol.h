//
//  IZMMTUserChatProtocol.h
//  VideoUI
//
//  Created by Michael.l on 12/26/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTUserChatProtocol_h
#define IZMMTUserChatProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTUserChatProtocol <ZMRoutableObject>

@optional
- (BOOL)userCanShowKeypadWithUserId:(int)userId;
- (void)sendInviteMMRMonitorLog:(NSString *)logStr;
- (NSRect)calcWindowInitialRect:(NSWindow*)myWindow;
- (nullable NSString *)getConfDCRegionForChat;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTVideoProtocol_h */
