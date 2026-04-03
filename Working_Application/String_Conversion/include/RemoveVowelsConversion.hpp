/*********************************************************************/
/* $Header: RemoveVowelsConversion.hpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - RemoveVowelsConversion.hpp                           */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               removes all vowels from a string.                   */
/*               This class implements the IStringConversion         */
/*               interface and eliminates all vowel characters       */
/*               (a, e, i, o, u, both uppercase and lowercase).     */
/*               Useful for creating compact identifiers or          */
/*               stylized text where vowels are omitted.             */
/*                                                                   */
/* Notes       - Removes all vowels from the input string.           */
/*                                                                   */
/* $Log: RemoveVowelsConversion.hpp                                  */
/*********************************************************************/

#ifndef REMOVEVOWELSCONVERSION_HPP
#define REMOVEVOWELSCONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class RemoveVowelsConversion
 * @brief Concrete implementation of IStringConversion that removes all vowels from a string.
 *
 * This class transforms input strings by eliminating all vowel characters,
 * producing a string without vowels.
 *
 * Example usage:
 * @code
 * RemoveVowelsConversion conv;
 * std::string result = conv.convert("Hello World");
 * // result == "Hll Wrld"
 * @endcode
 */
class RemoveVowelsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by removing all vowels.
     * @param input The original string to convert.
     * @return A new string with all vowels removed.
     */
    std::string convert(const std::string& input) const override;
};

#endif // REMOVEVOWELSCONVERSION_HPP