//
//  IZMMTThemeMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 2025/1/9.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTThemeMgr <NSObject>
- (ZMAppearance*)drawingAppearance;
- (ZMTheme*)drawingTheme;
@end

NS_ASSUME_NONNULL_END
