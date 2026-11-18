//
//  ZMMTDocSharePickerRecentFileItem.h
//  VideoUIBridge
//
//  ObjC mirror of zm::docs::RecentDocsFileItem; only ZMDocHelper.mm touches the C++ side.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Mirror of zm::docs::DocFileType — integer values match exactly.
typedef NS_ENUM(NSInteger, ZMMTDocFileType) {
    ZMMTDocFileTypeDefaultDoc   = 0,
    ZMMTDocFileTypeWhiteboard   = 1,
    ZMMTDocFileTypePaper        = 41,
    ZMMTDocFileTypeSpreadsheet  = 42,
    ZMMTDocFileTypePresentation = 43,
};

/// Mirror of zm::docs::DocSubFileType.
/// Summary/Agenda/Database are meaningful only when parent is kDefaultDoc.
/// Import is meaningful only when parent is kPaper / kSpreadsheet / kPresentation —
/// it tags an externally-uploaded Office file (.docx → Paper+Import = MS Word,
/// .xlsx → Spreadsheet+Import = MS Excel, .pptx → Presentation+Import = MS PowerPoint).
typedef NS_ENUM(NSInteger, ZMMTDocSubFileType) {
    ZMMTDocSubFileTypeNormal   = 0,
    ZMMTDocSubFileTypeSummary,
    ZMMTDocSubFileTypeAgenda,
    ZMMTDocSubFileTypeDatabase,
    ZMMTDocSubFileTypeImport,
};

/// Mirror of zm::docs::RecentTimeType — keep declaration order in lockstep with C++.
typedef NS_ENUM(NSInteger, ZMMTDocRecentTimeType) {
    ZMMTDocRecentTimeTypeInvalid = 0,
    ZMMTDocRecentTimeTypeJustNow,
    ZMMTDocRecentTimeTypeMinutes,
    ZMMTDocRecentTimeTypeSeconds,
    ZMMTDocRecentTimeTypeHours,
    ZMMTDocRecentTimeTypeDays,
    ZMMTDocRecentTimeTypeWeeks,
    ZMMTDocRecentTimeTypeMonths,
    ZMMTDocRecentTimeTypeYears,
};

/// Mirror of zm::docs::ParticipantPermission; ObjC keeps legacy `Access` name (layout identical).
typedef NS_ENUM(NSInteger, ZMMTDocParticipantAccess) {
    ZMMTDocParticipantAccessView    = 0,
    ZMMTDocParticipantAccessComment,
    ZMMTDocParticipantAccessEdit,
};

/// Immutable snapshot of one recent-docs row from ICmmDocsRecentFileList::GetAllRecentFileList().
@interface ZMMTDocSharePickerRecentFileItem : NSObject

@property (nonatomic, copy, readonly)   NSString *docId;
@property (nonatomic, copy, readonly)   NSString *title;
@property (nonatomic, copy, readonly)   NSString *url;
@property (nonatomic, copy, readonly)   NSString *ownerId;
@property (nonatomic, copy, readonly)   NSString *ownerName;
@property (nonatomic, copy, readonly)   NSString *parentId;
@property (nonatomic, copy, readonly)   NSString *parentTitle;
@property (nonatomic, assign, readonly) ZMMTDocFileType fileType;
/// Pair with fileType to resolve the row icon: DefaultDoc + Summary/Agenda/Database
/// → dedicated row icons; Paper/Spreadsheet/Presentation + Import → MS Office icons.
@property (nonatomic, assign, readonly) ZMMTDocSubFileType subType;
@property (nonatomic, assign, readonly) ZMMTDocRecentTimeType timeType;
/// Magnitude paired with timeType, e.g. (Hours, 3) → "3 hours ago".
@property (nonatomic, assign, readonly) NSInteger timeValue;
/// Server-formatted "X ago" string; render verbatim when non-empty.
@property (nonatomic, copy, readonly)   NSString *lastOperatedDisplayText;
/// "Updated" time (docs_updated_time*). Populated for search results (whose last-operated
/// fields are always default); recent results leave these default and use the fields above.
@property (nonatomic, assign, readonly) ZMMTDocRecentTimeType updatedTimeType;
@property (nonatomic, assign, readonly) NSInteger updatedTimeValue;
@property (nonatomic, copy, readonly)   NSString *updatedDisplayText;
/// Caller's current in-doc permission (NOT the dropdown ceiling).
@property (nonatomic, assign, readonly) ZMMTDocParticipantAccess participantPermission;
/// Drives ZUI dropdown ceiling: YES → View+Comment+Edit. Owners always have this.
@property (nonatomic, assign, readonly) BOOL canEditPermission;
/// Considered after canEditPermission when deriving the dropdown ceiling.
@property (nonatomic, assign, readonly) BOOL canCommentPermission;
@property (nonatomic, assign, readonly) BOOL persistentSharePermission;
/// NO → row disabled (caller has lost access since the snapshot).
@property (nonatomic, assign, readonly) BOOL accessPermission;

- (instancetype)initWithDocId:(NSString *)docId
                        title:(NSString *)title
                          url:(NSString *)url
                      ownerId:(NSString *)ownerId
                    ownerName:(NSString *)ownerName
                     parentId:(NSString *)parentId
                  parentTitle:(NSString *)parentTitle
                     fileType:(ZMMTDocFileType)fileType
                      subType:(ZMMTDocSubFileType)subType
                     timeType:(ZMMTDocRecentTimeType)timeType
                    timeValue:(NSInteger)timeValue
      lastOperatedDisplayText:(nullable NSString *)lastOperatedDisplayText
              updatedTimeType:(ZMMTDocRecentTimeType)updatedTimeType
             updatedTimeValue:(NSInteger)updatedTimeValue
           updatedDisplayText:(nullable NSString *)updatedDisplayText
        participantPermission:(ZMMTDocParticipantAccess)participantPermission
            canEditPermission:(BOOL)canEditPermission
         canCommentPermission:(BOOL)canCommentPermission
    persistentSharePermission:(BOOL)persistentSharePermission
             accessPermission:(BOOL)accessPermission NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
