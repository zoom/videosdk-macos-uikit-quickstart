//
//  ZMMTDocSharePickerEmptyStateStrings.h
//  VideoUIBridge
//
//  ObjC mirror of zm::docs::EmptyStateStrings — onboarding copy for the Files-tab empty state.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTDocSharePickerRecentFileItem.h>

NS_ASSUME_NONNULL_BEGIN

/// Mirror of zm::docs::ActionDisplay — one tile per entry; UI must render in server order.
@interface ZMMTDocSharePickerActionDisplay : NSObject

/// May be empty; UI falls back to a Figma default.
@property (nonatomic, copy, readonly) NSString *label;
/// May be empty; UI falls back to a Figma default.
@property (nonatomic, copy, readonly) NSString *desc;
@property (nonatomic, assign, readonly) ZMMTDocFileType type;

- (instancetype)initWithLabel:(nullable NSString *)label
                          desc:(nullable NSString *)desc
                          type:(ZMMTDocFileType)type NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new  NS_UNAVAILABLE;

@end

/// Server-driven copy for the Files-tab onboarding card; non-nil fields, may be empty.
@interface ZMMTDocSharePickerEmptyStateStrings : NSObject

@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *subtitle;
/// Render in server order; empty array → picker falls back to all four Figma defaults.
@property (nonatomic, copy, readonly) NSArray<ZMMTDocSharePickerActionDisplay *> *actions;

- (instancetype)initWithTitle:(nullable NSString *)title
                     subtitle:(nullable NSString *)subtitle
                      actions:(nullable NSArray<ZMMTDocSharePickerActionDisplay *> *)actions NS_DESIGNATED_INITIALIZER;

/// All-empty sentinel for when the server hasn't delivered copy yet.
+ (instancetype)empty;

- (BOOL)isEmpty;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
