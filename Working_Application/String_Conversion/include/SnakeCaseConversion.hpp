/*********************************************************************/
/* $Header: SnakeCaseConversion.hpp                                  */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - SnakeCaseConversion.hpp                               */
/*                                                                   */
/* Description - Concrete implementation of IStringConversion that   */
/*               converts strings to snake_case.                    */
/*               Words are separated by underscores (_) and all      */
/*               characters are lowercase.                           */
/*                                                                   */
/* Notes       - Useful for programming identifiers, file names,     */
/*               and variable naming conventions.                    */
/*                                                                   */
/* $Log: SnakeCaseConversion.hpp                                      */
/*********************************************************************/

#ifndef SNAKECASECONVERSION_HPP
#define SNAKECASECONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include "IStringConversion.hpp"
#include <string>

/**
 * @class SnakeCaseConversion
 * @brief Concrete implementation of IStringConversion that converts strings to snake_case.
 *
 * This class transforms input strings by replacing spaces or word boundaries
 * with underscores and converting all characters to lowercase.
 *
 * Example usage:
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