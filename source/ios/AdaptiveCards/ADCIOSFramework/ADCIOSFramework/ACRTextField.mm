//
//  ACRTextField
//  ACRTextField.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRTextField.h"

@implementation ACRTextField

- (BOOL)validate:(NSError **)error
{
    if(self.isRequired && !self.hasText)
    {
        if(error)
        {
            *error = [NSError errorWithDomain:ACRInputErrorDomain code:ACRInputErrorValueMissing userInfo:nil];
        }
        return NO;
    }
    else
        return YES;
}

- (void)getInput:(NSMutableDictionary *)dictionary
{
    dictionary[self.id] = self.text;
}
@end
