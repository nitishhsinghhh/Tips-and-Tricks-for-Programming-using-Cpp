#ifndef LOWERCASECONVERSION_HPP
#define LOWERCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <algorithm>
#include <cctype>

class LowerCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // LOWERCASECONVERSION_HPP