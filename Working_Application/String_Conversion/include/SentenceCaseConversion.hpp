/*********************************************************************/
/* $Header: SentenceCaseConversion.hpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - SentenceCaseConversion.hpp                           */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               converts a string to sentence case.                */
/*               Capitalizes the first character of the string      */
/*               and converts the remaining characters to lowercase.*/
/*                                                                   */
/* Notes       - Useful for formatting text in proper sentence style*/
/*                                                                   */
/* $Log: SentenceCaseConversion.hpp                                  */
/*********************************************************************/

#ifndef SENTENCECASECONVERSION_HPP
#define SENTENCECASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class SentenceCaseConversion
 * @brief Concrete implementation of IStringConversion that converts a string to sentence case.
 *
 * This class transforms input strings by capitalizing the first character
 * and converting the remaining characters to lowercase.
 *
 * Example usage:
 * @code
 * SentenceCaseConversion conv;
 * std::string result = conv.convert("hELLO WORLD");
 * // result == "Hello world"
 * @endcode
 */
class SentenceCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to sentence case.
     * @param input The string to convert.
     * @return The converted string with the first letter capitalized
     *         and remaining letters in lowercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // SENTENCECASECONVERSION_HPP