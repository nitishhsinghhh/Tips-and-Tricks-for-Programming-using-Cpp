/*********************************************************************/
/* $Header: KebabCaseConversion.hpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - KebabCaseConversion                                  */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               converts strings to kebab-case. Words are separated */
/*               by hyphens and all characters are lowercase.       */
/*                                                                   */
/* Notes       - Implements IStringConversion interface. Handles     */
/*               consecutive spaces, removes trailing hyphens.      */
/*                                                                   */
/* $Log: KebabCaseConversion.hpp                                     */
/*********************************************************************/

#ifndef KEBABCASECONVERSION_HPP
#define KEBABCASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class KebabCaseConversion
 * @brief Concrete implementation of IStringConversion that converts strings to kebab-case.
 *
 * This class transforms input strings so that:
 *   - Words are separated by hyphens (`-`)
 *   - All characters are lowercase
 *   - Consecutive spaces are replaced by a single hyphen
 *   - Leading/trailing hyphens are removed
 *
 * Example:
 * @code
 * KebabCaseConversion conv;
 * std::string result = conv.convert("Hello World Example");
 * // result == "hello-world-example"
 * @endcode
 */
class KebabCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to kebab-case.
     * @param input The string to convert.
     * @return The kebab-case version of the input.
     */
    std::string convert(const std::string& input) const override;
};

#endif // KEBABCASECONVERSION_HPP