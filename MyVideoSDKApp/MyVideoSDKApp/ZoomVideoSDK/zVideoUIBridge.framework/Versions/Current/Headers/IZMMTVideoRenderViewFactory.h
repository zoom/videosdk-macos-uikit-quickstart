//
//  IZMMTVideoRenderViewFactory.h
//  zVideoUIBridge
//
//  Created by Brace Liu on 12/11/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//
//  Factory protocol for creating video render view instances
//  Registered in VideoUI module and used by StudioUI through ZMRouterCenter
//  Lifecycle follows ZPConfUIMgr (lazy-loaded singleton)
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/IZMMTVideoRenderView.h>

NS_ASSUME_NONNULL_BEGIN

// Note: We use NSInteger for render type parameters to avoid C++ header dependencies
// RENDER_CONTAINER_TYPE and ZMMTVideoRenderSceneType are defined in C++ headers
// The protocol uses NSInteger to maintain compatibility while avoiding C++ imports
// Actual enum values are passed through at runtime without type checking at protocol level

/**
 Factory protocol for creating video render view instances
 
 Lifecycle: Lazy-loaded singleton via ZMRouterCenter, follows ZPConfUIMgr lifecycle.
 Instance is created on first access and removed when ConfUIMgr cleans up.
 
 Usage in StudioUI:
 ```objc
 // 1. Get factory from router (lazy-loaded singleton)
 id<IZMMTVideoRenderViewFactory> factory = ZMMTSharedFor(IZMMTVideoRenderViewFactory);
 
 // 2. Create render view
 NSView<IZMMTVideoRenderView> *renderView = 
     [factory createVideoRenderViewWithFrame:frame renderType:RENDER_ACTIVE];
 
 // 3. Configure and use
 renderView.delegate = self;
 [renderView updateWithUser:user];
 ```
 
 Registration in VideoUI (ZPConfUIMgr):
 ```objc
 [ZMMTRouterCenter registerProtocol:@protocol(IZMMTVideoRenderViewFactory)
                           forClass:[ZMMTVideoRenderViewFactory class]];
 ```
 */
@protocol IZMMTVideoRenderViewFactory <NSObject>

@required

/**
 Create a video render view instance with default scene type
 
 @param frame Initial frame for the render view
 @param renderType Render container type (RENDER_ATTENDEE, RENDER_ACTIVE, etc.)
                   Pass as NSInteger to avoid C++ header dependencies
 @return Video render view instance conforming to IZMMTVideoRenderView protocol
 
 @note The returned view is also a subclass of ZMMTVideoRender
 */
- (NSView<IZMMTVideoRenderView> *)createVideoRenderViewWithFrame:(NSRect)frame 
                                                       renderType:(NSInteger)renderType;

/**
 Create a video render view with specific scene type
 
 @param frame Initial frame for the render view
 @param renderType Render container type (pass as NSInteger)
 @param sceneType Scene type (pass as NSInteger)
 @return Video render view instance
 
 Scene types:
 - ZMMTVideoRenderSceneTypeBasic (0): Basic rendering
 - ZMMTVideoRenderSceneTypeNormal (1): Normal meeting view
 - ZMMTVideoRenderSceneTypeActive (2): Active speaker view
 - ZMMTVideoRenderSceneTypeImmersive (3): Immersive view (Studio)
 - ZMMTVideoRenderSceneTypeZappPlugin (4): Zapp plugin view
 */
- (NSView<IZMMTVideoRenderView> *)createVideoRenderViewWithFrame:(NSRect)frame 
                                                       renderType:(NSInteger)renderType
                                                        sceneType:(NSInteger)sceneType;

@end

NS_ASSUME_NONNULL_END

