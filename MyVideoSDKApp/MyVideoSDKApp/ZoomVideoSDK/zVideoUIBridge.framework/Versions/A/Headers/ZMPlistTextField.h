//
//  ZMPlistTextField.h
//  zVideoUIBridge
//
//  Created by Francis Zhuo on 2020/7/6.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark ZMPlistTextField
@interface ZMPlistTextFieldCell : NSTextFieldCell
@property(strong) NSString* userName;
@property(strong) NSString* userRole;
@end

@interface ZMPlistTextField : NSTextField
@property(strong) NSString* userName;
@property(strong) NSString* userRole;
@property(strong) ZMPlistTextFieldCell* cell;
@end


NS_ASSUME_NONNULL_END
