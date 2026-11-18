//
//  ZMMTAudioProtocol.h
//  ZoomUnit
//
//  Created by fistice on 8/30/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#ifndef ZMMTAudioProtocol_h
#define ZMMTAudioProtocol_h

@protocol ZMMTAudioProtocol <NSObject>

- (BOOL)isJoinAudio;
- (BOOL)isJoinAudioByVoip;
- (BOOL)isJoinAudioByTelephone;
- (BOOL)isSelfMuted;
- (NSInteger)microPhoneLevel;
- (void)toggleSelfVoipAudio;
- (void)audioStateChangeByHID:(BOOL)muted;
@end

#endif
