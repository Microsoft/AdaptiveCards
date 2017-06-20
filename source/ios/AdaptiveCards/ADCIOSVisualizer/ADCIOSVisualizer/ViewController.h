//
//  ViewController.h
//  ADCIOSVisualizer
//
//  Created by jwoo on 6/2/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (strong, nonatomic) UILabel *JSLab;
@property (readonly) NSArray* inputs;
@property NSUInteger idx;
@property UIView* curView;
@property (weak, nonatomic) IBOutlet UIStackView *StkView;


@end

