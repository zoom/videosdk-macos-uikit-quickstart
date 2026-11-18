//
//  IZMMTMyNotesMgr.h
//  VideoUIBridge
//
//  Created for My Notes Manager Protocol
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTMyNotesEntry<NSObject>
- (NSString*)triggerAction;
- (NSString*)buttonText4Off;
- (NSString*)buttonText4On;
@end

/**
 * @router ZMMTShared
 */
@protocol IZMMTMyNotesMgr <ZMRoutableObject>
@property(assign) BOOL isMynotesEnable;

- (void)startWithPayload:(NSDictionary *)payload;
- (BOOL)setAutoStartMyNotesEnabled:(BOOL)enabled;

#pragma mark - A/B Test
- (id<ZMMTMyNotesEntry>)mynotesEntry;
- (void)AddFirstTimeShowEntryEvent;
- (void)AddClickMynotesEntryEvent;
@end

NS_ASSUME_NONNULL_END

