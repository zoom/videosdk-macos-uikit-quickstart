/*
 *** Skill: use-zmxproc-value
 *** Doc: https://dg01docs.zoom.us/doc/i8TVw9XSQCCNCxzSQwseoQ
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ZMXProcValue keeps transport details internal. Writer updates reach local
/// Receivers synchronously; PT Writers then fan out to UI subprocesses, while
/// subprocess Writers report only to PT and are never relayed to other
/// subprocesses. Receiver creation performs one local-first refresh. Writer
/// removal clears its cached entry, including subprocess exit cleanup by PT.
///
/// The scalar value owned by a Writer.
///
/// Only NSString, NSNumber, NSNull, and nil are supported. Keys are nonempty
/// business-owned strings. Business code does not select a process role or
/// EventBus route.
@interface ZMXProcValue<ObjectType> : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, copy, readonly) NSString *key;
@property (nonatomic, copy, readonly, nullable) ObjectType value;

@end

/// The writable side of a value flow.
///
/// A write is delivered synchronously to Receivers in the current process,
/// then transported to PT or UI subprocesses according to the current process.
@interface ZMXProcValueWriter<ObjectType> : ZMXProcValue<ObjectType>

+ (instancetype)writerWithKey:(NSString *)key
                  defaultValue:(nullable ObjectType)defaultValue;

@property (nonatomic, copy, nullable) ObjectType value;

/// Invoked on the main thread when a Receiver performs a refresh. If the
/// returned value changed, the Writer updates its cache and revision. A refresh
/// republishes the current snapshot even when the value did not change so a new
/// Receiver can obtain the Writer's existing value.
@property (nonatomic, copy, nullable) ObjectType _Nullable (^valueProvider)(void);

@end

/// Read side that keeps the latest value from every Writer of the same key.
///
/// Multiple Receivers and multiple Writers may exist for a key. Business code
/// chooses any, a specific Writer, or another aggregation rule from the map.
@interface ZMXProcValueReceiver<ObjectType> : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)receiverWithKey:(NSString *)key
                       onChange:(void (^)(NSString *writerInstanceID,
                                          ObjectType _Nullable value))onChange;

@property (nonatomic, copy, readonly) NSString *key;
@property (nonatomic, copy, readonly) NSDictionary<NSString *, ObjectType> *cachedValuesByWriterInstanceID;

/// Requests the latest snapshot from every Writer for this key. The request is
/// asynchronous across processes; onChange: is invoked once per Writer update.
- (void)refresh;

/// Evaluates a snapshot of the cached values. NSNull is passed as nil.
/// any: returns NO for an empty cache; all: returns YES for an empty cache.
- (BOOL)any:(BOOL (^)(ObjectType _Nullable value))predicate;
- (BOOL)all:(BOOL (^)(ObjectType _Nullable value))predicate;

@end

NS_ASSUME_NONNULL_END
