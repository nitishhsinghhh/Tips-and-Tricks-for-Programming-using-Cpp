#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <string>
#include <iostream>

// Helper function to log string conversions
inline void logConversion(const std::string& name,
                          const std::string& input,
                          const std::string& output) {
    std::cout << "[" << name << "] Input: \"" << input
              << "\" => Output: \"" << output << "\"" << std::endl;
}

#endif // TEST_HELPERS_HPP