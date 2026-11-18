//
//  ZMMTMessageTextView.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/23/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTMessageTextView : NSTextView
- (void)setAttributedString:(NSAttributedString *)attributedString;

- (void)updateSelectedBackgroundColor:(BOOL)isHighLight;
- (void)onMutipleClickEvent:(NSEvent *)event;
@end

NS_ASSUME_NONNULL_END
