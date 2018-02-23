//
//  ACRColumnRenderer
//  ACRColumnRenderer.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRColumnRenderer.h"
#import "ACRColumnView.h"
#import "ACRRendererPrivate.h"
#import "Column.h"
#import "SharedAdaptiveCard.h"
#import "ACRLongPressGestureRecognizerFactory.h"
#import "ACOHostConfigPrivate.h"
#import "ACOBaseCardElementPrivate.h"

@implementation ACRColumnRenderer

+ (ACRColumnRenderer *)getInstance
{
    static ACRColumnRenderer *singletonInstance = [[self alloc] init];
    return singletonInstance;
}

+ (CardElementType)elemType
{
    return CardElementType::Column;
}

- (UIView *)render:(UIView<ACRIContentHoldingView> *)viewGroup
            rootViewController:(UIViewController *)vc
            inputs:(NSMutableArray *)inputs
   baseCardElement:(ACOBaseCardElement *)acoElem
        hostConfig:(ACOHostConfig *)acoConfig;
{

    std::shared_ptr<HostConfig> config = [acoConfig getHostConfig];
    std::shared_ptr<BaseCardElement> elem = [acoElem element];
    std::shared_ptr<Column> columnElem = std::dynamic_pointer_cast<Column>(elem);

    ACRColumnView* column = [[ACRColumnView alloc] initWithStyle:columnElem->GetStyle()
                                                     parentStyle:[viewGroup style] hostConfig:config];
    [ACRRenderer render:column
     rootViewController:vc
                 inputs:inputs
          withCardElems:columnElem->GetItems()
          andHostConfig:config];

    [viewGroup addArrangedSubview:column];

    [column setContentHuggingPriority:UILayoutPriorityDefaultHigh forAxis:UILayoutConstraintAxisHorizontal];
    [column setClipsToBounds:TRUE];
    if(columnElem->GetWidth() == "stretch")
    {
        [column setContentHuggingPriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisHorizontal];
    }

    [column adjustHuggingForLastElement];

    std::shared_ptr<BaseActionElement> selectAction = columnElem->GetSelectAction();
    // instantiate and add tap gesture recognizer
    UILongPressGestureRecognizer * gestureRecognizer =
        [ACRLongPressGestureRecognizerFactory getLongPressGestureRecognizer:viewGroup
                                                         rootViewController:vc
                                                                 targetView:column
                                                              actionElement:selectAction
                                                                     inputs:inputs
                                                                 hostConfig:config];
    if(gestureRecognizer)
    {
        [column addGestureRecognizer:gestureRecognizer];
        column.userInteractionEnabled = YES;
    }

    return column;
}

@end

