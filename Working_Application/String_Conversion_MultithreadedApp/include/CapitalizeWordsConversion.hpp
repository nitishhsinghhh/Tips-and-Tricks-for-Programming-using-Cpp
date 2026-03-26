#ifndef CAPITALIZEWORDSCONVERSION_HPP
#define CAPITALIZEWORDSCONVERSION_HPP

#include "IStringConversion.hpp"

/**
 * @class CapitalizeWordsConversion
 * @brief Concrete implementation of IStringConversion that capitalizes
 *        the first letter of each word in a string.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings so that each word starts with an uppercase letter and
 * the rest of the letters are lowercase.
 *
 * Example:
 * @code
 * CapitalizeWordsConversion conv;
 * std::string result = conv.convert("hello world");
 * // result == "Hello World"
 * @endcode
 */
class CapitalizeWordsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by capitalizing the first letter of each word.
     * @param input The original string to convert.
     * @return A new string with each word capitalized.
     */
    std::string convert(const std::string& input) const override;
};

#endif // CAPITALIZEWORDSCONVERSION_HPP