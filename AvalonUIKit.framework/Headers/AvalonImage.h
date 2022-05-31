//
//  AvalonImage.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonImage : UIImage

/// 获取本地图片
/// @param name 图片名称
+(AvalonImage *)initImageWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
