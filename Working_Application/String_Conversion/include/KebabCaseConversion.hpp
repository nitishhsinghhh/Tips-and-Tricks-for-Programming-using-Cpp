#ifndef KEBABCASECONVERSION_HPP
#define KEBABCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class KebabCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // KEBABCASECONVERSION_HPP