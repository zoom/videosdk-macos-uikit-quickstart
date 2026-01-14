//
//  ZPCMDWindowProtocol.h
//  ChatUI
//
//  Created for Created by davies zhao on 11/24/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZPCMDWindowModel;
@protocol ZPInvitationItemProtocol;
NS_ASSUME_NONNULL_BEGIN

/// CMD Window Controller common interface protocol
/// Ensures ZPCMDWindowController and ZPCMDHuddleWindowController have consistent interfaces
@protocol ZPCMDWindowBaseProtocol <NSObject>

#pragma mark - Properties
@required
@property (nullable, strong, readonly) NSWindow *window;
@property (nonatomic, strong, nullable) ZPCMDWindowModel *model;
@property (nonatomic, weak, readwrite) id<IZPCMDWindowManager> manager;
@property (nonatomic, strong) NSMutableArray *inviterIds;

#pragma mark - Lifecycle
@required
- (void)configWithCMDWindowModel:(ZPCMDWindowModel *)model
                               manager:(id<IZPCMDWindowManager>)theManager;
- (void)cleanUp;
- (void)cleanUpWithRemoveFromMgr:(BOOL)isRemoved;

#pragma mark - UI
@required
- (void)updateUI;
- (void)updateUIAvoidFocus:(BOOL)bAvoidFocus;
- (void)updateAccessibilityInfo;

#pragma mark - Window Actions
@required
- (void)actionCloseWindow;
- (void)actionCloseWindowWithMissedCall:(BOOL)isMissedCall;
- (void)closeAndRemoveWindow;
- (BOOL)windowShouldClose:(id)sender;

#pragma mark - Business Logic
@required
- (void)accept:(id)sender;
- (void)cancel:(id)sender;
- (void)cmdWindowAccept:(ZPCMDWindowModel *)theModel;
- (void)stopRinging;
- (void)onRingTimerEnded;

@end

@protocol ZPCMDWindowProtocol <ZPCMDWindowBaseProtocol>

@property (nonatomic, strong) NSMutableArray<id<ZPInvitationItemProtocol>> *invitationMeetingInfoArr;
- (void)windowDidBecomeKeyWindow;  // ZPCMDWindowController specific
- (void)windowDidResignKeyWindow;  // ZPCMDWindowController specific
- (void)onMeetingCallConflict; // ZPCMDWindowController specific

@end

@protocol ZPCMDHuddleWindowProtocol <ZPCMDWindowBaseProtocol>

@end

NS_ASSUME_NONNULL_END

