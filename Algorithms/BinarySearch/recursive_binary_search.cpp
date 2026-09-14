/**
 * @file recursive_binary_search.cpp
 * @author Nitish Singh
 * @brief Demonstrates recursive Binary Search in C++.
 *
 * Time Complexity: O(log N)
 * Auxiliary Space: O(log N) due to recursion.
 */

#include <iostream>
#include <vector>

/**
 * @brief Performs recursive binary search.
 *
 * @param numbers Sorted vector of integers.
 * @param left Left boundary of the search range.
 * @param right Right boundary of the search range.
 * @param target Value to search for.
 * @return int Index of the target if found; otherwise -1.
 */
int binarySearchRecursive(const std::vector<int>& numbers,
                          int left,
                          int right,
                          int target) {
    if (left > right) {
        return -1;
    }

    const int mid = left + (right - left) / 2;

    if (numbers[mid] == target) {
        return mid;
    }

    if (numbers[mid] < target) {
        return binarySearchRecursive(numbers, mid + 1, right, target);
    }

    return binarySearchRecursive(numbers, left, mid - 1, target);
}

/**
 * @brief Demonstrates recursive binary search.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> numbers = {2, 3, 4, 10, 40};
    const int target = 10;

    const int result = binarySearchRecursive(
        numbers,
        0,
        static_cast<int>(numbers.size()) - 1,
        target
    );

    if (result == -1) {
        std::cout << "Element is not present in the array.\n";
    } else {
        std::cout << "Element is present at index "
                  << result << ".\n";
    }

    return 0;
}