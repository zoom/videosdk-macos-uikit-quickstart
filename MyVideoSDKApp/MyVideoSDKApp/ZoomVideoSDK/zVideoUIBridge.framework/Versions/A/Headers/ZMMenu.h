//
//  ZMMenu.h
//  SaasBeeConfUIModule
//
//  Created by zoom on 13-4-20.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import "ZMMenuItem.h"
#import "ZMMenuWindow.h"

@class ZMMenu, ZMMTMenuItemGroupBuilder;
typedef void(^ZMMenuAction)(ZMMenu *menu);
@interface ZMMenu : ZMHMenu

@property(nonatomic, copy) ZMMenuAction menuWillClose;

- (instancetype)initWithBlur:(BOOL)isBlur;

- (void)addItem:(id<ZMMenuItemProtocol>)inItem;
- (void)insertItem:(id<ZMMenuItemProtocol>)inItem atIndex:(NSUInteger)index;
- (void)addItems:(NSArray<id<ZMMenuItemProtocol>> *)inItems;
- (void)addItemsFromMenuItemGroupBuilder:(ZMMTMenuItemGroupBuilder *)builder;
- (void)addSeparatorItem;
+ (ZMMenuItem *)separatorItemWithAppearance:(ZMHMenuAppearance)appearance;
- (NSArray *)itemArray;

- (void)popupRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView anchorCorner:(NSRectCorner)corner;
- (void)relayoutRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView anchorCorner:(NSRectCorner)corner;

- (void)closeAllMenu;

// Default is YES.
@property (nonatomic, assign) BOOL shouldInterceptKeyDownEvent;
- (BOOL)makeNextResponderWithEvent:(NSEvent*)inEvent;//[Zoom-21148]

+ (NSArray<ZMBaseMenuItem *> *)transferProtocolItemsToMenuItems:(NSArray<id<ZMMenuItemProtocol>> *)protocolItems;

@property (nonatomic, weak) ZMMenu *hostMenu;
@end

@interface ZMMTMenuItemGroupBuilder : NSObject
@property (nonatomic, strong, readonly) NSArray <__kindof ZMBaseMenuItem *> *items;
/// Default is ZMHMenuAppearanceDark
@property (nonatomic, assign) ZMHMenuAppearance appearance;

- (void)addItem:(id<ZMMenuItemProtocol>)inItem;
- (void)insertItem:(id<ZMMenuItemProtocol>)inItem atIndex:(NSUInteger)index;
- (void)addItems:(NSArray<id<ZMMenuItemProtocol>> *)inItems;
- (void)addSeparatorItem;
@end
