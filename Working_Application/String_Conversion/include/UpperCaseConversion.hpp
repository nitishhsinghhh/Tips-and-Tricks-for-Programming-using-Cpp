/*********************************************************************/
/* $Header: UpperCaseConversion.hpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - UpperCaseConversion.hpp                              */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that  */
/*               converts all alphabetic characters of a string to  */
/*               uppercase. Non-alphabetic characters remain        */
/*               unchanged.                                          */
/*                                                                   */
/* Notes       - Useful for formatting text in all-uppercase style  */
/*               or normalizing string data for comparisons.        */
/*                                                                   */
/* $Log: UpperCaseConversion.hpp                                      */
/*********************************************************************/

#ifndef UPPERCASECONVERSION_HPP
#define UPPERCASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class UpperCaseConversion
 * @brief Converts a string to uppercase.
 *
 * Implements the IStringConversion interface.
 * Non-alphabetic characters remain unchanged.
 *
 * Example usage:
 * @code
 * UpperCaseConversion upper;
 * std::string result = upper.convert("Hello World!");
 * // result == "HELLO WORLD!"
 * @endcode
 */
class UpperCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to uppercase.
     * @param input The string to convert.
     * @return std::string The converted string in uppercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // UPPERCASECONVERSION_HPP