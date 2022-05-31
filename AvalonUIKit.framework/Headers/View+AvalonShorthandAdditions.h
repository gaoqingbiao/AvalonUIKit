//
//  UIView+AvalonShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "View+AvalonAdditions.h"

#ifdef Avalon_SHORTHAND

/**
 *	Shorthand view additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface MAS_VIEW (AvalonShorthandAdditions)

@property (nonatomic, strong, readonly) AvalonViewAttribute *left;
@property (nonatomic, strong, readonly) AvalonViewAttribute *top;
@property (nonatomic, strong, readonly) AvalonViewAttribute *right;
@property (nonatomic, strong, readonly) AvalonViewAttribute *bottom;
@property (nonatomic, strong, readonly) AvalonViewAttribute *leading;
@property (nonatomic, strong, readonly) AvalonViewAttribute *trailing;
@property (nonatomic, strong, readonly) AvalonViewAttribute *width;
@property (nonatomic, strong, readonly) AvalonViewAttribute *height;
@property (nonatomic, strong, readonly) AvalonViewAttribute *centerX;
@property (nonatomic, strong, readonly) AvalonViewAttribute *centerY;
@property (nonatomic, strong, readonly) AvalonViewAttribute *baseline;
@property (nonatomic, strong, readonly) AvalonViewAttribute *(^attribute)(NSLayoutAttribute attr);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) AvalonViewAttribute *firstBaseline;
@property (nonatomic, strong, readonly) AvalonViewAttribute *lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) AvalonViewAttribute *leftMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *rightMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *topMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *bottomMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *leadingMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *trailingMargin;
@property (nonatomic, strong, readonly) AvalonViewAttribute *centerXWithinMargins;
@property (nonatomic, strong, readonly) AvalonViewAttribute *centerYWithinMargins;

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

@property (nonatomic, strong, readonly) AvalonViewAttribute *safeAreaLayoutGuideTop AvalonI_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) AvalonViewAttribute *safeAreaLayoutGuideBottom AvalonI_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) AvalonViewAttribute *safeAreaLayoutGuideLeft AvalonI_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) AvalonViewAttribute *safeAreaLayoutGuideRight AvalonI_AVAILABLE(ios(11.0),tvos(11.0));

#endif

- (NSArray *)makeConstraints:(void(^)(AvalonConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(AvalonConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(AvalonConstraintMaker *make))block;

@end

#define Avalon_ATTR_FORWARD(attr)  \
- (AvalonViewAttribute *)attr {    \
    return [self mas_##attr];   \
}

@implementation MAS_VIEW (AvalonShorthandAdditions)

Avalon_ATTR_FORWARD(top);
Avalon_ATTR_FORWARD(left);
Avalon_ATTR_FORWARD(bottom);
Avalon_ATTR_FORWARD(right);
Avalon_ATTR_FORWARD(leading);
Avalon_ATTR_FORWARD(trailing);
Avalon_ATTR_FORWARD(width);
Avalon_ATTR_FORWARD(height);
Avalon_ATTR_FORWARD(centerX);
Avalon_ATTR_FORWARD(centerY);
Avalon_ATTR_FORWARD(baseline);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

Avalon_ATTR_FORWARD(firstBaseline);
Avalon_ATTR_FORWARD(lastBaseline);

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

Avalon_ATTR_FORWARD(leftMargin);
Avalon_ATTR_FORWARD(rightMargin);
Avalon_ATTR_FORWARD(topMargin);
Avalon_ATTR_FORWARD(bottomMargin);
Avalon_ATTR_FORWARD(leadingMargin);
Avalon_ATTR_FORWARD(trailingMargin);
Avalon_ATTR_FORWARD(centerXWithinMargins);
Avalon_ATTR_FORWARD(centerYWithinMargins);

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

Avalon_ATTR_FORWARD(safeAreaLayoutGuideTop);
Avalon_ATTR_FORWARD(safeAreaLayoutGuideBottom);
Avalon_ATTR_FORWARD(safeAreaLayoutGuideLeft);
Avalon_ATTR_FORWARD(safeAreaLayoutGuideRight);

#endif

- (AvalonViewAttribute *(^)(NSLayoutAttribute))attribute {
    return [self mas_attribute];
}

- (NSArray *)makeConstraints:(void(NS_NOESCAvalonE ^)(AvalonConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(NS_NOESCAvalonE ^)(AvalonConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(NS_NOESCAvalonE ^)(AvalonConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
