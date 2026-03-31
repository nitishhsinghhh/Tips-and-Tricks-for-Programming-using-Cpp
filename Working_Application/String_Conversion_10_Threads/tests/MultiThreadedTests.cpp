#include <gtest/gtest.h>
#include "UpperCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "MultiThreadManager.hpp"

TEST(MultiThreadManagerTest, Handles100ThreadsUpperCase) {
    UpperCaseConversion conv;

    // Generate 100 sample strings
    std::vector<std::string> inputs;
    for (int i = 0; i < 10; ++i) {
        inputs.push_back("string_" + std::to_string(i));
    }

    // Run with 100 threads
    auto results = MultiThreadManager::processStrings(conv, inputs, 100);

    // Verify each string was converted correctly
    for (size_t i = 0; i < inputs.size(); ++i) {
        EXPECT_EQ(results[i], UpperCaseConversion().convert(inputs[i]));
    }
}

TEST(MultiThreadManagerTest, Handles100ThreadsToggleCase) {
    ToggleCaseConversion conv;

    std::vector<std::string> inputs;
    for (int i = 0; i < 10; ++i) {
        inputs.push_back("string_" + std::to_string(i));
    }

    auto results = MultiThreadManager::processStrings(conv, inputs, 100);

    for (size_t i = 0; i < inputs.size(); ++i) {
        EXPECT_EQ(results[i], ToggleCaseConversion().convert(inputs[i]));
    }
}

TEST(MultiThreadManagerTest, StressTestLargeInput) {
    UpperCaseConversion conv;

    std::vector<std::string> inputs(10000, "test_string");

    auto results = MultiThreadManager::processStrings(conv, inputs, 8);

    for (size_t i = 0; i < inputs.size(); ++i) {
        EXPECT_EQ(results[i], conv.convert(inputs[i]));
    }
}
