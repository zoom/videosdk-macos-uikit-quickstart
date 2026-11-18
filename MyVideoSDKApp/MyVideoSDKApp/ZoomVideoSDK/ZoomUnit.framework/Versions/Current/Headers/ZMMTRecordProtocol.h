//
//  ZMMTRecordProtocol.h
//  ChatUI
//
//  Created by Brace Liu on 2022/3/17.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTRecordProtocol <ZMRoutableObject>

- (BOOL)isLocalRecordingInProgress;
- (NSString *)getCurrentLocalRecordingPath;

@end

NS_ASSUME_NONNULL_END
