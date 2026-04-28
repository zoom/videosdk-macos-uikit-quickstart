//
//  ZMMTCustomTextView.h
//  zVideoUI
//
//  Created by  Devl on 12/14/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTCustomTextViewDelegate <NSObject>

- (void)textViewDidBecomeActive;
- (void)textViewDidResignActive;

@end
@interface ZMMTCustomTextView : NSTextView

@property (nonatomic, weak) id<ZMMTCustomTextViewDelegate> mtDelegate;
@property (nonatomic, copy) NSString *mtPlaceHolder;
@property (nonatomic, assign) BOOL hasAttachment;
@property (nonatomic, assign) BOOL hasAttachments;   //mean count >= 2

- (void)updateContainAttachment;
- (void)inputNearFieldAttachment:(NSTextAttachment *)attachment;
- (NSArray<NSDictionary*> *)getAttanchmentItems;

@end

@interface ZMMTCustomInputView : NSView

@property (nonatomic, readonly) ZMMTCustomTextView *textView;
@property (nonatomic, strong) NSColor *borderColor;

@end

@interface ZMMTCustomTextAttachmentCell : NSTextAttachmentCell

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) id mtObject;

@end

NS_ASSUME_NONNULL_END
