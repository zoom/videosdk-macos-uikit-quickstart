//
//  ZMLoadingView.h
//  VideoUI
//
//  Created by Michael Lin on 2022/4/8.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Prism/ZMBaseView.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMLoadingView : ZMBaseView

- (void)startAnimation;
- (void)stopAnimation;

@end

NS_ASSUME_NONNULL_END
