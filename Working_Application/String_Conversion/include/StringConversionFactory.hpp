#ifndef STRINGCONVERSIONFACTORY_HPP
#define STRINGCONVERSIONFACTORY_HPP

#include <memory>
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"

enum class ConversionType {
    Lower,
    Upper,
    Capitalize,
    Sentence,
    Toggle
};

class StringConversionFactory {
public:
    static std::unique_ptr<IStringConversion> create(ConversionType type) {
        switch (type) {
            case ConversionType::Lower:
                return std::make_unique<LowerCaseConversion>();
            case ConversionType::Upper:
                return std::make_unique<UpperCaseConversion>();
            case ConversionType::Capitalize:
                return std::make_unique<CapitalizeWordsConversion>();
            case ConversionType::Sentence:
                return std::make_unique<SentenceCaseConversion>();
            case ConversionType::Toggle:
                return std::make_unique<ToggleCaseConversion>();
        }
        return nullptr; // fallback
    }
};

#endif // STRINGCONVERSIONFACTORY_HPP