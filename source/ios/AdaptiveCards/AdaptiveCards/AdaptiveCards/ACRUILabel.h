//
//  ACRUILable.h
//  AdaptiveCards
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACOBaseCardElement.h"

@interface ACRUILabel:UITextView
@property ACRContainerStyle style;
@property BOOL isTitle;
@property BOOL isStretchable;
@property CGFloat area;
@property NSLayoutConstraint *widthConstraint;
@property NSLayoutConstraint *heightConstraint;

@end
