#pragma once
#include "DateTimePreparser.h"

#include <codecvt>
#include <string>

AdaptiveNamespaceStart
    class DateTimeParser
    {
    public:
        DateTimeParser(const std::string& language);
        std::string GenerateString(DateTimePreparser text);

    private:
        std::string m_languageString;
    };
AdaptiveNamespaceEnd
