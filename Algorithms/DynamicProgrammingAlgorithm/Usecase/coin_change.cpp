// Dynamic Programming Example: Coin Change

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/**
 * @brief Calculates the minimum number of coins required for an amount.
 *
 * For every amount from 1 to the target, the function determines the
 * minimum number of coins needed using previously calculated results.
 *
 * @param coins Available coin denominations.
 * @param amount Target amount.
 * @return int Minimum number of coins, or -1 if the amount cannot be formed.
 */
int coinChange(const std::vector<int>& coins, int amount) {
    const int impossible = std::numeric_limits<int>::max() / 2;

    std::vector<int> dp(amount + 1, impossible);
    dp[0] = 0;

    for (int currentAmount = 1; currentAmount <= amount; ++currentAmount) {
        for (int coin : coins) {
            if (coin <= currentAmount) {
                dp[currentAmount] = std::min(
                    dp[currentAmount],
                    dp[currentAmount - coin] + 1
                );
            }
        }
    }

    return dp[amount] == impossible ? -1 : dp[amount];
}

/**
 * @brief Demonstrates the Coin Change dynamic programming algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    const std::vector<int> coins = {1, 2, 5};
    const int amount = 11;

    const int result = coinChange(coins, amount);

    if (result == -1) {
        std::cout << "The amount cannot be formed." << std::endl;
    } else {
        std::cout << "Minimum number of coins required for "
                  << amount << ": " << result << std::endl;
    }

    return 0;
}