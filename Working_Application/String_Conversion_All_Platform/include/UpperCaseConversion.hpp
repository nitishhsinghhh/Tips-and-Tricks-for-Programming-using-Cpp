#ifndef UPPERCASECONVERSION_HPP
#define UPPERCASECONVERSION_HPP

#include "IStringConversion.hpp"

/**
 * @class UpperCaseConversion
 * @brief Converts a string to uppercase.
 *
 * All alphabetic characters in the input string are converted to uppercase.
 * Non-alphabetic characters remain unchanged.
 *
 * Usage example:
 * @code
 * UpperCaseConversion upper;
 * std::string result = upper.convert("Hello World!");
 * // result == "HELLO WORLD!"
 * @endcode
 */
class UpperCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to uppercase.
     * @param input The string to convert.
     * @return std::string The converted string in uppercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // UPPERCASECONVERSION_HPP