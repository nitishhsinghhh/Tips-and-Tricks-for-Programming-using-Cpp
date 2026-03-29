#include "UpperCaseConversion.hpp"
#include <algorithm>
#include <cctype>

std::string UpperCaseConversion::convert(const std::string& input) const {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return result;
}