//
//  ZMInterpretLanguage.h
//  zVideoUI
//
//  Created by Geno on 2019/6/28.
//  Copyright © 2019 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <zVideoApp/Confdef.h>
using namespace NS_ZOOM_DATA;

NS_ASSUME_NONNULL_BEGIN

@interface ZMInterpretLanguage : NSObject <NSCopying>

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *iconContent;
@property (nonatomic, copy) NSString *languageID;
@property (nonatomic, retain, readonly) NSImage *icon;
@property (nonatomic, assign) INTERPRETE_LANGUAGE language;
@property (nonatomic, assign, readonly) BOOL isCustomLanguage;

- (nullable NSImage *)toolbarLanguageIconWithColor:(NSColor *)color;

@end

NS_ASSUME_NONNULL_END
