//
//  ZMMTMutableArray.h
//  VideoUI
//
//  Created by martin.yu on 1/11/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMKeyedMutableArray.h>

NS_ASSUME_NONNULL_BEGIN

// MARK: - Fast Collection Macros
// Set ZM_USE_KEYED_COLLECTION to 1 to use ZMKeyedMutableArray/ZMKeyedOrderedSet (O(1) lookup by unique key)
// Set ZM_USE_KEYED_COLLECTION to 0 to use ZMMutableArray/ZMOrderedSet (original implementation)
#ifndef ZM_USE_KEYED_COLLECTION
#define ZM_USE_KEYED_COLLECTION 1
#endif

#if ZM_USE_KEYED_COLLECTION
    #define ZMFastMutableArray      ZMKeyedMutableArray
    #define ZMFastOrderedSet        ZMKeyedOrderedSet
#else
    #define ZMFastMutableArray      ZMMutableArray
    #define ZMFastOrderedSet        ZMOrderedSet
#endif

@interface ZMMutableArray<__covariant ObjectType> : NSObject <NSFastEnumeration, NSCopying>
@property(readonly) NSArray<ObjectType> *array;
@property(readonly, copy) NSMutableArray<ObjectType> *mutableArray;

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
- (void)sortUsingFunction:(NSInteger (NS_NOESCAPE *)(ObjectType,  ObjectType, void * _Nullable))compare context:(nullable void *)context;
@end

@interface ZMOrderedSet<ObjectType> : ZMMutableArray<ObjectType>
+ (instancetype)setWithArray:(NSArray<ObjectType> * _Nullable)array;
// caller needs to guarantee the array doesn't have repeated object, and we won't check it which can improve efficiency
+ (instancetype)setWithNoDuplicateArray:(NSArray<ObjectType> * _Nullable)array;
- (instancetype)initWithNoDuplicateArray:(NSArray<ObjectType> * _Nullable)array;
- (nullable ObjectType)member:(ObjectType)object;
@end

NS_ASSUME_NONNULL_END
