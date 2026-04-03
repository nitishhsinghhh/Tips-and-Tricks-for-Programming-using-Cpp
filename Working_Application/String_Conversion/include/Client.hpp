/*********************************************************************/
/* $Header: Client.hpp                                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* Class       - Client                                              */
/*                                                                   */
/* Description - Context class implementing Strategy design pattern */
/*               to execute string conversion strategies.            */
/*                                                                   */
/* Notes       - Delegates conversion logic to IStringConversion     */
/*               implementations.                                    */
/*                                                                   */
/* $Log: Client.hpp                                                  */
/*********************************************************************/

#ifndef CLIENT_HPP
#define CLIENT_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <memory>
#include <string>
#include "IStringConversion.hpp"

/**
 * @class Client
 * @brief Context class for executing string conversion strategies.
 *
 * Example:
 * auto strategy = std::make_unique<LowerCaseConversion>();
 * Client client;
 * client.setStrategy(std::move(strategy));
 * std::string result = client.execute("HELLO"); // "hello"
 */
class Client {
private:
    /// Pointer to the current string conversion strategy
    std::unique_ptr<IStringConversion> strategy;

public:
    /**
     * @brief Sets the current string conversion strategy.
     * @param s A unique pointer to an IStringConversion implementation.
     */
    void setStrategy(std::unique_ptr<IStringConversion> s);

    /**
     * @brief Executes the current strategy on the given input string.
     * @param input The string to convert.
     * @return The converted string according to the current strategy.
     *         Returns original input if no strategy is set.
     */
    std::string execute(const std::string& input) const;
};

#endif // CLIENT_HPP