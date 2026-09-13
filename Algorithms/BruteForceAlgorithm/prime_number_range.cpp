/**
 * @file prime_number_range.cpp
 * @author Nitish Singh
 * @brief Brute-force algorithm to find prime numbers in a given range.
 * @version 0.1
 * @date 2026-09-13
 *
 * @copyright Copyright (c) 2016-2026
 */

#include <iostream>

/**
 * @brief Checks whether a number is prime using brute force.
 *
 * Tests every possible divisor from 2 through n - 1.
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
 * @brief Main entry point for finding primes in a range.
 *
 * @return int Exit status code.
 */
int main() {
    int start;
    int end;

    std::cout << "Enter the range (start and end): ";
    std::cin >> start >> end;

    std::cout << "Prime numbers between "
              << start << " and " << end << " are: ";

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}