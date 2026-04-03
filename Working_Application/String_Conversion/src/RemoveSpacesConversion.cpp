/*********************************************************************/
/* $Header: RemoveSpacesConversion.cpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - RemoveSpacesConversion                              */
/*                                                                   */
/* Description - Removes all space characters from the input string. */
/*                                                                   */
/* Notes       - Uses erase-remove idiom                             */
/*               Only removes space character ' '                    */
/*                                                                   */
/* $Log: RemoveSpacesConversion.cpp                                  */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "RemoveSpacesConversion.hpp"
#include <algorithm>

std::string RemoveSpacesConversion::convert(const std::string& input) const {
    std::string result = input;

    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

    return result;
}