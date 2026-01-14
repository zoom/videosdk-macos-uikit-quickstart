//
//  PrismOCBridge.h
//  Prism
//
//  Created by Felipe Bastos on 4/9/24.
//

#ifndef PrismOCBridge_h
#define PrismOCBridge_h

enum PZMTextBadgeStyle : NSInteger;
@class PZMFloatingActionButton;
@class PZMCheckboxView;

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStylePrimary NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStyleUncategorized NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStylePositive NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStyleProgress NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStyleNegative NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern enum PZMTextBadgeStyle PZMTextBadgeStyleSpecial NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
typedef PZMFloatingActionButton PZMFirstActionButton NS_SWIFT_UNAVAILABLE("Use FirstActionButton directly instead.");

__attribute__((deprecated)) typedef PZMCheckboxView PZMCheckboxGroupView NS_SWIFT_UNAVAILABLE("Use CheckboxView directly instead.");

#endif /* PrismOCBridge_h */
