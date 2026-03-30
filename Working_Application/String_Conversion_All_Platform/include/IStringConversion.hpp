#ifndef ISTRINGCONVERSION_HPP
#define ISTRINGCONVERSION_HPP

#include <string>

/**
 * @interface IStringConversion
 * @brief Interface for string conversion strategies.
 *
 * This interface defines a common API for all string conversion strategies.
 * Implementing classes provide specific conversions such as lower case, 
 * upper case, sentence case, toggle case, and capitalization of words.
 *
 * Example usage:
 * @code
 * std::unique_ptr<IStringConversion> strategy = std::make_unique<LowerCaseConversion>();
 * std::string result = strategy->convert("HELLO"); // result == "hello"
 * @endcode
 */
class IStringConversion {
public:
    /**
     * @brief Converts the input string according to the strategy.
     * @param input The input string to be converted.
     * @return The converted string.
     */
    virtual std::string convert(const std::string& input) const = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~IStringConversion() = default;
};

#endif // ISTRINGCONVERSION_HPP