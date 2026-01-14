//
//  ZMAppearanceHelper.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/25.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMAppearanceHelper : NSObject

+ (NSImage *)getImageByName:(NSString*)name;
+ (NSImage *)getImageLightName:(NSString *)lightName darkName:(NSString *)darkName;
@end
