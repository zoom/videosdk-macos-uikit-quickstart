//
//  ZMUser+AppTag.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2025/6/18.
//

#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAppTag : NSObject <NSCopying>
@property (nonatomic, strong) NSString *appID;
@property (nonatomic, strong) NSString *appName;
@property (nonatomic, strong, nullable) NSString *appIconPath;

- (NSImage*)iconWithSize:(NSSize)size;
@end

@interface ZMUser (AppTag)
- (BOOL)hasAppTag;
- (NSArray<ZMMTAppTag*>*)appTagArray;
@end

NS_ASSUME_NONNULL_END
