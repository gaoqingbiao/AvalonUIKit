//
//  AvalonColor.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonColor : UIColor


//设置RGB颜色
+ (UIColor *)red:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(CGFloat)alpha;
//将颜色转换成RGB
+ (NSArray *)convertColorToRGB:(UIColor *)color;
//设置十六进制颜色
+ (UIColor *)colorWithHex:(NSInteger)hex;
+ (UIColor*)colorWithHexString:(NSString *)hexString;

@end

NS_ASSUME_NONNULL_END
