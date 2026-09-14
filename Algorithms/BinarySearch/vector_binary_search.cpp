/**
 * @file vector_binary_search.cpp
 * @author Nitish Singh
 * @brief Demonstrates sorting a vector and performing binary search.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @class VectorSearch
 * @brief Encapsulates vector sorting and binary search operations.
 */
class VectorSearch {
private:
    std::vector<int> numbers;

public:
    /**
     * @brief Constructs the search object.
     *
     * @param input Input vector.
     */
    explicit VectorSearch(const std::vector<int>& input)
        : numbers(input) {}

    /**
     * @brief Sorts the vector in ascending order.
     */
    void sortVector() {
        std::sort(numbers.begin(), numbers.end());
    }

    /**
     * @brief Checks whether a value exists using binary search.
     *
     * @param target Value to search for.
     * @return true if found; otherwise false.
     */
    bool contains(int target) const {
        return std::binary_search(
            numbers.begin(),
            numbers.end(),
            target
        );
    }

    /**
     * @brief Displays the vector.
     */
    void display() const {
        for (int number : numbers) {
            std::cout << number << ' ';
        }

        std::cout << '\n';
    }
};

/**
 * @brief Demonstrates vector sorting and binary search.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> input = {
        1, 5, 8, 9, 6, 7, 3, 4, 2, 0
    };

    VectorSearch search(input);

    std::cout << "Original vector: ";
    search.display();

    search.sortVector();

    std::cout << "Sorted vector: ";
    search.display();

    const int firstTarget = 2;
    const int secondTarget = 10;

    std::cout << "Searching for " << firstTarget << ": "
              << (search.contains(firstTarget) ? "Found" : "Not found")
              << '\n';

    std::cout << "Searching for " << secondTarget << ": "
              << (search.contains(secondTarget) ? "Found" : "Not found")
              << '\n';

    return 0;
}