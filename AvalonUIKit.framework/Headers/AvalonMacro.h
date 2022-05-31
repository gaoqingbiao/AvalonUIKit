//
//  Macro.h
//  AvalonFrameworkDemo
//
//  Created by admin on 2022/4/26.
//

#ifndef AvalonMacro_h
#define AvalonMacro_h

#define kScreenW                        [[UIScreen mainScreen] bounds].size.width
#define kScreenH                        [[UIScreen mainScreen] bounds].size.height
#define kAutoW(a)                       kScreenW/((UIInterfaceOrientationIsPortrait(kAppInterfaceOrientation)) ? 375.0 : 667.0)*a
#define kAutoH(b)                       kScreenH/((UIInterfaceOrientationIsPortrait(kAppInterfaceOrientation)) ? 667.0 : 375.0)*b
#define kTabBarH                        self.tabBarController.tabBar.frame.size.height
#define kNavConH                        self.navigationController.navigationBar.frame.size.height

#define kStatusBarH \
\
^(){ \
    CGFloat statusBarH = 0; \
    if (@available(iOS 13.0, *)) { \
        UIWindowScene *windowScene = (UIWindowScene *)[UIApplication sharedApplication].connectedScenes.allObjects.firstObject; \
        statusBarH = windowScene.statusBarManager.statusBarFrame.size.height; \
    } else { \
       statusBarH = [[UIApplication sharedApplication] statusBarFrame].size.height; \
    } \
    return statusBarH; \
}()

#define kAppWindow \
\
^(){ \
    UIWindow *window = [UIApplication sharedApplication].delegate.window; \
    if (!window) { \
        if (@available(iOS 13.0, *)) { \
            NSArray *array =[[[UIApplication sharedApplication] connectedScenes] allObjects]; \
            UIWindowScene *windowScene = (UIWindowScene*)array[0]; \
            UIWindow *mainWindow = [windowScene valueForKeyPath:@"delegate.window"]; \
            if(mainWindow) { \
                window = mainWindow; \
            } else { \
                window = [UIApplication sharedApplication].windows.lastObject; \
            } \
        } else { \
            window = [UIApplication sharedApplication].keyWindow; \
        } \
    } \
    return window; \
}()

//屏幕方向
#define kAppInterfaceOrientation \
\
^(){ \
    UIInterfaceOrientation interfaceOrientation; \
    if (@available(iOS 13.0, *)) { \
        UIWindowScene *windowScene = (UIWindowScene *)[UIApplication sharedApplication].connectedScenes.allObjects.firstObject; \
        interfaceOrientation = windowScene.interfaceOrientation; \
    } else { \
        interfaceOrientation = [UIApplication sharedApplication].statusBarOrientation; \
    } \
    return interfaceOrientation; \
}()

#define kSecurityH                      (kSafeAreaSeries ? (UIInterfaceOrientationIsPortrait(kAppInterfaceOrientation) ? 34.0 : 21.0) : 0)//底部安全高度

#define kSafeAreaSeries \
\
^(){ \
    if (@available(iOS 11.0, *)) { \
        CGFloat bottomSafeInset = kAppWindow.safeAreaInsets.bottom; \
        if (bottomSafeInset == 34.0 || bottomSafeInset == 21.0) { \
            return YES; \
        } \
    } \
    return NO; \
}()

// 判断是否是 iphone 4
#define isIPhone4 CGSizeEqualToSize(CGSizeMake(320, 480), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone 5 / 5s / SE
#define isIPhone5_5s_SE CGSizeEqualToSize(CGSizeMake(320, 568), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone 6 / 6s / 7 / 8
#define isIPhone6_6s_7_8 CGSizeEqualToSize(CGSizeMake(375, 667), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone 6 Plus / 6s Plus / 7 Plus / 8 Plus
#define isIPhone6p_6sp_7p_8p CGSizeEqualToSize(CGSizeMake(414, 736), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone X / Xs / 11 Pro /  12 mini
#define isIPhoneX_Xs_11Pro_12Mini CGSizeEqualToSize(CGSizeMake(375, 812), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone Xs Max / XR / 11 / 11 Pro Max
#define isIPhoneXsMax_XR_11_11ProMax CGSizeEqualToSize(CGSizeMake(414, 896), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone 12 / 12 Pro
#define isIPhone12_12Pro CGSizeEqualToSize(CGSizeMake(390, 844), [[UIScreen mainScreen] bounds].size)
// 判断是否是 iphone 12 Pro Max
#define isIPhone12ProMax CGSizeEqualToSize(CGSizeMake(428, 926), [[UIScreen mainScreen] bounds].size)

// 是否是 刘海儿屏/异形屏
#define isAlien  ([UIScreen mainScreen].bounds.size.height > 736 ? YES : NO)


#define kRGBColorAlpha(a,b,c,d)         [UIColor colorWithRed:a/255.0 green:b/255.0 blue:c/255.0 alpha:d]
#define kRGBColor(a,b,c)                kRGBColorAlpha(a,b,c,1.0)
//16位颜色值，使用方式：UIColorFromHexString(0xffffff)
#define AvalonRGBHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define AvalonRGBHexAlpha(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]

//#define kUIColorFromHexString(hexValue)       [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue &0xFF00) >>8))/255.0 blue:((float)(hexValue &0xFF))/255.0 alpha:1.0]
#define kRandomColor                    kRGBColor(arc4random() % 256, arc4random() % 256, arc4random() % 256)  //随机色
//UIColor转UIImage
#define kCreateImageForColor(color) \
\
^(){ \
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f); \
    UIGraphicsBeginImageContext(rect.size); \
    CGContextRef context = UIGraphicsGetCurrentContext(); \
    CGContextSetFillColorWithColor(context, [color CGColor]); \
    CGContextFillRect(context, rect); \
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext(); \
    UIGraphicsEndImageContext(); \
    return theImage; \
}()

//字号
#define kFontWeight(size,fontWeight) \
\
^(){ \
    CGFloat fontSize = size; \
    if (kBelowIPhone5Series) { \
        fontSize --; \
    } else { \
        fontSize = size; \
    } \
    return [UIFont systemFontOfSize:fontSize weight:fontWeight]; \
}()

#define kFontSize(size) \
\
^(){ \
    CGFloat fontSize = size; \
    if (kBelowIPhone5Series) { \
        fontSize --; \
    } else { \
        fontSize = size; \
    } \
    return fontSize; \
}()

#define kFontHeavy(size)                kFontWeight(size,UIFontWeightHeavy)
#define kFontBold(size)                 kFontWeight(size,UIFontWeightBold)
#define kFontRegular(size)              kFontWeight(size,UIFontWeightRegular)
#define kFontMedium(size)               kFontWeight(size,UIFontWeightMedium)
#define kFontThin(size)                 kFontWeight(size,UIFontWeightThin)

//拼接字符串
#define kNSStringFormat(format,...)     [NSString stringWithFormat:format,##__VA_ARGS__]
//检测是否含有目标子串
#define kHasString(string,subString)    ([string rangeOfString:subString].location != NSNotFound)

#ifdef DEBUG
#define KAVLog(fmt, ...)                NSLog((@"[文件名:%s]\n" "[函数名:%s]\n" "[行号:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define KAVLog(...)
#endif

//强弱引用
#define kWeakSelf(type)                 __weak typeof(type) weak##type = type;
#define kStrongSelf(type)               __strong typeof(type) type = weak##type;

//当前系统版本
#define kCurrentSystemVersion           [[UIDevice currentDevice].systemVersion doubleValue]
//当前语言
#define kCurrentSystemLanguage          [[NSLocale preferredLanguages] objectAtIndex:0]
//app版本
#define kCurrentAppVersion              [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//app名称
#define kCurrentAppName                 [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"]

//沙盒目录路径
#define kHomePath                       NSHomeDirectory()
#define kTemPath                        NSTemporaryDirectory()
#define kCachePath                      NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject
#define kLibraryPath                    NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject
#define kDocumentPath                   NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject

//判断是否为iPhone
#define IS_IPHONE                       ([[[UIDevice currentDevice] model] isEqualToString:@"iPhone"])
//判断是否为iPad
#define IS_IPAD                         ([[[UIDevice currentDevice] model] isEqualToString:@"iPad"])
//判断是否为iPod touch
#define IS_IPOD                         ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

//打印方法运行时间
#define METHOD_TIME_BEGIN               NSDate * startTime = [NSDate date];
#define METHOD_TIME_END                 KAVLog(@"time interval: %f", -[startTime timeIntervalSinceNow]);

//监听通知
#define kNotifyAdd(noParamsFunc, notifyName)  [[NSNotificationCenter defaultCenter] \
addObserver:self \
selector:@selector(noParamsFunc) \
name:notifyName \
object:nil];
//发送通知
#define kNotifyPost(notifyName,obj)     [[NSNotificationCenter defaultCenter] postNotificationName:notifyName object:obj];
//移除通知
#define kNotifyRemove(notifyName)       [[NSNotificationCenter defaultCenter] removeObserver:self name:notifyName object:nil];


#endif /* AvalonMacro_h */
