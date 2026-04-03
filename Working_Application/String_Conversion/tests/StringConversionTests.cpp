/*********************************************************************/
/* header here */
/*********************************************************************/
#include <gtest/gtest.h>
#include <iostream>

// Core Interfaces
#include "IStringConversion.hpp"
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp"
#include "TestHelpers.hpp"

// Basic Conversions
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"
#include "ReverseConversion.hpp"

// Advanced Conversions
#include "InvertWordsConversion.hpp"
#include "KebabCaseConversion.hpp"
#include "LeetSpeakConversion.hpp"
#include "RemoveSpacesConversion.hpp"
#include "RemoveVowelsConversion.hpp"
#include "SnakeCaseConversion.hpp"

//
// ======================================================
// 1. BASIC CONVERSION TESTS
// ======================================================
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

TEST(ReverseConversionTest, Basic) {
    ReverseConversion conv;
    EXPECT_EQ(conv.convert("Hello"), "olleH");
    EXPECT_EQ(conv.convert("Hello World!"), "!dlroW olleH");
}

//
// ======================================================
// 2. ADVANCED CONVERSION TESTS
// ======================================================
//

TEST(InvertWordsConversionTest, Basic) {
    InvertWordsConversion conv;
    EXPECT_EQ(conv.convert("Hello World"), "olleH dlroW");
}

TEST(KebabCaseConversionTest, Basic) {
    KebabCaseConversion conv;
    EXPECT_EQ(conv.convert("Hello World Example"), "hello-world-example");
}

TEST(SnakeCaseConversionTest, Basic) {
    SnakeCaseConversion conv;
    EXPECT_EQ(conv.convert("Hello World Example"), "hello_world_example");
}

TEST(RemoveSpacesConversionTest, Basic) {
    RemoveSpacesConversion conv;
    EXPECT_EQ(conv.convert("Hello World"), "HelloWorld");
}

TEST(RemoveVowelsConversionTest, Basic) {
    RemoveVowelsConversion conv;
    EXPECT_EQ(conv.convert("Hello World"), "Hll Wrld");
}

TEST(LeetSpeakConversionTest, Basic) {
    LeetSpeakConversion conv;
    EXPECT_EQ(conv.convert("Hello"), "H3ll0");
    EXPECT_EQ(conv.convert("Testing"), "73571ng"); // ensure mapping matches implementation
}

//
// ======================================================
// 3. EDGE CASE TESTS
// ======================================================
//

TEST(EdgeCases, EmptyString) {
    LowerCaseConversion conv;
    EXPECT_EQ(conv.convert(""), "");
}

TEST(EdgeCases, OnlySpaces) {
    RemoveSpacesConversion conv;
    EXPECT_EQ(conv.convert("   "), "");
}

TEST(EdgeCases, NumbersOnly) {
    UpperCaseConversion conv;
    EXPECT_EQ(conv.convert("12345"), "12345");
}

TEST(EdgeCases, SpecialCharacters) {
    ReverseConversion conv;
    EXPECT_EQ(conv.convert("!@#$"), "$#@!");
}

TEST(EdgeCases, OnlyVowels) {
    RemoveVowelsConversion conv;
    EXPECT_EQ(conv.convert("aeiouAEIOU"), "");
}

TEST(EdgeCases, NoVowels) {
    RemoveVowelsConversion conv;
    EXPECT_EQ(conv.convert("bcdfg"), "bcdfg");
}

TEST(LeetSpeakConversionTest, EdgeCases) {
    LeetSpeakConversion conv;
    EXPECT_EQ(conv.convert(""), "");
    EXPECT_EQ(conv.convert("123"), "123");
}

//
// ======================================================
// 4. FACTORY TESTS
// ======================================================
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

TEST(FactoryTest, CreatesReverse) {
    auto conv = StringConversionFactory::create(ConversionType::Reverse);
    ASSERT_NE(conv, nullptr);
    EXPECT_EQ(conv->convert("Hello"), "olleH");
}

//
// ======================================================
// 5. CLIENT (STRATEGY PATTERN) TESTS
// ======================================================
//

TEST(ClientTest, ExecutesStrategy) {
    Client client;

    client.setStrategy(StringConversionFactory::create(ConversionType::Lower));
    EXPECT_EQ(client.execute("HELLO"), "hello");

    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));
    EXPECT_EQ(client.execute("AbC"), "aBc");

    client.setStrategy(StringConversionFactory::create(ConversionType::Reverse));
    EXPECT_EQ(client.execute("Hello"), "olleH");
}

TEST(ClientTest, NoStrategySet) {
    Client client;
    EXPECT_EQ(client.execute("Hello"), "Hello");
}


//
// ======================================================
// 6. PROCESS STRING TESTS
// ======================================================
//

TEST(ProcessStringTest, BasicFlow) {
    EXPECT_EQ(processString("hello world", 1), "HeLlO WoRlD"); // Alternating
    EXPECT_EQ(processString("hello world", 2), "Hello World"); // Capitalize
    EXPECT_EQ(processString("Hello", 3), "hello");       // Lower
    EXPECT_EQ(processString("Hello", 4), "HELLO");       // Upper
    EXPECT_EQ(processString("hELLO wORLD", 5), "Hello world"); // Sentence
    EXPECT_EQ(processString("HeLLo", 6), "hEllO");       // Toggle
    EXPECT_EQ(processString("Hello", 7), "olleH");       // Reverse
}

TEST(ProcessStringTest, AdvancedChoices) {
    EXPECT_EQ(processString("Hello World", 8), "Hll Wrld");       // RemoveVowels
    EXPECT_EQ(processString("Hello World", 9), "HelloWorld");     // RemoveSpaces
    EXPECT_EQ(processString("Hello World", 10), "olleH dlroW");   // InvertWords
    EXPECT_EQ(processString("Hello World", 11), "hello_world");   // SnakeCase
    EXPECT_EQ(processString("Hello World", 12), "hello-world");   // KebabCase
    EXPECT_EQ(processString("Test", 13), "7357");                 // LeetSpeak
}

TEST(ProcessStringTest, InvalidChoice) {
    EXPECT_EQ(processString("Hello", 99), "Hello");
}

//
// ======================================================
// 7. LOGGING TESTS (OPTIONAL)
// ======================================================
//

TEST(LoggingTest, ConversionLogging) {
    std::string input = "TeSt";
    ToggleCaseConversion conv;

    std::string result = conv.convert(input);
    logConversion("ToggleCase", input, result);

    EXPECT_EQ(result, "tEsT");
}