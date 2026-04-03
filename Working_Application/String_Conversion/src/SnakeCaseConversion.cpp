/*********************************************************************/
/* $Header: SnakeCaseConversion.cpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - SnakeCaseConversion                                 */
/*                                                                   */
/* Description - Converts input string to snake_case format by       */
/*               replacing spaces with underscores and converting    */
/*               all characters to lowercase.                        */
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion                          */
/*               Multiple spaces converted to multiple underscores   */
/*                                                                   */
/* $Log: SnakeCaseConversion.cpp                                     */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "SnakeCaseConversion.hpp"
#include "LowerCaseConversion.hpp"

std::string SnakeCaseConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;

    std::string lower = lowerConv.convert(input);
    std::string result;

    for (char ch : lower) {
        if (ch == ' ') {
            result += '_';
        } else {
            result += ch;
        }
    }

    return result;
}