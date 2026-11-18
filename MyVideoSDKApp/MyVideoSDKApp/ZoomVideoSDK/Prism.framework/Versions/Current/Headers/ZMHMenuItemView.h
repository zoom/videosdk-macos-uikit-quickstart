//
//  ZMHMenuItemView.h
//  zChatUI
//
//  Created by Huxley on 2018/4/17.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMBaseMenuItem;
@interface ZMHMenuItemView : NSView

@property (weak) ZMBaseMenuItem *representedItem;
@property (nonatomic, assign) BOOL showsFocusRingMask;
@property (nonatomic, assign) BOOL canBecomeFirstResponder;

@end
