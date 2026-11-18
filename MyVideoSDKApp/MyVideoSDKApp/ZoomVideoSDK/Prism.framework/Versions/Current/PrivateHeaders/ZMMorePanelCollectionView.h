//
//  ZMMorePanelCollectionView.h
//  PTUIBridge
//
//  Created by Cursor on 10/20/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMMorePanelCellView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItemData;

#pragma mark - ZMDraggableCollectionView

@interface ZMMorePanelCollectionViewItem : NSCollectionViewItem

@property (nonatomic, strong, readonly) ZMMorePanelCellView *cellView;

- (void)focusSelf;

@end

#pragma mark - ZMDraggableCollectionView

@protocol ZMDraggableCollectionViewDelegate <NSObject>
@optional
/// Handle key down event, return YES if handled, NO to pass to super
- (BOOL)handleKeyDown:(NSEvent *)event;

- (void)collectionView:(NSCollectionView *)collectionView moveRight:(id)sender;
- (void)collectionView:(NSCollectionView *)collectionView moveLeft:(id)sender;
- (void)collectionView:(NSCollectionView *)collectionView moveUp:(id)sender;
- (void)collectionView:(NSCollectionView *)collectionView moveDown:(id)sender;
/// Move focused cell to next position
/// If at last pinned cell, move to first unpinned position
- (void)moveFocusedCellToNext;

- (void)handleCellButtonAction:(ZMTabItemData *)itemData;
@end

@interface ZMDraggableCollectionView : NSCollectionView

@property (nonatomic, copy, nullable) void (^onDraggingSessionMovedToPoint)(NSDraggingSession *session, NSPoint screenPoint);

@property (nonatomic, weak) id<ZMDraggableCollectionViewDelegate> keyDelegate;

@end

#pragma mark - Collection View

// Block type for creating custom pasteboard items during drag
typedef NSObject<NSPasteboardWriting, NSPasteboardReading> * _Nullable (^ZMMorePanelPasteboardWriterBlock)(ZMTabItemData *itemData, NSIndexPath *indexPath);

@interface ZMMorePanelCollectionView : ZMBaseView<ZMMorePanelCellButtonActionProtocol>

// Callbacks
@property (nonatomic, copy, nullable) void (^onCellClickHandler)(ZMTabItemData *itemData);
/// Fired when a cell is materialized for display (initial + scrolled into view).
/// Used by hosts to lazily load per-cell resources (e.g. zApp tab icons).
@property (nonatomic, copy, nullable) void (^onCellWillDisplayHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) void (^onCellRightMouseClickHandler)(ZMTabItemData *itemData, NSEvent *event, NSView *cellView);
@property (nonatomic, copy, nullable) void (^onItemsReorderedHandler)(ZMTabItemData *draggedItem, ZMTabItemData * _Nullable targetItem);
@property (nonatomic, copy, nullable) void (^onItemAddedFromExternalHandler)(ZMTabItemData *itemData, BOOL isPin, ZMTabItemData * _Nullable targetItem);
@property (nonatomic, copy, nullable) void (^onItemRemovedHandler)(ZMTabItemData *itemData);
@property (nonatomic, copy, nullable) void (^onSizeChangedHandler)(void);
@property (nonatomic, copy, nullable) BOOL (^shouldRemoveItemOnDragEndHandler)(NSPoint screenPoint);
@property (nonatomic, copy, nullable) void (^onDragSessionBeginHandler)(void);
@property (nonatomic, copy, nullable) void (^onDragSessionEndHandler)(void);

// Popout support callbacks
/// Called when drag moves to check if item can be popped out (returns YES if popout is supported)
@property (nonatomic, copy, nullable) BOOL (^canPopOutItemHandler)(ZMTabItemData *itemData);
/// Called during drag when position changes - provides screen point, dragging item, cell view, and session
@property (nonatomic, copy, nullable) void (^onDragMovedHandler)(NSPoint screenPoint, ZMTabItemData *itemData, NSImage *cellImage, NSDraggingSession *session);
/// Returns YES if the item is currently popped out
@property (nonatomic, copy, nullable) BOOL (^isItemPoppedOutHandler)(ZMTabItemData *itemData);

// Internal collection view (for advanced configuration)
@property (nonatomic, strong) ZMDraggableCollectionView *collectionView;
@property (nonatomic, strong, readonly) NSScrollView *scrollView;

// Customization
@property (nonatomic, copy) NSString *dragType;  // Default: @"us.zoom.maintabs"
@property (nonatomic, assign) BOOL draggingEnabled;  // Default: NO (dragging disabled)
@property (nonatomic, copy, nullable) ZMMorePanelPasteboardWriterBlock pasteboardWriterProvider;

@property (nonatomic, strong) NSColor *dividerColor;

@property (nonatomic,weak) id zmAccessibilityParent;

// Data Management
- (void)setPinnedItems:(NSArray<ZMTabItemData *> *)pinnedItems 
        unpinnedItems:(NSArray<ZMTabItemData *> *)unpinnedItems;

- (NSArray<ZMTabItemData *> *)pinnedItems;
- (NSArray<ZMTabItemData *> *)unpinnedItems;

// Reload Methods
- (void)reloadData;
- (void)reloadItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)reloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

/// Current document content height calculated from items/layout rules.
- (CGFloat)contentHeight;

// Drag & Drop
- (void)endDragSession;
- (void)endDragSessionIfExternal;
- (void)notifySourceEndIfNeeded;

@end

NS_ASSUME_NONNULL_END
