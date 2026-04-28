//
//  IZMMTQAMgr.h
//  VideoUIBridge
//
//  Bridge protocol for Meeting Q&A.
//  VideoUI should depend on this protocol instead of QAUI helpers/categories,
//  so on-demand loading of VideoUIEx won't cause missing-selector crashes.
//

#ifndef IZMMTQAMgr_h
#define IZMMTQAMgr_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __OBJC__
@protocol ZMRoutableObject;

@protocol IZMMTQAMgr <ZMRoutableObject>
@property (nonatomic, assign) BOOL isMerging;

// Panel state
- (BOOL)isQAShowing;
- (void)openQA;
- (void)closeQA;

// Entry / badge / visibility
- (BOOL)canShowQAButton;
- (BOOL)isQAReady;
- (BOOL)isAllowToAskQuestion;
- (NSInteger)getOpenQuestionCount;
- (int)getUnreadAnsweredQuestionCount;

// Security / status
- (BOOL)isQAOff;
- (BOOL)isStreamConflict;
- (BOOL)isMeeingQAEnableForSecurity;
- (BOOL)isWebinarQASubsettingLocked;
- (void)onDisableQAForSecurity:(BOOL)disable;

// Tip
- (void)showEnableQATip;
@end
#endif

NS_ASSUME_NONNULL_END

#endif /* IZMMTQAMgr_h */
