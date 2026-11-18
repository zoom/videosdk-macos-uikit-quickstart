//
//  IZMMTWhiteboardMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/28.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ZMCannotWBShareReason)
{
    ZM_CANNOT_WB_SHARE_REASON_NONE,
    ZM_CANNOT_WB_SHARE_REASON_DISABLED,
    ZM_CANNOT_WB_SHARE_REASON_HOST_DISABLED,
    ZM_CANNOT_WB_SHARE_REASON_HOST_ONLY,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_WB_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_CANNOT_CREATE,
    ZM_CANNOT_WB_SHARE_REASON_HAVE_SHARE_FROM_MAINSESSION,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_SHARE_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_ZDOC_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_PROCTORING_MODE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_WB,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_MY_SHARE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_OTHER_SHARE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_MY_ZDOC,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_OTHER_ZDOC,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_CLIPS_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_MY_CLIPS,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_OTHER_CLIPS,
};

NS_ASSUME_NONNULL_BEGIN

@class ZMMTWhiteboardDashboard;
@class ZMMTWhiteboardViewController;
@class ZMMTWBCanvasWebView;
@class ZMMenuItem;

/**
 * @router ZMMTShared
 */
@protocol IZMMTWhiteboardMgr <ZMRoutableObject>

@property (nonatomic, readonly) ZMMTWhiteboardDashboard *dashboard;
@property (nonatomic, readonly) ZMMTWBCanvasWebView *canvasWebView;

@property (nonatomic, readonly, assign) BOOL useCef;

- (void)createCanvasWebView;

- (ZMMTWhiteboardViewController*)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isPresentingWhiteboard;
- (BOOL)isViewingWhiteboard;
- (BOOL)isInWhiteboardMode;

- (BOOL)isReceivingWhiteboard;
- (BOOL)isAnyoneInWhiteboardMode;
- (BOOL)isWhiteboardSettingLocked;
- (BOOL)isSpotlighted;
- (int)viewRole;

- (NSUInteger)viewableWhiteboardCount;
- (NSString *)viewableWhiteboardId;
- (ZMUser *)viewableWhiteboardUser;

- (BOOL)isAllowShareWhiteboard;
- (void)setAllowShareWhiteboard:(BOOL)allowed;

- (void)showWhiteboardSetting;
- (void)showDashboard;
- (void)closeDashboard;

//ZOOM-1264296 Icebreakers — remote-flag gated whiteboard-activity entry; main thread; no-op if API unavailable.
- (BOOL)isWhiteboardActivityModeEnabled;
- (BOOL)isCurrentWhiteboardActivityMode;
- (void)openNewActivityWB;

- (void)stopShareWhiteboard;
- (void)stopAllWhiteboards;
- (BOOL)canStartWB:(ZMCannotWBShareReason *)reason
          isCreate:(BOOL)isCreate;
- (void)closeAllPanels;

- (void)closeBack2ClassicWBToast;
//Sink
- (void)onShareRoleChanged:(NSString*)docId role:(int)role;
- (void)onWebWBEvent:(int)event docId:(NSString*)docId userID:(ZMUserID)userID;

//Called when a user clicked the "meeting now" from outside whiteboard
- (void)onTrySharePTWhiteboard;

//Called when docs hub requests a whiteboard share permission check.
- (BOOL)onRequestStartNewShare:(NSString *)requestID isNew:(BOOL)isNew;

//Some switches
- (BOOL)shouldShowButtonOnToolBar;
- (BOOL)initiatingAllowed;
- (BOOL)canShareExistedWhiteboard;
- (BOOL)shouldShowWebWhiteboardPortalInShareWindow;
- (void)initiateAWhiteboard;
- (BOOL)isClassicWBFeatureOpen;

- (nullable ZMShareSource *)universalShareSource;
- (BOOL)canShareBeSpotlighted;
- (BOOL)spotlightThisShare;
- (BOOL)stopSpotlightThisShare;

//Collaborative Notes
- (BOOL)isCollaborativeNotesEnabled;
- (void)shareCollaborativeNotesWhiteboard;

//Visualization
- (void)visualizationEnabled:(BOOL*)pEnabled//If true, the menu item is shown
                   available:(BOOL*)pAvailable;//If false, the menu item is dimmed
- (void)registerVisualizationAvailableDidUpdateCallback:(nullable void(^)(void))visualizationAvailableDidUpdate;
- (void)shareVisualizationWhiteboard;//Action

@end

@protocol IZMMTWhiteboardStatusProtocol <NSObject>

- (void)onPermissionChanged;

@end

NS_ASSUME_NONNULL_END
