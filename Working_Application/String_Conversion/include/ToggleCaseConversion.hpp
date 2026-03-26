#ifndef TOGGLECASECONVERSION_HPP
#define TOGGLECASECONVERSION_HPP

#include "IStringConversion.hpp"

class ToggleCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // TOGGLECASECONVERSION_HPP