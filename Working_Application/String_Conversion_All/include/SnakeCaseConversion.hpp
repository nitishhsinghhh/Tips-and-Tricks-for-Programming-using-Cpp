#ifndef SNAKECASECONVERSION_HPP
#define SNAKECASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class SnakeCaseConversion
 * @brief Concrete implementation of IStringConversion that converts strings to snake_case.
 *
 * This class implements the IStringConversion interface. It transforms
 * input strings so that words are separated by underscores (`_`) and all
 * characters are lowercase. Snake case is commonly used in programming
 * for variable names, file names, and identifiers.
 *
 * Example:
 * @code
 * SnakeCaseConversion conv;
 * std::string result = conv.convert("Hello World Example");
 * // result == "hello_world_example"
 * @endcode
 */
class SnakeCaseConversion : public IStringConversion {
public:
    /**
     * @brief Converts the input string to snake_case.
     * @param input The original string to convert.
     * @return A new string in snake_case format.
     */
    std::string convert(const std::string& input) const override;
};

#endif // SNAKECASECONVERSION_HPP
