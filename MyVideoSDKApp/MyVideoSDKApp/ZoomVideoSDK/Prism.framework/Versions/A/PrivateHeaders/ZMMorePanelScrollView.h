//
//  ZMMorePanelScrollView.h
//  Prism
//
//  Created by Lester Gong on 6/5/2026.
//  Copyright © 2026 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMorePanelScrollView : NSScrollView

/// Runtime switch controlled by ZMMorePanel.
/// YES: allow scrolling when content overflows.
/// NO: fully disable scrolling and hide scrollers.
@property (nonatomic, assign, getter=isScrollingEnabled) BOOL scrollingEnabled;

@end

NS_ASSUME_NONNULL_END
