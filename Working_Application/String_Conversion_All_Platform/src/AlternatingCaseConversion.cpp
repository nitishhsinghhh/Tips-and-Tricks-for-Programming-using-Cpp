#include "AlternatingCaseConversion.hpp"
#include <cctype>

std::string AlternatingCaseConversion::convert(const std::string& input) const {
    std::string result;
    bool upper = true;

    for (char c : input) {
        if (std::isalpha(c)) {
            result += upper ? std::toupper(c) : std::tolower(c);
            upper = !upper;
        } else {
            result += c;
            if (c == ' ') {   // reset alternation after space
                upper = true;
            }
        }
    }
    return result;
}