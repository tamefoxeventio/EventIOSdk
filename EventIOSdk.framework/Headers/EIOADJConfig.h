//
//  EIOADJConfig.h
//  eventio
//
//  Created by Pedro Filipe on 30/10/14.
//  Copyright (c) 2014 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "EIOADJLogger.h"
#import "EIOADJAttribution.h"
#import "EIOADJEventSuccess.h"
#import "EIOADJEventFailure.h"
#import "EIOADJSessionSuccess.h"
#import "EIOADJSessionFailure.h"

/**
 * @brief Optional delegate that will get informed about tracking results.
 */
@protocol EventIODelegate

@optional

/**
 * @brief Optional delegate method that gets called when the attribution information changed.
 *
 * @param attribution The attribution information.
 *
 * @note See EIOADJAttribution for details.
 */
- (void)eventioAttributionChanged:(nullable EIOADJAttribution *)attribution;

/**
 * @brief Optional delegate method that gets called when an event is tracked with success.
 *
 * @param eventSuccessResponseData The response information from tracking with success
 *
 * @note See EIOADJEventSuccess for details.
 */
- (void)eventioEventTrackingSucceeded:(nullable EIOADJEventSuccess *)eventSuccessResponseData;

/**
 * @brief Optional delegate method that gets called when an event is tracked with failure.
 *
 * @param eventFailureResponseData The response information from tracking with failure
 *
 * @note See EIOADJEventFailure for details.
 */
- (void)eventioEventTrackingFailed:(nullable EIOADJEventFailure *)eventFailureResponseData;

/**
 * @brief Optional delegate method that gets called when an session is tracked with success.
 *
 * @param sessionSuccessResponseData The response information from tracking with success
 *
 * @note See EIOADJSessionSuccess for details.
 */
- (void)eventioSessionTrackingSucceeded:(nullable EIOADJSessionSuccess *)sessionSuccessResponseData;

/**
 * @brief Optional delegate method that gets called when an session is tracked with failure.
 *
 * @param sessionFailureResponseData The response information from tracking with failure
 *
 * @note See EIOADJSessionFailure for details.
 */
- (void)eventioSessionTrackingFailed:(nullable EIOADJSessionFailure *)sessionFailureResponseData;

/**
 * @brief Optional delegate method that gets called when a deferred deep link is about to be opened by the eventio SDK.
 *
 * @param deeplink The deep link url that was received by the eventio SDK to be opened.
 *
 * @return Boolean that indicates whether the deep link should be opened by the eventio SDK or not.
 */
- (BOOL)eventioDeeplinkResponse:(nullable NSURL *)deeplink;

@end

/**
 * @brief EventIO configuration object class.
 */
@interface EIOADJConfig : NSObject<NSCopying>

/**
 * @brief SDK prefix.
 *
 * @note Not to be used by users, intended for non-native eventio SDKs only.
 */
@property (nonatomic, copy, nullable) NSString *sdkPrefix;

/**
 * @brief Default tracker to attribute organic installs to (optional).
 */
@property (nonatomic, copy, nullable) NSString *defaultTracker;

@property (nonatomic, copy, nullable) NSString *externalDeviceId;

/**
 * @brief EventIO app token.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *appToken;

/**
 * @brief EventIO environment variable.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *environment;

/**
 * @brief Change the verbosity of EventIO's logs.
 *
 * @note You can increase or reduce the amount of logs from EventIO by passing
 *       one of the following parameters. Use EIOADJLogLevelSuppress to disable all logging.
 *       The desired minimum log level (default: info)
 *       Must be one of the following:
 *         - EIOADJLogLevelVerbose    (enable all logging)
 *         - EIOADJLogLevelDebug      (enable more logging)
 *         - EIOADJLogLevelInfo       (the default)
 *         - EIOADJLogLevelWarn       (disable info logging)
 *         - EIOADJLogLevelError      (disable warnings as well)
 *         - EIOADJLogLevelAssert     (disable errors as well)
 *         - EIOADJLogLevelSuppress   (suppress all logging)
 */
@property (nonatomic, assign) EIOADJLogLevel logLevel;

/**
 * @brief Enable event buffering if your app triggers a lot of events.
 *        When enabled, events get buffered and only get tracked each
 *        minute. Buffered events are still persisted, of course.
 */
@property (nonatomic, assign) BOOL eventBufferingEnabled;

/**
 * @brief Set the optional delegate that will inform you about attribution or events.
 *
 * @note See the EventIODelegate declaration above for details.
 */
@property (nonatomic, weak, nullable) NSObject<EventIODelegate> *delegate;

/**
 * @brief Enables sending in the background.
 */
@property (nonatomic, assign) BOOL sendInBackground;

/**
 * @brief Enables/disables reading of iAd framework data needed for ASA tracking.
 */
@property (nonatomic, assign) BOOL allowiAdInfoReading;

/**
 * @brief Enables/disables reading of IDFA parameter.
 */
@property (nonatomic, assign) BOOL allowIdfaReading;

/**
 * @brief Enables delayed start of the SDK.
 */
@property (nonatomic, assign) double delayStart;

/**
 * @brief User agent for the requests.
 */
@property (nonatomic, copy, nullable) NSString *userAgent;

/**
 * @brief Set if the device is known.
 */
@property (nonatomic, assign) BOOL isDeviceKnown;

/**
 * @brief EventIO app secret id.
 */
@property (nonatomic, copy, readonly, nullable) NSString *secretId;

/**
 * @brief EventIO app secret.
 */
@property (nonatomic, copy, readonly, nullable) NSString *appSecret;

/**
* @brief EventIO use taking IO
*/
@property (nonatomic, assign) BOOL useTkio;
/**
 * @brief EventIO set app secret.
 */
- (void)setAppSecret:(NSUInteger)secretId
               info1:(NSUInteger)info1
               info2:(NSUInteger)info2
               info3:(NSUInteger)info3
               info4:(NSUInteger)info4;


@property (nonatomic, assign, readonly) BOOL isSKAdNetworkHandlingActive;

- (void)deactivateSKAdNetworkHandling;

/**
 * @brief EventIO url strategy.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *urlStrategy;

/**
 * @brief Get configuration object for the initialization of the EventIO SDK.
 *
 * @param appToken The App Token of your app. This unique identifier can
 *                 be found it in your dashboard at http://eventio.com and should always
 *                 be 12 characters long.
 * @param environment The current environment your app. We use this environment to
 *                    distinguish between real traffic and artificial traffic from test devices.
 *                    It is very important that you keep this value meaningful at all times!
 *                    Especially if you are tracking revenue.
 *
 * @returns EventIO configuration object.
 */
+ (nullable EIOADJConfig *)configWithAppToken:(nullable NSString *)appToken
                               environment:(nullable NSString *)environment;

- (nullable id)initWithAppToken:(nullable NSString *)appToken
                    environment:(nullable NSString *)environment;

/**
 * @brief Configuration object for the initialization of the EventIO SDK.
 *
 * @param appToken The App Token of your app. This unique identifier can
 *                 be found it in your dashboard at http://eventio.com and should always
 *                 be 12 characters long.
 * @param environment The current environment your app. We use this environment to
 *                    distinguish between real traffic and artificial traffic from test devices.
 *                    It is very important that you keep this value meaningful at all times!
 *                    Especially if you are tracking revenue.
 * @param allowSuppressLogLevel If set to true, it allows usage of EIOADJLogLevelSuppress
 *                              and replaces the default value for production environment.
 *
 * @returns EventIO configuration object.
 */
+ (nullable EIOADJConfig *)configWithAppToken:(nullable NSString *)appToken
                               environment:(nullable NSString *)environment
                     allowSuppressLogLevel:(BOOL)allowSuppressLogLevel;

- (nullable id)initWithAppToken:(nullable NSString *)appToken
                    environment:(nullable NSString *)environment
          allowSuppressLogLevel:(BOOL)allowSuppressLogLevel;

/**
 * @brief Check if eventio configuration object is valid.
 * 
 * @return Boolean indicating whether eventio config object is valid or not.
 */
- (BOOL)isValid;

@end
