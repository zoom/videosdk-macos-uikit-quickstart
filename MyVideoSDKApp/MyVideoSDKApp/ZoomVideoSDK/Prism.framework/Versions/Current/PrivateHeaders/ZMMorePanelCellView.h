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

// MARK: - Cell Configuration
@protocol ZMMorePanelCellButtonActionProtocol <NSObject>

- (void)onCellButtionAction:(ZMTabItemData *)itemData;

@end

@interface ZMMorePanelCellView : ZMBaseView

@property (nonatomic, strong) ZMTabItemData *itemData;
@property (nonatomic, strong, nullable) NSImage *capture;
@property (nonatomic,weak) id<ZMMorePanelCellButtonActionProtocol> delegate;
@property (nonatomic, assign, getter=isHovered) BOOL hovered;

@property (nonatomic,weak) id zmAccessibilityParent;

- (void)updateWithItemData:(ZMTabItemData *)itemData;
- (void)updateVisibilityForDragging;
- (void)setGapMode:(BOOL)gapMode;

@end

NS_ASSUME_NONNULL_END
