/*********************************************************************/
/* $Header: RemoveVowelsConversion.cpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - RemoveVowelsConversion                              */
/*                                                                   */
/* Description - Removes all vowel characters from the input string. */
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion for case normalization   */
/*               Preserves non-vowel characters                      */
/*                                                                   */
/* $Log: RemoveVowelsConversion.cpp                                  */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "RemoveVowelsConversion.hpp"
#include "LowerCaseConversion.hpp"

std::string RemoveVowelsConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;
    std::string lower = lowerConv.convert(input);

    std::string result;

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = lower[i];

        if (ch != 'a' && ch != 'e' && ch != 'i' &&
            ch != 'o' && ch != 'u') {
            result += input[i];
        }
    }

    return result;
}