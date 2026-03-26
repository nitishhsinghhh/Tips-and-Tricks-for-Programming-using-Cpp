#ifndef STRINGCONVERSIONFACTORY_HPP
#define STRINGCONVERSIONFACTORY_HPP

#include <memory>
#include "IStringConversion.hpp"

enum class ConversionType {
    Lower,
    Upper,
    Capitalize,
    Sentence,
    Toggle
};

class StringConversionFactory {
public:
    static std::unique_ptr<IStringConversion> create(ConversionType type);
};

#endif // STRINGCONVERSIONFACTORY_HPP