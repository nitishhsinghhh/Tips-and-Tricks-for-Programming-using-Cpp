#include "LowerCaseConversion.hpp"
#include <algorithm>
#include <cctype>

std::string LowerCaseConversion::convert(const std::string& input) const {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}