#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>

// ============================================================================
// Approach 1: The Modern Range-Based View Way (Idiomatic C++20/C++23/C++26)
// ============================================================================
// Zero dynamic allocations for tokenization. We lazily split the string_view 
// by space, copy the segments into a result string, and reverse them in place.
std::string reverseEachWordRanges(std::string_view input) {
    if (input.empty()) return {};

    std::string result;
    result.reserve(input.size());

    // Clear, declaration-driven splitting using standard ranges
    auto words_view = input | std::views::split(' ');

    for (auto&& word_range : words_view) {
        // Construct a clean sub-string from the lazy range view segment
        std::string word(word_range.begin(), word_range.end());
        std::ranges::reverse(word);
        
        result += word;
        result += ' ';
    }

    if (!result.empty()) {
        result.pop_back(); // Strip trailing space
    }

    return result;
}

// ============================================================================
// Approach 2: Clean In-Place Range Modification (Replaces raw char* pointers)
// ============================================================================
// Instead of unsafe manual indexing on a char*, we use subrange pointers 
// directly on a standard string's mutable character sequence.
void reverseEachWordInPlace(std::string& str) {
    auto words_view = str | std::views::split(' ');

    for (auto&& word_range : words_view) {
        // std::ranges::reverse safely operates on the underlying iterators
        std::ranges::reverse(word_range);
    }
}

// ============================================================================
// Approach 3: String Stream Pipeline (Modernized iteration syntax)
// ============================================================================
std::string reverseEachWordStream(std::string_view input) {
    std::stringstream ss{std::string(input)};
    std::string word, result;

    while (ss >> word) {
        std::ranges::reverse(word);
        result += word;
        result += ' ';
    }

    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int main() {
    constexpr std::string_view sourceSentence = "My name is Nitish";

    // --- Method 1: Functional Range Abstraction ---
    std::string method1 = reverseEachWordRanges(sourceSentence);
    std::println("Method 1 (Ranges): {}", method1);


    // --- Method 2: Modern In-Place Mutation ---
    std::string method2{sourceSentence};
    reverseEachWordInPlace(method2);
    std::println("Method 2 (In-Place): {}", method2);


    // --- Method 3: Cleaned Up Stream Pipeline ---
    std::string method3 = reverseEachWordStream(sourceSentence);
    std::println("Method 3 (Streams): {}", method3);

    return 0;
}