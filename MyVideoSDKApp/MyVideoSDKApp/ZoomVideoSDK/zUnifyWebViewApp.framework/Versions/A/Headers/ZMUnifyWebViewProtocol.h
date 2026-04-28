//
//  ZMUnifyWebViewProtocol.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import "ZMUnifyWebViewDefine.h"
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMUnifyWebViewInstance;
@protocol ZMUnifyWebViewProtocol;

@protocol ZMUnifyWebViewHelper <NSObject>

@optional
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;
- (void)showEmojiWindow:(BOOL)show rect:(NSRect)rect positionView:(NSView *)view type:(NSString *)type;
- (NSString *)languageCode;
- (void)showReportProblemWindow;
- (NSString *)curCefAgentPath;
- (BOOL)isCefAgentReady;

@end

//MARK: - V2 Delegate Protocol (Callbacks)
@protocol ZMUnifyWebViewDelegate <NSObject>

@optional

//MARK: - Lifecycle Callbacks

/**
 *  Called when a unified WebView instance has been created
 *  This callback is triggered after the WebView initialization process completes,
 *  allowing the delegate to perform post-creation setup or handle creation failures
 *  - Parameters:
 *    - instance: The WebView instance that was created
 *    - isSuccess: Whether the WebView creation was successful
 *  - Possible Values: isSuccess can be YES (creation successful) or NO (creation failed)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onUnifyWebViewCreated:(id<ZMUnifyWebViewProtocol>)instance isSuccess:(BOOL)isSuccess;

/**
 *  Called when a unified WebView instance is about to be destroyed
 *  This callback allows the delegate to perform cleanup operations before the WebView is deallocated
 *  - Parameters:
 *    - instance: The WebView instance that will be destroyed
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onUnifyWebViewDestroyed:(id<ZMUnifyWebViewProtocol>)instance;

//MARK: - Navigation Callbacks

/**
 *  Called when navigation is about to start in the WebView
 *  This callback is triggered before any navigation request is processed, allowing the delegate
 *  to examine the target URL and decide whether to allow, deny, or modify the navigation
 *  - Parameters:
 *    - instance: The WebView instance initiating the navigation
 *    - url: The target URL for the navigation request
 *    - decisionHandler: Decision handler block to control navigation permission
 *  - Possible Values: Returns YES (delegate handled decision) or NO (use default behavior)
 *  - Default Value: NO (use default navigation behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onNavigateStart:(id<ZMUnifyWebViewProtocol>)instance url:(nullable NSString*)url decisionHandler:(nullable void (^)(enum UnifyWebViewOperateState decision))decisionHandler;

/**
 *  Called when navigation is about to start within an iframe in the WebView
 *  This callback is specifically for iframe navigation events, allowing fine-grained control
 *  over embedded content navigation separate from main frame navigation
 *  - Parameters:
 *    - instance: The WebView instance containing the iframe
 *    - url: The target URL for the iframe navigation request
 *    - decisionHandler: Decision handler block to control iframe navigation permission
 *  - Possible Values: Returns YES (delegate handled decision) or NO (use default behavior)
 *  - Default Value: NO (use default iframe navigation behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onIframeNavigateStart:(id<ZMUnifyWebViewProtocol>)instance url:(nullable NSString*)url decisionHandler:(nullable void (^)(enum UnifyWebViewOperateState decision))decisionHandler;

/**
 *  Called when navigation has completed in the WebView
 *  This callback is triggered after navigation finishes, whether successfully or with an error.
 *  It provides detailed information about the navigation result including any error codes and HTTP status
 *  - Parameters:
 *    - instance: The WebView instance that completed navigation
 *    - url: The final URL after navigation completion (may differ from original due to redirects)
 *    - errorCode: Navigation error code from UnifyWebViewError enum
 *    - httpStatus: HTTP status code returned by the server
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onNavigateFinish:(id<ZMUnifyWebViewProtocol>)instance url:(nullable NSString*)url errorCode:(enum UnifyWebViewError)errorCode httpStatus:(int)httpStatus;

//MARK: - Communication Callbacks

/**
 *  Called when the WebView receives a message from JavaScript
 *  This callback handles communication from web content to native code through JavaScript bridges.
 *  The message format and content depend on the web application's implementation
 *  - Parameters:
 *    - instance: The WebView instance that received the message
 *    - message: The message content sent from JavaScript (typically JSON string)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onRecvWebMessage:(id<ZMUnifyWebViewProtocol>)instance message:(nullable NSString*)message;

/**
 *  Called to retrieve custom HTTP headers for network requests
 *  This callback allows the delegate to provide additional HTTP headers that should be included
 *  with requests made by the WebView. Headers can be customized based on the target URL
 *  - Parameters:
 *    - instance: The WebView instance making the request
 *    - url: The target URL for which headers are being requested
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSDictionary<NSString*, NSString*>*)onGetRequestHeaderMap:(id<ZMUnifyWebViewProtocol>)instance url:(nullable NSString*)url;

/**
 *  Called when a resource fails to load in the WebView
 *  This callback is triggered when individual resources (images, CSS, JS files, etc.) fail to load,
 *  providing details about the failure for debugging and error handling purposes
 *  - Parameters:
 *    - instance: The WebView instance where the resource load failed
 *    - httpStatus: HTTP status code of the failed request
 *    - url: The URL of the resource that failed to load
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onResourceLoadError:(id<ZMUnifyWebViewProtocol>)instance httpStatus:(int)httpStatus url:(nullable NSString*)url;

/**
 *  Called to retrieve JavaScript code that should be executed when the document is created
 *  This callback allows injection of custom JavaScript code that runs early in the page lifecycle,
 *  before other scripts load. Useful for setting up JavaScript bridges, polyfills, or initial configuration
 *  - Parameters:
 *    - instance: The WebView instance requesting the script
 *  - Possible Values: JavaScript code string or nil if no script is needed
 *  - Default Value: nil (no script injection)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)onGetDocumentCreatedRunScript:(id<ZMUnifyWebViewProtocol>)instance;

//MARK: - Media & Capture Callbacks

/**
 *  Called when a single frame image has been captured from the WebView
 *  This callback is triggered after a frame capture operation completes, providing access to the
 *  captured image data for saving, processing, or display purposes
 *  - Parameters:
 *    - instance: The WebView instance from which the frame was captured
 *    - captureImage: The captured image object containing image data and metadata
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onCaptureOneFrameImage:(id<ZMUnifyWebViewProtocol>)instance captureImage:(nullable ZMUnifyWebViewCaptureImage*)captureImage;

/**
 *  Called when the network connectivity status changes
 *  This callback notifies the delegate about changes in network availability, allowing the
 *  application to respond appropriately to online/offline states or connection quality changes
 *  - Parameters:
 *    - instance: The WebView instance reporting the network status change
 *    - state: Network state identifier
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onNetworkStatusChange:(id<ZMUnifyWebViewProtocol>)instance state:(int)state;

//MARK: - Error & Recovery Callbacks

/**
 *  Called when the WebView browser process crashes
 *  This callback is triggered when the underlying browser engine crashes, allowing the application
 *  to handle recovery, logging, or user notification. The delegate can choose to handle the crash
 *  or let the default recovery mechanism take place
 *  - Parameters:
 *    - instance: The WebView instance that experienced the crash
 *    - crashType: Type of crash that occurred from UnifyWebviewCrashType enum
 *    - url: The URL that was being displayed when the crash occurred
 *  - Possible Values: Returns YES (delegate handled crash recovery) or NO (use default handling)
 *  - Default Value: NO (use default crash handling)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onBrowserCrashed:(id<ZMUnifyWebViewProtocol>)instance crashType:(enum UnifyWebviewCrashType)crashType url:(nullable NSString*)url;

/**
 *  Called when a hybrid application has been opened from the WebView
 *  This callback is triggered when the WebView successfully launches or attempts to launch
 *  a hybrid application, providing details about the operation result
 *  - Parameters:
 *    - instance: The WebView instance that initiated the hybrid app launch
 *    - openResult: Result object containing details about the hybrid app opening operation
 *  - Possible Values: ZMOpenHybridAppResult object with success status and app details
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onOpenHybridApp:(id<ZMUnifyWebViewProtocol>)instance openResult:(nullable ZMOpenHybridAppResult*)openResult;

/**
 *  Called when a custom button in the download view is clicked
 *  This callback is triggered when the user interacts with custom UI elements added to
 *  the download interface, allowing for custom download handling or additional actions
 *  - Parameters:
 *    - instance: The WebView instance containing the download view
 *  - Possible Values: Returns YES (delegate handled button click) or NO (use default behavior)
 *  - Default Value: NO (use default button behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onCustomButtonInDownloadViewClicked:(id<ZMUnifyWebViewProtocol>)instance;

/**
 *  Called before an error page is displayed to the user
 *  This callback allows the delegate to intercept error page display and provide custom
 *  error handling or UI. The delegate can prevent the default error page from showing
 *  - Parameters:
 *    - instance: The WebView instance that encountered the error
 *    - errorCode: Numeric error code identifying the type of error that occurred
 *  - Possible Values: Returns YES (prevent default error page) or NO (show default error page)
 *  - Default Value: NO (show default error page)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onBeforeErrorPageShow:(id<ZMUnifyWebViewProtocol>)instance errorCode:(int)errorCode;

/**
 *  Called when the refresh button on an error page is clicked
 *  This callback is triggered when the user attempts to reload content from an error page,
 *  allowing the delegate to perform custom refresh logic or additional error recovery
 *  - Parameters:
 *    - instance: The WebView instance displaying the error page
 *  - Possible Values: Returns YES (delegate handled refresh) or NO (use default refresh behavior)
 *  - Default Value: NO (use default refresh behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onErrorPageRefreshButtonClicked:(id<ZMUnifyWebViewProtocol>)instance;

/**
 *  Called when the top-left button on an error page is clicked
 *  This callback is triggered when the user clicks the top-left corner button (e.g., Back button)
 *  on the error page, allowing the delegate to handle navigation or custom actions
 *  - Parameters:
 *    - instance: The WebView instance displaying the error page
 *  - Possible Values: Returns YES (delegate handled click) or NO (use default behavior)
 *  - Default Value: NO (use default behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onErrorPageTopLeftButtonClicked:(id<ZMUnifyWebViewProtocol>)instance;

/**
 *  Called when the top-right button on an error page is clicked
 *  This callback is triggered when the user clicks the top-right corner button (e.g., Close button)
 *  on the error page, allowing the delegate to handle dismissal or custom actions
 *  - Parameters:
 *    - instance: The WebView instance displaying the error page
 *  - Possible Values: Returns YES (delegate handled click) or NO (use default behavior)
 *  - Default Value: NO (use default behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onErrorPageTopRightButtonClicked:(id<ZMUnifyWebViewProtocol>)instance;

/**
 *  Called when the bottom-right button on an error page is clicked
 *  This callback is triggered when the user clicks the bottom-right corner button (e.g., Open in browser button)
 *  on the error page, allowing the delegate to handle external navigation or custom actions
 *  - Parameters:
 *    - instance: The WebView instance displaying the error page
 *  - Possible Values: Returns YES (delegate handled click) or NO (use default behavior)
 *  - Default Value: NO (use default behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onErrorPageBottomRightButtonClicked:(id<ZMUnifyWebViewProtocol>)instance;

//MARK: - Download & File Management Callbacks

/**
 *  Called before a download operation begins
 *  This callback is triggered when the WebView is about to start downloading a file,
 *  allowing the delegate to control download behavior, customize the save path, or cancel the download
 *  - Parameters:
 *    - instance: The WebView instance initiating the download
 *    - downloadParam: Parameters containing download information (URL, suggested filename)
 *  - Possible Values: Returns ZMUnifyWebViewDownloadDecision object with download handling decision
 *  - Default Value: nil (use default download behavior)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable ZMUnifyWebViewDownloadDecision*)onBeforeDownload:(id<ZMUnifyWebViewProtocol>)instance downloadParam:(nullable ZMUnifyWebViewDownloadParam*)downloadParam;

//MARK: - Meeting & Status Callbacks

/**
 *  Called to query the current meeting session status of the application
 *  This callback allows the WebView to determine the detailed meeting status for the application,
 *  enabling meeting-aware behavior such as notification suppression, performance optimization,
 *  or UI adaptations during different meeting states
 *  - Parameters:
 *    - instance: The WebView instance requesting the meeting status
 *  - Return Value: UnifyWebviewMeetingState enum indicating the current meeting status
 *  - Possible Values:
 *    - UnifyWebviewMeetingState_Unknown (-1): Meeting status cannot be determined or is in an undefined state
 *    - UnifyWebviewMeetingState_PreMeeting (0): Application is in pre-meeting state
 *    - UnifyWebviewMeetingState_InMeeting (1): Application is actively participating in a meeting session
 *  - Default Value: UnifyWebviewMeetingState_Unknown
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (enum UnifyWebviewMeetingState)onQueryInMeetingState:(id<ZMUnifyWebViewProtocol>)instance;

//MARK: - UI & Interaction Callbacks

/**
 *  Called when the WebView's loading status changes
 *  This callback is triggered whenever the WebView starts or stops loading content,
 *  allowing the delegate to update UI elements like progress indicators or loading states
 *  - Parameters:
 *    - instance: The WebView instance whose loading status changed
 *    - isLoading: YES if the WebView is currently loading content, NO if loading has stopped
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)onLoadingStatusChange:(id<ZMUnifyWebViewProtocol>)instance isloading:(BOOL)isLoading;

/**
 *  Called when the WebView requests to open a new window
 *  This callback is triggered when JavaScript calls window.open() or when links with target="_blank"
 *  are clicked, allowing the delegate to control how new windows are handled
 *  - Parameters:
 *    - instance: The WebView instance requesting the new window
 *    - windowOpenParam: Parameters for the new window including URL, size, and features
 *  - Possible Values: ZMUnifyWebViewNewWindowOpenResult object (allow, deny, or custom handling)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable ZMUnifyWebViewNewWindowOpenResult*)onWindowOpenRequested:(id<ZMUnifyWebViewProtocol>)instance windowOpenParam:(nullable ZMUnifyWebViewWindowOpenParam*)windowOpenParam;

/**
 *  Called when the WebView receives an interactive event from the user
 *  This callback is triggered when user interaction events (such as mouse or keyboard events)
 *  occur within the WebView, allowing the delegate to intercept and handle these events
 *  - Parameters:
 *    - instance: The WebView instance that received the interactive event
 *    - event: The interactive event object (NSEvent on macOS)
 *  - Possible Values: Returns YES (delegate handled event) or NO (use default behavior)
 *  - Default Value: NO (use default event handling)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onRecvWebInteractiveEvent:(id<ZMUnifyWebViewProtocol>)instance event:(nullable NSEvent*)event;

/**
 *  Called when the WebView title changed
 *  - Parameters:
 *    - title: the title of the WebView
 *  - Supported WebView Types: UnifyWebViewType_WKWebView,
 */
- (void)onTitleChanged:(NSString *)title;

//MARK: - Context Menu Callbacks

/**
 *  Called before the context menu is displayed to allow customization
 *  This callback is triggered when a context menu is about to be shown, allowing the delegate
 *  to provide custom menu items that will be added to the context menu
 *  - Parameters:
 *    - instance: The WebView instance where the context menu will be shown
 *    - menu: Context menu object containing existing menu items that will be displayed
 *  - Possible Values: Returns a ZMUnifyWebViewContextMenu object containing menu items to add
 *  - Default Value: nil (no custom menu items added)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable ZMUnifyWebViewContextMenu*)onBeforeContextMenu:(id<ZMUnifyWebViewProtocol>)instance menu:(nullable ZMUnifyWebViewContextMenu*)menu;

/**
 *  Called when a context menu item is clicked
 *  This callback is triggered when the user selects an item from the context menu,
 *  allowing the delegate to handle custom menu item actions
 *  - Parameters:
 *    - instance: The WebView instance where the context menu item was clicked
 *    - menuParams: Parameters containing the menuId of the clicked menu item
 *  - Possible Values: Returns YES (delegate handled the click) or NO (use default behavior)
 *  - Default Value: NO (use default click handling)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)onContextMenuClicked:(id<ZMUnifyWebViewProtocol>)instance menu:(nullable ZMUnifyWebViewContextMenu*)menu;

//MARK: - Local Resource Callbacks

/**
 *  Called when local zmdf file is not found and WebView requests data from UI layer
 *  This callback is triggered when the WebView attempts to load a zmdf:// resource but the
 *  corresponding local file does not exist. The delegate should asynchronously provide the
 *  file data through the completion handler.
 *  - Parameters:
 *    - instance: The WebView instance requesting the zmdf file data
 *    - url: The zmdf:// URL being requested
 *    - completionHandler: Block to call with the file data (NSData*) or nil if not available
 *  - Possible Values: Returns YES (delegate will handle and call completionHandler) or NO (use default behavior)
 *  - Default Value: NO (file not found error will be returned)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView
 */
- (BOOL)onRequestZmdfFileData:(id<ZMUnifyWebViewProtocol>)instance
                          url:(NSString*)url
            completionHandler:(void (^)(NSData* _Nullable data))completionHandler;
@end

//MARK: - V2 Main Protocol (Methods)
@protocol ZMUnifyWebViewProtocol <NSObject>

@optional

//MARK: - Configuration & Setup

/**
 *  Sets the delegate object for receiving WebView callbacks
 *  The delegate will receive various notifications about WebView lifecycle events,
 *  navigation actions, errors, and other important state changes
 *  - Parameters:
 *    - delegate: Object implementing ZMUnifyWebViewDelegate protocol to receive callbacks
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)setDelegate:(nullable id<ZMUnifyWebViewDelegate>)delegate;

/**
 *  Sets the parent view that will contain the WebView
 *  The WebView will be added as a subview to the specified parent view and will
 *  automatically resize to match the parent's bounds
 *  - Parameters:
 *    - parentView: The NSView that will contain and display the WebView
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)setParentView:(nullable NSView*)parentView;

//MARK: - Navigation & Content Loading

/**
 *  Navigates the WebView to a specified URL with optional parameters
 *  This method initiates navigation to a new URL, supporting various navigation options
 *  such as custom headers, POST data, and navigation behavior settings
 *  - Parameters:
 *    - navigatePara: Navigation parameters object containing URL, headers, and other options
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)navigate:(nullable ZMUnifyWebViewNavigatePara*)navigatePara;

/**
 *  Opens a hybrid application with the specified configuration
 *  This method launches a hybrid app within the WebView context, enabling rich
 *  native-web integration with access to both web content and native capabilities
 *  - Parameters:
 *    - appInfo: Configuration object containing hybrid app details and launch parameters
 *  - Possible Values: Returns YES (hybrid app opened successfully) or NO (operation failed)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)openHybridApp:(nullable ZMHybridAppInfo*)appInfo;

/**
 *  Retrieves the unique identifier for this WebView instance
 *  Each WebView instance has a unique GUID that can be used for tracking,
 *  logging, or coordinating between multiple WebView instances
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)getGuid;

/**
 *  Retrieves the current URL displayed in the WebView
 *  This method returns the actual URL currently loaded in the WebView,
 *  which may differ from the originally requested URL due to redirects
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)getUrl;

/**
 *  Retrieves the home URL for this WebView instance
 *  The home URL represents the initial or default URL that was set for this WebView,
 *  often used for navigation reset or reference purposes
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)getHomeUrl;

/**
 *  Retrieves the type classification of this WebView instance
 *  WebView types distinguish between different usage scenarios and capabilities,
 *  allowing for type-specific behavior and optimizations
 *  - Parameters: None
 *  - Possible Values: UnifyWebViewType enum values
 *  - Default Value: UnifyWebViewType_None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (enum UnifyWebViewType)getWebViewType;

/**
 *  Retrieves the application type for this unified WebView
 *  Application types categorize WebViews based on their intended use case,
 *  such as main content, embedded widgets, or specialized functions
 *  - Parameters: None
 *  - Possible Values: UnifyWebViewAppType enum values
 *  - Default Value: UnifyWebViewAppType_None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (enum UnifyWebViewAppType)getUnifyWebViewAppType;

/**
 *  Retrieves the underlying native window of the WebView
 *  This method returns the platform-specific window object (NSWindow* on macOS) that
 *  contains the WebView. Use this for window-level operations such as making the
 *  window key, ordering, or accessing window properties
 *  - Parameters: None
 *  - Possible Values: NSWindow* on macOS, nil if WebView is not initialized or has no window
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSWindow*)getNativeWindow;

/**
 *  Retrieves the container view that wraps the WebView
 *  This method returns the ZMUnifyWebViewContainerView that contains the actual WebView.
 *  The container view provides additional UI elements such as error views, loading indicators,
 *  and navigation controls. Use this for view-level operations such as positioning popups,
 *  adding overlays, or getting view coordinates
 *  - Parameters: None
 *  - Possible Values: NSView* (ZMUnifyWebViewContainerView), nil if WebView is not initialized
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSView*)getContainerView;

/**
 *  Refreshes the current page content in the WebView
 *  This method reloads the current page, similar to pressing the browser refresh button.
 *  All page state will be reset and the page will be loaded fresh from the server
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)refresh;

/**
 *  Retrieves the title of the webview
 *  This method returns the title of the webview
 *  - Parameters: None
 *  - Possible Values: NSString*
 *  - Default Value: @""
 *  - Supported WebView Types: UnifyWebViewType_WKWebView
 */
- (NSString*)getTitle;

//MARK: - JavaScript & Scripting

/**
 *  Executes JavaScript code in the WebView
 *  This method runs the provided JavaScript code in the context of the currently loaded page.
 *  The execution is asynchronous and runs on the main thread
 *  - Parameters:
 *    - jsCode: JavaScript code string to execute in the WebView context
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)executeJavascript:(nullable NSString*)jsCode;

//MARK: - Cookie & Session Management

/**
 *  Adds a new cookie or updates an existing cookie in the WebView
 *  This method manages HTTP cookies for the WebView, supporting various security and scope options.
 *  Cookies set through this method will be available to JavaScript and HTTP requests within the specified domain
 *  - Parameters:
 *    - name: Cookie name/key identifier
 *    - value: Cookie value to store
 *    - domain: Domain scope for the cookie (e.g., ".example.com")
 *    - path: URL path scope for the cookie (e.g., "/", "/api")
 *    - httpOnly: YES to make cookie accessible only via HTTP(S), not JavaScript
 *    - isStrictSameSite: YES to enforce strict same-site policy for enhanced security
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)addOrUpdateCookie:(nullable NSString*)name value:(nullable NSString*)value domain:(nullable NSString*)domain path:(nullable NSString*)path httpOnly:(BOOL)httpOnly isStrictSameSite:(BOOL)isStrictSameSite;

/**
 *  Deletes a specific cookie from the WebView
 *  This method removes a cookie that matches the exact name, domain, and path combination.
 *  All parameters must match the original cookie for successful deletion
 *  - Parameters:
 *    - name: Cookie name to delete
 *    - domain: Domain where the cookie was set
 *    - path: Path where the cookie was set
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)deleteCookie:(nullable NSString*)name domain:(nullable NSString*)domain path:(nullable NSString*)path;

/**
 *  Clears all cookies stored in the WebView
 *  This method removes all cookies from the WebView's cookie storage, regardless of domain or path.
 *  Use with caution as this will affect the user's login status and preferences on all websites
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)clearAllCookie;

//MARK: - File System & Security

/**
 *  Sets up ZMDF folder mapping for file access
 *  This method configures how the WebView accesses local files through a domain-based mapping system,
 *  enabling secure file access with type restrictions for enhanced security
 *  - Parameters:
 *    - domain: Domain identifier for the folder mapping
 *    - rootFolder: Local file system path to the root folder that will be accessible
 *    - constraintFileTypes: Comma-separated list of allowed file extensions (e.g., "pdf,doc,txt")
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)setZmdfFolderMap:(nullable NSString*)domain rootFolder:(nullable NSString*)rootFolder constraintFileTypes:(nullable NSString*)constraintFileTypes;

//MARK: - Media Capture & Recording

/**
 *  Starts capturing video frames from the WebView content
 *  This method begins real-time capture of the WebView's rendered content as video frames,
 *  useful for recording, streaming, or analysis purposes
 *  - Parameters:
 *    - frameRate: Target frames per second for capture (e.g., 30 for 30fps)
 *    - maxWidth: Maximum width in pixels for captured frames
 *    - maxHeight: Maximum height in pixels for captured frames
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)startCapture:(int)frameRate maxWidth:(unsigned)maxWidth maxHeight:(unsigned)maxHeight;

/**
 *  Stops the ongoing video frame capture operation
 *  This method halts any active frame capture started with startCapture, freeing associated resources
 *  - Parameters: None
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)stopCapture;

//MARK: - Network & Headers

/**
 *  Retrieves the common HTTP headers used for all network requests
 *  This method returns the default set of headers that are automatically included
 *  with all HTTP requests made by the WebView
 *  - Parameters: None
 *  - Possible Values: Dictionary containing header name-value pairs, or nil if no common headers are set
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSDictionary<NSString*, NSString*>*)getCommonRequestHeaderMap;

//MARK: - Developer Tools & Debugging

/**
 *  Enables or disables the web inspector for debugging
 *  The web inspector provides developer tools for debugging web content,
 *  including DOM inspection, console access, and network monitoring
 *  - Parameters:
 *    - isEnable: YES to enable the web inspector, NO to disable it
 *  - Possible Values: YES (enable inspector), NO (disable inspector)
 *  - Default Value: NO (inspector disabled)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)setEnableInspect:(BOOL)isEnable;

//MARK: - UI & Coordinate Utilities

/**
 *  Converts a point from WebView coordinates to screen coordinates
 *  This method transforms coordinate positions within the WebView to absolute screen positions,
 *  useful for positioning UI elements or handling cross-application interactions
 *  - Parameters:
 *    - point: Point in WebView coordinate space
 *  - Possible Values: NSPoint with valid x,y coordinates, returns corresponding screen coordinates
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (NSPoint)convertWebViewPointToScreen:(NSPoint)point;

/**
 *  Sets or removes focus on the WebView
 *  This method controls whether the WebView becomes the first responder in the responder chain.
 *  When focus is YES, the WebView will receive key events and user input focus.
 *  When focus is NO, the WebView will resign first responder status.
 *  - Parameters:
 *    - focus: YES to make the WebView the first responder, NO to resign first responder status
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)setFocus:(BOOL)focus;

/**
 *  Pastes content from the clipboard as plain text
 *  This method removes all formatting from the clipboard content and pastes it as plain text,
 *  matching the style of the destination. Equivalent to "Paste and Match Style" functionality.
 *  - Supported WebView Types: UnifyWebViewType_WKWebView
 */
- (void)pasteAsPlainText;

/**
 *  Show loading UI immediately
 *  - Supported WebView Types: UnifyWebViewType_WKWebView,  UnifyWebViewType_CEF
 */
- (void)showLoading;

/**
 *  Hide loading UI immediately
 *  - Supported WebView Types: UnifyWebViewType_WKWebView,  UnifyWebViewType_CEF
 */
- (void)hideLoading;

//MARK: - Download & File Access

/**
 *  Adds a custom button to the download interface
 *  This method allows insertion of custom UI elements into the download view,
 *  enabling additional download-related actions or custom workflows
 *  - Parameters:
 *    - para: Button configuration object containing title, action, and styling parameters
 *  - Possible Values: ZMUnifyWebViewButtonPara object with valid button configuration
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)addCustomButtonInDownloadView:(nullable ZMUnifyWebViewButtonPara*)para;

/**
 *  Configures the download view appearance with custom text and images
 *  Call this method before showing the download view to customize its UI elements
 *  All properties in the configuration object are optional - nil values will use defaults
 *  - Parameters:
 *    - para: Download view configuration object containing customizable properties
 *  - Possible Values: ZMUnifyWebViewDownloadViewPara object with custom text/images
 *  - Supported WebView Types: UnifyWebViewType_CEF
 */
- (void)configureDownloadView:(nullable ZMUnifyWebViewDownloadViewPara *)para;

/**
 *  Registers a file path with the WebView and returns a unique identifier
 *  This method creates a secure mapping between local file paths and WebView-accessible IDs,
 *  enabling controlled file access while maintaining security boundaries
 *  - Parameters:
 *    - filePath: Local file system path to register
 *    - intention: Purpose identifier for the file registration (affects access permissions)
 *  - Possible Values: Returns unique path ID string, nil if registration fails
 *  - Default Value: nil (registration failed)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)registerFilePathId:(nullable NSString*)filePath intention:(int)intention;

/**
 *  Retrieves the original file path for a registered path ID
 *  This method resolves a previously registered path ID back to its original file system path,
 *  allowing secure access to files through the ID-based mapping system
 *  - Parameters:
 *    - intention: Purpose identifier that was used during registration
 *    - pathId: Unique path ID returned from registerFilePathId
 *  - Possible Values: Returns original file system path string, or nil if ID is invalid/expired
 *  - Default Value: nil (invalid or expired ID)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)getRegisteredFilePath:(int)intention pathId:(nullable NSString*)pathId;

//MARK: - Information & Status Queries

/**
 *  Retrieves the current navigation type of the WebView
 *  Navigation types indicate how the current page was loaded (user action, redirect, etc.),
 *  providing context for navigation history and behavior decisions
 *  - Parameters: None
 *  - Possible Values: UnifyWebViewNavigationType enum values (user action, redirect, etc.)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (enum UnifyWebViewNavigationType)getNavigationType;

/**
 *  Queries whether the WebView is currently loading content
 *  This method provides the current loading status of the WebView, indicating if any
 *  navigation or resource loading operations are in progress
 *  - Parameters: None
 *  - Possible Values: YES (WebView is currently loading), NO (WebView is not loading)
 *  - Default Value: NO (not loading)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (BOOL)isLoading;

//MARK: - Error Page Display

/**
 *  Displays an error page in the WebView with the specified error type and optional parameters
 *  This method shows a standardized error page to inform users about navigation failures,
 *  loading errors, or other issues that prevent normal content display
 *  - Parameters:
 *    - errorType: The type of error from UnifyWebViewError enum that triggered the error page
 *    - param: Optional parameters containing additional error details (title, info, errorCode, errorCodeMsg)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)showErrorPage:(enum UnifyWebViewError)errorType param:(nullable ZMUnifyWebViewErrorPageParam *)param;

//MARK: - Error Page Update

/**
 *  Updates the error page configuration at runtime with partial parameters.
 *  This method allows dynamic modification of the error page content and buttons
 *  after the WebView has been initialized, without needing to recreate the WebView.
 *  Only fields with valid values will be applied (supports partial update):
 *  - Parameters:
 *    - param: Error page parameters. Only non-default values will be applied:
 *             - title, info, errorCodeMsg: Updated when length > 0
 *             - errorCode: Updated when != 0
 *             - topLeftButton, topRightButton, bottomRightButton: Updated when != nil (nil removes button)
 *             - reportWindowPreferredProductType: Updated when != NSNotFound
 *             - reportWindowPreferredIssueType: Updated when != NSNotFound
 *             - reportWindowPreferredDisplayMode: Always updated (0 is valid for Independent mode)
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (void)updateErrorPage:(nullable ZMUnifyWebViewErrorPageParam *)param;

//MARK: - Event Emission

/**
 *  Emits a hybrid event to JavaScript running in the WebView
 *  This method sends an event from native code to the web layer, allowing communication
 *  with JavaScript code listening for hybrid events. The event will be delivered to
 *  registered event listeners in the web content.
 *  - Parameters:
 *    - event: The hybrid event object containing package, event name, and optional payload
 *  - Return Value: A reply ID string that can be used to track the event, or nil if emission failed
 *  - Possible Values: Non-empty string (event emitted successfully) or nil (emission failed)
 *  - Default Value: nil
 *  - Supported WebView Types: UnifyWebViewType_WKWebView, UnifyWebViewType_CEF
 */
- (nullable NSString*)emitEvent:(nullable ZMHybridEvent*)event;

@end

//MARK: - V1 (Deprecated, please use V2 interfaces)

__attribute__((deprecated("ZMUnifyWebViewInstanceDelegate is deprecated. Please use ZMUnifyWebViewDelegate (V2) instead.")))
@protocol ZMUnifyWebViewInstanceDelegate <NSObject>

@optional

/// Invoked when call `window.close()`
/// - Parameter instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebViewDidClose:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView did decide Policy, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:decidePolicyForNavigationAction:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: url the navigation URL
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance decidePolicyForNavigationAction:(nullable NSURL *)url DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead");

/// unifyWebView decide policy for navigation action, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:decidePolicyForNavigationAction:decisionHandler:`
/// - Parameters:
///   - instance: unifyWebView
///   - navigationAction: navigationAction object
///   - decisionHandler: completion handler
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction
                decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler API_AVAILABLE(macos(10.10)) DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead");

/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
getContextMenuFromProposedMenu:(NSMenu *)menu
                    forElement:(id)element
                      userInfo:(id<NSSecureCoding>)userInfo
             completionHandler:(void (^)(NSMenu *))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse
                  decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateStart:url:decisionHandler: instead");

/// unifyWebView did start navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didStartProvisionalNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didStartNavigationWithURL:(nullable NSURL *)url DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead");

/// unifyWebView did commit navigation, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:didCommitNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didCommitNavigationWithURL:(nullable NSURL *)url DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead");

/// unifyWebView did finish navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didFinishNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didFinishNavigationWithURL:(nullable NSURL *)url DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead");

/// unifyWebView did failed navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didFailNavigation:withError:` and `unifyWebView:didFailProvisionalNavigation:withError:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
///   - error: the navigation failed error
/// @deprecated Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didFailedNavigationWithURL:(nullable NSURL *)url Error:(NSError *)error DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onNavigateFinish:url:errorCode:httpStatus: instead");

/// unifyWebView content process did terminate, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:webContentProcessDidTerminateWithReason:` or `webViewWebContentProcessDidTerminate`, for OS version before macOS 10.14,
/// - Parameters:
///   - instance: unifyWebView
///   - reason: the error code describe the reason
/// @deprecated Use ZMUnifyWebViewDelegate's onBrowserCrashed:crashType:url: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance webContentProcessDidTerminateWithReason:(ZMWebProcessTerminationReason)reason DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onBrowserCrashed:crashType:url: instead");

/// unifyWebView rendering progress did change, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:renderingProgressDidChange:` which is a private method defined in `WKNavigtionDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - progressEvents: the rendering progress which is defined in `_WKRenderingProgressEvents.h` of the `WebKit`
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance renderingProgressDidChange:(NSUInteger)progressEvents DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView request media authorization for devices, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:requestUserMediaAuthorizationForDevices:url:mainFrameURL:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - devices: microphone, camera or display
///   - url: the current URL
///   - mainFrameURL: the URL of main frame
///   - decisionHandler: the decisionHandler
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
requestUserMediaAuthorizationForDevices:(NSUInteger)devices
                                    url:(nullable NSURL *)url
                           mainFrameURL:(nullable NSURL *)mainFrameURL
                        decisionHandler:(nullable void (^)(BOOL authorized))decisionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView check user media Permission for URL, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:checkUserMediaPermissionForURL:mainFrameURL: frameIdentifier:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the current URL
///   - mainFrameURL: the URL of main frame
///   - frameIdentifier: the identity of frame
///   - decisionHandler: the decisionHandler
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
checkUserMediaPermissionForURL:(nullable NSURL *)url
                  mainFrameURL:(nullable NSURL *)mainFrameURL
               frameIdentifier:(NSUInteger)frameIdentifier
               decisionHandler:(nullable void (^)(NSString * _Nullable salt, BOOL authorized))decisionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)webViewDidReceiveForceRefreshEvent:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView loading status changed, will be invoked when the keyPath `loading` of the WKWebView in the unifyWebView container changed
/// - Parameters:
///   - instance: unifyWebView
///   - isLoading: the webView is loading or not
/// @deprecated Use ZMUnifyWebViewDelegate's onLoadingStatusChange:isloading: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance loadingStatusDidChanged:(BOOL)isLoading DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onLoadingStatusChange:isloading: instead");

/// unifyWebView URL changed, will be invoked when the keyPath `URL` of the WKWebView in the unifyWebView container changed
/// - Parameters:
///   - instance: unifyWebView
///   - oldURL: the oldURL of the webView
///   - newURL: the newURL of the webView
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance urlDidChanged:(nullable NSURL *)oldURL newURL:(nullable NSURL *)newURL DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// @deprecated Use ZMUnifyWebViewDelegate's onRecvWebMessage:message: instead
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldIgnoreScriptMessage:(WKScriptMessage *)message DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onRecvWebMessage:message: instead");

/// @deprecated Use ZMUnifyWebViewDelegate's onRecvWebMessage:message: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didReceiveCustomScriptMessage:(WKScriptMessage *)message DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onRecvWebMessage:message: instead");

/// @deprecated Use ZMUnifyWebViewDelegate instead
- (BOOL)shouldRefreshHeader:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Whether to set download delegate
/// - Parameter instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead
- (BOOL)canPreformDownload:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead");

/// unifyWebView check whether allow download file with a filename
/// - Parameters:
///   - instance: unifyWebView
///   - download: download object, WKDownload on macOS 11.3 and above, _WKDownload on macOS before 11.3
///   - fileName: file suggested name
/// @deprecated Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldAllowDownload:(id)download withFileName:(NSString *)fileName DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead");

/// unifyWebView destination folder for download
/// - Parameters:
///   - instance: unifyWebView
///   - download: download object, WKDownload on macOS 11.3 and above, _WKDownload on macOS before 11.3
///   - completionHandler: callback block with expected folder path
/// @deprecated Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance decideDestinationForDownload:(nullable id)download comletionHandler:(nullable void (^)(NSURL * _Nullable destinationFolder))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onBeforeDownload:downloadParam: instead");

/// Invoked when click the reload in WebView Context Menu
/// - Parameter instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)webViewDidClickReloadItemInContextMenu:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView check user media Permission for URL on macOS 13.0 and above, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView: requestDisplayCapturePermissionForOrigin:initiatedByFrame:withSystemAudio:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - securityOrigin: origin of this permission request
///   - frame: frame info
///   - withSystemAudio: whether share with audio
///   - decisionHandler: the decisionHandler
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance requestDisplayCapturePermissionForOrigin:(nullable WKSecurityOrigin *)securityOrigin initiatedByFrame:(nullable WKFrameInfo *)frame withSystemAudio:(BOOL)withSystemAudio decisionHandler:(nullable void (^)(ZMWebDisplayCapturePermissionDecision decision))decisionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// unifyWebView dragged by mouse event, will be invoked when drag the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse drag event
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseDraggedEvent:(NSEvent *)event DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Mouse event entered into unifyWebView,  will be invoked when enter to the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse enter event
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseEnterEvent:(NSEvent *)event DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Mouse event exited out of unifyWebView,  will be invoked when exit out of unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse exited event
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseExitedEvent:(NSEvent *)event DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Mouse event moved in unifyWebView,  will be invoked when move in the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse moved event
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseMovedEvent:(NSEvent *)event DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Mouse event up in unifyWebView,  will be invoked when click in the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse up event
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseUpEvent:(NSEvent *)event DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// Customize cursor style in unifyWebView
/// - Parameter instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)resetCursorRects:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

///  should unifywebview's decidePolicyForNavigationResponse skip owasp check
/// - Parameters:
///   - instance: unifyWebView
///   - srcURL: url
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldSkipOWASPCheck:(nullable NSURL *)srcURL DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

///   Creates a new web view.
///   - Parameters:
///   - instance: unifyWebView
///   - configuration: The configuration to use when creating the new web
///   - navigationAction: The navigation action causing the new web view to be created.
///   - windowFeatures: Window features requested by the webpage.
///   result A new web view or nil
/// @deprecated Use ZMUnifyWebViewDelegate's onWindowOpenRequested:windowOpenParam: instead
- (nullable id<ZMUnifyWebViewInstance>)unifyWebView:(id<ZMUnifyWebViewInstance>)instance createWebViewWithConfiguration:(WKWebViewConfiguration *)configuration forNavigationAction:(WKNavigationAction *)navigationAction windowFeatures:(WKWindowFeatures *)windowFeatures DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onWindowOpenRequested:windowOpenParam: instead");

///  Determine whether unifyErrorView should be displayed based on errorcode
///  - Parameters:
///  - instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate's onBeforeErrorPageShow:errorCode: instead
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldShowErrorView:(NSInteger)errorCode DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onBeforeErrorPageShow:errorCode: instead");

///  Click event of the refresh button of unifyErrorView
/// - Parameters:
///   - instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate's onErrorPageRefreshButtonClicked: instead
- (void)unifyRefreshBtnClick:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onErrorPageRefreshButtonClicked: instead");

///  Does unifyErrorView only support dark mode?
/// - Parameters:
///   - instance: unifyWebView
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (BOOL)unifyErrorViewSupportsOnlyDarkMode:(id<ZMUnifyWebViewInstance>)instance DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");

/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance fullScreenStateWillChange:(BOOL)isWillChangeToFullScreen DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");
/// @deprecated Use ZMUnifyWebViewDelegate instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance fullScreenStateDidChange:(BOOL)isDidChangeToFullScreen DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate instead");
/// @deprecated Use ZMUnifyWebViewDelegate's onResourceLoadError:httpStatus:url: instead
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance resourceLoadError:(int)httpStatus url:(NSString*)url DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewDelegate's onResourceLoadError:httpStatus:url: instead");

@end

__attribute__((deprecated("ZMUnifyWebViewInstance is deprecated. Please use ZMUnifyWebViewProtocol (V2) instead.")))
@protocol ZMUnifyWebViewInstance <NSObject>


/// Set the implementation object of the ZMUnifyWebViewInstanceDelegate protocol
/// - Parameter delegate: the implementation object of the ZMUnifyWebViewInstanceDelegate protocol
/// @deprecated Use ZMUnifyWebViewProtocol's setDelegate: instead
- (void)configDelegate:(id<ZMUnifyWebViewInstanceDelegate>)delegate DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's setDelegate: instead");

/// Load a specific URL string for self with optional request headers
/// - Parameters:
///   - urlStr: url string to be loaded
///   - headers: headers you may add in the HTTP request
/// @deprecated Use ZMUnifyWebViewProtocol's navigate: instead
- (void)loadURL:(NSString *)urlStr withRequestHeaders:(nullable NSDictionary *)headers DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's navigate: instead");

/// Load file url for self
/// - Parameters:
///   - fileString: file path string
///   - folderString: folder path string
/// @deprecated Use ZMUnifyWebViewProtocol's navigate: instead
- (void)loadFileURL:(NSString *)fileString folderPath:(NSString *)folderString DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's navigate: instead");

/// Inject javascript for self
/// - Parameters:
///   - javaScriptString: javaScriptString to be injected
///   - mainFrameOnly: main frame only or both main frame and iframes
/// @deprecated Use ZMUnifyWebViewProtocol's executeJavascript: instead
- (void)injectJavaScript:(NSString *)javaScriptString mainFrameOnly:(BOOL)mainFrameOnly DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's executeJavascript: instead");

/// Run a javascript string in self
/// - Parameters:
///   - javaScriptString: javascript string
///   - completionHandler:  the completionHandler which contains the javascript result or the error
/// @deprecated Use ZMUnifyWebViewProtocol's executeJavascript: instead
- (void)runJavaScript:(NSString *)javaScriptString completionHandler:(nullable void (^)(id, NSError *error))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's executeJavascript: instead");

/// Get the current URL string of self
/// @deprecated Use ZMUnifyWebViewProtocol's getUrl instead
- (NSString *)currentURLStr DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getUrl instead");

/// Get the webviewID string of self
/// @deprecated Use ZMUnifyWebViewProtocol's getGuid instead
- (NSString *)webViewInstanceID DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getGuid instead");

/// set a specific cookie for self
/// - Parameters:
///   - cookie: the cookie object to be setted
///   - completionHandler: completion handler
/// @deprecated Use ZMUnifyWebViewProtocol's addOrUpdateCookie:value:domain:path:httpOnly:isStrictSameSite: instead
- (void)configCookie:(NSHTTPCookie *)cookie completionHandler:(nullable void (^)(void))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's addOrUpdateCookie:value:domain:path:httpOnly:isStrictSameSite: instead");

/// Get cookies from a unifyWebView's webSiteDataStore, this is for OnZoom only and available macOS 10.13 and above
/// - Parameter completionHandler: completion handler
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)getAllCookies:(void (^)(NSArray<NSHTTPCookie *> *))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// delete a specific cookie for self
/// - Parameters:
///   - cookie: the cookie object to be delete
///   - completionHandler: completion handler
/// @deprecated Use ZMUnifyWebViewProtocol's deleteCookie:domain:path: instead
- (void)deleteCookie:(NSHTTPCookie *)cookie completionHandler:(nullable void (^)(void))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's deleteCookie:domain:path: instead");

/// Set customUserAgent
/// - Parameter customUserAgent: new value for customUserAgent
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)configCustomUserAgent:(NSString *)customUserAgent DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Set SafariUserAgent
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)configSafariUserAgent; DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Get userAgent
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSString *)getUserAgentStr DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Whether to set the background color
/// - Parameter drawsBackground: Whether to set the background color
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)enableDrawsBackground:(BOOL)drawsBackground DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Set the background color for self
/// - Parameter color: background color to be set
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)configBackgroundColor:(NSColor *)color DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Whether horizontal swipe gestures trigger backward and forward page navigation
/// - Parameter enabled: Whether horizontal swipe gestures trigger backward and forward page navigation
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)enableBackForwardNavigationGestures:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// reload the WebView
/// @deprecated Use ZMUnifyWebViewProtocol's refresh instead
- (void)reloadWebView DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's refresh instead");

/// Get the home URL string of a webView, the home URL which means loaded from the `loadURL:withRequestHeaders:` method
/// @deprecated Use ZMUnifyWebViewProtocol's getHomeUrl instead
- (NSString *)getHomeURLStr DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getHomeUrl instead");

/// Get the last loaded failed URL of self, used for refresh only
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSString *)getRefreshURLStr DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Get the webView loading status
/// @deprecated Use ZMUnifyWebViewProtocol's isLoading instead
- (BOOL)getWebViewLoadingStatus DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's isLoading instead");

/// Stop audio/video play for self
/// - Parameter completeHandler: completionHandler with the media stop script running result
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)stopMediaPlay:(nullable void (^)(id, NSError *))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Stop the loading process of self
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)stopLoadingWebView DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Whether to allow setting transparent background
/// - Parameter enabled: Whether to allow setting transparent background
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)enableDrawsTransparentBackground:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// inject service worker script for unifyWebView
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)injectServiceWorkerScriptForUnifyWebView DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// inject common script for unifyWebView
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)injectCommonScriptForUnifyWebView DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// remove all user's script
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)removeAllUserScript DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Whether to allow checking for spelling errors
/// - Parameter enable: Whether to allow checking for spelling errors
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setSpellCheckEnable:(BOOL)enable DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// clear unifywebview cache
/// - Parameter completionHandler: completion handler
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)clearUnifyWebCache:(nullable void (^)(void))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Disable disable timer throttling for self when working in background
/// - Parameter enabled: enable will make timer throttling for self working in background, default YES
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setTimersThrottlingEnabled:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Check whether a webView has sound
/// - Parameter completeHandler: completionHandler with the check sound script running result
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)checkHasSound:(nullable void (^)(BOOL, NSError *))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Set the `magnification` of  self
/// - Parameter magnification: the magbification value
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)configMagnification:(CGFloat)magnification DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Get the content size of self
/// - Parameter completeHandler: completionHandler with the get content size script running result
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)getHTMLContentSize:(nullable void (^)(id, NSError *))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// get unifywebview datastore identity
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSString *)getUnifyDataStoreIdentity DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// Take a snapshot for self available >= 10.13
/// - Parameters:
///   - snapshotWidth: the width of the snapshot want to be set
///   - completionHandler:  completionHandler after the snapshot of webview be done
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)takeSnapshot:(CGFloat)snapshotWidth completionHandler:(void (^)(NSImage * _Nullable snapshotImage, NSError * _Nullable error))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

///  get unifywebview title
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSString *)getUnifyTitleStr DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

// For Content Rules
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setAllowDomainList:(NSArray<NSString *> *)allowedDomains completeHandler:(nullable void (^)(void))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setAllowDomainList:(NSArray<NSString *> *)allowedDomains customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(nullable void (^)(void))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setLocalHostFilterDomain:(NSArray<NSString *>  *)localAllowedDomains  customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(nullable void (^)(void))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)setDisallowDomainList:(NSArray<NSString *> *)domainList completeHandler:(nullable void (^)(void))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)removeAllContentRuleList:(nullable void (^)(void))completeHandler DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)addContentRuleList:(WKContentRuleList *)contentList completeHandler:(nullable void (^)(void))completeHandler API_AVAILABLE(macos(10.13)) DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

// For Custom Handler
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)addScriptMessageHandler:(id<WKScriptMessageHandler>)scriptMessageHandler name:(NSString *)name DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)removeScriptMessageHandler:(NSString *)name DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// @deprecated Use ZMUnifyWebViewProtocol instead
- (BOOL)receiveCommonScriptMessage:(NSString *)scirptMessage DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (BOOL)receiveCommonScriptMessage:(NSString *)scirptMessage urlString:(NSString *)urlString DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol's onGetRequestHeaderMap:url: instead
- (NSDictionary *)getRequestHeader:(NSString *)urlString DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's onGetRequestHeaderMap:url: instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)notifyWebviewVisibilityChange:(BOOL)isHidden DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)checkTimeFormatChange DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSView *)getContainerViewElement DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// @deprecated Use ZMUnifyWebViewProtocol instead
- (NSData *)getLocalFileData:(NSString *)urlString DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol's setEnableInspect: instead
- (void)showInspector DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's setEnableInspect: instead");

/// @deprecated Use ZMUnifyWebViewProtocol instead
- (enum UnifyWebViewIdleRecycleType)getIdleRecycleType DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)showUnifyErrorView:(NSInteger)errorCode DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)showUnifyErrorView:(NSString*)title errorInfo:(NSString*)info errorCode:(int)errorCode DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");
/// @deprecated Use ZMUnifyWebViewProtocol instead
- (void)hideUnifyErrorViewIfNeeded DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol instead");

/// @deprecated Use ZMUnifyWebViewProtocol's registerFilePathId:intention: instead
- (NSString*)registerFilePathId:(NSString*)filePath intention:(int)intention DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's registerFilePathId:intention: instead");
/// @deprecated Use ZMUnifyWebViewProtocol's getRegisteredFilePath:pathId: instead
- (NSString*)getRegisteredFilePath:(int)intention pathId:(NSString*)pathId DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getRegisteredFilePath:pathId: instead");
/// @deprecated Use ZMUnifyWebViewProtocol's setZmdfFolderMap:rootFolder:constraintFileTypes: instead
- (void)setZmdfFolderMap:(NSString*)domain rootFolder:(NSString*)rootFolder constraintFileTypes:(NSString*)constraintFileTypes DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's setZmdfFolderMap:rootFolder:constraintFileTypes: instead");
/// @deprecated Use ZMUnifyWebViewProtocol's getNavigationType instead
- (enum UnifyWebViewNavigationType)getNavigationType DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getNavigationType instead");

/// @deprecated Use ZMUnifyWebViewProtocol's getRenderProcessIds instead
- (NSArray*)getRenderProcessIds DEPRECATED_MSG_ATTRIBUTE("Use ZMUnifyWebViewProtocol's getRenderProcessIds instead");
@end

NS_ASSUME_NONNULL_END
