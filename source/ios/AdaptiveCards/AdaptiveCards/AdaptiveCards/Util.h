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
#import "TextElementProperties.h"
#import "ACRErrors.h"

using namespace AdaptiveCards;

void configVisibility(UIView *view, std::shared_ptr<BaseCardElement> const &visibilityInfo);

void configBleed(ACRView *rootView, std::shared_ptr<BaseCardElement> const &elem, ACRContentStackView *container, ACOHostConfig *acoConfig);

void renderBackgroundImage(const std::shared_ptr<BackgroundImage> backgroundImageProperties, UIView *containerView, ACRView *rootView);

void renderBackgroundImage(const BackgroundImage *backgroundImageProperties, UIImageView *imageView, UIImage *img);

void applyBackgroundImageConstraints(const BackgroundImage *backgroundImageProperties, UIImageView *imageView, UIImage *img);

ObserverActionBlock generateBackgroundImageObserverAction(std::shared_ptr<BackgroundImage> backgroundImageProperties, ACRView *observer, std::shared_ptr<BaseCardElement> const &context);

UIFontDescriptor *getItalicFontDescriptor(UIFontDescriptor *descriptor, bool isItalic);

void handleFallbackException(ACOFallbackException *exception, 
                             UIView<ACRIContentHoldingView> *view,
                             ACRView *rootView, 
                             NSMutableArray *inputs,
                             std::shared_ptr<BaseCardElement> const &elem,
                             ACOHostConfig *config);
void handleActionFallbackException(ACOFallbackException *exception,
                                   UIView<ACRIContentHoldingView> *view,
                                   ACRView *rootView,
                                   NSMutableArray *inputs,
                                   ACOBaseActionElement *acoElem,
                                   ACOHostConfig *config,
                                   UIView<ACRIContentHoldingView> *actionSet);

void removeLastViewFromCollectionView(const CardElementType elemType, UIView<ACRIContentHoldingView> *view);
