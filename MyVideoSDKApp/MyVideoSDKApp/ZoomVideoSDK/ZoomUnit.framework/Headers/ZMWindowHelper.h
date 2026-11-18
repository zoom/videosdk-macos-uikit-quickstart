//
//  ZMWindowHelper.h
//  ZoomUnit
//
//  Created by Francis Zhuo on 2026/8/24.
//

#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMWindowHelper : NSObject
+ (instancetype)shared;

- (void)moveFocusToNextWindow:(nullable NSWindow *)keyWindow;
@end

NS_ASSUME_NONNULL_END
