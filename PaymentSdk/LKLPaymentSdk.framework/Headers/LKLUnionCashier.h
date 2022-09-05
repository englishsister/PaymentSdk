//
//  LKLUnionCashier.h
//  lklPaySdk
//
//  Created by haoyingjie on 2022/9/5.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKLUnionCashier : NSObject
+ (instancetype)shareInstanceWithWebView:(WKWebView*)webview;
/**
 *  支付接口
 *
 *  @param tn             订单信息
 *  @param schemeStr      调用支付的app注册在info.plist中的scheme
 *  @param mode           支付环境
 *  @param viewController 启动支付控件的viewController
 *  @return 返回成功失败 YES：调起支付控件成功； NO：调起支付控件失败；
 */

+(BOOL)startPay:(NSString*)tn
      fromScheme:(NSString *)schemeStr
            mode:(NSString*)mode
  viewController:(UIViewController*)viewController;

//获取手机品牌
+(NSString *)mobileBrand;

+ (void)handlePaymentResult:(NSURL*)url;
@end

NS_ASSUME_NONNULL_END
