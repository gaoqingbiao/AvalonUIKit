//
//  AvalonLabel.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonLabel : UILabel

/// 根据文本宽度计算高度
/// @param text 文本
/// @param width 宽度
/// @param font 字体大小
+ (CGFloat)getLabelHeightWithText:(NSString *)text width:(CGFloat)width font:(CGFloat)font;

/// 根据文本高度计算宽度
/// @param text 文本
/// @param height 高度
/// @param font 字体大小
+ (CGFloat)getWidthWithText:(NSString *)text height:(CGFloat)height font:(CGFloat)font;


@end

NS_ASSUME_NONNULL_END
