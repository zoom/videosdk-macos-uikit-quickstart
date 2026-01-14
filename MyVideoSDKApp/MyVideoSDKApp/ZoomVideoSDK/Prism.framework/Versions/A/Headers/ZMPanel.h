//
//  ZMPanel.h
//  Prism
//
//  Created by Devl on 10/22/25.
//

#import <Prism/ZMBasePanel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Note: If the panel needs shadow, TitledMask is required.
 * If you don't want the system titlebar, FullsizeContentMask is required.
 * Automatically maintains widgets/radius/border/shadow, no additional configuration needed.
 */
@interface ZMPanel : ZMBasePanel

@property (nonatomic, nullable, copy) void (^escBlock)(void);
@property (nonatomic, assign) BOOL alertAsSheet;
@property (nonatomic, assign) BOOL responseESC;
@property (nonatomic, assign) BOOL ignoreKey;

@end

@interface ZMUnsharablePanel : ZMPanel
@end

NS_ASSUME_NONNULL_END
