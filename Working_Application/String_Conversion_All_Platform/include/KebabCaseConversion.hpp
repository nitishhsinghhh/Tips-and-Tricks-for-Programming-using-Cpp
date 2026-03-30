#ifndef KEBABCASECONVERSION_HPP
#define KEBABCASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class KebabCaseConversion
 * @brief Concrete implementation of IStringConversion that converts strings to kebab-case.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings so that words are separated by hyphens (`-`) and all
 * characters are lowercase. This is commonly used in URLs, CSS class names,
 * and other contexts where a standardized, lowercase, hyphen-separated
 * format is preferred.
 *
 * Example:
 * @code
 * KebabCaseConversion conv;
 * std::string result = conv.convert("Hello World Example");
 * // result == "hello-world-example"
 * @endcode
 */
class KebabCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to kebab-case.
     * @param input The original string to convert.
     * @return A new string in kebab-case format.
     */
    std::string convert(const std::string& input) const override;
};

#endif // KEBABCASECONVERSION_HPP
