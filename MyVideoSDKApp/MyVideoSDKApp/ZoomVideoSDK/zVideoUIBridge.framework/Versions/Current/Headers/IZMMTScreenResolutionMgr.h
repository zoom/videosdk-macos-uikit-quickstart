//
//  IZMMTScreenResolutionMgr.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2025/5/12.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTScreenResolutionMgr <ZMRoutableObject>

/// Check and update 4K display support status
/// @param forceUpdate If YES, always notify video views to update regardless of status change
- (void)checkIfSupport4kDisplayWithForceUpdate:(BOOL)forceUpdate;

/// Query whether current display supports 4K resolution
/// @return YES if supports 4K display, NO otherwise
- (BOOL)canSupport4KDisplay;

/// Called when enhanced media feature status changed
/// @param enable YES if enhanced media feature is enabled
- (void)onEnhancedMediaFeatureStatusChanged:(BOOL)enable;

@end


NS_ASSUME_NONNULL_END
