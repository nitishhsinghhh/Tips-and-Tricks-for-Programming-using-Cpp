#ifndef REMOVEVOWELSCONVERSION_HPP
#define REMOVEVOWELSCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class RemoveVowelsConversion
 * @brief Concrete implementation of IStringConversion that removes all vowels from a string.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings by eliminating all vowel characters (`a, e, i, o, u` in both
 * uppercase and lowercase). Useful for creating compact identifiers or
 * stylized text where vowels are omitted.
 *
 * Example:
 * @code
 * RemoveVowelsConversion conv;
 * std::string result = conv.convert("Hello World");
 * // result == "Hll Wrld"
 * @endcode
 */
class RemoveVowelsConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by removing all vowels.
     * @param input The original string to convert.
     * @return A new string with all vowels removed.
     */
    std::string convert(const std::string& input) const override;
};

#endif // REMOVEVOWELSCONVERSION_HPP
