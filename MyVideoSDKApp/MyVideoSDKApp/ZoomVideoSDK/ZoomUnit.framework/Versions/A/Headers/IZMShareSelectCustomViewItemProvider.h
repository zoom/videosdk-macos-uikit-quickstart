//
//  IZMShareSelectCustomViewItemProvider.h
//  ZoomUnit
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZPShareSelectWindowModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMShareSelectCustomViewItemProvider <NSObject>

@required

- (nullable ZPShareSelectWindowModel *)currentSelectedItemModel;
- (BOOL)hasInternalSelection;
- (void)clearInternalSelection;

@optional

- (void)makeInternalFirstResponder;
- (nullable NSArray<NSView *> *)customKeyViews;
/// YES while a popup menu anchored to this custom view is on screen. The picker
/// uses this to freeze content scrolling (same idea as meeting plist + PZMMenu).
- (BOOL)hasBlockingOverlayMenu;
- (void)closeBlockingOverlayMenuIfNeeded;

@end

NS_ASSUME_NONNULL_END
