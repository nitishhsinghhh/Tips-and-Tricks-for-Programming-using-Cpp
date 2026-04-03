/*********************************************************************/
/* $Header: ReverseConversion.cpp                                    */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - ReverseConversion                                   */
/*                                                                   */
/* Description - Reverses the entire input string.                   */
/*                                                                   */
/* Notes       - Uses std::reverse for in-place reversal             */
/*                                                                   */
/* $Log: ReverseConversion.cpp                                       */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "ReverseConversion.hpp"
#include <algorithm>

std::string ReverseConversion::convert(const std::string& input) const {
    std::string result = input;

    std::reverse(result.begin(), result.end());

    return result;
}