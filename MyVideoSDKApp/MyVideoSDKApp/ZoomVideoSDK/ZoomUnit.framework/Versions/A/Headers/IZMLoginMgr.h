//
//  IZMLoginMgr.h
//  ZoomUnit
//
//  Created by davies zhao on 2023/5/5.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef __cplusplus
#import <zPTApp/SaasBeePTAppInterface.h>
#import <events/MetricsScenario_enum.h>
#endif

NS_ASSUME_NONNULL_BEGIN

#define kZMLogin_SignUp_Source_SignInPage @"sign_in_page"
#define kZMLogin_SignUp_Source_WelcomePage @"welcome_page"

typedef NS_ENUM(NSUInteger, EnforceLoginErrorType) {
    Enforce_Login_Error_Type_Normal = 0,
    Enforce_Login_Error_Type_To_Government,
    Enforce_Login_Error_Type_To_Commercial,
};

@class ZMThirdPartLoginModel;
@class ZMDeepLinkParams, PZMToastCoordinator;
@class ZMTabItem;
@protocol IZMLoginMgr <ZMRoutableObject>

- (void)initModule;
//window
@property (nullable, strong, readonly) NSWindow *window;
- (BOOL)isWindowLoaded;
- (void)showWindow:(nullable id)sender;
- (void)showWindowAndSwitchToLoginPage;
- (void)showWindowAlertView:(nullable NSView *)view;
- (void)close;

@property (assign, readonly) BOOL isLogin;
- (BOOL)isInLoadingStatus;
- (BOOL)isInLoginProgress;

@property (nonatomic, strong) PZMToastCoordinator *toastCoordinator;
@property (nonatomic, assign) EnforceLoginErrorType showGovInfo;
@property (nonatomic, assign) BOOL isSignedUpLoginUser;

// Set when login and a join/start-meeting flow run in parallel; consumed by
// PT main window to avoid covering the meeting window after didLogin.
@property (nonatomic, assign) BOOL meetingActiveDuringLogin;

- (void)switchToLoginMethodsTab;
- (void)switchToSignUpTabWithSource:(nullable NSString *)source;
- (void)switchToLoginTabForZapp;
- (void)switchToBirthdayTab;

- (void)switchVanityUrl;

- (void)showRestrictedLoginDomainAlert;
- (void)showWebStartMeetingRestrictedDomainAlert;

//ZOOM-68190
- (void)showLoginUIWithSnsType:(NSInteger)snsType userName:(nullable NSString *)userName checkLoginStatue:(BOOL)checkLoginStatue;

- (void)resetAutoLogoutType:(BOOL)needDelay;
- (void)performLoginAction;

- (void)onConnectRetrurn:(NSInteger)err;

- (void)showSignToJoinOptionWindowWithLinkUrl:(nullable NSString *)detailLinkUrl couldSkip:(BOOL)couldSkip accountName:(nullable NSString *)accountNameString emailDomain:(nullable NSString *)emailDomainString;//ZOOM-114845
- (void)showLoginDialogWithPrefillEmail:(nullable NSString *)prefillEmail;//ZOOM-114845
- (void)webLaunchedToLoginWithType:(NSInteger)loginType ssoUrl:(nullable NSString *)ssoUrl ssoPrefix:(nullable NSString *)ssoPrefix ssoPostfix:(nullable NSString *)ssoPostfix domain:(nullable NSString *)domain;
- (void)onShowLoginDisclaimerDialogWithLanguage:(nullable NSString *)language title:(nullable NSString *)title description:(nullable NSString *)description linkUrl:(nullable NSString *)linkUrl linkText:(nullable NSString *)linkText;
- (void)onShowPasswordExpiredDialog:(nullable NSString *)passwordUrl;
- (void)showOTPChangePasswordAlertView:(nullable NSString *)url;
- (void)onOtpNotificationConfirmResponse:(NSInteger)result;

- (void)showReportProblemWindow;
- (void)resetReportProblemEmailString:(nullable NSString *)tipString;

//sign out
- (void)signOutWithContext:(id<ZMSignOutModel>)context;

- (void)onReachabilityFlagsChanged:(BOOL)reachable ipAddress:(NSString*)ip;

#ifdef __cplusplus
- (void)showMFAWithData:(const NS_ZWEBSERVICE::MultiFactorAuth&)mfa;
- (void)showIDPLoadingView:(ISBPTAppSink::GetSecurityParamsStatus)status;
- (void)notifyIDPSSOAction:(SB_webservice::IDPSSOActionParam)param;
- (void)showOTPLoginAlertView:(const SB_webservice::OtpNotificationInfo) info;

- (void)onOAuthReturn:(const OAuthInfo&)info;
- (void)onPKCEFacebookAuthReturn:(const CString&)encryptToken codeVerifier:(const CString&)codeVerifier expiresIn:(CmmUInt32)expiresIn error:(CmmInt32)error errorStr:(const CString&)errorStr;
- (void)onPKCEGoogleAuthReturn:(const CString&)encryptToken codeVerifier:(const CString&)codeVerifier error:(CmmInt32)error errorStr:(const CString&)errorStr;
- (void)onPKCESSOLoginTokenReturn:(const CString&)encryptToken codeVerifier:(const CString&)codeVerifier;
#pragma mark - sign in Scenario
- (void)startTrackSignInScenario:(e_MetricsScenario_step_name)stepName andScenarioLocation:(e_MetricsScenario_scenario_location)scenarioLocation;
- (void)addStepToTrackSignInScenario:(e_MetricsScenario_step_name)stepName andScenarioLocation:(e_MetricsScenario_scenario_location)scenarioLocation;
- (void)endTrackSignInScenario:(e_MetricsScenario_step_name)stepName andScenarioLocation:(e_MetricsScenario_scenario_location)scenarioLocation;

#endif
- (void)sinkQuerySSOVanityURL:(NSString *)reqID result:(int)result url:(NSString *)url;
@end

@protocol ZMLoginEventProtocol <NSObject>
@optional
- (void)loginTabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)workspaceListUpdated;
- (void)onSelectTabItemChanged:(ZMTabItem *)tabItem;
@end

NS_ASSUME_NONNULL_END
