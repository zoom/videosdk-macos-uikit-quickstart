//
//  IZMMTCustomSharePort.h
//  VideoUIBridge
//
//  Copyright © 2026 zoom.us. All rights reserved.
//

#ifndef IZMMTCustomSharePort_h
#define IZMMTCustomSharePort_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTCustomRecordingInfo;

@protocol IZMMTCustomSharePort <NSObject>

@property (nonatomic, readonly) NSView *view;
@property (nonatomic, readonly) BOOL isViewShowing;
@property (nonatomic, readonly) BOOL isInRemoteControllingOther;
@property (nonatomic, retain, nullable) ZMConfSession *confSession;
@property (nonatomic, readonly) ZMShareSource *zmShareSource;

- (void)startVideo;
- (void)stopVideo;
- (void)destroyRender;

- (nullable ZMMTCustomRecordingInfo *)getRecordingInfo;

- (void)onMouseDown:(NSEvent *)event;
- (void)onMagnifyWithEvent:(NSEvent *)event;
- (void)onSmartMagnifyWithEvent:(NSEvent *)event;
- (void)onSwipeWithEvent:(NSEvent *)event;
- (void)startSharingViewWithShareSource:(ZMShareSource *)zmShareSource;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTCustomSharePort_h */
