//
//  ZMMTTranscriptUserInfoCellView.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/31/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTMessageTextView.h>
#import <zVideoUIBridge/ZMMTTranscriptMessage.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTTranscriptUserInfoCellView;
@protocol ZMMTTranscriptUserInfoCellViewDelegate <NSObject>
- (void)userInfoCellView:(ZMMTTranscriptUserInfoCellView *)userInfoCellView didClickEditButton:(id)sender;
- (BOOL)userInfoCellView:(ZMMTTranscriptUserInfoCellView *)userInfoCellView canShowEditButtonForMessage:(ZMMTTranscriptUserInfoMessage *)message;
@end

@interface ZMMTTranscriptUserInfoCellView : ZMBaseTableCellView
@property (nonatomic, weak) id<ZMMTTranscriptUserInfoCellViewDelegate> delegate;

@property (nonatomic, strong) ZMMTTranscriptUserInfoMessage *message;

@property (nonatomic, strong, readonly) NSImageView *avatarImageView;
@property (nonatomic, strong, readonly) ZMLabel *userNameLabel;
@property (nonatomic, strong, readonly) ZMLabel *userNameSuffixLabel;
@property (nonatomic, strong, readonly) ZMLabel *timeLabel;

- (void)updateUIWithMessage:(ZMMTTranscriptUserInfoMessage *)message;
@end

NS_ASSUME_NONNULL_END
