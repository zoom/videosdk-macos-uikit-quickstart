//
//  ZMRouterCenter.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/3/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMRouterCenterProtocols.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMRouterCenter : NSObject <ZMRouterCenter>
+ (instancetype)shared;

/// Designated initializer with ID for identifying this RouterCenter (e.g., "Global", "Meeting")
- (instancetype)initWithID:(nullable NSString *)ID;

/// RouterCenter ID for debugging and conflict detection (e.g., "Global", "Meeting")
@property (nonatomic, copy, readonly, nullable) NSString *ID;

@end

NS_ASSUME_NONNULL_END

