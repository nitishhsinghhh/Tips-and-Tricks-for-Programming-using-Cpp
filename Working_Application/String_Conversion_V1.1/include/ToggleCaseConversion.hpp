#ifndef TOGGLECASECONVERSION_HPP
#define TOGGLECASECONVERSION_HPP

#include "IStringConversion.hpp"

/**
 * @class ToggleCaseConversion
 * @brief Converts a string by toggling the case of each character.
 *
 * Lowercase characters become uppercase and uppercase characters become lowercase.
 * Non-alphabetic characters remain unchanged.
 *
 * Usage example:
 * @code
 * ToggleCaseConversion toggle;
 * std::string result = toggle.convert("HeLLo");
 * // result == "hEllO"
 * @endcode
 */
class ToggleCaseConversion : public IStringConversion {
public:
    /**
     * @brief Toggles the case of each character in the input string.
     * @param input The string to convert.
     * @return std::string The converted string with toggled case.
     */
    std::string convert(const std::string& input) const override;
};

#endif // TOGGLECASECONVERSION_HPP