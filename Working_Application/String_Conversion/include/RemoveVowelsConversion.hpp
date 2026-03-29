#ifndef REMOVEVOWELSCONVERSION_HPP
#define REMOVEVOWELSCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class RemoveVowelsConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // REMOVEVOWELSCONVERSION_HPP