//
//  ZMMTSelectableTextItemProtocol.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/26/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#ifndef ZMMTSelectableTextItemProtocol_h
#define ZMMTSelectableTextItemProtocol_h

@protocol ZMMTSelectableTextItemProtocol <NSObject>
@optional
- (void)selectAll;
- (void)unselectAll;
- (NSString *)selectedText;
@end

#endif /* ZMMTSelectableTextItemProtocol_h */
