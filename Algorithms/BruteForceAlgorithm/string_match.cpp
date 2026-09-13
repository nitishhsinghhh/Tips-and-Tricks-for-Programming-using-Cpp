/**
 * @file string_match.cpp
 * @author Nitish Singh
 * @brief Brute-force algorithm for substring pattern matching.
 * @version 0.1
 * @date 2026-09-13
 *
 * @copyright Copyright (c) 2016-2026
 */

#include <iostream>
#include <string>

/**
 * @brief Searches for every occurrence of a pattern in a text.
 *
 * Compares the pattern against every possible starting position
 * in the input text.
 *
 * @param text The text to search.
 * @param pattern The pattern to find.
 */
void searchPattern(const std::string& text, const std::string& pattern) {
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    if (m == 0) {
        std::cout << "Pattern is empty.\n";
        return;
    }

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }

        if (j == m) {
            std::cout << "Pattern found at index " << i << '\n';
        }
    }
}

/**
 * @brief Main entry point for the string-matching demonstration.
 *
 * @return int Exit status code.
 */
int main() {
    const std::string text = "bruteforcebrutematch";
    const std::string pattern = "brute";

    searchPattern(text, pattern);

    return 0;
}