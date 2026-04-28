//
//  ZMMTMainSessionManagerSink.h
//  VideoUIBridge
//
//  Created by levi duan on 2025-01-29.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <zm_conf_callback_dispatcher/zm_conf_callback_dispatcher_main_session_manager_interface.h>

// Forward declaration for C++ class
class ZMMTConfInstSink;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTMainSessionMgrSinkAdapter : NSObject

@property (nonatomic, readonly) BOOL isRegistered;
@property (nonatomic, assign, nullable) ZMMTConfInstSink* confInstSink;

/// Register C++ Sink to Dispatcher
- (void)ensureRegistered;

/// Unregister C++ Sink from Dispatcher
- (void)unregister;

@end

NS_ASSUME_NONNULL_END
