/*********************************************************************/
/* $Header: ToggleCaseConversion.hpp                                 */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - ToggleCaseConversion.hpp                             */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that  */
/*               toggles the case of each character in a string.    */
/*               Lowercase characters become uppercase, uppercase  */
/*               characters become lowercase. Non-alphabetic       */
/*               characters remain unchanged.                       */
/*                                                                   */
/* Notes       - Useful for case inversion strategies in text       */
/*               formatting or testing string manipulation.         */
/*                                                                   */
/* $Log: ToggleCaseConversion.hpp                                     */
/*********************************************************************/

#ifndef TOGGLECASECONVERSION_HPP
#define TOGGLECASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class ToggleCaseConversion
 * @brief Converts a string by toggling the case of each character.
 *
 * Implements the IStringConversion interface.
 * Non-alphabetic characters remain unchanged.
 *
 * Example usage:
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