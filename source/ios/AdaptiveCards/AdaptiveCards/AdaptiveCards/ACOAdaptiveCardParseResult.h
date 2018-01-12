//
//  ACOAdaptiveCardParseResult.h
//  ACOAdaptiveCardParseResult
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACOParseError.h"

@class ACOAdaptiveCard;

@interface ACOAdaptiveCardParseResult:NSObject

@property ACOAdaptiveCard *card;
@property BOOL IsValid;
@property NSMutableArray<ACOParseError *> *parseErrors;

@end
