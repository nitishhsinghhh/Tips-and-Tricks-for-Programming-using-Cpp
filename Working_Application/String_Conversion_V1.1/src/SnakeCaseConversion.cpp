#include "SnakeCaseConversion.hpp"
#include <algorithm>
#include <cctype>

std::string SnakeCaseConversion::convert(const std::string& input) const {
    std::string result;
    for (char ch : input) {
        if (std::isspace(ch)) {
            result += '_';
        } else {
            result += std::tolower(ch);
        }
    }
    return result;
}