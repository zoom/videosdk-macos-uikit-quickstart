//
//  ZMChatFileAnnotationProtocol.h
//  zChatComponent
//
//  Created by Cooper Chen on 10/25/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMChatFileAnnotationDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol defining the public interface for annotation manager
 */
@protocol ZMChatFileAnnotationProtocol <NSObject>

@property (nonatomic, weak, nullable) id<ZMChatFileAnnotationDelegate> delegate;
@property (nonatomic, readonly) BOOL isAnnotating;

- (void)startAnnotationWithImage:(NSImage *)image 
                           frame:(NSRect)frame 
                      parentView:(NSView *)parentView;

- (void)cancelAnnotation;

- (void)updateAnnotationModeUI:(BOOL)isAnnotationMode 
                    parentView:(nullable NSView *)parentView;

@end

/**
 * Factory protocol for creating annotation manager instances
 */
@protocol ZMChatFileAnnotationFactory <NSObject>

+ (nullable id<ZMChatFileAnnotationProtocol>)createAnnotationManager;

@end

NS_ASSUME_NONNULL_END

