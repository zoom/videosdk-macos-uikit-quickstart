//
//  IZPConfToolbarTipsMgr.h
//  VideoUIBridge
//
//  Created by MolayYu on 2/24/26.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#ifndef IZPConfToolbarTipsMgr_h
#define IZPConfToolbarTipsMgr_h

#import <AppKit/AppKit.h>
#import <Prism/ZMRoutableObject.h>

@class ZMTipWindow;

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZPConfToolbarTipsMgr <ZMRoutableObject>

#pragma mark - Generic tip
- (void)showWithTip:(NSString *)inTip
               font:(nullable NSFont *)inFont
           inScreen:(nullable NSScreen *)inScreen;
- (void)showWithTip:(NSString *)inTip
               font:(nullable NSFont *)inFont
           inScreen:(nullable NSScreen *)inScreen
          needSpeak:(BOOL)needSpeak;
- (void)showNextTip;
- (void)closeTipWithString:(NSString *)inTip;
- (void)closeAllAutoCloseTip;

#pragma mark - Manual close tip
- (void)showManualCloseTip:(NSString *)inTip
                      font:(nullable NSFont *)inFont
                  inScreen:(nullable NSScreen *)inScreen;
- (NSRect)getLastManualCloseTipWndFrame;
- (void)closeAllManualCloseTip;

#pragma mark - Host / role change
- (void)loseHostOrCoHost;

#pragma mark - Temporarily-unmuted tip
- (void)showTempUnmuteTip;
- (void)hideTempUnmuteTip;

#pragma mark - Voice broadcast
- (void)showVoiceBroadcast;
- (void)hideVoiceBroadcast;

#pragma mark - Indicator tip
- (void)showIndicatorTip:(ZMTipWindow *)newIndicatorTip
            parentWindow:(nullable NSWindow *)parentWnd
               delayHide:(float)delay;
- (void)removeIndicatorTipWithTag:(NSInteger)tag;
- (void)updateIndicatorTipWithTag:(NSInteger)tag;
- (nullable ZMTipWindow *)getIndicatorTipWithTag:(NSInteger)tag;
- (NSRect)getTipArrowBaseRectWithTag:(NSInteger)tag;

@end

NS_ASSUME_NONNULL_END

#endif /* IZPConfToolbarTipsMgr_h */
