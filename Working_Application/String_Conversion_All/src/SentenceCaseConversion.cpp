#include "SentenceCaseConversion.hpp"
#include <cctype>

std::string SentenceCaseConversion::convert(const std::string& input) const {
    if (input.empty()) return input;

    std::string result = input;
    result[0] = std::toupper(static_cast<unsigned char>(result[0]));

    for (size_t i = 1; i < result.size(); ++i)
        result[i] = std::tolower(static_cast<unsigned char>(result[i]));

    return result;
}