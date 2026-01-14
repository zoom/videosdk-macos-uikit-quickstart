//
//  ZMSipEntityCallerID.h
//  zSIPCallUI
//
//  Created by ares.lin on 2/7/25.
//  Copyright © 2025 Evelyn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMSipEntityCallerIDType) {
    ZMSipEntityCallerIDTypeUser = 0,
    ZMSipEntityCallerIDTypeCQ,
    ZMSipEntityCallerIDTypeSLG,
    ZMSipEntityCallerIDTypeSLA,
};

@interface ZMSipEntityCallerID : NSObject

@property (nonatomic, copy) NSString *ownerName;
@property (nonatomic, copy, nullable) NSString *extensionId;
@property (nonatomic, copy, nullable) NSString *extensionNumber;
@property (nonatomic, strong, nullable) NSArray<NSString *> *didNumbers;
@property (nonatomic, assign) ZMSipEntityCallerIDType type;
@property (nonatomic, assign) BOOL callback;

- (instancetype)initWithOwnerName:(NSString *)ownerName
                      extensionId:(nullable NSString *)extensionId
                  extensionNumber:(nullable NSString *)extensionNumber
                       didNumbers:(nullable NSArray<NSString *> *)didNumbers;
- (nullable NSString *)firstNumber;
- (BOOL)containExtensionNumber:(NSString *)extensionNumber orFormattedDidNumber:(NSString *)formattedDidNumber;

@end

NS_ASSUME_NONNULL_END
