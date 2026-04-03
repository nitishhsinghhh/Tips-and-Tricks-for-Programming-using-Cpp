/*********************************************************************/
/* $Header: ProcessString.cpp                                        */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - ProcessString                                       */
/*                                                                   */
/* Description - Dispatches user choice to appropriate string        */
/*               conversion strategy using Factory and Client.       */
/*                                                                   */
/* Notes       - Uses Strategy and Factory design patterns           */
/*               Returns original input for invalid choice           */
/*                                                                   */
/* $Log: ProcessString.cpp                                           */
/*********************************************************************/

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "ProcessString.hpp"
#include "Client.hpp"
#include "StringConversionFactory.hpp"

std::string processString(const std::string& input, int choice) {
    Client client;
    ConversionType type;

    switch (choice) {
        case 1:  type = ConversionType::Alternating;   break;
        case 2:  type = ConversionType::Capitalize;    break;
        case 3:  type = ConversionType::Lower;         break;
        case 4:  type = ConversionType::Upper;         break;
        case 5:  type = ConversionType::Sentence;      break;
        case 6:  type = ConversionType::Toggle;        break;
        case 7:  type = ConversionType::Reverse;       break;
        case 8:  type = ConversionType::RemoveVowels;  break;
        case 9:  type = ConversionType::RemoveSpaces;  break;
        case 10: type = ConversionType::InvertWords;   break;
        case 11: type = ConversionType::SnakeCase;     break;
        case 12: type = ConversionType::KebabCase;     break;
        case 13: type = ConversionType::LeetSpeak;     break;
        default: return input; // fallback if choice is invalid
    }

    client.setStrategy(StringConversionFactory::create(type));
    return client.execute(input);
}