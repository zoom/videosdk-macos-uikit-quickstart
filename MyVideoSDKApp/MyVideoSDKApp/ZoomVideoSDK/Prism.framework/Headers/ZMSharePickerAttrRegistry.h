//
//  ZMSharePickerAttrRegistry.h
//  Prism
//
//  Process-local mirror of per-windowID share-picker attributes that
//  were set on NSWindows in *other* Zoom processes. Populated by an
//  upper-layer bus receiver (see mac-client/VideoUI's
//  ZMMTSharePickerAttrXProcReceiver); consumed by the share-select
//  filter when [NSApp windowWithWindowNumber:] returns nil for a
//  cross-process window. [Zoom-1197031]
//
//  Copyright (c) Zoom Communications. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSharePickerAttrRegistry : NSObject

+ (instancetype)shared;

/// Write a single (windowID, key, value) triple to the local mirror.
/// Called by the cross-process receiver after a bus message arrives.
- (void)setValue:(BOOL)value forWindowID:(NSInteger)windowID key:(NSString *)key;

/// Drop all entries for the given windowID (window destroyed).
- (void)clearForWindowID:(NSInteger)windowID;

/// Read accessors used by the share-select filter when the window is
/// not present in this process. Returns NO when no entry has been
/// recorded.
- (BOOL)isIncludedInSharePickerForWindowID:(NSInteger)windowID;
- (BOOL)isPreventScreenCaptureForWindowID:(NSInteger)windowID;

@end

NS_ASSUME_NONNULL_END
