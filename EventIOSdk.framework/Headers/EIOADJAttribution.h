//
//  EIOADJAttribution.h
//  eventio
//
//  Created by Pedro Filipe on 29/10/14.
//  Copyright (c) 2014 eventio GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief EventIO attribution object.
 */
@interface EIOADJAttribution : NSObject <NSCoding, NSCopying>

/**
 * @brief Tracker token.
 */
@property (nonatomic, copy, nullable) NSString *trackerToken;

/**
 * @brief Tracker name.
 */
@property (nonatomic, copy, nullable) NSString *trackerName;

/**
 * @brief Network name.
 */
@property (nonatomic, copy, nullable) NSString *network;

/**
 * @brief Campaign name.
 */
@property (nonatomic, copy, nullable) NSString *campaign;

/**
 * @brief Adgroup name.
 */
@property (nonatomic, copy, nullable) NSString *adgroup;

/**
 * @brief Creative name.
 */
@property (nonatomic, copy, nullable) NSString *creative;

/**
 * @brief Click label content.
 */
@property (nonatomic, copy, nullable) NSString *clickLabel;

/**
 * @brief EventIO identifier value.
 */
@property (nonatomic, copy, nullable) NSString *adid;

/**
 * @brief Make attribution object.
 * 
 * @param jsonDict Dictionary holding attribution key value pairs.
 * @param adid EventIO identifier value.
 * 
 * @return EventIO attribution object.
 */
+ (nullable EIOADJAttribution *)dataWithJsonDict:(nonnull NSDictionary *)jsonDict adid:(nonnull NSString *)adid;

- (nullable id)initWithJsonDict:(nonnull NSDictionary *)jsonDict adid:(nonnull NSString *)adid;

/**
 * @brief Check if given attribution equals current one.
 * 
 * @param attribution Attribution object to be compared with current one.
 * 
 * @return Boolean indicating whether two attribution objects are the equal.
 */
- (BOOL)isEqualToAttribution:(nonnull EIOADJAttribution *)attribution;

/**
 * @brief Get attribution value as dictionary.
 * 
 * @return Dictionary containing attribution as key-value pairs.
 */
- (nullable NSDictionary *)dictionary;

@end
