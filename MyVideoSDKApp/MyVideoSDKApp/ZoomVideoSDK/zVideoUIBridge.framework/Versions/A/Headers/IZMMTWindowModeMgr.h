//
//  IZMMTWindowModeMgr.h
//  VideoUIBridge
//
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMMTWindowModeMgr <ZMRoutableObject>

- (BOOL)isPopoutSelected;
- (void)toggleDualMode;
- (BOOL)isInPopoutMode;

@end

NS_ASSUME_NONNULL_END
