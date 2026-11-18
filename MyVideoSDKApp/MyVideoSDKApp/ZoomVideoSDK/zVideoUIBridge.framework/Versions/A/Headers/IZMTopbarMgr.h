//
//  IZMTopbarMgr.h
//  VideoUI
//
//  Created by Michael Lin on 2024/2/29.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMTopbarMgr_h
#define IZMTopbarMgr_h

#import <zVideoUIBridge/ZMTopbarStatusPortocol.h>

@class ZMAutoFloatViewController, ZMTopbarBaseItem;
@protocol IZMTopbarMgr <ZMRoutableObject>

- (nullable ZMAutoFloatViewController *)createTopbarVCWithType:(ZMMTType)type style:(ZMTopbarStyle)style;
- (nullable ZMAutoFloatViewController *)topbarVCWithType:(ZMMTType)type style:(ZMTopbarStyle)style;
- (nullable ZMTopbarBaseItem *)workingItemForType:(ZMTopbarItemType)itemType inVCType:(ZMMTType)vcType;
- (void)setCurrentWorkingItemType:(ZMTopbarItemType)itemType workingInStyle:(ZMTopbarStyle)style vcType:(ZMMTType)vcType;

@end

#endif /* IZMTopbarMgr_h */
