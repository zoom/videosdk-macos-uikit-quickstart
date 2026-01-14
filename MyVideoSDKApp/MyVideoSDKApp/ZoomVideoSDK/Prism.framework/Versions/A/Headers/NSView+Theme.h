//
//  NSView+Theme.h
//  Prism
//
//  Created by Francis Zhuo on 2025/9/2.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * NSView category that provides theme support through method swizzling.
 * This category automatically integrates theme functionality into all NSView instances
 * by hooking into key view lifecycle methods.
 * 
 * The swizzled methods ensure that:
 * - effectiveAppearance returns the correct theme-aware appearance
 * - Theme changes are properly propagated when views move between windows or superviews
 * - Drawing operations use the appropriate theme context
 */
@interface NSView (Theme)
- (void)didChangeEffectiveTheme NS_REQUIRES_SUPER;
@end

@interface NSViewController (Theme)
- (void)didChangeEffectiveTheme NS_REQUIRES_SUPER;
@end
NS_ASSUME_NONNULL_END
