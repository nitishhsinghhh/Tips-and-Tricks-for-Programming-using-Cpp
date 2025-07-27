#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Calculates the number of coins needed to make change for a given amount using a greedy algorithm.
 * 
 * This function tries to make change by always picking the largest coin denomination
 * possible at each step (greedy strategy). It may not work correctly for all coin systems
 * unless the coin denominations are canonical (like US coins).
 * 
 * @param coins A vector of available coin denominations, assumed to be sorted in increasing order.
 * @param amount The total amount to make change for.
 * @return A vector representing the number of each coin used (same order as input),
 *         or {-1} if exact change cannot be made.
 */
vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> result(coins.size(), 0);
    for (int i = coins.size() - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[i]++;
        }
    }
    if (amount > 0) {
        return { -1 };
    }
    return result;
}

/**
 * @brief Main function to accept user input and print the result of the coin change operation.
 * 
 * Prompts the user to enter an amount and prints how many coins of each denomination
 * are needed to make that amount using the greedy algorithm.
 * 
 * @return int Exit status of the program.
 */
int main() {
    vector<int> coins = { 1, 5, 10, 25 };
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
