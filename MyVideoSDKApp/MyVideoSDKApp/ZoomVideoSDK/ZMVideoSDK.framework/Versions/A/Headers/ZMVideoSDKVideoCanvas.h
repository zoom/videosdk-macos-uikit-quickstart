
/**
 * @file ZMVideoSDKVideoCanvas.h
 * @brief Interface for video/share canvas rendering in Zoom Video SDK.
 */

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKVideoCanvas
 * @brief Manages the rendering of video or screen share content in the Zoom Video SDK.
 */
@interface ZMVideoSDKVideoCanvas : NSObject
/**
 * @brief The canvas type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKCanvasType canvasType;

/**
 * @brief Subscribes to video or share data.
 * @param view The NSView object, needed to render video or share.
 * @param aspect The aspect ratio of the video or share.
 * @param resolution Specified the resolution of video. valid only for subscribe video.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)subscribeWithView:(NSView * _Nonnull)view aspectMode:(ZMVideoSDKVideoAspect)aspect resolution:(ZMVideoSDKResolution)resolution;

/**
 * @brief Unsubscribes to video or share data.
 * @param view The NSView object, needed to render video or share.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSubscribeWithView:(NSView * _Nonnull)view;

/**
 * @brief Sets the video or share aspect mode.
 * @param view The NSView object, needed to render video or share.
 * @param aspect The aspect ratio of the video or share.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setAspectMode:(NSView* _Nonnull)view aspect:(ZMVideoSDKVideoAspect)aspect;

/**
 * @brief Sets the resolution.
 * @param view The NSView object, needed to render video.
 * @param resolution The video's resolution.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @warning Avaliable only for subscribe video, unavaliable for subscribe sharing.
 */
- (ZMVideoSDKErrors)setResolution:(NSView* _Nonnull)view resolution:(ZMVideoSDKResolution)resolution;

/**
 * @brief Captures a snapshot of the current frame rendered in the specified NSView and returns it as an NSImage.
 * @param view The NSView object displaying the video or share content.
 * @return An NSImage containing the captured frame, or nil if the snapshot could not be taken.
 */
- (NSImage * _Nullable)takeSnapshot:(NSView*)view;
@end
NS_ASSUME_NONNULL_END
