//
//  IZMSelfViewMiniViewMgr.h
//  VideoUIBridge
//
//  Owns the floating self-view PiP, which lives as a plain subview of the
//  meeting window's video pane rather than a window of its own -- that is what
//  keeps it confined to the meeting window.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUIConstants.h> // ZMVideoUpdateStrategy

@class ZMUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMMTShared
 */
@protocol IZMSelfViewMiniViewMgr <ZMRoutableObject>

@property (nonatomic, readonly) BOOL isVisible;

// Creates the mini view if needed, adds it front-most in `hostView` and docks it.
- (void)showInHostView:(nullable NSView *)hostView;
- (void)hide;

- (void)bindToSelfUser:(nullable ZMUser *)selfUser;

// Forwards a ZMMTForceUpdateProtocol strategy into the embedded cell, which
// isn't wall-registered and so never receives the broadcast itself.
- (void)forceUpdateVideoView:(ZMVideoUpdateStrategy)strategy;



// Unlike the forwarders above, NOT gated on -isVisible: active-speaker changes
// are edge-driven, so dropping one while hidden loses it until the next time
// someone starts or stops talking.
- (void)setActiveSpeaker:(BOOL)isActiveSpeaker;

- (void)redockToCurrentCorner;

// Tears the embedded cell's render down on meeting teardown, alongside every
// other renderer (see ZPConfUIMgr's -destroyAllRenders).
- (void)destroyAllRenders;

@end

NS_ASSUME_NONNULL_END
