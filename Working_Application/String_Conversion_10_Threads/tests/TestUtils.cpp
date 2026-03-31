#include "TestUtils.hpp"
#include <iostream>

void logConversion(const std::string& input,
                   const std::string& output,
                   const std::string& type) {
    std::cout << "[" << type << "] "
              << input << " -> " << output << std::endl;
}