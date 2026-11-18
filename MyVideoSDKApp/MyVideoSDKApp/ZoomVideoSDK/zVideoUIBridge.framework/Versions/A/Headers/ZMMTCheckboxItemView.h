//
//  ZMMTCheckboxItemView.h
//  VideoUI
//
//  Created by martin yu on 2024/3/1.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTCheckboxItemView : NSView <ZMMenuItemProtocol>
@property (nonatomic, strong) ZMCheckButton *checkButton;
@property (nonatomic, strong) NSTextField *tailField;

- (instancetype)initWithTitle:(NSString *)title tailTitleText:(nullable NSString *)tailTitleText;
@end

NS_ASSUME_NONNULL_END
