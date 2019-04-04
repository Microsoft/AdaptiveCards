//
//  Util.h
//  Util
//
//  Copyfight © 2019 Microsoft. All rights reserved.
//

#import<UIKit/UIKit.h>
#import "ACRViewPrivate.h"
#import "BaseCardElement.h"
#import "CollectionTypeElement.h"

void configVisibility(UIView *view, std::shared_ptr<AdaptiveCards::BaseCardElement> const &visibilityInfo);

void configBleed(ACRView *rootView, std::shared_ptr<BaseCardElement> const &elem, ACRContentStackView *container, ACOHostConfig *acoConfig);

void renderBackgroundImageView(const BackgroundImage *backgroundImageProperties, UIView *containerView, ACRView *rootView);

void applyBackgroundImageConstraints(const BackgroundImage *backgroundImageProperties, UIImageView *imageView);
