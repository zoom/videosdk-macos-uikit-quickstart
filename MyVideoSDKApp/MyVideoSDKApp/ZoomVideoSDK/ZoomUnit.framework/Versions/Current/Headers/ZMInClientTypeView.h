//
//  ZMInClientTypeView.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/10/27.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMBannerType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMInClientTypeView : ZMAccessibleView

@property (assign, nonatomic) BANNER_TYPE type;
@property (copy, nonatomic) NSString *title;
@property (copy, nonatomic) NSFont *font;
@property (copy) NSArray *colors;
@property (nonatomic) CGPoint customizeStartPoint;
@property (nonatomic) CGPoint customizeEndPoint;
@property (nonatomic) BOOL needVerticalCenter;

- (void)sizeToFit;

@end

NS_ASSUME_NONNULL_END
