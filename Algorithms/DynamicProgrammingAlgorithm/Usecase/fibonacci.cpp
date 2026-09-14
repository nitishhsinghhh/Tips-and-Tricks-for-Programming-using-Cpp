// Dynamic Programming Example: Fibonacci Sequence

#include <iostream>
#include <vector>

/**
 * @brief Calculates the nth Fibonacci number using dynamic programming.
 *
 * This function uses bottom-up dynamic programming to calculate Fibonacci
 * numbers while storing previously calculated results in a vector.
 *
 * The Fibonacci sequence is defined as:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2) for n > 1
 *
 * @param n The index of the Fibonacci number to calculate.
 * @return int The nth Fibonacci number.
 */
int fibonacci(int n) {
    std::vector<int> memo(n + 1, 0);

    if (n >= 1) {
        memo[1] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

/**
 * @brief Demonstrates the Fibonacci dynamic programming algorithm.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "The " << n << "th Fibonacci number is "
              << fibonacci(n) << std::endl;

    return 0;
}