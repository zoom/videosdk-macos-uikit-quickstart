//
//  ZMUnifyWebViewUtil.h
//  zUnifyWebView
//
//  Created by Jax Wu on 2024/1/16.
//

#import <Cocoa/Cocoa.h>
#import <zUnifyWebViewApp/UnifyWebViewCommonDefine.h>

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

+ (NSString *)getWebKitVersionInUse;
+ (NSString *)getCEFVersionInUse;
+ (NSString *)getOriginalUserAgent:(BOOL)isCEF;
+ (NSString*)getThemeMode:(NSView*)view;
+ (NSString*)getThemeColor:(NSView*)view;
+ (NSString*)getWebViewThemeMode:(NSString*)webviewGuid;
+ (uint32_t)getWebViewBackgroundColor:(NSString*)webviewGuid;

+ (NSString*)getLanguageForWebView;
+ (NSString*)getLanguageForCookie;
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

+ (NSString*)getInjectDebugFrame:(NSString*)htmlBodyStr;

+ (BOOL)isProductionRun;
+ (int)getWindowType:(NSWindow *)window;

+ (const char *)getUnifyWebViewLoadAddr;
+ (const char *)entrance;
+ (NSString *)urlWithoutPII:(NSString *)urlStr;
+ (enum UnifyWebViewError)convertUnifyErrorFromHttpResponseCode:(int)errcode;

+ (NSWindow *)getWindowOfWebView:(NSString *)webViewID;
+ (NSWindow *)getPTMainWindow;

// Trigger JavaScript garbage collection on all process pools to reduce memory
+ (void)triggerJavaScriptGarbageCollection;

@end
