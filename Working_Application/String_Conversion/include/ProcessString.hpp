/*********************************************************************/
/* $Header: ProcessString.hpp                                        */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - ProcessString.hpp                                    */
/*                                                                   */
/* Description - Provides a client interface function to process a   */
/*               string using a chosen conversion strategy.          */
/*               Internally, this function uses a Client class and   */
/*               StringConversionFactory to select the appropriate  */
/*               string conversion implementation.                   */
/*                                                                   */
/* Notes       - Supports multiple conversion strategies:           */
/*               1: Alternating case                                  */
/*               2: Capitalize words                                  */
/*               3: Lowercase                                        */
/*               4: Uppercase                                        */
/*               5: Sentence case                                    */
/*               6: Toggle case                                      */
/*               7: Reverse                                          */
/*               8: Remove vowels                                     */
/*               9: Remove spaces                                     */
/*              10: Invert words                                      */
/*              11: Snake case                                        */
/*              12: Kebab case                                        */
/*              13: Leet speak                                        */
/*                                                                   */
/* $Log: ProcessString.hpp                                           */
/*********************************************************************/

#ifndef PROCESSSTRING_HPP
#define PROCESSSTRING_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <string>

/**
 * @brief Process a string using the specified conversion strategy.
 *
 * This function acts as a client interface to apply a string
 * conversion based on the user's choice.
 *
 * @param input The input string to be converted.
 * @param choice An integer representing the desired conversion type:
 *               1: Alternating case
 *               2: Capitalize words
 *               3: Lowercase
 *               4: Uppercase
 *               5: Sentence case
 *               6: Toggle case
 *               7: Reverse
 *               8: Remove vowels
 *               9: Remove spaces
 *              10: Invert words
 *              11: Snake case
 *              12: Kebab case
 *              13: Leet speak
 * @return The converted string according to the chosen strategy.
 *
 * @example
 * std::string result = processString("Hello World", 3); // "hello world" (Lowercase)
 */
std::string processString(const std::string& input, int choice);

#endif // PROCESSSTRING_HPP