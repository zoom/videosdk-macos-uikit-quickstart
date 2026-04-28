//
//  ZMTokenTextAttachmentCell.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/22.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMPTBaseTextAttachmentCell.h>

@interface ZMTokenTextAttachmentCell : NSTextAttachmentCell <ZMTrackingTextAttachmentCell>

@property(nonatomic, copy) NSString *name;

@property(nonatomic, retain) NSDictionary *userInfo;

@property (nonatomic,copy) void (^remove)(ZMTokenTextAttachmentCell *cell);

@property (nonatomic,copy) void (^expand)(ZMTokenTextAttachmentCell *cell, NSUInteger atCharacterIndex);

@property (nonatomic,copy) void (^hoverAvatar)(ZMTokenTextAttachmentCell *cell,BOOL isKeyPress);

@property (nonatomic, assign) BOOL isShowExternal;
@property (nonatomic, assign) BOOL isShowPending;
@property (nonatomic, assign) BOOL isShowAdded;

//default YES
@property (nonatomic, assign) BOOL isNeedShowCloseButton;

//default NO
@property (nonatomic, assign) BOOL isNeedShowExpandButton;

@property (readonly) NSRect closeIconRect;

@property (readonly) NSRect expandIconRect;

@property (readonly) NSRect frame;

@property (readonly) NSRect avatarRect;

@property (readonly) NSView *drawControlView;

@property (nonatomic, assign) BOOL expandEnable;

@property (nonatomic, strong) NSColor *borderColor;

@property (nonatomic, strong) NSColor *backgroundColor;

@property (nonatomic, strong) NSColor *highlightBackgroundColor;

@property (nonatomic, strong) NSString *accessibilityDescription;

@property (nonatomic, strong) NSColor *textColor;

@property (nonatomic, copy) NSString *closeButtonLabel;

@property (nonatomic, assign) BOOL isNeedShowAvatar;

@property (nonatomic, assign) BOOL isNeedShowAvatarAX;

@property (nonatomic, strong) NSImage *avatar;

@property (nonatomic, strong) NSColor *avatarBackgroundColor;

@property (nonatomic, assign) NSEdgeInsets avatarEdgeInset;

@property (nonatomic, assign) BOOL isNeedInverserAvatarWhenHighlight;

- (NSAttributedString *)attributedString;

@end
