//
//  ZPShareSelectCustomViewItem.h
//  ZoomUnit
//

#import <Cocoa/Cocoa.h>

@class ZMShareSelectCustomView;

NS_ASSUME_NONNULL_BEGIN

@interface ZPShareSelectCustomViewItem : NSCollectionViewItem

- (void)attachContentView:(nullable ZMShareSelectCustomView *)contentView;

@end

NS_ASSUME_NONNULL_END
