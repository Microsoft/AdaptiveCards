//
//  ACROpenURLTarget
//  ACROpenURLTarget.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//
#import <SafariServices/SafariServices.h>
#import <UIKit/UIKit.h>
#import "ACRLongPressGestureRecognizerEventHandler.h"

@interface ACROpenURLTarget:NSObject<SFSafariViewControllerDelegate, ACRSelectActionDelegate>

- (instancetype)initWithURL:(NSURL *)url viewController:(UIViewController *)vc;

- (IBAction)openURL;

@end
