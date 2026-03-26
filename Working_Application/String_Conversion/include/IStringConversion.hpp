#ifndef ISTRINGCONVERSION_HPP
#define ISTRINGCONVERSION_HPP

#include <string>

class IStringConversion {
public:
    virtual std::string convert(const std::string& input) const = 0;
    virtual ~IStringConversion() = default;
};

#endif // ISTRINGCONVERSION_HPP