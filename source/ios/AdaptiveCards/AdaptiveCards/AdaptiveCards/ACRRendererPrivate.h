//
//  ACRRendererPrivate
//  ACRRendererPrivate.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ACRBaseCardElementRenderer.h"
#import "ACRIContentHoldingView.h"
#import "SharedAdaptiveCard.h"
#import "HostConfig.h"
#import "ACRRenderer.h"

using namespace AdaptiveCards;

@interface ACRRenderer()

+ (UIView *)renderWithAdaptiveCards:(std::shared_ptr<AdaptiveCards::AdaptiveCard> const &)adaptiveCard
                             inputs:(NSMutableArray *)inputs
                     viewController:(UIViewController *)vc
                         guideFrame:(CGRect)guideFrame
                         hostconfig:(std::shared_ptr<AdaptiveCards::HostConfig> const &)config;

+ (UIView<ACRIContentHoldingView> *)render:(UIView *)view
                        rootViewController:(UIViewController *)vc
                                    inputs:(NSMutableArray *)inputs
                             withCardElems:(std::vector<std::shared_ptr<BaseCardElement>> const &)elems
                             andHostConfig:(std::shared_ptr<HostConfig> const &)config;

+ (UIView<ACRIContentHoldingView> *)renderButton:(UIViewController *)vc
                                          inputs:(NSMutableArray *)inputs
                                       superview:(UIView<ACRIContentHoldingView> *)superview
                                     actionElems:(std::vector<std::shared_ptr<BaseActionElement>> const &)elems
                                      hostConfig:(std::shared_ptr<HostConfig> const &)config;
@end
