//
//  IZMMTTheme.h
//  ZoomUnit
//
//  Created by Codex on 2026/7/15.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/ZoomKit.h>
#import <Prism/Prism-Swift.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZMMTVideoTheme <NSObject>
@property(nonatomic, strong) ZMPigment* backsplash;
@property(nonatomic, assign) CGFloat videoTileGap;
@property(nonatomic, assign) CGFloat cornerRadius;
@property(nonatomic, strong) NSColor* videoBackground;
@end

@protocol ZMMTSidePanelTheme <NSObject>
@property(nonatomic, strong) ZMPigment *floatFrame;
@property(nonatomic, strong) ZMPigment *sideFrame;
@property(nonatomic, strong) ZMPigment *content;
@end

@protocol IZMMTTheme <ZMRoutableObject>
@property(nonatomic, strong) id<ZMMTVideoTheme> videoTheme;
@property(nonatomic, strong) id<ZMMTSidePanelTheme> sidePanelTheme;
@end

NS_ASSUME_NONNULL_END
