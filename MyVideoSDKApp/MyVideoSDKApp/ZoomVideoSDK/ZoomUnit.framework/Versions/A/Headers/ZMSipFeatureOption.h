//
//  ZMSipFeatureOption.h
//  zSIPCallUI
//
//  Created by Feder Huang on 2019/4/29.
//  Copyright © 2019 Evelyn. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "zSipCallCommon/services/pbx_feature_option_def.h"

//equal to CmmPBXUpdateFeatureOptionRetCode
typedef NS_ENUM(NSUInteger, ZMSipUpdateFeatureOptionRetCode) {
    ZMSipUpdateFeatureOptionRetCode_OK = 0,
    ZMSipUpdateFeatureOptionRetCode_Handling,    // Update in progress
    ZMSipUpdateFeatureOptionRetCode_NotAllowed,  // FeatureOptions in common layer is different with the value on UI
                                                    // e.g action : close, but the  bit value in FeatureOptions is already zero
                                                    // UI should refresh
    ZMSipUpdateFeatureOptionRetCode_EmptyBits,
    ZMSipUpdateFeatureOptionRetCode_Failure,
};

@interface ZMSipFeatureOption : NSObject

@property (assign) uint64_t bit; //this is old
@property (assign) uint32_t bitIdx; //new option bit, Because bit is not enough
@property (nonatomic, assign) zoom_sipcall_app::CmmPBXFeatureOptionAction action;
@property (nonatomic, copy) NSString *optOutallCode; // if bit is opt-out all call queues, should give this

+ (ZMSipFeatureOption *)getFeatureOptionBitWith:(zoom_sipcall_app::CmmPBXFeatureOptionBit &)cmmFeatureOption;

- (zoom_sipcall_app::CmmPBXFeatureOptionBit)convertToCmmFeatureOption;
- (BOOL)isActionOpen;
@end
