//
//  ACRToggleVisibilityTarget
//  ACRToggleVisibilityTarget.mm
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import "ACRToggleVisibilityTarget.h"
#import "ACRRendererPrivate.h"
#import "ACOHostConfigPrivate.h"
#import "ACOBaseActionElementPrivate.h"
#import "ACRView.h"
#import "BaseActionElement.h"
#import "ToggleVisibilityTarget.h"

@implementation ACRToggleVisibilityTarget
{
    ACOHostConfig *_config;
    __weak ACRView *_rootView;
    std::unique_ptr<ToggleVisibilityAction> _action;
}

- (instancetype)initWithActionElement:(std::shared_ptr<AdaptiveCards::ToggleVisibilityAction> const &)actionElement
                              config:(ACOHostConfig *)config
                            rootView:(ACRView *)rootView
{
    self = [super init];
    if(self)
    {
        _config = config;
        _rootView = rootView;
        _action = std::make_unique<ToggleVisibilityAction>(*(actionElement.get()));
    }
    return self;
}

- (void)doSelectAction
{
    for(const auto &target : _action->GetTargetElements()) {
        NSString *hashString = [NSString stringWithCString:target->GetElementId().c_str() encoding:NSUTF8StringEncoding];
        NSUInteger tag = hashString.hash;
        UIView *view = [_rootView viewWithTag:tag];

        if(target->GetIsVisible() == AdaptiveCards::IsVisibleToggle){
            view.hidden = !(view.hidden);
        } else if(target->GetIsVisible() == AdaptiveCards::IsVisibleTrue) {
            view.hidden = NO;
        } else {
            view.hidden = YES;
        }
    }
}

@end
