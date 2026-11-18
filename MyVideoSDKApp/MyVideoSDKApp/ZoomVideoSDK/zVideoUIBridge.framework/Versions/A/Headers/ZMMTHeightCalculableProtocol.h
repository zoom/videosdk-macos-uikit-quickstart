//
//  ZMMTHeightCalculableProtocol.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 9/10/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#ifndef ZMMTHeightCalculableProtocol_h
#define ZMMTHeightCalculableProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMMTHeightCalculableProtocol <NSObject>
@property (assign) CGFloat height;
@property (assign) BOOL heightIsValid;
- (CGFloat)calculateHeightWithContext:(nullable void *)context;
@end

#endif /* ZMMTHeightCalculableProtocol_h */
