//
//  IZMLottieProtocol.h
//  ChatUI
//
//  Created by davies zhao on 2023/2/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMLottieViewDelegate <NSObject>

/// Plays the animation
- (void)play;

/// Stops the animation at the current frame. The completion block will be called.
- (void)pause;

/// Stops the animation and rewinds to the beginning. The completion block will be called.
- (void)stop;

/// Tells the animation to loop indefinitely. Defaults to NO.
@property (nonatomic, assign) BOOL loopAnimation;

/// Load animation by name from a specific bundle.
- (void)setAnimationNamed:(nonnull NSString *)animationName inBundle:(nullable NSBundle *)bundle;

/// Load animation from a JSON dictionary
- (void)setAnimationFromJSON:(NSDictionary *)animationJSON;
@end

@protocol IZMLottieProtocol <ZMRoutableObject>

@property (nonatomic, assign, readonly) BOOL isLoaded;

+ (instancetype)shared;

- (NSView <ZMLottieViewDelegate> *)generateLottieView;

- (NSBundle *)lottieResourceBundle;

@end

NS_ASSUME_NONNULL_END
