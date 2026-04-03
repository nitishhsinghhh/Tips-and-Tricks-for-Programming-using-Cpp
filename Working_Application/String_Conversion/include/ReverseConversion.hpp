/*********************************************************************/
/* $Header: ReverseConversion.hpp                                     */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - ReverseConversion.hpp                                 */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               reverses the characters in a string.               */
/*               This class implements the IStringConversion         */
/*               interface and returns the reversed version of       */
/*               the input string.                                   */
/*                                                                   */
/* Notes       - Useful for palindromes, reversing text for          */
/*               formatting, or testing string algorithms.           */
/*                                                                   */
/* $Log: ReverseConversion.hpp                                        */
/*********************************************************************/

#ifndef REVERSECONVERSION_HPP
#define REVERSECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class ReverseConversion
 * @brief Concrete implementation of IStringConversion that reverses a string.
 *
 * This class overrides the convert() method from IStringConversion
 * to return a new string with characters in reverse order.
 *
 * Example usage:
 * @code
 * ReverseConversion converter;
 * std::string result = converter.convert("Hello");
 * // result == "olleH"
 * @endcode
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