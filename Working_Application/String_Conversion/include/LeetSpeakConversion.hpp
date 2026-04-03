/*********************************************************************/
/* $Header: LeetSpeakConversion.hpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - LeetSpeakConversion                                  */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               converts strings into leet speak (1337). Certain    */
/*               alphabetic characters are replaced with numbers or */
/*               symbols, e.g., 'a' -> '4', 'e' -> '3', 'o' -> '0'.*/
/*                                                                   */
/* Notes       - Implements IStringConversion interface. Handles     */
/*               basic leet speak transformations.                  */
/*                                                                   */
/* $Log: LeetSpeakConversion.hpp                                     */
/*********************************************************************/

#ifndef LEETSPEAKCONVERSION_HPP
#define LEETSPEAKCONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class LeetSpeakConversion
 * @brief Concrete implementation of IStringConversion that converts strings into leet speak.
 *
 * This class transforms input strings by replacing certain alphabetic
 * characters with leet speak equivalents.
 *
 * Example:
 * @code
 * LeetSpeakConversion conv;
 * std::string result = conv.convert("Hello World");
 * // result == "H3ll0 W0rld"
 * @endcode
 */
class LeetSpeakConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string into leet speak.
     * @param input The string to convert.
     * @return The leet speak version of the input.
     */
    std::string convert(const std::string& input) const override;
};

#endif // LEETSPEAKCONVERSION_HPP