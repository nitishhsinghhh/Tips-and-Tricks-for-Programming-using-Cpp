#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "StringConversionFactory.hpp"
#include "Client.hpp"

//
// 🔹 Conversion Tests
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

//
// 🔹 Edge Cases
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
// 🔹 Factory Tests
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

//
// 🔹 Client (Strategy Pattern) Tests
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

TEST(ClientTest, NoStrategySet) {
    Client client;
    EXPECT_EQ(client.execute("Hello"), "Hello"); // should return input unchanged
}