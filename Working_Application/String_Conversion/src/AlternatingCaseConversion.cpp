/*********************************************************************/
/* $Header: AlternatingCaseConversion.cpp                            */
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
/* Notes       - Reuses LowerCaseConversion and                     */
/*               UpperCaseConversion                                 */
/*               Resets alternation after spaces                     */
/*                                                                   */
/* $Log: AlternatingCaseConversion.cpp                               */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "AlternatingCaseConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"

std::string AlternatingCaseConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;
    UpperCaseConversion upperConv;

    std::string result;
    bool upper = true;

    for (char c : input) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {

            std::string temp(1, c);

            if (upper)
                temp = upperConv.convert(temp);
            else
                temp = lowerConv.convert(temp);

            result += temp;
            upper = !upper;
        }
        else {
            result += c;
            if (c == ' ') {
                upper = true;
            }
        }
    }

    return result;
}