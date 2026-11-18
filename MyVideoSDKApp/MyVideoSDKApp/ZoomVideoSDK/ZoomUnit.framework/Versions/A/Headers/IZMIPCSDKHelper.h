//
//  IZMIPCSDKHelper.h
//  VideoUI
//
//  Created by Peter Xu on 2024/5/23.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMIPCSDKHelper <ZMRoutableObject>
- (void)initMTToolSuiteHost;
- (void)unInitMTToolSuiteHost;
- (void)cleanUp;
@end

NS_ASSUME_NONNULL_END
