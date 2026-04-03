/*********************************************************************/
/* header here */
/*********************************************************************/

#include <gtest/gtest.h>
#include "TestHelpers.hpp"

// ---------------------------
// Core Includes
// ---------------------------
#include "TestHelpers.hpp"
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"
#include "ReverseConversion.hpp"

// ---------------------------
// Design Pattern / Framework
// ---------------------------
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp"

#include <iostream>

// ============================================================
// 1. ADVANCED CONVERSION TESTS (WITH LOGGING)
// ============================================================

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

// ============================================================
// 2. CLIENT (STRATEGY PATTERN) TESTS
// ============================================================

TEST(ClientTest, ExecuteStrategyWithLog) {
    std::string input = "TeStInG";

    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));

    std::string output = client.execute(input);

    std::cout << "[Client Toggle] Input: \"" << input
              << "\" => Output: \"" << output << "\"" << std::endl;

    EXPECT_EQ(output, "tEsTiNg");
}

// ============================================================
// 3. PROCESS STRING (INTEGRATION TEST)
// ============================================================

TEST(ProcessStringTest, ProcessStringAlternating) {
    std::string input = "Hello World!";
    int choice = 1; // Alternating case

    std::string output = processString(input, choice);

    logConversion("ProcessString Alternating", input, output);

    EXPECT_EQ(output, "HeLlO WoRlD!");
}

TEST(ProcessStringTest, ProcessStringReverse) {
    std::string input = "Hello World!";
    int choice = 7; // Reverse

    std::string output = processString(input, choice);

    logConversion("ProcessString Reverse", input, output);

    EXPECT_EQ(output, "!dlroW olleH");
}

// ============================================================
// 4. SPECIAL CONVERSION TESTS
// ============================================================

TEST(ReverseConversionTest, ReverseStringWithLog) {
    std::string input = "Hello World!";
    ReverseConversion reverse;

    std::string output = reverse.convert(input);

    logConversion("ReverseCase", input, output);

    EXPECT_EQ(output, "!dlroW olleH");
}
