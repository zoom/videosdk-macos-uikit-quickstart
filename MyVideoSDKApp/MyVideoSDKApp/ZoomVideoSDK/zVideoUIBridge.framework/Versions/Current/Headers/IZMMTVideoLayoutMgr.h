//
//  IZMMTVideoLayoutMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 2026/1/6.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMMTVideoLayoutStatusProtocol <NSObject>
@optional
- (void)onVideoLayoutModeChanged:(ZMMTVideoLayoutMode)mode;
@end

/**
 * @router ZMMTShared
 */
@protocol IZMMTVideoLayoutMgr <ZMRoutableObject>
@property (nonatomic, assign) ZMMTVideoLayoutMode preferredLayoutMode;

- (BOOL)isPreferGalleryViewMode;
- (BOOL)isPreferDynamicViewMode;
- (BOOL)isPreferSpeakerViewMode;
- (BOOL)isPreferBestFitViewMode;
@end

NS_ASSUME_NONNULL_END
