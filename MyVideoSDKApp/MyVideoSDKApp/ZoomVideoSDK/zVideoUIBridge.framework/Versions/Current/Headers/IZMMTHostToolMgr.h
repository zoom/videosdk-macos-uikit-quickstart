//
//  IZMMTHostToolMgr.h
//  VideoUI
//
//  Created by martin.yu
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTHostToolMgr <NSObject>

@property (nonatomic, readonly) BOOL isHostToolShowing;
@property (nonatomic, readonly) BOOL isHostToolPopout;

// YES: show in popup window, NO: show in side panel
@property (nonatomic, assign) BOOL enablePopup;

- (void)openHostTool;
- (void)closeHostTool; // needBackToMainPage= YES
- (void)closeHostTool:(BOOL)needBackToMainPage;

- (void)openHostToolForAdvanced;
- (void)openHostToolForParticipants;
- (void)openHostToolForShare;
- (void)openHostToolForZoomApp;
- (void)openHostToolForWhiteboard;
- (void)openHostToolForDoc;
- (void)openHostToolForBO;
- (void)openHostToolForCaptions;
- (void)openHostToolForAiCompanion;
- (void)openHostToolForMynotes;

@property (nonatomic, readonly) BOOL isAdvancedHostToolShowing;
@property (nonatomic, readonly) BOOL isParticipantHostToolShowing;
@property (nonatomic, readonly) BOOL isBOHostToolShowing;
@property (nonatomic, readonly) BOOL isShareHostToolShowing;
@property (nonatomic, readonly) BOOL isCaptionsHostToolShowing;
@property (nonatomic, readonly) BOOL isDocsHostToolShowing;
@property (nonatomic, readonly) BOOL isWhiteboardHostToolShowing;
@property (nonatomic, readonly) BOOL isAppsHostToolShowing;
@property (nonatomic, readonly) BOOL isAiCompanionHostToolShowing;
@property (nonatomic, readonly) BOOL isMynotesHostToolShowing;

@end

NS_ASSUME_NONNULL_END
