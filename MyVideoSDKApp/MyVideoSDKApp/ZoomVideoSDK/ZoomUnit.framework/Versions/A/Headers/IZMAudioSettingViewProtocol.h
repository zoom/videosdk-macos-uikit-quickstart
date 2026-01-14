//
//  IZMAudioSettingViewProtocol.h
//  ZoomUnit
//
//  Created by Javenlee.Li on 2024/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMAudioSettingViewProtocol <NSObject>
@optional
- (void)refreshAudioSettingUI;
- (void)closePersonalVoiceDisclaimerIfNeed;

- (void)mt_checkPersonalizedVoiceState;

@end

NS_ASSUME_NONNULL_END
