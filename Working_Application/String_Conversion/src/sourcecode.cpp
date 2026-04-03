/*********************************************************************/
/* $Header: main.cpp                                                 */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - main                                                */
/*                                                                   */
/* Description - Entry point for string conversion application.      */
/*               Accepts user input and applies selected             */
/*               conversion strategy.                                */
/*                                                                   */
/* Notes       - Uses ProcessString dispatcher                       */
/*               Demonstrates runtime selection of conversions       */
/*                                                                   */
/* $Log: main.cpp                                                    */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <iostream>
#include "ProcessString.hpp"

int main() {
    std::string input;

    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::cout << "1: Alternating, 2: Capitalize, 3: Lower, 4: Upper, "
                 "5: Sentence, 6: Toggle, 7: Reverse, 8: RemoveVowels, "
                 "9: RemoveSpaces, 10: InvertWords, 11: SnakeCase, "
                 "12: KebabCase, 13: LeetSpeak\n";

    int choice;
    std::cin >> choice;

    std::string result = processString(input, choice);

    std::cout << "Result: " << result << std::endl;

    return 0;
}