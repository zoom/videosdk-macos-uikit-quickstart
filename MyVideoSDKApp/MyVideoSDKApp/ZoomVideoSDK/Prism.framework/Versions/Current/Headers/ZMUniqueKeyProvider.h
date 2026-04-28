//
//  ZMUniqueKeyProvider.h
//  ZoomKit
//
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Protocol for objects that can provide a unique key for fast lookup in keyed collections.
/// Objects conforming to this protocol can be stored in ZMKeyedMutableArray and ZMKeyedOrderedSet
/// for O(1) containsObject performance.
@protocol ZMUniqueKeyProvider <NSObject>
@required
/// Returns a unique key that identifies this object.
/// The key must be consistent with the object's isEqual: implementation.
/// Two objects that are equal must return the same key.
/// @return A non-nil unique key string, or nil if the object doesn't support keyed lookup.
- (nullable NSString *)zm_uniqueKey;
@end

NS_ASSUME_NONNULL_END
