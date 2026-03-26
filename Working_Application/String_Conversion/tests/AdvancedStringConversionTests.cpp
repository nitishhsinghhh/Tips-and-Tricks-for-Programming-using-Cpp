#include <gtest/gtest.h>
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp" 

// ---------------------------
// Advanced Conversion Tests
// ---------------------------

// Mixed case input
TEST(AdvancedConversionTest, MixedCaseInput) {
    LowerCaseConversion lower;
    UpperCaseConversion upper;
    CapitalizeWordsConversion cap;
    SentenceCaseConversion sentence;
    ToggleCaseConversion toggle;

    std::string input = "hElLo WoRLd!";

    EXPECT_EQ(lower.convert(input), "hello world!");
    EXPECT_EQ(upper.convert(input), "HELLO WORLD!");
    EXPECT_EQ(cap.convert(input), "Hello World!");
    EXPECT_EQ(sentence.convert(input), "Hello world!");
    EXPECT_EQ(toggle.convert(input), "HeLlO wOrlD!");
}

// Numeric and punctuation handling
TEST(AdvancedConversionTest, NumericAndPunctuation) {
    std::string input = "123abc!@# DEF";

    CapitalizeWordsConversion cap;
    ToggleCaseConversion toggle;

    EXPECT_EQ(cap.convert(input), "123abc!@# Def");
    EXPECT_EQ(toggle.convert(input), "123ABC!@# def");
}

// Empty string multiple conversions
TEST(AdvancedConversionTest, EmptyStringMultipleConversions) {
    std::string input = "";
    Client client;

    client.setStrategy(StringConversionFactory::create(ConversionType::Lower));
    EXPECT_EQ(client.execute(input), "");

    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));
    EXPECT_EQ(client.execute(input), "");
}

// All strategies combined in loop
TEST(AdvancedConversionTest, LoopAllStrategies) {
    std::string input = "Hello World 123!";
    std::vector<ConversionType> types = {
        ConversionType::Lower,
        ConversionType::Upper,
        ConversionType::Capitalize,
        ConversionType::Sentence,
        ConversionType::Toggle
    };

    for (auto type : types) {
        auto conv = StringConversionFactory::create(type);
        ASSERT_NE(conv, nullptr);
        std::string output = conv->convert(input);
        EXPECT_FALSE(output.empty());
    }
}

// Stress test: very long string
TEST(AdvancedConversionTest, VeryLongString) {
    std::string input(10000, 'a'); // 10,000 'a's
    input[5000] = 'Z';

    ToggleCaseConversion toggle;
    std::string output = toggle.convert(input);

    EXPECT_EQ(output.size(), input.size());
    EXPECT_EQ(output[5000], 'z'); // toggled
}

// Factory returns nullptr for invalid enum
TEST(AdvancedConversionTest, FactoryInvalidType) {
    // Force cast to simulate invalid type
    auto conv = StringConversionFactory::create(static_cast<ConversionType>(999));
    EXPECT_EQ(conv, nullptr);
}

// Chained client strategies
TEST(AdvancedConversionTest, ChainedClientStrategies) {
    std::string input = "hello world";

    Client client;
    client.setStrategy(StringConversionFactory::create(ConversionType::Upper));
    std::string output1 = client.execute(input);

    client.setStrategy(StringConversionFactory::create(ConversionType::Toggle));
    std::string output2 = client.execute(output1);

    EXPECT_EQ(output1, "HELLO WORLD");
    EXPECT_EQ(output2, "hello world"); // toggled back
}