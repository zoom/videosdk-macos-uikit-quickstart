//
//  ZMSecurityMgr.h
//  zChatUI
//
//  Created by john on 2018/6/11.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef __cplusplus
#import <webService/SBWebServiceInterface.h>
#endif
@class ZMCertificateViewer;

NS_ASSUME_NONNULL_BEGIN

@interface ZMSecurityMgr : NSObject

@property (nonatomic, strong) ZMCertificateViewer *certificateViewer;
@property (nonatomic, copy, nullable) BOOL(^isShowCertViewerHandleGetter)(void);
@property (nonatomic, copy, nullable) void(^isShowCertViewerHandleSetter)(BOOL value);
@property (nonatomic, copy, nullable) void(^trustAnywayHandler)(void);

+ (instancetype)sharedInstance;
#ifdef __cplusplus
- (void)showSecurityCertAlertWithEvent:(const NS_ZWEBSERVICE::VerifyCertEvent&)inEvent;
- (void)showSecurityInDiagnoseCertAlertWithEvent:(const NS_ZWEBSERVICE::VerifyCertEvent&)inEvent;
- (void)showSecurityCertBlockAlertWithWithEvent:(const NS_ZWEBSERVICE::VerifyCertEvent&)inEvent;
#endif

- (void)onTrust;
- (void)onNotTrust;
@end

NS_ASSUME_NONNULL_END
