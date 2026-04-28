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

@optional
- (NSString*)getLanguageForCookie;
- (BOOL)registerHotkey:(NSString*)name isGlobal:(BOOL)isGlobal;
- (BOOL)unregisterHotkey:(NSString*)name isGlobal:(BOOL)isGlobal;
- (NSDictionary*)queryHotkeyDetail:(NSString*)name;
- (void)startScreenShot:(NSString*)requestId hideMainWindow:(BOOL)hideMainWindow;
// Check if user is currently in a meeting or connecting to a meeting   
- (BOOL)isConnectingOrInMeeting;

/**
 *  Show the report problem window with specified display mode, product type and issue type.
 *  @param displayMode The display mode for the report window (0: Independent, 1: Sheet, 2: Modal)
 *  @param productType The product type tag (NSNotFound to not pre-select)
 *  @param issueType The issue type tag (NSNotFound to not pre-select)
 */
- (void)showReportProblemWindowWithDisplayMode:(NSInteger)displayMode productType:(NSInteger)productType issueType:(NSInteger)issueType;
- (void)showFeedbackWindowWithProduct:(NSString*)product featureName:(NSString*)featureName;

// Meeting action methods - called from webview to trigger PT UI actions
- (BOOL)onWebViewRequestNewMeeting:(NSString*)webviewId;
- (BOOL)onWebViewRequestJoinMeeting:(NSString*)webviewId;
- (BOOL)onWebViewRequestScheduleMeeting:(NSString*)webviewId;
- (BOOL)onWebViewRequestShareScreen:(NSString*)webviewId;
- (BOOL)onWebViewRequestOpenMyNotes:(NSString*)webviewId;
- (BOOL)onWebViewRequestMeetingInfo:(NSString*)webviewId;

@end

//MARK: - unifywebview api, call for pt
@protocol ZMUnifyWebViewHelperProtocol <NSObject>

@optional
- (BOOL)onHotkeyClicked:(NSString*)name;
- (void)onHotkeyChanged:(NSDictionary*)hotkeyInfo;

@end
