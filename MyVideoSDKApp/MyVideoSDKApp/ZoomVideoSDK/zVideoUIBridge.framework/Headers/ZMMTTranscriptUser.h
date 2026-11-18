//
//  ZMMTTranscriptUser.h
//  VideoUI
//
//  Created by martin yu on 2025/12/23.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTTranscriptUser : ZMUser

+ (nullable ZMMTTranscriptUser *)transcriptUserWithUserID:(ZMUserID)userID confSession:(ZMConfSession *)confSession screenName:(nullable NSString *)screenName;

- (BOOL)isEqualToZmUser:(ZMUser *)object;

- (nullable NSString *)userNameSuffix;
- (nullable NSImage *)displayAvatarImageWithSize:(NSSize)size cornerRadius:(CGFloat)cornerRadius;
@end

NS_ASSUME_NONNULL_END
