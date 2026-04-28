//
//  PZMLocalized.h
//  Prism
//
//  Created by Francis Zhuo on 2025/8/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PZMLocalized : NSObject

@property(class, readonly) PZMLocalized* shared;

#pragma mark - Bundle Registration

- (void)registerBundle:(NSBundle *)bundle;
- (void)registerBundle:(NSBundle *)bundle tableName:(nullable NSString *)tableName;
- (void)registerBundle:(NSBundle *)bundle tableName:(nullable NSString *)tableName atFront:(BOOL)atFront;
- (void)unregisterBundle:(NSBundle *)bundle;

#pragma mark - Lookup
- (void)clearCache;
- (NSString *)localizedString:(NSString *)theKey;
- (NSString *)localizedString:(NSString *)theKey langBundle:(nullable NSBundle *)langBundle enBundle:(nullable NSBundle *)enBundle;
@end

NS_ASSUME_NONNULL_END
