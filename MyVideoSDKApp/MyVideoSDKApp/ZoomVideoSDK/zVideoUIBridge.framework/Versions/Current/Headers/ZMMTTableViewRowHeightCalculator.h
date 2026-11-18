//
//  ZMMTTableViewRowHeightCalculator.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 9/9/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMMTHeightCalculableProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMMTTableViewRowHeightCalculator;

@interface ZMMTTableViewRowHeightCalculatorContext : NSObject
@property (nonatomic, assign) BOOL asynchronously;
@property (nonatomic, assign) CGFloat limitWidth;
@end

@protocol ZMMTTableViewRowHeightCalculatorDelegate <NSObject>
- (CGFloat)getLimitWidth:(ZMMTTableViewRowHeightCalculator *)calculator;
@end

@interface ZMMTTableViewRowHeightCalculator : NSObject
@property (nonatomic, weak) NSTableView *tableView;
// Must init calculator after tableView is attached to scrollView.
- (instancetype)initWithTableView:(NSTableView *)tableView;

@property (nonatomic, weak) id<ZMMTTableViewRowHeightCalculatorDelegate> delegate;

// Calculate height asynchronously when item count greater than asyncThreshold. Default is 1000.
@property (nonatomic, assign) NSUInteger asyncThreshold;
@property (nonatomic, assign) CGFloat defaultRowHeight;

@property (nonatomic, strong, nullable) NSArray<id<ZMMTHeightCalculableProtocol>> *items;
- (CGFloat)heightOfRow:(NSInteger)row;

- (NSRange)updateAllAvailableRowHeights;
- (void)updateAllRowHeighs;

- (void)forceCalculateHeightOfItem:(id<ZMMTHeightCalculableProtocol>)item;
- (void)forceCalculateHeightOfItems:(NSArray<id<ZMMTHeightCalculableProtocol>> *)items;
@end

NS_ASSUME_NONNULL_END
