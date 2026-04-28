//
//  ZMKeyedMutableArray.h
//  ZoomKit
//
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMUniqueKeyProvider.h>

NS_ASSUME_NONNULL_BEGIN

/// A mutable array that uses unique keys for O(1) containsObject performance.
/// This class has the same interface as ZMMutableArray but requires objects to conform to ZMUniqueKeyProvider.
/// Objects are looked up by their zm_uniqueKey instead of using isEqual:.
@interface ZMKeyedMutableArray<__covariant ObjectType: id<ZMUniqueKeyProvider>> : NSObject <NSFastEnumeration, NSCopying>
@property (nonatomic, readonly) NSArray<ObjectType> *array;
@property (nonatomic, readonly, copy) NSMutableArray<ObjectType> *mutableArray;

+ (instancetype)array;
+ (instancetype)arrayWithCapacity:(NSUInteger)capacity;
+ (instancetype)arrayWithArray:(NSArray<ObjectType> * _Nullable)array;

- (instancetype)initWithArray:(NSArray<ObjectType> * _Nullable)array;

@property (nonatomic, readonly) NSUInteger count;

- (BOOL)addObject:(ObjectType)anObject;
- (BOOL)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
- (BOOL)insertObjects:(NSArray<ObjectType> *)otherArray atIndexes:(NSIndexSet *)indexes;

- (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;

- (BOOL)removeObject:(ObjectType)anObject;
- (BOOL)removeObjectAtIndex:(NSUInteger)index;
- (BOOL)removeObjectsAtIndexes:(NSIndexSet *)indexes;
// This method is suitable for batch deletion in large array
- (BOOL)fast_removeObjectsAtIndexes:(NSIndexSet *)indexes;
- (BOOL)removeObjectsInArray:(NSArray *)otherArray;
- (void)removeAllObjects;

- (void)moveObjectFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

- (void)replaceObject:(ObjectType)anObject;

// Support indexed subscripting need to declare this method
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index;
- (nullable ObjectType)objectAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfObject:(ObjectType)anObject;

- (BOOL)containsObject:(ObjectType)anObject;

- (void)sortUsingComparator:(NSComparator)cmptr;
- (void)sortUsingFunction:(NSInteger (NS_NOESCAPE *)(ObjectType, ObjectType, void * _Nullable))compare context:(nullable void *)context;
@end

/// An ordered set that uses unique keys for O(1) containsObject and duplicate checking.
/// This class has the same interface as ZMOrderedSet but requires objects to conform to ZMUniqueKeyProvider.
@interface ZMKeyedOrderedSet<ObjectType: id<ZMUniqueKeyProvider>> : ZMKeyedMutableArray<ObjectType>
+ (instancetype)setWithArray:(NSArray<ObjectType> * _Nullable)array;
// caller needs to guarantee the array doesn't have repeated object, and we won't check it which can improve efficiency
+ (instancetype)setWithNoDuplicateArray:(NSArray<ObjectType> * _Nullable)array;
- (instancetype)initWithNoDuplicateArray:(NSArray<ObjectType> * _Nullable)array;
- (nullable ObjectType)member:(ObjectType)object;
@end

NS_ASSUME_NONNULL_END
