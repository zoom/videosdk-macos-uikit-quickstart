//
//  IZMMTStudioMgr.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/11/13.
//

#ifndef IZMMTStudioMgr_h
#define IZMMTStudioMgr_h

#import <zVideoUIBridge/ZMMTVideoViewController.h>
#import <zVideoUIBridge/IZMMTProductionStudioViewController.h>
#import <zTelemetryBiz/SnowplowBiz/meetings_v2/meetings_v2_telemetry_types.h>

@class ZMMTStudioScene;

/**
 * @router ZMMTShared
 */
@protocol IZMMTStudioMgr <ZMRoutableObject>

@optional
- (nullable ZMMTVideoViewController<IZMMTProductionStudioViewController> *)newViewControllerWithType:(ZMMTType)type;
- (BOOL)isStudioWindowShowing;
- (void)openStudioWindow;
- (void)closeStudioWindow;
- (void)stopLiving;
- (BOOL)isStudioLivingForHostCohost;
- (BOOL)isSendingLiveByMe;
- (void)startPumpPureVideoForProducer;
- (void)stopPumpPureVideoForProducer;
- (void)updatePrivateShareReceiver;

- (void)onPSLMixShareInfoChangedWithSourceID:(ZMShareSourceID)shareSourceID rect:(NSRect)rect;
- (void)onPSLInviteRequested:(BOOL)isSuccess message:(NSString *_Nullable)errorMessage;
- (void)onPSLLiveLayoutChanged:(CMM_USERID)sender_id layout:(const CmmPSLLayout&)layout;
- (void)onPSLControlCommandChanged:(const CmmRSGWControlData&)data;
- (ZMMTStudioScene *_Nullable)getLiveScene;

/// Returns the PS Scene Entity parameters for event tracking
/// This method decouples VideoUI from StudioUI by providing tracking data directly
- (MeetingsV2PsSceneEntityParams)getPSSceneEntityParams;
@end

#endif /* IZMMTStudioMgr_h */
