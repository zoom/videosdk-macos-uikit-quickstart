//
//  ZMMultipleSelectCellViewProtocol.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/26/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#ifndef ZMMultipleSelectCellViewProtocol_h
#define ZMMultipleSelectCellViewProtocol_h

#import <Cocoa/Cocoa.h>

@protocol ZMMultipleSelectCellViewProtocol <NSObject>
@optional
- (void)clickAtPoint:(NSPoint)point event:(NSEvent *)event;
- (void)multipleClickAtPoint:(NSPoint)point event:(NSEvent *)event;

- (void)selectAll;
- (void)unselectAll;
- (void)selectFromPoint:(NSPoint)fromPoint toPoint:(NSPoint)toPoint;
@end

#endif /* ZMMultipleSelectCellViewProtocol_h */
