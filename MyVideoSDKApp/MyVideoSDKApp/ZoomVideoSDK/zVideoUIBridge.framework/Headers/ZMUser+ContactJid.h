//
//  ZMUser+ContactJid.h
//  VideoUIBridge
//
//  Created by Cursor AI on 2026/1/21.
//

#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMUser (ContactJid)

/// Contact JID for this user in meeting context.
/// This is used by Billing (billable hours) to check contact status.
@property (nullable, readonly, copy) NSString *contactJid;

@end

NS_ASSUME_NONNULL_END

