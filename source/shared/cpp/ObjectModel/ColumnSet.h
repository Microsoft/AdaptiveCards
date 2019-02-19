#pragma once

#include "pch.h"
#include "BaseCardElement.h"
#include "CollectionTypeElement.h"

namespace AdaptiveSharedNamespace
{
    class Column;

    class ColumnSet : public BaseCardElement, public CollectionTypeElement
    {
        friend class ColumnSetParser;

    public:
        ColumnSet();
        ColumnSet(const ColumnSet&) = default;
        ColumnSet(ColumnSet&&) = default;
        ColumnSet& operator=(const ColumnSet&) = default;
        ColumnSet& operator=(ColumnSet&&) = default;
        ~ColumnSet() = default;

        Json::Value SerializeToJsonValue() const override;

        std::vector<std::shared_ptr<Column>>& GetColumns();
        const std::vector<std::shared_ptr<Column>>& GetColumns() const;

        std::shared_ptr<BaseActionElement> GetSelectAction() const;
        void SetSelectAction(const std::shared_ptr<BaseActionElement> action);

        void SetLanguage(const std::string& language);

        void GetResourceInformation(std::vector<RemoteResourceInformation>& resourceInfo) override;

    private:
        void PopulateKnownPropertiesSet() override;

        std::vector<std::shared_ptr<Column>> m_columns;
        std::shared_ptr<BaseActionElement> m_selectAction;
    };

    class ColumnSetParser : public BaseCardElementParser
    {
    public:
        ColumnSetParser() = default;
        ColumnSetParser(const ColumnSetParser&) = default;
        ColumnSetParser(ColumnSetParser&&) = default;
        ColumnSetParser& operator=(const ColumnSetParser&) = default;
        ColumnSetParser& operator=(ColumnSetParser&&) = default;
        virtual ~ColumnSetParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& context, const std::string& jsonString) override;
    };
}
