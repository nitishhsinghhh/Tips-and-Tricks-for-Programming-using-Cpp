// Dynamic Programming Example: 0/1 Knapsack

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Calculates the maximum value that can fit in a knapsack.
 *
 * Each item can either be selected once or skipped.
 * The dynamic programming state stores the maximum value achievable
 * for each capacity.
 *
 * @param weights The weights of the available items.
 * @param values The values of the available items.
 * @param capacity Maximum weight capacity of the knapsack.
 * @return int Maximum achievable value.
 */
int knapsack(const std::vector<int>& weights,
             const std::vector<int>& values,
             int capacity) {
    std::vector<int> dp(capacity + 1, 0);

    for (std::size_t i = 0; i < weights.size(); ++i) {
        for (int currentCapacity = capacity;
             currentCapacity >= weights[i];
             --currentCapacity) {

            dp[currentCapacity] = std::max(
                dp[currentCapacity],
                dp[currentCapacity - weights[i]] + values[i]
            );
        }
    }

    return dp[capacity];
}

/**
 * @brief Demonstrates the 0/1 Knapsack dynamic programming algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    const std::vector<int> weights = {1, 3, 4, 5};
    const std::vector<int> values = {1, 4, 5, 7};
    const int capacity = 7;

    std::cout << "Maximum value for capacity " << capacity
              << ": " << knapsack(weights, values, capacity)
              << std::endl;

    return 0;
}