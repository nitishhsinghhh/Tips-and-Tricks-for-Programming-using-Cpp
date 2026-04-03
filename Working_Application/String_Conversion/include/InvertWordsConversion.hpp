/*********************************************************************/
/* $Header: InvertWordsConversion.hpp                                */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - InvertWordsConversion                               */
/*                                                                   */
/* Description - Converts input string by reversing each word        */
/*               individually while preserving word order.           */
/*                                                                   */
/* Notes       - Implements IStringConversion interface              */
/*                                                                   */
/* $Log: InvertWordsConversion.hpp                                   */
/*********************************************************************/

#ifndef INVERTWORDSCONVERSION_HPP
#define INVERTWORDSCONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class InvertWordsConversion
 * @brief Concrete implementation of IStringConversion that inverts each word.
 *
 * Example:
 * Input  : "Hello World"
 * Output : "olleH dlroW"
 */
class InvertWordsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by inverting each word.
     * @param input The original string to convert.
     * @return A new string with each word reversed.
     */
    std::string convert(const std::string& input) const override;
};

#endif // INVERTWORDSCONVERSION_HPP