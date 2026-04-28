//
//  ZMAppProtocol.h
//  Zoom
//
//  Created by Francis Zhuo on 5/17/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef ZMAppProtocol_h
#define ZMAppProtocol_h
#import <Appkit/Appkit.h>

#define kAppStartTime @"kAppStartTime"
#define kAppLaunchTimeCost @"kAppLaunchTimeCost"

@protocol ZMAppProtocol <NSObject>

@optional
- (void)applicationDidFinishLaunching:(NSDictionary *)launchingInfo;
- (void)applicationWillTerminate:(NSApplication *)application;

- (BOOL)applicationShouldTerminateNow:(NSApplication *)application;
- (void)applicationAppearanceDidChanged:(NSApplication *)application;
@end

#endif /* ZMAppProtocol_h */
