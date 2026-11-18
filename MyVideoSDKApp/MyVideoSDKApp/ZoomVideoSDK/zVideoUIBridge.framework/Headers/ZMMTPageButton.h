//
//  ZMMTPageButton.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2026/8/7.
//

#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMTPageButtonDirection) {
    ZMMTPageButtonDirectionLeft = 0,
    ZMMTPageButtonDirectionRight,
    ZMMTPageButtonDirectionUp,
    ZMMTPageButtonDirectionDown,
};

@interface ZMMTPageButton : ZMButton
@property(nonatomic, assign) ZMMTPageButtonDirection direction;
@property(nonatomic, assign) NSInteger currentPageNumber;
@property(nonatomic, assign) NSInteger totalPageNumber;

- (instancetype)initWithFrame:(NSRect)frameRect direction:(ZMMTPageButtonDirection)direction;
+ (instancetype)buttonWithDirection:(ZMMTPageButtonDirection)direction;
@end

NS_ASSUME_NONNULL_END
