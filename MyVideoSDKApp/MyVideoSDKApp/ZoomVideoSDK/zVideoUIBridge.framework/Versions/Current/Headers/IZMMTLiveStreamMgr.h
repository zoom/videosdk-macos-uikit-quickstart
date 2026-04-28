//
//  IZMMTLiveStreamMgr.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2026/2/10.
//

#import <Foundation/Foundation.h>

@class ZMUser;
@class ZMMTLiveStreamModel;
@class ZMBubbleObject;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTLiveStreamMgr <NSObject>

#pragma mark - Toolbar
- (BOOL)shouldShowToolbarEntrance;
- (BOOL)shouldShowToolbarMenuItems;

#pragma mark - Status
- (nullable NSString *)liveStreamViewerUrl; //ZOOM-158179
- (BOOL)isLiveStreamAvailable;
- (BOOL)isLivestreamMenuDisabled;
- (BOOL)isLiveOnOrConnecting;
- (BOOL)isLiveConnecting;
- (BOOL)hasLiveOnStream;
- (BOOL)shouldShowLiveOnEventLobbyIcon;
- (BOOL)isKVSIndicatorShowing;
- (BOOL)shouldShowNewLiveStreamText;

#pragma mark - Operations
- (void)startLiveStreamForChannelKey:(NSString *)channelKey;
- (void)stopLiveStreamForKey:(nullable NSString *)key; // if nil, stop all
- (void)stopLiveStreamForModel:(ZMMTLiveStreamModel *)model;
- (void)openLiveStreamLink:(ZMMTLiveStreamModel *)model;

#pragma mark - Channel Info
- (nullable NSString *)getLiveOnOrConnectingChannelKey;
- (nullable NSArray<NSString *> *)getLiveOnChannelKeys;
- (nullable NSString *)getChannelNameForChannelKey:(NSString *)key;
- (nullable NSString *)getViewerURLForChannelKey:(NSString *)inKey;
- (BOOL)hasViewerURLForChannelKey:(NSString *)inKey;
- (void)openViewerURLForChannelkey:(NSString *)inChannelkey;
- (void)copyViewerURLForChannelkey:(NSString *)inChannelkey;
- (nullable NSString *)getLiveStreamTitle;
- (nullable NSString *)getLiveOnTip;

#pragma mark - Bubble
@property(nonatomic, strong, readonly, nullable) ZMBubbleObject* liveStreamBubble;
- (BOOL)isLiveStreamBubbleShowing;
- (void)relayoutLiveStreamBubble;

#pragma mark - Callbacks
- (void)liveStreamStatusChanged:(int)bLiveOn;
- (void)liveStreamStatusChangedIndex:(uint32_t)index;
- (void)liveStreamStartTimeOut:(int)index;
- (void)liveStreamOnNDIStatusChanged; // ZOOM-273351
- (void)onLobbyStatusChanged; //ZOOM-297016
- (void)updateLobbyWhenStatusChanged;
- (void)onReceiveLiveURL:(NSString *)url;
- (void)onReceiveLivePrivilege:(const ReqLocalLiveStreamParam&)param;
- (void)onLocalLiveStreamStatusChanged:(ZMUser*)zmUser;
- (void)grantLocalLiveStreamPrivilege;
- (void)rejectLocalLiveStreamPrivilege;
- (void)cancelLocalLiveStreamPrivilege;
- (void)willShowLiveStreamBubble;
- (void)userLeft:(ZMUser *)user;

@end

NS_ASSUME_NONNULL_END
