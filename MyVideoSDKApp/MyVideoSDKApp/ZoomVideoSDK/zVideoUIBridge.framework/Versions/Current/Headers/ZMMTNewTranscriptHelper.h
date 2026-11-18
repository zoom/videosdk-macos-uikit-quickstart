//
//  ZMMTNewTranscriptHelper.h
//  VideoUIBridge
//
//  Created by Karen Cao on 1/21/26.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

#ifdef __cplusplus
class ICmmUser;
struct CmmSpeakerDiarInfo;
#endif

NS_ASSUME_NONNULL_BEGIN

ZMConfSession *ZMMTTranscriptGetCurrentConfSession(void);

@interface ZMMTNewTranscriptHelper : ZMBaseHelper

- (nullable NSString *)getCurrentRecPath;
- (BOOL)isNewTranscriptEnabled;
- (BOOL)isMeetingTranscriptionStarted;
- (BOOL)isViewTranscriptAllowed;
- (BOOL)isSaveTranscriptionAllowed;
- (ZMUserID)getZRSpeakerIDWithDisplayId:(NSString *)displayId;
- (BOOL)shouldShowZRSpeakerAvatarWithDisplayId:(NSString *)displayId;
- (nullable NSString *)getZRSpeakerAvataPathWithDisplayId:(NSString *)displayId;
- (nullable NSString *)getZRSpeakerTagNameWithDisplayId:(NSString *)displayId;
- (nullable NSString *)getZRMsgScreenNameWithDisplayId:(NSString *)displayId;
- (BOOL)isSameZRSmartSpeakerUserWithDisplayId1:(NSString *)displayId1 displayId2:(NSString *)displayId2;
#ifdef __cplusplus
- (CmmSpeakerDiarInfo)getZRSpeakerDiarInfoWithDisplayId:(NSString *)displayId;
- (nullable ICmmUser *)getCmmUserByDisplayId:(NSString *)displayId;
#endif

@end

NS_ASSUME_NONNULL_END
