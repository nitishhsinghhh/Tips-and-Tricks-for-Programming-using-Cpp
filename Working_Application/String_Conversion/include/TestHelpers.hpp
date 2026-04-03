/*********************************************************************/
/* $Header: TestHelpers.hpp                                          */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - TestHelpers.hpp                                      */
/*                                                                   */
/* Description - Provides utility functions for logging string      */
/*               conversions during tests. Used to visualize        */
/*               input/output for various IStringConversion         */
/*               strategies in unit tests.                           */
/*                                                                   */
/* Notes       - Contains inline helper functions for GoogleTest    */
/*               or other test frameworks.                           */
/*                                                                   */
/* $Log: TestHelpers.hpp                                             */
/*********************************************************************/

#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <string>
#include <iostream>

/**
 * @brief Logs the result of a string conversion.
 *
 * Prints the conversion name, input string, and output string
 * to the standard output stream in a structured format.
 *
 * Example:
 * @code
 * logConversion("LowerCase", "HELLO", "hello");
 * // Output: [LowerCase] Input: "HELLO" => Output: "hello"
 * @endcode
 *
 * @param name   The name of the conversion strategy.
 * @param input  The original input string.
 * @param output The converted output string.
 */
inline void logConversion(const std::string& name,
                          const std::string& input,
                          const std::string& output) {
    std::cout << "[" << name << "] Input: \"" << input
              << "\" => Output: \"" << output << "\"" << std::endl;
}

#endif // TEST_HELPERS_HPP