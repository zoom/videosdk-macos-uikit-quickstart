//
//  NSView+Prism.h
//  Prism
//
//  Created by Felipe Bastos on 12/18/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (Prism)

- (void)viewDidChangeEffectiveFrame;

@property (nonatomic, assign) BOOL needsEffectiveFrameNotification;

@end

NS_ASSUME_NONNULL_END
