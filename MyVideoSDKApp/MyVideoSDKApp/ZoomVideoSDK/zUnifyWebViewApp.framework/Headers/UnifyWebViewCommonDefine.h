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
#define HybridAppIndex_Phone           60
#define HybridAppIndex_NewHomePage     62
#define HybridAppIndex_MeetingApp      63
#define HybridAppIndex_PhoneAICW       66
#define HybridAppIndex_ActivityCenter  67
#define HybridAppIndex_OfflineNotes    69
#define HybridAppIndex_Contacts        73
#define HybridAppIndex_ZoomRNBundleIOS     74
#define HybridAppIndex_ZoomRNBundleAndroid 76


#define HybridAppIndex_SearchApp_SubAppType    9999  // only for search app's sub app type, used for APM data collection

#define IS_INVALID_HYBRID_APP_IDX(index) ((index) < 0)

// HybridAppInfo.extraInfo extra info key string define
// home url like: https://[app_local_domain]/[url_home_path] or https://[app_local_domain]/index.html[hash_route]
#define HybridAppExtraInfo_HashRoute    "hash_route"    //  <--> GetAppContextExTraParaType_AppResourceHashRoute
#define HybridAppExtraInfo_UrlHomePath  "url_home_path" //  <--> GetAppContextExTraParaType_UrlHomePath
#define HybridAppExtraInfo_HistoryRoute "history_route" //  <--> GetAppContextExTraParaType_AppResourceHistoryRoute
#define HybridAppExtraInfo_RegionId     "region_id"     //  <--> GetAppContextExTraParaType_AppResourceRegionId
#define HybridAppExtraInfo_DeeplinkUrl  "deeplink_url"  // open app with this url directly; higher priority than other path extras


#define HybridApp_Default_RegionId "___default_region___"

#define UnifyWebView_WindowOpenDialogIdQueryKey _T("zm_dialogId")

#define FeatureName_ReleaseNote           _T("ReleaseNote")
#define FeatureName_UserUpgrade           _T("UserUpgrade")
#define FeatureName_ZoomOnePro            _T("ZoomOnePro")
#define FeatureName_Poll                  _T("Poll")
#define FeatureName_CCI                   _T("CCI")
#define FeatureName_Mail                  _T("Mail")
#define FeatureName_ZoomApps              _T("ZoomApps")
#define FeatureName_ZoomDocs              _T("ZoomDocs")
#define FeatureName_TeamChat              _T("TeamChat")
#define FeatureName_Clips                 _T("Clips")
#define FeatureName_Whiteboard            _T("Whiteboard")
#define FeatureName_Note                  _T("Note")
#define FeatureName_Calendar              _T("Calendar")
#define FeatureName_Scheduler             _T("Scheduler")
#define FeatureName_ZoomIQ                _T("ZoomIQ")
#define FeatureName_MeetingProfile        _T("MeetingProfile")
#define FeatureName_WorkSpace             _T("WorkSpace")
#define FeatureName_ZR                    _T("ZR")
#define FeatureName_ZRC                   _T("ZRC")
#define FeatureName_WorkFlow              _T("WorkFlow")
#define FeatureName_Hub                   _T("Hub")
#define FeatureName_SignUp                _T("SignUp")
#define FeatureName_SSOLogin              _T("SSOLogin")
#define FeatureName_Diagnostic            _T("Diagnostic")
#define FeatureName_NewFeedback           _T("NewFeedback")
#define FeatureName_QA                    _T("QA")
#define FeatureName_WorkVivo              _T("WorkVivo")
#define FeatureName_NewChat               _T("NewChat")
#define FeatureName_SdkMeetingFeature     _T("SdkMeetingFeature")
#define FeatureName_WebRTCServer          _T("WebRTCServer")
#define FeatureName_InAppPurchases        _T("InAppPurchases")
#define FeatureName_Billing               _T("Billing")
#define FeatureName_Tasks                 _T("Tasks")
#define FeatureName_FLWToday              _T("FLWToday")
#define FeatureName_FLWShifts             _T("FLWShifts")
#define FeatureName_Surveys               _T("surveys")
#define FeatureName_ZRCNewMeetingChat     _T("ZRCNewMeetingChat")
#define FeatureName_AIC                   _T("AIC")
#define FeatureName_Events                _T("Events")
#define FeatureName_F2F                   _T("F2F")
#define FeatureName_ZRCompanion           _T("ZRCompanion")
#define FeatureName_NewSearch             _T("NewSearch")
#define FeatureName_ClinicalNote          _T("ClinicalNote")
#define FeatureName_ClinicalNotesInRecording    _T("ClinicalNotesInRecording")
#define FeatureName_ZRHelpButton          _T("ZRHelpButton")
#define FeatureName_EnhanceLogin          _T("EnhanceLogin")
#define FeatureName_EnhanceLoginAicSidePanel    _T("EnhanceLoginAicSidePanel")
#define FeatureName_Support               _T("Support")
#define FeatureName_PBXCallQueue          _T("PBXCallQueue")
#define FeatureName_SmartRecognitionVideo _T("SmartRecognitionVideo")
#define FeatureName_HotDesk               _T("HotDesk")
#define FeatureName_AiAdoption            _T("AiAdoption")
#define FeatureName_Videos                _T("Videos")
#define FeatureName_ForgotPasswd          _T("ForgotPasswd")
#define FeatureName_UnifyWebView          _T("UnifyWebView")
#define FeatureName_MarketplaceOAuthLogin _T("MarketplaceOAuthLogin")
#define FeatureName_ThirdPartyPopup       _T("ThirdPartyPopup")
#define FeatureName_CommonZoomPopup       _T("CommonZoomPopup")
#define FeatureName_SharedNavTabWebView   _T("SharedNavTabWebView")
#define FeatureName_BookingScheduler      _T("BookingScheduler")
#define FeatureName_CustomizedURL         _T("CustomizedURL")
#define FeatureName_Certifications        _T("Certifications")
#define FeatureName_InClientBrowser       _T("InClientBrowser")
#define FeatureName_PreVoiceNotes         _T("PreVoiceNotes")
#define FeatureName_StudioRecording       _T("StudioRecording")
#define FeatureName_PhoneMediaDiagnostic  _T("PhoneMediaDiagnostic")
#define FeatureName_PhoneWebClient        _T("PhoneWebClient")
#define FeatureName_PhonePriority         _T("PhonePriority")
#define FeatureName_DocumentPreview       _T("DocumentPreview")
#define FeatureName_Contacts              _T("Contacts")
#define FeatureName_NewHomePage           _T("NewHomePage")
#define FeatureName_ClipsCreateAvatar     _T("ClipsCreateAvatar")
#define FeatureName_CallSummary           _T("CallSummary")
#define FeatureName_FaxDocumentPreview    _T("FaxDocumentPreview")
#define FeatureName_MyNotes               _T("MyNotes")
#define FeatureName_PhoneAnalytics        _T("PhoneAnalytics")
#define FeatureName_ActivityCenter        _T("ActivityCenter")
#define FeatureName_PhoneOnboarding       _T("PhoneOnboarding")
#define FeatureName_HomeAIC3Panel         _T("HomeAIC3Panel")
#define FeatureName_PhonePurchase         _T("PhonePurchase")
#define FeatureName_PhoneMessageShaft     _T("PhoneMessageShaft")
#define FeatureName_PhoneCallQueueManager _T("PhoneCallQueueManager")
#define FeatureName_CalendarSidebar       _T("CalendarSidebar")
#define FeatureName_CalendarEventCard     _T("CalendarEventCard")
#define FeatureName_ClinicalNoteTab       _T("ClinicalNoteTab")
#define FeatureName_PhoneWhatsAppTemplate _T("PhoneWhatsAppTemplate")
#define FeatureName_RTMP                  _T("RTMP")
#define FeatureName_SideCar               _T("SideCar")
#define FeatureName_MediaStream           _T("MediaStream")
#define FeatureName_FilePicker            _T("FilePicker")
#define FeatureName_PSL                   _T("PSL")
#define FeatureName_WebSurvey             _T("WebSurvey")
#define FeatureName_AICredit              _T("AICredit")
#define FeatureName_OnlineBusiness        _T("OnlineBusiness")
#define FeatureName_AiAssist              _T("AiAssist")
#define FeatureName_PhoneSMSAutoReply     _T("PhoneSMSAutoReply")
#define FeatureName_PreCreateWebview      _T("PreCreateWebview")
#define FeatureName_ZRKiosk               _T("ZRKiosk")
#define FeatureName_MeetingAIC3           _T("MeetingAIC3")

enum UnifyWebViewAppType
{
    UnifyWebViewAppType_None = 0,
    UnifyWebViewAppType_WebViewUISDK = 1,//will be deprecated
    UnifyWebViewAppType_ReleaseNote = 2,
    UnifyWebViewAppType_UserUpgrade = 3,
    UnifyWebViewAppType_ZoomOnePro = 4,
    UnifyWebViewAppType_Poll = 5,
    UnifyWebViewAppType_CCI = 6,
    UnifyWebViewAppType_Mail = 7,
    UnifyWebViewAppType_ZoomApps = 8,
    UnifyWebViewAppType_ZoomDocs = 9,
    UnifyWebViewAppType_TeamChat = 10,
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
    UnifyWebViewAppType_UnifyWebView = 56,//will be deprecated
    UnifyWebViewAppType_ThirdPartyPopupWindow = 57,
    UnifyWebViewAppType_CommonZoomPopupWindow = 58,
    UnifyWebViewAppType_SharedNavTabWebView = 59,
    UnifyWebViewAppType_BookingScheduler = 60,
    UnifyWebViewAppType_MarketplaceOAuthLogin = 61,
    UnifyWebviewAppType_CustomizedURL = 62,//UnifyWebView tab for local test
    UnifyWebviewAppType_Certifications = 63,
    UnifyWebviewAppType_InClientBrowser = 64,
    UnifyWebViewAppType_PreVoiceNotes = 65,
    UnifyWebViewAppType_StudioRecording = 66,
    UnifyWebViewAppType_PhoneMediaDiagnostic = 67,
    UnifyWebViewAppType_PhoneWebClient = 68,
    UnifyWebViewAppType_DocumentPreview = 69,
    UnifyWebViewAppType_Contacts = 70,
    UnifyWebViewAppType_NewHomePage = 71,
    UnifyWebViewAppType_ClipsCreateAvatar = 72,
    UnifyWebViewAppType_CallSummary = 73,
    UnifyWebViewAppType_FaxDocumentPreview = 74,
    UnifyWebViewAppType_MyNotes = 75,
    UnifyWebViewAppType_PhoneAnalytics = 76,
    UnifyWebViewAppType_ActivityCenter = 77,
    UnifyWebViewAppType_PhonePriority = 78,
    UnifyWebViewAppType_PhoneOnboarding = 79,
    UnifyWebViewAppType_HomeAIC3Panel = 80,
    UnifyWebViewAppType_PhonePurchase = 81,
    UnifyWebViewAppType_PhoneMessageShaft = 82,
    UnifyWebViewAppType_CalendarSidebar = 83,
    UnifyWebViewAppType_CalendarEventCard = 84,
    UnifyWebViewAppType_ClinicalNoteTab = 85,
    UnifyWebViewAppType_PhoneWhatsAppTemplate = 86,
    UnifyWebViewAppType_PSL = 87,
    UnifyWebViewAppType_Billing = 88,
    UnifyWebViewAppType_WebSurvey = 89,
    UnifyWebViewAppType_AICredit = 90,
    UnifyWebViewAppType_OnlineBusiness = 91,
    UnifyWebViewAppType_AiAssist = 92,
    UnifyWebViewAppType_PhoneCallQueueManager = 93,
    UnifyWebViewAppType_PhoneSMSAutoReply = 94,
    UnifyWebViewAppType_PreCreate = 95,
    UnifyWebViewAppType_ZRKiosk = 96,
    UnifyWebViewAppType_MeetingAIC3 = 97,
    UnifyWebViewAppType_Max,  // sentinel: keep last, used for range validation
};

typedef int UnifyWebViewAppSubType;

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
    UnifyWebViewError_CreateBlockedByLoginGate          = 56,
    UnifyWebViewError_GpuProcessUnusable                = 57,
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
    UnifyWebviewHybridAppError_NoError                     = 0,
    UnifyWebviewHybridAppError_Unknown                     = 7000,
    UnifyWebviewHybridAppError_DownloadPkgFailed           = 7001,
    UnifyWebviewHybridAppError_DownloadRequestFailed       = 7002,
    UnifyWebviewHybridAppError_LoadLocalPathFailed         = 7003,
    UnifyWebviewHybridAppError_RecheckAfterDownloadFailed  = 7004,
    UnifyWebviewHybridAppError_NoRemoteCdnUrl              = 7005,
    UnifyWebviewHybridAppError_NotUseLocalResource         = 7006,
    UnifyWebviewHybridAppError_DownloadPkgTimeout          = 7007,
    UnifyWebviewHybridAppError_AppDisabled                 = 7008,
    UnifyWebviewHybridAppError_LoadBundleFailed            = 7009,
    UnifyWebviewHybridAppError_UseBuiltInPackage           = 7010,
};

enum UnifyWebviewAPMError
{
    UnifyWebviewAPMError_ConnectAgentTimeout,
    UnifyWebviewAPMError_ApiVerificationFailed,
    UnifyWebviewAPMError_CreateBrowserFailed,
    UnifyWebviewAPMError_CreateAgentProcessFailed,
    UnifyWebviewAPMError_NavigationTimeout,
    UnifyWebviewAPMError_TaskSyncException,
    UnifyWebviewAPMError_ZipLoadFailed,
    UnifyWebviewAPMError_NetConnectionError,
    UnifyWebviewAPMError_HighMemoryRecycle,
    UnifyWebviewAPMError_HybridAPIError,
};

enum UnifyWebViewPermissionType
{
    UnifyWebViewPermissionType_Unknown = 0,
    UnifyWebViewPermissionType_Microphone,
    UnifyWebViewPermissionType_Camera,
    UnifyWebViewPermissionType_Location,
    UnifyWebViewPermissionType_ShareScreen,
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

enum DialogWindowLevel {
    DialogWindowLevel_Default = 0,
    DialogWindowLevel_Floating,
};

enum UnifyWebViewEventBusTopic
{
    UnifyWebViewEventBusTopic_CollectProcessInfo    = 101,
    
    UnifyWebViewEventBusTopic_PublicMax             = 200, //don't add topic id after this type
};

#endif
