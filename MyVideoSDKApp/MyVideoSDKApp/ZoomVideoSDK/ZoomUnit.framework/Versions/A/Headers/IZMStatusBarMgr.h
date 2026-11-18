//
//  IZMStatusBarMgr.h
//  ZoomUnit
//
//  Created for the statusbar-mgr-in-ptui change.
//  Defines the cross-module contract used to move macOS NSStatusItem ownership
//  from VideoUI to PTUI while keeping multi-process (PT + standalone meeting)
//  topologies first-class.
//

#import <Cocoa/Cocoa.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMStatusBarMenuProvider;

/// Owner of the macOS NSStatusItem hosted by the PT process.
///
/// Resolved via ZMRouterCenter as a singleton (registered by ZMPTMgr at module
/// registration time). The PT-side concrete implementation owns the lifecycle
/// of the NSStatusItem and reacts to zpref::zPolicy_ShowIconInMenuBar updates.
///
/// The public surface intentionally exposes only menu-provider registration:
/// NSStatusItem add/remove is driven exclusively by the policy listener inside
/// the implementation. External callers must not bypass that single source of
/// truth, so add/remove helpers are deliberately not part of this protocol.
@protocol IZMStatusBarMgr <ZMRoutableObject>

/// Register a menu provider whose items replace the PT menu while present.
///
/// The implementation stores providers via a weak collection (NSHashTable with
/// NSHashTableWeakMemory), so providers that get deallocated without an
/// explicit unregister are transparently dropped on the next menu open.
/// Re-registering an already-registered provider is a no-op.
- (void)registerMenuProvider:(id<IZMStatusBarMenuProvider>)provider;

/// Remove a previously-registered provider. Unregistering an unknown provider
/// is a no-op.
- (void)unregisterMenuProvider:(id<IZMStatusBarMenuProvider>)provider;

@end

/// Contributor of NSStatusItem menu items.
///
/// Adopted by the meeting-side ZMStatusBarMenuMgr in the in-process (PT plus
/// meeting) topology. The provider is responsible for setting target/action on
/// each returned NSMenuItem; the PT-side manager must not mutate them.
@protocol IZMStatusBarMenuProvider <NSObject>

/// Build the current snapshot of menu items. Invoked at NSMenuDelegate
/// menuWillOpen: time. Implementations should treat each invocation as
/// independent (no caching assumptions) because the meeting state can change
/// between consecutive menu opens.
- (NSMenu *)buildStatusBarMenu;

@end

NS_ASSUME_NONNULL_END
