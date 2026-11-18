//
//  IZMConfReactionsMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMConfReactionsMgr_h
#define IZMConfReactionsMgr_h

#import <zVideoUIBridge/ZMMTBaseView.h>
#ifdef __cplusplus
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class ZMUser, ZMConfReactionsMenuItem, ZMMTEmojiMenuItem, ZMSysEmojiMgr, ZMMTBaseViewController, ZMWebinarReactionsModel, ZMEmojiModel, ZMEmojiV2Configuration;
@protocol ZMConfReactionsMenuItemView;

typedef NS_ENUM(NSUInteger, ZMWebinarEmojiReactionType) {
    ZMWebinarEmojiReactionTypeFull,
    ZMWebinarEmojiReactionTypeCompact,
    ZMWebinarEmojiReactionTypeHidden
};

typedef NS_ENUM(NSUInteger, ZMReactionGestureType) {
    ZMReactionGestureTypeNone = 0,
    ZMReactionGestureTypeThumbsup = 1,
    ZMReactionGestureTypeHand = 2,
    ZMReactionGestureTypeThumbsdown = 14,
    ZMReactionGestureTypeOk = 15,
    ZMReactionGestureTypeCelebrate = 18,
    ZMReactionGestureTypeHeart = 19,
};

typedef NS_ENUM(NSUInteger, ZMMTReactionMenuKind) {
    ZMMTReactionMenuKindUnknown = 0,
    ZMMTReactionMenuKindReactionPanel,
    ZMMTReactionMenuKindMoreEmojiPanel,
};

#define GESTURE_TIME    2
@protocol ZMReactionsServiceProtocol;

/**
 * @router ZMMTShared
 */
@protocol IZMConfReactionsMgr <ZMRoutableObject>

- (ZMSysEmojiMgr *)sysEmojiMgr;
- (NSDictionary *)webinarEmojisDic;
- (ZMWebinarEmojiReactionType)webinarReactionType;
- (ZMReactionGestureType)reactionGestureType;
- (ZMMTBaseViewController *)newViewControllerWithType:(ZMMTType)type;
- (ZMMTBaseViewController *)newExplosionReactionViewController;
- (ZMMTBaseViewController *)newFloatingReactionViewController;

- (void)resetWebinarEmoji;

/** user emoji reaction changed callback */
#ifdef __cplusplus
- (void)onEmojiReactionReceived:(ZMUser *)user emoji:(NSString *)emoji emojiCategory:(CmmReactionCategory)emojiCategory;
#endif

- (nullable NSImage *)reactionImageWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
- (nullable NSImage *)feedbackImageWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
- (nullable NSImage *)feedbackIconWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
- (nullable NSImage *)feedbackImageWithString:(NSString *)string size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc isFBEx:(BOOL)isFBEx;
- (nullable NSImage *)feedbackIconWithType:(int)type size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc isFBEx:(BOOL)isFBEx;
/** draw a emoji to image */
- (nullable NSImage *)emojiImageWithString:(NSString *)string size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
/** draw a single feedback image type: CMM_NONVERBAL_FEEDBACK */
- (nullable NSImage *)feedbackIconWithType:(int)type size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;

- (nullable ZMWebinarReactionsModel *)webinarEmoji;

- (nullable ZMCustomEmojiModel *)customEmojiModelWithUser:(ZMUser *)user;

- (NSView<ZMConfReactionsMenuItemView> *)getReactionsMenuItem;
- (ZMMTEmojiMenuItem *)getReactionsMoreEmojiMenuItem;
/** get local skin tone reaction emojis */
- (NSArray <NSDictionary *>*)localSkinToneEmojis;
- (NSArray <NSDictionary *>*)localSkinToneDynamicEmojis;
/** get local skin tone for raise hand emoji */
- (nullable NSString *)localSkinToneRaiseHand;
/** get raise hand emoji for skin tone */
- (BOOL)isDynamicEmojiMoreMenu;
/** get floating emoji more menu flag */
#ifdef __cplusplus
- (nullable NSString *)raiseHandEmojiWithSkinTone:(CmmEmojiReactionSkinTone)skinTone;
- (CmmReactionCategory)getEmojiReactionCategoryWithUser:(ZMUser *)user;
#endif

- (void)eventTrackingWithSubEvent:(int)subEvent;

- (nullable NSString *)reactionForUser:(ZMUser *)user;

- (void)interpreterInfoChanged;
// reactions in webinar
#ifdef __cplusplus
- (void)onEmojiReactionReceivedInWebinar:(const EmojiContentMap &)emoji_contents confSession:(ZMConfSession *)confSession;
#endif

- (void)updateReactionViewWithType:(ZMWebinarEmojiReactionType)type;

// reaction gesture
#ifdef __cplusplus
- (void)onHandGestureDetected:(SSB_MC_DATA_BLOCK_HAND_POSE_INFO)info;
#endif

- (void)onReactionAwareness:(BOOL)isEnable;
- (void)toggleHandGestureSetting;

// aic adoption
- (BOOL)isNeedToShowAicAdoption;
- (BOOL)isMyselfInAwayOrCoffeeState;
- (void)recvdTranscriptResult:(NSString *)reportId type:(NSInteger)type result:(BOOL)result;
- (void)startTranscriptionGeneratedTimer;
- (void)transcriptionTimerFire;
- (void)setCanShowBRBAicCM:(BOOL)shouldShow;
- (void)stopTranscriptionGeneratedTimer;
- (void)stopMinuteTrackerTimer;
- (NSString *)getMinutesString;

//Lottie
- (nullable NSString *)lottieAnimationNameForUser:(ZMUser *)user;
- (nullable NSString *)lottieAnimationNameForReaction:(NSString *)reaction;

// [ZOOM-426408] Raise Hand Improvements
- (void)activeAudioChanged;

// ZOOM-713530 Keyboard shortcuts
- (void)openShortcutReactionsPanel;
- (void)sendShortcutEmoji:(NSString *)title withIdentifier:(NSString *)identifier;

- (BOOL)shouldShowRaiseHandIndex;

- (BOOL)isFeedbackRaiseHandWithUser:(ZMUser *)user;
- (NSUInteger)getAVStatus;
- (void)clearAVStatus;
- (BOOL)isAwayStatus;
- (void)setIsAwayStatus:(BOOL)newStatus;
- (void)cleanBRBIfNeeded;

-(void)triggerDynamicEmojiReaction:(NSString *)emojiString;

//zUI meeting reaction setting call back
- (void)ShowEnableSendReactionsConfirmDialogIfNeed;

#pragma mark - Reaction redesign - DG/LOG builds only

- (BOOL)isReactionRedesignEnabled;

/**
 * Called by the React-button toolbar component BEFORE popping a menu (the
 * primary reactions menu, the more-emoji menu, or any of the sub-menus that
 * anchor on the React button). Closes the AutoLower and Awareness windows,
 * but does NOT cancel the AutoLower countdown timer.
 * Implementation is a no-op when redesign is disabled.
 */
- (void)closeReactionFloatingWindowsForMenuOpen;

/**
 * Called from the menu's menuWillClose hook to restore the Awareness window
 * (AutoLower self-restores via its timer's next tick).
 * Implementation is a no-op when redesign is disabled.
 */
- (void)restoreReactionFloatingWindowsAfterMenuClose;

/// Reports the closing reaction-menu surface for interaction telemetry.
- (void)reactionMenuWillClose:(ZMMTReactionMenuKind)menuKind;

/// Build the V2 panel configuration (visible tabs + feedback items +
/// animated emojis) from the current meeting state. Returns nil when
/// redesign is disabled. Exposed on the protocol so embed-mode hosts
/// (e.g. `ZMMTEmojiMenuItemV2`) can build their own VC without taking
/// a hard dependency on the concrete `ZMConfReactionsMgr` class.
- (nullable ZMEmojiV2Configuration *)buildV2Configuration;

@end

/**
 * @poster ZMMTEventPoster
 */
@protocol ZMConfReactionsProtocol <NSObject>

@optional
#ifdef __cplusplus
- (void)onRaiseHandIndexArrayChanged:(const ns_zm_conf_universal_ui::RaiseHandInstParam&) param;
- (void)onProcessEmojiReactionReceived:(const ns_zm_conf_universal_ui::ConfInstParam&)param event:(const ns_zm_conf_universal_ui::EmojiEvent&)event;
- (void)onQueryEmojiStatus:(const ns_zm_conf_universal_ui::ConfInstParam&)param emojiContent:(const CString&)emojiContent emojiCategory:(CmmReactionCategory)emojiCategory;
#endif

@end

NS_ASSUME_NONNULL_END

#endif /* IZMConfReactionsMgr_h */
