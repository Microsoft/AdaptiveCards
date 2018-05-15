#include "pch.h"
#include "Image.h"
#include "ParseUtil.h"
#include "Util.h"

using namespace AdaptiveSharedNamespace;

Image::Image() :
    BaseCardElement(CardElementType::Image),
    m_imageStyle(ImageStyle::Default),
    m_imageSize(ImageSize::None),
    m_pixelWidth(0),
    m_pixelHeight(0),
    m_hAlignment(HorizontalAlignment::Left)
{
    PopulateKnownPropertiesSet();
}

Json::Value Image::SerializeToJsonValue()
{
    const char pixelstring[] = "px";

    Json::Value root = BaseCardElement::SerializeToJsonValue();

    if (m_pixelWidth || m_pixelHeight)
    {
        if (m_pixelWidth)
        {
            std::ostringstream stringStream;
            stringStream << m_pixelWidth;

            std::string widthString = stringStream.str() + pixelstring;
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width)] = widthString;
        }
        if (m_pixelHeight)
        {
            std::ostringstream stringStream;
            stringStream << m_pixelHeight;

            std::string heightString = stringStream.str() + pixelstring;
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Height)] = heightString;
        }
    }
    else if (m_imageSize != ImageSize::None)
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Size)] = ImageSizeToString(m_imageSize);
    }

    if (m_imageStyle != ImageStyle::Default)
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Style)] = ImageStyleToString(m_imageStyle);
    }

    if (!m_url.empty())
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Url)] = m_url;
    }

    if (m_hAlignment != HorizontalAlignment::Left)
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::HorizontalAlignment)] =
            HorizontalAlignmentToString(m_hAlignment);
    }

    if (!m_altText.empty())
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::AltText)] = m_altText;
    }

    if (m_selectAction != nullptr)
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::SelectAction)] = BaseCardElement::SerializeSelectAction(m_selectAction);
    }

    return root;
}

std::string Image::GetUrl() const
{
    return m_url;
}

void Image::SetUrl(const std::string value)
{
    m_url = value;
}

ImageStyle Image::GetImageStyle() const
{
    return m_imageStyle;
}

void Image::SetImageStyle(const ImageStyle value)
{
    m_imageStyle = value;
}

ImageSize Image::GetImageSize() const
{
    return m_imageSize;
}

void Image::SetImageSize(const ImageSize value)
{
    m_imageSize = value;
}

std::string Image::GetAltText() const
{
    return m_altText;
}

void Image::SetAltText(const std::string value)
{
    m_altText = value;
}

HorizontalAlignment Image::GetHorizontalAlignment() const
{
    return m_hAlignment;
}

void Image::SetHorizontalAlignment(const HorizontalAlignment value)
{
    m_hAlignment = value;
}

std::shared_ptr<BaseActionElement> Image::GetSelectAction() const
{
    return m_selectAction;
}

void Image::SetSelectAction(const std::shared_ptr<BaseActionElement> action)
{
    m_selectAction = action;
}

unsigned int Image::GetPixelWidth() const 
{
    return m_pixelWidth;
}

void Image::SetPixelWidth(unsigned int value)
{
    m_pixelWidth = value;
}

unsigned int Image::GetPixelHeight() const
{
    return m_pixelHeight;
}

void Image::SetPixelHeight(unsigned int value)
{
    m_pixelHeight = value;
}

std::shared_ptr<BaseCardElement> ImageParser::DeserializeFromString(
    std::shared_ptr<ElementParserRegistration> elementParserRegistration,
    std::shared_ptr<ActionParserRegistration> actionParserRegistration,
    const std::string& jsonString)
{
    return ImageParser::Deserialize(elementParserRegistration, actionParserRegistration, ParseUtil::GetJsonValueFromString(jsonString));
}

std::shared_ptr<BaseCardElement> ImageParser::Deserialize(
    std::shared_ptr<ElementParserRegistration> elementParserRegistration,
    std::shared_ptr<ActionParserRegistration> actionParserRegistration,
    const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::Image);
    return ImageParser::DeserializeWithoutCheckingType(elementParserRegistration, actionParserRegistration, json);
}

std::shared_ptr<BaseCardElement> ImageParser::DeserializeWithoutCheckingType(
    std::shared_ptr<ElementParserRegistration> elementParserRegistration,
    std::shared_ptr<ActionParserRegistration> actionParserRegistration,
    const Json::Value& json)
{
    std::shared_ptr<Image> image = BaseCardElement::Deserialize<Image>(json);

    image->SetUrl(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Url, true));
    image->SetImageStyle(ParseUtil::GetEnumValue<ImageStyle>(json, AdaptiveCardSchemaKey::Style, ImageStyle::Default, ImageStyleFromString));
    image->SetAltText(ParseUtil::GetString(json, AdaptiveCardSchemaKey::AltText));
    image->SetHorizontalAlignment(ParseUtil::GetEnumValue<HorizontalAlignment>(json, AdaptiveCardSchemaKey::HorizontalAlignment, HorizontalAlignment::Left, HorizontalAlignmentFromString));

    std::vector<std::string> requestedDimensions;
    std::string imageWidth = ParseUtil::GetValueAsString(json, AdaptiveCardSchemaKey::Width);
    std::string imageHeight = ParseUtil::GetValueAsString(json, AdaptiveCardSchemaKey::Height);
    requestedDimensions.push_back(imageWidth);
    requestedDimensions.push_back(imageHeight);

    // validate user inputs
    
    if ( (!imageHeight.empty() && (isdigit(imageHeight.at(0)) || ('-' == imageHeight.at(0)))) || 
        (!imageWidth.empty() && (isdigit(imageWidth.at(0)) || ('-' == imageWidth.at(0)))))
    {
        const std::string unit = "px";
        std::size_t foundIndexHeight = imageHeight.find(unit);
        std::size_t foundIndexWidth = imageWidth.find(unit);
        /// check if width is determined explicitly
        if (std::string::npos != foundIndexHeight || std::string::npos != foundIndexWidth)
        {
            std::vector<int> parsedDimensions;
            ValidateUserInputForDimensionWithUnit(unit, requestedDimensions, parsedDimensions);

            if (parsedDimensions[0] != 0 || parsedDimensions[1] != 0)
            {
                image->SetPixelWidth(parsedDimensions[0]);
                image->SetPixelHeight(parsedDimensions[1]);
            }

        }
    }
    else
    {
        image->SetImageSize(ParseUtil::GetEnumValue<ImageSize>(json, AdaptiveCardSchemaKey::Size, ImageSize::None, ImageSizeFromString));
    }

    // Parse optional selectAction
    image->SetSelectAction(ParseUtil::GetSelectAction(elementParserRegistration, actionParserRegistration, json, AdaptiveCardSchemaKey::SelectAction, false));

    return image;
}

void Image::PopulateKnownPropertiesSet() 
{
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Url));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Style));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Size));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::AltText));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::HorizontalAlignment));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Height));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::SelectAction));
}

void Image::GetResourceUris(std::vector<std::string>& resourceUris)
{
    auto url = GetUrl();
    resourceUris.push_back(url);
    return;
}