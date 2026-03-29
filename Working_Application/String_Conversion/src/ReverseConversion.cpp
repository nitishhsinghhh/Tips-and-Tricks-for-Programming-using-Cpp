// ReverseConversion.cpp
#include "ReverseConversion.hpp"
#include <algorithm>

std::string ReverseConversion::convert(const std::string& input) const {
    std::string result = input;
    std::reverse(result.begin(), result.end());
    return result;
}
