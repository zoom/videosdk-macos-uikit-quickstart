//
//  ZMTabItemData.h
//  PTUIBridge
//
//  Created by Cursor on 10/17/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMPigment.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItemData;

#pragma mark - Drag Source Protocol

/// Protocol for drag sources that can provide ZMTabItemData
@protocol ZMTabItemDataDragSource <NSObject>

@required
/// Get the tab item data being dragged
- (ZMTabItemData *)draggingTabItemData;

@end

typedef NS_ENUM(NSInteger, ZMTabDragOrigin) {
    ZMTabDragOriginUnknown = 0,
    ZMTabDragOriginTabBar,
    ZMTabDragOriginMorePanel,
};


@interface ZMTabItemColorfuls : NSObject

@property (nonatomic, strong, nullable) NSImage *lightColorfulImage;
@property (nonatomic, strong, nullable) NSImage *darkColorfulImage;

@end

/**
 * Base data model for tab items
 * Contains common properties shared between ZMTabItem and other tab-related data
 */
@interface ZMTabItemData : NSObject

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong, nullable) ZMTabItemColorfuls *colorfulImageSet;
@property (nonatomic, strong, nullable) NSImage *greyImage;
- (BOOL)forceUpdateImage;
/// Returns the colorful image for the current appearance.
/// If `colorfulImageSet` exists, returns `darkColorfulImage` in dark mode or
/// `lightColorfulImage` in light mode. Otherwise returns `nil`; callers that need a
/// fallback are responsible for using `greyImage`.
@property (nonatomic, strong, readonly, nullable) NSImage *colorfulImage;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) CGFloat disabledAlphaValue;
@property (nonatomic, copy, nullable) NSString *disabledToolTip;
@property (nonatomic, assign) BOOL isPin;
@property (nonatomic, assign) BOOL showNew;
@property (nonatomic, assign) BOOL showBeta;
@property (nonatomic, assign) BOOL showFreeTrial;
@property (nonatomic, assign) BOOL showError;
@property (nonatomic, assign) NSInteger badgeValue;
@property (nonatomic, assign) BOOL showRedDot;
@property (nonatomic, assign) BOOL draggable;
@property (nonatomic, assign) BOOL draggingNow;
/// YES until a More-panel drag reaches the bar; keeps that item's tab-bar slot visible.
@property (nonatomic, assign) BOOL draggingFromMorePanel;
@property (nonatomic, strong) ZMPigment<ZMButtonPigmentProtocol> *pigment;
@property (nonatomic, assign) BOOL matchImageColorWithTitle; //default NO

/// Pre-assembled accessibility label text (e.g., "Docs, 1 of 5, not pinned, tab")
@property (nonatomic, copy) NSString *accessibilityText;

+ (void)writeDragOrigin:(ZMTabDragOrigin)origin toPasteboardItem:(NSPasteboardItem *)item;
+ (ZMTabDragOrigin)dragOriginFromPasteboard:(NSPasteboard *)pasteboard;

@end

NS_ASSUME_NONNULL_END


