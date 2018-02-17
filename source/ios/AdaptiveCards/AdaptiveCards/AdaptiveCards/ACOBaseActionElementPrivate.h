//
//  ACOBaseCardElementPrivate
//  ACOBaseCardElementPrivate.h
//
//  Copyright © 2018 Microsoft. All rights reserved.
//
#import "ACOBaseActionElement.h"
#import "BaseCardElement.h"

using namespace AdaptiveCards;

@interface ACOBaseActionElement()

- (std::shared_ptr<BaseActionElement>)getElem;
- (void)setElem:(std::shared_ptr<BaseActionElement> const &)elem;

@end    
