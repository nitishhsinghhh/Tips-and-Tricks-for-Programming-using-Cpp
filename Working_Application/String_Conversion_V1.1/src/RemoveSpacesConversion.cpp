#include "RemoveSpacesConversion.hpp"
#include <algorithm>

std::string RemoveSpacesConversion::convert(const std::string& input) const {
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}