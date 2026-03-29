#ifndef SNAKECASECONVERSION_HPP
#define SNAKECASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class SnakeCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // SNAKECASECONVERSION_HPP