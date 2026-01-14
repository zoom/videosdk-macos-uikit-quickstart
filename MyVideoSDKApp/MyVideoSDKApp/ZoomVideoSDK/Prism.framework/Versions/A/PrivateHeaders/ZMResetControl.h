//
//  ZMResetControl.h
//  PTUIBridge
//
//  Created by Cursor on 10/17/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseView.h>
#import <Prism/Prism-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMResetControl;

/// Protocol for keyboard events from ZMResetControl
@protocol ZMResetControlKeyboardDelegate <NSObject>
@optional
/// Handle key down event, return YES if handled
- (BOOL)resetControl:(ZMResetControl *)resetControl handleKeyDown:(NSEvent *)event;
@end

@interface ZMResetControl : ZMBaseView

@property (nonatomic, copy) NSString *hintText;        // Hint text (left side)
@property (nonatomic, copy, nullable) void (^clickHandler)(void);
@property (nonatomic, strong) PZMButton *resetButton;     // Right: "Reset" (clickable)
@property (nonatomic, weak, nullable) id<ZMResetControlKeyboardDelegate> keyboardDelegate;
@property (nonatomic,weak) id zmAccessibilityParent;
/// Focus the reset control itself (makes it first responder)
- (void)focusSelf;

- (instancetype)initWithTitle:(NSString *)title 
                     hintText:(NSString *)hintText;

@end

NS_ASSUME_NONNULL_END


