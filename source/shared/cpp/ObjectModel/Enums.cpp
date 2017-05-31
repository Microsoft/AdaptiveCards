#include "Enums.h"

namespace AdaptiveCards
{
static std::unordered_map<AdaptiveCardSchemaKey, std::string, EnumHash> AdaptiveCardSchemaKeyEnumToName =
{
    { AdaptiveCardSchemaKey::Accent, "accent" },
    { AdaptiveCardSchemaKey::ActionAlignment, "actionAlignment" },
    { AdaptiveCardSchemaKey::ActionMode, "actionMode" },
    { AdaptiveCardSchemaKey::Actions, "actions" },
    { AdaptiveCardSchemaKey::ActionSetConfig, "actionSetConfig" },
    { AdaptiveCardSchemaKey::ActionsOrientation, "actionsOrientation" },
    { AdaptiveCardSchemaKey::AdaptiveCard, "adaptiveCard" },
    { AdaptiveCardSchemaKey::AltText, "altText" },
    { AdaptiveCardSchemaKey::Attention, "attention" },
    { AdaptiveCardSchemaKey::BackgroundColor, "backgroundColor" },
    { AdaptiveCardSchemaKey::BackgroundImageUrl, "backgroundImageUrl" },
    { AdaptiveCardSchemaKey::BaseCardElement, "baseCardElement" },
    { AdaptiveCardSchemaKey::Body, "body" },
    { AdaptiveCardSchemaKey::BorderColor, "borderColor" },
    { AdaptiveCardSchemaKey::BorderThickness, "borderThickness" },
    { AdaptiveCardSchemaKey::ButtonSpacing, "buttonSpacing" },
    { AdaptiveCardSchemaKey::Card, "card" },
    { AdaptiveCardSchemaKey::Center, "center" },
    { AdaptiveCardSchemaKey::Choices, "choices" },
    { AdaptiveCardSchemaKey::ChoiceSet, "choiceSet" },
    { AdaptiveCardSchemaKey::Color, "color" },
    { AdaptiveCardSchemaKey::ColorConfig, "colorConfig" },
    { AdaptiveCardSchemaKey::Colors, "colors" },
    { AdaptiveCardSchemaKey::Column, "column" },
    { AdaptiveCardSchemaKey::Columns, "columns" },
    { AdaptiveCardSchemaKey::ColumnSet, "columnSet" },
    { AdaptiveCardSchemaKey::Container, "container" },
    { AdaptiveCardSchemaKey::ContainerStyleConfig, "containerStyleConfig" },
    { AdaptiveCardSchemaKey::Dark, "dark" },
    { AdaptiveCardSchemaKey::DateInput, "dateInput" },
    { AdaptiveCardSchemaKey::Default, "default" },
    { AdaptiveCardSchemaKey::Emphasis, "emphasis" },
    { AdaptiveCardSchemaKey::ExtraLarge, "extraLarge" },
    { AdaptiveCardSchemaKey::Facts, "facts" },
    { AdaptiveCardSchemaKey::FactSet, "factSet" },
    { AdaptiveCardSchemaKey::FallbackText, "fallbackText" },
    { AdaptiveCardSchemaKey::FontFamily, "fontFamily" },
    { AdaptiveCardSchemaKey::FontSizes, "fontSizes" },
    { AdaptiveCardSchemaKey::Good, "good" },
    { AdaptiveCardSchemaKey::HorizontalAlignment, "horizontalAlignment" },
    { AdaptiveCardSchemaKey::Id, "id" },
    { AdaptiveCardSchemaKey::Image, "image" },
    { AdaptiveCardSchemaKey::Images, "images" },
    { AdaptiveCardSchemaKey::ImageSet, "imageSet" },
    { AdaptiveCardSchemaKey::ImageSize, "imageSize" },
    { AdaptiveCardSchemaKey::ImageSizes, "imageSizes" },
    { AdaptiveCardSchemaKey::InlineTopMargin, "inlineTopMargin" },
    { AdaptiveCardSchemaKey::IsMultiline, "isMultiline" },
    { AdaptiveCardSchemaKey::IsMultiSelect, "isMultiSelect" },
    { AdaptiveCardSchemaKey::IsRequired, "isRequired" },
    { AdaptiveCardSchemaKey::IsSelected, "isSelected"},
    { AdaptiveCardSchemaKey::IsSubtle, "isSubtle" },
    { AdaptiveCardSchemaKey::Items, "items" },
    { AdaptiveCardSchemaKey::Large, "large" },
    { AdaptiveCardSchemaKey::Left, "left" },
    { AdaptiveCardSchemaKey::Light, "light" },
    { AdaptiveCardSchemaKey::LineColor, "lineColor" },
    { AdaptiveCardSchemaKey::LineThickness, "lineThickness" },
    { AdaptiveCardSchemaKey::Max, "max" },
    { AdaptiveCardSchemaKey::MaxActions, "maxActions" },
    { AdaptiveCardSchemaKey::MaxLength, "maxLength" },
    { AdaptiveCardSchemaKey::MaxLines, "maxLines" },
    { AdaptiveCardSchemaKey::Medium, "medium" },
    { AdaptiveCardSchemaKey::Method, "method" },
    { AdaptiveCardSchemaKey::Min, "min" },
    { AdaptiveCardSchemaKey::MinVersion, "minVersion" },
    { AdaptiveCardSchemaKey::Normal, "normal" },
    { AdaptiveCardSchemaKey::NumberInput, "numberInput" },
    { AdaptiveCardSchemaKey::Padding, "padding" },
    { AdaptiveCardSchemaKey::Placeholder, "placeholder" },
    { AdaptiveCardSchemaKey::Right, "right" },
    { AdaptiveCardSchemaKey::Separation, "separation" },
    { AdaptiveCardSchemaKey::ShowActionMode, "showActionMode" },
    { AdaptiveCardSchemaKey::ShowCard, "showCard" },
    { AdaptiveCardSchemaKey::ShowCardActionConfig, "showCardActionConfig" },
    { AdaptiveCardSchemaKey::Size, "size" },
    { AdaptiveCardSchemaKey::Small, "small" },
    { AdaptiveCardSchemaKey::Spacing, "spacing" },
    { AdaptiveCardSchemaKey::SpacingDefinition, "spacingDefinition" },
    { AdaptiveCardSchemaKey::Speak, "speak" },
    { AdaptiveCardSchemaKey::Stretch, "stretch" },
    { AdaptiveCardSchemaKey::StrongSeparation, "strongSeparation" },
    { AdaptiveCardSchemaKey::Style, "style" },
    { AdaptiveCardSchemaKey::Subtle, "subtle" },
    { AdaptiveCardSchemaKey::SupportsInteractivity, "supportsInteractivity" },
    { AdaptiveCardSchemaKey::Text, "text" },
    { AdaptiveCardSchemaKey::TextBlock, "textBlock" },
    { AdaptiveCardSchemaKey::TextConfig, "textConfig" },
    { AdaptiveCardSchemaKey::TextInput, "textInput" },
    { AdaptiveCardSchemaKey::TextWeight, "weight" },
    { AdaptiveCardSchemaKey::TimeInput, "timeInput" },
    { AdaptiveCardSchemaKey::Title, "title" },
    { AdaptiveCardSchemaKey::ToggleInput, "toggleInput" },
    { AdaptiveCardSchemaKey::Type, "type" },
    { AdaptiveCardSchemaKey::Url, "url" },
    { AdaptiveCardSchemaKey::Value, "value" },
    { AdaptiveCardSchemaKey::ValueOff, "valueOff" },
    { AdaptiveCardSchemaKey::ValueOn, "valueOn" },
    { AdaptiveCardSchemaKey::Version, "version" },
    { AdaptiveCardSchemaKey::Warning, "warning" },
    { AdaptiveCardSchemaKey::Weight, "weight" },
    { AdaptiveCardSchemaKey::Wrap, "wrap" },
};

static std::unordered_map<std::string, AdaptiveCardSchemaKey, CaseInsensitiveHash, CaseInsensitiveEqualTo> 
AdaptiveCardSchemaKeyNameToEnum = GenerateStringToEnumMap<AdaptiveCardSchemaKey>(AdaptiveCardSchemaKeyEnumToName);

static std::unordered_map<CardElementType, std::string, EnumHash> CardElementTypeEnumToName =
{
    { CardElementType::AdaptiveCard, "AdaptiveCard" },
    { CardElementType::Column, "Column" },
    { CardElementType::ColumnSet, "ColumnSet"},
    { CardElementType::Container, "Container" },
    { CardElementType::Fact, "Fact" },
    { CardElementType::FactSet, "FactSet" },
    { CardElementType::Image, "Image" },
    { CardElementType::ImageSet, "ImageSet" },
    { CardElementType::InputChoiceSet, "Input.ChoiceSet" },
    { CardElementType::InputDate, "Input.Date" },
    { CardElementType::InputNumber, "Input.Number" },
    { CardElementType::InputText, "Input.Text" },
    { CardElementType::InputTime, "Input.Time" },
    { CardElementType::InputToggle, "Input.Toggle" },
    { CardElementType::TextBlock, "TextBlock" },
};

static std::unordered_map<std::string, CardElementType, CaseInsensitiveHash, CaseInsensitiveEqualTo> 
CardElementTypeNameToEnum = GenerateStringToEnumMap<CardElementType>(CardElementTypeEnumToName);

static std::unordered_map<ActionType, std::string, EnumHash> ActionTypeEnumToName =
{
    { ActionType::Http, "Action.Http" },
    { ActionType::OpenUrl, "Action.OpenUrl" },
    { ActionType::ShowCard, "Action.ShowCard" },
    { ActionType::Submit, "Action.Submit" }
};

static std::unordered_map<std::string, ActionType, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionTypeNameToEnum = GenerateStringToEnumMap<ActionType>(ActionTypeEnumToName);

static std::unordered_map<SeparationStyle, std::string, EnumHash> SeparationStyleEnumToName =
{
    { SeparationStyle::Default, "default" },
    { SeparationStyle::None, "none" },
    { SeparationStyle::Strong, "strong" }
};

static std::unordered_map<std::string, SeparationStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
SeparationStyleNameToEnum = GenerateStringToEnumMap<SeparationStyle>(SeparationStyleEnumToName);

static std::unordered_map<ImageStyle, std::string, EnumHash> ImageStyleEnumToName =
{
    {ImageStyle::Normal, "normal"},
    {ImageStyle::Person, "person"}
};

static std::unordered_map<std::string, ImageStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ImageStyleNameToEnum = GenerateStringToEnumMap<ImageStyle>(ImageStyleEnumToName);

static std::unordered_map<ImageSize, std::string, EnumHash> ImageSizeEnumToName =
{
    { ImageSize::Auto, "Auto" },
    { ImageSize::Default, "Auto" },
    { ImageSize::Large, "Large" },
    { ImageSize::Medium, "Medium" },
    { ImageSize::Small, "Small" },
    { ImageSize::Stretch, "Stretch" },
};

static std::unordered_map<std::string, ImageSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ImageSizeNameToEnum = GenerateStringToEnumMap<ImageSize>(ImageSizeEnumToName);

static std::unordered_map<HorizontalAlignment, std::string, EnumHash> HorizontalAlignmentEnumToName = 
{
    {HorizontalAlignment::Center, "Center"},
    {HorizontalAlignment::Left, "Left"},
    {HorizontalAlignment::Right, "Right"}
};

static std::unordered_map<std::string, HorizontalAlignment, CaseInsensitiveHash, CaseInsensitiveEqualTo>
HorizontalAlignmentNameToEnum = GenerateStringToEnumMap<HorizontalAlignment>(HorizontalAlignmentEnumToName);

static std::unordered_map<TextColor, std::string, EnumHash> TextColorEnumToName =
{
    {TextColor::Accent, "Accent"},
    {TextColor::Attention, "Attention"},
    {TextColor::Dark, "Dark"},
    {TextColor::Default, "Default"},
    {TextColor::Good, "Good"},
    {TextColor::Light, "Light"},
    {TextColor::Warning, "Warning"},
};

static std::unordered_map<std::string, TextColor, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextColorNameToEnum = GenerateStringToEnumMap<TextColor>(TextColorEnumToName);

static std::unordered_map<TextWeight, std::string, EnumHash> TextWeightEnumToName =
{
    {TextWeight::Bolder, "Bolder"},
    {TextWeight::Lighter, "Lighter"},
    {TextWeight::Normal, "Normal"},
};

static std::unordered_map<std::string, TextWeight, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextWeightNameToEnum = GenerateStringToEnumMap<TextWeight>(TextWeightEnumToName);

static std::unordered_map<TextSize, std::string, EnumHash> TextSizeEnumToName =
{
    {TextSize::ExtraLarge, "ExtraLarge"},
    {TextSize::Large, "Large"},
    {TextSize::Medium, "Medium"},
    {TextSize::Normal, "Normal"},
    {TextSize::Small, "Small"},
};

static std::unordered_map<std::string, TextSize, CaseInsensitiveHash, CaseInsensitiveEqualTo>
TextSizeNameToEnum = GenerateStringToEnumMap<TextSize>(TextSizeEnumToName);

static std::unordered_map<ActionsOrientation, std::string, EnumHash> ActionsOrientationEnumToName =
{
    { ActionsOrientation::Horizontal, "Horizontal" },
    { ActionsOrientation::Vertical, "Vertical" },
};

static std::unordered_map<std::string, ActionsOrientation, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionsOrientationNameToEnum = GenerateStringToEnumMap<ActionsOrientation>(ActionsOrientationEnumToName);

static std::unordered_map<ActionMode, std::string, EnumHash> ActionModeEnumToName =
{
    { ActionMode::Inline, "Inline" },
    { ActionMode::Popup, "Popup" }
};

static std::unordered_map<std::string, ActionMode, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ActionModeNameToEnum = GenerateStringToEnumMap<ActionMode>(ActionModeEnumToName);

static std::unordered_map<ChoiceSetStyle, std::string, EnumHash> ChoiceSetStyleEnumToName =
{
    { ChoiceSetStyle::Compact, "Compact" },
    { ChoiceSetStyle::Expanded, "Expanded" }
};

static std::unordered_map<std::string, ChoiceSetStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ChoiceSetStyleNameToEnum = GenerateStringToEnumMap<ChoiceSetStyle>(ChoiceSetStyleEnumToName);

static std::unordered_map<TextInputStyle, std::string, EnumHash> TextInputStyleEnumToName =
{
    { TextInputStyle::Email, "Email" },
    { TextInputStyle::Tel, "Tel" },
    { TextInputStyle::Text, "Text" },
    { TextInputStyle::Url, "Url" },
};

static std::unordered_map<std::string, TextInputStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
InputTextStyleNameToEnum = GenerateStringToEnumMap<TextInputStyle>(TextInputStyleEnumToName);

static std::unordered_map<ContainerStyle, std::string, EnumHash> ContainerStyleEnumToName =
{
    { ContainerStyle::Emphasis, "Emphasis" },
    { ContainerStyle::Normal, "Normal" },
};

static std::unordered_map<std::string, ContainerStyle, CaseInsensitiveHash, CaseInsensitiveEqualTo>
ContainerStyleNameToEnum = GenerateStringToEnumMap<ContainerStyle>(ContainerStyleEnumToName);

const std::string AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey type)
{
    if (AdaptiveCardSchemaKeyEnumToName.find(type) == AdaptiveCardSchemaKeyEnumToName.end())
    {
        throw std::out_of_range("Invalid AdaptiveCardSchemaKeys");
    }

    return AdaptiveCardSchemaKeyEnumToName[type];
}

AdaptiveCardSchemaKey AdaptiveCardSchemaKeyFromString(const std::string& type)
{
    if (AdaptiveCardSchemaKeyNameToEnum.find(type) == AdaptiveCardSchemaKeyNameToEnum.end())
    {
        throw std::out_of_range("Invalid AdaptiveCardSchemaKey: " + type);
    }

    return AdaptiveCardSchemaKeyNameToEnum[type];
}

const std::string CardElementTypeToString(CardElementType elementType)
{
    if (CardElementTypeEnumToName.find(elementType) == CardElementTypeEnumToName.end())
    {
        throw std::out_of_range("Invalid CardElementType");
    }

    return CardElementTypeEnumToName[elementType];
}

CardElementType CardElementTypeFromString(const std::string& elementType)
{
    if (CardElementTypeNameToEnum.find(elementType) == CardElementTypeNameToEnum.end())
    {
        throw std::out_of_range("Invalid CardElementType: " + elementType);
    }

    return CardElementTypeNameToEnum[elementType];
}

const std::string ActionTypeToString(ActionType actionType)
{
    if (ActionTypeEnumToName.find(actionType) == ActionTypeEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionType");
    }

    return ActionTypeEnumToName[actionType];
}

ActionType ActionTypeFromString(const std::string& actionType)
{
    if (ActionTypeNameToEnum.find(actionType) == ActionTypeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionType: " + actionType);
    }

    return ActionTypeNameToEnum[actionType];
}

const std::string HorizontalAlignmentToString(HorizontalAlignment type)
{
    if (HorizontalAlignmentEnumToName.find(type) == HorizontalAlignmentEnumToName.end())
    {
        throw std::out_of_range("Invalid HorizontalAlignment type");
    }
    return HorizontalAlignmentEnumToName[type];
}

HorizontalAlignment HorizontalAlignmentFromString(const std::string& type)
{
    if (HorizontalAlignmentNameToEnum.find(type) == HorizontalAlignmentNameToEnum.end())
    {
        throw std::out_of_range("Invalid HorizontalAlignment: " + type);
    }

    return HorizontalAlignmentNameToEnum[type];
}

const std::string TextColorToString(TextColor type)
{
    if (TextColorEnumToName.find(type) == TextColorEnumToName.end())
    {
        throw std::out_of_range("Invalid TextColor type");
    }
    return TextColorEnumToName[type];
}

TextColor TextColorFromString(const std::string& type)
{
    if (TextColorNameToEnum.find(type) == TextColorNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextColor: " + type);
    }

    return TextColorNameToEnum[type];
}

const std::string TextWeightToString(TextWeight type)
{
    if (TextWeightEnumToName.find(type) == TextWeightEnumToName.end())
    {
        throw std::out_of_range("Invalid TextWeight type");
    }
    return TextWeightEnumToName[type];
}

TextWeight TextWeightFromString(const std::string& type)
{
    if (TextWeightNameToEnum.find(type) == TextWeightNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextWeight: " + type);
    }

    return TextWeightNameToEnum[type];
}

const std::string TextSizeToString(TextSize type)
{
    if (TextSizeEnumToName.find(type) == TextSizeEnumToName.end())
    {
        throw std::out_of_range("Invalid TextSize type");
    }
    return TextSizeEnumToName[type];
}

TextSize TextSizeFromString(const std::string& type)
{
    if (TextSizeNameToEnum.find(type) == TextSizeNameToEnum.end())
    {
        throw std::out_of_range("Invalid TextSize: " + type);
    }

    return TextSizeNameToEnum[type];
}

const std::string ImageSizeToString(ImageSize type)
{
    if (ImageSizeEnumToName.find(type) == ImageSizeEnumToName.end())
    {
        throw std::out_of_range("Invalid ImageSize type");
    }
    return ImageSizeEnumToName[type];
}

ImageSize ImageSizeFromString(const std::string& type)
{
    if (ImageSizeNameToEnum.find(type) == ImageSizeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ImageSize: " + type);
    }

    return ImageSizeNameToEnum[type];
}

const std::string SeparationStyleToString(SeparationStyle type)
{
    if (SeparationStyleEnumToName.find(type) == SeparationStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid SeparationStyle type");
    }
    return SeparationStyleEnumToName[type];
}

SeparationStyle SeparationStyleFromString(const std::string& type)
{
    if (SeparationStyleNameToEnum.find(type) == SeparationStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid SeparationStyle: " + type);
    }

    return SeparationStyleNameToEnum[type];
}

const std::string ImageStyleToString(ImageStyle style)
{
    if (ImageStyleEnumToName.find(style) == ImageStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ImageStyle style");
    }
    return ImageStyleEnumToName[style];
}

ImageStyle ImageStyleFromString(const std::string& style)
{
    if (ImageStyleNameToEnum.find(style) == ImageStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ImageStyle: " + style);
    }

    return ImageStyleNameToEnum[style];
}

const std::string ActionsOrientationToString(ActionsOrientation orientation)
{
    if (ActionsOrientationEnumToName.find(orientation) == ActionsOrientationEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionsOrientation type");
    }
    return ActionsOrientationEnumToName[orientation];
}

ActionsOrientation ActionsOrientationFromString(const std::string& orientation)
{
    if (ActionsOrientationNameToEnum.find(orientation) == ActionsOrientationNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionsOrientation: " + orientation);
    }
    return ActionsOrientationNameToEnum[orientation];
}

const std::string ActionModeToString(ActionMode mode)
{
    if (ActionModeEnumToName.find(mode) == ActionModeEnumToName.end())
    {
        throw std::out_of_range("Invalid ActionMode type");
    }
    return ActionModeEnumToName[mode];
}

ActionMode ActionModeFromString(const std::string& mode)
{
    if (ActionModeNameToEnum.find(mode) == ActionModeNameToEnum.end())
    {
        throw std::out_of_range("Invalid ActionMode: " + mode);
    }
    return ActionModeNameToEnum[mode];
}
const std::string ChoiceSetStyleToString(ChoiceSetStyle style)
{
    if (ChoiceSetStyleEnumToName.find(style) == ChoiceSetStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ChoiceSetStyle");
    }
    return ChoiceSetStyleEnumToName[style];
}
ChoiceSetStyle ChoiceSetStyleFromString(const std::string & style)
{
    if (ChoiceSetStyleNameToEnum.find(style) == ChoiceSetStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ChoiceSetStyle: " + style);
    }
    return ChoiceSetStyleNameToEnum[style];
}

const std::string TextInputStyleToString(TextInputStyle style)
{
    if (TextInputStyleEnumToName.find(style) == TextInputStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid InputTextStyle");
    }
    return TextInputStyleEnumToName[style];
}
TextInputStyle TextInputStyleFromString(const std::string & style)
{
    if (InputTextStyleNameToEnum.find(style) == InputTextStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid InputTextStyle: " + style);
    }
    return InputTextStyleNameToEnum[style];
}

const std::string ContainerStyleToString(ContainerStyle style)
{
    if (ContainerStyleEnumToName.find(style) == ContainerStyleEnumToName.end())
    {
        throw std::out_of_range("Invalid ContainerStyle");
    }
    return ContainerStyleEnumToName[style];
}
ContainerStyle ContainerStyleFromString(const std::string & style)
{
    if (ContainerStyleNameToEnum.find(style) == ContainerStyleNameToEnum.end())
    {
        throw std::out_of_range("Invalid ContainerStyle: " + style);
    }
    return ContainerStyleNameToEnum[style];
}

}