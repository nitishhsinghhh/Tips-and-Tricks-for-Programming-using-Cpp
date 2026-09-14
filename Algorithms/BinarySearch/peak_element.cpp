/**
 * @file peak_element.cpp
 * @author Nitish Singh
 * @brief Finds a peak element using Binary Search.
 *
 * A peak element is an element greater than its adjacent elements.
 *
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

/**
 * @brief Finds the index of a peak element.
 *
 * @param numbers Input vector.
 * @return int Index of a peak element.
 */
int findPeakElement(const std::vector<int>& numbers) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left < right) {
        const int mid = left + (right - left) / 2;

        if (numbers[mid] < numbers[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

/**
 * @brief Demonstrates peak element search.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> numbers = {1, 2, 1, 3, 5, 6, 4};

    const int index = findPeakElement(numbers);

    std::cout << "Peak element: " << numbers[index] << '\n';
    std::cout << "Peak index: " << index << '\n';

    return 0;
}