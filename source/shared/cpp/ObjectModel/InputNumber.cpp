#include "InputNumber.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

InputNumber::InputNumber() :
    BaseCardElement(CardElementType::InputNumber),
    m_min(std::numeric_limits<int>::min()),
    m_max(std::numeric_limits<int>::max())
{
}

std::shared_ptr<InputNumber> InputNumber::Deserialize(const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::InputNumber);

    std::shared_ptr<InputNumber> inputNumber = BaseCardElement::Deserialize<InputNumber>(json);

    inputNumber->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    inputNumber->SetValue(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Value, 0));
    inputNumber->SetMax(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Max, INT_MAX));
    inputNumber->SetMin(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Min, INT_MIN));

    return inputNumber;
}

std::shared_ptr<InputNumber> InputNumber::DeserializeFromString(const std::string& jsonString)
{
    Json::Value jsonValue(jsonString);

    return InputNumber::Deserialize(jsonValue);
}

std::string InputNumber::Serialize()
{
    return "";
}

std::string InputNumber::GetPlaceholder() const
{
    return m_placeholder;
}

void InputNumber::SetPlaceholder(const std::string value)
{
    m_placeholder = value;
}

int InputNumber::GetValue() const
{
    return m_value;
}

void InputNumber::SetValue(const int value)
{
    m_value = value;
}

int InputNumber::GetMax() const
{
    return m_max;
}

void InputNumber::SetMax(const int value)
{
    m_max = value;
}

int InputNumber::GetMin() const
{
    return m_min;
}

void InputNumber::SetMin(const int value)
{
    m_min = value;
}