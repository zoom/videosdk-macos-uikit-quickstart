
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZMCefDesktopMediaSourceType) {
    ZMCefDesktopMediaSourceTypeNone = 0,
    ZMCefDesktopMediaSourceTypeScreen = 1,
    ZMCefDesktopMediaSourceTypeWindow = 2,
};

typedef struct {
    ZMCefDesktopMediaSourceType type;
    long long id;
    BOOL audioShare;
} ZMCefDesktopMediaSource;

// CEF getDisplayMedia() screen picker result. |source.type| is
// ZMCefDesktopMediaSourceTypeNone when the user cancels.
typedef void (^ZMCefScreenPickerCompletion)(ZMCefDesktopMediaSource source);

@protocol ZMUnifyWebViewSharedProtocol <NSObject>

- (NSString *)languageCode;

// MARK: - Screenshot
// Shared entry point for WebView screenshot requests. The implementation
// selects the PT or standalone Meeting host for the current process.
- (void)startScreenShot:(NSString *)requestId
        hideMainWindow:(BOOL)hideMainWindow
  compressImageIntensity:(NSInteger)compressImageIntensity;

//MARK: - hot key
- (BOOL)registerHotkey:(NSString*)name isGlobal:(BOOL)isGlobal webviewID:(NSString*)webViewID;
- (BOOL)unregisterHotkey:(NSString*)name isGlobal:(BOOL)isGlobal webviewID:(NSString*)webViewID;
- (NSDictionary*)queryHotkeyDetail:(NSString*)name;
- (BOOL)handledLocalEvent:(NSEvent *)event webviewID:(NSString *)webviewID;

//MARK: - CEF getDisplayMedia() screen picker
// CEF getDisplayMedia() native screen picker. Owner-aware: a request from a
// different |ownerId| while one is in flight is rejected with a None source.
- (void)showCefScreenPickerForOwner:(NSString *)ownerId
                  audioShareRequest:(BOOL)audioShareRequest
                         completion:(ZMCefScreenPickerCompletion)completion;
// No-op unless the picker is currently owned by |ownerId|.
- (void)closeCefScreenPickerForOwner:(NSString *)ownerId;

@end
