//
//  ZMMTTranscriptMessage.h
//  SaasBeeConfUIModule
//
//  Created by martin.yu on 8/30/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTSelectableTextItemProtocol.h>
#import <zVideoUIBridge/ZMMTHeightCalculableProtocol.h>
#import <zVideoUIBridge/ZMMTTranscriptUser.h>

NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN const CGFloat ZMMTTranscriptTextHorizontalMarginBase;
APPKIT_EXTERN const CGFloat ZMMTTranscriptTimeTextHeightBase;
APPKIT_EXTERN const CGFloat ZMMTTranscriptVerticalSpacingBase;

typedef NS_ENUM(NSInteger, ZMMTTranscriptStatusType) {
    ZMMTTranscriptStatusTypeStarted,
    ZMMTTranscriptStatusTypeStopped,
};

@interface ZMMTTranscriptRawMessage : NSObject
@property (nonatomic, strong) ZMConfSession *confSession;
@property (nonatomic, strong, nullable) NSString *messageId;
@property (nonatomic, strong, nullable) NSString *text;
@property (nonatomic, assign) NSWritingDirection writingDirection;
@property (nonatomic, strong, nullable) NSString *timeString;
@property (nonatomic, assign) time_t timeInSec;

@property (nonatomic, strong, nullable) ZMMTTranscriptUser *user;

// For Smart Speaker Tag
@property (nonatomic, assign) ZMUserID zrSpeakerID;
@end

typedef NS_ENUM(NSInteger, ZMMTTranscriptMessageType) {
    ZMMTTranscriptMessageTypeText,
    ZMMTTranscriptMessageTypeUserInfo,
    ZMMTTranscriptMessageTypeTranscriptionStatus,
};

@interface ZMMTTranscriptMessage : NSObject <ZMMTSelectableTextItemProtocol, ZMMTHeightCalculableProtocol>
// May be nil.
@property (nonatomic, strong, nullable) ZMMTTranscriptUser *user;
@property (nonatomic, strong, nullable) ZMConfSession *confSession;
@property (nonatomic, assign, readonly) ZMMTTranscriptMessageType type;

@property (assign) CGFloat height;
@property (assign) BOOL heightIsValid;
@end

@interface ZMMTTranscriptTextMessage : ZMMTTranscriptMessage
@property (nonatomic, strong) NSString *messageId;

@property (atomic, strong) NSAttributedString *attributedContent;
@property (nonatomic, assign) NSRange contentSelectedRange;

@property (nonatomic, strong) NSAttributedString *attributedTimeString;
@property (nonatomic, assign) NSRange timeSelectedRange;
@property (nonatomic, assign) time_t timeInSec;
@property (nonatomic, assign, readonly) BOOL shouldShowTimeString; 
- (BOOL)updateShouldShowTimeString:(BOOL)shouldShowTimeString;

// For search
@property (nonatomic, assign) BOOL isInSearchMode;
@property (nonatomic, assign) BOOL contentIsValidForSearch;
@property (nonatomic, strong, nullable) NSArray<NSValue *> *timeSearchRanges;
@property (nonatomic, strong, nullable) NSArray<NSValue *> *contentSearchRanges;
// Index of the currently highlighted range within contentSearchRanges (NSNotFound = none).
@property (nonatomic, assign) NSInteger currentHighlightRangeIndexInContent;
@end

@interface ZMMTTranscriptUserInfoMessage : ZMMTTranscriptMessage
@property (nonatomic, strong) NSAttributedString *attributedTimeString;

@property (nonatomic, strong) NSString *messageId;
@property (nonatomic, strong, nullable) NSArray<NSValue *> *timeSearchRanges;
// Index of the currently highlighted range within timeSearchRanges (NSNotFound = none).
@property (nonatomic, assign) NSInteger currentHighlightRangeIndexInTime;
@end

@interface ZMMTTranscriptStatusMessage : ZMMTTranscriptMessage
@property (nonatomic, assign) ZMMTTranscriptStatusType status;
@property (nonatomic, strong) NSAttributedString *attributedContent;
@property (nonatomic, strong) NSAttributedString *attributedTimeString;
@property (nonatomic, assign) time_t timeInSec;
@end

NS_ASSUME_NONNULL_END
