#include "RemoveVowelsConversion.hpp"
#include <algorithm>

std::string RemoveVowelsConversion::convert(const std::string& input) const {
    std::string result;
    for (char ch : input) {
        char lower = std::tolower(ch);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            result += ch;
        }
    }
    return result;
}