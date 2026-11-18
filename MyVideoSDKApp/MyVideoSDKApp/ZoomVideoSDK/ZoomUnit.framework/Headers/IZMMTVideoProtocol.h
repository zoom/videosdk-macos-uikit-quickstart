//
//  IZMMTVideoProtocol.h
//  VideoUI
//
//  Created by martin.yu on 10/17/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTVideoProtocol_h
#define IZMMTVideoProtocol_h

#import <Foundation/Foundation.h>

@protocol IZMMTVideoProtocol <ZMRoutableObject>

- (void)videoStateChangeByHID:(BOOL)muted;
- (int)getVideoHIDState;

@end

#endif /* IZMMTVideoProtocol_h */
