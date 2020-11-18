//
//  EventIOHolder.h
//  EventIO
//
//  Created by zena.tang on 2020/11/17.
//  Copyright © 2020 adjust GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIOADJConfig.h"

NS_ASSUME_NONNULL_BEGIN


@interface EventIOHolder : NSObject

/**
* @brief Tell EventIO that the application did launch.
*        This is required to initialize EventIO. Call this in the didFinishLaunching
*        method of your AppDelegate.
*
* @note See EIOADJConfig.h for more configuration options
*
* @param eventioConfig The configuration object that includes the environment
*                     and the App Token of your app. This unique identifier can
*                     be found it in your dashboard at http://eventio.com and should always
*                     be 12 characters long.
*/
+ (void)appDidLaunch:(nullable EIOADJConfig *)eventioConfig;

/**
* @brief send event to test server.
*
*/
+ (void)setTestMode;

/**
* @brief Enable or disable offline mode. Activities won't be sent but they are saved when
*        offline mode is disabled. This feature is not saved for future sessions.
*
* @param enabled The flag to enable or disable offline mode.
*/
+ (void)setOfflineMode:(BOOL)enabled;

/**
 * @brief Enable or disable the eventio SDK. This setting is saved for future sessions.
 *
 * @param enabled The flag to enable or disable the eventio SDK.
 */
+ (void)setEnabled:(BOOL)enabled;

/**
 * @brief Check if the SDK is enabled or disabled.
 *
 * return Boolean indicating whether SDK is enabled or not.
 */
+ (BOOL)isEnabled;
/**
 * @brief Read the URL that opened the application to search for an eventio deep link.
 *
 * @param url URL object which contains info about eventio deep link.
 */
+ (void)appWillOpenUrl:(nonnull NSURL *)url;

/**
* @brief Tell EventIO that a particular event has happened.
*
* @param eventName  eventName
* @param eventValue  can be nil
*/
+ (void)trackEvent:(NSString *)eventName eventValue:(nullable NSDictionary *)eventValue;


/**
 * @brief Tell EventIO that a particular event has happened. and set the custom user defined ID for the event which will be reported in
 *        success/failure callbacks.
 *
 ** @param eventName  eventName
 * @param eventValue  can be nil
 * @param callbackId Custom user defined identifier for the event
 */
+ (void)trackEvent:(NSString *)eventName eventValue:(nullable NSDictionary *)eventValue callbackId: (NSString *)callbackId;

/**
 * @brief Get current EventIO SDK version string.
 *
 * @return EventIO SDK version string (iosX.Y.Z).
 */
+ (nullable NSString *)sdkVersion;


@end

NS_ASSUME_NONNULL_END
