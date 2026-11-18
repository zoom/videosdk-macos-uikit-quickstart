//
//  IZMMTVcardProtocol.h
//  VideoUI
//
//  Created by davies zhao on 2023/12/13.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <commonDef/CmmCommonStruct.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTVcardProtocol <ZMRoutableObject>

- (CmmVCardData)getVCardDataWithUserId:(NSString *)userId;

- (NSString *)getVCardAvatarUrlWithUserId:(NSString *)userId;

- (NSString *)getVCardProuounsWithUserId:(NSString *)userId;

- (NSString *)getProfileCardDomain;

- (NSString *)getMeetingName;

- (void)closeVCard;
@end

NS_ASSUME_NONNULL_END
