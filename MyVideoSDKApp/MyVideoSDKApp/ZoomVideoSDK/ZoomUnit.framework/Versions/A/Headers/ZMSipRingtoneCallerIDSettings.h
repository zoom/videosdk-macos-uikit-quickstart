//
//  ZMSipRingtoneCallerIDSettings.h
//  zSIPCallUI
//
//  Created by ares.lin on 2/11/25.
//  Copyright © 2025 Evelyn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSipEntityCallerID;

@interface ZMSipRingtoneCallerIDSettings : NSObject

@property (nonatomic, strong) NSMutableArray<ZMSipEntityCallerID *> *userCallerIDs;
@property (nonatomic, strong) NSMutableArray<ZMSipEntityCallerID *> *slgCallerIDs;
@property (nonatomic, strong) NSMutableArray<ZMSipEntityCallerID *> *cqCallerIDs;
@property (nonatomic, strong) NSMutableArray<ZMSipEntityCallerID *> *slaCallerIDs;

- (nullable ZMSipEntityCallerID *)callerIDWithNumber:(NSString *)number;
- (void)addUserCallerID:(ZMSipEntityCallerID *)callerID;
- (void)addUserExtensionNumber:(NSString *)extensionNumber;
- (void)sortCallerIDs;

@end

NS_ASSUME_NONNULL_END

