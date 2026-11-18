//
//  ZMDocHelper.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2024/1/12.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMMTDocSharePickerRecentFileItem.h>

@class ZMShareSource;
@class ZMMTDocSharePickerEmptyStateStrings;

NS_ASSUME_NONNULL_BEGIN

@interface ZMDocHelper : ZMBaseHelper

- (BOOL)isDocEnable;
- (BOOL)isPresentingDoc;
- (BOOL)isViewingDoc;
- (BOOL)isInDocMode;

- (NSArray<ZMShareSource *> *)getViewableDocShareSources;
- (NSString *)getDashboardURL;

/// docId of the first doc I am currently sharing in this meeting; nil when I
/// am not the presenter of any doc. Read-through to GetMyCollaborationSources.
- (nullable NSString *)getMyInProgressShareDocId;

#ifdef __cplusplus
- (zm::docs::DocsPermission)getDocPermission;
- (zm::docs::ShareError)notifyDocsShareDialogResult:(BOOL)result withJSCallID:(NSString *)jsCallID;
#endif

- (void)enableDocShareStreamForRecording:(BOOL)bRecordDocShare;

- (BOOL)isSidePanelPopUpEnabled;
- (void)setIsSidePanelPopUpEnabled:(BOOL)enabled;

- (BOOL)isZoomDocsAllowedDomain:(nullable NSString *)url;

//MARK: - MeetingNotes
- (BOOL)isMeetingNotesEnabled;
- (NSString*)getMeetingNotesUrl;

- (BOOL)isMeetingNotesPopout;
- (void)notifyMeetingNotesPopCapability:(BOOL)enabled;
- (void)notifyMeetingNotesPopStatus:(BOOL)isPopout;

#pragma mark - ZoomDocs Recent file list & Permission (Share Picker Refresh)

/// ObjC surface over zm::docs::ICmmDocsRecentFileList / ICmmDocsPermissionSetting.
/// Re-read on kRecentFileListUpdate / kPermissionSettingUpdate; do NOT cache snapshots.

- (BOOL)isRecentFileListReady;
/// Use to skip duplicate updateRecentFileListForce: calls.
- (BOOL)isRecentFileListInRequest;
/// C++ side de-duplicates, but callers should still short-circuit via isRecentFileListInRequest.
- (void)updateRecentFileListForce:(BOOL)force;
/// Sets the number of recent items returned by the common recent-file interface.
- (void)setRecentFileListMaxCount:(NSInteger)maxCount;
/// Returns @[] when unavailable; never nil.
- (NSArray<ZMMTDocSharePickerRecentFileItem *> *)allRecentFileItems;
/// Returns [ZMMTDocSharePickerEmptyStateStrings empty] when unavailable; never nil.
- (ZMMTDocSharePickerEmptyStateStrings *)recentFileListEmptyStateStrings;

#pragma mark - ZoomDocs Search file list (Files Picker V2)

/// ObjC surface over zm::docs::ICmmDocsSearchFileList; UI owns debounce.

/// Update/start the search; query is limited to 256 characters, empty query cancels it, and results reuse the recent-file item shape.
- (void)updateSearchQuery:(NSString *)query;
/// Sets the number of search items returned by the common search-file interface.
- (void)setSearchFilesMaxCount:(NSInteger)maxCount;
/// YES while a search request is in flight — drives the loading state.
- (BOOL)isSearchFileListInRequest;
/// YES once the current query's result is in place; NO while requesting or after failure.
- (BOOL)isCurrentSearchResultReady;
/// Returns @[] when unavailable / not ready / failed; never nil. Reuses the recent-file item shape.
- (NSArray<ZMMTDocSharePickerRecentFileItem *> *)searchFileItems;

#pragma mark - ZoomDocs file thumbnails (Share Picker)

/// Returns the SDK-managed local thumbnail path when it is already available.
- (nullable NSString *)getFileThumbnailLocalPathForDocId:(NSString *)docId;
/// Starts an async thumbnail request; completion is delivered through the Docs sink event.
- (BOOL)requestFileThumbnailForDocId:(NSString *)docId;

- (BOOL)isPermissionSettingReady;
/// Use to skip duplicate updatePermissionSettingForce: calls.
- (BOOL)isPermissionSettingInRequest;
- (void)updatePermissionSettingForce:(BOOL)force;
/// NO when the API is unavailable, the setting is not ready, or the user lacks create rights.
- (BOOL)hasCreatePermissionForFileType:(ZMMTDocFileType)fileType;
/// NO when the API is unavailable, the setting is not ready, or the user lacks share rights.
- (BOOL)hasSharePermissionForFileType:(ZMMTDocFileType)fileType;

/// Server-side admin flag gating the refreshed Files-tab section.
- (BOOL)isClientFilesPickerEnabled;

/// Files Picker V2 flag: merges whiteboard into the docs file list and enables search.
- (BOOL)isClientFilesPickerV2Enabled;

#pragma mark - ZoomDocs Share entry-points (Share Picker Refresh)

/// Share an existing recent doc; NO when the docs API is unavailable or the backend rejects.
///   - access        : View / Comment / Edit (reuses ZMMTDocParticipantAccess)
///   - makePermanent : persists across meetings when YES
///   - presentMode   : only honoured for presentation docs
- (BOOL)startShareFromRecentDocId:(NSString *)docId
                          fileType:(ZMMTDocFileType)fileType
                            access:(ZMMTDocParticipantAccess)access
                     makePermanent:(BOOL)makePermanent
                       presentMode:(BOOL)presentMode;

/// Create a new doc of the given type and start sharing; NO when API unavailable / backend rejects.
- (BOOL)createAndStartShareWithFileType:(ZMMTDocFileType)fileType;

@end

NS_ASSUME_NONNULL_END
