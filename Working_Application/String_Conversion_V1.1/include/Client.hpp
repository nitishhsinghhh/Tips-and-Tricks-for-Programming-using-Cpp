#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
#include <string>
#include "IStringConversion.hpp"

/**
 * @class Client
 * @brief Context class for executing string conversion strategies.
 *
 * The Client class follows the Strategy design pattern. It holds a 
 * reference to an IStringConversion strategy and delegates the string
 * conversion operation to the current strategy.
 *
 * Example usage:
 * @code
 * auto strategy = std::make_unique<LowerCaseConversion>();
 * Client client;
 * client.setStrategy(std::move(strategy));
 * std::string result = client.execute("HELLO"); // result == "hello"
 * @endcode
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
     *         Returns the original input if no strategy is set.
     */
    std::string execute(const std::string& input) const;
};

#endif // CLIENT_HPP