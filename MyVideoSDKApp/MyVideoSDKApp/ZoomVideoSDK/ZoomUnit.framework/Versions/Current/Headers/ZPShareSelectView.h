//
//  ZPShareSelectView.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>

@class ZMTrackingView;
@class ZPShareSelectView;
@protocol ZPShareSelectViewDelegate <NSObject>
//respond selectview action
- (void)selectViewDidDoubleClicked:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewDidHovered:(ZPShareSelectView*_Nonnull)view hovered:(BOOL)hovered;
- (void)selectViewWillSelect:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteLeft:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteRight:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteTop:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewWillSelecteBottom:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewDidTabKeyPressed:(ZPShareSelectView*_Nonnull)view isShiftDown:(BOOL)isShiftDown;
- (void)selectViewDidReturnKeyPressed:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewDidBecomeNexFirsstResponse:(ZPShareSelectView*_Nonnull)view;
- (void)selectViewMoreMenuResponder:(ZPShareSelectView*_Nonnull)view menuTag:(NSInteger)tag;

//setting content
- (NSString *_Nullable)selectViewStringForAxRoleDescription:(ZPShareSelectView*_Nonnull)view;
- (NSString *_Nullable)selectViewStringForAxTitle:(ZPShareSelectView*_Nonnull)view;
- (NSString *_Nullable)selectViewStringForToolTip:(ZPShareSelectView*_Nonnull)view;
- (NSString *_Nullable)selectViewStringForDisabledInfo:(ZPShareSelectView*_Nonnull)view;
- (BOOL)selectViewIsDesktopType:(ZPShareSelectView*_Nonnull)view;
- (ZMShareSelectItemType)selectViewShareType:(ZPShareSelectView*_Nonnull)view;
- (NSDictionary<NSNumber *, NSString *>*_Nullable)selectViewMoreMenu:(ZPShareSelectView*_Nonnull)view;
- (NSNumber *_Nullable)moreMenuSelectedStatus:(ZPShareSelectView*_Nonnull)view;
@end

@interface ZPShareSelectView : ZMTrackingView {
    
    BOOL _selected;
    BOOL    _valid;
    BOOL    _enabled;
}

@property (nonatomic, strong, readonly, nullable) NSImageView *imageView;
@property (nonatomic, strong, readonly, nullable) NSTextField *nameField;
@property (nonatomic, strong, nullable) NSImage *staticContentGlyphImage;
/// Uses the 100x110 narrow tile layout instead of the regular wide tile layout.
@property (nonatomic, assign) BOOL narrowTile;

/// Optional 16×16pt prefix icon shown on the leading side of the label row
/// (e.g. host-app icon for Windows tiles). `nil` collapses the slot so the
/// label centers as a single column. KVO-compliant — cells bind it via
/// `[selectView bind:@"prefixIcon" toObject:model withKeyPath:@"…"]`.
///
/// Why not expose `prefixIconView` for direct `bind:NSValueBinding`? Cocoa
/// Binding on `NSImageView.image` updates the ivar through a private
/// `_NSObservedObject` channel that bypasses `setImage:`, so the host view
/// has no hook to refresh stack visibility. Routing through this property's
/// setter is the only reliable trigger.
@property (nonatomic, copy, nullable) NSImage *prefixIcon;

@property (nonatomic, assign, readwrite) BOOL selected;
@property (nonatomic, assign, getter=isValid)   BOOL valid;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
@property (nonatomic, weak, nullable) id<ZPShareSelectViewDelegate> viewDelegate;

- (void)cleanUp;
- (BOOL)isOverlayMenuVisible;
- (void)closeOverlayMenuIfNeeded;
- (void)setMoreButtonAccessibilityTitle:(NSString *_Nullable)accessibilityTitle;
- (void)setHelpString:(NSString *_Nullable)helpString;
- (void)setHelpAttributedString:(NSAttributedString *_Nullable)helpAttributedString;
- (void)setBadgeHidden:(BOOL)hidden;
- (void)showWarningIcon:(BOOL)show;

@end
