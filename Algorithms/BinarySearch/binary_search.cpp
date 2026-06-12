/**
 * @file binary_search.cpp
 * @author Nitish Singh
 * @email me.singhnitish@yandex.com
 * @brief Demonstrates the use of the Binary Search algorithm in C++.
 * @date 2025
 *
 * @details
 * Binary Search is a divide-and-conquer algorithm used to efficiently find the position
 * of a target value in a sorted array. This implementation first sorts the input array
 * and then applies binary search to check whether a given key exists.
 *
 * The program runs two test cases and prints the corresponding results.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Performs binary search on a sorted array to find the index of a given key.
 *
 * @param nums The sorted vector of integers.
 * @param search_key The value to search for.
 * @return int Index of the element if found; otherwise, -1.
 */
int binary_search(std::vector<int>& nums, int search_key) {
    int ans_index = -1;
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] == search_key) {
            ans_index = mid;
            break;
        } else if (nums[mid] < search_key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans_index;
}

/**
 * @brief Main function to demonstrate binary search.
 *
 * @return int Exit status.
 */
int main() {
    std::vector<int> numbers = {4, 6, 7, 12, 9, 3, 6, 7};
    int search_key = 6;
    int res;

    // Sort the input array before performing binary search
    std::sort(numbers.begin(), numbers.end());

    // Test case 1: Search for 6
    res = binary_search(numbers, search_key);

    if (res == -1)
        std::cout << "Test Case 1: Element is not found\n";
    else
        std::cout << "Test Case 1: Element has been found\n";

    // Test case 2: Search for 5
    res = binary_search(numbers, 5);

    if (res == -1)
        std::cout << "Test Case 2: Element is not found\n";
    else
        std::cout << "Test Case 2: Element has been found\n";

    return 0;
}