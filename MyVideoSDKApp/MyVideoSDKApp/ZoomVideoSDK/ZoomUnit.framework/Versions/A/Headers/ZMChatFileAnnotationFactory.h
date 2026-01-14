//
//  ZMChatFileAnnotationFactory.h
//  ZoomUnit
//
//  Created by Cooper Chen on 10/27/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZMChatFileAnnotationProtocol;

NS_ASSUME_NONNULL_BEGIN

/**
 * Factory for creating annotation manager instances
 * Supports registration pattern to decouple implementation from usage
 */
@interface ZMChatFileAnnotationFactory : NSObject

/**
 * Register annotation manager factory block
 * Should be called during framework initialization (e.g., in +load method)
 * @param factory Block that creates and returns annotation manager instance
 */
+ (void)registerFactory:(id<ZMChatFileAnnotationProtocol> (^)(void))factory;

/**
 * Create annotation manager instance using registered factory
 * @return Annotation manager instance or nil if no factory registered
 */
+ (nullable id<ZMChatFileAnnotationProtocol>)createAnnotationManager;

@end

NS_ASSUME_NONNULL_END

