//
//  CABackdropLayer.h
//  PrismBook
//
//  Created by Felipe Bastos on 1/5/26.
//

#ifndef CABackdropLayer_h
#define CABackdropLayer_h

#import <Foundation/Foundation.h>
#import <QuartzCore/CABase.h>
#import <QuartzCore/CALayer.h>

// mark: filter type declarations
extern NSString * const kCAFilterColorSaturate;
extern NSString * const kCAFilterColorBrightness;
extern NSString * const kCAFilterColorContrast;
extern NSString * const kCAFilterColorMatrix;
extern NSString * const kCAFilterColorInvert;
extern NSString * const kCAFilterColorHueRotate;
extern NSString * const kCAFilterColorMonochrome;
extern NSString * const kCAFilterGaussianBlur;
extern NSString * const kCAFilterMultiplyColor;
extern NSString * const kCAFilterMultiplyGradient;

// mark: blend mode declarations
extern NSString * const kCAFilterNormalBlendMode;
extern NSString * const kCAFilterDarkenBlendMode;
extern NSString * const kCAFilterLightenBlendMode;
extern NSString * const kCAFilterColorBurnBlendMode;
extern NSString * const kCAFilterColorDodgeBlendMode;
extern NSString * const kCAFilterLinearBurnBlendMode;
extern NSString * const kCAFilterLinearDodgeBlendMode;
extern NSString * const kCAFilterOverlayBlendMode;
extern NSString * const kCAFilterSoftLightBlendMode;
extern NSString * const kCAFilterHardLightBlendMode;
extern NSString * const kCAFilterLinearLightBlendMode;
extern NSString * const kCAFilterPinLightBlendMode;
extern NSString * const kCAFilterDifferenceBlendMode;
extern NSString * const kCAFilterExclusionBlendMode;
extern NSString * const kCAFilterMultiplyBlendMode;
extern NSString * const kCAFilterSubtractBlendMode;
extern NSString * const kCAFilterDivideBlendMode;
extern NSString * const kCAFilterScreenBlendMode;
extern NSString * const kCAFilterPlusD;
extern NSString * const kCAFilterPlusL;
extern NSString * const kCAFilterClear;
extern NSString * const kCAFilterCopy;
extern NSString * const kCAFilterSourceIn;
extern NSString * const kCAFilterSourceOut;
extern NSString * const kCAFilterSourceAtop;
extern NSString * const kCAFilterXor;
extern NSString * const kCAFilterDestIn;
extern NSString * const kCAFilterDestOut;
extern NSString * const kCAFilterDestOver;
extern NSString * const kCAFilterDestAtop;

void CGSetCatenatedWindowTransform(int cid, int wid, CGAffineTransform *transform);
void CGSFlushSurface(int cid, int wid, int sid, int flag);

@interface CAFilter: NSObject
- (nullable instancetype)initWithType:(nonnull NSString *)type;
- (void)setDefaults;
@end

@interface CALayer ()
@property BOOL allowsGroupBlending;
@end

@interface CABackdropLayer: CALayer
@property BOOL ignoresOffscreenGroups;
@property BOOL windowServerAware;
@property CGFloat bleedAmount;
@property CGFloat statisticsInterval;
@property (copy) NSString *statisticsType;
@property BOOL disablesOccludedBackdropBlurs;
@property BOOL allowsInPlaceFiltering;
@property BOOL captureOnly;
@property CGFloat marginWidth;
@property CGRect backdropRect;
@property CGFloat scale;
@property BOOL usesGlobalGroupNamespace;
@property (copy) NSString *groupName;
@property (getter=isEnabled) BOOL enabled;
@property BOOL allowsSubstituteColor;
@end

@interface NSWindow ()

- (void)_registerBackdropView:(NSView *)view;
- (void)_unregisterBackdropView:(NSView *)view;
- (NSArray *)_registeredBackdropViews;
- (BOOL)shouldGetCornerMaskFromVisualEffectView;
- (void)_cornerMaskChanged;
- (BOOL)_hasActiveAppearanceIgnoringKeyFocus;
- (BOOL)_visualEffectViewAlwaysUseWSAwareBackdrops;

@end

typedef int32_t CGSConnectionID;

extern CGSConnectionID CGSMainConnectionID(void);

extern CGError CGSSetWindowTags(CGSConnectionID cid, int32_t wid, const int32_t *tags, int32_t maxTagSize);
extern CGError CGSClearWindowTags(CGSConnectionID cid, int32_t wid, const int32_t *tags, int32_t maxTagSize);
extern CGError CGSGetWindowTags(CGSConnectionID cid, int32_t wid, const int32_t *tags, int32_t maxTagSize);
extern void CGSSetCatenatedWindowTransform(CGSConnectionID cid, int32_t wid, CGAffineTransform *transform);

@interface CALayer (PrismBackdrop)
@end

@interface NSWindow (PrismBackdrop)
@end

#endif /* CABackdropLayer_h */
