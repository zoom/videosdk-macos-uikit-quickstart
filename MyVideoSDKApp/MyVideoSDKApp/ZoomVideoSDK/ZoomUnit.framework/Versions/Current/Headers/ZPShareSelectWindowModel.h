//
//  ZPShareSelectWindowModel.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>
#import <ZoomUnit/ZMCaptureModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZPShareSelectThirdPartyInfo: NSObject

@property (nonatomic, assign) ZMShareSelectItemType docType;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *docURL;
@property (nonatomic, copy) NSString *appName;

@end

@protocol ZPShareSelectWindowModelDelegate <NSObject>

@optional
- (NSArray<NSNumber *> *)filterOutWinIDsForDS;

@end

/**
 * Configuration for window list filtering
 */
@interface ZMMTShareSelectWindowFilterConfig : NSObject
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *excludeProcessIds; // Process IDs to exclude (local sharing)
@property (nonatomic, assign) BOOL includeZoomWindow;                            // Include Zoom windows
@property (nonatomic, assign) BOOL filterChromeIndicator;                        // Filter Chrome sharing indicator (only when actively sharing)
@property (nonatomic, assign) BOOL filterChromeZoomTitledWindow;                 // When sharing Chrome: filter Chrome windows titled exactly "zoom" (case-sensitive)
@property (nonatomic, assign) BOOL filterEdgeZoomTitledWindow;                   // When sharing Edge: filter Edge windows titled exactly "Zoom" (case-sensitive)
@end

@interface ZPShareSelectWindowModel : ZMCaptureModel

@property(assign)ZMShareSelectItemType sharingType;
@property(copy)NSString* toolTipString;
@property(copy)NSAttributedString* toolTipAttributedString;
@property(copy)NSString* disabledInfo;
@property(copy)NSString* documentPath;
@property(assign)NSUInteger winCount;
@property(copy)NSString* axTitle;
@property(copy)NSString* nativeToolTip;
@property (nonatomic, strong, nonnull) NSString *audioShareToolTip;
@property (nonatomic, strong, nonnull) NSString *videoShareToolTip;
@property(retain)NSArray<NSNumber *> *winIDsForPS;
@property(weak) id<ZPShareSelectWindowModelDelegate> delegate;
@property(retain, readonly)NSArray<NSNumber *> *filterOutWinIDsForDS;
@property(retain)NSDictionary<NSNumber *, NSString *> *moreMenus;
@property(assign)BOOL disabled;
@property(copy)NSString* appId;
@property(assign)BOOL canCollaborate;
@property(retain) ZPShareSelectThirdPartyInfo *docInfo;
@property(assign)BOOL hasBadge;
@property(assign)BOOL showWarningIcon;
@property(assign)ZMShareSelectItemBrowserTabType tabType;

+ (id)modelWithCaptureModel:(ZMCaptureModel*)model;
- (id)initWithCaptureModel:(ZMCaptureModel*)model;
- (BOOL)isValid;
- (BOOL)isDesktopModel;
- (BOOL)isAsOrPsModel:(BOOL)containZapp;
- (BOOL)isAsModel;
- (BOOL)isZoomAppsCollaborationModel; //add for collaborateMode
- (BOOL)isPsModel;
- (BOOL)isAudioModel;
- (BOOL)isVideoModel;
- (BOOL)isClipsModel;
- (BOOL)isDocModel;
- (BOOL)isWebWBModel;
- (BOOL)isFrameModel;
- (BOOL)isThirdPartyDoc;
- (BOOL)isZNotesModel;
- (BOOL)canEnableShareButton;
- (BOOL)supportAudioShare;
- (BOOL)supportVideoShare;
- (BOOL)supportBoShare;
- (BOOL)supportWatermark;
- (BOOL)supportHighFPS;
- (BOOL)supportZoomWindowConfig;
- (BOOL)supportZoomWindowSubOptions;
+ (NSArray<ZPShareSelectWindowModel*>*)getScreensModelList;
/**
 * Get windows model list excluding local share windows
 * @return Array of ZPShareSelectWindowModel objects, excluding Zoom windows by default
 */
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelList;

/**
 * Get windows model list with filter configuration (Recommended)
 * @param config Filter configuration object
 * @return Array of ZPShareSelectWindowModel objects
 */
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelListWithConfig:(nullable ZMMTShareSelectWindowFilterConfig *)config;

+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeList;

/**
 * Get process mode list with filter configuration (Recommended)
 * @param config Filter configuration object
 * @return Array of ZPShareSelectWindowModel objects
 */
+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeListWithConfig:(nullable ZMMTShareSelectWindowFilterConfig *)config;

+ (ZPShareSelectWindowModel*)getEmptyScreenModel;
+ (ZPShareSelectWindowModel*)getIOSDevideModel;
+ (ZPShareSelectWindowModel*)getIOSWiredDeviceModel;
+ (ZPShareSelectWindowModel*)getModelWithFileStorageModel:(NSString *)name imageName:(NSString *)imageName shareType:(ZMShareSelectItemType)shareType;
+ (ZPShareSelectWindowModel*)getClassicWhiteboardModel;
+ (ZPShareSelectWindowModel*)getWebWhiteboardModel;
+ (ZPShareSelectWindowModel*)getCameraModel;
+ (ZPShareSelectWindowModel*)getFrameModel;
+ (ZPShareSelectWindowModel*)getSoundModel;
+ (ZPShareSelectWindowModel*)getDocModel;
+ (ZPShareSelectWindowModel*)getVideoModel;
+ (ZPShareSelectWindowModel*)getChromeTabModel;
+ (ZPShareSelectWindowModel*)getEdgeTabModel;
+ (ZPShareSelectWindowModel*)getZoomNotesModel;
+ (ZPShareSelectWindowModel*)getZoomDocsModel;
+ (ZPShareSelectWindowModel*)getZoomHubModel;
+ (ZPShareSelectWindowModel*)getZoomClipsModel;
@end

@interface ZPAppShareSelectWindowModel : ZPShareSelectWindowModel

@property(retain)NSDictionary* zappShareParam;
@property(assign)BOOL isAppOpened;
@property(assign)BOOL isSidePanel;

@end

NS_ASSUME_NONNULL_END
