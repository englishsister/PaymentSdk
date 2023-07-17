# PaymentSdk
收银台

#收银台支付控件接入指南
使用方法cocoapods引入
  pod 'LKLPaymentSdk'
  
##工程配置
1.在工程 info.plist 设置中添加一个 URL Types 回调协议，用于在支付完成后返回商户客户端。请注意 URL Schemes 需要是唯一的。
2.http 请求设置（ats）
在测试环境测试时，需要在工程对应的 plist 文件中添加 NSAppTransportSecurity Dictionary 并同时设置里面 NSAllowsArbitraryLoads 属性值为 YES
发生产环境可删除此设置。向 Apple 发布正式版本时请删除此设置。
3.

##使用方法
在需要调用支付控件接口的代码文件内引用头文件 
import <LKLPaymentSdk/UPPaymentControl.h>
注意：（注意：如果工程的 compile source as 选项的值不是 Objective–C++，则引用此头文件的文件类型都要改为.mm）


调用支付接口
/**
 *  支付接口
 *
 *  @param tn             订单信息
 *  @param schemeStr      调用支付的app注册在info.plist中的scheme
 *  @param mode           支付环境
 *  @param viewController 启动支付控件的viewController
 *  @return 返回成功失败
 */
- (BOOL)startPay:(NSString*)tn
      fromScheme:(NSString *)schemeStr
            mode:(NSString*)mode
  viewController:(UIViewController*)viewController;
  
  1.使用方法
    [[UPPaymentControl defaultControl]startPay:data[@"tn"] fromScheme:@"lklPayDemo" mode:data[@"serverMode"] viewController:self];
2.返回结果接口调用
支付控件结果处理函数handlePaymentResult: completeBlock:需要在工程 AppDelegate文件的application: openURL: options: 方法中进行调用。 支付控件结果处理函数handlePaymentResult: completeBlock:包含两个参数，参 数1 url为支付结果串，由handlePaymentResult: completeBlock:方法解析url内容； 参数2 completionBlock为商户APP定义的结果处理方法，包含两个传入参数code和 data，其中code表示支付结果，取值为suceess、fail、cancel分别表示支付成功、支 付失败、支付取消。data字段为保留字段，目前请忽略
控件返回的结果信息仅作为参考，商户订单是否成功支付应该以商户后台主动到全 渠道查询的结果或者收到全渠道支付结果通知为准。 收到控件返回结果后，建议直接到自己的后台查状态，如果后台此时未收到全渠道 的后台通知，则主动发起查询接口到全渠道查状态。这样可既保证APP中展示的订单状 态和后台记录一致，也可及时更新后台记录的订单状态。 调用支付接口后，结果处理方法示例代码：
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    [[UPPaymentControl defaultControl] handlePaymentResult:url completeBlock:^(NSString *code, NSDictionary *data) {
    if([code isEqualToString:@"success"]) { //结果code为成功时，去商户后台查询一下确保交易是成功的再展示成功
        
    }else if([code isEqualToString:@"fail"]) { //交易失败
        
    }else if([code isEqualToString:@"cancel"]) { //交易取消
        
    }
    }];
    return YES;
}
    
    


