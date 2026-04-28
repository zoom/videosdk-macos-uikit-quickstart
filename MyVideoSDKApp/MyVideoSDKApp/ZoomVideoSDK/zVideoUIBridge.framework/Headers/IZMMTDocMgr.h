//
//  IZMMTDocMgr.h
//  VideoUI
//
//  Created by Molay.Yu on 2023/11/30.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/zVideoUIBridge.h>

@class ZMMTBaseViewController, ZMConfSession, ZMUser;
@class ZMShareSource;
@protocol IZMFitDocMenuHelper;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTDocViewController <NSObject>

@property (nonatomic, weak) ZMConfSession* confSession;
@property (nonatomic, assign, readonly) BOOL canRecord;
@property (nonatomic, strong) id<IZMFitDocMenuHelper> menuHelper;
@property (nonatomic, strong) ZMShareSource *shareSource;

- (void)startVideo NS_UNAVAILABLE;
- (void)startVideoWithShareSource:(ZMShareSource *)shareSource;
- (void)stopVideo;

@end

@protocol ZMMTDocViewControllerEventProtocol <NSObject>

@optional
- (void)attachedWebViewDidChangeForDocViewController:(id<IZMMTDocViewController>)viewController;

@end

@protocol IZMMTDocMgr <ZMRoutableObject>

- (void)registerSink;
- (void)unRegisterSink;
- (BOOL)shouldShowDocEntry;

- (BOOL)isLockedByAdmin;
- (BOOL)isAllowShareDoc;
- (void)setAllowShareDoc:(BOOL)allowShare;

- (void)shareDocWithAttachment:(nullable id)attachment;
- (void)showDashboardIfNeededWithFromShare:(BOOL)fromShare;
- (void)closeDashboard;

- (void)showSettingPanel;
- (void)closeSettingPanel;
- (void)closeAllPanels;

- (void)stopDocShareSource:(ZMShareSource *)shareSource;
- (void)stopDocShareById:(uint32_t)docId;
- (void)stopAllShareDocs;

- (ZMMTBaseViewController<IZMMTDocViewController> *)newViewControllerWithType:(ZMMTType)type;

- (void)showDocDeferShareAlert:(_Nullable dispatch_block_t)completionHandler;
- (void)showDocBlockShareAlert;
- (void)showDocBlockGeneralAlert;

- (BOOL)canControlDoc;
- (nullable NSString *)getWebviewIdWithViewType:(ZMMTType)viewType;

- (NSString *)getLatestDocPageId;

#ifdef BUILD_FOR_CLIENT_SDK
- (nullable NSWindow *)getCurrentSidePanelWindow;
- (nullable NSWindowController *)getCurrentDashboardWindowController;
#endif
@end

NS_ASSUME_NONNULL_END
