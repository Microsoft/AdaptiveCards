//
//  ACOBaseCardElementPrivate
//  ACOBaseCardElementPrivate.h
//
//  Copyright © 2018 Microsoft. All rights reserved.
//
#import "ACOBaseCardElement.h"
#import "BaseCardElement.h"

using namespace AdaptiveCards;

@interface ACOBaseCardElement()

- (std::shared_ptr<BaseCardElement>)getElem;
- (void)setElem:(std::shared_ptr<BaseCardElement> const &)elem;

@end
