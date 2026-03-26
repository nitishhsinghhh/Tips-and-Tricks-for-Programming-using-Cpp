#ifndef UPPERCASECONVERSION_HPP
#define UPPERCASECONVERSION_HPP

#include "IStringConversion.hpp"

class UpperCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // UPPERCASECONVERSION_HPP