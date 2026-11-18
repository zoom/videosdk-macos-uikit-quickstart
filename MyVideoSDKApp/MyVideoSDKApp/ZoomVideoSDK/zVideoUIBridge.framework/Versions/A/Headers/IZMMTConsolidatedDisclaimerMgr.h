//
//  IZMMTConsolidatedDisclaimerMgr.h
//  VideoUIBridge
//
//  Created by Carol Li on 2026/4/28.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 *
 * Mac → UUI driver for the consolidated custom disclaimer feature.
 * Owns the side of the bridge where Mac proactively notifies UUI
 * (e.g. transition lifecycle), complementing ZMMTDisclaimerSink which
 * handles the UUI → Mac direction.
 */
@protocol IZMMTConsolidatedDisclaimerMgr <ZMRoutableObject>
@end

NS_ASSUME_NONNULL_END
