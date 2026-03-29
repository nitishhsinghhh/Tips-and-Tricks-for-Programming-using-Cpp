#include "AlternatingCaseConversion.hpp"
#include <cctype>

std::string AlternatingCaseConversion::convert(const std::string& input) const {
    std::string result;
    result.reserve(input.size());
    bool upper = true; // Start with uppercase

    for (char ch : input) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            if (upper) {
                result += std::toupper(static_cast<unsigned char>(ch));
            } else {
                result += std::tolower(static_cast<unsigned char>(ch));
            }
            upper = !upper; // Flip case for next character
        } else {
            result += ch; // Non-alphabet characters remain the same
        }
    }

    return result;
}