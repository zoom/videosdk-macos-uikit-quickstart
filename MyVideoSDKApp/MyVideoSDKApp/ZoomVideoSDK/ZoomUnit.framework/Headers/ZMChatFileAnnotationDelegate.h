//
//  ZMChatFileAnnotationDelegate.h
//  zChatComponent
//
//  Created by Cooper Chen on 10/25/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatFileAnnotationDelegate <NSObject>

@required
/**
 * Annotation finished callback
 * @param manager Annotation manager instance
 * @param imageData Annotated image data
 */
- (void)annotationManager:(id)manager didFinishWithImageData:(NSData *)imageData;

/**
 * Annotation cancelled callback
 * @param manager Annotation manager instance
 */
- (void)annotationManagerDidCancel:(id)manager;

@optional
/**
 * Download annotated image
 * @param manager Annotation manager instance
 * @param imageData Image data to download
 */
- (void)annotationManager:(id)manager didRequestDownload:(NSData *)imageData;

/**
 * Show tool palette
 * @param manager Annotation manager instance
 * @param toolController Tool palette controller
 */
- (void)annotationManager:(id)manager showToolPalette:(NSViewController *)toolController;

/**
 * Get annotation button title
 * @param manager Annotation manager instance
 * @return Title string
 */
- (NSString *)annotationManagerCaptureTitle:(id)manager;

/**
 * Get current window
 * @param manager Annotation manager instance
 * @return Current window
 */
- (NSWindow *)annotationManagerWindow:(id)manager;

@end

NS_ASSUME_NONNULL_END

