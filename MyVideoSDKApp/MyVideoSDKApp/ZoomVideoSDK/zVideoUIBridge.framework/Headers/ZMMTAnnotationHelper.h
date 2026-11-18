//
//  ZMMTAnnotationHelper.h
//  VideoUIBridge
//
//  Created by walt.li on 4/15/26.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoApp/CmmConfAPI.h>

NS_ASSUME_NONNULL_BEGIN

@class NSView;
@class NSWindow;

typedef NS_ENUM(NSInteger, ZMAnnotationSavedType) {
    ZMAnnotationSavedType_Png,
    ZMAnnotationSavedType_Pdf,
};

@interface ZMMTAnnotationHelper : ZMBaseHelper

#pragma mark - Capability Query (web/feature toggle)

/// whether the annotation feature is globally enabled (feature toggle)
- (BOOL)isAnnotationFeatureEnabled;
/// Whether attendees are allowed to annotate, as controlled by web configuration
- (BOOL)isAnnotationAllowedForAttendee;
/// Whether annotation is available to attendees in the current share state
- (BOOL)canAttendeeAnnotateInCurrentShare;

#pragma mark - Settings (Presenter)

- (BOOL)isShowingAnnotatorName;
- (void)toggleShowingAnnotatorName;
/// Whether attendee annotation is locked by the presenter via UI
- (BOOL)isAttendeeAnnotationLocked;
- (void)toggleAnnotationLockForAttendee;

#pragma mark - Presenter Toolbar / State

- (void)setPresenterAnnoDockPosition:(NSPoint)topLeft
                            topRight:(NSPoint)topRight
                          bottomLeft:(NSPoint)bottomLeft
                         bottomRight:(NSPoint)bottomRight;
- (void)hidePresenterAnnoterToolbar;
- (void)showPresenterAnnoterToolbar;
- (BOOL)isPresenterAnnoterToolbarShown;
- (BOOL)isPresenterAnnotating;
- (BOOL)isPresenterSharingWhiteboard;
/// SenderSupportAnnotation for myShareSource
- (BOOL)isMyShareSupportAnnotation;
/// Presenter whiteboard content window
- (nullable NSWindow *)getWbContentWindow;
/// Get current presenter annotation save type (PNG/PDF)
- (ZMAnnotationSavedType)getPresenterSavedType;
/// Save presenter annotation
- (void)savePresenterAnnotationWithSavedType:(ZMAnnotationSavedType)savedType isAutoSave:(BOOL)isAutoSave;

#pragma mark - Annotation API Access (low-level, used by SDK bridge / shared logic)

/// Presenter annotation API (via SharePort)
- (nullable ICmmAnnotationAPI *)getPresenterAnnotationAPI;
/// Attendee annotation API (via render view handle)
- (nullable ICmmAnnotationAPI *)getAttendeeAnnotationAPIForView:(nullable NSView *)renderView;

#pragma mark - Utility

- (ZMAnnotationSavedType)switchSavedTypeFromSessionType:(CMM_ANNO_SAVE_TYPE)sessionType;
- (CMM_ANNO_SAVE_TYPE)switchSavedTypeToSessionType:(ZMAnnotationSavedType)type;
- (NSString *)getSavedFileSuffix:(ZMAnnotationSavedType)type;
- (nullable NSString *)getSavedDisplayString:(ZMAnnotationSavedType)type isWB:(BOOL)isWB totalPages:(NSUInteger)totalPages;

@end

NS_ASSUME_NONNULL_END
