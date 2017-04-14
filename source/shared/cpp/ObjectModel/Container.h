#pragma once

#include "Enums.h"
#include "pch.h"
#include "BaseCardElement.h"

namespace AdaptiveCards
{
class Container : public BaseCardElement
{
public:
    Container();
    Container(SeparationStyle separation, std::string speak);
    Container(SeparationStyle separation, std::string speak, std::vector<std::shared_ptr<BaseCardElement>>& items);

    virtual std::string Serialize();

    std::vector<std::shared_ptr<BaseCardElement>>& GetItems();
    const std::vector<std::shared_ptr<BaseCardElement>>& GetItems() const;

    static std::shared_ptr<Container> Deserialize(const Json::Value& root);
    static std::shared_ptr<Container> DeserializeFromString(const std::string& jsonString);

protected:
    static const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Json::Value&)>, EnumHash> CardElementParsers;
    void SetItems(std::vector<std::shared_ptr<BaseCardElement>>& items);

private:
    std::vector<std::shared_ptr<AdaptiveCards::BaseCardElement>> m_items;
};
}