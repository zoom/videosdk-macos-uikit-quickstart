//
//  ZMPIntegrationInfo.h
//  ZoomPhoneUI
//
//  Created by Feder Huang on 2022/9/27.
//  Copyright © 2022 Evelyn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMPIntegrationInfo : NSObject

@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *domain;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *authoriztionName;
@property (nonatomic, copy) NSString *registerServer;
@property (nonatomic, copy) NSString *proxyServer;
@property (nonatomic, assign) int protocol;
@property (nonatomic, assign) int registrationExpiry;

//SIP register status : 0: init, 1: register success, 2: connection failed
@property (nonatomic, assign) int status;

@property (nonatomic, assign) int errorCode;
@property (nonatomic, copy) NSString *errorString;
@property (nonatomic, copy) NSString *voiceMail;
@property (nonatomic, assign) int dtmfPayloadType;
@property (nonatomic, copy) NSString *registerServer2;
@property (nonatomic, copy) NSString *proxyServer2;
@property (nonatomic, assign) int protocol2;
@property (nonatomic, copy) NSString *registerServer3;
@property (nonatomic, copy) NSString *proxyServer3;
@property (nonatomic, assign) int protocol3;
@property (nonatomic, assign) BOOL dscp;
@property (nonatomic, copy) NSString *dtmfMethod;

//updated after registering
@property (nonatomic, copy) NSString *activeRegisterServer;
@property (nonatomic, copy) NSString *activeProxyServer;
@property (nonatomic, assign) int activeProtocol;

- (NSString *)getActiveProtocolString;


//+ (ZMPIntegrationInfo *)getIntegrationInfoWith:(const NS_ZWEBSERVICE::SipPhoneIntegration *)cmmIntegration;
//
//- (NS_ZWEBSERVICE::SipPhoneIntegration)convertToCmmIntegration;
@end


