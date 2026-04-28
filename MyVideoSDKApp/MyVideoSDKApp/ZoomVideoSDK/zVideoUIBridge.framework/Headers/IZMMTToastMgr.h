//
//  IZMMTToastMgr.h
//  VideoUIBridge
//
//  Created by davies zhao on 2025/2/21.
//

#import <Foundation/Foundation.h>

@class ZMToast;
@class PZMToastCoordinator;

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTToastMgr <ZMRoutableObject>

#pragma mark - Basic Toast Operations

/// Add a toast to the coordinator
/// @param toast The toast to add
- (void)addToast:(ZMToast *)toast NS_SWIFT_NAME(addToast(_:));

/// Remove a toast from the coordinator
/// @param toast The toast to remove
- (void)removeToast:(ZMToast *)toast NS_SWIFT_NAME(removeToast(_:));

/// Fetch a toast by its identifier
/// @param identifier The unique identifier of the toast
/// @return The toast if found, nil otherwise
- (nullable ZMToast *)fetchToastWithIdentifier:(NSString *)identifier;

#pragma mark - Compatibility

/// Get the underlying toast coordinator for advanced operations
/// @warning This method is for compatibility with ZoomAppUI. New code should use the protocol methods instead.
/// @return The toast coordinator instance
- (nullable PZMToastCoordinator *)getToastCoordinator;

#pragma mark - Simple Toast API

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

/// Show a screen-level toast with type
/// @param message The message to display
/// @param type The toast type (information, warning, error, etc.)
- (void)showScreenToast:(NSString *)message type:(ZMToastType)type;

/// Show a screen-level toast with type and title
/// @param title Optional title for the toast
/// @param message The message to display  
/// @param type The toast type (information, warning, error, etc.)
- (void)showScreenToastWithTitle:(nullable NSString *)title
                         message:(NSString *)message
                            type:(ZMToastType)type;

@end

NS_ASSUME_NONNULL_END
