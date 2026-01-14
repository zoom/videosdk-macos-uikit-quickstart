//
//  ZMUnifyWebViewDefine.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#ifndef ZMUnifyWebViewDefine_h
#define ZMUnifyWebViewDefine_h

#import <WebKit/WebKit.h>
#import "UnifyWebViewCommonDefine.h"

extern NSString *const kWebKitDeveloperExtrasEnabled;
extern NSString *const kWebKitCachePath;
extern NSString *const kWebKitDataPath;
extern NSString *const kBlobScheme;

typedef NS_OPTIONS(NSUInteger, ZMWebCaptureDevices) {
    ZMWebCaptureDeviceMicrophone = 1 << 0,
    ZMWebCaptureDeviceCamera = 1 << 1,
    ZMWebCaptureDeviceDisplay = 1 << 2,
};

typedef NS_ENUM(NSInteger, ZMWebDisplayCapturePermissionDecision) {
    ZMWebDisplayCapturePermissionDecisionDeny,
    ZMWebDisplayCapturePermissionDecisionScreenPrompt,
    ZMWebDisplayCapturePermissionDecisionWindowPrompt,
};

typedef NS_ENUM(NSInteger, ZMWebProcessTerminationReason) {
    ZMWebProcessTerminationReasonUnknown = -1,
    ZMWebProcessTerminationReasonExceededMemoryLimit,
    ZMWebProcessTerminationReasonExceededCPULimit,
    ZMWebProcessTerminationReasonRequestedByClient,
    ZMWebProcessTerminationReasonCrash,
    ZMWebProcessTerminationReasonExceededSharedProcessCrashLimit,

    ZMWebProcessTerminationReasonRenderProcessUnresponsive = 100,
};

typedef NS_ENUM(NSInteger, ZMContextMenuItemTag) {
    kZMContextMenuItemTagNoAction = 0,
    kZMContextMenuItemTagOpenLinkInNewWindow,
    kZMContextMenuItemTagDownloadLinkToDisk,
    kZMContextMenuItemTagCopyLinkToClipboard,
    kZMContextMenuItemTagOpenImageInNewWindow,
    kZMContextMenuItemTagDownloadImageToDisk,
    kZMContextMenuItemTagCopyImageToClipboard,
    kZMContextMenuItemTagOpenFrameInNewWindow,
    kZMContextMenuItemTagCopy,
    kZMContextMenuItemTagGoBack,
    kZMContextMenuItemTagGoForward,
    kZMContextMenuItemTagStop,
    kZMContextMenuItemTagReload,
    kZMContextMenuItemTagCut,
    kZMContextMenuItemTagPaste,
    kZMContextMenuItemTagSpellingGuess,
    kZMContextMenuItemTagNoGuessesFound,
    kZMContextMenuItemTagIgnoreSpelling,
    kZMContextMenuItemTagLearnSpelling,
    kZMContextMenuItemTagOther,
    kZMContextMenuItemTagSearchInSpotlight,
    kZMContextMenuItemTagSearchWeb,
    kZMContextMenuItemTagLookUpInDictionary,
    kZMContextMenuItemTagOpenWithDefaultApplication,
    kZMContextMenuItemTagPDFActualSize,
    kZMContextMenuItemTagPDFZoomIn,
    kZMContextMenuItemTagPDFZoomOut,
    kZMContextMenuItemTagPDFAutoSize,
    kZMContextMenuItemTagPDFSinglePage,
    kZMContextMenuItemTagPDFFacingPages,
    kZMContextMenuItemTagPDFContinuous,
    kZMContextMenuItemTagPDFNextPage,
    kZMContextMenuItemTagPDFPreviousPage,
    kZMContextMenuItemTagOpenLink,
    kZMContextMenuItemTagIgnoreGrammar,
    kZMContextMenuItemTagSpellingMenu,
    kZMContextMenuItemTagShowSpellingPanel,
    kZMContextMenuItemTagCheckSpelling,
    kZMContextMenuItemTagCheckSpellingWhileTyping,
    kZMContextMenuItemTagCheckGrammarWithSpelling,
    kZMContextMenuItemTagFontMenu,
    kZMContextMenuItemTagShowFonts,
    kZMContextMenuItemTagBold,
    kZMContextMenuItemTagItalic,
    kZMContextMenuItemTagUnderline,
    kZMContextMenuItemTagOutline,
    kZMContextMenuItemTagStyles,
    kZMContextMenuItemTagShowColors,
    kZMContextMenuItemTagSpeechMenu,
    kZMContextMenuItemTagStartSpeaking,
    kZMContextMenuItemTagStopSpeaking,
    kZMContextMenuItemTagWritingDirectionMenu,
    kZMContextMenuItemTagDefaultDirection,
    kZMContextMenuItemTagLeftToRight,
    kZMContextMenuItemTagRightToLeft,
    kZMContextMenuItemTagPDFSinglePageScrolling,
    kZMContextMenuItemTagPDFFacingPagesScrolling,
    kZMContextMenuItemTagInspectElement,
    kZMContextMenuItemTagTextDirectionMenu,
    kZMContextMenuItemTagTextDirectionDefault,
    kZMContextMenuItemTagTextDirectionLeftToRight,
    kZMContextMenuItemTagTextDirectionRightToLeft,
    kZMContextMenuItemTagCorrectSpellingAutomatically,
    kZMContextMenuItemTagSubstitutionsMenu,
    kZMContextMenuItemTagShowSubstitutions,
    kZMContextMenuItemTagSmartCopyPaste,
    kZMContextMenuItemTagSmartQuotes,
    kZMContextMenuItemTagSmartDashes,
    kZMContextMenuItemTagSmartLinks,
    kZMContextMenuItemTagTextReplacement,
    kZMContextMenuItemTagTransformationsMenu,
    kZMContextMenuItemTagMakeUpperCase,
    kZMContextMenuItemTagMakeLowerCase,
    kZMContextMenuItemTagCapitalize,
    kZMContextMenuItemTagChangeBack,
    kZMContextMenuItemTagOpenMediaInNewWindow,
    kZMContextMenuItemTagDownloadMediaToDisk,
    kZMContextMenuItemTagCopyMediaLinkToClipboard,
    kZMContextMenuItemTagToggleMediaControls,
    kZMContextMenuItemTagToggleMediaLoop,
    kZMContextMenuItemTagEnterVideoFullscreen,
    kZMContextMenuItemTagMediaPlayPause,
    kZMContextMenuItemTagMediaMute,
    kZMContextMenuItemTagDictationAlternative,
    kZMContextMenuItemTagPlayAllAnimations,
    kZMContextMenuItemTagPauseAllAnimations,
    kZMContextMenuItemTagPlayAnimation,
    kZMContextMenuItemTagPauseAnimation,
    kZMContextMenuItemTagCopyImageUrlToClipboard,
    kZMContextMenuItemTagSelectAll,
    kZMContextMenuItemTagOpenLinkInThisWindow,
    kZMContextMenuItemTagToggleVideoFullscreen,
    kZMContextMenuItemTagShareMenu,
    kZMContextMenuItemTagToggleVideoEnhancedFullscreen,
    kZMContextMenuItemTagAddHighlightToCurrentQuickNote,
    kZMContextMenuItemTagAddHighlightToNewQuickNote,
    kZMContextMenuItemTagRevealImage,
    kZMContextMenuItemTagTranslate,
    kZMContextMenuItemTagCopyCroppedImage,
    kZMContextMenuItemBaseApplicationTag = 10000,
};

typedef NS_OPTIONS(NSUInteger, ZMWebRenderProgressEvent) {
    _WKRenderingProgressEventFirstVisuallyNonEmptyLayout = 1 << 1,
};

API_AVAILABLE(macos(10.11))
@interface WKWebsiteDataStore (UnifyWebView)
- (void)clearWebCache:(nullable void (^)(void))completionHandler;
@end

@protocol ZMUnifyWebViewURLSchemeHandlerProtocol <NSObject>

- (id<WKURLSchemeHandler>)urlSchemeHandler;
- (NSString *)urlSchemeName;

@end

/// Configuration object for UnifyWebView instances
/// This class provides comprehensive configuration options for customizing WebView behavior,
/// performance settings, security policies, and feature enablement
/// Doc Link: https://dg01docs.zoom.us/doc/FCvFJTBrRVSJwi5JW9EVSw
@interface ZMUnifyWebViewConfiguration : NSObject

//MARK: - Core Configuration

/**
*  Configures the specify the kernel type of WebView
*  - Possible Values: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*  - Default Value: UnifyWebViewType_None
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) enum UnifyWebViewType unifyWebViewType;

/**
*  Define the type of WebView application to distinguish different upper-layer applications and set different permissions.
*  - Possible Values: UnifyWebViewType_Mail, UnifyWebViewType_ZoomDocs, ...
*  - Default Value: UnifyWebViewType_None
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) enum UnifyWebViewAppType moduleType;

/**
*  Instance name for the WebView, used to identify different WebView instances.
*  - Possible Values: Any string identifier
*  - Default Value: Empty string
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, strong) NSString *instName;

//MARK: - Feature Controls

/**
*  A setting in WKWebView that controls whether asynchronous clipboard access is enabled, which affects the use of clipboard APIs (such as navigator.clipboard.readText(), writeText()) by JavaScript in web pages.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL asyncClipboardEnabled;

/**
*  A setting in WebKit that controls whether a web page is allowed to use the fullscreen API. When enabled, the web page can enter fullscreen, for example: Clicking the fullscreen button on an HTML5 video will enlarge it to fullscreen
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL fullScreenEnabled;

/**
*  Determines whether to enable the fullscreen mode observer, which monitors changes in the WebView's fullscreen state.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL fullScreenObserverEnabled;

/**
*  Determines whether to allow the WebView to use media devices, such as cameras and microphones.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL mediaDevicesEnabled;

/**
*  Determines whether to allow the Tab key to focus on links, enhancing keyboard navigation accessibility.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL tabFocusesLinksEnabled;

/**
*  Determines whether to allow JavaScript to open new windows using the window.open() method.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isWindowOpenEnabled;

//MARK: - Security & Privacy Settings

/**
*  Whether to allow third-party cookies affects the processing of cross-site requests, including third-party web pages opened by window.open().
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isThirdPartyCookieEnabled;

/**
*  Determines whether to force-terminate the Web content process when the WebView is destroyed.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL forceKillWebContentProcessOnDestroyEnabled;

//MARK: - Network Configuration

/**
 * Enables request interception for adding custom headers to HTTP/HTTPS requests.
 * When enabled, a WebProcess PlugIn will be loaded to modify outgoing requests.
 * - Possible Values: YES, NO
 * - Default Value: NO
 * - Supported WebView Types: UnifyWebViewType_WKWebView
 */
@property (nonatomic, assign) BOOL isNewLocalLoadModeEnabled;

//MARK: - UI Configuration

/**
*  Determines whether to allow zoom operations using keyboard shortcuts, such as Command + + (zoom in), Command + - (zoom out), and Command + 0 (reset).
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isZoomControlEnabled;

/**
*  Determines whether to allow non-HTTPS requests to be upgraded to HTTPS, especially when loading non-HTTPS resources on HTTPS pages.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
//@property (nonatomic, assign) BOOL isUpgradeMixedContentEnabled;

/**
*  Determines whether to enable native spell checking for web pages, providing real-time spelling corrections.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
//@property (nonatomic, assign) BOOL isSpellCheckEnabled;

/**
*  Determines whether to keep the WebView background transparent
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isDrawsTransparentBackgroundEnabled;

/**
*  The loading wording below the progress indicator
*  - Possible Values: String or nil
*  - Default Value: nil
*  - Supported WebView Types: V2 for UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, copy, nullable) NSString *loadingDesc;

/**
*  Determines whether to keep the WebView active in the background, preventing it from entering sleep mode.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isBackgroundKeepAliveEnabled;

/**
*  Determines whether to disable the system's backspace shortcut key (e.g., Command + left arrow), preventing WebView's back navigation.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isBackspaceKeyNavigationEnabled;

/**
*  Determines whether to detect blank pages and display corresponding error messages.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isBlankPageDetectionEnabled;

//MARK: - Performance & Resource Management

/**
*  Determines whether to display the loading interface provided by the unified WebView.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isShowLoadingEnabled;

/**
*  Determines whether to hide the problem report button in the error view.
*  - Possible Values: YES, NO
*  - Default Value: YES (button displayed)
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isProblemReportButtonInErrorViewEnabled;

/**
*  Determines whether to enable zoom-style context menu options
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL isZoomStyleContextMenuEnabled;

//MARK: - Navigation & Interaction

/**
*  Determines whether to allows the WebView to process and handle deep link navigation
*  - Possible Values: YES, NO
*  - Default Value: NO
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isHandlingDeeplinkEnabled;

/**
 * Whether to execute the download logic during the Navigation process.
 *  - Possible Values: YES, NO
 *  - Default Value: NO
 *  - Supported WebView Types: UnifyWebViewType_WKWebView
 */
@property (nonatomic, assign) BOOL isPerformDownloadInNavigationEnabled;

/**
*  A custom suffix for the user agent string, used to identify the WebView or additional information.
*  - Possible Values: Empty string or custom string (e.g., @" MyApp/1.0")
*  - Default Value: Empty string
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, strong) NSString *userAgentSuffix;

/**
*  Unique identifier for cache and cookie isolation. Different identifiers create separate storage spaces for web data
*  - Possible Values: Appid
*  - Default Value: Empty string
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, strong) NSString *cacheAndCookieIdentify;

/**
*  Determines whether to enable privacy mode. Similar to Chrome's privacy mode, cookies and cache are no longer stored on the hard disk.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isPrivacyMode;

/**
*  Indicates whether the WebView is being used within an active meeting context
*  - Possible Values: UnifyWebviewMeetingState_Unknown, UnifyWebviewMeetingState_PreMeeting, UnifyWebviewMeetingState_InMeeting
*  - Default Value: UnifyWebviewMeetingState_Unknown
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) enum UnifyWebviewMeetingState inMeetingState;

/**
*  Determines whether to enable tracking areas, used to handle user input events within the WebView.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL enableTrackingArea;

/**
*  Specifies the idle recycling strategy for the WebView, optimizing resource usage.
*  - Possible Values: UnifyWebViewIdleRecycleType_Default, UnifyWebViewIdleRecycleType_Enabled, UnifyWebViewIdleRecycleType_NoResponseEnabled,UnifyWebViewIdleRecycleType_ForceDisabled
*  - Default Value: UnifyWebViewIdleRecycleType_Default
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) enum UnifyWebViewIdleRecycleType idleRecycleType;

/**
*  Determines whether to allow silent downloading of WebView plugins for automatic updates or feature enhancements.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isEnableSilentDownloadWebViewPlugin;

/**
*  Controls the cache cleanup strategy during sign out operation.
*  When enabled, only cookies and database will be cleared during sign out, preserving other cache data.
*  When disabled, the entire WebView cache directory will be removed during sign out.
*  - Possible Values: YES (only clear cookies and database), NO (remove entire cache directory)
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL enableClearSensitiveCacheOnly;

/**
*  Controls whether JavaScript is allowed to access the system clipboard.
*  When enabled, JavaScript running inside the WebView can read/write the clipboard through supported APIs.
*  When disabled, JavaScript access to the clipboard is blocked to enhance privacy and security.
*  - Possible Values: YES (allow JS clipboard access), NO (block JS clipboard access)
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_CEF
*/
@property (nonatomic, assign) BOOL isJsAccessClipboardEnabled;

//MARK: - Deprecated Properties

/**
 *  Sets the display name of the process for management and monitoring purposes. Deprecated.
 *  - Possible Values: Custom string
 *  - Default Value: System-generated display name
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, copy) NSString *processDisplayName DEPRECATED_MSG_ATTRIBUTE("This property is deprecated");

/**
*  Whether to check messages sent from JavaScript to ensure they come from a trusted source. Deprecated.
*  - Possible Values: YES, NO
*  - Default Value: NO
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL checkJSMessageEnabled DEPRECATED_MSG_ATTRIBUTE("This property is deprecated");

/**
*  Specifies the instance responsible for managing website data storage, such as caches and cookies. Deprecated.
*  - Possible Values: An instance of WKWebsiteDataStore
*  - Default Value: Uses the shared WKWebsiteDataStore instance
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, strong) WKWebsiteDataStore *websiteDataStore DEPRECATED_MSG_ATTRIBUTE("This property is deprecated");

/**
*  An array of custom URL scheme handlers, allowing developers to manage specific URL requests. Deprecated.
*  - Possible Values: An array of objects implementing ZMUnifyWebViewURLSchemeHandlerProtocol
*  - Default Value: Empty array
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, strong) NSArray<id<ZMUnifyWebViewURLSchemeHandlerProtocol>> *handlerArray DEPRECATED_MSG_ATTRIBUTE("This property is deprecated");

/**
*  Determines whether to display the context menu (e.g., right-click options). Deprecated.
*  - Possible Values: YES, NO
*  - Default Value: YES
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
@property (nonatomic, assign) BOOL needShowContextMenu DEPRECATED_MSG_ATTRIBUTE("This property is deprecated");

/**
*  Returns an identifier string for the data store, used to distinguish between different data store instances. Deprecated.
*  - Return Value: An identifier string for the data store.
*  - Supported WebView Types: UnifyWebViewType_WKWebView
*/
- (NSString *)dataStoreIdentity DEPRECATED_MSG_ATTRIBUTE("This method is deprecated");

@end

/// Category extension for NSURLRequest to support UnifyWebView scheme handling
/// Adds additional properties needed for custom URL scheme processing
@interface NSURLRequest (UnifyWebSchemeHandler)

/// Timestamp associated with the request for tracking and caching purposes
/// Used internally by UnifyWebView to manage request timing and cache invalidation
@property (nonatomic, strong) NSNumber *unifyTimestamp;

@end

/// Configuration object for managing domain access permissions
/// This class defines which domains are allowed or blocked for web resource loading
@interface ZMWebResourceAllowDomains : NSObject

/**
 *  Array of domain strings to be allowed or blocked
 *  - Possible Values: Domain format examples: ["example.com", "*.google.com", "subdomain.site.org"]
 *  - Default Value: Empty array
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSArray *domains;

/**
 *  Determines whether the domains list represents an allow-list or block-list
 *  - Possible Values: YES (domains are allowed), NO (domains are blocked)
 *  - Default Value: YES
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) BOOL isAllowDomains;
@end

/// Parameters object for WebView navigation requests
/// This class encapsulates all the information needed to perform a navigation operation
@interface ZMUnifyWebViewNavigatePara : NSObject

/**
 *  Target URL for the navigation request
 *  - Possible Values: Any valid URL including HTTP, HTTPS, file://, or custom schemes
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString *url;

/**
 *  Custom HTTP headers to include with the navigation request
 *  - Possible Values: Key-value pairs where keys are header names and values are header values
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *customRequestHeaders;

/**
 *  List of domain access permissions for this navigation
 *  - Possible Values: Array of ZMWebResourceAllowDomains objects
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSArray<ZMWebResourceAllowDomains*> *allowDomainList;
@end

/// Container object for captured WebView images
/// This class holds image data and metadata from WebView frame capture operations
@interface ZMUnifyWebViewCaptureImage : NSObject

/**
 *  Type identifier for the captured image format
 *  - Possible Values: Integer values indicating image format (e.g., PNG, JPEG, etc.)
 *  - Default Value: 0
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) int type;

/**
 *  Raw image data in the specified format
 *  - Possible Values: NSData containing actual image bytes
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSData *imgData;
@end

/// Configuration object for hybrid application launching
/// Contains all the information needed to open and configure a hybrid app within the WebView
@interface ZMHybridAppInfo : NSObject

/**
 *  Unique index identifier for the hybrid application
 *  - Possible Values: Integer index used to distinguish between different hybrid apps
 *  - Default Value: 0
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) int hybridAppIdx;

/**
 *  Indicates whether the hybrid app is being launched within a meeting context
 *  - Possible Values: YES (in meeting), NO (not in meeting)
 *  - Default Value: NO
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) BOOL isInMeeting;

/**
 *  Determines whether to use CDN fallback for app resources
 *  - Possible Values: YES (use CDN fallback), NO (no fallback)
 *  - Default Value: YES
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) BOOL needFallbackToCDN;

/**
 *  Additional configuration parameters for the hybrid app
 *  - Possible Values: Key-value pairs containing app-specific settings and metadata
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*>* extraInfo;
@end

/// Result object for hybrid application opening operations
/// Contains the outcome and details of a hybrid app launch attempt
@interface ZMOpenHybridAppResult : NSObject

/**
 *  Index of the hybrid application that was attempted to be opened
 *  - Possible Values: Integer index corresponding to the hybridAppIdx from the original launch request
 *  - Default Value: 0
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) int hybridAppIdx;

/**
 *  Unique application identifier for the opened hybrid app
 *  - Possible Values: String identifier that can be used to reference the app instance
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString* appId;

/**
 *  Indicates whether the hybrid app was successfully opened
 *  - Possible Values: YES (app launched successfully), NO (launch failed)
 *  - Default Value: NO
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) BOOL bSuccess;

/**
 *  Type of loading mechanism used for the hybrid app
 *  - Possible Values: HybridAppLoadType enum values (local, remote, cached, etc.)
 *  - Default Value: Depends on HybridAppLoadType enum default
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) enum HybridAppLoadType loadType;
@end

/// Parameters object for custom button configuration in WebView interfaces
/// This class defines the properties and behavior of custom buttons added to WebView UI elements
@interface ZMUnifyWebViewButtonPara : NSObject

/**
 *  Display text for the custom button
 *  - Possible Values: Any string that will be shown as the button's label to users
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString* labelString;
@end


/// Parameters object for new window opening requests
/// Contains the configuration details when a web page requests to open a new window
@interface ZMUnifyWebViewWindowOpenParam : NSObject

/**
 *  Target URL for the new window
 *  - Possible Values: Any valid URL that should be loaded in the newly opened window
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString* url;
@end

/// Result object for new window opening operations
/// Contains the outcome and handling status of a window.open() request
@interface ZMUnifyWebViewNewWindowOpenResult : NSObject

/**
 *  Result code indicating how the window opening request was processed
 *  - Possible Values: UnifyWebViewNewWindowOpenResultCode enum values (allowed, denied, custom handling)
 *  - Default Value: Depends on UnifyWebViewNewWindowOpenResultCode enum default
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) enum UnifyWebViewNewWindowOpenResultCode returnCode;

/**
 *  Indicates whether the window opening request was handled by the delegate
 *  - Possible Values: YES (delegate processed the request), NO (use default behavior)
 *  - Default Value: NO
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) BOOL handled;
@end

/// Parameters object for download before callback
/// Contains the information about the file being downloaded
@interface ZMUnifyWebViewDownloadParam : NSObject

/**
 *  Suggested file name for the download
 *  - Possible Values: String representing the suggested filename for the download
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString* suggestedFileName;

/**
 *  URL of the file being downloaded
 *  - Possible Values: Any valid URL pointing to the downloadable file
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, strong) NSString* downloadUrl;
@end

/// Decision object for download callback response
/// Contains the delegate's decision on how to handle the download
@interface ZMUnifyWebViewDownloadDecision : NSObject

/**
 *  Download handling decision type
 *  - Possible Values: UnifyWebviewDownloadType enum values (None, Cancel, ShowDialog, SystemDownloadPath)
 *  - Default Value: UnifyWebviewDownloadType_None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
@property (nonatomic, assign) enum UnifyWebviewDownloadType downloadType;
@end


#endif /* ZMUnifyWebViewDefine_h */
