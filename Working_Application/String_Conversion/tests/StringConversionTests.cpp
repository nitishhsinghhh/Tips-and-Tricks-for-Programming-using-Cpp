#include <gtest/gtest.h>
#include "TestHelpers.hpp"
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"
#include "ReverseConversion.hpp"
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp"
#include <iostream>

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
// Reverse Conversion Tests
//
TEST(ReverseConversionTest, Basic) {
    ReverseConversion conv;
    EXPECT_EQ(conv.convert("Hello"), "olleH");
    EXPECT_EQ(conv.convert("Hello World!"), "!dlroW olleH");
}

TEST(ConversionEdgeCases, ReverseEmptyString) {
    ReverseConversion conv;
    EXPECT_EQ(conv.convert(""), "");
}

TEST(ConversionEdgeCases, ReverseNumbersAndSymbols) {
    ReverseConversion conv;
    EXPECT_EQ(conv.convert("123!@#"), "#@!321");
}

//
// Factory Tests for Reverse
//
TEST(FactoryTest, CreatesReverseCase) {
    auto conv = StringConversionFactory::create(ConversionType::Reverse);
    ASSERT_NE(conv, nullptr);
    EXPECT_EQ(conv->convert("Hello"), "olleH");
}

//
// Client (Strategy Pattern) Tests for Reverse
//
TEST(ClientTest, ExecutesReverseStrategy) {
    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Reverse));
    EXPECT_EQ(client.execute("Hello"), "olleH");
}

