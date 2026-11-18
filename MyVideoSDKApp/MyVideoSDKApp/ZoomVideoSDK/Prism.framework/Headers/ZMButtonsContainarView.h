//
//  ZMButtonsContainarView.h
//  ZCommonUI
//
//  Created by Huxley on 2019/5/20.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMButtonsContainarView : NSView
{
    NSUInteger _lineNumber;
}
@property IBInspectable CGFloat spacing;
@end

@interface ZMReactionContainarView : NSView
{
    NSUInteger _maxLineNum; //start from 0
}
@property IBInspectable CGFloat spacing;
@property(nonatomic, retain, nullable) NSView* anchorView;
@property(nonatomic, retain, nullable) NSView* tailView;
@property(nonatomic, assign) NSSize  expSize;
@property(nonatomic, assign) CGFloat lineBreakMaxWidth;
@end

NS_ASSUME_NONNULL_END
