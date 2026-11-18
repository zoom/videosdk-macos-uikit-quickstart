//
//  ZMZappVirtualEffectsProtocol.h
//  ZoomUnit
//
//  Shared Zoom Apps virtual-effects capability implemented by both PT and
//  meeting hosts.
//

#ifndef ZMZappVirtualEffectsProtocol_h
#define ZMZappVirtualEffectsProtocol_h

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZPZAppAdapter.h>

@protocol ZMZappVirtualEffectsProtocol <NSObject>
- (void)downloadAomhostCompletion:(void (^)(BOOL))completion;
- (BOOL)setVideoFilter:(NSString *)filterName
             imagePath:(NSString *)imagePath
             thumbPath:(NSString *)thumbPath
          filterOption:(NSInteger)option;
- (BOOL)couldSelectVideoFilter;

- (void)setZappVBWithPath:(NSString *)filepath
                imageName:(NSString *)VBimageName
                  isVBGen:(BOOL)isVBGen
                  eventId:(NSString *)reqId;
- (void)selectVBItemById:(NSString *)vbId
                 eventId:(NSString *)reqId;
- (void)selectLastVBItem;
- (void)checkAomHostUpdateCompletion:(void (^)(BOOL, NSUInteger))completion;
- (void)OnRefreshSettingWithType:(ZAppRefreshSettingType)type;
- (void)OnHDSettingWillChange;
@end

#endif /* ZMZappVirtualEffectsProtocol_h */
