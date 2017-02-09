#include "ParseUtil.h"
#include "AdaptiveCardParseException.h"

namespace AdaptiveCards
{

void ParseUtil::ThrowIfNotJsonObject(const Json::Value& json)
{
    if (!json.isObject()) {
        throw AdaptiveCardParseException("Expected JSON Object\n");
    }
}

void ParseUtil::ExpectString(const Json::Value& json)
{
    if (!json.isString())
    {
        throw AdaptiveCardParseException("The JSON element did not have the expected type 'string'");
    }
}

std::string ParseUtil::GetTypeAsString(const Json::Value& json)
{
    std::string typeKey = "@type";
    if (!json.isMember(typeKey))
    {
        throw AdaptiveCardParseException("The JSON element is missing the following value: " + typeKey);
    }

    return json.get(typeKey, Json::Value()).asString();
}

std::string ParseUtil::TryGetTypeAsString(const Json::Value& json)
{
    try
    {
        return GetTypeAsString(json);
    }
    catch (const AdaptiveCardParseException&)
    {
        return "";
    }

}

std::string ParseUtil::GetString(const Json::Value& json, AdaptiveCardSchemaKey key)
{
    std::string propertyName = AdaptiveCardSchemaKeyToString(key);
    auto propertyValue = json.get(propertyName, Json::Value());
    if (propertyValue.empty())
    {
        return "";
    }

    if (!propertyValue.isString())
    {
        throw AdaptiveCardParseException("Value was invalid. Expected type string.");
    }

    return propertyValue.asString();
}

void ParseUtil::ExpectTypeString(const Json::Value& json, CardElementType bodyType)
{
    std::string actualType = GetTypeAsString(json);
    std::string expectedTypeStr = CardElementTypeToString(bodyType);
    bool isTypeCorrect = expectedTypeStr.compare(actualType) == 0;
    if (!isTypeCorrect)
    {
        throw AdaptiveCardParseException("The JSON element did not have the correct type. Expected: " + expectedTypeStr + ", Actual: " + actualType);
    }
}

// throws if the key is missing or the value mapped to the key is the wrong type
void ParseUtil::ExpectKeyAndValueType(const Json::Value& json, const char* expectedKey, std::function<void(const Json::Value&)> throwIfWrongType)
{
    if (expectedKey == nullptr)
    {
        throw AdaptiveCardParseException("null expectedKey");
    }

    if (!json.isMember(expectedKey))
    {
        throw AdaptiveCardParseException("The JSON element is missing the following key: " + std::string(expectedKey));
    }

    auto value = json.get(expectedKey, Json::Value());
    throwIfWrongType(value);
}

CardElementType ParseUtil::GetCardElementType(const Json::Value& json)
{
    std::string actualType = GetTypeAsString(json);
    try
    {
        return CardElementTypeFromString(actualType);
    }
    catch (const std::out_of_range&)
    {
        throw AdaptiveCardParseException("Invalid CardElementType");
    }
}

CardElementType ParseUtil::TryGetCardElementType(const Json::Value& json)
{
    try
    {
        return GetCardElementType(json);
    }
    catch (const AdaptiveCardParseException&)
    {
        return CardElementType::Unsupported;
    }
}

ParseUtil::ParseUtil()
{
}

ParseUtil::~ParseUtil()
{
}

}