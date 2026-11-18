//
//  ZMAvatarHelper.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 2/13/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN NSString *const kZMDefaultUserAvatar;
APPKIT_EXTERN NSString *const kZMDefaultAppAvatar;

@class ZMUser;
@interface ZMAvatarHelper : NSObject

+ (void)cleanUp;
+ (instancetype)shared;

- (NSImage*)getAvatarByPath:(NSString*)path hasDownloaded:(BOOL)bDownloaded;//will return default avatar if not exist
- (NSImage*)getOriginalAvatarByPath:(NSString*)path hasDownloaded:(BOOL)bDownloaded;
#ifdef __cplusplus
- (BOOL)resetUserAvatarByUser:(ICmmUser *)user;//ZOOM-123364
- (BOOL)requestAvatarByUser:(ICmmUser *)user;
#endif

- (NSImage *)activePureCallImageForUser:(ZMUser*)zmUser;
- (NSImage *)normalPureCallImageForUser:(ZMUser*)zmUser;
- (NSImage *)h323ImageForUser:(ZMUser*)zmUser;
- (NSImage *)zoomRoomImageForUser:(ZMUser*)zmUser;
+ (NSImage *)defaultAvatarImage;


#pragma mark - Get display avatar
#ifdef __cplusplus
- (nullable NSImage*)getUploadAvatarByUser:(ICmmUser*)theUser isAvatarAllowed:(BOOL)isAvatarAllowed constrainSize:(NSSize)inSize;
#endif
- (nullable NSImage*)getDisplayAvatarByZmUser:(ZMUser*)zmUser isAvatarAllowed:(BOOL)isAvatarAllowed constrainSize:(NSSize)inSize generateWithNameIfNeed:(BOOL)generateIfNeed downloadIfNeed:(BOOL)downloadIfNeed;

- (nullable NSImage*)getDisplayAvatarByUserName:(NSString*)userName constrainSize:(NSSize)inSize;
- (nullable NSImage*)getDisplayAvatarWithName:(nullable NSString *)name seed:(nullable NSString *)seed constrainSize:(NSSize)inSize;
#ifdef __cplusplus
- (nullable NSImage*)getDisplayIconByApp:(ICmmConfAppItem*)appItem constrainSize:(NSSize)inSize;
#endif
- (nullable NSImage*)getDisplayAvatarByJid:(NSString*)inUserJid constrainSize:(NSSize)inSize;
- (nullable NSImage*)getAvatarByKey:(NSString*)key constrainSize:(NSSize)inSize;
- (nullable NSImage*)getDisplayAvatarByInvitee:(ZMUser*)zmUser constrainSize:(NSSize)inSize;
- (nullable NSImage*)getDisplayAvatarByPath:(NSString*)path constrainSize:(NSSize)inSize;

#pragma mark - Seed
- (nullable NSString*)colorSeedForZmUser:(ZMUser*)zmUser;
- (nullable NSString*)getCachedSeedByKey:(nullable NSString*)key;
@end
NS_ASSUME_NONNULL_END
