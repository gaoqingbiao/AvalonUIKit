//
//  NSArray+MASAdditions.h
//
//
//  Created by Daniel Hammond on 11/26/13.
//
//

#import "AvalonUtilities.h"
#import "AvalonConstraintMaker.h"
#import "AvalonViewAttribute.h"

typedef NS_ENUM(NSUInteger, AvalonAxisType) {
    AvalonAxisTypeHorizontal,
    AvalonAxisTypeVertical
};

@interface NSArray (AvalonAdditions)

/**
 *  Creates a AvalonConstraintMaker with each view in the callee.
 *  Any constraints defined are added to the view or the Avalonpropriate superview once the block has finished executing on each view
 *
 *  @param block scope within which you can build up the constraints which you wish to Avalonply to each view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)mas_makeConstraints:(void (NS_NOESCAPE ^)(AvalonConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with each view in the callee.
 *  Any constraints defined are added to each view or the Avalonpropriate superview once the block has finished executing on each view.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to Avalonply to each view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_updateConstraints:(void (NS_NOESCAPE ^)(AvalonConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with each view in the callee.
 *  Any constraints defined are added to each view or the Avalonpropriate superview once the block has finished executing on each view.
 *  All constraints previously installed for the views will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to Avalonply to each view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_remakeConstraints:(void (NS_NOESCAPE ^)(AvalonConstraintMaker *make))block;

/**
 *  distribute with fixed spacing
 *
 *  @param axisType     which axis to distribute items along
 *  @param fixedSpacing the spacing between each item
 *  @param leadSpacing  the spacing before the first item and the container
 *  @param tailSpacing  the spacing after the last item and the container
 */
- (void)mas_distributeViewsAlongAxis:(AvalonAxisType)axisType withFixedSpacing:(CGFloat)fixedSpacing leadSpacing:(CGFloat)leadSpacing tailSpacing:(CGFloat)tailSpacing;

/**
 *  distribute with fixed item size
 *
 *  @param axisType        which axis to distribute items along
 *  @param fixedItemLength the fixed length of each item
 *  @param leadSpacing     the spacing before the first item and the container
 *  @param tailSpacing     the spacing after the last item and the container
 */
- (void)mas_distributeViewsAlongAxis:(AvalonAxisType)axisType withFixedItemLength:(CGFloat)fixedItemLength leadSpacing:(CGFloat)leadSpacing tailSpacing:(CGFloat)tailSpacing;

@end
