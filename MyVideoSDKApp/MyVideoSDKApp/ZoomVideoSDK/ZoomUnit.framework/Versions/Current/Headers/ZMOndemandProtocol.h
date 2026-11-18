//
//  ZMOndemandProtocol.h
//  ZoomUnit
//
//  Created by Francis Zhuo on 7/7/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism.h>

#define ZoomTelemetryBundle @"ZoomTelemetry.bundle"
#define zTelemetryBizBundle @"zTelemetryBiz.bundle"
#define ZoomSettingExFramework @"ZoomSettingEx.framework"

NS_ASSUME_NONNULL_BEGIN
@class ZMDownloadObject;
@protocol ZMOndemandProductInfoProtocol;
typedef enum {
    ZMDownloadStageIdle = 0,
    ZMDownloadStageInitial,
    ZMDownloadStageRequestUrl,
    ZMDownloadStageDownloading,
    ZMDownloadStageUnzipping,
    ZMDownloadStageCopying,
    ZMDownloadStageFailed,
    ZMDownloadStageSuccess,
    ZMDownloadStageCancel,
} ZMDownloadStage;

typedef NS_ENUM(NSUInteger, ZMDownloadType) {
    ZMDownloadTypeDefault,
    ZMDownloadTypeCodeSnippet,
    ZMDownloadTypeSipCall,
    ZMDownloadTypeComponents,
    ZMDownloadTypeAomhost,
    ZMDownloadTypeAirhost,
    ZMDownloadTypeViperEX,
    ZMDownloadTypeMail,
    ZMDownloadTypeCalendar,
    ZMDownloadTypeCefAgent,
    ZMDownloadTypeSchedulerPlugin,
    ZMDownloadTypeCefFrameworkPlugin,
    ZMDownloadTypeCefWebViewPlugin,
    ZMDownloadTypeASRLibrary,
    ZMDownloadTypeASRModel,
    ZMDownloadTypeLocalization,
    ZMDownloadTypeZoomClips,
    ZMDownloadTypeZoomInterFont,
    ZMDownloadTypeZoomMeeting,
};

/// Resource type for check update callback routing
typedef NS_ENUM(NSUInteger, ZMCheckUpdateResourceType) {
    ZMCheckUpdateResourceTypeUnknown = 0,
    ZMCheckUpdateResourceTypePTUIExtPackage,
    ZMCheckUpdateResourceTypeCodeSnippet,
    ZMCheckUpdateResourceTypeMail,
    ZMCheckUpdateResourceTypeSipcall,
};

typedef NS_ENUM(NSUInteger, ZMDownloadResult) {
    ZMDownloadResultFailed,
    ZMDownloadResultSuccess,
    ZMDownloadResultCancel,
};

typedef NS_ENUM(NSUInteger, ZMDownloadResultReason) {
    ZMDownloadResultReasonNone,
    ZMDownloadResultReasonFetchUrlFail,
    ZMDownloadResultReasonNotNeedDownload,
};

@protocol ZMOndemandStatusProtocol <NSObject>

- (void)downloadFinishedWithType:(ZMDownloadType)type
                          result:(ZMDownloadResult)result
                          reason:(ZMDownloadResultReason)reason
                           error:(nullable NSError *)error;

@optional
/// Called when download state changes (started/stopped)
- (void)downloadStateChangedWithType:(ZMDownloadType)type isDownloading:(BOOL)isDownloading;

@end

typedef void (^ZMDownloadProgressBlock)(ZMDownloadStage stage, CGFloat process);
typedef void (^ZMDownloadCompletionBlock)(ZMDownloadResult result, NSError *_Nullable error);
typedef void (^ZMDownloadCompletionWithReasonBlock)(ZMDownloadResult result,
                                                     ZMDownloadResultReason reason,
                                                     NSError *_Nullable error);
typedef void (^ZMDownloadCancelCompletionBlock)(BOOL processed);

@protocol ZMOndemandProtocol <ZMRoutableObject>
@optional
- (void)downloadForType:(ZMDownloadType)type;
- (void)downloadForType:(ZMDownloadType)type withProductInfo:(id<ZMOndemandProductInfoProtocol>)info;
- (void)pauseDownloadingWithType:(ZMDownloadType)type;
- (void)fileDownloadedWithType:(ZMDownloadType)type requestID:(NSString *)requestID localFilePath:(NSString *)localFilePath result:(int)result;

- (void)setupChildProcessIfNeeded;

/// Available only in the main process.
- (BOOL)isInProgress;

///return token
- (nullable id)downloadForType:(ZMDownloadType)type
                      progress:(nullable ZMDownloadProgressBlock)progress
                    completion:(nullable ZMDownloadCompletionBlock)completion;

///return token
- (nullable id)downloadForType:(ZMDownloadType)type
                      progress:(nullable ZMDownloadProgressBlock)progress
          completionWithReason:(nullable ZMDownloadCompletionWithReasonBlock)completion;

- (void)updateProgress:(nullable ZMDownloadProgressBlock)progress
            completion:(nullable ZMDownloadCompletionBlock)completion
              withType:(ZMDownloadType)type
                 token:(id)token;

- (void)cancelDownloadForType:(ZMDownloadType)type;
- (void)cancelDownloadForType:(ZMDownloadType)type
                     withToken:(id)token
                    completion:(nullable ZMDownloadCancelCompletionBlock)completion;

/// @deprecated Use checkUpdateReturnForResourceType:latestVersion:downloadURL:releaseNote:requestId:result: instead
- (void)checkUpdateReturn:(NSString *)inLatestVersion
              downloadURL:(NSString *)inURLString
              releaseNote:(NSString *)inReleaseNote
                requestId:(NSString *)inRequestId
                   result:(NSInteger)inResult;

/// Check update callback with resource type for precise routing
/// @param resourceType The type of resource that triggered this callback
/// @param inLatestVersion Latest version string
/// @param inURLString Download URL
/// @param inReleaseNote Release notes
/// @param inRequestId Request ID for matching
/// @param inResult Result code
- (void)checkUpdateReturnForResourceType:(ZMCheckUpdateResourceType)resourceType
                           latestVersion:(NSString *)inLatestVersion
                             downloadURL:(NSString *)inURLString
                             releaseNote:(NSString *)inReleaseNote
                               requestId:(NSString *)inRequestId
                                  result:(NSInteger)inResult;
- (BOOL)isInstalledForType:(ZMDownloadType)type;
- (nullable NSString *)bundlePathForType:(ZMDownloadType)type;
- (void)isCodeSignValidForType:(ZMDownloadType)type completion:(void (^)(NSString *_Nullable path))completion;
- (void)isCodeSignValidForType:(ZMDownloadType)type files:(NSArray<NSString *> *)files completion:(void (^)(NSString *_Nullable path))completion;
//codesign for resource, eg. ASR model resource
- (void)isCodeSignValidForType:(ZMDownloadType)type productName:(NSString *_Nullable)productName completion:(void (^)(NSString *_Nullable path))completion;
- (void)isCodeSignValidForType:(ZMDownloadType)type productName:(NSString *_Nullable)productName files:(NSArray<NSString *> *)files completion:(void (^)(NSString *_Nullable path))completion;

/// Available only in the main process.
- (nullable ZMDownloadObject *)downloadObjectForType:(ZMDownloadType)type;

/// Download a type of resource if needed.
/// Starts a download only when the resource is not installed.
/// @param type download type
- (void)downloadIfNeededForType:(ZMDownloadType)type;

/// Download a type of resource if needed.
/// it is a combination of "isInstalledForType:" and "downloadForType:progress:completion:"
/// @param type download type
/// @param token return download token
/// @param progress progress block
/// @param completion completion block
- (void)downloadIfNeededForType:(ZMDownloadType)type
                          token:(NSString * _Nullable * _Nullable)token
                       progress:(nullable ZMDownloadProgressBlock)progress
                     completion:(nullable ZMDownloadCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
