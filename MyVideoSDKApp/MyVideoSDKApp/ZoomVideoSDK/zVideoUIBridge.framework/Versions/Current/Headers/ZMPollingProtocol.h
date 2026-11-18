//
//  ZMPollingProtocol.h
//  zVideoUIEx
//
//  Created by Francis Zhuo on 4/14/21.
//

#import <Foundation/Foundation.h>
//#import "ZMPollData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMPollType) {
    ZMPollTypeUnknown = 0,
    ZMPollTypeBasic,
    ZMPollTypeAdvanced,
    ZMPollTypeQuiz
};

typedef NS_ENUM(NSInteger, ZMPollUIType) {
    ZMPollUITypeOldPollFlowAndNormal = 0,
    ZMPollUITypeOldPollFlowAndAdvanced,
    ZMPollUITypeNewPollFlow
};

typedef NS_ENUM(NSInteger, ZMPollResultType)
{
    ZMPollNone                      = -1,
    ZMPollInProgressResult          = 0,        //End Poll
    ZMPollInSharingResultHost       = 1,        //Stop Sharing
    ZMPollInSharingResultAttendee   = 2,        //Close
    ZMPollInQuickResult             = 3,        //Submit
    ZMPollNotStart                = 4,          //Launch
    ZMPollClosed                  = 5           //Share Results
};

typedef NS_ENUM(NSUInteger, ZMPollEvent) {
    ZMPollEventCreate,
    ZMPollEventEdit,
    ZMPollEventLaunch,
    ZMPollEventRelaunchPoll,
    ZMPollEventDownloadResult,
    ZMPollEventViewResultFromBrowser,
    ZMPollEventShareResult,
    ZMPollEventEndPoll,
    ZMPollEventCloseWindow,
    ZMPollEventMinimizeWindow,
    ZMPollEventMaximizeWindow
};

typedef NS_ENUM(NSUInteger, ZMPollPageType) {
    ZMPollPageTypeList = 0,
    ZMPollPageTypeWebView,
    ZMPollPageTypeDetail,
    ZMPollPageTypeWebError,
    ZMPollPageTypeSubmit
};

typedef NS_ENUM(NSUInteger, ZMPollStartType) {
    ZMPollStartTypeAll = 0,
    ZMPollStartTypeOnlyLaunch,
    ZMPollStartTypeOnlySharing
};

typedef NS_ENUM(NSUInteger, ZMPollWebActionType) {
    ZMPollWebActionTypeCreate = 0,
    ZMPollWebActionTypeEdit,
};

@protocol ZMPollAnswer <NSObject>

@property (nonatomic, readwrite, assign) NSInteger selectedCount;
@property (nonatomic, readwrite, assign) NSInteger answeredCount;
@property (nonatomic, readwrite, assign) BOOL checked;
@property (nonatomic, readwrite, assign) NSInteger resultWidth;
@property (nonatomic, copy) NSString *answerID;
@property (nonatomic, copy) NSString *optionLabel;
@property (nonatomic, copy) NSString *answerContent;
@property (nonatomic, copy) NSString *selfInputAnswer;
@property (nonatomic, copy) NSString *pollingID;
@property (nonatomic, copy) NSString *questionID;
@property (nonatomic, copy) NSString *subQuestionID;

@end

@protocol ZMPollQuestion <NSObject>

@property (nonatomic, readwrite) NSInteger questionType;
@property (nonatomic, copy) NSString *questionID;
@property (nonatomic, copy) NSString *serialNumber;
@property (nonatomic, copy) NSString *imageDesc;
@property (nonatomic, assign) NSInteger questionIndex;
@property (nonatomic, copy) NSString *questionContent;
@property (nonatomic, copy) NSString *subQuestionContent;
@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, retain) NSImage *showImage;
@property (nonatomic, assign) NSUInteger imageWidth;
@property (nonatomic, assign) NSUInteger imageHeight;
@property (nonatomic, copy) NSString *pollingID;
@property (nonatomic, assign) NSInteger answeredCount;
@property (nonatomic, assign) CGFloat cellHeight;
@property (nonatomic, retain) NSMutableArray *answers;
@property (nonatomic, retain) NSMutableArray *rightAnswers;
@property (nonatomic, retain) NSMutableArray *subQuestions;
@property (nonatomic, assign) NSInteger   currentLineNumber;
@property (nonatomic, assign) BOOL isRequired;
@property (nonatomic, assign) BOOL isCaseSensitive;
@property (nonatomic, assign) NSUInteger minCharacters;
@property (nonatomic, assign) NSUInteger maxCharacters;
@property (nonatomic, copy) NSString *otherTextAnswer;
@property (nonatomic, assign) BOOL isSingleWrong;
@property (nonatomic, assign) int voteCount;

@optional
- (void)addAnswer:(id<ZMPollAnswer>)answer;
- (nullable id<ZMPollAnswer>)getAnswerByIndex:(NSInteger)index;
- (NSInteger)answerCount;
- (void)addRightAnswer:(id<ZMPollAnswer>)answer;
- (nullable id<ZMPollAnswer>)getRightAnswerByIndex:(NSInteger)index;
- (NSInteger)rightAnswerCount;
- (void)addSubQuestions:(id<ZMPollQuestion>)question;
- (nullable id<ZMPollQuestion>)getSubQuestionByIndex:(NSInteger)index;
- (NSInteger)subQuestionCount;

@end

@protocol ZMPollingDelegate;
@protocol ZMPollData <NSObject>

@property (nonatomic, readwrite) NSInteger pollingState;
@property (nonatomic, readwrite) unsigned int elapsedTime;
@property (nonatomic, readwrite) NSInteger voteCount;
@property (nonatomic, copy) NSString *pollingID;
@property (nonatomic, copy) NSString *pollingName;
@property (nonatomic, retain) NSMutableArray *questions;
@property (nonatomic, readwrite, assign) NSInteger voteIndex;
@property (nonatomic, copy) NSString* viewDetailsUrl;
@property (nonatomic, assign) NSInteger pollType;
@property (nonatomic, assign) NSInteger myPollState;
@property (nonatomic, assign) NSInteger resultType;
@property (nonatomic, assign) NSInteger pollIndex;
@property (nonatomic, assign) CGFloat containerWidth;
//@property (nonatomic, assign) BOOL showOneQuestion;
@property (nonatomic, assign) BOOL isSubmitted;
@property (nonatomic, assign) BOOL isAnonymous;
@property (nonatomic, assign) BOOL isFromLibrary;
@property (nonatomic, assign) BOOL isStared;
@property (nonatomic, assign) BOOL isSharedPoll;
@property (nonatomic, assign) BOOL isEditAllowed;
@property (nonatomic, assign) BOOL isShowScheduleTime;
@property (nonatomic, assign) long long autoLaunchTime;
@property (nonatomic, assign) long long autoEndTime;
@property (nonatomic, assign) long long autoShareTime;
@property (nonatomic, assign) long long autoStopShareTime;
@property (nonatomic, copy) NSString *sharedUserName;
@property (nonatomic, assign) long long createTime;
@property (nonatomic, assign) long long editTime;
@property (nonatomic, assign) BOOL isAllowShowAnswerToAllEnable;
@property (nonatomic, assign) BOOL isNewPollFlowEnabled;
@property (nonatomic, copy) NSString *reportDownloadUrl;
@property (nonatomic, copy) NSString *pollingViewDetailsUrl;
@property (nonatomic, assign) int totalUserCount;
@property (nonatomic, assign) int totalVotedUserCount;
@property (nonatomic, assign) BOOL needShowDownloadButton;
@property (nonatomic, assign) int pollingCount;
@property (nonatomic, assign) BOOL isSupportAdvancedPollEnabled;
@property (nonatomic, assign) BOOL keepUIObject;
@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, copy) NSString *questionID;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, copy) NSString *submitUrl;
@property (nonatomic, copy) NSString *viewResultUrl;
@property (nonatomic, copy) NSString *content;

@property(weak) id<ZMPollingDelegate> delegate;

@optional
- (void)addQuestion:(id<ZMPollQuestion>)question;
- (nullable id<ZMPollQuestion>)getQuestionByIndex:(NSInteger)index;
- (NSInteger)questionCount;
- (NSInteger)requiredQuestionCount;
- (NSInteger)getNotAnswerdRequiredQuestionIndex;
- (BOOL)notRequiredShortLongQuestionAnswered;
- (NSInteger)getFirstAnsweredQuestionIndex;
- (NSInteger)getAnsweredQuestionCount;
- (NSInteger)getTotalAnsweredQuestionCount;
+ (BOOL)isRequireedQuestionAnswered:(id<ZMPollQuestion>)question;
+ (NSMutableString *)getQuestionAnswerWithQuestion:(id<ZMPollQuestion>)question answerType:(NSInteger)answerType;
+ (NSInteger)getCheckQuestionAnsweredType:(id<ZMPollQuestion>)question;
+ (NSInteger)getCheckQuestionAnsweredType:(id<ZMPollQuestion>)question answer:(id<ZMPollAnswer>)answer;
+ (NSString *)getCheckQuestionAnsweredContent:(id<ZMPollQuestion>)question;
+ (NSInteger)getTextQuestionAnsweredType:(id<ZMPollQuestion>)question;
+ (NSInteger)getHavaSubQuestionQuestionAnsweredType:(id<ZMPollQuestion>)question;
+ (NSInteger)getQuestionAnsweredType:(id<ZMPollQuestion>)question;
+ (BOOL)isShortLongQuestionAnswered:(id<ZMPollQuestion>)question inputString:(NSString *)inputString;
- (void)setPollQuizData:(NSString*)pollingID;
- (BOOL)needShowOneQuestionOnce;

@end


@protocol ZMPollingDelegate <NSObject>

@optional
- (void)showPollingConflictAlertEx;
- (BOOL)isPollingHostCoHostEx;
- (BOOL)isWebinarPanelistEx;
- (BOOL)isInSilentModeEx;
- (BOOL)isSelfOriginalHostEx;
- (BOOL)isAllowPanelistVoteEx;
- (NSString*)getPollingEditUrlEx:(NSString*)pollingID;
- (BOOL)isCreateBOBaseOnPollingEnabledEx:(NSString *)questionID;
- (BOOL)requestPollingResult:(NSString *)pollingID
                  questionID:(NSString *)questionID
                       order:(NSUInteger)order
                enableLimits:(BOOL)enableLimits
                       count:(NSUInteger)count;
- (BOOL)canEditBOEx;
- (NSInteger)getParticipantsLimitPerRoomWhenCreateBOEx;
- (void)setParticipantsLimitPerRoomWhenCreateBOEx:(NSInteger)count;
- (BOOL)isSplitParticipantsWhenCreateBOEx;
- (void)setSplitParticipantsWhenCreateBOEx:(BOOL)set;
- (NSInteger)getMaxBORoomCountEx;
- (NSString *)getPollingViewDetailsUrlEx:(NSString*)pollingID;
- (void)editPollForMeetingEx;
- (BOOL)startPollEx:(NSString*)pollingID;
- (BOOL)closePollEx:(NSString*)pollingID;
- (BOOL)stopPollSharingEx:(NSString*)pollingID;
- (void)hasSubmitPollingEx:(BOOL)submit;
- (BOOL)submitPollEx:(NSString*)pollingID;
- (BOOL)starPollEx:(NSString*)pollingID;
- (BOOL)unStarPollEx:(NSString*)pollingID;
- (void)updateFitBarEx;
- (int)getVoteUserCountByPollingIDEx:(NSString*)pollingID;
- (int)getInMeetingVotedUserCountByPollingIDEx:(NSString*)pollingID;
- (int)getQRCodeVotedUserCountByPollingIDEx:(NSString*)pollingID;
- (int)getTotalUserCountEx;
- (NSInteger)inMeetingAnswerSelectedCountEx:(id<ZMPollAnswer>)answer;
- (void)saveAnswerResultEx:(id<ZMPollAnswer>)answer;
- (void)saveSubQuestionAnswerResultEx:(id<ZMPollAnswer>)answer;
- (void)saveTextAnswerResultEx:(id<ZMPollAnswer>)answer;
- (void)saveSubQuestionTextAnswerResultEx:(id<ZMPollAnswer>)answer;
- (BOOL)pollReadyEx;
- (BOOL)reStartPollEx:(NSString*)pollingID;
- (BOOL)sharePollResultEx:(NSString*)pollingID;
- (unsigned long long)elapsedTimeEx;
- (int)getPollingCountEx;
- (id<ZMPollData>)getPollingByIDEx:(nullable NSString*)ID;
- (id<ZMPollData>)getPollingByIndexEx:(NSInteger)index;
- (BOOL)isMySelfForUserIdEx:(int)inUserId;
- (BOOL)isWebinarAttendeeEx;
- (BOOL)needShowDownloadButtonEx;
- (NSString *)getReportDownloadLinkEx;
- (NSString *)getQRCodeURLByPollingIDEx:(NSString*)pollingID;
- (BOOL)isWebinarEx;
- (void)saveAllowPanelistVoteStateEx:(BOOL)isAllowVote;
- (BOOL)isPollingLegalNoticeAvailableEx;
- (BOOL)isArchivePollEnabledEx;
- (BOOL)isAllowDisplayQuestionInRandomOrderEnableEx;
- (void)setAllowDisplayQuestionInRandomOrderEnableEx;
- (BOOL)isAllowShowOneQuestionOnceEnableEx;
- (void)setAllowShowOneQuestionOnceEnableEx;
- (BOOL)isAllowShowAnswerToAllEnableEx;
- (void)setAllowShowAnswerToAllEnableEx;
- (BOOL)isPollConflictEx;
- (void)relaunchPollEx:(NSString *)pollingID;
- (BOOL)isAllowReLaunchPollNoticeEnabledEx;
- (BOOL)isSupportAdvancedPollEnabledEx;
- (void)disallowReLaunchPollNoticeEx;
- (BOOL)isNewPollFlowEnabledEx;
- (BOOL)needShowStarEntranceEx;
- (BOOL)isUseLibrarySurveyEnabledEx;
- (BOOL)amIOriginalHostEx;
- (NSString*)getLibraryPollUrlEx;
- (BOOL)hasPollCapabilityEx;
- (BOOL)isWebViewPollEnabledEx;
- (BOOL)canEditPollingEx:(NSString*)pollingID isEditAllowed:(BOOL)allowed;
- (BOOL)canDeletePollingEx:(NSString*)pollingID;
- (BOOL)canStarOrUnstarPollEx;
- (BOOL)canCreatePollingEx;
- (NSString*)getPollingCreateUrlEx;
- (BOOL)isPollingSizeReachedMaxinumEx;
- (BOOL)canDuplicatePollEx:(NSString *)pollingID;
- (NSString*)getViewPollingListURLEx;
- (NSString*)getCreateEditPollUrlEx;
- (BOOL)isPollUrlCustomizedEx:(BOOL)isEdit;
- (NSString*)getProductDomainEx;
- (NSString*)getLanguageIDEx;
- (BOOL)isOnZoomMeetingEx;
- (BOOL)isOnZoomMeetingDisableNewPollFlowEx;
- (NSString *)appendTokenToUrlEx:(NSString *)sourceUrlStr;
- (BOOL)duplicatePollEx:(NSString *)pollingID;
- (BOOL)deletetePollEx:(NSString *)pollingID;
- (BOOL)removeScheduleTimeEx:(NSString *)pollingID;
- (BOOL)requestPollingResultEx:(NSString *)pollingID
                    questionID:(NSString *)questionID
                         order:(NSUInteger)order
                  enableLimits:(BOOL)enableLimits
                         count:(NSUInteger)count;

@end

@protocol ZMPollingProtocol <NSObject>

@property(weak) id<ZMPollingDelegate> delegate;         //ZMPollingMgr

@optional
- (void)setHelper:(id<ZMPollingDelegate>)helper;
- (void)cleanUp;
- (void)updateTimeLabel;
- (void)relaunchPoll;
- (void)updatePollWindow:(BOOL)showWindow pollUrl:(nullable NSString *)pollUrl;
- (void)makePollWindowFirstResponse;
- (void)showPollWithData:(id<ZMPollData>)pollData needShowWindow:(BOOL)showWindow pollUrl:(nullable NSString *)pollUrl;
- (void)closePollLaunchWindow;
- (void)closePollVCWindow;
- (void)updateWebPollWindowPosition:(NSString *)windowPosition;
- (void)resetListSearchField;
- (BOOL)isPollWindowVisible;
- (void)pollConflict:(BOOL)isConflict;
- (void)voteUserCountChanged;
- (void)onHostChanged:(int)inUserId;
- (void)onCoHostChanged:(int)inUserId;
- (nullable id<ZMPollData>)getUnfinishedPoll;
- (void)reloadPollUI;
- (void)updateAttendeePollData;
- (void)onPollError;
- (void)onPollLaunchFailed:(id<ZMPollData>)pollData;
- (void)onPollShareFailed:(id<ZMPollData>)pollData;
- (void)onPollResultUpdate:(id<ZMPollData>)pollData;
- (void)onPollImageDownloaded:(id<ZMPollData>)pollData;
- (void)onPollingDocReceived;
- (void)resetOneQuestionIndex;
- (void)selectPollTabItemAtIndex:(NSUInteger)pageType;
- (void)closeCreateBOAlert;
- (void)showCreateBOErrorAlert;
- (void)closeCreateBOErrorAlert;
- (void)updateCreateBOUI;
- (void)showCreateBOAlertWithQuestion:(id<ZMPollQuestion>)question pollData:(id<ZMPollData>)pollData;

@end

@protocol ZMPollContentDelegate <ZMPollingProtocol, ZMPollingDelegate>

@property(weak) id<ZMPollContentDelegate> pollContentDelagete;

@optional
- (void)setShowPollIndex:(NSInteger)pollIndex;
- (NSInteger)getShowPollIndex;
- (BOOL)isPollWindowMiniaturized;
- (void)showDetailPopupView:(id<ZMPollQuestion>)question positionView:(NSView *)positionView autoClose:(BOOL)autoClose;
- (void)closeDetailPopover;
- (void)reloadTableCellWithRow:(NSInteger)row needReloadData:(BOOL)need;
- (BOOL)canPreviousCellViewBecomeFirstResponse:(NSTableCellView *)cellView;
- (BOOL)canNextCellViewBecomeFirstResponse:(NSTableCellView *)cellView;
- (void)showPollTitleDetailBubble:(id<ZMPollData>)polling positionView:(NSView *)positionView;
- (void)closePollTitleDetailBubble;
- (void)pollContentViewSelectPollIndex:(NSInteger)pollIndex pollData:(id<ZMPollData>)polling;
- (void)selectPollTabViewItemAtIndex:(NSUInteger)pageType;
- (void)jumptoCreatePollItemWithModuleFrom:(ZMPollPageType)from;
- (void)jumptoEditPollItem:(id<ZMPollData>)pollData moduleFrom:(ZMPollPageType)from;
- (CGFloat)getPollTabViewWidth;
- (void)updateAddedPollingID:(NSString *)pollingID;
- (void)hideRemindView;
- (void)resetPollListHighlightRow;
- (void)handleRelaunchPoll:(id<ZMPollData>)pollData;
- (void)handleDuplicatePoll:(id<ZMPollData>)pollData;
- (void)handleDeletePoll:(id<ZMPollData>)pollData;
- (void)handleRemoveScheduleTime:(id<ZMPollData>)pollData;
- (void)handleDownloadPollResult:(id<ZMPollData>)pollData;
- (void)handleViewPollResult:(id<ZMPollData>)pollData;
- (void)showPollDetailSavedView;
- (void)showLoadingView;
- (void)removeLoadingView;
- (BOOL)isPollStarted:(ZMPollStartType)startType;

@end


NS_ASSUME_NONNULL_END
