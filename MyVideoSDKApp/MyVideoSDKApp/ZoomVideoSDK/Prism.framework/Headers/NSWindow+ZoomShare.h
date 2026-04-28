//
//  NSWindow+InvisibleInShare.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/11/23.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
typedef NS_ENUM(NSInteger, ZMWindowShareType){
    ZMWindowShareTypeShareable4ZoomShare        = 0,
    ZMWindowShareTypeUnshareable4ZoomShare      = 1,
    ZMWindowShareTypeShareableAlways            = 2,
};

@interface NSWindow (ZoomShare)
@property(nonatomic,assign) ZMWindowShareType zmShareType;
@property(nonatomic,assign) BOOL zmShareTypeFollowParentWindow;//default is YES
@property(nonatomic,assign) BOOL zmPreventScreenCaptureWindow;//default is NO


// YES: window may become mouse-transparent during remote control (mouse events pass through)
// NO: normal mouse event handling (default)
// Replaces the legacy invisibleInSharing method
@property(nonatomic,assign) BOOL zmIgnoreMouseEventInRemoteControl;
@property(nonatomic,assign) BOOL zmIncludedInSharePicker;

- (BOOL)configWindowCaptureExcludeShape;
- (void)clearWindowCaptureExcludeShape;

@end
