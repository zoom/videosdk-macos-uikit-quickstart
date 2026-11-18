//
//  ZMMTTranscriptTextSearcher.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 9/6/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTTranscriptMessage.h>

NS_ASSUME_NONNULL_BEGIN

struct ZMMTTranscriptSearchResultNode {
    BOOL isInTimeString;
    NSRange range;
    __weak ZMMTTranscriptTextMessage *message;
};
typedef struct ZMMTTranscriptSearchResultNode ZMMTTranscriptSearchResultNode;

@class ZMMTTranscriptTextSearcher;

@protocol ZMMTTranscriptTextSearcherProtocol <NSObject>
- (void)searchDidComplete:(ZMMTTranscriptTextSearcher *)textSearcher;
- (void)highlightStateDidChangeForMessage:(ZMMTTranscriptTextMessage *)message makeMessageVisible:(BOOL)visible;
@end
 
@interface ZMMTTranscriptTextSearcher : NSObject
@property (nonatomic, weak) id<ZMMTTranscriptTextSearcherProtocol> delegate;

@property (nonatomic, strong) NSArray<ZMMTTranscriptMessage *> *messageList;
@property (nonatomic, assign, readonly) NSUInteger resultNodeCount;
- (void)cleanResultNodes;
- (ZMMTTranscriptSearchResultNode)resultNodeAtIndex:(NSUInteger)index;

// Search
- (void)prepareForSearch;
- (void)searchInMessageList:(NSArray<ZMMTTranscriptMessage *> *)messageList targetString:(NSString *)targetString;

// Highlight
@property (nonatomic, assign) NSInteger highlightedResultNodeIndex;
- (void)highlightPreviousResultNode;
- (void)highlightNextResultNode;
- (void)highlightCurrentResultNodeAndMakeVisible;
@end

NS_ASSUME_NONNULL_END
