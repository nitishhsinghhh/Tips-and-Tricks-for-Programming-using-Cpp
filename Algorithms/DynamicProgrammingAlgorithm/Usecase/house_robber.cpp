// Dynamic Programming Example: House Robber

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Calculates the maximum amount that can be robbed.
 *
 * Adjacent houses cannot both be robbed. For each house, the algorithm
 * chooses between:
 *
 * 1. Skipping the current house.
 * 2. Robbing the current house and adding its value to the best result
 *    from two houses earlier.
 *
 * @param houses Money available in each house.
 * @return int Maximum amount that can be robbed without robbing
 *         adjacent houses.
 */
int houseRobber(const std::vector<int>& houses) {
    if (houses.empty()) {
        return 0;
    }

    if (houses.size() == 1) {
        return houses[0];
    }

    std::vector<int> dp(houses.size(), 0);

    dp[0] = houses[0];
    dp[1] = std::max(houses[0], houses[1]);

    for (std::size_t i = 2; i < houses.size(); ++i) {
        dp[i] = std::max(
            dp[i - 1],
            dp[i - 2] + houses[i]
        );
    }

    return dp.back();
}

/**
 * @brief Demonstrates the House Robber dynamic programming algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    const std::vector<int> houses = {2, 7, 9, 3, 1};

    std::cout << "Maximum amount that can be robbed: "
              << houseRobber(houses)
              << std::endl;

    return 0;
}