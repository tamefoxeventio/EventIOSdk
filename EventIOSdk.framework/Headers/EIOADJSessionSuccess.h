//
//  EIOADJSuccessResponseData.h
//  eventio
//
//  Created by Pedro Filipe on 05/01/16.
//  Copyright © 2016 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EIOADJSessionSuccess : NSObject <NSCopying>

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
 * @brief Backend response in JSON format.
 */
@property (nonatomic, strong, nullable) NSDictionary *jsonResponse;

/**
 * @brief Initialisation method.
 *
 * @return EIOADJSessionSuccess instance.
 */
+ (nullable EIOADJSessionSuccess *)sessionSuccessResponseData;

@end
