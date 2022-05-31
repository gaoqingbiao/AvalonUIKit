//
//  AvalonConstraintMaker.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "AvalonConstraint.h"
#import "AvalonUtilities.h"

typedef NS_OPTIONS(NSInteger, AvalonAttribute) {
    AvalonAttributeLeft = 1 << NSLayoutAttributeLeft,
    AvalonAttributeRight = 1 << NSLayoutAttributeRight,
    AvalonAttributeTop = 1 << NSLayoutAttributeTop,
    AvalonAttributeBottom = 1 << NSLayoutAttributeBottom,
    AvalonAttributeLeading = 1 << NSLayoutAttributeLeading,
    AvalonAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    AvalonAttributeWidth = 1 << NSLayoutAttributeWidth,
    AvalonAttributeHeight = 1 << NSLayoutAttributeHeight,
    AvalonAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    AvalonAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    AvalonAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    
    AvalonAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    AvalonAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#endif
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)
    
    AvalonAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    AvalonAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    AvalonAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    AvalonAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    AvalonAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    AvalonAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    AvalonAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    AvalonAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating AvalonConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface AvalonConstraintMaker : NSObject

/**
 *	The following properties return a new AvalonViewConstraint
 *  with the first item set to the makers associated view and the Avalonpropriate AvalonViewAttribute
 */
@property (nonatomic, strong, readonly) AvalonConstraint *left;
@property (nonatomic, strong, readonly) AvalonConstraint *top;
@property (nonatomic, strong, readonly) AvalonConstraint *right;
@property (nonatomic, strong, readonly) AvalonConstraint *bottom;
@property (nonatomic, strong, readonly) AvalonConstraint *leading;
@property (nonatomic, strong, readonly) AvalonConstraint *trailing;
@property (nonatomic, strong, readonly) AvalonConstraint *width;
@property (nonatomic, strong, readonly) AvalonConstraint *height;
@property (nonatomic, strong, readonly) AvalonConstraint *centerX;
@property (nonatomic, strong, readonly) AvalonConstraint *centerY;
@property (nonatomic, strong, readonly) AvalonConstraint *baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) AvalonConstraint *firstBaseline;
@property (nonatomic, strong, readonly) AvalonConstraint *lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) AvalonConstraint *leftMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *rightMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *topMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *bottomMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *leadingMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *trailingMargin;
@property (nonatomic, strong, readonly) AvalonConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) AvalonConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new AvalonCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  AvalonAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) AvalonConstraint *(^attributes)(AvalonAttribute attrs);

/**
 *	Creates a AvalonCompositeConstraint with type AvalonCompositeConstraintTypeEdges
 *  which generates the Avalonpropriate AvalonViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) AvalonConstraint *edges;

/**
 *	Creates a AvalonCompositeConstraint with type AvalonCompositeConstraintTypeSize
 *  which generates the Avalonpropriate AvalonViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) AvalonConstraint *size;

/**
 *	Creates a AvalonCompositeConstraint with type AvalonCompositeConstraintTypeCenter
 *  which generates the Avalonpropriate AvalonViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) AvalonConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstraint are created with this view as the first item
 *
 *	@return	a new MASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (AvalonConstraint * (^)(dispatch_block_t))group;

@end
