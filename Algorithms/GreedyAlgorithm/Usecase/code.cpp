// Here is an example of a greedy algorithm in C++ that solves the coin change problem:

#include <iostream>
#include <vector>
using namespace std;

vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> result(coins.size(), 0);
    for (int i = coins.size() - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[i]++;
        }
    }
    if (amount > 0) {
        return {-1};
    }
    return result;
}

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

/^ 
This program uses a greedy algorithm to solve the coin change problem, which involves finding the minimum number of 
coins needed to make change for a given amount. The coinChange function takes a vector of coin denominations and an amount 
to make change for, and returns a vector of the number of each coin denomination needed to make change. It iterates through 
the coin denominations from largest to smallest, and at each step, it takes as many coins of the current denomination as 
possible until the remaining amount is less than the denomination. The function returns -1 if it is not possible to make 
change for the given amount using the given coins. The main function takes input for the amount to make change for and 
calls the coinChange function on a vector of coin denominations. If it is possible to make change, it prints the number 
of each coin denomination needed to make change to the console.

*/
