// Here is an example of a dynamic programming algorithm in C++ that solves the Fibonacci sequence:

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Calculates the nth Fibonacci number using dynamic programming.
 *
 * This function computes the Fibonacci sequence iteratively, storing previously
 * calculated values in a memoization table (vector) to avoid redundant computations.
 *
 * The Fibonacci sequence is defined as:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2) for n > 1
 *
 * @param n The index of the Fibonacci number to calculate (e.g., n=5 returns the 5th Fibonacci number).
 * It is assumed that n is a non-negative integer. For n=0, it returns 0.
 * @return int The nth Fibonacci number.
 */
int fibonacci(int n) {
    // Create a vector to store the computed Fibonacci numbers.
    // The size is n + 1 because we need to store up to F(n), and indices are 0-based.
    vector<int> memo(n + 1, 0);

    // Base cases for the Fibonacci sequence.
    // F(0) is already 0 by initialization.
    if (n >= 1) {
        memo[1] = 1;
    }

    // Iterate from the 2nd number up to n, calculating each Fibonacci number
    // by summing the two preceding ones.
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    // Return the nth Fibonacci number from the memoization table.
    return memo[n];
}

/**
 * @brief Main function to demonstrate the Fibonacci calculation.
 *
 * Prompts the user to enter a number, then calculates and prints the
 * corresponding Fibonacci number using the fibonacci() function.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n; // Read the input number from the user.
    // Print the result to the console.
    cout << "The " << n << "th Fibonacci number is " << fibonacci(n) << endl;
    return 0; // Indicate successful program execution.
}
