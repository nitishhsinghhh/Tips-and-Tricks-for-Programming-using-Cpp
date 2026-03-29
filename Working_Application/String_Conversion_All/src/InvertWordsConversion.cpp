#include "InvertWordsConversion.hpp"
#include <sstream>
#include <algorithm>

std::string InvertWordsConversion::convert(const std::string& input) const {
    std::istringstream iss(input);
    std::ostringstream oss;
    std::string word;
    bool first = true;
    while (iss >> word) {
        std::reverse(word.begin(), word.end());
        if (!first) oss << ' ';
        oss << word;
        first = false;
    }
    return oss.str();
}