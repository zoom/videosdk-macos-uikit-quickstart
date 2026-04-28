//
//  ZMWindow.h
//  Prism
//
//  Created by Devl on 10/22/25.
//

#import <Prism/ZMBaseWindow.h>
#import <Prism/NSWindow+ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Note: If the window needs shadow, TitledMask is required.
 * If you don't want the system titlebar, FullsizeContentMask is required.
 * Automatically maintains widgets/radius/border/shadow, no additional configuration needed.
 */
@interface ZMWindow : ZMBaseWindow

@property (nonatomic, nullable, copy) void (^escBlock)(void);
@property (nonatomic, assign) BOOL alertAsSheet;
@property (nonatomic, assign) BOOL responseESC;
@property (nonatomic, assign) BOOL ignoreKey;

- (instancetype)initWithContentRect:(NSRect)rect;
- (instancetype)initWithContentRect:(NSRect)rect radius:(ZMWindowRadius)radius;

- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable;
- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable;
- (instancetype)initWithContentRect:(NSRect)rect closable:(BOOL)closable miniaturizable:(BOOL)miniaturizable resizable:(BOOL)resizable;

@end

@interface ZMUnsharableWindow : ZMWindow
@end

NS_ASSUME_NONNULL_END
