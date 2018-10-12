#pragma once
#include "DateTimePreparser.h"

#include <codecvt>
#include <string>

namespace AdaptiveNamespace
{
    class DateTimeParser
    {
    public:
        DateTimeParser(const std::string& language);
        std::string GenerateString(DateTimePreparser text);

    private:
        std::string m_languageString;
    };
}
