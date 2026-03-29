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

// Helper function for logging conversions
void logConversion(const std::string& name, const std::string& input, const std::string& output) {
    std::cout << "[" << name << "] Input: \"" << input << "\" => Output: \"" << output << "\"" << std::endl;
}

//
// Basic Conversion Tests
//
TEST(LowerCaseConversionTest, Basic) {
    LowerCaseConversion conv;
    EXPECT_EQ(conv.convert("HELLO"), "hello");
}

TEST(UpperCaseConversionTest, Basic) {
    UpperCaseConversion conv;
    EXPECT_EQ(conv.convert("hello"), "HELLO");
}

TEST(CapitalizeWordsConversionTest, Basic) {
    CapitalizeWordsConversion conv;
    EXPECT_EQ(conv.convert("hello world"), "Hello World");
}

TEST(SentenceCaseConversionTest, Basic) {
    SentenceCaseConversion conv;
    EXPECT_EQ(conv.convert("hELLO WORLD"), "Hello world");
}

TEST(ToggleCaseConversionTest, Basic) {
    ToggleCaseConversion conv;
    EXPECT_EQ(conv.convert("HeLLo"), "hEllO");
}

TEST(AlternatingCaseConversionTest, Basic) {
    AlternatingCaseConversion conv;
    EXPECT_EQ(conv.convert("hello world"), "HeLlO WoRlD");
}

//
// Edge Cases
//
TEST(ConversionEdgeCases, EmptyString) {
    LowerCaseConversion conv;
    EXPECT_EQ(conv.convert(""), "");
}

TEST(ConversionEdgeCases, NumbersAndSymbols) {
    UpperCaseConversion conv;
    EXPECT_EQ(conv.convert("abc123!@#"), "ABC123!@#");
}

//
// Factory Tests
//
TEST(FactoryTest, CreatesLowerCase) {
    auto conv = StringConversionFactory::create(ConversionType::Lower);
    ASSERT_NE(conv, nullptr);
    EXPECT_EQ(conv->convert("HELLO"), "hello");
}

TEST(FactoryTest, CreatesUpperCase) {
    auto conv = StringConversionFactory::create(ConversionType::Upper);
    ASSERT_NE(conv, nullptr);
    EXPECT_EQ(conv->convert("hello"), "HELLO");
}

TEST(FactoryTest, CreatesAlternatingCase) {
    auto conv = StringConversionFactory::create(ConversionType::Alternating);
    ASSERT_NE(conv, nullptr);
    EXPECT_EQ(conv->convert("hello world"), "HeLlO WoRlD");
}

//
// Client (Strategy Pattern) Tests
//
TEST(ClientTest, ExecutesLowerCaseStrategy) {
    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Lower));
    EXPECT_EQ(client.execute("HELLO"), "hello");
}

TEST(ClientTest, ExecutesToggleStrategy) {
    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));
    EXPECT_EQ(client.execute("AbC"), "aBc");
}

TEST(ClientTest, ExecutesAlternatingStrategy) {
    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Alternating));
    EXPECT_EQ(client.execute("hello world"), "HeLlO WoRlD");
}

TEST(ClientTest, NoStrategySet) {
    Client client;
    EXPECT_EQ(client.execute("Hello"), "Hello"); // should return input unchanged
}

//
// Advanced Conversion Tests with Logging
//
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

TEST(ProcessStringTest, ProcessStringToggle) {
    std::string input = "Hello World!";
    int choice = 5; // Toggle

    std::string output = processString(input, choice);
    logConversion("ProcessString Toggle", input, output);
    EXPECT_EQ(output, "HeLlO wOrlD!");
}