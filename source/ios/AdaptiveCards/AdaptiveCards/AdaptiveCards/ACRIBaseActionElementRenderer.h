//
//  ACRIBaseActionElementRenderer
//  ACRIBaseActionElementRenderer.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ACOHostConfig.h"
#import "ACOBaseActionElement.h"

@protocol ACRIBaseActionElementRenderer

- (UIButton* )renderButton:(UIViewController *)vc
                    inputs:(NSMutableArray *)inputs
                 superview:(UIView *)superview
         baseActionElement:(ACOBaseActionElement *)acoElem
                hostConfig:(ACOHostConfig *)acoConfig;
@end
