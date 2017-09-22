//
//  ACRViewController.m
//  ACRViewController
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRViewController.h"
#import "ACOHostConfigPrivate.h"
#import "ACOAdaptiveCardsInternal.h"
#import "SharedAdaptiveCard.h"
#import "ACRRendererInternal.h"
#import <AVFoundation/AVFoundation.h>

using namespace AdaptiveCards;

@implementation ACRViewController
{
    std::shared_ptr<AdaptiveCard> adaptiveCard;
    std::shared_ptr<HostConfig> hostConfig;
    CGRect guideFrame;
}

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if(self){
        guideFrame = CGRectMake(0, 0, 0, 0);
        hostConfig = std::make_shared<HostConfig>();
    }
    return self;
}

- (instancetype)init:(ACOAdaptiveCards *)card
          hostconfig:(ACOHostConfig *)config
               frame:(CGRect)frame
{
    self = [self initWithNibName:nil bundle:nil];
    if(self)
    {
        self->adaptiveCard = [((ACOAdaptiveCardsInternal *)card) getCard];
        hostConfig = [config getHostConfig];
        guideFrame = frame;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self render];
}

- (void)render
{
    UIView *view = self.view;
    view.frame = guideFrame;
    NSMutableArray *inputs = [[NSMutableArray alloc] init];

    UIView *newView = [ACRRendererInternal renderWithAdaptiveCards:adaptiveCard
                                                             inputs:inputs
                                                     viewController:self
                                                         guideFrame:guideFrame
                                                         hostconfig:hostConfig];

    [view addSubview:newView];

    NSLayoutConstraint *constraint =
    [NSLayoutConstraint constraintWithItem:view
                                 attribute:NSLayoutAttributeLeading
                                 relatedBy:NSLayoutRelationEqual
                                    toItem:newView
                                 attribute:NSLayoutAttributeLeading
                                multiplier:1.0
                                  constant:0];
    [view addConstraint:constraint];

    constraint =
    [NSLayoutConstraint constraintWithItem:view
                                 attribute:NSLayoutAttributeTrailing
                                 relatedBy:NSLayoutRelationEqual
                                    toItem:newView
                                 attribute:NSLayoutAttributeTrailing
                                multiplier:1.0
                                  constant:0];
    [view addConstraint:constraint];

    constraint =
    [NSLayoutConstraint constraintWithItem:view
                                 attribute:NSLayoutAttributeTop
                                 relatedBy:NSLayoutRelationLessThanOrEqual
                                    toItem:newView
                                 attribute:NSLayoutAttributeTop
                                multiplier:1.0
                                  constant:0];
    [view addConstraint:constraint];

    constraint =
    [NSLayoutConstraint constraintWithItem:view
                                 attribute:NSLayoutAttributeBottom
                                 relatedBy:NSLayoutRelationGreaterThanOrEqual
                                    toItem:newView
                                 attribute:NSLayoutAttributeBottom
                                multiplier:1.0
                                  constant:0];
    [view addConstraint:constraint];

    [NSLayoutConstraint activateConstraints:
     @[[newView.leadingAnchor constraintEqualToAnchor:view.leadingAnchor],
       [newView.topAnchor constraintEqualToAnchor:view.topAnchor]]];
}

@end
