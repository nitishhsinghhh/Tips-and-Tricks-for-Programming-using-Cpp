/**
 * @file next_greatest_letter.cpp
 * @brief Finds the smallest character in a sorted array that is greater
 * than the target character.
 *
 * @details
 * If no character is strictly greater than the target, the function wraps
 * around and returns the first element.
 *
 * This is a binary search-based solution with O(log n) time complexity.
 */

#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Implements binary search to find the next greatest letter.
 */
class Solution {
public:
    /**
     * @brief Returns the smallest character in letters that is strictly
     * greater than target.
     *
     * @param letters A vector of sorted characters.
     * @param target The target character.
     * @return char The next greatest character, with wrap-around logic.
     */
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0;
        int r = n - 1;

        // Binary search for the smallest character > target
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (letters[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }

        // If all characters are <= target, wrap around to first character
        return letters[l % n];
    }
};