
#include "pch.h"
#include "BaseActionElement.h"
#include "ParseUtil.h"

using namespace AdaptiveSharedNamespace;

constexpr char BaseActionElement::defaultSentiment[];

BaseActionElement::BaseActionElement(ActionType type) :
    m_type(type), m_typeString(ActionTypeToString(type)), m_sentiment("default")
{
    PopulateKnownPropertiesSet();
}

std::string BaseActionElement::GetElementTypeString() const
{
    return m_typeString;
}

void BaseActionElement::SetElementTypeString(const std::string& value)
{
    m_typeString = value;
}

std::string BaseActionElement::GetTitle() const
{
    return m_title;
}

void BaseActionElement::SetTitle(const std::string& value)
{
    m_title = value;
}

std::string BaseActionElement::GetId() const
{
    return m_id;
}

void BaseActionElement::SetId(const std::string& value)
{
    m_id = value;
}

std::string BaseActionElement::GetIconUrl() const
{
    return m_iconUrl;
}

void BaseActionElement::SetIconUrl(const std::string& value)
{
    m_iconUrl = value;
}

std::string BaseActionElement::GetSentiment() const
{
    return m_sentiment;
}

void BaseActionElement::SetSentiment(const std::string& value)
{
    m_sentiment = value;
}

const ActionType BaseActionElement::GetElementType() const
{
    return m_type;
}

std::string BaseActionElement::Serialize() const
{
    Json::FastWriter writer;
    return writer.write(SerializeToJsonValue());
}

Json::Value BaseActionElement::SerializeToJsonValue() const
{
    Json::Value root = GetAdditionalProperties();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type)] = ActionTypeToString(m_type);
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Id)] = m_id;

    if (!m_title.empty())
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = m_title;
    }

    if (!m_sentiment.empty() && (m_sentiment != defaultSentiment))
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Sentiment)] = m_sentiment;
    }

    if (!m_iconUrl.empty())
    {
        root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IconUrl)] = m_iconUrl;
    }

    return root;
}

Json::Value BaseActionElement::GetAdditionalProperties() const
{
    return m_additionalProperties;
}

void BaseActionElement::SetAdditionalProperties(Json::Value const& value)
{
    m_additionalProperties = value;
}

void BaseActionElement::PopulateKnownPropertiesSet()
{
    m_knownProperties.insert({AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Id),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IconUrl),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Sentiment)});
}

void BaseActionElement::GetResourceInformation(std::vector<RemoteResourceInformation>& resourceInfo)
{
    if (!m_iconUrl.empty())
    {
        RemoteResourceInformation imageResourceInfo;
        imageResourceInfo.url = m_iconUrl;
        imageResourceInfo.mimeType = "image";
        resourceInfo.push_back(imageResourceInfo);
    }
}
