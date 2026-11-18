//
//  ZMMTTranscriptTextCellView.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/31/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMultipleSelectCellViewProtocol.h>
#import <zVideoUIBridge/ZMMTMessageTextView.h>
#import <zVideoUIBridge/ZMMTTranscriptMessage.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTTranscriptTextCellView : NSTableCellView <ZMMultipleSelectCellViewProtocol>
@property (nonatomic, strong, readonly) ZMMTMessageTextView *contentTextView;

- (void)updateUIWithMessage:(ZMMTTranscriptTextMessage *)message;
@end

NS_ASSUME_NONNULL_END
