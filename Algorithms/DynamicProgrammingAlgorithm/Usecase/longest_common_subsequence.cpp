// Dynamic Programming Example: Longest Common Subsequence

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @brief Calculates the length of the Longest Common Subsequence.
 *
 * The function compares two strings and builds a dynamic programming
 * table where dp[i][j] represents the LCS length for the first i
 * characters of the first string and the first j characters of
 * the second string.
 *
 * @param first The first input string.
 * @param second The second input string.
 * @return int Length of the longest common subsequence.
 */
int longestCommonSubsequence(const std::string& first,
                             const std::string& second) {
    const int m = static_cast<int>(first.size());
    const int n = static_cast<int>(second.size());

    std::vector<std::vector<int>> dp(
        m + 1,
        std::vector<int>(n + 1, 0)
    );

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

/**
 * @brief Demonstrates the Longest Common Subsequence algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    const std::string first = "ABCBDAB";
    const std::string second = "BDCABA";

    std::cout << "Length of the Longest Common Subsequence: "
              << longestCommonSubsequence(first, second)
              << std::endl;

    return 0;
}