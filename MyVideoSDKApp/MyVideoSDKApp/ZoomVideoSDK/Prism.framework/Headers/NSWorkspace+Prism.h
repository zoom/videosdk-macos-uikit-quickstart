//
//  NSWorkspace+Prism.h
//  Prism
//
//  Created by Cooper.Chen on 2026/1/15.
//

#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSWorkspace (Prism)

// MARK: - Web Link Management

/// Safely opens the Web link at the specified URL.
///
/// This method is a specialization of NSWorkspace.open() method,
/// which only allows valid Web links to be opened.
///
/// @param url A URL specifying the Web page to open.
/// @return A Boolean value indicating whether the operation is proceeded.
- (BOOL)zm_safelyOpenWebLinkWithURL:(NSURL *)url NS_SWIFT_NAME(safelyOpenWebLink(with:));

// MARK: - File Safety Management

/// Safely opens a file at the specified path with security checks.
- (BOOL)safeOpenFile:(NSString *)filePath;

/// Returns an array of whitelisted file extensions that are considered safe to open.
- (NSArray<NSString *> *)getWhiteListArray;

/// Returns an array of blacklisted file extensions that are considered unsafe to open.
- (NSArray<NSString *> *)getBlackListArray;

/// Sets the server-provided blacklist array for file extensions.
- (void)setServerBlackList:(nullable NSArray<NSString *> *)blackList;

/// Returns the current server blacklist array, falling back to default blacklist if needed.
- (NSArray<NSString *> *)getServerBlackList;

// MARK: - Browser Window Management

/// Opens a new browser window with the specified URL.
///
/// This method attempts to open a URL in a new browser window, supporting Safari, Chrome, and Firefox.
/// It handles different browser configurations appropriately.
///
/// @param url The URL to open in a new browser window.
/// @param completionHandler A completion block called when the operation completes.
///        - pid: The process identifier of the opened application (may be 0 for some browsers).
///        - error: An error object if the operation failed, or nil if successful.
/// @return A Boolean value indicating whether the operation was attempted.
- (BOOL)openNewWindowWithURL:(NSURL *)url
           completionHandler:(void (^ _Nullable)(NSInteger pid, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(openNewWindow(with:completionHandler:));

// MARK: - Legacy API Compatibility

/// Legacy method name compatibility for setServerBlackListArray.
- (void)setServerBlackListArray:(nullable NSArray<NSString *> *)blackListArray;

/// Legacy method name compatibility for getServerBlackListArray.
- (NSArray<NSString *> *)getServerBlackListArray;

@end

NS_ASSUME_NONNULL_END
