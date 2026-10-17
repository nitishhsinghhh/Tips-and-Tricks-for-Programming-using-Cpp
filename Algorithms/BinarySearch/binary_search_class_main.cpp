/**
 * @file binary_search_class_main.cpp
 * @brief Demonstrates Binary Search using a class-based implementation in C++.
 * @author Nitish Singh
 * @date 2025
 *
 * @details
 * This program defines a BinarySearch class containing a method to perform binary search
 * on a sorted array. It checks whether a given element exists in the array and prints
 * its index or an appropriate message if not found.
 */

#include <iostream>
#include <vector>

/**
 * @class BinarySearch
 * @brief A class that encapsulates binary search functionality.
 */
class BinarySearch {
public:
    /**
     * @brief Searches for a target value in a sorted vector using binary search.
     *
     * @param arr A sorted vector of integers.
     * @param x The target value to search for.
     * @return int The index of the target if found, else -1.
     */
    int search(const std::vector<int>& arr, int x) {
        int l = 0;
        int r = arr.size() - 1;

        while (r >= l) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};

/**
 * @brief The main function to test the BinarySearch class.
 *
 * @return int Exit status of the program.
 */
int main() {
    std::vector<int> arr{2, 3, 4, 10, 40};
    int x = 10;

    BinarySearch bs;
    int result = bs.search(arr, x);

    if (result == -1)
        std::cout << "Element is not present in array";
    else
        std::cout << "Element is present at index " << result;

    std::cout << std::endl;

    return 0;
}