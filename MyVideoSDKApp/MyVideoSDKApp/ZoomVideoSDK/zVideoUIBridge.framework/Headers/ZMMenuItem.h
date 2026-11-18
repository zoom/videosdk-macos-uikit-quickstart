//
//  ZMMenuItem.h
//  SaasBeeConfUIModule
//
//  Created by zoom on 13-4-20.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import "ZMMTSwitchItemView.h"
#import "ZMMTCheckboxItemView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMenuItemInfoButtonPosition) {
    ZMMenuItemInfoButtonPositionAfterTitle = 0,
    ZMMenuItemInfoButtonPositionBeforeTailField
};

@interface ZMMenuItem : ZMBaseMenuItem <ZMMenuItemProtocol>

@property (nonatomic, assign) NSInteger badgeNumber;
@property (nonatomic, assign) NSSize fixedSize;
@property (nonatomic, assign) NSSize titleImageSize;
@property (nonatomic, assign) CGFloat titleImgAndTitleMargin;
@property (nonatomic, assign) BOOL showNewTag;//default is NO
@property (nonatomic, copy) NSString *additionalAccHelpString;
@property (nonatomic, assign) CGFloat disableImageAlpha;
@property (nonatomic, assign) BOOL showInfoButton;
@property (nonatomic, assign) ZMMenuItemInfoButtonPosition infoButtonPosition;//default is ZMMenuItemInfoButtonPositionAfterTitle
@property (nonatomic, strong, readonly) ZMHelpButton *infoButton;

@property (nonatomic, assign) BOOL matchImageColorWithTitle; // Default is YES

- (instancetype)initWithTitle:(NSString *)inTitle indentationDistance:(CGFloat)indentationDistance;
+ (instancetype)separatorItem;
+ (instancetype)separatorItemWithColor:(NSColor*)color;
+ (instancetype)indentItemWithTitle:(NSString *)title;
+ (instancetype)itemWithTitle:(NSString *)title;
+ (instancetype)itemWithTitle:(NSString *)title target:(id)target action:(SEL)action;
+ (instancetype)switchItemWithTitle:(NSString *)title
                        configBlock:(void(^)(ZMMTSwitchItemView *view))configBlock;
+ (instancetype)switchItemWithHeadIconView:(nullable NSView *)headIconView
                                     title:(NSString *)title
                               configBlock:(void(^)(ZMMTSwitchItemView *view))configBlock;
+ (instancetype)switchItemWithHeadIconView:(nullable NSView *)headIconView
                                     title:(NSString *)title
                                      desc:(nullable NSString *)desc
                                  maxWidth:(CGFloat)maxWidth
                               configBlock:(void(^)(ZMMTSwitchItemView *view))configBlock;
+ (instancetype)checkboxItemWithTitle:(NSString *)title
                          configBlock:(void(^)(ZMMTCheckboxItemView *view))configBlock;
+ (instancetype)checkboxItemWithTitle:(NSString *)title
                        tailTitleText:(nullable NSString *)tailTitleText
                          configBlock:(void(^)(ZMMTCheckboxItemView *view))configBlock;

- (void)reloadUI;
@end

@interface ZMBaseMenuItem(ZMSpeecher)
- (void)speakTitleWithState:(BOOL)isCheck;
- (void)speakTitleWithToggledState;
@end

@interface PZMMenuItem(ZMSpeecher)
- (void)speakTitleWithState:(BOOL)isCheck;
- (void)speakTitleWithToggledState;
@end
NS_ASSUME_NONNULL_END
