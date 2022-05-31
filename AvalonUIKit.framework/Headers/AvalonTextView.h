//
//  AvalonTextView.h
//  AvalonUIKit
//
//  Created by admin on 2022/5/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AvalonTextView : UITextView

// 是否进行多语言适配
@property (nonatomic ,assign) BOOL isNation;
// 协议
@property (nonatomic ,copy) NSString *textString;
// 协议
@property (nonatomic ,copy) NSString *agreement;
// 隐私
@property (nonatomic ,copy) NSString *privacy;
// linkTextColor
@property (nonatomic ,strong) UIColor *linkTextColor;

@end

NS_ASSUME_NONNULL_END
