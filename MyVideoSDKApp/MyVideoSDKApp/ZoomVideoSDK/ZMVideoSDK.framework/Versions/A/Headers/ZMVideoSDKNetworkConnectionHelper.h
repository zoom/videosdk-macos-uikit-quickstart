/**
 * @file ZMVideoSDKNetworkConnectionHelper.h
 * @brief This file provides classes and methods to manage proxy configuration and SSL certificate information within the Zoom Video SDK.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKProxySettings
 * @brief Represents the proxy configuration settings used for network connections.
 */
@interface ZMVideoSDKProxySettings : NSObject

/**
 * @brief The proxy ip address and port that user want to use, should be organized like ip:port, such as '255.255.255.255:8080'. Use ';' to separate multi proxies.
 */
@property (nonatomic, copy) NSString * _Nullable proxy;

/**
 * @brief YES indicates automatic detection.
 */
@property (nonatomic, assign) BOOL autoDetect;
@end


/**
 * @class ZMVideoSDKProxySettingHandler
 * @brief Handles proxy authentication input and provides metadata about the proxy connection.
 */
@interface ZMVideoSDKProxySettingHandler : NSObject

/**
 * @brief Gets the proxy host's address.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable proxyHost;

/**
 * @brief Gets the proxy port.
 */
@property (nonatomic, assign, readonly) unsigned int proxyPort;

/**
 * @brief Gets the proxy's description.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable proxyDescription;

/**
 * @brief Input the username and password when using the proxy.
 * @param userName The username when using the proxy.
 * @param psw The password when using the proxy.
 */
- (void)inputUsernamePassword:(NSString *)userName password:(NSString *)psw;

/**
 * @brief Cancels the process to input the username and password of the proxy.
 */
- (void)cancel;

@end


/**
 * @class ZMVideoSDKSSLCertificateInfo
 * @brief Provides details about the SSL certificate used for secure connections.
 */
@interface ZMVideoSDKSSLCertificateInfo : NSObject

/**
 * @brief Gets the value of whom the SSL certificate is issued to.
 */
@property (nonatomic, copy, readonly, nullable) NSString * certIssuedTo;

/**
 * @brief Gets the value that who issues the SSL certificate.
 */
@property (nonatomic, copy, readonly, nullable) NSString * certIssuedBy;

/**
 * @brief Gets the serial number of the SSL certificate.
 */
@property (nonatomic, copy, readonly, nullable) NSString * certSerialNum;

/**
 * @brief Gets the SSL certificate's fingerprint.
 */
@property (nonatomic, copy, readonly, nullable) NSString * certFingerprint;

@end


/**
 * @class ZMVideoSDKNetworkConnectionHelper
 * @brief A helper class for configuring proxy settings for SDK network connections.
 */
@interface ZMVideoSDKNetworkConnectionHelper : NSObject

/**
 * @brief Sets the proxy that the user want to use according to your net environment.
 * @param proxySetting The proxy ip address and port that user want to use, should be organized like ip:port, such as '255.255.255.255:8080'. Using ';' to separate multi proxies.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)configureProxy:(ZMVideoSDKProxySettings*)proxySetting;
@end

NS_ASSUME_NONNULL_END
