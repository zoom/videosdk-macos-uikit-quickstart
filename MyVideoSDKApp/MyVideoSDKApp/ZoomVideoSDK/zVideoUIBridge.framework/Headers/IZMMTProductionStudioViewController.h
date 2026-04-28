//
//  IZMMTProductionStudioViewController.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2024/12/09.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMShareSource;

@protocol IZMMTProductionStudioViewController <NSObject>

@property (nonatomic, assign) NSEdgeInsets paddingRatio; // 0~1

- (void)updateMixShare:(ZMShareSource *_Nullable)shareSource rect:(NSRect)rect;

@end

NS_ASSUME_NONNULL_END

