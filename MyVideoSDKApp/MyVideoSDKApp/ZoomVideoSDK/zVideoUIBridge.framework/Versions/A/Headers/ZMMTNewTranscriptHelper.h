//
//  ZMMTNewTranscriptHelper.h
//  VideoUIBridge
//
//  Created by Karen Cao on 1/21/26.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

ZMConfSession *ZMMTTranscriptGetCurrentConfSession(void);

@interface ZMMTNewTranscriptHelper : ZMBaseHelper

- (nullable NSString *)getCurrentRecPath;
- (BOOL)isNewTranscriptEnabled;
- (BOOL)isMeetingTranscriptionStarted;
- (BOOL)isViewTranscriptAllowed;
- (BOOL)isSaveTranscriptionAllowed;

@end

NS_ASSUME_NONNULL_END
