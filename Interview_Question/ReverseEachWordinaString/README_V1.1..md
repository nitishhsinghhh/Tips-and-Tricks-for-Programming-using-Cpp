# Reverse Each Word in a Sentence (C++ Implementation)

## Problem Statement

Given a string consisting of words separated by spaces, reverse each word **individually**, keeping the original word order intact.

### Example

**Input:** "My name is Nitishi"
**Output:** "yM eman si hsitiN"

Each word has been reversed, but the order of the words remains unchanged.

---

## Solution Approach

We approach the problem using three distinct evolutionary stages in modern C++:

1. Classic Copy & Tokenize: Allocating working buffers character-by-character.
2. Low-Level Contiguous Modification: Operating on raw, linear memory bounds directly.
3. Modern Functional Ranges: Creating non-allocating lazy pipeline projections via C++20/23/26 view compositions.

### Step-by-Step Algorithm (Ranges Projection)

1. Accept the incoming string sequence as a light, non-allocating std::string_view.
2. Apply std::views::split(' ') to create a lazy stream of sub-ranges pointing exactly to word boundaries.
3. Traverse the segmented sub-ranges without tracking manual index loops.
4. Materialize or mutate each sub-range using standard algorithm views (std::ranges::reverse).

---

## Modern C++26 Concepts Used

1. std::string_view
Introduced in C++17 and expanded throughout C++26. It serves as a zero-allocation, lightweight window (const char* pointer + size) over an existing string block.
2. Standard Ranges (std::views::split)
Provides a pipeline utility to isolate tokens dynamically without rewriting data payloads or storing temporary string copies inside vector structures.
3. Type-Safe Formatting (std::print & std::println)
Introduced in C++23 as a modern replacement for legacy std::cout streams. It removes stream synchronization overhead and offers faster compile and run-time execution.

---

## 1. Traditional Iterative String Mutation

This approach copies strings over boundaries using pass-by-reference logic.

```Cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <print>

using std::string;

string swapWords(string& s) {
    size_t size = s.size();
    for (size_t i = 0; i < size / 2; ++i) {
        std::swap(s[i], s[size - i - 1]);
    }
    return s;
}

string swapWordByWord(const string& s) {
    string res = "";
    string tmp = "";
    for (char c : s) {
        if (c != ' ') {
            tmp += c;
        } else {
            res += swapWords(tmp);
            res += ' ';
            tmp = "";
        }
    }
    res += swapWords(tmp);
    return res;
}

int main() {
    string var = "My name is Nitish";
    string res = swapWordByWord(var);
    std::println("{}", res);
    return 0;
}
```

## 2. Low-Level Optimization (Zero STL Constraints)

When working without standard library helpers, we manipulate contiguous memory using manual index logic on stack-allocated data.

Constraints Imposed

- No <string>, <vector>, or <ranges> headers allowed.
- No std::swap or std::reverse.
- Zero reliance on standard utility systems outside of low-level console streams.

```Cpp
#include <iostream>

/**
 * @brief Reverses a word in-place between indices [start, end] of a char array.
 */
void reverseWord(char* arr, int start, int end) {
    while (start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief Reverses each word in a sentence stored in a char array.
 */
void reverseEachWord(char* str) {
    int i = 0, start = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int end = (str[i] == ' ') ? i - 1 : i;
            reverseWord(str, start, end);
            start = i + 1;
        }
        i++;
    }
}

int main() {
    char sentence[] = "My name is Nitish";
    reverseEachWord(sentence);
    std::cout << sentence << std::endl;
    return 0;
}
```

## 3. Idiomatic C++26 Range Abstractions

This is the preferred modern pattern. It drops the legacy std::stringstream allocation footprint and substitutes it with zero-cost range pipelines.

Functional In-Place Transformation

```Cpp
#include <print>
#include <string>
#include <string_view>
#include <ranges>
#include <algorithm>

void reverseEachWordInPlace(std::string& str) {
    // Lazily split the string on word boundaries
    auto words_view = str | std::views::split(' ');

    for (auto&& word_range : words_view) {
        // Reverse each word segment safely in-place via underlying iterators
        std::ranges::reverse(word_range);
    }
}

int main() {
    std::string sentence = "My name is Nitish";
    reverseEachWordInPlace(sentence);
    
    // C++23 type-safe uniform print pipeline
    std::println("{}", sentence); // Output: yM eman si hsitiN
    return 0;
}
```

### Pure Functional String Construction

If you prefer returning a pristine std::string copy from a read-only parameter without modifying the original input data structure:

```Cpp
#include <print>
#include <string>
#include <string_view>
#include <ranges>
#include <algorithm>

std::string reverseEachWordRanges(std::string_view input) {
    if (input.empty()) return {};

    std::string result;
    result.reserve(input.size());

    auto words_view = input | std::views::split(' ');

    for (auto&& word_range : words_view) {
        std::string word(word_range.begin(), word_range.end());
        std::ranges::reverse(word);
        
        result += word;
        result += ' ';
    }

    if (!result.empty()) {
        result.pop_back(); // Strip trailing space delimiter safely
    }

    return result;
}

int main() {
    constexpr std::string_view sentence = "My name is Nitish";
    std::string reversed = reverseEachWordRanges(sentence);
    std::println("{}", reversed);
    return 0;
}
```

### Complexity Analysis

- Time Complexity: O(N) across all variants. Every character position is evaluated exactly once linearly, and internal reversals operate symmetrically relative to isolated word sizes.
Space Complexity:
- Traditional/Stream Abstractions: O(N) allocations due to tokenization pipelines.
Low-Level Array & Modern In-Place Ranges: O(1) auxiliary space allocations, modifying characters completely within existing memory footprints.