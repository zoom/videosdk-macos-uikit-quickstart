//
//  IZPConfUIMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/15/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPConfUIMgr_h
#define IZPConfUIMgr_h

#import <zVideoUIBridge/IZMMTSharingViewController.h>

typedef NS_ENUM(NSUInteger, ZMMTLeaveMeetingAction) {
    ZMMTLeaveMeetingActionCancel,
    ZMMTLeaveMeetingActionLeave,
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMMTLeaveMeetingCompletion)(ZMMTLeaveMeetingAction action);

/**
 * @router ZMShared
 */
@protocol IZPConfUIMgr <ZMRoutableObject>
@property (nonatomic, readonly, assign) BOOL isConfReady;
@property (nonatomic, readonly, assign) BOOL isDualMode;
@property (nonatomic, readonly, assign) BOOL isMiniVideoMode;

- (void)startSendingShareForType:(NSInteger)type; //ZMSendingShareType

- (void)askConfLeaveWithConfirm:(BOOL)confirm completion:(ZMMTLeaveMeetingCompletion)completion;

// Toast management (facade to IZMMTToastMgr)
- (void)addToast:(ZMToast *)toast;
- (void)removeToast:(ZMToast *)toast;
- (nullable ZMToast *)fetchToastWithIdentifier:(NSString *)identifier;

- (__kindof NSWindow *)confWindow;

- (BOOL)isDualMode;

- (BOOL)isFloatingVideoVisible;
- (BOOL)floatingVideoNeedShowUserInfo;
- (BOOL)isInSilentMode;

@optional //ZPConfUIMgr(Window)
// MinimalView support
- (void)exitMinimalViewMode;
- (NSRect)getMainViewRectInScreen;

#ifdef BUILD_FOR_CLIENT_SDK
- (void)notifyConfUIEventToSDK:(int)type param1:(void*)param1 param2:(void*)param2;
- (nullable id<IZMMTSharingViewController>)newCustomSharePortControllerForSDK;
#endif

@end

NS_ASSUME_NONNULL_END

#endif /* IZPConfUIMgr_h */
