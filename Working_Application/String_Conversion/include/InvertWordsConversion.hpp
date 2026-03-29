#ifndef INVERTWORDSCONVERSION_HPP
#define INVERTWORDSCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class InvertWordsConversion
 * @brief Concrete implementation of IStringConversion that inverts each word in a string.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings so that each word is individually reversed, while the
 * overall word order remains unchanged.
 *
 * Example:
 * @code
 * InvertWordsConversion conv;
 * std::string result = conv.convert("Hello World");
 * // result == "olleH dlroW"
 * @endcode
 */
class InvertWordsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by inverting each word.
     * @param input The original string to convert.
     * @return A new string with each word reversed.
     */
    std::string convert(const std::string& input) const override;
};

#endif // INVERTWORDSCONVERSION_HPP
