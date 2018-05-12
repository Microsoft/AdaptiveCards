#pragma once

#include "pch.h"
#include "BaseActionElement.h"
#include "Enums.h"
#include "ActionParserRegistration.h"

AdaptiveSharedNamespaceStart
class SubmitAction : public BaseActionElement
{
public:
    SubmitAction();

    std::string GetDataJson() const;
    Json::Value GetDataJsonAsValue() const;
    void SetDataJson(const Json::Value &value);

    virtual Json::Value SerializeToJsonValue() override;

private:
    void PopulateKnownPropertiesSet();

    Json::Value m_dataJson;
};

class SubmitActionParser : public ActionElementParser
{
    std::shared_ptr<BaseActionElement> Deserialize(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration,
        const Json::Value& value);

    std::shared_ptr<BaseActionElement> DeserializeFromString(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration,
        const std::string& jsonString);
};
AdaptiveSharedNamespaceEnd
