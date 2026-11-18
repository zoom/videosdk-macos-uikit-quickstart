//
//  ZMMTSwitchItemView.h
//  VideoUI
//
//  Created by martin yu on 7/20/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTSwitchItemView : ZMHMenuItemView
@property (nonatomic, strong) NSTextField *titleField;
@property (nonatomic, strong) NSTextField *descriptionField;
@property (nonatomic, strong) PZMToggleView *roundSwitch;
@property (nonatomic, strong, nullable) NSView *headIconView;

@property (nonatomic, assign) BOOL enabled;

- (instancetype)initWithTitle:(NSString *)title;
- (instancetype)initWithHeadIconView:(nullable NSView *)headerIconView
                               title:(NSString *)title;
- (instancetype)initWithHeadIconView:(nullable NSView *)headerIconView
                               title:(NSString *)title
                         description:(nullable NSString *)description
                            maxWidth:(CGFloat)maxWidth;

- (void)performMenuItemAction;
@end

NS_ASSUME_NONNULL_END
