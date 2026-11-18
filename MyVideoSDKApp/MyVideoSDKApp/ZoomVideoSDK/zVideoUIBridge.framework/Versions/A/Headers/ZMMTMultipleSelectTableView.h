//
//  ZMMTMutipleSelectTableView.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/23/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTMultipleSelectContext, ZMMTMultipleSelectTableView;

@protocol ZMMTMultipleSelectTableViewProtocol <NSObject>
@optional
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView mouseDownEventWillStart:(NSEvent *)event;
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView clickAtPoint:(NSPoint)point event:(NSEvent *)event;
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView multipleClickAtPoint:(NSPoint)point event:(NSEvent *)event;
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView rightClickAtPoint:(NSPoint)point event:(NSEvent *)event;

// Will call these method if shouldTrackMouseMovedEvent is set to YES.
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView hoverAtRow:(NSInteger)row;
- (void)tableView:(ZMMTMultipleSelectTableView *)tableView unhoverAtRow:(NSInteger)row;

- (void)tableView:(ZMMTMultipleSelectTableView *)tableView selectWithContext:(ZMMTMultipleSelectContext *)context;

// intercept key down events.
- (BOOL)tableView:(ZMMTMultipleSelectTableView *)tableView onKeyDownEvent:(NSEvent *)event;
@end

@interface ZMMTMultipleSelectContext : NSObject
@property (nonatomic, assign, readonly) NSPoint startPoint;
@property (nonatomic, assign, readonly) NSPoint endPoint;

@property (nonatomic, assign, readonly) NSRange selectedRows;
@end

// Note: To support multiple selection, view in subtree should forward some events to tableView.
// ZMMTMessageTextView is a example.
@interface ZMMTMultipleSelectTableView : NSTableView
@property (nonatomic, weak) id<ZMMTMultipleSelectTableViewProtocol> multipleSelectDelegate;

@property (nonatomic, assign) BOOL shouldTrackMouseMovedEvent;

@property (nonatomic, copy) NSString *customAccLabel;
@end

NS_ASSUME_NONNULL_END
