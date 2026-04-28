//
//  IZMMTVcardMgr.h
//  VideoUIBridge
//
//  Created by davies zhao on 10/24/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMWKWebUserProfileViewController;
@class ZMBubbleObject;
@class ZMUser;
@protocol IZMWKWebUserProfileViewController;

@protocol IZMMTVCardBubbleView <NSObject>
@property (nonatomic, retain, nullable) ZMUser *user;
@property (nonatomic, assign) CGFloat focusRingRadius;
@property (nonatomic, retain, nullable) NSString *jid;
@property (nonatomic, assign) BOOL isBubbleShowing;
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, weak) id<ZMTrackBubbleViewDelegate> bubbleViewdelegate;

- (void)setShowPopover:(BOOL)showPopver;
- (void)showVCardViewAtView:(NSView*)view jid:(NSString*)jid;
- (void)showVCardViewAtView:(NSView*)view jid:(NSString*)jid relativeRect:(NSRect)rect;
@end

/**
 * @router ZMMTShared
 */
@protocol IZMMTVcardMgr <ZMRoutableObject>
- (void)showVCard:(ZMUser*)user;
- (void)closeVCard;
- (BOOL)enableShowVcard:(ZMUser*)user;
- (BOOL)enableShowVCardByJid:(NSString*)jid;
- (BOOL)isUserLeft:(ZMUser *)user;

- (NSView<IZMMTVCardBubbleView> *)createVCardBubbleView;

#ifdef __cplusplus
class CmmVCardData;
- (CmmVCardData)getVCardDataWithUserId:(NSString *)userId;
#endif

@property (nonatomic, strong, nullable) NSViewController<IZMWKWebUserProfileViewController> *webProfileVC;
@property (nonatomic, strong) ZMBubbleObject *previousShowedBubble;

@end

NS_ASSUME_NONNULL_END
