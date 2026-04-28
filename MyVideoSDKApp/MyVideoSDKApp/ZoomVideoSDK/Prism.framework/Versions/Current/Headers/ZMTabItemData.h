//
//  ZMTabItemData.h
//  PTUIBridge
//
//  Created by Cursor on 10/17/2025.
//  Copyright © 2025 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMPigment.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItemData;

#pragma mark - Drag Source Protocol

/// Protocol for drag sources that can provide ZMTabItemData
@protocol ZMTabItemDataDragSource <NSObject>

@required
/// Get the tab item data being dragged
- (ZMTabItemData *)draggingTabItemData;

@end

/**
 * Base data model for tab items
 * Contains common properties shared between ZMTabItem and other tab-related data
 */
@interface ZMTabItemData : NSObject

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong) NSImage *image;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) CGFloat disabledAlphaValue;
@property (nonatomic, copy, nullable) NSString *disabledToolTip;
@property (nonatomic, assign) BOOL isPin;
@property (nonatomic, assign) BOOL showNew;
@property (nonatomic, assign) BOOL showBeta;
@property (nonatomic, assign) BOOL showFreeTrial;
@property (nonatomic, assign) BOOL showError;
@property (nonatomic, assign) NSInteger badgeValue;
@property (nonatomic, assign) BOOL showRedDot;
@property (nonatomic, assign) BOOL draggable;
@property (nonatomic, assign) BOOL draggingNow;
@property (nonatomic, strong) ZMPigment<ZMButtonPigmentProtocol> *pigment;
@property (nonatomic, assign) BOOL matchImageColorWithTitle; //default NO

/// Pre-assembled accessibility label text (e.g., "Docs, 1 of 5, not pinned, tab")
@property (nonatomic, copy) NSString *accessibilityText;

+ (instancetype)dataWithText:(NSString *)text 
                       image:(NSImage *)image 
                  identifier:(NSString *)identifier 
                       isPin:(BOOL)isPin;

@end

NS_ASSUME_NONNULL_END


