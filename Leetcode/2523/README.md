# Basic Solution: Using isPrime
## Step-by-Step Explanation:
1. **Check if a Number is Prime:**
    - We use the isPrime function to determine if a number is prime.
    - This function checks divisibility from 2 up to the square root of the number.
2. **Find Primes in a Range:**
    - We iterate through each number in the given range.
    - For each number, we use the isPrime function to check if it is prime.
    - If it is prime, we add it to our list of primes.
```cpp 
class Solution {
public:
    /**
     * @brief Checks if a number is a prime.
     * @param number The number to check.
     * @return True if the number is prime, otherwise false.
     */
    bool isPrime(int number) {
        if (number <= 1)
            return false;

        for (int i = 2; i * i <= number; ++i)
            if (number % i == 0)
                return false;
        
        return true;
    }
    /**
     * @brief Finds all prime numbers in a given range.
     * @param start The start of the range.
     * @param end The end of the range.
     * @return A vector containing all the prime numbers in the specified range.
     */
    vector<int> findPrimesInRange(int start, int end) {
        vector<int> primes;
        for (int number = start; number <= end; ++number)
            if (isPrime(number))
                primes.push_back(number);
        
        return primes;
    }
    /**
     * @brief Finds the closest prime numbers in a given range.
     * @param left The left boundary of the range.
     * @param right The right boundary of the range.
     * @return A vector containing the closest prime numbers or [-1, -1] if no such pair exists.
     */
    vector<int> closestPrimes(int left, int right) {
        vector<int> result{-1, -1};
        vector<int> primesInRange = findPrimesInRange(left, right);
        int minimumDifference = INT_MAX;

        for (int i = 1; i < primesInRange.size(); ++i) {
            int difference = primesInRange[i] - primesInRange[i - 1];
            if (difference < minimumDifference) {
                minimumDifference = difference;
                result[0] = primesInRange[i - 1];
                result[1] = primesInRange[i];
            }
        } 
        return result;
    }
};
```
# Optimized Solution: Using Sieve of Eratosthenes
## Step-by-Step Explanation:
1. **Mark Non-Prime Numbers:**
    - We use the Sieve of Eratosthenes algorithm to mark non-prime numbers in a boolean array.
    - This algorithm iterates through each number starting from 2 and marks its multiples as non-prime.
2. **Collect Primes in a Range:**
    - After marking non-prime numbers, we collect all numbers that are still marked as prime within the given range.
3. **Find Closest Primes:**
    - We iterate through the list of primes to find the closest pair by checking the difference between consecutive primes.
```cpp 
class Solution {
public:
    /**
     * @brief Finds all prime numbers in a given range using the Sieve of Eratosthenes.
     * @param start The start of the range.
     * @param end The end of the range.
     * @return A vector containing all the prime numbers in the specified range.
     */
    vector<int> sieveOfEratosthenes(int start, int end) {
        vector<bool> isPrime(end + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= end; ++i)  
            if (isPrime[i])  
                for (int j = i * i; j <= end; j += i)  
                    isPrime[j] = false; 

        vector<int> primes;
        for (int i = max(start, 2); i <= end; ++i) 
            if (isPrime[i])  
                primes.push_back(i);
             
        return primes;
    }
    /**
     * @brief Finds the closest prime numbers in a given range.
     * @param left The left boundary of the range.
     * @param right The right boundary of the range.
     * @return A vector containing the closest prime numbers or [-1, -1] if no such pair exists.
     */
    vector<int> closestPrimes(int left, int right) {
        vector<int> primesInRange = sieveOfEratosthenes(left, right);
        vector<int> result{-1, -1};
        int minimumDifference = INT_MAX;

        for (int i = 1; i < primesInRange.size(); ++i) {
            int difference = primesInRange[i] - primesInRange[i - 1];
            if (difference < minimumDifference) {
                minimumDifference = difference;
                result[0] = primesInRange[i - 1];
                result[1] = primesInRange[i];
            }
        }
        return result;
    }
};
```
# Refactored code
1. **Interface Segregation:** The PrimeFinder interface allows for different implementations of prime-finding algorithms.
2. **Modularity:** The code is modular, making it easy to extend or modify individual components.
3. **Testing:** The ClosestPrimesFinderTest class provides a way to validate the functionality, ensuring reliability.
4. **Efficiency:** The use of the Sieve of Eratosthenes in SievePrimeFinder ensures efficient prime number generation for large ranges.

```cpp 
// GCC 13.1 (C++23)
#include <iostream>
#include <vector>
#include <limits.h>
#include <cassert>

/**
 * @interface PrimeFinder
 * @brief Interface for finding prime numbers in a given range.
 */
class PrimeFinder {
public:
    /**
     * @brief Virtual destructor for PrimeFinder.
     */
    virtual ~PrimeFinder() = default;

    /**
     * @brief Finds all prime numbers in the specified range.
     * @param start The start of the range.
     * @param end The end of the range.
     * @return A vector containing all the prime numbers in the specified range.
     */
    virtual std::vector<int> findPrimesInRange(int start, int end) = 0;
};
/**
 * @class SievePrimeFinder
 * @brief Concrete implementation of PrimeFinder using the Sieve of Eratosthenes algorithm.
 */
class SievePrimeFinder : public PrimeFinder {
public:
    /**
     * @brief Finds all prime numbers in the specified range using the Sieve of Eratosthenes.
     * @param start The start of the range.
     * @param end The end of the range.
     * @return A vector containing all the prime numbers in the specified range.
     */
    std::vector<int> findPrimesInRange(int start, int end) override {
        std::vector<bool> isPrime(end + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= end; ++i)  
            if (isPrime[i])  
                for (int j = i * i; j <= end; j += i)  
                    isPrime[j] = false; 

        std::vector<int> primes;
        for (int i = std::max(start, 2); i <= end; ++i) 
            if (isPrime[i])  
                primes.push_back(i);

        return primes;
    }
};
/**
 * @class ClosestPrimesFinder
 * @brief Class for finding the closest prime numbers in a given range.
 */
class ClosestPrimesFinder {
private:
    PrimeFinder* primeFinder;

public:
    /**
     * @brief Constructor for ClosestPrimesFinder.
     * @param pf A pointer to an implementation of the PrimeFinder interface.
     */
    ClosestPrimesFinder(PrimeFinder* pf) : primeFinder(pf) {}

    /**
     * @brief Finds the closest prime numbers in the specified range.
     * @param left The left boundary of the range.
     * @param right The right boundary of the range.
     * @return A vector containing the closest prime numbers or [-1, -1] if no such pair exists.
     */
    std::vector<int> findClosestPrimes(int left, int right) {
        std::vector<int> primesInRange = primeFinder->findPrimesInRange(left, right);

        std::vector<int> result{-1, -1};
        int minimumDifference = INT_MAX;

        for (std::vector<int>::size_type i = 1; i < primesInRange.size(); ++i) {
            int difference = primesInRange[i] - primesInRange[i - 1];
            if (difference < minimumDifference || 
                (difference == minimumDifference && primesInRange[i - 1] < result[0])) {
                minimumDifference = difference;
                result[0] = primesInRange[i - 1];
                result[1] = primesInRange[i];
            }
        }

        return result;
    }
};
/**
 * @class ClosestPrimesFinderTest
 * @brief Class for testing the ClosestPrimesFinder functionality.
 */
class ClosestPrimesFinderTest {
public:
    /**
     * @brief Runs all test cases for ClosestPrimesFinder.
     */
    static void runTests() {
        PrimeFinder* primeFinder = new SievePrimeFinder();
        ClosestPrimesFinder closestPrimesFinder(primeFinder);

        // Test Case 1: Example 1
        std::vector<int> result = closestPrimesFinder.findClosestPrimes(10, 19);
        assert(result[0] == 11 && result[1] == 13);
        std::cout << "Test Case 1 Passed!" << std::endl;

        // Test Case 2: Example 2
        result = closestPrimesFinder.findClosestPrimes(4, 6);
        assert(result[0] == -1 && result[1] == -1);
        std::cout << "Test Case 2 Passed!" << std::endl;

        delete primeFinder;
    }
};

int main() {
    ClosestPrimesFinderTest::runTests();
    return 0;
}
```
# Unified Table: C++ Libraries, Usage, and Application Context

| **Library**     | **Purpose**                                      | **Used In**                  | **Application Context**                                                        | **Test Case Example**             |
|------------------|--------------------------------------------------|-------------------------------|----------------------------------------------------------------------------------|-----------------------------------|
| `<iostream>`     | Input/output operations                          | `std::cout`, `std::endl`      | Displaying test results in `ClosestPrimesFinderTest`                            | `Test Case 1 Passed!`             |
| `<vector>`       | Dynamic array to store primes/results            | `std::vector<int>`            | Storing primes and closest prime pairs in `SievePrimeFinder`, `ClosestPrimesFinder` | `[11, 13]`, `[-1, -1]`            |
| `<limits.h>`     | Provides `INT_MAX` constant                      | `INT_MAX`                     | Used to track the minimum difference between prime pairs                        | `minimumDifference = INT_MAX`     |
| `<cassert>`      | Assertion-based testing                          | `assert()`                    | Validates correctness of output in `ClosestPrimesFinderTest`                    | `assert(result[0] == 11...)`      |
| `<algorithm>` ❌ | *(Not used but should be for `std::max`)*        | `std::max` (implicitly)       | Ensures range starts from at least 2 in `SievePrimeFinder`                      | `std::max(start, 2)`              |
