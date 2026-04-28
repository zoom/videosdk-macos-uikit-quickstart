//
//  ZMMTSessionManager.h
//  VideoUIBridge
//
//  Created by Levi on 2026/01/06.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMConfMgrSinkAdapter;
@class ZMMTMainSessionMgrSinkAdapter;
@class ZMMTSessionObject;

NS_ASSUME_NONNULL_BEGIN

/// Manages architecture-level sink adapters for the meeting system.
/// This singleton class coordinates the lifecycle of:
/// - ConfMgr sink (ICmmConfMgrAPI events)
/// - MainSessionManager sink (IMainSessionManager events)
@interface ZMMTSessionManager : NSObject

/// Shared singleton instance
+ (instancetype)shared;

/// Setup all sinks (basic registration)
- (void)setupSinks;

/// Setup all sinks with session object (provides confInstSink)
/// @param sessionObject The session object containing confInstSink
- (void)setupSinksWithSessionObject:(ZMMTSessionObject*)sessionObject;

/// Cleanup and unregister all sinks
- (void)cleanupSinks;

/// Conference manager sink adapter
@property (nonatomic, strong, readonly, nullable) ZMConfMgrSinkAdapter* confMgrSinkAdapter;

/// Main session manager sink adapter
@property (nonatomic, strong, readonly, nullable) ZMMTMainSessionMgrSinkAdapter* mainSessionMgrSinkAdapter;

@end

NS_ASSUME_NONNULL_END
