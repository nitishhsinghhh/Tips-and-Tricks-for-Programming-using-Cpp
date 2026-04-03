/*********************************************************************/
/* $Header: ToggleCaseConversion.cpp                                 */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - ToggleCaseConversion                                */
/*                                                                   */
/* Description - Toggles the case of alphabetic characters in the    */
/*               input string (lowercase to uppercase and vice versa)*/
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion and UpperCaseConversion  */
/*               Non-alphabetic characters unchanged                 */
/*                                                                   */
/* $Log: ToggleCaseConversion.cpp                                    */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "ToggleCaseConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"

std::string ToggleCaseConversion::convert(const std::string& input) const {
    LowerCaseConversion lowerConv;
    UpperCaseConversion upperConv;

    std::string result;

    for (char c : input) {
        if ((c >= 'a' && c <= 'z')) {
            std::string temp(1, c);
            result += upperConv.convert(temp);
        }
        else if ((c >= 'A' && c <= 'Z')) {
            std::string temp(1, c);
            result += lowerConv.convert(temp);
        }
        else {
            result += c;
        }
    }

    return result;
}