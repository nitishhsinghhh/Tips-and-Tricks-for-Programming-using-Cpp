/*********************************************************************/
/* $Header: CapitalizeWordsConversion.hpp                            */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - CapitalizeWordsConversion                           */
/*                                                                   */
/* Description - Converts input string by capitalizing the first     */
/*               letter of each word while making remaining letters  */
/*               lowercase.                                          */
/*                                                                   */
/* Notes       - Implements IStringConversion interface              */
/*                                                                   */
/* $Log: CapitalizeWordsConversion.hpp                               */
/*********************************************************************/

#ifndef CAPITALIZEWORDSCONVERSION_HPP
#define CAPITALIZEWORDSCONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"

/**
 * @class CapitalizeWordsConversion
 * @brief Concrete implementation of IStringConversion that capitalizes
 *        the first letter of each word in a string.
 *
 * Example:
 * Input  : "hello world"
 * Output : "Hello World"
 */
class CapitalizeWordsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by capitalizing the first letter of each word.
     * @param input The original string to convert.
     * @return A new string with each word capitalized.
     */
    std::string convert(const std::string& input) const override;
};

#endif // CAPITALIZEWORDSCONVERSION_HPP