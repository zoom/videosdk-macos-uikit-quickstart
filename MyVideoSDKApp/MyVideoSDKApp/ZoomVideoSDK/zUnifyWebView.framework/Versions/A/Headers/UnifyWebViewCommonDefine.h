#ifndef _UNIFYWEBVIEW_COMMON_DEFINE_H_
#define _UNIFYWEBVIEW_COMMON_DEFINE_H_

// Hybrid app index define (type: CmmInt32), https://dg01docs.zoom.us/doc/QFPzi6xeQVuWs14ofn8Icw
#define HybridAppIndex_None           -1
#define HybridAppIndex_SearchApp       0
#define HybridAppIndex_Documentview    9
#define HybridAppIndex_AICApp          18
#define HybridAppIndex_SystemApp       25
#define HybridAppIndex_LauncherApp     28
#define HybridAppIndex_Calendar        34
#define HybridAppIndex_NewChat         35
#define HybridAppIndex_CCIMobile       44
#define HybridAppIndex_Mail            46
#define HybridAppIndex_FilePickerMenu  50    // dev env local load test app
#define HybridAppIndex_AiAdoption      53
#define HybridAppIndex_WebViewPolicy   56
#define HybridAppIndex_Certification   58
#define HybridAppIndex_StudioRecording 59

#define IS_INVALID_HYBRID_APP_IDX(index) ((index) < 0)

// HybridAppInfo.extraInfo extra info key string define
// home url like: https://[app_domain]/[url_home_path]/[history_route]/index.html#[hash_route]
#define HybridAppExtraInfo_HashRoute    _T("hash_route")    //  <--> GetAppContextExTraParaType_AppResourceHashRoute
#define HybridAppExtraInfo_UrlHomePath  _T("url_home_path") //  <--> GetAppContextExTraParaType_UrlHomePath
#define HybridAppExtraInfo_HistoryRoute _T("history_route") //  <--> GetAppContextExTraParaType_AppResourceHistoryRoute
#define HybridAppExtraInfo_RegionId     _T("region_id")     //  <--> GetAppContextExTraParaType_AppResourceRegionId


#define HybridApp_Default_RegionId _T("___default_region___")

enum UnifyWebViewAppType
{
    UnifyWebViewAppType_None = 0,
    UnifyWebViewAppType_WebViewUISDK = 1,
    UnifyWebViewAppType_ReleaseNote = 2,
    UnifyWebViewAppType_UserUpgrade = 3,
    UnifyWebViewAppType_ZoomOnePro = 4,
    UnifyWebViewAppType_Poll = 5,
    UnifyWebViewAppType_CCI = 6,
    UnifyWebViewAppType_Mail = 7,
    UnifyWebViewAppType_ZoomApps = 8,
    UnifyWebViewAppType_ZoomDocs = 9,
    UnifyWebViewAppType_TeamChat = 10,
    UnifyWebViewAppType_Simulive = 11,
    UnifyWebViewAppType_Clips = 12,
    UnifyWebViewAppType_Whiteboard = 13,
    UnifyWebViewAppType_Note = 14,
    UnifyWebViewAppType_Calendar = 15,
    UnifyWebViewAppType_Scheduler = 16,
    UnifyWebViewAppType_ZoomIQ = 17,
    UnifyWebViewAppType_MeetingProfile = 18,
    UnifyWebViewAppType_WorkSpace = 19,
    UnifyWebViewAppType_ZR = 20,
    UnifyWebViewAppType_ZRC = 21,
    UnifyWebViewAppType_WorkFlow = 22,
    UnifyWebViewAppType_Hub = 23,
    UnifyWebViewAppType_SignUp = 24,
    UnifyWebViewAppType_SSOLogin = 25,
    UnifyWebViewAppType_Diagnostic = 26,
    UnifyWebViewAppType_NewFeedback = 27,
    UnifyWebViewAppType_QA = 28,
    UnifyWebViewAppType_WorkVivo = 29,
    UnifyWebViewAppType_NewChat = 30,
    UnifyWebViewAppType_SdkMeetingFeature = 31,
    UnifyWebViewAppType_WebRTCServer = 32,
    UnifyWebViewAppType_InAppPurchases = 33,
    UnifyWebViewAppType_Tasks = 34,
    UnifyWebViewAppType_FLWToday = 35,
    UnifyWebViewAppType_FLWShifts = 36,
    UnifyWebViewAppType_Surveys = 37,
    UnifyWebViewAppType_ZRCNewMeetingChat = 38,
    UnifyWebViewAppType_AIC = 39,
    UnifyWebViewAppType_Events = 40,
    UnifyWebViewAppType_F2F = 41,
    UnifyWebViewAppType_ZRCompanion = 42,
    UnifyWebViewAppType_NewSearch = 43,
    UnifyWebViewAppType_ClinicalNote = 44,
    UnifyWebViewAppType_ClinicalNotesInRecording = 45,
    UnifyWebViewAppType_ZRHelpButton = 46,
    UnifyWebViewAppType_EnhanceLogin = 47,
    UnifyWebViewAppType_EnhanceLoginAicSidePanel = 48,
    UnifyWebViewAppType_Support = 49,
    UnifyWebViewAppType_PBXCallQueue = 50,
    UnifyWebViewAppType_SmartRecognitionVideo = 51,
    UnifyWebViewAppType_HotDesk = 52,
    UnifyWebViewAppType_AiAdoption = 53,
    UnifyWebViewAppType_Videos = 54,
    UnifyWebViewAppType_ForgotPasswd = 55,
    UnifyWebViewAppType_UnifyWebView = 56,
    UnifyWebViewAppType_ThirdPartyPopupWindow = 57,
    UnifyWebViewAppType_CommonZoomPopupWindow = 58,
    UnifyWebViewAppType_SharedNavTabWebView = 59,
    UnifyWebViewAppType_BookingScheduler = 60,
    UnifyWebViewAppType_MarketplaceOAuthLogin = 61,
    UnifyWebviewAppType_CustomizedURL = 62,
    UnifyWebviewAppType_Certifications = 63,
    UnifyWebviewAppType_InClientBrowser = 64,
    UnifyWebViewAppType_PreVoiceNotes = 65,
    UnifyWebViewAppType_StudioRecording = 66,
};

enum UnifyWebViewType
{
    UnifyWebViewType_None,
    UnifyWebViewType_SystemWebView2,
    UnifyWebViewType_CEF,
    UnifyWebViewType_FixVersionWebView2,
    UnifyWebViewType_WKWebView,
    UnifyWebViewType_AndroidWebView
};

enum UnifyWebViewIdleRecycleType {
    UnifyWebViewIdleRecycleType_Default = 0,  // default
    UnifyWebViewIdleRecycleType_Enabled = 1 << 0,
    UnifyWebViewIdleRecycleType_NoResponseEnabled = 1 << 1,
    UnifyWebViewIdleRecycleType_ForceDisabled = 1 << 2,  // business forced disable, highest priority
};

enum UnifyWebViewWindowType {
    UnifyWebViewWindowType_Unknown,
    UnifyWebViewWindowType_Popup,
    UnifyWebViewWindowType_MT,
    UnifyWebViewWindowType_PT,
};

enum UnifyWebviewCrashType
{
    UnifyWebviewCrashType_None,
    UnifyWebviewCrashType_WebViewAgentCrashed,
    UnifyWebviewCrashType_ExitCodeNonZero,
    UnifyWebviewCrashType_WasKilled,
    UnifyWebviewCrashType_Crashed,
    UnifyWebviewCrashType_OutOfMemory,
    UnifyWebviewCrashType_BrowserProcessExited,
    UnifyWebviewCrashType_RenderProcessExited,
    UnifyWebviewCrashType_RenderProcessUnresponsive,
    UnifyWebviewCrashType_FrameRenderProcesExited,
    UnifyWebviewCrashType_UtilityProcessExited,
    UnifyWebviewCrashType_SandboxHelperProcessExited,
    UnifyWebviewCrashType_GpuProcessExited,
    UnifyWebviewCrashType_PpapiPluginProcessExited,
    UnifyWebviewCrashType_PpapiBrokerProcessExited,
    UnifyWebviewCrashType_UnknownProcessExited,
    UnifyWebviewCrashType_ExceededCPULimit,
    UnifyWebviewCrashType_RequestedByClient,
    UnifyWebviewCrashType_WebViewAgent_Unresponsive,
    UnifyWebviewCrashType_ExceededSharedProcessCrashLimit,
};

enum UnifyWebViewOperateState
{
    UnifyWebViewOperateState_Deny,
    UnifyWebViewOperateState_Allow,
    UnifyWebViewOperateState_Hold
};

enum UnifyWebviewMeetingState
{
    UnifyWebviewMeetingState_Unknown = -1,
    UnifyWebviewMeetingState_PreMeeting,
    UnifyWebviewMeetingState_InMeeting
};

enum UnifyWebViewError
{
    UnifyWebViewError_NoError                           = 0,
    UnifyWebViewError_ConnectError                      = 1,
    UnifyWebViewError_ServerError                       = 2,
    UnifyWebViewError_Timeout                           = 3,
    UnifyWebViewError_ServerUnreachable                 = 4,
    UnifyWebViewError_CertificateError                  = 5,
    UnifyWebViewError_OperationCanceled                 = 6,
    UnifyWebViewError_AuthenticationFail                = 7,
    UnifyWebViewError_RedirectFail                      = 8,
    UnifyWebViewError_DnsError                          = 9,
    UnifyWebViewError_ExceededLimit                     = 10,
    UnifyWebViewError_UnRegisterModule                  = 11,
    UnifyWebViewError_Unknown                           = 12,
    UnifyWebViewError_ConnectRefused                    = 13,
    UnifyWebViewError_WebViewVersionTooLow              = 14,
    UnifyWebViewError_ResourceError                     = 15,
    UnifyWebViewError_UrlError                          = 16,
    UnifyWebViewError_FilePermissionsError              = 17,
    UnifyWebViewError_DecodeError                       = 18,
    UnifyWebViewError_CacheWriteFailure                 = 19,
    UnifyWebViewError_CacheReadFailure                  = 20,
    UnifyWebViewError_CheckUrlFailed                    = 21,
    UnifyWebViewError_PermissionDenied                  = 22,
    UnifyWebViewError_ResourceUnavailable               = 23,
    UnifyWebViewError_DataError                         = 24,
    UnifyWebViewError_WebviewUnsupport                  = 25,
    UnifyWebViewError_WebviewDisable                    = 26,
    UnifyWebViewError_PageShowBlank                     = 27,
    UnifyWebViewError_JsUnanswered                      = 28,
    UnifyWebViewError_HugeMemoryUsage                   = 29,
    UnifyWebViewError_SystemUnsupportCEF                = 30,
    UnifyWebViewError_WebViewEngineDownloadFailed       = 31,
    UnifyWebViewError_TypeIllegal                       = 32,
    UnifyWebViewError_RecordNotFound                    = 33,
    UnifyWebViewError_CEFPluginNotExist                 = 34,
    UnifyWebViewError_RenderProcessUnresponsive         = 35,
    UnifyWebViewError_RenderProcessTerminated           = 36,
    UnifyWebViewError_WebView2RuntimeOutDated           = 37,
    UnifyWebViewError_WebViewCreateFailed               = 38,
    UnifyWebViewError_WebViewEngineLoadTimeout          = 39,
    UnifyWebViewError_WebViewCreateTimeout              = 40,
    UnifyWebViewError_NavigateTimeout                   = 41,
    UnifyWebViewError_ComposeResultCancelled            = 42,
    UnifyWebViewError_ComposeResultSaved                = 43,
    UnifyWebViewError_ComposeResultSent                 = 44,
    UnifyWebViewError_ComposeResultFailed               = 45,
    UnifyWebViewError_BrowserProcessCrashed             = 46,
    UnifyWebViewError_AgentProcessCrashed               = 47,
    UnifyWebViewError_LocalLoadUnzipFailed              = 48,
    UnifyWebViewError_WebViewEngineLoadFailed           = 49,
    UnifyWebViewError_WebViewRestoreFailed              = 50,
    UnifyWebViewError_UrlCancelled                      = 51,
    UnifyWebViewError_NavigationCanceledForDownload     = 52,
    UnifyWebViewError_RecoveryFailed                    = 53,
    UnifyWebViewError_NavigationStaysInvalid            = 54,
    UnifyWebViewError_OpenAppFailed                     = 55,
};

enum UnifyWebViewWarning
{
    UnifyWebViewWarning_NoWarning                       = 0,
    UnifyWebViewWarning_ResourceFailed                  = 1 << 0,
    UnifyWebViewWarning_JavascriptError                 = 1 << 1,
    UnifyWebViewWarning_GpuCrashed                      = 1 << 2,
    UnifyWebViewWarning_AboutBlank                      = 1 << 3,
    UnifyWebViewWarning_HttpAuthFailed                  = 1 << 4,
    UnifyWebViewWarning_JsMessageIpcFailed              = 1 << 5,
    UnifyWebViewWarning_DiskSpaceLow                    = 1 << 6,
    UnifyWebViewWarning_CpuOveruse                      = 1 << 7,
    UnifyWebViewWarning_LowPower                        = 1 << 8,
    UnifyWebViewWarning_HugeMemoryUsage                 = 1 << 9,
    UnifyWebViewWarning_SharedProcessCrashOverLimit     = 1 << 10,
};

enum UnifyWebviewHybridAppError
{
    UnifyWebviewHybridAppError_None                        = 7000,
    UnifyWebviewHybridAppError_DownloadPkgFailed           = 7001,
    UnifyWebviewHybridAppError_DownloadRequestFailed       = 7002,
    UnifyWebviewHybridAppError_LoadLocalPathFailed         = 7003,
    UnifyWebviewHybridAppError_RecheckAfterDownloadFailed  = 7004,
    UnifyWebviewHybridAppError_NoRemoteCdnUrl              = 7005,
    UnifyWebviewHybridAppError_NotUseLocalResource         = 7006,
    UnifyWebviewHybridAppError_DownloadPkgTimeout          = 7007,
    UnifyWebviewHybridAppError_AppDisabled                 = 7008,
};

enum UnifyWebviewAPMError
{
    UnifyWebviewAPMError_ConnectAgentTimeout,
    UnifyWebviewAPMError_ApiVerificationFailed,
    UnifyWebviewAPMError_CreateBrowserFailed,
    UnifyWebviewAPMError_CreateAgentProcessFailed,
    UnifyWebviewAPMError_NavigationTimeout,
};

enum UnifyWebViewPermissionState
{
    UnifyWebViewPermissionState_Default = 0,
    UnifyWebViewPermissionState_Allow,
    UnifyWebViewPermissionState_Deny
};

enum UnifyWebViewBlankCheckResult
{
    OperationNotCompleted = 0,
    Invisible,
    Blank,
    Normal,
};

enum UnifyWebViewBlankCheckType
{
    WindowShot     = 1,
    ViewShot       = 2,
    Api            = 4,
}; 

enum UnifyWebViewBlankCheckReason
{
    BlankCheckReason_Default = 0,
    BlankCheckReason_AppWillEnterForeGround,
};

enum UnifyWebViewProcessType
{
    WebViewProcessType_Unknown = 0,
    WebViewProcessType_Browser = 1,
    WebViewProcessType_Renderer = 2,
    WebViewProcessType_GPU = 3,
    WebViewProcessType_Utility = 4,
    WebViewProcessType_Zygote = 5,
    WebViewProcessType_SandboxHelper = 6,
    WebViewProcessType_PPAPIPlugin = 7,
    WebViewProcessType_PPAPIBroker = 8,
};

// For iOS, default load type is REMOTE_CDN_URL
// for other platform, when local LOCAL_PKG failed will fallback to REMOTE_CDN_URL unless needFallbackToCDN set to false
enum HybridAppLoadType
{
    NONE,
    LOCAL_PKG,
    REMOTE_CDN_URL,
};

enum UnifyWebViewNewWindowOpenResultCode
{
    ResultCodeNone = 0,
    OpenUrlInSystemBrowser,
    PopNewWindow,
    Ignore,
    PopCommonWindow,
};

enum UnifyWebViewNavigationType {
    NavigationType_Unknown = 0,
    NavigationType_Others,
    NavigationType_Reload_API,
    NavigationType_Reload_Script,
    NavigationType_BackOrForward,
    NavigationType_API,
    NavigationType_Script,
    NavigationType_Redirect,
    NavigationType_LinkActivated,
};

enum UnifyWebViewZAppState
{
    UnifyWebViewZAppState_Initial                               = 0,
    UnifyWebViewZAppState_InstCreated                           = 1,
    UnifyWebViewZAppState_LocalInstCreated                      = 2,
    UnifyWebViewZAppState_LocalDownloadingPkg                   = 3,
    UnifyWebViewZAppState_LocalDownloadFailed                   = 4,
    UnifyWebViewZAppState_LocalDownloadTimeout                  = 5,
    UnifyWebViewZAppState_LocalPkgHashMismatch                  = 6,
    UnifyWebViewZAppState_LocalPkgReady                         = 7,
    UnifyWebViewZAppState_LocalPkgLoaded                        = 8,
    UnifyWebViewZAppState_LocalPkgLoadFailed                    = 9,
    UnifyWebViewZAppState_LocalCdnUrlLoaded                     = 10, // 0xa
    UnifyWebViewZAppState_MpGettingAppContext                   = 11, // 0xb
    UnifyWebViewZAppState_MpGetAppContextFailed                 = 12, // 0xc
    UnifyWebViewZAppState_MpHomeUrlLoaded                       = 13, // 0xd
};

enum UnifyWebViewLifecycleState
{
    UnifyWebViewLifecycleState_Initial                          = 0,
    UnifyWebViewLifecycleState_EngineDownloading                = 1,
    UnifyWebViewLifecycleState_EngineDownloadFailed             = 2,
    UnifyWebViewLifecycleState_EngineDownloaded                 = 3,
    UnifyWebViewLifecycleState_EngineAvailabled                 = 4,
    UnifyWebViewLifecycleState_EngineLoaded                     = 5,
    UnifyWebViewLifecycleState_EngineLoadFailed                 = 6,
    UnifyWebViewLifecycleState_Creating                         = 7,
    UnifyWebViewLifecycleState_CreateFailed                     = 8,
    UnifyWebViewLifecycleState_CreateTimeout                    = 9,
    UnifyWebViewLifecycleState_Ready                            = 10, // 0xa
    UnifyWebViewLifecycleState_Recycling                        = 11, // 0xb
    UnifyWebViewLifecycleState_Recycled                         = 12, // 0xc
    UnifyWebViewLifecycleState_Restoring                        = 13, // 0xd
    UnifyWebViewLifecycleState_RestoreTimeout                   = 14, // 0xe
    UnifyWebViewLifecycleState_Closing                          = 15, // 0xf
};

enum UnifyWebViewNavigationState
{
    UnifyWebViewNavigationState_Initial                         = 0,
    UnifyWebViewNavigationState_Started                         = 1,
    UnifyWebViewNavigationState_Redirecting                     = 2,
    UnifyWebViewNavigationState_Fetching                        = 3,
    UnifyWebViewNavigationState_DOMContentLoaded                = 4,
    UnifyWebViewNavigationState_Canceled                        = 5,
    UnifyWebViewNavigationState_Finished                        = 6,
    UnifyWebViewNavigationState_Error                           = 7,
    UnifyWebViewNavigationState_Timeout                         = 8,
};

enum UnifyWebviewDownloadType {
    UnifyWebviewDownloadType_None = 0,
    UnifyWebviewDownloadType_Cancel = 1,
    UnifyWebviewDownloadType_ShowDialog = 2,
    UnifyWebviewDownloadType_SystemDownloadPath = 3
};

enum UnifyWebViewEventBusTopic
{
    UnifyWebViewEventBusTopic_CollectProcessInfo    = 101,
    UnifyWebViewEventBusTopic_PolicyCheckRequest    = 102,
    UnifyWebViewEventBusTopic_PolicyCheckResponse   = 103,
    UnifyWebViewEventBusTopic_PolicyDebugNotify     = 104,
};

#endif
