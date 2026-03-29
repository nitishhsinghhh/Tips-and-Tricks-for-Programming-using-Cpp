/**
 * @file ReverseConversion.hpp
 * @brief Defines the ReverseConversion class for reversing strings.
 *
 * The ReverseConversion class implements the IStringConversion interface
 * and provides functionality to reverse the characters in a given string.
 * This is part of the String Conversion library.
 *
 * Example usage:
 * @code
 * ReverseConversion converter;
 * std::string result = converter.convert("Hello");
 * // result == "olleH"
 * @endcode
 */

#ifndef REVERSECONVERSION_HPP
#define REVERSECONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

/**
 * @class ReverseConversion
 * @brief A string conversion strategy that reverses the input string.
 *
 * This class overrides the convert() method from IStringConversion
 * to return the reversed version of the input string.
 */
class ReverseConversion : public IStringConversion {
public:
    /**
     * @brief Reverse the input string.
     * @param input The string to be reversed.
     * @return A new string with characters in reverse order.
     */
    std::string convert(const std::string& input) const override;
    
};

#endif // REVERSECONVERSION_HPP
