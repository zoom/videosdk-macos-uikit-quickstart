//
//  ZMMTSidePanelItem.h
//  VideoUI
//
//  Created by Francis Zhuo on 4/24/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <ZoomUnit/ZoomUnit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMStackView;
@interface ZMMTSidePanelHeadView : ZMSidePanelBaseHeadView
@property (nonatomic, retain) ZMStackView* btnStackView;
- (void)initSubviews;
- (void)initTitle;
- (void)updateTitle:(NSString*)title;
// update the trailing and leading of the title, the default value is 40
- (void)updateTitleSideInset:(CGFloat)inset;
- (void)onActionButtonClicked:(ZMButton*)sender;
- (void)reloadViewContent;
@end

@protocol IZMMTSidePanelMgr;
@interface ZMMTSidePanelItem : ZMSidePanelItem
@property(copy) void (^onCloseAction)(void);
@property(copy) void (^onMiniaturizedAction)(void);
@property(copy) void (^onDeminiaturizedAction)(void);
@property(copy) void (^onPopupAction)(void);
@property(copy) void (^onPopinAction)(void);
@property(copy) void (^onExpandAction)(void);
@property(copy) void (^onCollapseAction)(void);
@property(copy) void (^onBackupAction)(ZMSidePanelWindowAction action);
@property(copy) void (^onRestoreAction)(ZMSidePanelWindowAction action);

@property(weak) id<IZMMTSidePanelMgr> sidePanel;
@property(nonatomic, strong, readonly) ZMButton *popinButton;
@property(nonatomic, assign) BOOL forceHidePopinButton;

- (NSView*)generateHeadView;//for override

- (void)updateTitle:(NSString*)title;

- (void)updateBoldTitle:(NSString*)title;

- (void)setNeedsRestore:(BOOL)needed;

- (void)updateActionButtons;

- (BOOL)isItemShowing;
@end


NS_ASSUME_NONNULL_END
