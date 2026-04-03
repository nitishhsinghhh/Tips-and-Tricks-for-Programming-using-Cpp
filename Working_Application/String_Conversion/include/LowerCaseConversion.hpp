/*********************************************************************/
/* $Header: LowerCaseConversion.hpp                                   */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - LowerCaseConversion                                   */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               converts all alphabetic characters in a string to   */
/*               lowercase using the standard library.               */
/*                                                                   */
/* Notes       - Implements IStringConversion interface. Handles     */
/*               character-by-character conversion to lowercase.    */
/*                                                                   */
/* $Log: LowerCaseConversion.hpp                                      */
/*********************************************************************/

#ifndef LOWERCASECONVERSION_HPP
#define LOWERCASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <algorithm>
#include <cctype>

/**
 * @class LowerCaseConversion
 * @brief Converts a string to all lowercase characters.
 *
 * Implements the IStringConversion interface. This strategy converts
 * each character of the input string to its lowercase equivalent
 * using the standard library.
 *
 * Example usage:
 * @code
 * LowerCaseConversion converter;
 * std::string result = converter.convert("HELLO WORLD");
 * // result == "hello world"
 * @endcode
 */
class LowerCaseConversion : public IStringConversion {
public:
    /**
     * @brief Convert the input string to lowercase.
     * @param input The string to convert.
     * @return A new string where all alphabetic characters are lowercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // LOWERCASECONVERSION_HPP