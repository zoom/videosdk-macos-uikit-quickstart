//
//  ZMCertificateViewer.h
//  SaasBeePTUIModule
//
//  Created by Huxley on 3/25/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#ifdef __cplusplus
#import <webService/SBWebServiceInterface.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ZMCertificateViewer : NSWindowController

@property (nonatomic, copy, nullable) void(^certTestHandler)(NSString *requestUrl);
@property (nonatomic, copy, nullable) BOOL(^shouldShowCertTestButton)(void);
@property (nonatomic, copy, nullable) BOOL(^isShowCertViewerHandle)(void);
@property (nonatomic, copy, nullable) void(^setShowCertViewerHandle)(BOOL value);

- (void)showWithItem:(NS_ZOOM_DATA::ZoomCertItem)item requestUrl:(NSString *)requstUrl;

- (void)updateCertTestButtonStatus;

@end

NS_ASSUME_NONNULL_END
