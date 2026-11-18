//
//  ZMUnifyWebViewUtil.h
//  zUnifyWebView
//
//  Created by Jax Wu on 2024/1/16.
//

#import <Cocoa/Cocoa.h>
#import <zUnifyWebViewApp/UnifyWebViewCommonDefine.h>
@class WKNavigationAction;

@interface ZMUnifyWebViewUtil : NSObject

+ (BOOL)isEnableWebViewContextMenu;
+ (BOOL)isEnableOsrWebViewContextMenu;

+ (NSString *)disableServiceWorkerJSCode;
+ (NSString *)checkSoundJSCode;
+ (NSString *)getFilterAllowDomains:(NSArray *)allowedDomains ifDomain:(NSString *)ifDomain customSchemes:(NSArray<NSString *>*)customSchemes;
+ (NSString *)getLocalHostFilterDomain:(NSArray *)localAllowedDomains customSchemes:(NSArray<NSString *>*)customSchemes;
+ (NSString *)getBlockListFilter:(NSArray *)disallowedDomains;

+ (void)removeCookieAndLocalStorageFolderForIdentity:(NSString *)appIdentity;
+ (void)deleteWebCacheFolders;
+ (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;

+ (NSString *)getCommonInjectJSString:(BOOL)isCef webviewGuid:(NSString*)webviewGuid;
+ (NSString*)getUnifyConfigInjectJSString:(BOOL)isCef webviewGuid:(NSString*)webviewGuid;
+ (NSDictionary *)getInjectJSCommonSysPra:(BOOL)isCef webviewGuid:(NSString*)webviewGuid;
+ (NSDictionary *)getHTTPCommonHeader;
+ (NSString *)webviewVisibilityChangeJSCode:(BOOL)isHidden;
+ (NSString *)computerWakeStatusChangeJSCode:(BOOL)isSleep;
+ (NSString *)themeModeChangedEventJSCode:(NSView*)view;
+ (NSString *)getInjectFullscreenObserverJSCode;
+ (NSString*)getWebviewZoomFactorChangedJSCode:(int)zoomFactor;
+ (NSString *)contextMenuTrackingJSCode;

+ (BOOL)safeRemoveItemAtPath:(NSString *)path error:(NSError **)error;
+ (BOOL)safeCopyDirectoryFromPath:(NSString *)sourcePath toPath:(NSString *)destinationPath;

+ (NSString *)getWebKitVersionInUse;
+ (NSString *)getCEFVersionInUse;
+ (NSString *)getOriginalUserAgent:(BOOL)isCEF;
+ (NSString*)getThemeMode:(NSView*)view;
+ (NSString*)getThemeColor:(NSView*)view;
+ (NSString*)getWebViewThemeMode:(NSString*)webviewGuid;
+ (uint32_t)getWebViewBackgroundColor:(NSString*)webviewGuid;

+ (NSString*)getLanguageForWebView;
+ (NSString*)getHostForCookie:(NSString*)urlHost;
+ (NSString *)getDownloadFilePathWithFolder:(NSString *)downloadFolder suggestedName:(NSString *)fileName overwriteExisting:(BOOL)overwriteExisting;

+ (NSString*)getCookieFolder;
+ (NSString*)getPersistCookieFolder;
+ (NSString*)getLocalStorageFolder;

+ (NSScreen *)currentScreenForMouse;
+ (BOOL)isRectValidOnScreen:(NSRect)rect;
+ (NSRect)constrainRectToVisibleScreen:(NSRect)rect;

+ (BOOL)getIntegerValue:(NSInteger*)value with:(id)paramValue;
+ (BOOL)getBoolValue:(BOOL*)value with:(id)paramValue;
+ (NSString *)getStringValueWith:(id)paramValue;
+ (NSArray *)getArrayValueWith:(id)paramValue;

+ (NSString *)getLegalSdkName:(NSString *)name;

+ (NSString*)getInjectDebugFrame:(NSString*)htmlBodyStr;

+ (BOOL)isProductionRun;
+ (int)getWindowType:(NSWindow *)window oldWindowType:(int)oldWindowType;

+ (const char *)getUnifyWebViewLoadAddr;
+ (const char *)entrance;
+ (NSString *)urlWithoutPII:(NSString *)urlStr;
+ (enum UnifyWebViewError)convertUnifyErrorFromHttpResponseCode:(int)errcode;

+ (NSWindow *)getWindowOfWebView:(NSString *)webViewID;
+ (NSWindow *)getMainWindow;
+ (BOOL)isFullScreenWindow:(NSWindow *)window;
+ (void)updateWebViewWindowTitleIfNeeded:(NSWindow *)window urlString:(NSString *)urlString pageTitle:(NSString *)pageTitle;

// Trigger JavaScript garbage collection on all process pools to reduce memory
+ (void)triggerJavaScriptGarbageCollection;
+ (BOOL)isLinkActivatedOpenNewWindow:(WKNavigationAction *)navigationAction;
+ (BOOL)isForceCEF:(enum UnifyWebViewAppType)appType;
+ (enum UnifyWebViewType)getCustomWebViewType:(enum UnifyWebViewAppType)appType;
+ (NSURL *)convertToURL:(NSString *)strUrl;
+ (BOOL)openRemoteURLInSystemBrowser:(NSString *)url;

+ (BOOL)isConnectingOrInMeeting;
@end

@interface ZMUnifySavePanelWriteAccessDelegate : NSObject <NSOpenSavePanelDelegate>
@end
