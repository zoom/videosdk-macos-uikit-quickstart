//
//  ZMMultiConfEventDelegate.h
//  VideoUI
//
//  Created by Javenlee Li on 2023/3/14.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@protocol ZMMultiConfEventError <NSObject>
@property NSInteger confErrorCode;
@property NSInteger sdkErrorCode;
@end

@protocol ZMMultiConfEventDelegate <NSObject>
@optional

- (void)onSignDisclaimer:(CmmUInt16)roomID sponsorUniqueJoinIndex:(CmmUInt32)sponsorUniqueJoinIndex;
- (void)onSubConf:(CmmUInt16)roomID prepareMaterial:(zm::ConfMaterial&)material;
- (void)onSubConf:(CmmUInt16)roomID createSuccess:(BOOL)success;
- (void)onSubConfDestroying:(CmmUInt16)roomID;

- (void)onBeginJoinSub:(CmmUInt16)roomID reason:(zm::join_or_leave_reason)reason;
- (void)onEndedJoinSub:(CmmUInt16)roomID success:(BOOL)success error:(id<ZMMultiConfEventError>)error;

- (void)onBeginLeaveSub:(CmmUInt16)roomID reason:(zm::join_or_leave_reason)reason;
- (void)onEndedLeaveSub:(CmmUInt16)roomID success:(BOOL)success error:(id<ZMMultiConfEventError>)error;;

- (void)onBeginSwitchSub:(CmmUInt16)toRoomID fromSub:(CmmUInt16)fromRoomID reason:(zm::join_or_leave_reason)reason;
- (void)onEndedSwitchSub:(CmmUInt16)roomID success:(BOOL)success error:(id<ZMMultiConfEventError>)error;;

- (void)onConfSinkDispatcherCreatedWithType:(const CmmConfInstType&)confInstType roomID:(const CmmUInt16&)roomID;
@end

NS_ASSUME_NONNULL_END
