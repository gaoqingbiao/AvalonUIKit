//
//  AvalonBundle.h
//  AvalonFoundation
//
//  Created by admin on 2022/5/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonBundle : NSBundle


/// 国际化语言
/// @param key key
+ (NSString*)internationTextFromLanguageBundleKey:(NSString*)key;

/// 本地图片
/// @param imageName 图片名称
+ (UIImage *)imageFromBundleImageName:(NSString*)imageName;

/// bundle 中的json 文件
/// @param fileName 文件名
+ (NSDictionary *)jsonFromBundleFileName:(NSString *)fileName;


@end

NS_ASSUME_NONNULL_END
