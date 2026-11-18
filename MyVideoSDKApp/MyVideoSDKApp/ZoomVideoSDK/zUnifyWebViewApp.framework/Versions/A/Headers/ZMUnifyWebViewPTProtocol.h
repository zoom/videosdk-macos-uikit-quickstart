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
@class NSEvent;
@class NSView;

//MARK: - chat ui api, call for unifyWebview
@protocol ZMUnifyWebViewPTProtocol <NSObject>

@required
- (NSWindow *)getPTMainWindow;

@optional
/// @param compressImageIntensity 0 = default PNG settings, 1–2 = stronger PNG compression (PNG compression level).
// Kept as a compatibility entry point. New callers should use
// ZMUnifyWebViewSharedProtocol's screenshot entry point.
- (void)startScreenShot:(NSString*)requestId hideMainWindow:(BOOL)hideMainWindow compressImageIntensity:(NSInteger)compressImageIntensity;

// Screenshot host hooks used by the shared screenshot coordinator.
- (NSView *)captureScreenSender;
- (BOOL)isMeetingSession;
- (void)meetingChatStartScreenshot:(BOOL)needHideWindow;
- (void)meetingChatScreenshotCompleted:(BOOL)successed;

// Check if user is currently in a meeting or connecting to a meeting   
- (BOOL)isConnectingOrInMeeting;

- (void)showReportProblemWindow;
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
- (BOOL)onWebViewRequestNewMeeting:(NSString*)webviewId isVideoOn:(BOOL)isVideoOn;
- (BOOL)onWebViewRequestNewMeeting:(NSString*)webviewId isVideoOn:(BOOL)isVideoOn usePmi:(BOOL)usePmi;
- (BOOL)onWebViewRequestJoinMeeting:(NSString*)webviewId;
- (BOOL)onWebViewRequestScheduleMeeting:(NSString*)webviewId;
- (BOOL)onWebViewRequestShareScreen:(NSString*)webviewId;
- (BOOL)onWebViewRequestOpenMyNotes:(NSString*)webviewId;
- (BOOL)onWebViewRequestCallRoom:(NSString*)webviewId;
- (BOOL)onWebViewRequestMeetingInfo:(NSString*)webviewId;
- (BOOL)onWebViewRequestPMIMeetingInfo:(NSString*)webviewId;
- (BOOL)onWebViewRequestPmiSettings:(NSString*)webviewId;
- (BOOL)onWebViewRequestSetStartWithVideo:(NSString*)webviewId isVideoOn:(BOOL)isVideoOn;
- (BOOL)onWebViewRequestSetUsePmi:(NSString*)webviewId usePmi:(BOOL)usePmi;
- (BOOL)onWebViewRequestCopyPmiLink:(NSString*)webviewId;
- (BOOL)onWebViewRequestCopyPmiId:(NSString*)webviewId;
- (BOOL)onWebViewRequestCopyPmiInvitation:(NSString*)webviewId;

@end

//MARK: - unifywebview api, call for pt
@protocol ZMUnifyWebViewHelperProtocol <NSObject>

@optional
- (BOOL)onHotkeyClicked:(NSString*)name;
- (void)onHotkeyChanged:(NSDictionary*)hotkeyInfo;
- (BOOL)shouldUseActiveWindowLocalHotkeyDispatch:(NSString*)name;
- (void)bringPTMainWindowToFront:(NSWindow *)window;
- (void)onLocalAddressChanged:(NSString*)oldIP newIP:(NSString*)newIP;
- (void)onConfReady;

@end
