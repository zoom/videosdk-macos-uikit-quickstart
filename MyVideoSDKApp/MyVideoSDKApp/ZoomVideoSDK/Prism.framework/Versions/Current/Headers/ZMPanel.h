//
//  ZMPanel.h
//  Prism
//
//  Created by Devl on 10/22/25.
//

#import <Prism/ZMBasePanel.h>
#import <Prism/NSWindow+ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Note: If the panel needs shadow, TitledMask is required.
 * If you don't want the system titlebar, FullsizeContentMask is required.
 * Automatically maintains widgets/radius/border/shadow, no additional configuration needed.
 */
@interface ZMPanel : ZMBasePanel

@property (nonatomic, nullable, copy) void (^escAction)(void);
@property (nonatomic, assign) BOOL alertAsSheet;
@property (nonatomic, assign) BOOL responseESC;
@property (nonatomic, assign) BOOL ignoreKey;

- (instancetype)initWithContentRect:(NSRect)rect;
- (instancetype)initWithContentRect:(NSRect)rect radius:(ZMWindowRadius)radius;

- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable;
- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable;
- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable resizable:(BOOL)resizable;

- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable resizable:(BOOL)resizable generateWidgets:(BOOL)generate API_DEPRECATED("Use initWithContentRect: instead", macos(10.13, 26.0));

@end

@interface ZMUnsharablePanel : ZMPanel
@end

NS_ASSUME_NONNULL_END
