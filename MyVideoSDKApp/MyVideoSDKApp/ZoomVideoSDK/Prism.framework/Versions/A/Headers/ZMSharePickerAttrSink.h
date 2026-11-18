//
//  ZMSharePickerAttrSink.h
//  Prism
//
//  Inversion-of-control protocol for cross-process propagation of the
//  per-NSWindow share-picker attributes (zmIncludedInSharePicker,
//  zmPreventScreenCaptureWindow). Prism's NSWindow setter fans out via
//  ZMEventPosterFor(ZMSharePickerAttrSink) without depending on the
//  upper layer that actually publishes the change cross-process; the
//  PT-side implementer lives in mac-client/PTUI and republishes onto
//  ZMXProcEventBus. When no implementer is registered (e.g. unit tests,
//  Meeting subprocess with no producer of these attrs), the dispatch
//  is a harmless no-op. [Zoom-1197031]
//
//  Copyright (c) Zoom Communications. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN

/// Attribute keys carried in the sink's payload.
/// Keep these in sync with the names of the corresponding NSWindow properties.
FOUNDATION_EXPORT NSString * const ZMSharePickerAttrKeyIncludedInSharePicker;
FOUNDATION_EXPORT NSString * const ZMSharePickerAttrKeyPreventScreenCapture;

@protocol ZMSharePickerAttrSink <ZMRoutableObject>
@optional

/// Fired by NSWindow's share-picker attribute setters after the local
/// associated-object store is updated. `windowID` is the NSWindow's
/// windowNumber at the time of the change.
- (void)onSharePickerAttrChangedForWindowID:(NSInteger)windowID
                                        key:(NSString *)key
                                      value:(BOOL)value;

/// Fired during NSWindow dealloc swizzle so cross-process registries
/// can drop their entries for the given windowID.
- (void)onSharePickerAttrClearedForWindowID:(NSInteger)windowID;

@end

NS_ASSUME_NONNULL_END
