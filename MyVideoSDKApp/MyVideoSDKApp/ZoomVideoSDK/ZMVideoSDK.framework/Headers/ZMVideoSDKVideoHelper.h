/**
 * @file ZMVideoSDKVideoHelper.h
 * @brief Defines video control, camera device management, virtual background, and video preference interfaces in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
#import "ZMVideoSDKUserHelper.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKVirtualBackgroundItem
 * @brief Virtual background Item interface.
 */
@interface ZMVideoSDKVirtualBackgroundItem : NSObject

/**
 * @brief Gets the current item image file path.
 */
@property (nonatomic, copy, readonly) NSString *imageFilePath;

/**
 * @brief Gets the current item image name.
 */
@property (nonatomic, copy, readonly) NSString *imageName;

/**
 * @brief Gets the current item background type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKVirtualBackgroundDataType type;

/**
 * @brief Determines whether the virtual background supports deletion.
 */
@property (nonatomic, assign, readonly) BOOL canVirtualBackgroundBeDeleted;

@end



/**
 * @class ZMVideoSDKCameraDevice
 * @brief Represents a camera device and its state.
 */
@interface ZMVideoSDKCameraDevice : NSObject
/**
 * @brief Gets the camera's device Id.
 */
@property (nonatomic, copy, readonly) NSString* deviceID;
    
/**
 * @brief Gets the camera's device name.
 */
@property (nonatomic, copy, readonly) NSString* deviceName;
    
/**
 * @brief Determines if the device is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedDevice;

/**
 * @brief Determines whether the camera is selected as multiple stream video.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedAsMultiCamera;
    
/**
 * @brief Determines whether the camera is running as multiple stream video.
 */
@property (nonatomic, assign, readonly) BOOL isRunningAsMultiCamera;
@end


/**
 * @class ZMVideoSDKPreferenceSetting
 * @brief Video preference interface. When setting custom modes, the maximum and minimum frame rates are provided by the developer. If the current bandwidth cannot maintain the minimum frame rate, the video system drops to the next lower resolution. The default maximum and minimum frame rates for other modes are 0.
 */
@interface ZMVideoSDKPreferenceSetting : NSObject
/**
 * @brief Preferred video mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKVideoPreferenceMode mode;
    
/**
 * @brief Minimum frame rate, default is 0.
 * @note The value of minimumFrameRate should be less than maximumFrameRate, the value of minimumFrameRate range from 0 to 30. If the frame rate out of range, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int minimumFrameRate;
    
/**
 * @brief Maximum frame rate, default is 0.
 * @note The value of maximumFrameRate should be less and equal than 30, the value of maximumFrameRate range from 0 to 30. If the frame rate out of range, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int maximumFrameRate;
@end


/**
 * @class ZMVideoSDKVideoHelper
 * @brief An interface to control video and manage cameras during a video session.
 */
@interface ZMVideoSDKVideoHelper : NSObject
    
/**
 * @brief Starts sending local video data from the camera.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startVideo;
    
/**
 * @brief Stops sending local video data from the camera.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopVideo;
    
/**
 * @brief Rotates the video when the device is rotated.
 * @param rotation It is emum.
 * @return YES if the function is success. Otherwise, NO.
 */
- (BOOL)rotateMyVideo:(ZMVideoRotation)rotation;
    
/**
 * @brief Switches to the next available camera.
 * @return YES if the function is success. Otherwise, NO.
 */
- (BOOL)switchCamera;
    
/**
 * @brief Switches to the camera passed in as cameraDevice.
 * @param cameraDeviceID The ID of camera.
 * @return YES if the function is success. Otherwise, NO.
 */
- (BOOL)selectCamera:(NSString*)cameraDeviceID;
    
/**
 * @brief Returns number of cameras available to share the video.
 * @return The count of cameras.
 */
- (unsigned int)getNumberOfCameras;
    
/**
 * @brief Returns a collection of camera devices available to share the video as an object of ZMVideoSDKCameraDevice.
 * @return If the function succeeds, it returns camera devices list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKCameraDevice *>* _Nullable)getCameraList;

/**
 * @brief Checks whether the current user has permission to control the camera.
 * @param canControl The output parameter. YES indicates can control local camera, NO otherwise.
 * @param deviceID The camera device ID to check. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)canControlCamera:(BOOL *)canControl deviceID:(nullable NSString*)deviceID;

/**
 * @brief Pan the camera to the left.
 * @param range Rotation range, 10 <= range <= 100.
 * @param deviceID The camera device ID to rotate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnCameraLeft:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Pan the camera to the right.
 * @param range Rotation range, 10 <= range <= 100.
 * @param deviceID The camera device ID to rotate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnCameraRight:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Tilt the camera up.
 * @param range Rotation range, 10 <= range <= 100.
 * @param deviceID The camera device ID to rotate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnCameraUp:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Tilt the camera down.
 * @param range Rotation range, 10 <= range <= 100.
 * @param deviceID The camera device ID to rotate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)turnCameraDown:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Zoom the camera in.
 * @param range Zoom range, 10 <= range <= 100.
 * @param deviceID The camera device ID to operate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)zoomCameraIn:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Zoom the camera out.
 * @param range Zoom range, 10 <= range <= 100.
 * @param deviceID The camera device ID to operate. The default is the main camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)zoomCameraOut:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 * @brief Adjust user's video solution and frame-rate.
 * @param preferenceSetting An instance of ZMVideoSDKPreferenceSetting.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setVideoQualityPreference:(ZMVideoSDKPreferenceSetting*)preferenceSetting;

/**
 * @brief Enables multiple stream video if you have multiple cameras, and other participants can see multiple videos of you.
 * @param cameraDeviceID The camera ID for the camera to enable.
 * @param customDeviceName The camera's custom device name. If this parameter is not passed, a default name will be generated.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)enableMultiStreamVideo:(NSString *)cameraDeviceID customDeviceName:(nullable NSString *)customDeviceName;

/**
 * @brief Disables multiple stream video.
 * @param cameraDeviceID The camera ID which you want to disable.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)disableMultiStreamVideo:(NSString *)cameraDeviceID;

/**
 * @brief Turn off multiple stream video.
 * @param cameraDeviceID The camera ID which is running as multiple camera.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)muteMultiStreamVideo:(NSString *)cameraDeviceID;

/**
 * @brief Turn on multiple stream video.
 * @param cameraDeviceID The camera ID which is running as multiple camera.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)unmuteMultiStreamVideo:(NSString *)cameraDeviceID;
/**
 * @brief Gets the device ID associated with my multi-camera pipe.
 * @param pipe My multi-camera pipe.
 * @return If the function succeeds, it returns the video device ID. Otherwise, this function fails and returns nil.
 */
- (NSString * _Nullable)getDeviceIDByMyPipe:(ZMVideoSDKRawDataPipe *)pipe;
/**
 * @brief Subscribes preview video raw data with a callback.
 * @param listener The callback sink object.
 * @param cameraDeviceID The camera ID.
 * @return If the function succeeds, it returns @c ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 * @deprecated Use \link ZMVideoSDKVideoHelper::startVideoPreview:deviceID: resolution:\endlink instead.
 */
- (ZMVideoSDKErrors)startVideoPreview:(id<ZMVideoSDKRawDataPipeDelegate>)listener deviceID:(NSString* _Nullable)cameraDeviceID DEPRECATED_MSG_ATTRIBUTE("Use -startVideoPreview:deviceID:resolution: instead");

/**
 * @brief Subscribes to preview video raw data with a callback.
 * @param listener The callback object.
 * @param cameraDeviceID Camera device ID.
 * @param resolution Specify the resolution for opening the camera.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startVideoPreview:(id<ZMVideoSDKRawDataPipeDelegate>)listener deviceID:(NSString* _Nullable)cameraDeviceID resolution:(ZMVideoSDKResolution)resolution;
/**
 * @brief UnSubscribe preview video raw data with the subscribed callback.
 * @param listener The callback sink object.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopVideoPreview:(id<ZMVideoSDKRawDataPipeDelegate>)listener;

/**
 * @brief Starts the preview video with a view.
 * @param view The view to preview video.
 * @param cameraDeviceID The camera ID.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)startVideoCanvasPreview:(NSView*)view deviceID:(NSString* _Nullable)cameraDeviceID;

/**
 * @brief Stops the preview video.
 * @param view The view to preview video.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)stopVideoCanvasPreview:(NSView*)view;

/**
 * @brief Adds virtual background object.
 * @param imagePath The path of image.
 * @param imageItem An object of ZMVideoSDKVirtualBackgroundItem. Once the function is called successfully, this parameter will store the pointer to the ZMVideoSDKVirtualBackgroundItem*.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)addVirtualBackgroundItem:(NSString *)imagePath imageItem:(ZMVideoSDKVirtualBackgroundItem * _Nullable * _Nonnull)imageItem;

/**
 * @brief Removes virtual background object.
 * @param imageItem The ZMVideoSDKVirtualBackgroundItem object to be removed.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)removeVirtualBackgroundItem:(ZMVideoSDKVirtualBackgroundItem *)imageItem;

/**
 * @brief Returns a collection of virtual background item as an object of ZMVideoSDKVirtualBackgroundItem.
 * @return If the function succeeds, it returns a list of virtual background items. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKVirtualBackgroundItem* >* _Nullable)getVirtualBackgroundItemList;

/**
 * @brief Select virtual background item.
 * @param imageItem The ZMVideoSDKVirtualBackgroundItem object to select.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)setVirtualBackgroundItem:(ZMVideoSDKVirtualBackgroundItem*)imageItem;

/**
 * @brief Gets a selected virtual background item.
 * @return If the function succeeds, it returns the object of ZMVideoSDKVirtualBackgroundItem. Otherwise, this function fails and returns nil.
 */
- (ZMVideoSDKVirtualBackgroundItem* _Nullable)getSelectedVirtualBackgroundItem;

/**
 * @brief Determines whether current aspect ratio is the original aspect ratio of video.
 * @return YES if is original aspect ratio. Otherwise, NO.
 */
- (BOOL)isOriginalAspectRatioEnabled;

/**
 * @brief Sets the aspect ratio of the video sent out.
 * @param bEnabled NO indicates the aspect ratio is 16:9, YES indicates that using the original aspect ratio of video.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 * @note If session is using video source and data_mode is not VideoSourceDataMode_None, default always use original aspect ration of video.
 */
- (BOOL)enableOriginalAspectRatio:(BOOL)bEnabled;


/**
 * @brief Mirrors the current user's video. Valid only for canvas.
 * @param bEnabled YES to enable mirror my video, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)mirrorMyVideo:(BOOL)bEnabled;

/**
 * @brief Determines whether mirror my video is enabled.
 * @return YES if mirror my video is enabled. Otherwise, NO.
 */
- (BOOL)isMyVideoMirrored;

/**
 * @brief Determines if the current device supports alpha channel mode.
 * @return YES if that the current device supports alpha channel mode. Otherwise, NO.
 */
- (BOOL)isDeviceSupportAlphaChannelMode;

/**
 * @brief Determines if alpha channel mode is available.
 * @return YES if it is available. Otherwise, NO.
 */
- (BOOL)canEnableAlphaChannelMode;

/**
 * @brief Enables or disables alpha channel mode.
 * @param enabled YES indicates to enable alpha channel mode, NO to disable.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)enableAlphaChannelMode:(BOOL)enabled;

/**
 * @brief Determines if alpha channel mode is enabled.
 * @return YES if is in alpha channel mode. Otherwise, NO.
 */
- (BOOL)isAlphaChannelModeEnabled;

/**
 * @brief Spotlights user's video.
 * @param user Which you  want to spotlight video.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)spotLightVideo:(ZMVideoSDKUser*)user;

/**
 * @brief UnSpotlights user's video.
 * @param user Which you  want to unSpotlight video.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSpotLightVideo:(ZMVideoSDKUser*)user;

/**
 * @brief Sets all user's video unSpotlight.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZMVideoSDKErrors)unSpotlightAllVideos;

/**
 * @brief Enables or disables alpha channel mode.
 * @return If the function succeeds, it returns ZMVideoSDKUser object list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getSpotlightedVideoUserList;
@end

NS_ASSUME_NONNULL_END
