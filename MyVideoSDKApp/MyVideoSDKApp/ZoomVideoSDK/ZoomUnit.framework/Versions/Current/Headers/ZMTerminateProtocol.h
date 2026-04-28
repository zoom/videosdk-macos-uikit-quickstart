//
//  ZMTerminateProtocol.h
//  ZoomUnit
//
//  Created by fistice on 8/15/25.
//

#ifndef ZMTerminateProtocol_h
#define ZMTerminateProtocol_h


@protocol ZMTerminateProtocol <NSObject>

//- (BOOL)allowsAppTermination;
- (BOOL)preventsAppTermination;
- (BOOL)willPreventsAppTermination;
@end

#endif /* ZMTerminateProtocol_h */
