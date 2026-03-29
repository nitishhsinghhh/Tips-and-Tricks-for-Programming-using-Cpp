#ifndef REMOVESPACECONVERSION_HPP
#define REMOVESPACECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class RemoveSpacesConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // REMOVESPACECONVERSION_HPP