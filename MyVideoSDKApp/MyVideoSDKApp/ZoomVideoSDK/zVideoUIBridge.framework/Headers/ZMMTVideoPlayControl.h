//
//  ZMMTVideoPlayControl.h
//  SaasBeeConfUIModule
//
//  Created by  Devl on 6/18/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import <zVideoUIBridge/ZMMTVideoView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTVideoPlayControlStyle) {
    ZMMTVideoPlayControlDefault,
    ZMMTVideoPlayControlMedia,//The style is the same as Default, with small ICONS.
    ZMMTVideoPlayControlSimple,
};

@protocol ZMMTVideoPlayDelegate <NSObject>

@property (readonly) NSInteger volume;
@property (readonly) BOOL isPlaying;

- (void)videoControlPlay;
- (void)videoControlUpdatePosition:(NSInteger)position;
- (void)videoControlUpdateVolume:(NSInteger)volume;
@optional
- (void)onVolumeMuted:(BOOL)isMuted;
- (void)videoControlSettingButtonAction:(NSButton *)sender;
- (void)videoControlFrameSizeDidChanged;

@end

@interface ZMMTVideoPlayControl : ZMMTBaseView

@property (nonatomic, weak) id<ZMMTVideoPlayDelegate> delegate;
@property (nonatomic, readonly) BOOL isShowVolume;
@property (nonatomic, assign) BOOL isShowSetting;
@property (nonatomic, assign) BOOL isShowTime;

- (instancetype)initWithStyle:(ZMMTVideoPlayControlStyle)style;

- (void)updateVideoDuration:(NSInteger)duration;
- (void)updateVideoPosition:(NSInteger)position;
- (void)updateVideoVolume:(NSInteger)volume;

- (void)updatePlayEnded;
- (void)updatePlayState;

- (BOOL)onKeyDown:(NSEvent *)event;

@end

@protocol ZMMTVideoTrackingDelegate <NSObject>
@optional
- (void)onMouseMoved:(NSEvent *)event;
- (void)onMouseExited:(NSEvent *)event;

- (BOOL)onMouseDown:(NSEvent *)event;
- (BOOL)onKeyDown:(NSEvent *)event;

@end

@interface ZMMTVideoTrackingView : ZMMTVideoView

@property (nonatomic, weak) id<ZMMTVideoTrackingDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
