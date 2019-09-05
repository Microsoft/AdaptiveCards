//
//  ACRLongPressGestureRecognizerFactory
//  ACRLongPressGestureRecognizerFactory.mm
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import "ACRLongPressGestureRecognizerFactory.h"
#import "OpenUrlAction.h"
#import "ACRShowCardTarget.h"
#import "ACRToggleVisibilityTarget.h"
#import "ShowCardAction.h"
#import "SubmitAction.h"
#import "ToggleVisibilityAction.h"
#import "ACRAggregateTarget.h"
#import "ACOBaseActionElementPrivate.h"
#import "ACRUILabel.h"
#import "Util.h"

using namespace AdaptiveCards;

@implementation ACRLongPressGestureRecognizerFactory

+ (void)addLongPressGestureRecognizerToUIView:(UIView<ACRIContentHoldingView> *)viewGroup
                                     rootView:(ACRView *)rootView
                                recipientView:(UIView *)recipientView
                                actionElement:(std::shared_ptr<BaseActionElement> const &)action
                                   hostConfig:(ACOHostConfig *)config
{
    if(action != nullptr){
        NSObject<ACRSelectActionDelegate> *target;
        if (ACRRenderingError::ACROk == buildTarget(rootView, action, &target, ACRSelectAction) && viewGroup) {
            UILongPressGestureRecognizer *recognizer = [ACRLongPressGestureRecognizerFactory getGestureRecognizer:viewGroup target:target];
            [recipientView addGestureRecognizer:recognizer];
            recipientView.userInteractionEnabled = YES;
        }
    }
}

+ (void)addTapGestureRecognizerToUITextView:(UITextView *)textView
                                     target:(NSObject<ACRSelectActionDelegate> *)target
                                   rootView:(ACRView *)rootView
                                 hostConfig:(ACOHostConfig *)config
{
    if(target && textView){
        UITapGestureRecognizer *recognizer = [[UITapGestureRecognizer alloc] initWithTarget:textView action:@selector(handleInlineAction:)];
        [textView addGestureRecognizer:recognizer];
        textView.userInteractionEnabled = YES;
    }
}

+ (UILongPressGestureRecognizer *)getGestureRecognizer:(UIView<ACRIContentHoldingView> *)viewGroup
                                                target:(NSObject<ACRSelectActionDelegate> *)target
{
    ACRLongPressGestureRecognizerEventHandler *handler = [[ACRLongPressGestureRecognizerEventHandler alloc] init];
    // add the target to the viewGroup; life time of the target is as long as the viewGroup
    // add the handler to the viewGroup; life time of the target is as long as the viewGroup
    [viewGroup addTarget:target];
    [viewGroup addTarget:handler];
    UILongPressGestureRecognizer *recognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:handler action:@selector(processLongPressGesture:)];
    handler.delegate = target;
    recognizer.delegate = handler;
    recognizer.minimumPressDuration = 0.01;
    recognizer.allowableMovement = 1;
    return recognizer;
}

@end
