//
//  RUAuth2Manager.h
//  Pods
//
//  Created by Benjamin Maer on 4/6/15.
//
//

#import <Foundation/Foundation.h>





@class RUAuthenticationCredentials;





typedef void(^ru_Auth2Manager_authenticationSuccessBlock) (RUAuthenticationCredentials *credentials);
typedef void(^ru_Auth2Manager_successBlock) (id jsonResponse);
typedef void(^ru_Auth2Manager_failureBlock) (NSError *error);





@interface RUAuth2Manager : NSObject

@property (nonatomic, copy) NSString* clientId;
@property (nonatomic, copy) NSString* secret;
@property (nonatomic, copy) NSURL* baseURL;

@property (nonatomic, strong) dispatch_queue_t completionQueue;

#pragma mark - General
- (NSURLSessionDataTask *)POST:(NSString *)URLString
					parameters:(id)parameters
					   success:(ru_Auth2Manager_successBlock)success
					   failure:(ru_Auth2Manager_failureBlock)failure;

- (NSURLSessionDataTask *)PUT:(NSString *)URLString
				   parameters:(id)parameters
					  success:(ru_Auth2Manager_successBlock)success
					  failure:(ru_Auth2Manager_failureBlock)failure;

- (NSURLSessionDataTask *)GET:(NSString *)URLString
				   parameters:(id)parameters
					  success:(ru_Auth2Manager_successBlock)success
					  failure:(ru_Auth2Manager_failureBlock)failure;

- (NSURLSessionDataTask *)PATCH:(NSString *)URLString
				   parameters:(id)parameters
					  success:(ru_Auth2Manager_successBlock)success
					  failure:(ru_Auth2Manager_failureBlock)failure;

- (NSURLSessionDataTask *)DELETE:(NSString *)URLString
				   parameters:(id)parameters
					  success:(ru_Auth2Manager_successBlock)success
					  failure:(ru_Auth2Manager_failureBlock)failure;

#pragma mark - Authentication
- (NSURLSessionDataTask *)authenticateUsingOAuthWithURLString:(NSString *)URLString
														 code:(NSString *)code
												  redirectURI:(NSString *)uri
													  success:(ru_Auth2Manager_authenticationSuccessBlock)success
													  failure:(ru_Auth2Manager_failureBlock)failure;

@end
