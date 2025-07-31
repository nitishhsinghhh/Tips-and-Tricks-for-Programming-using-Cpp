#include <iostream>
using namespace std;

/**
 * @brief Calculates the factorial of a non-negative integer using recursion.
 * @param n The number to calculate factorial of.
 * @return The factorial of n.
 */
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << n << "! = " << factorial(n) << endl;
    }

    return 0;
}
/**
==================== PROGRAM DESCRIPTION =====================
This program uses a recursive function to calculate the factorial
of a given non-negative integer.
Example Input/Output:
Input: 5
Output: 5! = 120
Input: 0
Output: 0! = 1
Input: -3
Output: Factorial is not defined for negative numbers.
===============================================================
**/
