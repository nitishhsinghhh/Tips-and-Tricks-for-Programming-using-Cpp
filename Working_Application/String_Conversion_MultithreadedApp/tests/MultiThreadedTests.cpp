#include <gtest/gtest.h>
#include "TestUtils.hpp"
#include "IStringConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "MultiThreadManager.hpp"
#include <vector>
#include <string>
#include <mutex>
#include <iostream>

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