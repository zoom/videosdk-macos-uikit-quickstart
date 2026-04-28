//
//  IZMMTAIAccessibleMgr.h
//  VideoUIBridge
//
//  Created by Auto on 2025/1/20.
//

#ifndef IZMMTAIAccessibleMgr_h
#define IZMMTAIAccessibleMgr_h

#import <Foundation/Foundation.h>

/**
 * @router ZMMTShared
 */
@protocol IZMMTAIAccessibleMgr <ZMRoutableObject>

@optional
- (void)startLocalMCPServer;
- (void)registerToolsToCmmMCP;
@end

#endif /* IZMMTAIAccessibleMgr_h */
