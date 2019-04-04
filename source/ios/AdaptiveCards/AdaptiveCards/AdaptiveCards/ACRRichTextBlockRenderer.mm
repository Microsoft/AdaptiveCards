//
//  ACRRichTextBlockRenderer
//  ACRRichTextBlockRenderer.mm
//
//  Copyright © 2019 Microsoft. All rights reserved.
//

#import "ACRRichTextBlockRenderer.h"
#import "ACRContentHoldingUIView.h"
#import "RichTextBlock.h"
#import "TextRun.h"
#import "ACRAggregateTarget.h"
#import "HostConfig.h"
#import "MarkDownParser.h"
#import "ACRView.h"
#import "ACOHostConfigPrivate.h"
#import "ACOBaseCardElementPrivate.h"
#import "ACOBaseActionElementPrivate.h"
#import "ACRUILabel.h"
#import "DateTimePreparsedToken.h"
#import "DateTimePreparser.h"
#import "Util.h"
#import "ACRLongPressGestureRecognizerFactory.h"

@implementation ACRRichTextBlockRenderer

+ (ACRRichTextBlockRenderer *)getInstance
{
    static ACRRichTextBlockRenderer *singletonInstance = [[self alloc] init];
    return singletonInstance;
}

+ (ACRCardElementType)elemType
{
    return ACRRichTextBlock;
}

- (UIView *)render:(UIView<ACRIContentHoldingView> *)viewGroup
          rootView:(ACRView *)rootView
            inputs:(NSMutableArray *)inputs
   baseCardElement:(ACOBaseCardElement *)acoElem
        hostConfig:(ACOHostConfig *)acoConfig;
{
    std::shared_ptr<HostConfig> config = [acoConfig getHostConfig];
    std::shared_ptr<BaseCardElement> elem = [acoElem element];
    std::shared_ptr<RichTextBlock> rTxtBlck = std::dynamic_pointer_cast<RichTextBlock>(elem);
    ACRUILabel *lab = [[ACRUILabel alloc] initWithFrame:CGRectMake(0,0,viewGroup.frame.size.width, 0)];
    lab.backgroundColor = [UIColor clearColor];
    lab.style = [viewGroup style];
    lab.editable = NO;
    lab.textContainer.lineFragmentPadding = 0;
    lab.textContainerInset = UIEdgeInsetsZero;
    lab.layoutManager.usesFontLeading = false;

    NSMutableAttributedString *content = [[NSMutableAttributedString alloc] init];
    if(rootView){
        NSMutableDictionary *textMap = [rootView getTextMap];

        for(const auto &paragraph : rTxtBlck->GetParagraphs()) {
            for(const auto &inlineText : paragraph->GetInlines()) {
                std::shared_ptr<TextRun> textRun = std::static_pointer_cast<TextRun>(inlineText);
                if(textRun) {
                    NSNumber *number = [NSNumber numberWithUnsignedLongLong:(unsigned long long)textRun.get()];
                    NSString *key = [number stringValue];
                    NSDictionary* data = textMap[key];
                    NSData *htmlData = data[@"html"];
                    NSDictionary *options = data[@"options"];
                    NSDictionary *descriptor = data[@"descriptor"];
                    NSString *text = data[@"nonhtml"];

                    NSMutableAttributedString *textRunContent = nil;
                    // Initializing NSMutableAttributedString for HTML rendering is very slow
                    if(htmlData) {
                        textRunContent = [[NSMutableAttributedString alloc] initWithData:htmlData options:options documentAttributes:nil error:nil];
                        lab.selectable = YES;
                        lab.dataDetectorTypes = UIDataDetectorTypeLink;
                        lab.userInteractionEnabled = YES;
                    } else {
                        textRunContent = [[NSMutableAttributedString alloc] initWithString:text attributes:descriptor];
                        // text is preprocessed by markdown parser, and will wrapped by <p></P>
                        // lines below remove the p tags
                        [textRunContent deleteCharactersInRange:NSMakeRange(0, 3)];
                        [textRunContent deleteCharactersInRange:NSMakeRange([textRunContent length] -4, 4)];
                    }
                    // Set paragraph style such as line break mode and alignment
                    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
                    paragraphStyle.alignment = [ACOHostConfig getTextBlockAlignment:rTxtBlck->GetHorizontalAlignment()];

                    // Obtain text color to apply to the attributed string
                    ACRContainerStyle style = lab.style;
                    auto foregroundColor = [acoConfig getTextBlockColor:style textColor:textRun->GetTextColor() subtleOption:textRun->GetIsSubtle()];

                    // Config and add Select Action
                    std::shared_ptr<BaseActionElement> baseAction = textRun->GetSelectAction();
                    if(baseAction) {
                        NSObject<ACRSelectActionDelegate> *target = [ACRLongPressGestureRecognizerFactory buildTarget:textRun->GetSelectAction() rootView:rootView hostConfig:acoConfig destinationViewForShowCard:nil];
                        if(target) {
                            // add target as attribute of the NSAttributedString for rather retrieval when touch event is triggered
                            [textRunContent addAttribute:@"SelectAction" value:target range:NSMakeRange(0, textRunContent.length - 1)];
                            [ACRLongPressGestureRecognizerFactory addTapGestureRecognizerToUITextView:lab target:target rootView:rootView hostConfig:acoConfig];
                        }
                    }

                    // apply hightlight to textrun
                    if(textRun->GetHighlight()) {
                        UIColor *highlightColor = [acoConfig getHighlightColor:style
                                                               foregroundColor:textRun->GetTextColor()
                                                                  subtleOption:textRun->GetIsSubtle()];
                        [textRunContent addAttribute:NSBackgroundColorAttributeName value:highlightColor range:NSMakeRange(0,textRunContent.length - 1)];
                    }

                    // Add paragraph style, text color, text weight as attributes to a NSMutableAttributedString, content.
                    [textRunContent addAttributes:@{NSParagraphStyleAttributeName:paragraphStyle, NSForegroundColorAttributeName:foregroundColor,} range:NSMakeRange(0, textRunContent.length - 1)];

                    [content appendAttributedString:textRunContent];
                }
            }

            // inserts a new line
            NSAttributedString * const newline = [[NSAttributedString alloc] initWithString:@"\n"];
            [content appendAttributedString:newline];
        }
    }

    lab.textContainer.lineBreakMode = NSLineBreakByTruncatingTail;
    lab.attributedText = content;
    lab.area = lab.frame.size.width * lab.frame.size.height;

    ACRContentHoldingUIView *wrappingview = [[ACRContentHoldingUIView alloc] initWithFrame:lab.frame];
    wrappingview.translatesAutoresizingMaskIntoConstraints = NO;
    lab.translatesAutoresizingMaskIntoConstraints = NO;

    [viewGroup addArrangedSubview:wrappingview];
    [wrappingview addSubview:lab];

    NSLayoutAttribute horizontalAlignment = NSLayoutAttributeLeading;
    if(rTxtBlck->GetHorizontalAlignment() == HorizontalAlignment::Right) {
        horizontalAlignment = NSLayoutAttributeTrailing;
    } else if (rTxtBlck->GetHorizontalAlignment() == HorizontalAlignment::Center) {
        horizontalAlignment = NSLayoutAttributeCenterX;
    }

    [NSLayoutConstraint constraintWithItem:lab attribute:horizontalAlignment relatedBy:NSLayoutRelationEqual toItem:wrappingview attribute:horizontalAlignment multiplier:1.0 constant:0].active = YES;
    [NSLayoutConstraint constraintWithItem:lab attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:wrappingview attribute:NSLayoutAttributeBottom multiplier:1.0 constant:0].active = YES;
    [NSLayoutConstraint constraintWithItem:lab attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:wrappingview attribute:NSLayoutAttributeTop multiplier:1.0 constant:0].active = YES;

    lab.textContainer.maximumNumberOfLines = int(rTxtBlck->GetMaxLines());
    if(!lab.textContainer.maximumNumberOfLines && !rTxtBlck->GetWrap()){
        lab.textContainer.maximumNumberOfLines = 1;
    }

    if(rTxtBlck->GetHeight() == HeightType::Auto){
        [wrappingview setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
        [wrappingview setContentHuggingPriority:UILayoutPriorityDefaultHigh forAxis:UILayoutConstraintAxisVertical];
    } else {
        [wrappingview setContentHuggingPriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisVertical];
        [wrappingview setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
    }

    [NSLayoutConstraint constraintWithItem:wrappingview attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationGreaterThanOrEqual toItem:lab attribute:NSLayoutAttributeWidth multiplier:1.0 constant:0].active = YES;
    [lab setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];
    [wrappingview setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];

    configVisibility(wrappingview, elem);

    return wrappingview;
}

@end
