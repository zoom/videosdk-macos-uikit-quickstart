//
//  ZMReportWindowAdapter.h
//  ChatUI
//
//  Created by Cooper.Chen on 2024/5/14.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMScreenshotCallback.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMReportWindowHandleDelegate <NSObject>

@optional

- (BOOL)submitJMFReport;

- (NSDictionary <NSString *, NSArray <NSString *> *> *)queryFeedbackIssues;

- (BOOL)submitReport:(NSString *)description
            ticketId:(NSString *)ticketId
          includeLog:(BOOL)includeLog
           moduleInt:(NSInteger)moduleInt
           issueType:(NSInteger)issueType
         audioLogDir:(NSString *)audioLogDir
                date:(NSDate *)date
    attachmentsPaths:(NSArray <NSString *>*)attachmentsPaths;

- (void)showErrorToast:(NSString *)errorInfo;

- (NSWindow *)responsibleWindow;

@end

@interface ZMReportWindowAdapter : NSObject

//+ (BOOL)reportDogfoodIssue;
@property (nonatomic, weak) id<ZMReportWindowHandleDelegate> delegate;

@property (nonatomic, copy) NSString *privacyLink;

+ (instancetype)sharedInstance;

+ (NSString *)featureIDToLocalizedString:(NSString *)num;

+ (NSString *)issueTypeToLocalizedString:(NSString *)num isPhone:(BOOL)phone;

+ (NSDictionary <NSString *, NSArray <NSString *> *> *)queryFeedbackIssues;

+ (BOOL)submitReport:(NSString *)description
            ticketId:(NSString *)ticketId
          includeLog:(BOOL)includeLog
           moduleInt:(NSInteger)moduleInt
           issueType:(NSInteger)issueType
         audioLogDir:(NSString *)audioLogDir
                date:(NSDate *)date
    attachmentsPaths:(NSArray <NSString *>*)attachmentsPaths;

+ (BOOL)submitJMFReport;

+ (BOOL)reportWithMemlogEnabled;

+ (BOOL)isPhoneFeatureType:(long)selectTag;

+ (NSInteger)featureMeetingTag;

+ (NSInteger)featurePhoneTag;

+ (NSInteger)featureJoinMeetingFailureTag;

+ (NSInteger)featureDocTag;

+ (NSInteger)feedbackDocsOutMeeting;

+ (NSInteger)feedbackDocsInMeeting;

+ (NSInteger)featureNotesTag;

+ (NSInteger)featureWhiteTag;

+ (NSInteger)isWBOutOrInMeeting:(BOOL)isFromOutMeeting;

+ (NSInteger)isNotesOutOrInMeeting:(BOOL)isFromOutMeeting;

// Clips
+ (NSInteger)featureClipsTag;
+ (NSInteger)feedbackClipsRecorder;
+ (NSInteger)feedbackClipsZoomClient;
+ (NSInteger)feedbackClipsWebBrowser;

+ (NSInteger)currentFeatureTab;

+ (BOOL)disableReportProblemGPO;

+ (BOOL)inCall;

+ (NSString *)zmIntToString:(NSInteger)num;

+ (BOOL)isInMeeting;

+ (void)captureScreenshotButtonClick:(id <ZMScreenshotCallback>)callback;

@end

NS_ASSUME_NONNULL_END

