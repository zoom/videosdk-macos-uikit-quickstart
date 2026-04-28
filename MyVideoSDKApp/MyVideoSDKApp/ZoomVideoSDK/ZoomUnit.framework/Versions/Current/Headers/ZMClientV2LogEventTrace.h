//
//  ZMClientV2LogEventTrace.h
//  ZoomUnit
//
//  Created by Davies Zhao on 2026/1/19.
//

#import <Foundation/Foundation.h>
#import <zTelemetryBiz/SnowplowBiz/client_v2/client_v2_telemetry_types.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMClientV2LogEvent : NSObject
@property(nonatomic, assign) e_LogTrace_feature_name featureName;
@property(nonatomic, assign) e_LogTrace_sub_feature_name subFeatureName;
@property(nonatomic, assign) e_LogTrace_log_level logLevel;
@property(nonatomic, assign) e_LogTrace_log_name logName;
@property(nonatomic, assign) double errorCode;
@property(nonatomic, copy) NSString * errorReason;

@property (nonatomic, assign) ns_zoom_telemetry::ZMonitorLogCategory logCategoryType;

@end

@interface ZMClientV2LogEventTrace : NSObject

+ (void)trackClientLogEvent:(ZMClientV2LogEvent *)clientLogEvent;

@end

NS_ASSUME_NONNULL_END
