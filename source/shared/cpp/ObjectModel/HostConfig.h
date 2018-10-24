#pragma once

#include "pch.h"
#include "Enums.h"
#include "json/json.h"

namespace AdaptiveSharedNamespace
{
    class FontSizesConfig
    {
    public:
        FontSizesConfig();
        FontSizesConfig(unsigned int smallFontSize,
                        unsigned int defaultFontSize,
                        unsigned int mediumFontSize,
                        unsigned int largeFontSize,
                        unsigned int extraLargeFontSize);
        static FontSizesConfig Deserialize(const Json::Value& json, const FontSizesConfig& defaultValue);
        static unsigned int GetDefaultFontSize(TextSize size);
        unsigned int GetFontSize(TextSize size);
        void SetFontSize(TextSize size, unsigned int value);

    private:
        // UINT_MAX used to check if value was defined
        unsigned int smallFontSize;
        unsigned int defaultFontSize;
        unsigned int mediumFontSize;
        unsigned int largeFontSize;
        unsigned int extraLargeFontSize;
    };

    class FontWeightsConfig
    {
    public:
        FontWeightsConfig();
        FontWeightsConfig(unsigned int lighterWeight, unsigned int defaultWeight, unsigned int bolderWeight);
        static FontWeightsConfig Deserialize(const Json::Value& json, const FontWeightsConfig& defaultValue);
        static unsigned int GetDefaultFontWeight(TextWeight weight);
        unsigned int GetFontWeight(TextWeight weight);
        void SetFontWeight(TextWeight weight, unsigned int value);

    private:
        // UINT_MAX used to check if value was defined
        unsigned int lighterWeight;
        unsigned int defaultWeight;
        unsigned int bolderWeight;
    };

    struct FontStyleDefinition
    {
        std::string fontFamily;
        FontSizesConfig fontSizes;
        FontWeightsConfig fontWeights;

        static FontStyleDefinition Deserialize(const Json::Value& json, const FontStyleDefinition& defaultValue);
    };

    struct FontStylesDefinition
    {
        FontStyleDefinition defaultStyle;
        FontStyleDefinition displayStyle;
        FontStyleDefinition monospaceStyle;

        static FontStylesDefinition Deserialize(const Json::Value& json, const FontStylesDefinition& defaultValue);
    };

    struct ColorConfig
    {
        std::string defaultColor;
        std::string subtleColor;

        static ColorConfig Deserialize(const Json::Value& json, const ColorConfig& defaultValue);
    };

    struct ColorsConfig
    {
        ColorConfig defaultColor = {"#FF000000", "#B2000000"};
        ColorConfig accent = {"#FF0000FF", "#B20000FF"};
        ColorConfig dark = {"#FF101010", "#B2101010"};
        ColorConfig light = {"#FFFFFFFF", "#B2FFFFFF"};
        ColorConfig good = {"#FF008000", "#B2008000"};
        ColorConfig warning = {"#FFFFD700", "#B2FFD700"};
        ColorConfig attention = {"#FF8B0000", "#B28B0000"};

        static ColorsConfig Deserialize(const Json::Value& json, const ColorsConfig& defaultValue);
    };

    struct TextConfig
    {
        TextWeight weight = TextWeight::Default;
        TextSize size = TextSize::Default;
        FontStyle style = FontStyle::Default;
        ForegroundColor color = ForegroundColor::Default;
        bool isSubtle = false;
        bool wrap = true;
        unsigned int maxWidth = ~0U;

        static TextConfig Deserialize(const Json::Value& json, const TextConfig& defaultValue);
    };

    struct SpacingConfig
    {
        unsigned int smallSpacing = 3;
        unsigned int defaultSpacing = 8;
        unsigned int mediumSpacing = 20;
        unsigned int largeSpacing = 30;
        unsigned int extraLargeSpacing = 40;
        unsigned int paddingSpacing = 20;

        static SpacingConfig Deserialize(const Json::Value& json, const SpacingConfig& defaultValue);
    };

    struct SeparatorConfig
    {
        unsigned int lineThickness = 1;
        std::string lineColor = "#B2000000";

        static SeparatorConfig Deserialize(const Json::Value& json, const SeparatorConfig& defaultValue);
    };

    struct ImageSizesConfig
    {
        unsigned int smallSize = 80;
        unsigned int mediumSize = 120;
        unsigned int largeSize = 180;

        static ImageSizesConfig Deserialize(const Json::Value& json, const ImageSizesConfig& defaultValue);
    };

    struct ImageSetConfig
    {
        ImageSize imageSize = ImageSize::Auto;
        unsigned int maxImageHeight = 100;

        static ImageSetConfig Deserialize(const Json::Value& json, const ImageSetConfig& defaultValue);
    };

    struct ImageConfig
    {
        ImageSize imageSize = ImageSize::Auto;

        static ImageConfig Deserialize(const Json::Value& json, const ImageConfig& defaultValue);
    };

    struct AdaptiveCardConfig
    {
        bool allowCustomStyle = true;

        static AdaptiveCardConfig Deserialize(const Json::Value& json, const AdaptiveCardConfig& defaultValue);
    };

    struct FactSetConfig
    {
        TextConfig title{TextWeight::Bolder, TextSize::Default, FontStyle::Default, ForegroundColor::Default, false, true, 150};
        TextConfig value{TextWeight::Default, TextSize::Default, FontStyle::Default, ForegroundColor::Default, false, true, ~0U};
        unsigned int spacing = 10;

        static FactSetConfig Deserialize(const Json::Value& json, const FactSetConfig& defaultValue);
    };

    struct ContainerStyleDefinition
    {
        std::string backgroundColor = "#FFFFFFFF";
        std::string borderColor = "#FF7F7F7F7F"; // CAUTION: Experimental feature for iOS. Not in v1 schema, subject to change.
        unsigned int borderThickness = 0; // CAUTION: Experimental feature for iOS. Not in v1 schema, subject to change.
        ColorsConfig foregroundColors;

        static ContainerStyleDefinition Deserialize(const Json::Value& json, const ContainerStyleDefinition& defaultValue);
    };

    struct ContainerStylesDefinition
    {
        ContainerStyleDefinition defaultPalette;
        ContainerStyleDefinition emphasisPalette = {"#08000000",
                                                    "#08000000",
                                                    0,
                                                    {
                                                        {"#FF000000", "#B2000000"}, // defaultColor
                                                        {"#FF0000FF", "#B20000FF"}, // accent
                                                        {"#FF101010", "#B2101010"}, // dark
                                                        {"#FFFFFFFF", "#B2FFFFFF"}, // light
                                                        {"#FF008000", "#B2008000"}, // good
                                                        {"#FFFFD700", "#B2FFD700"}, // warning
                                                        {"#FF8B0000", "#B28B0000"}  // attention
                                                    }};

        static ContainerStylesDefinition Deserialize(const Json::Value& json, const ContainerStylesDefinition& defaultValue);
    };

    struct ShowCardActionConfig
    {
        ActionMode actionMode = ActionMode::Inline;
        ContainerStyle style = ContainerStyle::Emphasis;
        unsigned int inlineTopMargin = 16;

        static ShowCardActionConfig Deserialize(const Json::Value& json, const ShowCardActionConfig& defaultValue);
    };

    struct ActionsConfig
    {
        ShowCardActionConfig showCard;
        ActionsOrientation actionsOrientation = ActionsOrientation::Horizontal;
        ActionAlignment actionAlignment = ActionAlignment::Stretch;
        unsigned int buttonSpacing = 10;
        unsigned int maxActions = 5;
        Spacing spacing = Spacing::Default;
        IconPlacement iconPlacement = IconPlacement::AboveTitle;
        unsigned int iconSize = 30;

        static ActionsConfig Deserialize(const Json::Value& json, const ActionsConfig& defaultValue);
    };

    struct MediaConfig
    {
        std::string defaultPoster;
        std::string playButton;
        bool allowInlinePlayback = true;

        static MediaConfig Deserialize(const Json::Value& json, const MediaConfig& defaultValue);
    };

    class HostConfig
    {
    public:
        HostConfig();
        static HostConfig Deserialize(const Json::Value& json);
        static HostConfig DeserializeFromString(const std::string jsonString);

        FontStyleDefinition GetFontStyle(FontStyle style);
        std::string GetFontFamily(FontStyle style);
        unsigned int GetFontSize(FontStyle style, TextSize size);
        unsigned int GetFontWeight(FontStyle style, TextWeight weight);

        std::string GetFontFamily() const;
        void SetFontFamily(const std::string& value);

        FontSizesConfig GetFontSizes() const;
        void SetFontSizes(const FontSizesConfig value);

        FontWeightsConfig GetFontWeights() const;
        void SetFontWeights(const FontWeightsConfig value);

        FontStylesDefinition GetFontStyles() const;
        void SetFontStyles(const FontStylesDefinition value);

        bool GetSupportsInteractivity() const;
        void SetSupportsInteractivity(const bool value);

        std::string GetImageBaseUrl() const;
        void SetImageBaseUrl(const std::string& value);

        ImageSizesConfig GetImageSizes() const;
        void SetImageSizes(const ImageSizesConfig value);

        ImageConfig GetImage() const;
        void SetImage(const ImageConfig value);

        SeparatorConfig GetSeparator() const;
        void SetSeparator(const SeparatorConfig value);

        SpacingConfig GetSpacing() const;
        void SetSpacing(const SpacingConfig value);

        AdaptiveCardConfig GetAdaptiveCard() const;
        void SetAdaptiveCard(const AdaptiveCardConfig value);

        ImageSetConfig GetImageSet() const;
        void SetImageSet(const ImageSetConfig value);

        FactSetConfig GetFactSet() const;
        void SetFactSet(const FactSetConfig value);

        ActionsConfig GetActions() const;
        void SetActions(const ActionsConfig value);

        ContainerStylesDefinition GetContainerStyles() const;
        void SetContainerStyles(const ContainerStylesDefinition value);

        MediaConfig GetMedia() const;
        void SetMedia(const MediaConfig value);

    private:
        std::string fontFamily;
        FontSizesConfig fontSizes;
        FontWeightsConfig fontWeights;
        FontStylesDefinition fontStyles;
        bool supportsInteractivity = true;
        std::string imageBaseUrl;
        ImageSizesConfig imageSizes;
        ImageConfig image;
        SeparatorConfig separator;
        SpacingConfig spacing;
        AdaptiveCardConfig adaptiveCard;
        ImageSetConfig imageSet;
        FactSetConfig factSet;
        ActionsConfig actions;
        ContainerStylesDefinition containerStyles;
        MediaConfig media;
    };
}
