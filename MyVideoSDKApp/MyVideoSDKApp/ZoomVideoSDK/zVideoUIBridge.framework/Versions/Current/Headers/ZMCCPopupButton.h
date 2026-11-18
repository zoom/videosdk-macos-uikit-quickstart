//
//  ZMCCPopupButton.h
//  VideoUIBridge
//
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMCCPopupButton : ZMPopUpButton
@property (nonatomic, copy) NSString *(^accessibilityValueBlock)(ZMCCPopupButton *aButton);
@end

NS_ASSUME_NONNULL_END
