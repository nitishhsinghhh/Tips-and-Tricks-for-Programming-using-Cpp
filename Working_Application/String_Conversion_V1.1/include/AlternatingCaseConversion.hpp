#ifndef ALTERNATINGCASECONVERSION_HPP
#define ALTERNATINGCASECONVERSION_HPP

#include "IStringConversion.hpp"

/**
 * @class AlternatingCaseConversion
 * @brief Concrete implementation of IStringConversion that alternates
 *        the case of each character in a string.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings so that characters alternate between uppercase and lowercase,
 * starting with uppercase.
 *
 * Example:
 * @code
 * AlternatingCaseConversion conv;
 * std::string result = conv.convert("hello world");
 * // result == "HeLlO WoRlD"
 * @endcode
 */
class AlternatingCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by alternating the case of each character.
     * @param input The original string to convert.
     * @return A new string with alternating character case.
     */
    std::string convert(const std::string& input) const override;
};

#endif // ALTERNATINGCASECONVERSION_HPP