/*********************************************************************/
/* $Header: IStringConversion.hpp                                    */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - IStringConversion                                   */
/*                                                                   */
/* Description - Interface defining contract for string conversion   */
/*               strategies.                                         */
/*                                                                   */
/* Notes       - Base interface for all string transformation        */
/*               implementations (e.g., lower, upper, toggle case).  */
/*                                                                   */
/* $Log: IStringConversion.hpp                                       */
/*********************************************************************/

#ifndef ISTRINGCONVERSION_HPP
#define ISTRINGCONVERSION_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <string>

/**
 * @interface IStringConversion
 * @brief Interface for string conversion strategies.
 *
 * This interface defines a common API for all string conversion strategies.
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