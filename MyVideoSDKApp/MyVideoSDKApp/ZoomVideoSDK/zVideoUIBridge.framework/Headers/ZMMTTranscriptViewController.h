//
//  ZMMTTranscriptViewController.h
//  VideoUI
//
//  Created by martin yu on 2025/12/22.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Prism/Prism.h>
#import <zVideoUIBridge/ZMMTTranscriptMessage.h>
#import <zVideoUIBridge/ZMMTMultipleSelectTableView.h>
#import <zVideoUIBridge/ZMMTMultipleSelectTextAdapter.h>
#import <zVideoUIBridge/ZMMTTableViewRowHeightCalculator.h>
#import <zVideoUIBridge/ZMMTTranscriptUserInfoCellView.h>
#import <zVideoUIBridge/IZMMTUserStatusProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#define ZMMTTranscriptShowTimeStringInterval 300 // 5 min

@interface ZMMTTranscriptTableView : ZMMTMultipleSelectTableView
@end

@class ZMMTTranscriptViewController;
@protocol ZMMTTranscriptViewControllerDelegate <NSObject>
- (BOOL)isTranscriptViewControllerShowing:(ZMMTTranscriptViewController *)viewController;
@end

@interface ZMMTTranscriptViewController : ZMBaseViewController <ZMMTTranscriptUserInfoCellViewDelegate, ZMMTMultipleSelectTextAdapterDelegate, ZMMTTableViewRowHeightCalculatorDelegate, IZMMTUserStatusProtocol>
@property (nonatomic, weak) id<ZMMTTranscriptViewControllerDelegate> delegate;

@property (nonatomic, strong) NSSearchField *searchField;
@property (nonatomic, strong) NSScrollView *scrollView;
@property (nonatomic, strong) ZMMTTranscriptTableView *tableView;
@property (nonatomic, strong) ZMMTMultipleSelectTextAdapter *multipleSelectTextAdapter;
@property (nonatomic, strong) ZMMTTableViewRowHeightCalculator *rowHeightCalculator;

@property (nonatomic, strong) NSDictionary *textAttribute;
@property (nonatomic, strong) NSDictionary *statusAttribute;
@property (nonatomic, strong) NSDictionary *timeAttribute;

@property (nonatomic, strong) NSMutableArray<__kindof ZMMTTranscriptMessage *> *messageList;

@property (nonatomic, assign) BOOL hasMessageReceived;

@property (nonatomic, strong) ZMButton *saveButton;
@property (nonatomic, strong) ZMBaseView *bottomContainer;
@property (nonatomic, strong) ZMBaseView *dividerView;

- (void)setupSaveButton;
- (void)setupBottomSection;
- (void)configureSaveButtonLayout; 
- (void)onSaveButtonClicked:(id)sender; 
- (BOOL)shouldReceiveLTRawMessage:(ZMMTTranscriptRawMessage *)rawMessage operationType:(int)operationType;
- (void)onReceiveLTRawMessage:(ZMMTTranscriptRawMessage *)rawMessage operationType:(int)operationType;
- (void)updateUser:(ZMMTTranscriptUser *)user forTextMsg:(ZMMTTranscriptTextMessage *)textMsg;

- (void)onTextMessageDidUpdate:(ZMMTTranscriptTextMessage *)textMessage
                    rawMessage:(ZMMTTranscriptRawMessage *)rawMessage
                      curIndex:(NSUInteger)curIndex;
- (nullable NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(nullable NSTableColumn *)tableColumn row:(NSInteger)row;

#pragma mark - Groupped By Time
- (BOOL)updateShouldShowTimeStringForMsg:(ZMMTTranscriptTextMessage *)msg inMsgList:(NSArray<ZMMTTranscriptMessage *> *)msgList isRegroup:(BOOL)isRegroup;
- (BOOL)insertLastUserInfoMsgInMsgListIfNeeded:(NSMutableArray<ZMMTTranscriptMessage *> *)msgList shouldInsertToListView:(BOOL)shouldInsertToListView;
- (BOOL)insertLastUserInfoMsgInMsgListIfNeeded:(NSMutableArray<ZMMTTranscriptMessage *> *)msgList shouldInsertToListView:(BOOL)shouldInsertToListView timeAttributedString:(nullable NSAttributedString *)timeAttributedString;

#pragma mark - Helper
- (void)reloadAvailableUserInfoCellViews;
- (BOOL)shouldScrollToEndWithLastAddedMsgCount:(NSInteger)lastAddedMsgCount;
- (void)scrollToEndIfNeededWithLastAddedMsgCount:(NSInteger)lastAddedMsgCount;
- (BOOL)scrollViewIsAtBottom:(NSScrollView *)scrollView;
- (BOOL)isTranscriptViewControllerShowing;

- (NSMutableDictionary *)textAttributesWithWritingDirection:(NSWritingDirection)writingDirection;

#pragma mark - Keyboard Navigation
- (void)didDockContentToSidePanel;
- (void)didReturnFromSaveDialog;
@end

NS_ASSUME_NONNULL_END
