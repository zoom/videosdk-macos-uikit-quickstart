//
//  ZMMTUniversalUIProtocol.h
//  VideoUIBridge
//
//  Created by Davies Zhao on 2026/1/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTUniversalUIProtocol <NSObject>

@optional
- (void)onModuleAfterCreated:(NS_ZM_CONF_UNIVERSAL_UI::UuiModuleName)moduleName;
- (void)onModuleBeforeDestroyed:(NS_ZM_CONF_UNIVERSAL_UI::UuiModuleName)moduleName;

@end

NS_ASSUME_NONNULL_END
