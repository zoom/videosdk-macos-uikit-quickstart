//
//  ZMScreenShotItem.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ScreenShotItemState) {
    ZM_STATE_UNKNOW = 0,
    ZM_STATE_FAIL,
    ZM_STATE_FINISH,
};

@interface ZMScreenShotItem : NSObject
{
    NSString*   _itemId;
    NSImage*    _image;
    id          _video;
    NSUInteger  _itemState;
}
@property(nonatomic, copy) NSString* itemId;
@property(nonatomic, retain) NSImage*   image;
@property(nonatomic, assign) NSUInteger  itemState;
@end

NS_ASSUME_NONNULL_END
