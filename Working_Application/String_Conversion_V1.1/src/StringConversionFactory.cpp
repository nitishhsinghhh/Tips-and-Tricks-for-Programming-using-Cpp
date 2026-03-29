#include "StringConversionFactory.hpp"
#include "StringConversionFactory.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"
#include "ReverseConversion.hpp"
#include "RemoveVowelsConversion.hpp"
#include "RemoveSpacesConversion.hpp"
#include "InvertWordsConversion.hpp"
#include "SnakeCaseConversion.hpp"
#include "KebabCaseConversion.hpp"
#include "LeetSpeakConversion.hpp"
#include "SnakeCaseConversion.hpp"
#include "LeetSpeakConversion.hpp"

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
        case ConversionType::Alternating:
            return std::make_unique<AlternatingCaseConversion>();
        case ConversionType::Reverse:
            return std::make_unique<ReverseConversion>();
        case ConversionType::RemoveVowels: 
            return std::make_unique<RemoveVowelsConversion>();
        case ConversionType::RemoveSpaces:
            return std::make_unique<RemoveSpacesConversion>();
        case ConversionType::InvertWords: 
            return std::make_unique<InvertWordsConversion>();
        case ConversionType::SnakeCase: 
            return std::make_unique<SnakeCaseConversion>();
        case ConversionType::KebabCase: 
            return std::make_unique<KebabCaseConversion>();
        case ConversionType::LeetSpeak: 
            return std::make_unique<LeetSpeakConversion>();
        default:
            break;
    }
    return nullptr; // fallback
}