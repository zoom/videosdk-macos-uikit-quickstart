//
//  ZMUnifyWebView+WKDelegate.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#import "ZMUnifyWebView.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMUnifyWebView (WKDelegate)

- (void)webView:(WKWebView *)webView
decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction
                decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler;
- (void)webView:(WKWebView *)webView
decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse
                  decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler;

- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation;

- (void)onNavigateStart:(NSString*)url isMainFrame:(BOOL)isMainFrame isRedirect:(BOOL)isRedirect policy:(WKNavigationActionPolicy)policy;
- (void)onNavigateStart:(NSString*)url isMainFrame:(BOOL)isMainFrame isRedirect:(BOOL)isRedirect  httpStatusCode:(int)httpStatusCode policy:(WKNavigationResponsePolicy)policy;

@end

NS_ASSUME_NONNULL_END
