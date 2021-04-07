//
//  ACRActionDelegate
//  ACRActionDelegate.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACOAdaptiveCard.h"
#import "ACOBaseActionElement.h"
#import <Foundation/Foundation.h>

@class ACROverflowMenuItem;
@class ACROverflowTarget;

@protocol ACRActionDelegate <NSObject>

- (void)didFetchUserResponses:(ACOAdaptiveCard *)card action:(ACOBaseActionElement *)action;

@optional
- (void)didLoadElements;
- (void)didChangeVisibility:(UIButton *)button isVisible:(BOOL)isVisible;
- (void)didChangeViewLayout:(CGRect)oldFrame newFrame:(CGRect)newFrame;
- (void)didChangeViewLayout:(CGRect)oldFrame newFrame:(CGRect)newFrame properties:(NSDictionary *)properties;

// for overflow actions
- (BOOL)shouldAllowMoreThanMaxActionsInOverflowMenu;
- (BOOL)shouldRenderOverflowActionButton:(UIButton *)button
                               forTarget:(ACROverflowTarget *)target
                    isAtRootLevelActions:(BOOL)isAtRootLevelActions;
- (void)displayOverflowActionMenu:(NSArray<ACROverflowMenuItem*> *)menuItems
                  alertController:(UIAlertController *)alert;
@end
