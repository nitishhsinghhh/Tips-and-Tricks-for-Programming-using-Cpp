/**
 * @file solution.hpp
 * @brief Solution for LeetCode 1390 - Four Divisors.
 *
 * This file contains the implementation of the Solution class used to compute
 * the sum of divisors for numbers that have exactly four divisors.
 */

#include <vector>
#include <cmath>

/**
 * @class Solution
 * @brief Provides a method to solve the Four Divisors problem.
 */
class Solution {
public:
    /**
     * @brief Returns the total sum of divisors for numbers with exactly four divisors.
     *
     * A number has exactly four divisors only in these two cases:
     * - It is of the form p^3, where p is prime.
     * - It is of the form p * q, where p and q are distinct primes.
     *
     * @param nums A reference to the input vector of integers.
     * @return The sum of divisors of all integers in the array that have exactly four divisors.
     */
    int sumFourDivisors(std::vector<int>& nums) {
        int total = 0;

        for (int n : nums) {
            // Case 1: n = p^3
            int p = round(cbrt(n));
            if ((long long)p * p * p == n && isPrime(p)) {
                total += 1 + p + p * p + n;
                continue;
            }

            // Case 2: n = p * q
            for (int i = 2; (long long)i * i <= n; ++i) {
                if (n % i == 0) {
                    int j = n / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        total += 1 + i + j + n;
                    }
                    break;
                }
            }
        }

        return total;
    }

private:
    /**
     * @brief Checks whether a number is prime.
     *
     * @param x The number to check.
     * @return true if the number is prime, otherwise false.
     */
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }

        for (int i = 2; (long long)i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    }
};