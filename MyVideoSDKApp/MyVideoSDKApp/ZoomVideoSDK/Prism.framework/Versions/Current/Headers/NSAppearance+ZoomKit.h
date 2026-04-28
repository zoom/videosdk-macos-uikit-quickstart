//
//  NSAppearance+ZoomKit.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/22.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTheme;
@interface NSAppearance (ZoomKit)
+ (instancetype)zm_darkAppearance;
+ (instancetype)zm_lightAppearance;
@property (readonly) BOOL isDarkMode;

+ (NSAppearance*)zmDrawingAppearance;

- (void)zm_performAsCurrentDrawingAppearance:(void (NS_NOESCAPE ^)(void))block;

@property (nullable, strong) ZMTheme* theme;
@end

@interface NSView (ZoomAppearance)
@property (assign, readonly) BOOL isDarkMode;
@end

NS_ASSUME_NONNULL_END
