/*
 
 TSKNSURLSessionDelegateProxy.h
 TrustKit
 
 Copyright 2015 The TrustKit Project Authors
 Licensed under the MIT license, see associated LICENSE file for terms.
 See AUTHORS file for the list of project authors.
 
 */

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class TrustKit;

typedef void(^TSKURLSessionAuthChallengeCallback)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential);

@interface TSKNSURLSessionDelegateProxy : NSObject

+ (void)swizzleNSURLSessionConstructors:(TrustKit *)trustKit;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithTrustKit:(TrustKit *)trustKit sessionDelegate:(id<NSURLSessionDelegate>)delegate NS_DESIGNATED_INITIALIZER;

- (void)URLSession:(NSURLSession *)session
didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(TSKURLSessionAuthChallengeCallback)completionHandler;

- (void)URLSession:(NSURLSession *)session
              task:(NSURLSessionTask *)task
didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(TSKURLSessionAuthChallengeCallback)completionHandler;

@end

NS_ASSUME_NONNULL_END
