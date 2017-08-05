//
//  ACRRenderer
//  ACRRenderer.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRRenderer.h"
#import "ACRRegistration.h"
#import "ACRBaseCardElementRenderer.h"
#import "ACRBaseActionElementRenderer.h"
#import "ACRSeparator.h"
#import "ACRIContentHoldingView.h"
#import "ACRColumnSetView.h"
#import "ACRColumnView.h"


using namespace AdaptiveCards;

@implementation ACRRenderer

+ (UIView *)renderWithAdaptiveCards:(std::shared_ptr<AdaptiveCard> const &)adaptiveCard
                             inputs:(NSMutableArray *)inputs
                     viewController:(UIViewController *)vc
                         guideFrame:(CGRect)guideFrame
                         hostconfig:(std::shared_ptr<HostConfig> const &)config
{
    std::vector<std::shared_ptr<BaseCardElement>> body = adaptiveCard->GetBody();
    
    ACRColumnView *verticalView = nil;
    
    if(!body.empty())
    {
         verticalView = [[ACRColumnView alloc] initWithFrame:CGRectMake(0, 0, guideFrame.size.width, guideFrame.size.height)];
        
        [ACRRenderer render:verticalView inputs:inputs withCardElems:body andHostConfig:config];

        std::vector<std::shared_ptr<BaseActionElement>> actions = adaptiveCard->GetActions();
        UIView<ACRIContentHoldingView> *actionChildView = [ACRRenderer renderButton:vc inputs:inputs superview:verticalView actionElems:actions hostConfig:config];
        [verticalView addArrangedSubview:actionChildView];
    }
    return verticalView;
}

+ (UIView *)renderWithJson:(NSString *)str
                    inputs:(NSArray *)inputs
            viewController:(UIViewController *)vc
                guideFrame:(CGRect)guideFrame
                hostconfig:(std::shared_ptr<HostConfig> const &)config
{
    std::shared_ptr<AdaptiveCard> adaptiveCard = AdaptiveCard::DeserializeFromString(std::string([str UTF8String]));
    return [ACRRenderer renderWithAdaptiveCards:adaptiveCard
                                         inputs:(NSMutableArray *)inputs
                                 viewController:vc
                                     guideFrame:guideFrame
                                     hostconfig:config];
}

+ (UIView<ACRIContentHoldingView> *)renderButton:(UIViewController *)vc
                                          inputs:(NSMutableArray *)inputs
                                       superview:(UIView<ACRIContentHoldingView> *)superview
                                     actionElems:(std::vector<std::shared_ptr<BaseActionElement>> const &)elems
                                      hostConfig:(std::shared_ptr<HostConfig> const &)config
{
    ACRRegistration *reg = [ACRRegistration getInstance];
    UIView<ACRIContentHoldingView> *childview = nil;
    UILayoutConstraintAxis axis = UILayoutConstraintAxisVertical;
    if(ActionsOrientation::Horizontal == config->actions.actionsOrientation)
    {
        childview = [[ACRColumnSetView alloc] initWithFrame:CGRectMake(0, 0, superview.frame.size.width, superview.frame.size.height)];
        axis = UILayoutConstraintAxisHorizontal;
    }
    else
    {
        childview = [[ACRColumnView alloc] initWithFrame:CGRectMake(0, 0, superview.frame.size.width, superview.frame.size.height)];
    }
    
    for(auto elem:elems)
    {
        ACRBaseActionElementRenderer *actionRenderer =
        [reg getActionRenderer:[NSNumber numberWithInt:(int)elem->GetElementType()]];
        
        if(actionRenderer == nil)
        {
            NSLog(@"Unsupported card action type:%d\n", (int) elem->GetElementType());
            continue;
        }
        
        UIButton* button = [actionRenderer renderButton:vc
                                                 inputs:inputs
                                              superview:superview
                                      baseActionElement:elem
                                          andHostConfig:config];
        [childview addArrangedSubview:button];
        ACRSeparator *buttonSeparation = [[ACRSeparator alloc] initWithFrame:CGRectMake(0,0,config->actions.buttonSpacing, config->actions.buttonSpacing) 
                                                               withSuperview:childview toAxis:axis];
        [childview addArrangedSubview:buttonSeparation];
    }
    
    [childview adjustHuggingForLastElement];
    
    return childview;
}

+ (UIView *)render:(UIView *)view
            inputs:(NSMutableArray *)inputs
     withCardElems:(std::vector<std::shared_ptr<BaseCardElement>> const &)elems
     andHostConfig:(std::shared_ptr<HostConfig> const &)config
{
    ACRRegistration *reg = [ACRRegistration getInstance];
    
    for(auto elem:elems)
    {
        [ACRSeparator renderSeparation:elem forSuperview:view withHostConfig:config];
        
        ACRBaseCardElementRenderer *renderer =
            [reg getRenderer:[NSNumber numberWithInt:(int)elem->GetElementType()]];
        
        if(renderer == nil)
        {
            NSLog(@"Unsupported card element type:%d\n", (int) elem->GetElementType());
            continue;
        }
        
        [renderer render:view inputs:inputs withCardElem:elem andHostConfig:config];
    }
    
    return view;
}
@end
