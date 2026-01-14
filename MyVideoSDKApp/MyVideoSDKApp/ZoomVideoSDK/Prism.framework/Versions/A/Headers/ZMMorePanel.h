//
//  ZMMorePanel.h
//  PTUIBridge
//
//  Created by Cursor on 10/17/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMorePanel;
@protocol ZMMorePanelKeyDownDelegate <NSObject>
@optional
/// Handle key down event, return YES if handled, NO to pass to super
- (BOOL)handleKeyDown:(NSEvent *)event;

- (BOOL)morePanel:(ZMMorePanel *)morePanel moveRight:(id)sender;
- (BOOL)morePanel:(ZMMorePanel *)morePanel moveLeft:(id)sender;
- (BOOL)morePanel:(ZMMorePanel *)morePanel moveUp:(id)sender;
- (BOOL)morePanel:(ZMMorePanel *)morePanel moveDown:(id)sender;

@end

@class ZMTabItemData;

// Block type for creating custom pasteboard items during drag
typedef NSObject<NSPasteboardWriting, NSPasteboardReading> * _Nullable (^ZMMorePanelPasteboardWriterBlock)(ZMTabItemData *itemData, NSIndexPath *indexPath);

@interface ZMMorePanel : ZMBaseView

// Customization properties
@property (nonatomic, assign) NSSize cellSize;  // Default: {72, 56}
@property (nonatomic, copy) NSString *dragType;  // Default: @"us.zoom.maintabs"
@property (nonatomic, copy) NSString *cellIdentifier;  // Default: @"ZMMorePanelCell"
@property (nonatomic, assign) BOOL draggingEnabled;  // Default: YES (dragging enabled)
@property (nonatomic, assign) BOOL showResetControl;  // Default: YES (show reset control)
@property (nonatomic, strong) NSColor *dividerColor;

// Color customization blocks
@property (nonatomic, copy, nullable) NSColor * (^cellBackgroundColorProvider)(ZMTabItemData *itemData);

// Pasteboard writer customization
@property (nonatomic, copy, nullable) ZMMorePanelPasteboardWriterBlock pasteboardWriterProvider;

// Empty state customization
@property (nonatomic, strong, nullable) NSImage *emptyStateIcon;  // Icon for empty state
@property (nonatomic, copy, nullable) NSString *emptyStateText;  // Text for empty state

// Callback handlers
@property (nonatomic, copy, nullable) void (^onResetHandler)(void);
@property (nonatomic, copy, nullable) void (^onCellClickHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) void (^onCellRightMouseClickHandler)(ZMTabItemData *itemData, NSEvent *event, NSView *cellView);
@property (nonatomic, copy, nullable) void (^onCellsReorderedHandler)(ZMTabItemData *draggedItem, ZMTabItemData * _Nullable targetItem);
@property (nonatomic, copy, nullable) void (^onSizeChangedHandler)(NSSize newSize);
@property (nonatomic, copy, nullable) void (^onItemAddedFromExternalHandler)(ZMTabItemData *itemData, BOOL isPin, ZMTabItemData * _Nullable targetItem);
@property (nonatomic, copy, nullable) void (^onItemRemovedHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) BOOL (^shouldRemoveItemOnDragEndHandler)(NSPoint screenPoint);
@property (nonatomic, copy, nullable) void (^onUnpinCellClickHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) void (^onDragSessionBeginHandler)(void);
@property (nonatomic, copy, nullable) void (^onDragSessionEndHandler)(void);
@property (nonatomic, weak, nullable) id<ZMMorePanelKeyDownDelegate> keyDelegate;
// Popout support callbacks
/// Called to check if item can be popped out (returns YES if popout is supported)
@property (nonatomic, copy, nullable) BOOL (^canPopOutItemHandler)(ZMTabItemData *itemData);
/// Called when drag moves to a point - allows handling popout/merge logic
/// Handler receives screenPoint, itemData, cellView, and dragging session
@property (nonatomic, copy, nullable) void (^onDragMovedHandler)(NSPoint screenPoint, ZMTabItemData *itemData, NSImage *cellImage, NSDraggingSession *session);
/// Returns YES if the item is currently popped out
@property (nonatomic, copy, nullable) BOOL (^isItemPoppedOutHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) void (^onEscKeyHandler)(void);
- (void)setTopSectionData:(NSArray<ZMTabItemData *> *)dataArray;
- (void)setBottomSectionData:(NSArray<ZMTabItemData *> *)dataArray;

- (NSArray<ZMTabItemData *> *)topSectionData;
- (NSArray<ZMTabItemData *> *)bottomSectionData;

- (void)updateLayout;

// Reload/Remove/Add methods for pinned items
- (void)reloadTopItems:(NSArray<NSString *> *)itemIDs;
- (void)removeTopItems:(NSArray<NSString *> *)itemIDs;
- (void)addTopItems:(NSArray<ZMTabItemData *> *)items;

// Reload/Remove/Add methods for unpinned items
- (void)reloadBottomItems:(NSArray<NSString *> *)itemIDs;
- (void)removeBottomItems:(NSArray<NSString *> *)itemIDs;
- (void)addBottomItems:(NSArray<ZMTabItemData *> *)items;

// Reload all data
- (void)reloadAll;

#pragma mark - Accessibility Focus Management

// Focus the first item in the panel
- (void)focusFirstItem;

// Focus the reset control
- (void)focusResetControl;

// Focus a specific item by identifier
- (BOOL)focusItemWithIdentifier:(NSString *)identifier;

// Get currently focused item data (nil if reset control is focused)
- (nullable ZMTabItemData *)focusedItemData;

#pragma mark - Arrow Key Handlers

- (void)handleLeftArrowKey;

- (void)handleRightArrowKey;

- (void)handleUpArrowKey;

- (void)handleDownArrowKey;

- (void)handleTabKey;

- (void)activateFocusedItem;

@end

NS_ASSUME_NONNULL_END

