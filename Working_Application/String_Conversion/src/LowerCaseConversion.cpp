/*********************************************************************/
/* $Header: LowerCaseConversion.cpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - LowerCaseConversion                                 */
/*                                                                   */
/* Description - Converts all characters in the input string to      */
/*               lowercase format using ASCII conversion.            */
/*                                                                   */
/* Notes       - ASCII difference between upper and lower is 32      */
/*               Preserves non-alphabetic characters                 */
/*                                                                   */
/* $Log: LowerCaseConversion.cpp                                     */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "LowerCaseConversion.hpp"

std::string LowerCaseConversion::convert(const std::string& input) const {
    std::string result = input;

    for (char &c : result) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');  // ASCII conversion
        }
    }

    return result;
}