//
//  ZMUnifyWebViewPTProtocol.h
//  zUnifyWebView
//
//  Created by Ethan Wu on 2025/1/4.
//

typedef void (^ZMCefDownloadCompletion)(BOOL);
typedef void (^ZMCefDownloadProgress)(NSNumber *);

typedef void (^ZMPTCefDownloadCompletion)(BOOL, BOOL, NSString *);

@class NSWindow;

//MARK: - chat ui api, call for unifyWebview
@protocol ZMUnifyWebViewPTProtocol <NSObject>

@required
- (NSWindow *)getPTMainWindow;
- (NSWindow *)getConfMainWindow;

@optional
- (void)startCefFrameworkDownload:(BOOL)silentDownload progress:(void (^)(float))progress completion:(ZMPTCefDownloadCompletion)completion;
- (void)startCefWebViewDownload:(BOOL)silentDownload progress:(void (^)(float))progress completion:(ZMPTCefDownloadCompletion)completion;
- (void)cancelCefFrameworkDownload;
- (void)cancelCefWebViewDownload;
- (NSString*)getLanguageForCookie;
- (BOOL)registerHotkey:(NSString*)name isGlobal:(BOOL)isGlobal;
- (BOOL)unregisterHotkey:(NSString*)name isGlobal:(BOOL)isGlobal;
- (NSDictionary*)queryHotkeyDetail:(NSString*)name;
- (void)startScreenShot:(NSString*)requestId hideMainWindow:(BOOL)hideMainWindow;

@end

//MARK: - unifywebview api, call for pt
@protocol ZMUnifyWebViewHelperProtocol <NSObject>

@optional
- (BOOL)isCefPluginReady;
- (NSString *)getDownloadedCefFrameworkVersion;
- (NSString *)getDownloadedCefWebViewVersion;
- (NSString *)getCefFrameworkDirWithVersion:(NSString *)version;
- (NSString *)getCefWebViewDirWithVersion:(NSString *)version;
- (BOOL)isNewCefPluginVersionValid:(NSString *)newVersion currentVersion:(NSString *)currentVersion;
- (BOOL)onHotkeyClicked:(NSString*)name;
- (void)onHotkeyChanged:(NSDictionary*)hotkeyInfo;

@end
