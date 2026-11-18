//
//  ZPAlertInfo.h
//  ZoomUnit
//
//  Created by fistice on 7/29/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <ZoomUnit/ZMAlertInfo.h>
#ifdef __cplusplus
struct CmmCoachmarkInfo;
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ZPAlertInfo : ZMAlertInfo
#ifdef __cplusplus
+ (instancetype)infoWithCInfo:(CmmCoachmarkInfo)info;
+ (instancetype)infoWithZPNSToastInfo:(CmmZpnsToast)info;
+ (instancetype)infoWithZPNSBubbleInfo:(CmmZpnsCoachmark)obj;
#endif

- (BOOL)isECMSCoachmark;

@property (nonatomic,copy) NSString *identifier;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,copy) NSString *information;
@property (nonatomic,strong) ZMAlertButtonInfo *primaryBtn;
@property (nonatomic,strong) ZMAlertButtonInfo *secondaryBtn;
@property (nonatomic,strong) ZMAlertButtonInfo *leftLinkBtn;
@property (nonatomic,copy) NSString *primaryButtonLink;
@property (nonatomic,copy) NSString *secondaryButtonLink;
@property (nonatomic,copy) NSString *popoverPlacement;
@property (nonatomic,copy) NSString *primaryButtonID;
@property (nonatomic,copy) NSString *secondaryButtonID;
@property (nonatomic,copy) NSString *linkButtonID;
@property (nonatomic,assign) BOOL ecmsImpressionReported;
@property (nonatomic,assign) BOOL ecmsTerminalActionReported;
@property (nonatomic,assign) NSInteger dismissTimes;
@property (nonatomic,assign) NSInteger dismissThreshold;
@property (nonatomic,assign) BOOL dismissEligible;

@property (nonatomic,assign) BOOL isShowClose;
@property (nonatomic,assign) ZMToastType iconType;
@property (nonatomic,assign) ZMAlertType displayType;

@property (nonatomic,assign) BOOL needRequestShownCount;
@property (nonatomic,copy) NSString *displayEventType;
@property (nonatomic,copy) NSString *dismissEventType;

@property (nonatomic,assign) BOOL isCoachmark;
@property (nonatomic,assign) BOOL isEcms;
@property (nonatomic,copy) NSString *coachmarkID;
@property (nonatomic,assign) NSUInteger coachmarkPriority;

@property (nonatomic,copy) NSString *entry;
@property (nonatomic,assign) BOOL showForNewUser;

@property (nonatomic,weak) id alertUI;
@property (nonatomic,assign) int64_t dismissTimer;
@end

NS_ASSUME_NONNULL_END
