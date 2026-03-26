#ifndef UPPERCASECONVERSION_HPP
#define UPPERCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <algorithm>
#include <cctype>

class UpperCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::toupper(c); });
        return result;
    }
};

#endif // UPPERCASECONVERSION_HPP