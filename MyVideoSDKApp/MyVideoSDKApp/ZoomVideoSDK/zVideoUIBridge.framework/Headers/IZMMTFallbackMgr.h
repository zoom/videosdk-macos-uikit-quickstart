//
//  IZMMTFallbackMgr.h
//  VideoUIBridge
//
//  Created by Devl on 12/01/26.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMConfEventType) {
    ZMConfEvent_SendMessage,
};

@protocol IZMMTChatMessageModel;
@class ZMMTAppTag;

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

//MARK: - App tag (RTMS list for video tile)
- (BOOL)hasRTMSAppTagsForOwner:(ZMUJID)ownerID;
- (nullable NSArray<ZMMTAppTag *> *)rtmsAppTagsForOwner:(ZMUJID)ownerID;

@end

NS_ASSUME_NONNULL_END
