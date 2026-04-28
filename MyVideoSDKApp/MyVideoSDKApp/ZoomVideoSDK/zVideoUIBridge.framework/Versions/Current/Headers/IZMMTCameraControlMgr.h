//
//  IZMMTCameraControlMgr.h
//  VideoUIBridge
//
//  Camera Control Manager Protocol
//

#ifndef IZMMTCameraControlMgr_h
#define IZMMTCameraControlMgr_h

#import <zVideoUIBridge/ZMMTConstants.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTCameraControlMgr <ZMRoutableObject>

- (void)updateRemoteCameraController:(NSView*)parentView userID:(int)userID;
- (void)hideController;
- (void)superViewDidHidden;
- (BOOL)isMouseInControllerView;
- (BOOL)receiveEvent:(NSEvent*)inEvent;

- (void)onControllableCameraAdded:(ZMUser *)user;
- (void)onControllableCameraRemoved:(ZMUser *)user;
- (void)onCameraControlGroupAdded:(ZMUser *)user error:(FECCGroupAddmemberError)error;
- (void)onCameraControlGroupRemoved:(ZMUser *)user success:(BOOL)success;
- (void)onRequestSwitchCamera:(ZMUserID)userID;
- (void)onActionApproveControl:(ZMUserID)userID;
- (void)onActionDeclineControl:(ZMUserID)userID;
- (void)onCameraControllerDidChanged:(ZMUser *)zmUser;
- (void)onUserStartedCameraControl:(ZMUserID)userID;
- (void)onUserRequestedCameraControl:(ZMUserID)userID;
- (void)onUserDeclinedCameraControl:(ZMUserID)userID reason:(int)reason;
- (void)onUserApprovedCameraControl:(ZMUserID)userID;
- (void)onUserGaveupCameraControl:(ZMUserID)userID;

- (void)showAddToCameraControlGroupAlert:(ZMUser *)user;
- (void)addToCameraControlGroup:(ZMUser *)user;
- (void)removeFromCameraControlGroup:(ZMUser *)user;
- (void)requestControlCameraOfUser:(ZMUserID)userID;
- (void)startControlCameraOfUser:(ZMUserID)userID;
- (void)giveUpControlCameraOfUser:(ZMUserID)userID;
- (void)onRespondSwitchCamera;

- (BOOL)isControllingCamera;
- (BOOL)isCameraInControlWithUserId:(ZMUserID)inUserId;
- (BOOL)canShowStartCameraControlMenu:(ZMUser *)user;
- (BOOL)canShowAddToCameraControlGroupMenu:(ZMUser *)user;
- (BOOL)canShowRemoveFromCameraControlGroupMenu:(ZMUser *)user;
- (BOOL)canRequestRemoteCameraControl:(ZMUserID)userID;
- (BOOL)canControlCameraOfID:(ZMUserID)userID;
- (BOOL)canGiveUpRemoteCameraControl:(ZMUserID)userID;

@end

@protocol IZMMTCameraControlProtocol <NSObject>

@optional
- (void)onCameraControlStatusChanged;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTCameraControlMgr_h */
