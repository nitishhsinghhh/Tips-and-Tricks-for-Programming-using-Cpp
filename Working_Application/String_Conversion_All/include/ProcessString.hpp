#ifndef PROCESSSTRING_HPP
#define PROCESSSTRING_HPP

#include <string>

/**
 * @brief Process a string using the specified conversion strategy.
 *
 * This function acts as a client interface to apply a string
 * conversion based on the user's choice. Internally, it uses
 * the Client class and StringConversionFactory to select the
 * appropriate strategy.
 *
 * Conversion choices:
 * - 1: Lowercase
 * - 2: Uppercase
 * - 3: Sentence case
 * - 4: Capitalize words
 * - 5: Toggle case
 *
 * @param input The input string to be converted.
 * @param choice An integer representing the desired conversion type.
 * @return The converted string according to the chosen strategy.
 *
 * @example
 * std::string result = processString("Hello World", 2); // "HELLO WORLD"
 */
std::string processString(const std::string& input, int choice);

#endif // PROCESSSTRING_HPP