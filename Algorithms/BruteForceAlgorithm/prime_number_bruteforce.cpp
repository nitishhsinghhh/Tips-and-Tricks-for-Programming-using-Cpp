/**
 * @file prime_number_bruteforce.cpp
 * @author Nitish Singh
 * @brief Brute-force algorithm to check whether a number is prime.
 * @version 0.1
 * @date 2026-09-13
 *
 * @copyright Copyright (c) 2016-2026
 */

#include <iostream>

/**
 * @brief Checks whether a number is prime using brute force.
 *
 * Tests every integer from 2 through n - 1 as a possible divisor.
 *
 * @param n The number to check.
 * @return true If n is prime.
 * @return false If n is not prime.
 */
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Main entry point for the prime-number checker.
 *
 * @return int Exit status code.
 */
int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " is prime.\n";
    } else {
        std::cout << number << " is not prime.\n";
    }

    return 0;
}