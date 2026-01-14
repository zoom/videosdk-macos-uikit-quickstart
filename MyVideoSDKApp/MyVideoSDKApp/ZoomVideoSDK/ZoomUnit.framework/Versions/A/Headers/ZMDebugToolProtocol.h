//
//  ZMDebugToolProtocol.h
//  ZoomUnit
//
//  Created by fistice on 10/13/25.
//

@protocol ZMDebugToolProtocol <NSObject>
#ifndef __ZOOM_NO_CLIENT_LOG
@optional
- (void)getDebugTargetNames:(NSMutableArray*)array;
- (void)openDebugTool:(NSString *)targetName object:(NSDictionary *)userInfo;
#endif /* ZMDebugToolProtocol_h */
@end

@protocol IZMDebugToolMgr <NSObject>
@end
/**
 Q: How to add a tool in client for debug?
 A: Register for listening when launchModule, and Implement the `ZMDebugToolProtocol protocol` method
 
 ```
 - (void)launchModule {
 ...
 #if !defined(__ZOOM_NO_CLIENT_LOG)
     ZMEventRegister(self, ZMDebugToolProtocol);
 #endif
 ...
 }
 
 #if !defined(__ZOOM_NO_CLIENT_LOG)
 #pragma mark ZMDebugToolProtocol
 - (void)openDebugTool:(NSString *)targetName object:(NSDictionary *)userInfo
 {
     if([targetName isEqualToString:@"showPTTestAlertWindow"]) {
         [self showTestWindow:nil];
     }
 }
 - (void)getDebugTargetNames:(NSMutableArray*)array;
 {
     [array addObject:@"showPTTestAlertWindow"];
 }
 #endif
 ```
 Q: How to use a debug tool?
 A: There are two way to use the tool.
    1. open in Menu 'Help->Debug->Debugging->Show Debug Tools->Your Tool;
    2. send a NSDistributedNotification to process; You can send yourself with following format, or ask Script for fistice.wang@zoom.us.
        notificationName: "ZoomDebugToolNotification",
        "targetPID": process id,
        "targetName: debugTool targetName
    
 */
