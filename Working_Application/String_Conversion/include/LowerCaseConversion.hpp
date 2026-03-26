#ifndef LOWERCASECONVERSION_HPP
#define LOWERCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <algorithm>
#include <cctype>

class LowerCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return result;
    }
};

#endif // LOWERCASECONVERSION_HPP