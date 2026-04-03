/*********************************************************************/
/* $Header: StringConversionFactory.cpp                              */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - StringConversionFactory                             */
/*                                                                   */
/* Description - Factory class responsible for creating string       */
/*               conversion strategy objects based on type.          */
/*                                                                   */
/* Notes       - Implements Factory design pattern                   */
/*               Returns unique_ptr to IStringConversion             */
/*                                                                   */
/* $Log: StringConversionFactory.cpp                                 */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
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

std::unique_ptr<IStringConversion> 
StringConversionFactory::create(ConversionType type) {
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