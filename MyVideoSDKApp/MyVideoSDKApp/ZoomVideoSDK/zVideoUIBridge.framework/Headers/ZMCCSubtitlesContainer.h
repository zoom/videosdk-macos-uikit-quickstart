//
//  ZMCCSubtitlesContainer.h
//  VideoUIBridge
//
//  Migrated from ClosedCaptionUI for bridge visibility.
//

#ifndef ZMCCSubtitlesContainer_h
#define ZMCCSubtitlesContainer_h

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <ZoomKit/ZoomKit.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTBaseViewController;
@class ZMUser;
@class ZMCCSubtitlesMessage;
@protocol ZMCCSubtitlesContainer;

@protocol ZMCCSubtitlesContainerDelegate <NSObject>
@optional
- (void)intrinsicContentSizeDidChange:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController;
- (BOOL)shouldAutoHideSubtitles:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController;
- (void)autoHideSubtitles:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController;
- (NSView *)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController customHitTestViewOfScrollViewWithPoint:(NSPoint)point;

// Mouse Event
- (BOOL)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController mouseDown:(NSEvent *)event;
- (BOOL)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController mouseDragged:(NSEvent *)event;
- (BOOL)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController mouseUp:(NSEvent *)event;
// Key Event
- (BOOL)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController keyDown:(NSEvent *)event;
- (BOOL)viewController:(ZMMTBaseViewController<ZMCCSubtitlesContainer> *)viewController keyUp:(NSEvent *)event;
@end

@protocol ZMCCSubtitlesContainer <NSObject>
@property (nonatomic, weak) id<ZMCCSubtitlesContainerDelegate> delegate;
@property (nonatomic, assign) CGFloat intrinsicContentWidth;
@property (nonatomic, readonly) NSSize intrinsicContentSize;
@property (nonatomic, assign) BOOL viewIsAccessibilityElement;
@property (nonatomic, assign) ZMMTCaptionDisplayMode captionDisplayMode;
@property (nonatomic, assign, readonly) CGFloat preferredMaxWidth;

@property (nonatomic, readonly) NSString *accTitleForShow;
@property (nonatomic, readonly) NSString *accTitleForHide;

- (void)updateUI;
- (void)updateUITitleOnly;
- (void)updateUIWithFontName:(nullable NSString *)fontName;
- (BOOL)updateUIWithFontSize:(int)fontSize;
- (void)updateCaptionColor:(NSColor *)color;
- (void)updateTranslationColor:(NSColor *)color;
- (void)updateBackgroundColor:(NSColor *)color;
- (void)onReceiveMessage:(ZMCCSubtitlesMessage *)message;
- (void)scheduleOneTime2HideSubtitles;

// Smart Speaker Tag
- (void)onSpeakerTagInfoUpdatedWithMsgIds:(NSMutableOrderedSet<NSString *> *)msgIds;
- (void)onZRSpeakerInfoChanged:(ZMUser *)zmUser;

// Resizing
- (ZMResizeEdge)resizeEdgeForMouseDownEvent:(NSEvent *)event;
- (nullable NSCursor *)cursorForEdge:(ZMResizeEdge)edge;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMCCSubtitlesContainer_h */
