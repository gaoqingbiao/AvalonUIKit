//
//  MASConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "AvalonUtilities.h"

/**
 *	Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (MASViewConstraint) 
 *  or a group of NSLayoutConstraints (MASComposisteConstraint)
 */
@interface AvalonConstraint : NSObject

// Chaining Support

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (AvalonConstraint * (^)(AvalonEdgeInsets insets))insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (AvalonConstraint * (^)(CGFloat inset))inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (AvalonConstraint * (^)(CGSize offset))sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (AvalonConstraint * (^)(CGPoint offset))centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (AvalonConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
- (AvalonConstraint * (^)(NSValue *value))valueOffset;

/**
 *	Sets the NSLayoutConstraint multiplier property
 */
- (AvalonConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *	Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
- (AvalonConstraint * (^)(CGFloat divider))dividedBy;

/**
 *	Sets the NSLayoutConstraint priority to a float or AvalonLayoutPriority
 */
- (AvalonConstraint * (^)(AvalonLayoutPriority priority))priority;

/**
 *	Sets the NSLayoutConstraint priority to AvalonLayoutPriorityLow
 */
- (AvalonConstraint * (^)(void))priorityLow;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityMedium
 */
- (AvalonConstraint * (^)(void))priorityMedium;

/**
 *	Sets the NSLayoutConstraint priority to AvalonLayoutPriorityHigh
 */
- (AvalonConstraint * (^)(void))priorityHigh;

/**
 *	Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    AvalonViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (AvalonConstraint * (^)(id attr))equalTo;

/**
 *	Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    AvalonViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (AvalonConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *	Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    AvalonViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (AvalonConstraint * (^)(id attr))lessThanOrEqualTo;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (AvalonConstraint *)with;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (AvalonConstraint *)and;

/**
 *	Creates a new AvalonCompositeConstraint with the called attribute and reciever
 */
- (AvalonConstraint *)left;
- (AvalonConstraint *)top;
- (AvalonConstraint *)right;
- (AvalonConstraint *)bottom;
- (AvalonConstraint *)leading;
- (AvalonConstraint *)trailing;
- (AvalonConstraint *)width;
- (AvalonConstraint *)height;
- (AvalonConstraint *)centerX;
- (AvalonConstraint *)centerY;
- (AvalonConstraint *)baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

- (AvalonConstraint *)firstBaseline;
- (AvalonConstraint *)lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

- (AvalonConstraint *)leftMargin;
- (AvalonConstraint *)rightMargin;
- (AvalonConstraint *)topMargin;
- (AvalonConstraint *)bottomMargin;
- (AvalonConstraint *)leadingMargin;
- (AvalonConstraint *)trailingMargin;
- (AvalonConstraint *)centerXWithinMargins;
- (AvalonConstraint *)centerYWithinMargins;

#endif


/**
 *	Sets the constraint debug name
 */
- (AvalonConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of Avalon_updateConstraints/Avalon_makeConstraints blocks

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(AvalonEdgeInsets)insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInset:(CGFloat)inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects AvalonConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;


// NSLayoutConstraint Installation support

#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)
/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
@property (nonatomic, copy, readonly) AvalonConstraint *animator;
#endif

/**
 *  Activates an NSLayoutConstraint if it's supported by an OS. 
 *  Invokes install otherwise.
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
- (void)deactivate;

/**
 *	Creates a NSLayoutConstraint and adds it to the Avalonpropriate view.
 */
- (void)install;

/**
 *	Removes previously installed NSLayoutConstraint
 */
- (void)uninstall;

@end


/**
 *  Convenience auto-boxing macros for AvalonConstraint methods.
 *
 *  Defining Avalon_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will Avalonpear in global scope.
 */
#define mas_equalTo(...)                 equalTo(AvalonBoxValue((__VA_ARGS__)))
#define mas_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(AvalonBoxValue((__VA_ARGS__)))
#define mas_lessThanOrEqualTo(...)       lessThanOrEqualTo(AvalonBoxValue((__VA_ARGS__)))

#define mas_offset(...)                  valueOffset(AvalonBoxValue((__VA_ARGS__)))


#ifdef Avalon_SHORTHAND_GLOBALS

#define equalTo(...)                     mas_equalTo(__VA_ARGS__)
#define greaterThanOrEqualTo(...)        mas_greaterThanOrEqualTo(__VA_ARGS__)
#define lessThanOrEqualTo(...)           mas_lessThanOrEqualTo(__VA_ARGS__)

#define offset(...)                      mas_offset(__VA_ARGS__)

#endif


@interface AvalonConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
- (AvalonConstraint * (^)(id attr))mas_equalTo;
- (AvalonConstraint * (^)(id attr))mas_greaterThanOrEqualTo;
- (AvalonConstraint * (^)(id attr))mas_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
- (AvalonConstraint * (^)(id offset))mas_offset;

@end
