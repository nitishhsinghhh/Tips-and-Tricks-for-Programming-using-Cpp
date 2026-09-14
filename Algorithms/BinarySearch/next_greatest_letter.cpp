/**
 * @file next_greatest_letter.cpp
 * @author Nitish Singh
 * @brief Finds the smallest letter strictly greater than a target.
 *
 * Uses binary search with wrap-around.
 *
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

/**
 * @brief Finds the smallest character greater than target.
 *
 * @param letters Sorted vector of characters.
 * @param target Target character.
 * @return char Smallest character greater than target.
 */
char nextGreatestLetter(const std::vector<char>& letters,
                        char target) {
    int left = 0;
    int right = static_cast<int>(letters.size()) - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;

        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return letters[left % letters.size()];
}

/**
 * @brief Demonstrates next-greatest-letter search.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<char> letters = {'c', 'f', 'j'};
    const char target = 'd';

    std::cout << "Next greatest letter after '" << target
              << "': " << nextGreatestLetter(letters, target)
              << '\n';

    return 0;
}