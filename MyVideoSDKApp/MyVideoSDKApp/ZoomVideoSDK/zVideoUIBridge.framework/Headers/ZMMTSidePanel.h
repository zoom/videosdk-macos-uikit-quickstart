//
//  ZMMTSidePanel.h
//  VideoUIBridge
//
//  Created by Devl on 7/16/25.
//

#import <zVideoUIBridge/ZMInvisibleWindow.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTSidePanelItem;

@protocol ZMMTSidePanelDelegate <NSWindowDelegate>
@optional
- (void)windowClickClose:(NSButton *)sender;

@end

@interface ZMMTSidePanel : ZMInvisibleWindow
@property (weak) id<ZMMTSidePanelDelegate> delegate;
@property (nonatomic, strong, nullable) ZMMTSidePanelItem *item;

- (instancetype)init;
- (instancetype)initWithContentRect:(NSRect)contentRect;
- (void)showWithContentView:(NSView*)view;
- (void)addTopRightView:(NSView*)view;

@end

NS_ASSUME_NONNULL_END
