#include <gtest/gtest.h>
#include "IStringConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "MultiThreadManager.hpp"
#include <vector>
#include <string>
#include <mutex>
#include <iostream>

// Optional: to safely log from multiple threads
std::mutex coutMutex;
void logConversion(const std::string& name, const std::string& input, const std::string& output) {
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << "[" << name << "] Input: \"" << input << "\" => Output: \"" << output << "\"" << std::endl;
}

// Test multi-threaded processing of UpperCaseConversion
TEST(MultiThreadedConversionTest, UpperCaseStrings) {
    UpperCaseConversion converter;
    std::vector<std::string> inputs = {"hello", "world", "multi-threaded"};

    // MultiThreadManager prints each result
    MultiThreadManager::processStrings(converter, inputs);

    // Optional: assertions if you modify MultiThreadManager to return results
    // EXPECT_EQ(results[0], "HELLO");
    // EXPECT_EQ(results[1], "WORLD");
    // EXPECT_EQ(results[2], "MULTI-THREADED");
}

// Test multi-threaded processing of ToggleCaseConversion
TEST(MultiThreadedConversionTest, ToggleCaseStrings) {
    ToggleCaseConversion converter;
    std::vector<std::string> inputs = {"hello", "world", "multi-threaded"};

    MultiThreadManager::processStrings(converter, inputs);
}