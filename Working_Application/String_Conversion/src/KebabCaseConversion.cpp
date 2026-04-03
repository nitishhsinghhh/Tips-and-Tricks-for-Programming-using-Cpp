/*********************************************************************/
/* $Header: KebabCaseConversion.cpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - KebabCaseConversion                                 */
/*                                                                   */
/* Description - Converts input string to kebab-case format          */
/*               by replacing spaces with hyphens and converting     */
/*               all characters to lowercase.                        */
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion                          */
/*               Multiple spaces converted to multiple hyphens       */
/*                                                                   */
/* $Log: KebabCaseConversion.cpp                                     */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "KebabCaseConversion.hpp"
#include "LowerCaseConversion.hpp"

std::string KebabCaseConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;

    std::string lower = lowerConv.convert(input);
    std::string result;

    for (char ch : lower) {
        if (ch == ' ') {
            result += '-';
        } else {
            result += ch;
        }
    }

    return result;
}