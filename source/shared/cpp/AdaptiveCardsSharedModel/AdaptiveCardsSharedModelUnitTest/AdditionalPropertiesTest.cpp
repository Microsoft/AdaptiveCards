#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBlock.h"
#include <time.h>
#include <Windows.h>
#include <StrSafe.h>
#include "SharedAdaptiveCard.h"
#include "BaseCardElement.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdaptiveCards;
using namespace std;

namespace AdaptiveCardsSharedModelUnitTest
{
    TEST_CLASS(AdditionalPropertyTest)
    {
    public:
        TEST_METHOD(CanGetAdditionalProperitesTest)
        {
            std::string testJsonString = 
            "{\
                \"$schema\":\"http://adaptivecards.io/schemas/adaptive-card.json\",\
                \"type\": \"AdaptiveCard\",\
                \"version\": \"1.0\",\
                \"body\": [\
                    {\
                        \"type\": \"TextBlock\",\
                        \"text\": \"You can even draw attention to certain text with color\",\
                        \"wrap\": true,\
                        \"color\": \"attention\",\
                        \"unknown\": \"testing unknown\"\
                    }\
                ]\
            }";
            std::shared_ptr<AdaptiveCard> adaptiveCard = AdaptiveCard::DeserializeFromString(testJsonString);
            std::shared_ptr<BaseCardElement> elem =  adaptiveCard->GetBody().front();
            Json::Value value = elem->GetAdditionalProperties();
            Json::FastWriter fastWriter;
            std::string jsonString = fastWriter.write(value);

            std::string expected = "{\"color\":\"attention\",\"text\":\"You can even draw attention to certain text with color\",\"unknown\":\"testing unknown\",\"wrap\":true}\n";
            Assert::AreEqual(jsonString, expected);
        }
    };
}
