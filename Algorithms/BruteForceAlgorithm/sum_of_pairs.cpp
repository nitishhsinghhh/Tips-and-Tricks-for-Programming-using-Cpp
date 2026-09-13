/**
 * @file sum_of_pairs.cpp
 * @author Nitish Singh
 * @brief Brute-force algorithm to find all pairs that sum to a target.
 * @version 0.1
 * @date 2026-09-13
 *
 * @copyright Copyright (c) 2016-2026
 */

#include <iostream>
#include <vector>

/**
 * @brief Finds and prints all pairs whose sum equals the target.
 *
 * Checks every possible pair using two nested loops.
 *
 * @param arr The input vector.
 * @param target The required pair sum.
 */
void findPairs(const std::vector<int>& arr, int target) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == target) {
                std::cout << '(' << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }
}

/**
 * @brief Main entry point for the pair-sum demonstration.
 *
 * @return int Exit status code.
 */
int main() {
    const std::vector<int> numbers = {1, 3, 5, 2, 4, 6};
    const int target = 7;

    std::cout << "Pairs summing to " << target << ":\n";

    findPairs(numbers, target);

    return 0;
}