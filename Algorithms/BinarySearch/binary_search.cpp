/**
 * @file binary_search.cpp
 * @author Nitish Singh
 * @brief Demonstrates iterative Binary Search in C++.
 *
 * Binary Search operates on a sorted array by repeatedly dividing the
 * search space in half.
 *
 * Time Complexity:
 * - Best Case: O(1)
 * - Average Case: O(log N)
 * - Worst Case: O(log N)
 *
 * Space Complexity: O(1)
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Searches for a target value using iterative binary search.
 *
 * @param numbers Sorted vector of integers.
 * @param target Value to search for.
 * @return int Index of the target if found; otherwise -1.
 */
int binarySearch(const std::vector<int>& numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;

        if (numbers[mid] == target) {
            return mid;
        }

        if (numbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

/**
 * @brief Demonstrates iterative binary search.
 *
 * @return int Exit status.
 */
int main() {
    std::vector<int> numbers = {4, 6, 7, 12, 9, 3, 6, 7};

    std::sort(numbers.begin(), numbers.end());

    const int target = 6;
    const int result = binarySearch(numbers, target);

    std::cout << "Sorted array: ";

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    if (result == -1) {
        std::cout << "Target " << target << " was not found.\n";
    } else {
        std::cout << "Target " << target
                  << " found at index " << result << ".\n";
    }

    return 0;
}