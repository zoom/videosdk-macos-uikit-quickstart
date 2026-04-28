//
//  ZMEventPublisher.h
//  ZMEventCenter
//
//  Created by martin.yu on 4/6/22.
//

#import <Foundation/Foundation.h>
//#import "ZMRouterCenterProtocols.h"
#import <Prism/ZMMutableArray.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMEventTarget;
@interface ZMEventPoster<ObjectType> : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithProtocol:(Protocol *)protocol;
- (instancetype)initWithProtocol:(Protocol *)protocol sender:(nullable id)sender;
- (instancetype)initWithProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object;
- (instancetype)initWithProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object tag:(NSInteger)tag;
- (instancetype)initWithProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object tag:(NSInteger)tag ignoreSelfObjectIfNil:(BOOL)ignoreSelfObjectIfNil NS_DESIGNATED_INITIALIZER;


@property (weak) id sender;
@property (assign) BOOL ignoreSender;

@property (weak) id object;
@property (assign) NSInteger tag;

@property (assign) BOOL ignoreSelfObjectIfNil;

@property (copy,nullable) ZMOrderedSet<id<ZMEventTarget>> *eventTargets;

@property (strong) void(^callBack)(id obj, BOOL returnValue, BOOL *stop);

- (void)enumerateObjectsUsingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block API_AVAILABLE(macos(10.6));
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

@end

NS_ASSUME_NONNULL_END
