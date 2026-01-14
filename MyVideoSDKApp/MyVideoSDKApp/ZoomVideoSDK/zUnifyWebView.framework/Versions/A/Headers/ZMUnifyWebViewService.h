//
//  ZMUnifyWebViewService.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/30.
//

#import <Foundation/Foundation.h>
#import <zUnifyWebView/ZMUnifyWebViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN
 
@interface ZMUnifyWebViewService : NSObject

+ (ZMUnifyWebViewService *)shareInstance;
//MARK: - V2
- (id<ZMUnifyWebViewProtocol>)createUnifyWebView:(ZMUnifyWebViewConfiguration*)config;
- (id<ZMUnifyWebViewProtocol>)getUnifyWebViewWith:(NSString *)webViewID;
- (void)destroyUnifyWebView:(id<ZMUnifyWebViewProtocol>)unifyWebInstance;

//MARK: - V1 (Deprecated, please use V2 interfaces)
/// @deprecated Use createUnifyWebView: (V2) instead
- (id<ZMUnifyWebViewInstance>)createUnifyWebView:(ZMUnifyWebViewConfiguration *)config layoutBlock:(void (^)(NSView *view))layoutBlock DEPRECATED_MSG_ATTRIBUTE("Use createUnifyWebView: (V2) instead");
/// @deprecated Use createUnifyWebView: (V2) instead
- (id<ZMUnifyWebViewInstance>)createUnifyWebView:(enum UnifyWebViewAppType)moduleType processDisplayName:(NSString *)processDisplayName config:(WKWebViewConfiguration *)config layoutBlock:(void (^)(NSView *view))layoutBlock DEPRECATED_MSG_ATTRIBUTE("Use createUnifyWebView: (V2) instead");
/// @deprecated Use getUnifyWebViewWith: (V2) instead
- (id<ZMUnifyWebViewInstance>)unifyWebViewWith:(NSString *)webViewID DEPRECATED_MSG_ATTRIBUTE("Use getUnifyWebViewWith: (V2) instead");
/// @deprecated Use destroyUnifyWebView: (V2) instead
- (void)destroyWebView:(id<ZMUnifyWebViewInstance>)unifyWebInstance DEPRECATED_MSG_ATTRIBUTE("Use destroyUnifyWebView: (V2) instead");

@end

NS_ASSUME_NONNULL_END
