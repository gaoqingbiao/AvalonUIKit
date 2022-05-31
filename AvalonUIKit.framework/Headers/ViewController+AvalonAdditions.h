//
//  UIViewController+AvalonAdditions.h
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "AvalonUtilities.h"
#import "AvalonConstraintMaker.h"
#import "AvalonViewAttribute.h"

#ifdef Avalon_VIEW_CONTROLLER

@interface Avalon_VIEW_CONTROLLER (AvalonAdditions)

/**
 *	following properties return a new MASViewAttribute with Avalonpropriate UILayoutGuide and NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_topLayoutGuide;
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_bottomLayoutGuide;
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_topLayoutGuideTop;
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_topLayoutGuideBottom;
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_bottomLayoutGuideTop;
@property (nonatomic, strong, readonly) AvalonViewAttribute *mas_bottomLayoutGuideBottom;


@end

#endif
