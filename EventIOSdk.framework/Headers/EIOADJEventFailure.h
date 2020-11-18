//
//  EIOADJEventFailure.h
//  eventio
//
//  Created by Pedro Filipe on 17/02/16.
//  Copyright © 2016 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EIOADJEventFailure : NSObject

/**
 * @brief Message from the eventio backend.
 */
@property (nonatomic, copy) NSString * message;

/**
 * @brief Timestamp from the eventio backend.
 */
@property (nonatomic, copy) NSString * timeStamp;

/**
 * @brief EventIO identifier of the device.
 */
@property (nonatomic, copy) NSString * adid;

/**
 * @brief Event token value.
 */
@property (nonatomic, copy) NSString * eventToken;

/**
 * @brief Event callback ID.
 */
@property (nonatomic, copy) NSString *callbackId;

/**
 * @brief Information whether sending of the package will be retried or not.
 */
@property (nonatomic, assign) BOOL willRetry;

/**
 * @brief Backend response in JSON format.
 */
@property (nonatomic, strong) NSDictionary *jsonResponse;

/**
 * @brief Initialisation method.
 *
 * @return EIOADJEventFailure instance.
 */
+ (EIOADJEventFailure *)eventFailureResponseData;

@end
