//
//  ZMUser+SmartTag.h
//  VideoUI
//
//  Created by Devl on 7/30/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMUser.h>
#import <Prism/ZMUniqueKeyProvider.h>

NS_ASSUME_NONNULL_BEGIN

/// Orthogonal facets of a video port's bottom-left SNT layout. Folds in the size
/// gate; each bit answers one rendering question so consumers test bits instead of matching
/// whole states.
typedef NS_OPTIONS(NSUInteger, ZMMTSmartTagInfo) {
    ZMMTSmartTagInfoNone         = 0,      ///< plain name, no standalone block
    ZMMTSmartTagInfoSeparateSNT  = 1 << 0, ///< SNT icon in the standalone block
    ZMMTSmartTagInfoReplaceName  = 1 << 1, ///< name replaced by the single tag name
};

@interface ZMMTSmartTag : NSObject <NSCopying, ZMUniqueKeyProvider>
@property (nonatomic, assign) ZMUserID userID;
@property (nonatomic, assign) ZMUserID companionID;
@property (nonatomic, assign) int tagID;

@property (nonatomic, assign) BOOL isActive;
@property (nonatomic, assign) SmartNameTagAlignment alignment;
@property (nonatomic, assign) float positionX;  //0~1
@property (nonatomic, assign) float positionY;  //0~1

@property (nonatomic, copy) NSString *tagJid;
@property (nonatomic, copy) NSString *tagName;
@property (nonatomic, copy) NSString *tagAvatar;
@property (nonatomic, copy) NSString *tagShortName;
@property (nonatomic, readonly) BOOL isPositionValid;
@property (nonatomic, readonly) BOOL isCompanionBinded;
@end

@interface ZMUser (SmartTag)
- (nullable NSString *)activeSpeakerName;
- (nullable NSArray<ZMMTSmartTag*> *)smartTagArray;
- (BOOL)hasSmartTag:(BOOL)checkPos;
- (BOOL)hasSmartTagBinded;

- (BOOL)isAble2ShowSmartTag:(CGFloat)width inVideo:(BOOL)inVideo;

/// Folds the caller-supplied "is the standalone SNT block being shown" flag and the user's SNT
/// data into the final info description, so every consumer reads one value. The flag is
/// view-context driven (render width / scene), so callers pass it in rather than the model
/// computing it.
- (ZMMTSmartTagInfo)smartTagInfoShowingTag:(BOOL)showingTag;

/// The tag name that replaces the user name. Keeps the last displayed name if it is still present,
/// otherwise picks the tag with the smallest horizontal position.
- (nullable NSString *)smartTagReplacementName;

@end

NS_ASSUME_NONNULL_END
