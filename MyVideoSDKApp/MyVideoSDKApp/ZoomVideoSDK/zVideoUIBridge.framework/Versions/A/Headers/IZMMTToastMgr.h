//
//  IZMMTToastMgr.h
//  VideoUIBridge
//
//  Created by davies zhao on 2025/2/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTToastMgr <ZMRoutableObject>

/// Show a simple information toast with auto-disappear
/// @param message The message to display
- (void)showInfoToast:(NSString *)message;

/// Show a simple information toast
/// @param message The message to display
/// @param autoDisappear Whether the toast should auto-disappear
- (void)showInfoToast:(NSString *)message autoDisappear:(BOOL)autoDisappear;

/// Show a toast with identifier (for deduplication)
/// @param message The message to display
/// @param identifier Unique identifier for the toast
/// @param autoDisappear Whether the toast should auto-disappear
- (void)showInfoToast:(NSString *)message identifier:(nullable NSString *)identifier autoDisappear:(BOOL)autoDisappear;

#pragma mark - Screen Level Toast (Independent of Meeting Window)

/// Show a screen-level toast at the top-right corner of the screen
/// This toast is independent of the meeting window and will be visible even when:
/// - Meeting window is minimized
/// - Screen sharing is active
/// - Meeting window is in background
/// @param message The message to display
- (void)showScreenToast:(NSString *)message;

/// Show a screen-level toast with title at the top-right corner of the screen
/// @param title Optional title for the toast
/// @param message The message to display
- (void)showScreenToastWithTitle:(nullable NSString *)title message:(NSString *)message;

/// Show a screen-level toast with full configuration
/// @param title Optional title for the toast
/// @param message The message to display
/// @param autoDisappear Whether the toast should auto-disappear
/// @param needSpeak Whether to use VoiceOver to speak the message
- (void)showScreenToastWithTitle:(nullable NSString *)title
                         message:(NSString *)message
                   autoDisappear:(BOOL)autoDisappear
                       needSpeak:(BOOL)needSpeak;

@end

NS_ASSUME_NONNULL_END
