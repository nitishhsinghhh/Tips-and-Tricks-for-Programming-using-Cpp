#ifndef SENTENCECASECONVERSION_HPP
#define SENTENCECASECONVERSION_HPP

#include "IStringConversion.hpp"

/**
 * @class SentenceCaseConversion
 * @brief Converts a string to sentence case.
 *
 * This class implements the IStringConversion interface.
 * It capitalizes the first character of the string and converts
 * the rest to lowercase. Useful for formatting text in a
 * proper sentence style.
 *
 * Example:
 * @code
 * SentenceCaseConversion conv;
 * std::string result = conv.convert("hELLO WORLD");
 * // result == "Hello world"
 * @endcode
 */
class SentenceCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to sentence case.
     * @param input The string to convert.
     * @return The converted string with the first letter capitalized
     *         and remaining letters in lowercase.
     */
    std::string convert(const std::string& input) const override;
};

#endif // SENTENCECASECONVERSION_HPP