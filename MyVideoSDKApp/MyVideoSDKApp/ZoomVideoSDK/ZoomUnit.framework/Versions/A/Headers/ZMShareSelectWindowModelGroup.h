//
//  ZMShareSelectWindowModelGroup.h
//  ZoomUnit
//
//  Created by Walt.Li on 2024/1/30.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ZoomUnit/ZPShareSelectWindowModel.h>

@class ZMShareSelectCustomView;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMShareSelectGroupContentMode) {
    ZMShareSelectGroupContentModeStandardTiles = 0,
    ZMShareSelectGroupContentModeCustomView,
};

@interface ZMShareSelectWindowModelGroup : NSObject

@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly, copy) NSArray<ZPShareSelectWindowModel *> *content;
@property (nonatomic, assign) BOOL hasNewTag;
@property (nonatomic, readonly, assign) ZMShareSelectGroupContentMode contentMode;
/// The owning top-level segment. Nil keeps the legacy factory semantics for callers
/// that do not use the segmented share picker layout.
@property (nullable, nonatomic, readonly, copy) NSNumber *segmentIdentifier;

/// Non-nil iff contentMode == CustomView.
@property (nullable, nonatomic, readonly, strong) ZMShareSelectCustomView *customContentView;
@property (nonatomic, readonly, assign) CGSize customContentSize;

- (void)updateCustomContentSize:(CGSize)size;

+ (instancetype)modelGroupWithTitle:(NSString *)title
                            content:(NSArray<ZPShareSelectWindowModel *> *)content;

+ (instancetype)modelGroupWithTitle:(NSString *)title
                            content:(NSArray<ZPShareSelectWindowModel *> *)content
                   segmentIdentifier:(nullable NSNumber *)segmentIdentifier;

+ (instancetype)modelGroupWithTitle:(NSString *)title
                  customContentView:(ZMShareSelectCustomView *)customContentView
                        contentSize:(CGSize)contentSize;

+ (instancetype)modelGroupWithTitle:(NSString *)title
                  customContentView:(ZMShareSelectCustomView *)customContentView
                        contentSize:(CGSize)contentSize
                   segmentIdentifier:(nullable NSNumber *)segmentIdentifier;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
