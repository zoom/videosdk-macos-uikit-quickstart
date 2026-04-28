//
//  IZMMTFallbackMgr.h
//  VideoUIBridge
//
//  Created by Devl on 12/01/26.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMConfEventType) {
    ZMConfEvent_SendMessage,
};

@protocol IZMMTChatMessageModel;

/**
 * @router ZMMTShared
 */
@protocol IZMMTFallbackMgr <ZMRoutableObject>

//MARK: - Chat
- (void)updateChatStatus:(BOOL)status instType:(NSUInteger)instType;

- (void)sendInvitation:(id<IZMMTChatMessageModel>)message;
- (void)receiveInvitation:(id<IZMMTChatMessageModel>)message;

- (void)chatMessageReceived:(NSString*)json;
- (void)jumpZappByShareInfo:(ZMZAppConfShareInfo*)info;
- (void)getZappHeadById:(NSString*)appId completion:(void (^)(ZPZAppHeader *header, NSError *error))completion;

- (void)eventLogWithType:(ZMConfEventType)type;

@end

NS_ASSUME_NONNULL_END
