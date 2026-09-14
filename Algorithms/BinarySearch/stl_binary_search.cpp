/**
 * @file stl_binary_search.cpp
 * @author Nitish Singh
 * @brief Demonstrates std::binary_search from the C++ Standard Library.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Demonstrates STL binary search.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> numbers = {1, 3, 4, 5, 9};
    const std::vector<int> targets = {1, 2, 3};

    for (const int target : targets) {
        std::cout << "Searching for " << target << ": ";

        if (std::binary_search(
                numbers.begin(),
                numbers.end(),
                target)) {
            std::cout << "Found\n";
        } else {
            std::cout << "Not found\n";
        }
    }

    return 0;
}