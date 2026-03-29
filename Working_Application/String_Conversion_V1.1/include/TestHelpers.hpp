#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <string>
#include <iostream>

/**
 * @file TestHelpers.hpp
 * @brief Provides utility functions for logging string conversions during tests.
 *
 * This header defines helper functions used in unit tests to log
 * the input and output of string conversion strategies. It helps
 * visualize transformations when running GoogleTest suites.
 */

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
