//
//  ACRView.h
//  ACRView
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ACRActionDelegate.h"
#import "ACOAdaptiveCard.h"
#import "ACOHostConfig.h"
#import "ACRColumnView.h"

@interface ACRView:ACRColumnView

@property (weak) id<ACRActionDelegate>acrActionDelegate;
@property BOOL seenAllElements;

- (instancetype)init:(ACOAdaptiveCard *)card
          hostconfig:(ACOHostConfig *)config
     widthConstraint:(float)width
adaptiveCardDelegate:(id<ACRActionDelegate>)delegate;

- (NSMutableDictionary *)getImageMap;

- (dispatch_queue_t)getSerialQueue;

- (NSMutableDictionary *)getTextMap;

- (NSMutableDictionary *)getActionsMap;

- (dispatch_queue_t)getSerialTextQueue;

- (ACOAdaptiveCard *)card;

- (UIView *)render;

- (void)callDidLoadElementsIfNeeded;

+ (void) setImageView:(UIImageView*)imageView inButton:(UIButton*)button withConfig:(ACOHostConfig *)config;
@end
