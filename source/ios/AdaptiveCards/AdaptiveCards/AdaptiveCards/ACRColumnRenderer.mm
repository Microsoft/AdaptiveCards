//
//  ACRColumnRenderer
//  ACRColumnRenderer.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRColumnRenderer.h"
#import "ACRColumnView.h"
#import "ACRRenderer.h"
#import "Column.h"
#import "SharedAdaptiveCard.h"

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
            inputs:(NSMutableArray *)inputs
      withCardElem:(std::shared_ptr<BaseCardElement> const &)elem
     andHostConfig:(std::shared_ptr<HostConfig> const &)config
{ 
    std::shared_ptr<Column> columnElem = std::dynamic_pointer_cast<Column>(elem);

    ACRColumnView* column = [[ACRColumnView alloc] init];
    [viewGroup addArrangedSubview:column];
    [ACRRenderer render:column
                 inputs:inputs
          withCardElems:columnElem->GetItems()
          andHostConfig:config];

    [column setContentHuggingPriority:UILayoutPriorityDefaultHigh forAxis:UILayoutConstraintAxisHorizontal];
    [column setClipsToBounds:TRUE];
    if(columnElem->GetSize() == "stretch")
    {
        [column setContentHuggingPriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisHorizontal];
    }
    
    [column adjustHuggingForLastElement];
    
    return column;
}

@end

