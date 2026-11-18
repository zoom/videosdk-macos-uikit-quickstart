//
//  ZMZappStatusProtocol.h
//  ZoomUnit
//
//  Observer contracts for Zoom Apps status changes.
//

#ifndef ZMZappStatusProtocol_h
#define ZMZappStatusProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMZappStatusProtocol <NSObject>
@optional
- (void)onZappEnableStatusChanged:(BOOL)enable;
@end

@protocol ZMZappConfStatusProtocol <NSObject>
- (void)onZappModuleLoadedStatusChanged;
@end

#endif /* ZMZappStatusProtocol_h */
