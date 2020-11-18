//
//  EIOADJEventSuccess.h
//  eventio
//
//  Created by Pedro Filipe on 17/02/16.
//  Copyright © 2016 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EIOADJEventSuccess : NSObject

/**
 * @brief Message from the eventio backend.
 */
@property (nonatomic, copy) NSString *message;

/**
 * @brief Timestamp from the eventio backend.
 */
@property (nonatomic, copy) NSString *timeStamp;

/**
 * @brief EventIO identifier of the device.
 */
@property (nonatomic, copy) NSString *adid;

/**
 * @brief Event token value.
 */
@property (nonatomic, copy) NSString *eventToken;

/**
 * @brief Event callback ID.
 */
@property (nonatomic, copy) NSString *callbackId;

/**
 * @brief Backend response in JSON format.
 */
@property (nonatomic, strong) NSDictionary *jsonResponse;

/**
 * @brief Initialisation method.
 *
 * @return EIOADJEventSuccess instance.
 */
+ (EIOADJEventSuccess *)eventSuccessResponseData;

@end
