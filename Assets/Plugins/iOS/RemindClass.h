#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//----------------------------------------------------------------------
// remind program from samurai-apps
// http://samurai-apps.com/2012/04/07/%E3%80%90ios%E3%80%91%E8%B5%B7%E5%8B%95%E6%99%82%E3%81%ABuialert%E3%82%92%E5%87%BA%E3%81%97%E3%81%A6%E8%A9%95%E4%BE%A1%E3%83%9A%E3%83%BC%E3%82%B8%E3%81%AB%E9%A3%9B%E3%81%B0%E3%81%99/
//----------------------------------------------------------------------

@interface RemindClass : NSObject<UIAccelerometerDelegate, UIApplicationDelegate>

+ (void)check;
+ (void)action;
+ (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

@end

//----------------------------------------------------------------------
@implementation RemindClass

+ (void)check
{
    //userdefaults
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    NSInteger executeTime = [userDefaults integerForKey: @"executeTime"];
    NSInteger isLate = [userDefaults integerForKey: @"isLate"];
    executeTime++;
    [userDefaults setInteger:executeTime forKey: @"executeTime"];
    //reset
    BOOL reset = NO;
    if (reset) {
        isLate = 0;
        [userDefaults setInteger:isLate forKey: @"isLate"];
    }
    [userDefaults synchronize];
    
    //check
    if (executeTime > 3 && isLate == 0) [self action];
}

+ (void)action
{
    UIAlertView *alert = [[UIAlertView alloc] init];
    alert.delegate = self;
    alert.title = @"評価のお願い";
    alert.message = @"いつもご利用ありがとうございます。評価のご協力をお願いいたします。";
    [alert addButtonWithTitle:@"今すぐ評価する"];
    [alert addButtonWithTitle:@"あとで"];
    [alert addButtonWithTitle:@"評価しない"];
    [alert show];
}

+ (void)alertView:(UIAlertView*)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSString *appid = @"000000000";
    NSString *url = [NSString stringWithFormat:@"%@%@%@",@"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=",appid,@"&onlyLatestVersion=true&pageNumber=0&sortOrdering=1&type=Purple+Software"];

    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    switch (buttonIndex) {
        case 0:
            //go to rate page
            [userDefaults setInteger:1 forKey: @"isLate"];
            [userDefaults synchronize];
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
            break;
        case 1:
            [userDefaults setInteger:0 forKey: @"executeTime"];
            [userDefaults synchronize];
            break;
        case 2:
            [userDefaults setInteger:1 forKey: @"isLate"];
            [userDefaults synchronize];
            break;
    }
}

//----------------------------------------------------------------------

@end
