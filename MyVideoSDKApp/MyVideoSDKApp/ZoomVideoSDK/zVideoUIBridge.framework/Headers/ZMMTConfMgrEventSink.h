//
//  ZMMTConfMgrEventSink.h
//  VideoUIBridge
//
//  Created by levi duan on 2026-01-06.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTMainSessionMgrSinkAdapter;

@interface ZMConfMgrSinkAdapter : NSObject

@property (nonatomic, readonly) BOOL isRegistered;
@property (nonatomic, weak) ZMMTMainSessionMgrSinkAdapter* mainSessionMgrSinkAdapter;

/// Register C++ Sink to Dispatcher
- (void)ensureRegistered;

/// Unregister C++ Sink from Dispatcher
- (void)unregister;

@end

NS_ASSUME_NONNULL_END
