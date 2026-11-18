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

/// Re-broadcast doc events; thumbnail updates carry the affected doc ID.
@protocol ZMMTDocNotifyEventProtocol <NSObject>

@optional

/// Re-read via ZMDocHelper.allRecentFileItems / recentFileListEmptyStateStrings.
- (void)onRecentFileListUpdated;

/// Recent-file-list request errored out (alert is presented by the mgr). Listeners re-read
/// `ZMDocHelper.isRecentFileListInRequest` to exit any loading state they're showing.
- (void)onRecentFileListRequestFailed;

/// Re-read via ZMDocHelper.hasCreatePermissionForFileType:; distinct from onDocPermissionChanged.
- (void)onZoomDocsPermissionSettingUpdated;

/// Search results updated (kSearchFileListUpdate). Re-read via ZMDocHelper.searchFileItems.
- (void)onSearchFileListUpdated;

/// Search request failed (kApiRequestError / kSearchFileList); result is empty → no-result state.
- (void)onSearchFileListRequestFailed;

/// Thumbnail request/download state changed for the supplied doc; re-read its local path via ZMDocHelper.
- (void)onFileThumbnailUpdated:(NSString *)docId;

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
- (void)showDashboardIfNeededWithFromShare:(BOOL)fromShare Query:(nullable NSString *)query;
- (void)showDashboardIfNeededWithFromShare:(BOOL)fromShare ShowTemplates:(BOOL)showTemplates;
- (void)closeDashboard;

- (void)showSettingPanel;
- (void)closeSettingPanel;
- (void)closeAllPanels;

- (void)stopDocShareSource:(ZMShareSource *)shareSource;
- (void)stopDocShareById:(uint32_t)docId;
- (void)stopAllShareDocs;

- (ZMMTBaseViewController<IZMMTDocViewController> *)newViewControllerWithType:(ZMMTType)type;

- (void)showDocDeferShareAlert:(_Nullable dispatch_block_t)completionHandler;
- (void)showDocDeferShareAlert:(_Nullable dispatch_block_t)completionHandler
                   cancelAction:(_Nullable dispatch_block_t)cancelAction;
- (void)showDocBlockShareAlert;
- (void)showDocBlockGeneralAlert;
- (void)showDocBlockGeneralAlertWithCancelAction:(_Nullable dispatch_block_t)cancelAction;

- (BOOL)canControlDoc;
- (nullable NSString *)getWebviewIdWithViewType:(ZMMTType)viewType;

- (NSString *)getLatestDocPageId;

#ifdef BUILD_FOR_CLIENT_SDK
- (nullable NSWindow *)getCurrentSidePanelWindow;
- (nullable NSWindowController *)getCurrentDashboardWindowController;
#endif
@end

NS_ASSUME_NONNULL_END
