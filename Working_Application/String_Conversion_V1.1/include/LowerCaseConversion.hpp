#ifndef LOWERCASECONVERSION_HPP
#define LOWERCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <algorithm>
#include <cctype>

/**
 * @class LowerCaseConversion
 * @brief Converts a string to all lowercase characters.
 *
 * Implements the IStringConversion interface. This strategy converts
 * each character of the input string to its lowercase equivalent
 * using the standard library.
 *
 * Example usage:
 * @code
 * LowerCaseConversion converter;
 * std::string result = converter.convert("HELLO WORLD"); // result == "hello world"
 * @endcode
 */
class LowerCaseConversion : public IStringConversion {
public:
    /**
     * @brief Convert the input string to lowercase.
     * @param input The string to convert.
     * @return A new string where all alphabetic characters are lowercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // LOWERCASECONVERSION_HPP