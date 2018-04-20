#include "pch.h"
#include "Util.h"
#include "ColumnSet.h"
#include "Container.h"
#include "TextBlock.h"

void PropagateLanguage(const std::string& language, std::vector<std::shared_ptr<BaseCardElement>>& m_body)
{
    for (auto& bodyElement : m_body)
    {
        CardElementType elementType = bodyElement->GetElementType();

        if (elementType == CardElementType::ColumnSet)
        {
            auto columnSet = std::static_pointer_cast<ColumnSet>(bodyElement);
            if (columnSet != nullptr)
            {
                columnSet->SetLanguage(language);
            }
        }
        else if (elementType == CardElementType::Container)
        {
            auto container = std::static_pointer_cast<Container>(bodyElement);
            if (container != nullptr)
            {
                container->SetLanguage(language);
            }
        }
        else if (bodyElement->GetElementType() == CardElementType::TextBlock)
        {
            auto textBlock = std::static_pointer_cast<TextBlock>(bodyElement);
            if (textBlock != nullptr)
            {
                textBlock->SetLanguage(language);
            }
        }

    }

}

void validateUserInputForDimensionWithUnit(const std::string &unit, const std::vector<std::string> &requestedDimensions, std::vector<int> &parsedDimensions)
{
    for(auto eachDimension : requestedDimensions)
    { 
        if (eachDimension.empty())
        {
            parsedDimensions.push_back(0);
        }
        else
        {
            std::size_t foundIndex = eachDimension.find(unit);
            if (eachDimension.size() != foundIndex + unit.size())
            {
                throw AdaptiveCardParseException(ErrorStatusCode::InvalidPropertyValue, "unit is either missing or inproper form: " + eachDimension);
            }
            try
            {
                float parsedVal = stof(eachDimension.substr(0, foundIndex));
                if(parsedVal != (int) parsedVal || parsedVal < 0)
                {
                    throw AdaptiveCardParseException(ErrorStatusCode::InvalidPropertyValue, "unsigned integer is accepted but received : " + eachDimension);
                }
                parsedDimensions.push_back((int)parsedVal);
            }
            catch (const std::invalid_argument &e)
            {
                (void)e;
                throw AdaptiveCardParseException(ErrorStatusCode::InvalidPropertyValue, "unsigned integer is accepted but received : " + eachDimension);
            }
            catch (const std::out_of_range &e)
            {
                (void)e;
                throw AdaptiveCardParseException(ErrorStatusCode::InvalidPropertyValue, "out of range: " + eachDimension);
            }
        }
    }
}
