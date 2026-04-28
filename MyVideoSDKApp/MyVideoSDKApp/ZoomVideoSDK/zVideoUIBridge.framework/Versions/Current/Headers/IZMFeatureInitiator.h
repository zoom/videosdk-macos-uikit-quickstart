//
//  IZMFeatureInitiator.h
//  VideoUI
//
//  Created by Howie Xu on 2/29/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMFeatureType) {
    ZMFeatureTypeSummary,
    ZMFeatureTypeQuestion,
    ZMFeatureTypeRecording,
    ZMFeatureTypeCC,
    ZMFeatureTypeLivestream,
};


@protocol IZMFeatureInitiator <ZMRoutableObject>
@optional
- (BOOL)isStartByself:(ZMFeatureType)type;
- (void)setStartByself:(ZMFeatureType)type isByself:(BOOL)isByself;
- (BOOL)isStopByself:(ZMFeatureType)type;
- (void)setStopByself:(ZMFeatureType)type isByself:(BOOL)isByself;
- (BOOL)isOriginalHostJoined:(ZMFeatureType)type;
- (void)setOriginalHostJoined:(ZMFeatureType)type isByself:(BOOL)isJoined;
- (BOOL)isShowed:(ZMFeatureType)type;
- (void)setShowed:(ZMFeatureType)type showed:(BOOL)showed;
- (BOOL)isStartWithNextStep:(ZMFeatureType)type;
- (void)setStartWithNextStep:(ZMFeatureType)type startWithNextStep:(BOOL)startWithNextStep;

@end

NS_ASSUME_NONNULL_END

