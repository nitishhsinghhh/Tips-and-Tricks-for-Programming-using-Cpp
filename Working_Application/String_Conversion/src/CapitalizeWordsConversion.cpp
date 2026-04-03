/*********************************************************************/
/* $Header: CapitalizeWordsConversion.cpp                            */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - CapitalizeWordsConversion                           */
/*                                                                   */
/* Description - Converts input string so that each word starts      */
/*               with an uppercase letter followed by lowercase      */
/*               characters.                                         */
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion and                     */
/*               UpperCaseConversion                                 */
/*                                                                   */
/* $Log: CapitalizeWordsConversion.cpp                               */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "CapitalizeWordsConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include <sstream>

std::string CapitalizeWordsConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;
    UpperCaseConversion upperConv;

    std::istringstream iss(input);
    std::string word, result;

    while (iss >> word) {
        if (!result.empty()) result += " ";

        // make whole word lowercase first
        word = lowerConv.convert(word);

        // capitalize first letter using UpperCaseConversion
        std::string firstChar(1, word[0]);
        firstChar = upperConv.convert(firstChar);
        word[0] = firstChar[0];

        result += word;
    }

    return result;
}