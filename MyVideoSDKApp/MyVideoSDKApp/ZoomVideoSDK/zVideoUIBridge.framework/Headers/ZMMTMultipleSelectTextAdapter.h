//
//  ZMMTMultipleSelectTextAdapter.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/26/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMMTMultipleSelectTableView.h"
#import "ZMMTSelectableTextItemProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMMTMultipleSelectTextAdapter;

@protocol ZMMTMultipleSelectTextAdapterDelegate <NSObject>
@optional
// Default is YES
- (BOOL)shouldCopyText:(ZMMTMultipleSelectTextAdapter *)adapter;
@end

@interface ZMMTMultipleSelectTextAdapter : NSObject <ZMMTMultipleSelectTableViewProtocol>
@property (nonatomic, weak) id<ZMMTMultipleSelectTextAdapterDelegate> delegate;

@property (nonatomic, strong) NSArray<id<ZMMTSelectableTextItemProtocol>> *textItems;

- (void)selectAllTextWithTableView:(NSTableView *)tableView;
- (void)unselectAllTextWithTableView:(NSTableView *)tableView;
@end

NS_ASSUME_NONNULL_END
