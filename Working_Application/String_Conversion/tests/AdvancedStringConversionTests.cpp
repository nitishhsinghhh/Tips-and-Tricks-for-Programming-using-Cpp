#include <gtest/gtest.h>
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"  
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp"
#include <iostream>

// Helper function to print results
void logConversion(const std::string& name, const std::string& input, const std::string& output) {
    std::cout << "[" << name << "] Input: \"" << input << "\" => Output: \"" << output << "\"" << std::endl;
}

// ---------------------------
// Advanced Conversion Tests with Logging
// ---------------------------

TEST(AdvancedConversionTest, MixedCaseInputWithLog) {
    std::string input = "hElLo WoRLd!";

    LowerCaseConversion lower;
    UpperCaseConversion upper;
    CapitalizeWordsConversion cap;
    SentenceCaseConversion sentence;
    ToggleCaseConversion toggle;
    AlternatingCaseConversion alternating;

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

    result = alternating.convert(input);
    logConversion("AlternatingCase", input, result);
    EXPECT_EQ(result, "HeLlO WoRlD!");
}

// ---------------------------
// Client Strategy Test with Logging
// ---------------------------

TEST(ClientTest, ExecuteStrategyWithLog) {
    std::string input = "TeStInG";

    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));
    std::string output = client.execute(input);

    std::cout << "[Client Toggle] Input: \"" << input << "\" => Output: \"" << output << "\"" << std::endl;
    EXPECT_EQ(output, "tEsTiNg");
}

// ---------------------------
// ProcessString Helper Test
// ---------------------------

TEST(ProcessStringTest, ProcessStringToggle) {
    std::string input = "Hello World!";
    int choice = 5; // Toggle

    std::string output = processString(input, choice);
    logConversion("ProcessString Toggle", input, output);
    EXPECT_EQ(output, "HeLlO wOrlD!");
}
