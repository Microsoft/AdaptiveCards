#include "BaseCardElement.h"
#include "HttpAction.h"
#include "ShowCardAction.h"
#include "OpenUrlAction.h"
#include "ParseUtil.h"
#include "SubmitAction.h"

using namespace AdaptiveCards;

const std::unordered_map<ActionType, std::function<std::shared_ptr<BaseActionElement>(const Json::Value&)>, EnumHash> BaseCardElement::ActionParsers =
{
    { ActionType::Http, HttpAction::Deserialize },
    { ActionType::OpenUrl, OpenUrlAction::Deserialize },
    { ActionType::ShowCard, ShowCardAction::Deserialize },
    { ActionType::Submit, SubmitAction::Deserialize },
};

BaseCardElement::BaseCardElement(
    CardElementType type,
    Spacing spacing,
    std::shared_ptr<Separator> separator) :
    m_type(type),
    m_spacing(spacing),
    m_separator(separator)
{
}

BaseCardElement::BaseCardElement(CardElementType type) :
    m_type(type), m_spacing(Spacing::Default)
{
}

AdaptiveCards::BaseCardElement::~BaseCardElement()
{
}

std::shared_ptr<Separator> BaseCardElement::GetSeparator() const
{
    return m_separator;
}

void BaseCardElement::SetSeparator(const std::shared_ptr<Separator> value)
{
    m_separator = value;
}

Spacing BaseCardElement::GetSpacing() const
{
    return m_spacing;
}

void BaseCardElement::SetSpacing(const Spacing value)
{
    m_spacing = value;
}

const CardElementType AdaptiveCards::BaseCardElement::GetElementType() const
{
    return m_type;
}

Json::Value BaseCardElement::SerializeToJsonValue()
 {
    Json::Value root;
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Type)] = CardElementTypeToString(GetElementType());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Spacing)] = SpacingToString(GetSpacing());

    Json::Value jsonSeparator;
    jsonSeparator[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Color)] = ColorToString(GetSeparator()->GetColor());
    jsonSeparator[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Thickness)] = SeparatorThicknessToString(GetSeparator()->GetThickness());

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Separator)] = jsonSeparator;

    return root;
}

std::shared_ptr<BaseActionElement> BaseCardElement::DeserializeSelectAction(const Json::Value & json, AdaptiveCardSchemaKey key)
{
    Json::Value selectActionValue = ParseUtil::ExtractJsonValue(json, key, false);
    if (!selectActionValue.empty())
    {
        return ParseUtil::GetActionFromJsonValue<BaseActionElement>(selectActionValue, BaseCardElement::ActionParsers);
    }
    return nullptr;
}

Json::Value BaseCardElement::SerializeSelectAction(const std::shared_ptr<BaseActionElement> selectAction)
{
    if (selectAction != nullptr)
    {
        return selectAction->SerializeToJsonValue();
    }
    return Json::Value();
}
