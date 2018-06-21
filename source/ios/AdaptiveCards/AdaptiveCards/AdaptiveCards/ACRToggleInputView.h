//
//  ACRToggleInputView
//  ACRToggleInputView.h
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import "ToggleInput.h"
#import "ACRIBaseInputHandler.h"
#import "ACRIBaseCardElementRenderer.h"
#import "HostConfig.h"
#import "ACRColumnSetView.h"

@interface ACRToggleInputView:ACRColumnSetView<ACRIBaseInputHandler>

@property NSString *id;
@property NSString *valueOn;
@property NSString *valueOff;

- (instancetype)initWithInputToggle:(std::shared_ptr<AdaptiveCards::ToggleInput> const&)toggleInput
                     WithHostConfig:(std::shared_ptr<AdaptiveCards::HostConfig> const&)hostConfig;
@end
