//
//  IZMMTStudioHelper.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2025/12/18.
//

#ifndef IZMMTStudioHelper_h
#define IZMMTStudioHelper_h

#import <Foundation/Foundation.h>

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for StudioHelper that defines the interface for VideoUI to call StudioUI functionality.
 * This protocol enables decoupling between VideoUI and StudioUI modules.
 * Only includes interfaces that are actually used in VideoUI/VideoUIBridge modules.
 */
@protocol IZMMTStudioHelper <NSObject>

#pragma mark - Producer Status

- (BOOL)isCurrentProducerPublishing;
- (nullable ZMUser *)getCurrentProducer;
- (BOOL)isProducerParent:(ZMUser *)user;
- (BOOL)isProductionStudioEnabled;
- (BOOL)forceSubscribeProducer;
- (BOOL)isEnablePSLMode;

#pragma mark - Live Status

- (BOOL)isUserPSLived:(ZMUser*)zmUser;
- (ZMUserID)getCurrentVideoSceneUserID;
- (BOOL)isSendingLive;

#pragma mark - First Time Use

- (BOOL)isFirstTimeStudioOnBoarding;

#pragma mark - Device & Quality

- (BOOL)isDeviceSupportOpenPSL;
- (BOOL)canStartPrivateShare;

#pragma mark - Cloud Mix

- (BOOL)isCloudMixEnabled;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTStudioHelper_h */
