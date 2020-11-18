//
//  EventIOObjectCache.h
//  EventIOSdk
//
//  Created by zena.tang on 2020/11/9.
//  Copyright © 2020 adjust GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface EventIOObjectCache : NSObject

+ (instancetype)sharedInstance;
@property(nonatomic, strong) NSMutableDictionary *references;

@end


// 返回用于查找 Unity 对象的 key。
@interface NSObject (EIOOwnershipAdditions)

- (NSString *)eio_referenceKey;


@end
