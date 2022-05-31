//
//  AvalonButton.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/13.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AvalonButtonStyle) {
    AvalonButtonImageLeft,
    AvalonButtonImageRight,
    AvalonButtonImageTop,
    AvalonButtonImageBottom,
};

@interface AvalonButton : UIButton

// 是否进行多语言适配
@property (nonatomic ,assign) BOOL isNation;
// 下划线颜色
@property (nonatomic ,strong) UIColor *underlineColor;
// 下划线字体颜色
@property (nonatomic ,strong) UIColor *underlineTextColor;
// 下划线文字
@property (nonatomic ,copy) NSString *underlineText;


/// button常规
/// @param title 文字
/// @param status 状态
/// @param titleColor 文字颜色
- (void)setTitle:(NSString *)title status:(UIControlState)status titleColor:(UIColor *)titleColor;

/// 设置按钮图片
/// @param imageName 图片名称
/// @param status 状态
- (void)setImageName:(NSString *)imageName status:(UIControlState)status;

/// 按钮图片位置
/// @param type 样式
/// @param padding 文字和图片的距离
- (void)setButtonWithType:(AvalonButtonStyle)type padding:(CGFloat)padding;



@end

NS_ASSUME_NONNULL_END
