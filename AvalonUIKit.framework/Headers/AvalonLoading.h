//
//  AvalonLoading.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/20.
//

#import <AvalonUIKit/AvalonUIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonLoading : NSObject

//loading 图片
@property(nonatomic ,copy) NSString *loadingImg;

+ (instancetype)loading;

/// 显示loading
+ (void)showLoading;

/// 隐藏loading
+ (void)hiddenLoading;

@end

NS_ASSUME_NONNULL_END
