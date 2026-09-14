// Dynamic Programming Example: Climbing Stairs

#include <iostream>
#include <vector>

/**
 * @brief Calculates the number of ways to climb a staircase.
 *
 * Each move can consist of either one step or two steps.
 * The problem follows the recurrence:
 *
 * ways(n) = ways(n-1) + ways(n-2)
 *
 * This is solved using bottom-up dynamic programming.
 *
 * @param n The total number of stairs.
 * @return int The number of distinct ways to reach the top.
 */
int climbingStairs(int n) {
    if (n <= 1) {
        return 1;
    }

    std::vector<int> ways(n + 1, 0);

    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; ++i) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}

/**
 * @brief Demonstrates the Climbing Stairs dynamic programming algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    int n;

    std::cout << "Enter the number of stairs: ";
    std::cin >> n;

    std::cout << "Number of ways to climb " << n
              << " stairs: " << climbingStairs(n) << std::endl;

    return 0;
}