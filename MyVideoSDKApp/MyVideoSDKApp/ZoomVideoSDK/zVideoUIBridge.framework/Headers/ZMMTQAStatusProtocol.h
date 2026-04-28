//
//  ZMMTQAStatusProtocol.h
//  QAUI
//
//  Created by Francis Zhuo on 9/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTQAQuestion;
@class ZMMTQAAnswer;
@class ZMMTQAUser;
@protocol ZMMTQAStatusProtocol <NSObject>
@optional
- (void)onReceiveQuestions:(NSArray<ZMMTQAQuestion*>*)questionArray;
- (void)onReceiveAnswers:(NSArray<ZMMTQAAnswer*>*)answerArray;

- (void)onUserDismissQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserReopenQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserUpvoteQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserRevokeUpvoteQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;

- (void)onUserDeleteQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserDeleteAnswer:(ZMMTQAAnswer*)answer operatedByUser:(nullable ZMMTQAUser*)operateUser;

- (void)onUserStartComposingQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserStopComposingQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserStartLivingQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;
- (void)onUserStopLivingQuestion:(ZMMTQAQuestion*)question operatedByUser:(nullable ZMMTQAUser*)operateUser;

- (void)onDismissQuestionByQuestionID:(NSString *)questionID;

- (void)onAllowAskQuestionAnonymouslyStatusChanged;
- (void)onAllowAttendeeSubmitQuestionStatusChanged;
- (void)onAllowAttendeeViewAllQuestionStatusChanged;
- (void)onAllowAttendeeUpvoteQuestionStatusChanged;
- (void)onAllowAttendeeAnswerQuestionStatusChanged;

- (void)onNotifyConnectStart;
- (void)onNotifyConnectResult:(BOOL)isSuccess;
- (void)onRefreshQAUI;
@end

NS_ASSUME_NONNULL_END
