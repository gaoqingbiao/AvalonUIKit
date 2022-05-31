//
//  NSArray+AvalonShorthandAdditions.h
//  Avalononry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "NSArray+AvalonAdditions.h"

#ifdef MAS_SHORTHAND

/**
 *	Shorthand array additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface NSArray (AvalonShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(AvalonConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(AvalonConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(AvalonConstraintMaker *make))block;

@end

@implementation NSArray (AvalonShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(AvalonConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(^)(AvalonConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(^)(AvalonConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
