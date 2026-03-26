#ifndef MULTI_THREAD_MANAGER_HPP
#define MULTI_THREAD_MANAGER_HPP

#include <vector>
#include <thread>
#include <string>
#include "IStringConversion.hpp"

/**
 * @class MultiThreadManager
 * @brief Manages multithreaded processing of string conversions.
 *
 * This class provides functionality to process a collection of input strings
 * using multiple threads and a provided string conversion strategy.
 */
class MultiThreadManager {
public:
    /**
     * @brief Processes a list of strings using the given converter.
     *
     * This function distributes the input strings across multiple threads
     * and applies the provided string conversion logic.
     *
     * @param converter Reference to an implementation of IStringConversion
     *                  that defines how each string should be processed.
     * @param inputs A vector of input strings to be processed.
     */
    static void processStrings(const IStringConversion& converter,
                               const std::vector<std::string>& inputs);
};

#endif // MULTI_THREAD_MANAGER_HPP