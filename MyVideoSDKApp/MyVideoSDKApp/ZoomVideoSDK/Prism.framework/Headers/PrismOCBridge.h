//
//  PrismOCBridge.h
//  Prism
//
//  Created by Felipe Bastos on 4/9/24.
//

#ifndef PrismOCBridge_h
#define PrismOCBridge_h

enum PZMTextBadgeStyle : NSInteger;
enum PZMNotifierViewStyle: NSInteger;
enum PZMToastButtonType: NSInteger;
enum PZMToastType: NSInteger;
enum PZMToastPosition: NSInteger;
enum PZMLinkTriggerType: NSInteger;
enum PZMPlaybarItemType: NSInteger;
@class PZMFloatingActionButton;
@class PZMCheckboxView;

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStylePrimary NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStyleUncategorized NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStylePositive NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStyleProgress NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStyleNegative NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMTextBadgeStyle PZMTextBadgeStyleSpecial NS_SWIFT_UNAVAILABLE("Use TextBadge.Style directly instead.");

__attribute__((deprecated))
typedef PZMFloatingActionButton PZMFirstActionButton NS_SWIFT_UNAVAILABLE("Use FirstActionButton directly instead.");

__attribute__((deprecated))
typedef PZMCheckboxView PZMCheckboxGroupView NS_SWIFT_UNAVAILABLE("Use CheckboxView directly instead.");

__attribute__((deprecated))
extern const enum PZMNotifierViewStyle PZMNotifierViewStyleBlue NS_SWIFT_UNAVAILABLE("Use NotifierView.Style directly instead.");

__attribute__((deprecated))
extern const enum PZMNotifierViewStyle PZMNotifierViewStyleRed NS_SWIFT_UNAVAILABLE("Use NotifierView.Style directly instead.");

// Backwards-compatible aliases for ToastButtonType (@objc PZMToastButtonType). Declared as typed
// `static const enum PZMToastButtonType` for the same reasons as the PZMPlaybarItemType aliases
// below: they carry the actual enum type (so they can be passed to APIs typed PZMToastButtonType
// without an illegal enum-to-enum conversion in C++) while remaining usable as switch/case labels.
// Values are hardcoded to match the Swift declaration order in Sentiment.swift; PrismOCBridge.m
// has _Static_assert checks that fail the build if they ever drift.
static const enum PZMToastButtonType ToastButtonTypePrimary   __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ToastButtonType.primary directly instead.")   = (enum PZMToastButtonType)0;
static const enum PZMToastButtonType ToastButtonTypeSecondary __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ToastButtonType.secondary directly instead.") = (enum PZMToastButtonType)1;
static const enum PZMToastButtonType ToastButtonTypeOpenLink  __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ToastButtonType.openLink directly instead.")  = (enum PZMToastButtonType)2;
static const enum PZMToastButtonType ToastButtonTypeClose     __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ToastButtonType.close directly instead.")     = (enum PZMToastButtonType)3;
static const enum PZMToastButtonType ToastButtonTypeNone      __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ToastButtonType.none directly instead.")      = (enum PZMToastButtonType)4;

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeInformation NS_SWIFT_UNAVAILABLE("Use ToastType.information directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeConfirmation NS_SWIFT_UNAVAILABLE("Use ToastType.confirmation directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeAdvisory NS_SWIFT_UNAVAILABLE("Use ToastType.advisory directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeWarning NS_SWIFT_UNAVAILABLE("Use ToastType.warning directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeError NS_SWIFT_UNAVAILABLE("Use ToastType.error directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeImage NS_SWIFT_UNAVAILABLE("Use ToastType.image directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeAi NS_SWIFT_UNAVAILABLE("Use ToastType.ai directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeCustom NS_SWIFT_UNAVAILABLE("Use ToastType.custom directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypePlain NS_SWIFT_UNAVAILABLE("Use ToastType.plain directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeNew NS_SWIFT_UNAVAILABLE("Use ToastType.new directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeBeta NS_SWIFT_UNAVAILABLE("Use ToastType.beta directly instead.");

__attribute__((deprecated))
extern const enum PZMToastType ZMToastTypeSystem NS_SWIFT_UNAVAILABLE("Use ToastType.system directly instead.");

__attribute__((deprecated))
typedef enum PZMToastPosition ZMToastPosition NS_SWIFT_UNAVAILABLE("Use ToastPosition directly instead.");

__attribute__((deprecated))
extern const enum PZMToastPosition ZMToastPositionChatClient NS_SWIFT_UNAVAILABLE("Use ToastPosition.chatClient directly instead.");

__attribute__((deprecated))
extern const enum PZMToastPosition ZMToastPositionClipsAIAvatar NS_SWIFT_UNAVAILABLE("Use ToastPosition.clipsAIAvatar directly instead.");

__attribute__((deprecated))
typedef enum PZMLinkTriggerType ZMLinkTriggerType NS_SWIFT_UNAVAILABLE("Use LinkTriggerType directly instead.");

__attribute__((deprecated))
extern const enum PZMLinkTriggerType ZMLinkTriggerTypeMouseClick NS_SWIFT_UNAVAILABLE("Use LinkTriggerType.MouseClick directly instead.");

__attribute__((deprecated))
extern const enum PZMLinkTriggerType ZMLinkTriggerTypeEnterKeyDown NS_SWIFT_UNAVAILABLE("Use LinkTriggerType.EnterKeyDown directly instead.");

__attribute__((deprecated))
extern const enum PZMLinkTriggerType ZMLinkTriggerTypeSpaceKeyDown NS_SWIFT_UNAVAILABLE("Use LinkTriggerType.SpaceKeyDown directly instead.");

__attribute__((deprecated))
typedef enum PZMPlaybarItemType ZMPlaybarItemType NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType directly instead.");

// Backwards-compatible aliases for ZMPlaybarViewController.PlaybarItemType (@objc PZMPlaybarItemType).
// Declared as file-scope `static const enum PZMPlaybarItemType` (rather than a separate anonymous
// enum) so each alias carries the *actual* enum type. A distinct anonymous-enum type would compile
// as a switch/case label but fail wherever an alias is passed to an API parameter typed
// PZMPlaybarItemType — Objective-C++ forbids the implicit enum-to-enum conversion. Because these
// have a visible constant initializer they remain usable as case labels,
// unlike the former `extern const` variables (whose values were not constant expressions in the
// consumer). This header is reachable from the Prism umbrella and cannot import the generated
// Prism-Swift.h, so the values are hardcoded to match the Swift declaration order in
// ZMPlaybarViewController.swift; PrismOCBridge.m has _Static_assert checks that fail the build if
// they ever drift.
static const enum PZMPlaybarItemType ZMPlaybarItemTypePlay          __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.play directly instead.")          = (enum PZMPlaybarItemType)0;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeDurationLabel __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.durationLabel directly instead.") = (enum PZMPlaybarItemType)1;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeVolume        __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.volume directly instead.")        = (enum PZMPlaybarItemType)2;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeSetting       __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.setting directly instead.")       = (enum PZMPlaybarItemType)3;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeSpeed         __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.speed directly instead.")         = (enum PZMPlaybarItemType)4;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeClosedCaption __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.closedCaption directly instead.") = (enum PZMPlaybarItemType)5;
static const enum PZMPlaybarItemType ZMPlaybarItemTypeSliderView    __attribute__((deprecated)) NS_SWIFT_UNAVAILABLE("Use ZMPlaybarViewController.PlaybarItemType.sliderView directly instead.")    = (enum PZMPlaybarItemType)6;

// These macros alias the deprecated compatibility type names to their real (@objc-exported) enum
// types. They are macros rather than typedefs so that the names can still be used with an explicit
// `enum` specifier, which is illegal against a typedef name. A macro cannot carry a deprecation
// attribute, so deprecation lives on the individual value aliases above.
#define ZMPlaybarItemType PZMPlaybarItemType
#define ToastButtonType   PZMToastButtonType
#define ZMToastType       PZMToastType

#endif /* PrismOCBridge_h */
