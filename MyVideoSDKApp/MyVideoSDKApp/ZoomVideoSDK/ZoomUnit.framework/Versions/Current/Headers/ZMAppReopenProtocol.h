//
//  ZMAppReopenProtocol.h
//  ZoomUnit
//
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
static const ZMEventPriority ZMAppReopenPriorityMeeting   = 100;   // Meeting/Conference window (highest priority)
static const ZMEventPriority ZMAppReopenPriorityMTMini    = 101;   // Meeting mini window
static const ZMEventPriority ZMAppReopenPriorityCCI       = 200;   // CCI (Contact Center Integration) window
static const ZMEventPriority ZMAppReopenPriorityPTMain    = 400;   // PT Main window (after login)
static const ZMEventPriority ZMAppReopenPriorityLogin     = 600;   // Login window (lowest priority)
static const ZMEventPriority ZMAppReopenPriorityMyNotes   = 1000;  // My Notes
static const ZMEventPriority ZMAppReopenPriorityHuddles   = 1100;   // Huddles/Spot meeting window

/**
 * @poster ZMEventPoster
 * Protocol for handling application reopen events (dock icon click).
 *
 * Observers register with priority via ZMRouterCenter's registerTarget:forProtocol:object:priority:
 * Lower priority value = higher priority (will be enumerated first).
 *
 * Enumeration logic:
 * 1. Get all observers sorted by priority (ascending)
 * 2. Find the observer where isActiveForReopen returns YES
 * 3. Start from the NEXT observer in circular order
 * 4. Call handleApplicationReopen:, stop if returns YES
 */
@protocol ZMAppReopenProtocol <NSObject>

@optional

/**
 * Return YES if this observer is disabled for all reopen events.
 * Used to determine if the observer should be disabled for reopen.
 * For example, if some feature want to disable all reopen events, return YES.
 * If disabled for all but available, will directly call handleApplicationReopen: with reopenWhenActive = NO.
 * @return YES if disabled, NO otherwise, default is NO.
 */
- (BOOL)isReopenDisabledForAll;

@required
/**
 * Return YES if this observer is available for reopen.
 * Used to determine if the observer should be enumerated.
 * For example, if observer's window is not visible, return NO.
 * @return YES if available, NO otherwise.
 */
- (BOOL)isReopenAvailable;
/**
 * Return YES if this observer is currently in active state.
 * Used to determine the starting point for circular enumeration.
 * For example, if observer's window is key window, return YES.
 * @return YES if active, NO otherwise.
 */
- (BOOL)isActiveForReopen;

/**
 * Called when dock icon is clicked to reopen windows.
 * @param reopenWhenActive YES if app is already active when dock icon is clicked.
 * @return YES if this observer handled the reopen event successfully, NO otherwise.
 *         When returning YES, subsequent observers will NOT be called.
 */
- (BOOL)handleApplicationReopen:(BOOL)reopenWhenActive;

@end

NS_ASSUME_NONNULL_END

