#ifndef LEETSPEAKCONVERSION_HPP
#define LEETSPEAKCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class LeetSpeakConversion
 * @brief Concrete implementation of IStringConversion that converts strings into leet speak.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings by replacing certain alphabetic characters with numbers
 * or symbols commonly used in "leet speak" (1337). For example, 'a' may
 * become '4', 'e' becomes '3', 'o' becomes '0', etc.
 *
 * Example:
 * @code
 * LeetSpeakConversion conv;
 * std::string result = conv.convert("Hello World");
 * // result == "H3ll0 W0rld"
 * @endcode
 */
class LeetSpeakConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string into leet speak.
     * @param input The original string to convert.
     * @return A new string with characters replaced by leet equivalents.
     */
    std::string convert(const std::string& input) const override;
};

#endif // LEETSPEAKCONVERSION_HPP
