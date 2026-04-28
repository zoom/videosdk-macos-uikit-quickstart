//
//  IZMLiveStreamToLobbyMgr.h
//  VideoUIBridge
//
//  Created for LiveStream to Zoom Events Lobby
//

#ifndef IZMLiveStreamToLobbyMgr_h
#define IZMLiveStreamToLobbyMgr_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMLiveStreamToLobbyMgr <ZMRoutableObject>

#pragma mark - Toolbar
- (BOOL)shouldShowToolbarEntrance;
- (BOOL)shouldShowToolbarMenuItems;

@property (nonatomic, assign, readonly) BOOL isPending;

#pragma mark - Meeting
- (BOOL)startLiveStreamToZoomEventsLobby;
- (BOOL)stopLiveStreamToZoomEventsLobby;
- (void)onStartLivestreamToZoomEventsFail:(NSInteger)code;
- (void)onStopLivestreamToZoomEventsFail:(NSInteger)code;
- (void)onStartLivestreamToZoomEventsTimeOut;
- (void)onStopLivestreamToZoomEventsTimeOut;

#pragma mark - Callbacks
- (void)onConfReady;
- (void)onLobbyStatusChanged;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMLiveStreamToLobbyMgr_h */
