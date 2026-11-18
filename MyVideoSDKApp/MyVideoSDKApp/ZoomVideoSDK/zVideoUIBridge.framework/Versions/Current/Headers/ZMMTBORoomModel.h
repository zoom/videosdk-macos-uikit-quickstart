//
//  ZMMTBORoomModel.h
//  VideoUI
//
//  Created by Molay.Yu on 2022/10/10.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/IZMMTBOControlMgr.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTBORoomModel : NSObject

@property (nonatomic, assign) NSInteger roomID;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, assign, readonly) NSInteger userLimit;
@property (nonatomic, assign, readonly) NSInteger userCount;
@property (nonatomic, assign, readonly) BOOL hasUser;
@property (nonatomic, assign) BOOL isAssignedRoom;

- (instancetype)initWithType:(ZMMTBOType)type;
- (std::shared_ptr<zm::new_bo::IBOUser>)getUserById:(ZMUserID)uniqueJoinIndex;
- (std::vector<std::shared_ptr<zm::new_bo::IBOUser>>)getUserList;

@end

NS_ASSUME_NONNULL_END
