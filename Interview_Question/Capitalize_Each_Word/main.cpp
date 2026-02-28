#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cassert>
#include <cctype>
#include <print> // C++23 standard printing mechanism

// Capitalize in-place using safe, idiomatic standard library transforms
std::string& capitalizeEachWord(std::string& str) {
    if (str.empty()) {
        return str;
    }

    // Capitalize first character safely
    str[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[0])));

    // Capitalize characters trailing a space sequence
    for (size_t i = 0; i < str.size() - 1; ++i) {
        if (str[i] == ' ') {
            str[i + 1] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i + 1])));
        }
    }
    return str;
}

// Cleaned validation using string_view to eliminate allocation overhead
bool is_valid_input(std::string_view s) {
    if (s.empty() || s.front() == ' ' || s.back() == ' ') {
        return false;
    }

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == ' ') {
            // Ensure space isn't followed by another space or out of bounds
            if (i + 1 >= s.size() || s[i + 1] == ' ') {
                return false;
            }
            if (!std::islower(static_cast<unsigned char>(s[i + 1]))) {
                return false;
            }
        } else {
            if (!std::islower(static_cast<unsigned char>(c))) {
                return false;
            }
        }
    }
    return true;
}

// Modernized verification function using type-safe formatting layout
void expect_eq(std::string_view input, std::string_view expected) {
    assert(is_valid_input(input) && "Input does not meet the specified constraints!");

    std::string s{input}; // Explicit copy for mutation
    std::string out = capitalizeEachWord(s);

    // Using C++23 std::print instead of legacy std::cout streams
    std::print("IN : [{}]\nOUT: [{}]\nEXP: [{}]\n----\n", input, out, expected);
    
    assert(out == expected && "Output did not match expected result!");
}

int main() {
    std::println("Testing implementation under constrained valid inputs...");

    expect_eq("a", "A");
    expect_eq("m", "M");
    expect_eq("my", "My");
    expect_eq("my name", "My Name");
    expect_eq("my name is mohit", "My Name Is Mohit");
    expect_eq("hello world this is test", "Hello World This Is Test");
    expect_eq("abcdefghijklmnopqrstuvwxyz", "Abcdefghijklmnopqrstuvwxyz");
    expect_eq("a b c d e f", "A B C D E F");
    expect_eq("aa aa aa aa aa", "Aa Aa Aa Aa Aa");

    std::println("All asserts passed for constrained valid inputs!");
    return 0;
}

// c++ -std=c++26 main.cpp -o main && ./main

/*
    Testing implementation under constrained valid inputs...
    IN : [a]
    OUT: [A]
    EXP: [A]
    ----
    IN : [m]
    OUT: [M]
    EXP: [M]
    ----
    IN : [my]
    OUT: [My]
    EXP: [My]
    ----
    IN : [my name]
    OUT: [My Name]
    EXP: [My Name]
    ----
    IN : [my name is mohit]
    OUT: [My Name Is Mohit]
    EXP: [My Name Is Mohit]
    ----
    IN : [hello world this is test]
    OUT: [Hello World This Is Test]
    EXP: [Hello World This Is Test]
    ----
    IN : [abcdefghijklmnopqrstuvwxyz]
    OUT: [Abcdefghijklmnopqrstuvwxyz]
    EXP: [Abcdefghijklmnopqrstuvwxyz]
    ----
    IN : [a b c d e f]
    OUT: [A B C D E F]
    EXP: [A B C D E F]
    ----
    IN : [aa aa aa aa aa]
    OUT: [Aa Aa Aa Aa Aa]
    EXP: [Aa Aa Aa Aa Aa]
    ----
    All asserts passed for constrained valid inputs!
 */