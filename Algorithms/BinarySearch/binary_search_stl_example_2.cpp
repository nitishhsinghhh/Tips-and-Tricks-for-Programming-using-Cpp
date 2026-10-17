#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Entry point of the program.
 *
 * Initializes a sorted vector (`haystack`) and a set of target values
 * (`needles`), then performs binary search on each needle and prints
 * the result.
 *
 * @return int Exit code of the program.
 */
int main() {
    std::vector<int> haystack{1, 3, 4, 5, 9};
    std::vector<int> needles{1, 2, 3};

    for (const auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';

        // Perform binary search
        if (std::binary_search(haystack.begin(), haystack.end(), needle))
            std::cout << "Found " << needle << '\n';
        else
            std::cout << "No dice!\n";
    }
}