//
//  ZMUnifyWebViewUtil.h
//  zUnifyWebView
//
//  Created by Jax Wu on 2024/1/16.
//

#import <Cocoa/Cocoa.h>
#import <zUnifyWebView/UnifyWebViewCommonDefine.h>


@class ZMUnifyLocalPathInfo;

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

+ (BOOL)safeRemoveItemAtPath:(NSString *)path error:(NSError **)error;

+ (NSString*)getUrlFromLocalPath:(ZMUnifyLocalPathInfo *)pathInfo;
+ (NSString*)getLocalFile:(NSString *)urlString localPathInfo:(ZMUnifyLocalPathInfo*)pathInfo;
+ (NSString *)getFilePathFrom:(NSString *)url;
+ (BOOL)isRelativePath:(NSString *)urlStr;

+ (NSString *)urlToMIME:(NSURL *)url;

+ (NSString *)getWebKitVersionInUse;
+ (NSString *)getCEFVersionInUse;
+ (NSString *)getOriginalUserAgent:(BOOL)isCEF;
+ (NSString*)getThemeMode:(NSView*)view;
+ (NSString*)getWebViewThemeMode:(NSString*)webviewGuid;
+ (uint32_t)getWebViewBackgroundColor:(NSString*)webviewGuid;

+ (NSString*)getLanguageForCookie;
+ (NSString*)getHostForCookie:(NSString*)urlHost;
+ (NSString *)getDownloadFilePathWithFolder:(NSString *)downloadFolder suggestedName:(NSString *)fileName;

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

+ (NSString*)getInjectDebugFrame:(NSString*)htmlBodyStr;

+ (BOOL)isProductionRun;
+ (int)getWindowType:(NSWindow *)window;

+ (const char *)getUnifyWebViewLoadAddr;
+ (const char *)entrance;
+ (NSString *)hostOfURL:(NSString *)urlStr;

+ (NSWindow *)getWindowOfWebView:(NSString *)webViewID;
+ (NSWindow *)getPTMainWindow;
+ (NSWindow *)getConfMainWindow;

@end
