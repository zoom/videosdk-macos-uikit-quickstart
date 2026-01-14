//
//  ZMPlainWindow.h
//  zChatUI
//
//  Created by groot.ding on 2018/4/20.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMWindowWidgets.h>

API_DEPRECATED("Use ZMWindow instead", macos(10.13, 26.0))
@interface ZMPlainWindow : NSWindow

- (nonnull instancetype)initWithContentRect:(NSRect)contentRect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable resizable:(BOOL)resizable generateWidgets:(BOOL)generate;///< Creat Plain Window by Code

@property (nonatomic, nullable, retain) IBOutlet ZMWindowWidgets *widgets;
@property (nonatomic, nullable, copy) void (^escBlock)(void);

@property (getter=isMovableByWindowBackground) IBInspectable BOOL movableByWindowBackground;
@property IBInspectable BOOL alertAsSheet;
@property IBInspectable BOOL responseESC;

- (void)generateWidgetsIfDontHave;

@end

API_DEPRECATED("Use ZMUnsharableWindow instead", macos(10.13, 26.0))
@interface ZMInvisiblePlainWindow : ZMPlainWindow

@end

API_DEPRECATED("Use ZMPanel instead", macos(10.13, 26.0))
@interface ZMPlainPanel : NSPanel

- (nonnull instancetype)initWithContentRect:(NSRect)contentRect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable resizable:(BOOL)resizable generateWidgets:(BOOL)generate;///< Creat Plain Window by Code

@property (nonatomic, nullable, retain) IBOutlet ZMWindowWidgets *widgets;

@property (getter=isMovableByWindowBackground) IBInspectable BOOL movableByWindowBackground;
@property IBInspectable BOOL alertAsSheet;
@property IBInspectable BOOL responseESC;

- (void)generateWidgetsIfDontHave;

@end

API_DEPRECATED("Use ZMUnsharablePanel instead", macos(10.13, 26.0))
@interface ZMInvisiblePlainPanel : ZMPlainPanel

@end
