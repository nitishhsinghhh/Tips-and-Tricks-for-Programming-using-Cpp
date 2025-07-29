#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Calculates the number of coins needed to make change for a given amount using a greedy algorithm.
 * 
 * This function implements a greedy strategy to compute the minimum number of coins
 * required to make the given amount using the largest denominations first.
 * 
 * @param coins A vector of available coin denominations, sorted in increasing order.
 * @param amount The total amount (in cents) to make change for.
 * @return std::vector<int> A vector representing the number of each coin used (in the same order as input),
 *         or {-1} if it is not possible to make exact change.
 * 
 * @note This algorithm works correctly only for canonical coin systems (e.g., US coins). 
 *       For arbitrary denominations, it may not yield the optimal solution.
 * 
 * @see https://en.wikipedia.org/wiki/Greedy_algorithm
 */
vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> result(coins.size(), 0);

    // Iterate from the largest coin to the smallest
    for (int i = coins.size() - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[i]++;
        }
    }

    // If exact change can't be made
    if (amount > 0) {
        return { -1 };
    }

    return result;
}

/**
 * @brief Main function to execute the coin change program.
 * 
 * Reads an amount from user input and calculates the minimum number of coins
 * required to make that amount using the greedy algorithm.
 * 
 * The program uses US coin denominations: 1, 5, 10, and 25 cents.
 * 
 * @return int Exit code (0 = success).
 */
int main() {
    vector<int> coins = { 1, 5, 10, 25 }; ///< US coin denominations (in cents)
    int amount;

    cout << "Enter the amount to make change for: ";
    cin >> amount;

    vector<int> result = coinChange(coins, amount);

    if (result[0] == -1) {
        cout << "Cannot make change for " << amount << "." << endl;
    } else {
        cout << "Coins needed to make change for " << amount << ":" << endl;
        for (int i = coins.size() - 1; i >= 0; i--) {
            if (result[i] > 0) {
                cout << result[i] << " x " << coins[i] << " cents" << endl;
            }
        }
    }

    return 0;
}
