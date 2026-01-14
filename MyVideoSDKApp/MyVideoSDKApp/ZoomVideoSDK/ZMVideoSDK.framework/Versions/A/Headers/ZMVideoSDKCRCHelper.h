/**
 * @file ZMVideoSDKCRCHelper.h
 * @brief Interface for managing CRC (Cloud Room Connector) features in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKCRCHelper
 * @brief Helper interface for Cloud Room Connector (CRC) features.
 */
@interface ZMVideoSDKCRCHelper : NSObject

/**
 * @brief Queries if the CRC feature is enabled.
 * @return YES if the CRC is enabled. Otherwise, NO.
 * @warning Only get the correct value after joining the session.
 */
- (BOOL)isCRCEnabled;

/**
 * @brief Calls the CRC device. Only available for the host or co-host.
 * @param address The CRC device's IP address.
 * @param callProtocol The CRC device's protocol.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)callCRCDevice:(NSString *)address protocol:(ZMVideoSDKCRCProtocol)callProtocol;

/**
 * @brief Cancels the call to the CRC device. Only available for the host or co-host.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)cancelCallCRCDevice;

/**
 * @brief Gets the dial-in SIP address of a live session when CRC is enabled
 * @return Return the live session SIP address if the CRC is enabled. Otherwise, return nil.
 */
- (NSString* _Nullable)getSessionSIPAddress;
@end

NS_ASSUME_NONNULL_END
