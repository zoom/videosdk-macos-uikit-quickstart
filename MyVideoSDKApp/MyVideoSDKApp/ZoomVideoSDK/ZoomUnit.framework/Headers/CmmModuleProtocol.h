//
//  CmmModuleProtocol.h
//  PTUIBridge
//
//  Created by Francis Zhuo on 2025/11/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
* @router ZMRouterCenter
*/
@protocol CmmModuleProtocol <ZMRoutableObject>
@optional
- (void)onMcmModuleRegistry;
- (void)onMcmModuleUnregistry;

@end

NS_ASSUME_NONNULL_END
