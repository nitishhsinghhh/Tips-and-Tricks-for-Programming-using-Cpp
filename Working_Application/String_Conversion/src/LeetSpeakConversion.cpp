/*********************************************************************/
/* $Header: LeetSpeakConversion.cpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - LeetSpeakConversion                                 */
/*                                                                   */
/* Description - Converts input string into leetspeak format by      */
/*               replacing certain alphabetic characters with        */
/*               numeric representations.                            */
/*                                                                   */
/* Notes       - Uses unordered_map for character mapping            */
/*               Preserves characters not in mapping                 */
/*                                                                   */
/* $Log: LeetSpeakConversion.cpp                                     */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "LeetSpeakConversion.hpp"
#include <unordered_map>

std::string LeetSpeakConversion::convert(const std::string& input) const {
    std::unordered_map<char, std::string> leetMap = {
        {'a', "4"}, {'A', "4"}, {'e', "3"}, {'E', "3"},
        {'i', "1"}, {'I', "1"}, {'o', "0"}, {'O', "0"},
        {'s', "5"}, {'S', "5"}, {'t', "7"}, {'T', "7"}
    };

    std::string result;
    for (char ch : input) {
        if (leetMap.find(ch) != leetMap.end())
            result += leetMap[ch];
        else
            result += ch;
    }
    return result;
}