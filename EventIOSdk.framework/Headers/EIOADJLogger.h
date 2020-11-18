//
//  EIOADJLogger.h
//  EventIO
//
//  Created by Christian Wellenbrock on 2012-11-15.
//  Copyright (c) 2012-2014 eventio GmbH. All rights reserved.
//
#import <Foundation/Foundation.h>

typedef enum {
    EIOADJLogLevelVerbose  = 1,
    EIOADJLogLevelDebug    = 2,
    EIOADJLogLevelInfo     = 3,
    EIOADJLogLevelWarn     = 4,
    EIOADJLogLevelError    = 5,
    EIOADJLogLevelAssert   = 6,
    EIOADJLogLevelSuppress = 7
} EIOADJLogLevel;

/**
 * @brief EventIO logger protocol.
 */
@protocol EIOADJLogger

/**
 * @brief Set the log level of the SDK.
 *
 * @param logLevel Level of the logs to be displayed.
 */
- (void)setLogLevel:(EIOADJLogLevel)logLevel isProductionEnvironment:(BOOL)isProductionEnvironment;

/**
 * @brief Prevent log level changes.
 */
- (void)lockLogLevel;

/**
 * @brief Print verbose logs.
 */
- (void)verbose:(nonnull NSString *)message, ...;

/**
 * @brief Print debug logs.
 */
- (void)debug:(nonnull NSString *)message, ...;

/**
 * @brief Print info logs.
 */
- (void)info:(nonnull NSString *)message, ...;

/**
 * @brief Print warn logs.
 */
- (void)warn:(nonnull NSString *)message, ...;
- (void)warnInProduction:(nonnull NSString *)message, ...;

/**
 * @brief Print error logs.
 */
- (void)error:(nonnull NSString *)message, ...;

/**
 * @brief Print assert logs.
 */
- (void)assert:(nonnull NSString *)message, ...;

@end

/**
 * @brief EventIO logger class.
 */
@interface EIOADJLogger : NSObject<EIOADJLogger>

/**
 * @brief Convert log level string to EIOADJLogLevel enumeration.
 *
 * @param logLevelString Log level as string.
 *
 * @return Log level as EIOADJLogLevel enumeration.
 */
+ (EIOADJLogLevel)logLevelFromString:(nonnull NSString *)logLevelString;

@end
