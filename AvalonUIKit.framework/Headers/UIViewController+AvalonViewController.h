//
//  UIViewController+AvalonViewController.h
//  AvalonSuperSDK
//
//  Created by admin on 2022/4/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (AvalonViewController)

// 获取当前显示的 UIViewController
+ (UIViewController *)avalon_findCurrentShowingViewController;

/// 获取keyWindow
+ (UIWindow *)getKeyWindow;

@end

NS_ASSUME_NONNULL_END
