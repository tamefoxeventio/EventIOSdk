//
//  EIOADJFailureResponseData.h
//  eventio
//
//  Created by Pedro Filipe on 05/01/16.
//  Copyright © 2016 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EIOADJSessionFailure : NSObject <NSCopying>

/**
 * @brief Message from the eventio backend.
 */
@property (nonatomic, copy, nullable) NSString *message;

/**
 * @brief Timestamp from the eventio backend.
 */
@property (nonatomic, copy, nullable) NSString *timeStamp;

/**
 * @brief EventIO identifier of the device.
 */
@property (nonatomic, copy, nullable) NSString *adid;

/**
 * @brief Information whether sending of the package will be retried or not.
 */
@property (nonatomic, assign) BOOL willRetry;

/**
 * @brief Backend response in JSON format.
 */
@property (nonatomic, strong, nullable) NSDictionary *jsonResponse;

/**
 * @brief Initialisation method.
 *
 * @return EIOADJSessionFailure instance.
 */
+ (nullable EIOADJSessionFailure *)sessionFailureResponseData;

@end
