//
//  ZMMorePanelCellView.h
//  PTUIBridge
//
//  Created by Cursor on 10/20/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMTabItemData.h>
#import <Prism/ZMBaseView.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Cell Configuration Protocol

/// Protocol for button action
@protocol ZMMorePanelCellButtonActionProtocol <NSObject>

- (void)onCellButtionAction:(ZMTabItemData *)itemData;

@end

/// Protocol for custom cell views in ZMMorePanelCollectionView
@protocol ZMMorePanelCellViewProtocol <NSObject>

@required
/// Update the cell view with item data
- (void)updateWithItemData:(ZMTabItemData *)itemData;

@property (nonatomic,weak) id zmAccessibilityParent;

@optional
/// Called when the cell is about to be reused
- (void)prepareForReuse;

/// Reset the hover state of the cell
- (void)resetHoverState;

- (NSImage *)getCapture;

/// Focus on the cell's primary interactive element
- (void)focusSelf;

@end

@interface ZMMorePanelCellView : ZMBaseView <ZMMorePanelCellViewProtocol>

// Use weak to avoid duplicate strong references (array already holds strong reference)
@property (nonatomic, weak) ZMTabItemData *itemData;
@property (nonatomic, nullable, retain) ZMPigment<ZMButtonPigmentProtocol>* pigment;
// Color customization blocks
@property (nonatomic, copy, nullable) NSColor * (^backgroundColorProvider)(ZMTabItemData *itemData);

@property (nonatomic,weak) id<ZMMorePanelCellButtonActionProtocol> delegate;

@property (nonatomic,weak) id zmAccessibilityParent;

- (instancetype)initWithItemData:(ZMTabItemData *)itemData;
- (void)updateWithItemData:(ZMTabItemData *)itemData;
- (void)updateVisibilityForDragging;
- (void)resetHoverState;

@end

NS_ASSUME_NONNULL_END
