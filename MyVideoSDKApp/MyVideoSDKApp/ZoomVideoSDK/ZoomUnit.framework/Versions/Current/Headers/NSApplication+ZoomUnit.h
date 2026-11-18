//
//  NSApplication+ZoomUnit.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/6/12.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSApplication (ZoomUnit)

+ (NSString *)systemSettingPrivacyDescription;

+ (BOOL)zm_isMultiProcessMeetingEnabled;

@end

NS_ASSUME_NONNULL_END
