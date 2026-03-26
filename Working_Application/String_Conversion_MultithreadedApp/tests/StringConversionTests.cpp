#include <gtest/gtest.h>
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include <iostream>

// Helper function to print results
void logConversion(const std::string& name, const std::string& input, const std::string& output) {
    std::cout << "[" << name << "] Input: \"" << input << "\" => Output: \"" << output << "\"" << std::endl;
}

// ---------------------------
// Conversion Tests with logging
// ---------------------------

TEST(ConversionTest, MixedCaseInputWithLog) {
    std::string input = "hElLo WoRLd!";

    LowerCaseConversion lower;
    UpperCaseConversion upper;
    CapitalizeWordsConversion cap;
    SentenceCaseConversion sentence;
    ToggleCaseConversion toggle;

    std::string result;

    result = lower.convert(input);
    logConversion("LowerCase", input, result);
    EXPECT_EQ(result, "hello world!");

    result = upper.convert(input);
    logConversion("UpperCase", input, result);
    EXPECT_EQ(result, "HELLO WORLD!");

    result = cap.convert(input);
    logConversion("CapitalizeWords", input, result);
    EXPECT_EQ(result, "Hello World!");

    result = sentence.convert(input);
    logConversion("SentenceCase", input, result);
    EXPECT_EQ(result, "Hello world!");

    result = toggle.convert(input);
    logConversion("ToggleCase", input, result);
    EXPECT_EQ(result, "HeLlO wOrlD!");
}