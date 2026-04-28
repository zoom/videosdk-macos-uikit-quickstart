//
//  ZMSipLanguageListProtocol.h
//  ZoomUnit
//
//  Created by ares.lin on 10/31/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#ifndef ZMSipLanguageListProtocol_h
#define ZMSipLanguageListProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for language list management in SIP calls
 * Provides methods to query language codes, names, and their mappings
 */
@protocol ZMSipLanguageListProtocol <NSObject>

@required

/**
 * Gets all language codes, returned in insertion order
 * @return Array of language codes, never returns nil
 */
- (NSArray<NSString *> *)languageCodes;

/**
 * Gets all language names, returned in insertion order
 * @return Array of language names, never returns nil
 */
- (NSArray<NSString *> *)languageNames;

/**
 * Gets the language name for the given language code
 * @param code Language code
 * @return Corresponding language name, or nil if not found
 */
- (nullable NSString *)nameForCode:(NSString *)code;

/**
 * Gets the language code for the given language name
 * @param name Language name
 * @return Corresponding language code, or nil if not found
 */
- (nullable NSString *)codeForName:(NSString *)name;

/**
 * Gets the index position of the specified language code in the list
 * @param code Language code
 * @return Index position, or NSNotFound if not found
 */
- (NSUInteger)indexOfCode:(NSString *)code;

/**
 * Gets the count of languages in the list
 * @return Number of languages
 */
- (NSUInteger)count;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMSipLanguageListProtocol_h */

