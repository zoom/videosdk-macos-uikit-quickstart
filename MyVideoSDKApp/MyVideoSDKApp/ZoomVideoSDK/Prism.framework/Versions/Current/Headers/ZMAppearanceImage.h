//
//  PrismImage.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/22.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@interface PrismImage : NSImage

@property (nonatomic, strong) NSImage *lightImg;
@property (nonatomic, strong) NSImage *darkImg;

+ (NSImage*)imageNamed:(NSImageName)name;
+ (NSImage*)imageNamed:(NSImageName)lightName darkName:(NSImageName)darkName;

- (PrismImage *)initImageWithLight:(NSImage *)lightImg darkImg:(NSImage *)darkImg;

- (NSImage *)currentAppearanceImage;
@end
typedef PrismImage ZMAppearanceImage NS_SWIFT_NAME(Image);

@interface NSImage(PrismImage)
/// support dark and light mode
+ (instancetype)zmImageWithSize:(NSSize)size drawingHandler:(void (^)(NSRect rect))drawingHandler;
@end

NS_ASSUME_NONNULL_END
