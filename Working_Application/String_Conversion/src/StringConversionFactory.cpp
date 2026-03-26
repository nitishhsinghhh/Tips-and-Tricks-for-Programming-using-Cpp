#include "StringConversionFactory.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"

std::unique_ptr<IStringConversion> StringConversionFactory::create(ConversionType type) {
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