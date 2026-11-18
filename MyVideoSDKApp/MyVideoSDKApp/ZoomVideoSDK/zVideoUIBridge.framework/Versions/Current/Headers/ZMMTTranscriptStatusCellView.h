//
//  ZMMTTranscriptStatusCellView.h
//  VideoUI
//
//  Created by Karen Cao on 2026-02-25.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTTranscriptMessage.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTTranscriptStatusCellView : ZMBaseTableCellView

@property (nonatomic, strong) ZMMTTranscriptStatusMessage *message;

- (void)updateUIWithMessage:(ZMMTTranscriptStatusMessage *)message;

@end

NS_ASSUME_NONNULL_END
