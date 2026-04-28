//
//  NSView+Bubble.h
//  Prism
//
//  Created by Cursor on 2025/12/3.
//  Copyright © 2025 zoom. All rights reserved.
//
//  This category provides bubble/alert positioning support for NSView.
//  It uses a KVO-like dynamic subclass approach to avoid global method swizzling overhead.
//
//  Implementation notes:
//  - Dynamic subclass (ZM_Bubble_XXX) is created lazily when viewBecameReadyForAlertBlock is set
//  - Setting zmControlID alone does NOT create the dynamic subclass
//  - Once created, the dynamic subclass is NOT removed (isa is not restored)
//  - This provides minimal overhead: only views with active blocks have frame observation
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (Bubble)

/// Unique identifier for the control, used for bubble/alert positioning.
/// Setting this property registers the view in a lookup table, but does NOT
/// create the dynamic subclass. The subclass is created lazily when
/// viewBecameReadyForAlertBlock is set.
@property (nonatomic, copy, nullable) NSString *zmControlID;

/// Get a view by its zmControlID.
/// @param zmControlID The control ID to search for.
/// @return The view with the specified control ID, or nil if not found.
+ (nullable NSView *)getViewByZMControlID:(NSString *)zmControlID;

/// Related control view for positioning. If nil, returns self.
/// Used for tab items in "more" menu scenarios.
@property (nonatomic, weak, nullable) NSView *zmRelatedControlView;

/// Add a block to be executed when a view with the specified control ID becomes available.
/// If the view already exists, the block is executed immediately.
/// @param alertBlock The block to execute when the view is ready.
/// @param zmControlID The control ID of the target view.
+ (void)addAlertBlock:(void (^)(NSView *view))alertBlock toZMControl:(NSString *)zmControlID;

/// Remove pending alert blocks for the specified control ID.
/// @param zmControlID The control ID to remove blocks for.
+ (void)removeAlertBlockForZMControl:(NSString *)zmControlID;

/// Block called when the view becomes ready for showing an alert/bubble.
/// Setting this block triggers creation of the dynamic subclass (ZM_Bubble_XXX)
/// which enables frame/visibility observation. Setting to nil does NOT restore
/// the original class (minimal overhead - just a nil check).
/// @param view The related control view (zmRelatedControlView or self).
/// @param canShowAlert Whether the view is currently visible and ready to show an alert.
@property (nonatomic, copy, nullable) void (^viewBecameReadyForAlertBlock)(NSView *view, BOOL canShowAlert);

/// Manually trigger the viewBecameReadyForAlertBlock callback. DO NOT call the method directly, use `setNeedsUpdateForRelatedAlert` instead.
- (void)updateForRelatedAlert;

/// Schedule an update for related alert (coalesced to avoid redundant calls within the same runloop).
- (void)setNeedsUpdateForRelatedAlert;

/// Preferred edge for positioning alerts relative to this control.
@property (nonatomic, assign) NSRectEdge zmControlEdge;

@end

NS_ASSUME_NONNULL_END

