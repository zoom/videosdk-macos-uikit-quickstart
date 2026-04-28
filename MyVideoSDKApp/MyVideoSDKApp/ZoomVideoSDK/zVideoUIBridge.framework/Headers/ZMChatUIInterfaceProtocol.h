//
//  ZMChatUIInterfaceProtocol.h
//  ZoomSetting
//
//  Created by Groot Ding on 2022/3/31.
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef ZMChatUIInterfaceProtocol_h
#define ZMChatUIInterfaceProtocol_h
#import <ZoomUnit/ZPZMailAdapter.h>
#import <dataModule/zDataConstants.h>

@class ZMUserProfileFloat;
@class ZMMessageAdapter;
@class ZMFileEntity;
@class ZMChatFileItem;
@class ZMUserProfileFloatViewController;
@class ZMProfileConfig;
@class ZMWKWebUserProfileViewController;

@protocol ZMChatUISessionGroupAdapterProtocoll;
@protocol ZMChatUISessionAdapterProtocol;
@protocol ZMChatUISessionStorageInfoProtocol;

@protocol IZMUserProfileDataAndActionHelper <NSObject>
- (BOOL)isEnableHostWebProfileCard;
@end

@protocol IZMMessageAPIHelper <NSObject>
- (ZoomIMPresence)getMyPresence;
- (ZoomIMPresenceStatus)getMyPresenceStatus;
- (BOOL)isEnableOutOfOffice;
@end

@protocol IZMSpellCheckSettingsHelper <NSObject>
- (void)setContinuousSpellCheckingEnabled:(BOOL)enabled;
- (void)setGrammarCheckingEnabled:(BOOL)enabled;
- (void)setAutomaticSpellingCorrectionEnabled:(BOOL)enabled;
@end

@protocol IZMReadReceiptsHelper <NSObject>
- (BOOL)getReadReceiptsUserSetting;
- (void)setReadReceiptsUserSetting:(BOOL)enabled;
@end

@protocol ZMChatUISessionStorageHelper <NSObject>
- (void)getAllSessionStorageInfosWithProgress:(nullable void (^)(NSUInteger processedCount, NSUInteger total, id<ZMChatUISessionStorageInfoProtocol> _Nullable currentItem))progress
                                  completion:(void (^)(NSArray<id<ZMChatUISessionStorageInfoProtocol>> * _Nullable storageInfos, NSError * _Nullable error))completion;

- (void)cleanupStorageForFolderPaths:(NSArray<NSString *> *)folderPaths
                            progress:(nullable void (^)(NSUInteger processedCount, NSUInteger total, id<ZMChatUISessionStorageInfoProtocol> _Nullable currentItem))progress
                          completion:(void (^)(BOOL success, NSError * _Nullable error))completion;
@end

@protocol ZMChatUIBuddyParamProtocol <NSObject>

@optional
//type is from ZoomBuddyGroupBuddyType string,split by ",",like "1,2,3"
- (NSString *)contactType;
- (BOOL)isForInviteToMeeting;
- (BOOL)externalFlag;
- (NSInteger)category;
- (NSString *)reqSource;

@end

@protocol ZMChatUISearchInterfaceProtocol <NSObject>

- (NSString *)searchBuddy:(NSString *)key param:(id<ZMChatUIBuddyParamProtocol>)param callBack:(void(^)(NSString *key,NSArray <NSString *> * jids,NSError *error))callBack;

- (NSString *)asyn_searchLocalBuddyByKey:(NSString *)key callBack:(void(^)(NSString *key,NSArray <NSString *> * jids,NSError *error))callBack;

- (void)removeBuddySearch:(NSString *)key;

- (void)refreshBuddyVCards:(NSArray<NSString *> *)jids;
- (void)refreshBuddyVCardsRightNow:(NSArray<NSString *> *)jids;
@end

@protocol ZMChatUIPresenceInterfaceProtocol <NSObject>

- (void)subscribeBuddyPresence:(NSArray <NSString *>*)jids forType:(int)type;

//target use ZMChatUIBuddyUpdateInterfaceProtocol
- (void)registerBuddyUpdateByTartget:(id)target;

@end

@protocol ZMChatUIMessageInterfaceProtocol <NSObject>

@required

- (void)jumpToChatByMessageId:(NSString *)messageId sessionId:(NSString *)sessionId;

- (void)deleteMessageById:(NSString *)messageId sessionId:(NSString *)sessionId;

- (ZMMessageAdapter *)getMessageById:(NSString *)messageId sessionId:(NSString *)sessionId;

@end

@protocol ZMChatUIVCardInterfaceProtocol <NSObject>

@required

- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect;

//- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect autoClose:(BOOL)autoClose;

- (ZMUserProfileFloat *)getUserProfileFloat;

- (NSViewController *)getNewVcardViewController:(NSString *)uid floatConfig:(ZMProfileConfig *)config;

- (NSString *)getJIDWithUserId:(NSString *)userid;

- (BOOL)isUserInvalid:(NSString *)jid meetingGuest:(BOOL)meetingGuest;

@end

//@protocol ZMChatUIToastInterfaceProtocol <NSObject>
//
//@required
//
//- (void)showToast:(id)toast_String_or_AttributedString autoDisappear:(BOOL)autoDisappear type:(NSInteger)type;
//
//@end

@protocol ZMChatUIOpenFileInterfaceProtocol <NSObject>

@required

- (void)openFilePreviewByItems:(NSArray <ZMFileEntity *> *)fileItems sessionId:(NSString *)sessionId currentIndex:(NSInteger)currentIndex  window:(NSWindow *)window isDockOut:(BOOL)isDockout;

- (void)openCodeSnippetByMessage:(ZMMessageAdapter *)message window:(NSWindow *)window;

- (void)openWhiteboardFile:(ZMChatFileItem *)file;

@end

@protocol ZMChatUIShareMailInfoProtocol <NSObject>

@required
- (NSString *)mailTitle;
- (NSString *)fromJid;
- (NSString *)fromName;
- (NSString *)mailBody;
- (NSString *)mailId;
- (unsigned long long)mailTime;

- (NSString *)filePath;
@optional
- (BOOL)isFromZMail;
- (NSString *)validInfo;

@end

@protocol ZMChatUIShareMessageInterfaceProtocol <NSObject>

@required

- (void)shareEmail:(id<ZMChatUIShareMailInfoProtocol>)emailInfo shareCallback:(void (^)(ZMShareResult result))shareCallback;

@end

@protocol ZMUnifyScheduleProtocol;
@protocol ZMChatUIScheduernterfaceProtocol <NSObject>

@required
- (BOOL)isZoomCalendarUIEnabled;
- (BOOL)isCalendarUILoaded;
- (void)closeScheudlerWnd;
- (void)openCalendarTab;
- (void)expandQuickSchedule;
- (void)closeScheduler;
- (void)closeUnifyScheduler;
- (void)switch2FindTime;
- (void)schedulerOptionsHaveChanged;
- (void)showScheduler:(bool)show;
- (id<ZMUnifyScheduleProtocol>)unifyScheduler;
@end

//@protocol ZMChatUIActivityCenterInterfaceProtocol <NSObject>
//
//@required
//- (void)openActivityCenterSettingWindow;
//- (void)closeActivityCenterSettingWindow;
//
//- (void)closeActivityCenterWindow;
//
//- (void)closeActivityCenterWithSourceType:(NSInteger)sourceType webView:(NSView *)webView;
//@end

@protocol ZMChatUIReportProtocol <NSObject>

@required
- (void)reportWhiteboardFromMeeting;
- (void)reportNotesFromMeeting;
- (void)reportDocsFromMeeting;
- (void)openQualtricsFeedbackFromMeeting:(NSString*)activeTab
                                  sender:(id)sender;
@end

//@protocol ZMChatUIJSCallInterfaceProtocol <NSObject>
////- (void)addPostJsMessageCommonAPISink;
////- (void)removePostJsMessageCommonAPISink;
////- (NSArray *)getRegisteredFunctionNames;
//- (void)handleJsMessageWithParam:(NSDictionary *)param sourceType:(NSInteger)type;
//- (NSString *)getResourceStringWithResourceType:(NSInteger)resourceType;
//@end

@protocol ZMWebViewCallProtocol <NSObject>
@optional
- (void)handleJsMessageWithParam:(NSDictionary *)param sourceType:(NSInteger)type;
- (NSString *)getResourceStringWithResourceType:(NSInteger)resourceType;
- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect autoClose:(BOOL)autoClose;
- (void)showToast:(id)toast_String_or_AttributedString autoDisappear:(BOOL)autoDisappear type:(NSInteger)type;

- (void)openActivityCenterSettingWindow;
- (void)closeActivityCenterSettingWindow;
- (void)closeActivityCenterWindow;
- (void)closeActivityCenterWithSourceType:(NSInteger)sourceType webView:(NSView *)webView;
@end

@protocol ZMChatUIInterfaceProtocol <IZMUserProfileDataAndActionHelper, IZMMessageAPIHelper, IZMSpellCheckSettingsHelper, IZMReadReceiptsHelper, ZMChatUISessionStorageHelper, ZMChatUIMessageInterfaceProtocol, ZMChatUIVCardInterfaceProtocol, ZMChatUIOpenFileInterfaceProtocol, ZMChatUIShareMessageInterfaceProtocol, ZMChatUISearchInterfaceProtocol, ZMChatUIPresenceInterfaceProtocol, ZMChatUIScheduernterfaceProtocol, ZMChatUIReportProtocol, ZMWebViewCallProtocol>

- (BOOL)isLoginin;

- (nullable NSArray<id<ZMChatUISessionAdapterProtocol>> *)chatSessions;

@end


#endif /* ZMChatUIInterfaceProtocol_h */
