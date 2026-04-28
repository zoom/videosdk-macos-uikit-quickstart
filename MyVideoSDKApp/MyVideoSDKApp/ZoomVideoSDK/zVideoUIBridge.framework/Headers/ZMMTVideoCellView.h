//
//  ZMMTVideoCellView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 1/11/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseVideoCellView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTVideoCellViewDelegate;
@class ZMMenu;
@class ZMMTVideoRenderView;
@class ZMMTRaiseHandIndexView;
@class ZMCustomEmojiView;
@class ZMMTTimeLabelView;
@class ZMMTTopTipBarView;
@interface ZMMTVideoCellView : ZMMTBaseVideoCellView
@property (nonatomic, weak) id<ZMMTVideoCellViewDelegate> delegate;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, retain, nullable) ZMMTVideoRenderView *videoItem;
#pragma clang diagnostic pop
@property (nonatomic, nullable, retain) PZMMenu* moreMenu;
- (BOOL)enableShowMoreButton;
- (BOOL)enableShowBorderView;

@property (nonatomic, assign) ZMVideoMenuPlaceID placeID;

@property (nonatomic, retain) NSImageView *reactionsView;
@property (nonatomic, retain) ZMMTRaiseHandIndexView *raiseHandView;
@property (nonatomic, retain) ZMButton *moreButton;
@property (nonatomic, retain) ZMButton *unmuteButton;
@property (nonatomic, retain) NSView<ZMLottieViewDelegate> *lottieView;
@property (nonatomic, retain) NSString *lottieName;
@property (nonatomic, retain) ZMButton *liveButton;
@property (nonatomic, retain) ZMButton *requestShareButton;
@property (nonatomic, retain) ZMCustomEmojiView *customEmojiView;
@property (nonatomic, retain) ZMMTTimeLabelView *timeLabelView;
@property (nonatomic, retain) ZMMTTopTipBarView *topTipBarView;
@end

NS_ASSUME_NONNULL_END
