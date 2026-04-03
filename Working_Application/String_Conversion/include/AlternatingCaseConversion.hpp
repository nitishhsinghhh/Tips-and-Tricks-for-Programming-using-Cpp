/*********************************************************************/
/* $Header: AlternatingCaseConversion.hpp                            */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - AlternatingCaseConversion                           */
/*                                                                   */
/* Description - Converts input string into alternating case format  */
/*               (uppercase/lowercase alternation starting with      */
/*               uppercase).                                         */
/*                                                                   */
/* Notes       - Implements IStringConversion interface              */
/*                                                                   */
/* $Log: AlternatingCaseConversion.hpp                               */
/*********************************************************************/

#ifndef ALTERNATINGCASECONVERSION_HPP
#define ALTERNATINGCASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"

/**
 * @class AlternatingCaseConversion
 * @brief Concrete implementation of IStringConversion that alternates
 *        the case of each character in a string.
 *
 * Example:
 * Input  : "hello world"
 * Output : "HeLlO WoRlD"
 */
class AlternatingCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by alternating the case of each character.
     * @param input The original string to convert.
     * @return A new string with alternating character case.
     */
    std::string convert(const std::string& input) const override;
};

#endif // ALTERNATINGCASECONVERSION_HPP