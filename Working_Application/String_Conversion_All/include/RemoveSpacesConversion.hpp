#ifndef REMOVESPACECONVERSION_HPP
#define REMOVESPACECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class RemoveSpacesConversion
 * @brief Concrete implementation of IStringConversion that removes all spaces from a string.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings by eliminating all whitespace characters, producing a
 * continuous string without spaces. Useful for compact identifiers,
 * filenames, or cases where spacing is not desired.
 *
 * Example:
 * @code
 * RemoveSpacesConversion conv;
 * std::string result = conv.convert("Hello World Example");
 * // result == "HelloWorldExample"
 * @endcode
 */
class RemoveSpacesConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string by removing all spaces.
     * @param input The original string to convert.
     * @return A new string with all spaces removed.
     */
    std::string convert(const std::string& input) const override;
};

#endif // REMOVESPACECONVERSION_HPP
