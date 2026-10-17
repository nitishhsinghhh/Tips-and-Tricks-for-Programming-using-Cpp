/**
 * @file binary_search_class_iterative.cpp
 * @brief Implements Binary Search using a class in C++ (Iterative method).
 * @author Nitish Singh
 * @date 2025
 *
 * @details
 * This program demonstrates how to use the Binary Search algorithm inside a class-based structure.
 * It performs an efficient search for an element in a sorted array and returns the index if found.
 */

#include <iostream>
#include <vector>

/**
 * @class BinarySearch
 * @brief A class that encapsulates an iterative binary search algorithm.
 */
class BinarySearch {
public:
    /**
     * @brief Performs binary search on a sorted vector to find the target value.
     *
     * @param arr A sorted vector of integers.
     * @param x The target value to search for.
     * @return int The index of the target if found, else -1.
     */
    int search(const std::vector<int>& arr, int x) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m] == x)
                return m;

            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};

/**
 * @brief Main function to test the BinarySearch class.
 *
 * @return int Exit status of the program.
 */
int main() {
    std::vector<int> arr{2, 3, 4, 10, 40};
    int x = 10;

    BinarySearch bs;
    int result = bs.search(arr, x);

    if (result == -1)
        std::cout << "Element is not present in array\n";
    else
        std::cout << "Element is present at index " << result << '\n';

    return 0;
}