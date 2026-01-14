//
//  ZMMenuItemProtocol.h
//  zVideoUI
//
//  Created by geno.chen on 2020/9/23.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#ifndef ZMMenuItemProtocol_h
#define ZMMenuItemProtocol_h

@protocol ZMMenuItemProtocol <NSObject>

- (NSArray <NSControl *> *)allAvailableResponder;

@end

#endif /* ZMMenuItemProtocol_h */
