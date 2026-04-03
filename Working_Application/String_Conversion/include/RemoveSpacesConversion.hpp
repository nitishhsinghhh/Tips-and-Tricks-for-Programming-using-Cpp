/*********************************************************************/
/* $Header: RemoveSpacesConversion.hpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - RemoveSpacesConversion.hpp                           */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               removes all spaces from a string.                   */
/*               This class implements the IStringConversion         */
/*               interface and produces a continuous string without  */
/*               spaces. Useful for compact identifiers, filenames,  */
/*               or cases where spacing is not desired.             */
/*                                                                   */
/* Notes       - Removes all whitespace characters from the string.  */
/*                                                                   */
/* $Log: RemoveSpacesConversion.hpp                                  */
/*********************************************************************/

#ifndef REMOVESPACECONVERSION_HPP
#define REMOVESPACECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class RemoveSpacesConversion
 * @brief Concrete implementation of IStringConversion that removes all spaces from a string.
 *
 * This class transforms input strings by eliminating all whitespace characters,
 * producing a continuous string without spaces.
 *
 * Example usage:
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