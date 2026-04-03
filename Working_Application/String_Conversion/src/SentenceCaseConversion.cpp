/*********************************************************************/
/* $Header: SentenceCaseConversion.cpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - SentenceCaseConversion                              */
/*                                                                   */
/* Description - Converts input string to sentence case by           */
/*               capitalizing the first character and converting     */
/*               the remaining characters to lowercase.              */
/*                                                                   */
/* Notes       - Reuses LowerCaseConversion and UpperCaseConversion  */
/*               Handles empty input safely                          */
/*                                                                   */
/* $Log: SentenceCaseConversion.cpp                                  */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "SentenceCaseConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"

std::string SentenceCaseConversion::convert(const std::string& input) const {
    if (input.empty()) return input;

    LowerCaseConversion lowerConv;
    UpperCaseConversion upperConv;

    std::string result = lowerConv.convert(input);

    std::string first(1, result[0]);
    result[0] = upperConv.convert(first)[0];

    return result;
}