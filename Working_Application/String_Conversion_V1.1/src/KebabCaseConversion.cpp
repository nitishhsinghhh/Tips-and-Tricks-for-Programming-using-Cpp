#include "KebabCaseConversion.hpp"
#include <algorithm>
#include <cctype>

std::string KebabCaseConversion::convert(const std::string& input) const {
    std::string result;
    for (char ch : input) {
        if (std::isspace(ch)) {
            result += '-';
        } else {
            result += std::tolower(ch);
        }
    }
    return result;
}