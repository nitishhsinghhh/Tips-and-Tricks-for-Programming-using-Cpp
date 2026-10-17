/**
 * @file vector_search.cpp
 * @brief Demonstrates class-based vector operations: sorting and binary search
 * in C++.
 * @author Nitish Singh
 *
 * @details
 * This program defines a class `VectorSearch` that:
 * - Stores a vector of integers.
 * - Sorts the vector using `std::sort`.
 * - Searches for a value using `std::binary_search`.
 *
 * It also includes a demonstration in `main()` using hardcoded values.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @class VectorSearch
 * @brief A class to encapsulate vector operations.
 */
class VectorSearch {
private:
    std::vector<int> vec; ///< Internal vector to operate on

public:
    /**
     * @brief Constructor to initialize the vector.
     * @param v Input vector of integers.
     */
    VectorSearch(const std::vector<int>& v) : vec(v) {}

    /**
     * @brief Displays the contents of the vector.
     */
    void show() {
        for (int i : vec)
            std::cout << i << " ";
    }

    /**
     * @brief Sorts the vector in ascending order.
     */
    void sortVector() {
        std::sort(vec.begin(), vec.end());
    }

    /**
     * @brief Performs binary search on the sorted vector.
     * @param key The value to search for.
     * @return true if the key is found, false otherwise.
     */
    bool binarySearch(int key) {
        return std::binary_search(vec.begin(), vec.end(), key);
    }
};

/**
 * @brief Main function to demonstrate the use of VectorSearch class.
 * @return int Exit status of the program.
 */
int main() {
    std::vector<int> vec = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    std::cout << "The original vector is: ";

    VectorSearch vectorSearch(vec);
    vectorSearch.show();

    std::cout << "\n\nSorting the vector before performing binary search...";

    vectorSearch.sortVector();

    std::cout << "\n\nThe sorted vector is: ";
    vectorSearch.show();

    std::cout << "\n\nBinary Search for element 2:";

    if (vectorSearch.binarySearch(2))
        std::cout << "\n Element found in the vector.";
    else
        std::cout << "\n Element not found in the vector.";

    std::cout << "\n\nBinary Search for element 10:";

    if (vectorSearch.binarySearch(10))
        std::cout << "\n Element found in the vector.\n";
    else
        std::cout << "\n Element not found in the vector.\n";

    // Portable alternative to system("pause")
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    std::cin.get();

    return 0;
}