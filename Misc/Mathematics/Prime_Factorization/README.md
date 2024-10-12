# Mathematical Concepts Behind the Prime Factors Program

This document explains the mathematical concepts used in the program for calculating the prime factors of a number.

## Prime Factors

Prime factors of a number are the prime numbers that divide the number exactly, without leaving a remainder. The process of finding the prime factors involves dividing the number by the smallest possible prime numbers until the number itself becomes a prime.

### Steps to Calculate Prime Factors

1. **Divisibility by 2**:
   - Divide the number by 2 until it is no longer divisible by 2. This handles all the even factors.
2. **Divisibility by 3**:
   - Similarly, divide the number by 3 until it is no longer divisible by 3.
3. **Divisibility by Remaining Primes**:
   - For numbers greater than 3, check divisibility by numbers of the form \(6k \pm 1\) (i.e., 5, 7, 11, 13, ...) up to the square root of the number.
4. **Remaining Prime Factor**:
   - If the remaining number after all divisions is greater than 1, it is a prime factor.

### Implementation in the Program

In the provided code, the `calculatePrimeFactors` method implements the algorithm to find and print the prime factors of a number. Here's a step-by-step explanation of the program:

1. **Class Definition**: The `PrimeFactors` class has a private member `n` to store the number. It also has methods to compute and print the prime factors.
2. **Constructor**: The constructor initializes the number `n`.
3. **Prime Factors Calculation**:
   - **Divisibility by 2**:
     - Divide `n` by 2 until it is no longer divisible by 2, printing each factor.
   - **Divisibility by 3**:
     - Divide `n` by 3 until it is no longer divisible by 3, printing each factor.
   - **Divisibility by Remaining Primes**:
     - For each number `i` from 5 to the square root of `n`, check divisibility by `i` and `i + 2`, printing each factor.
   - **Remaining Prime Factor**:
     - If the remaining `n` is greater than 1, print `n` as it is a prime factor.

4. **Main Function**: The `main` function takes a positive number as input, creates an instance of the `PrimeFactors` class, and calls the `calculatePrimeFactors` method to compute and display the prime factors.

## Example Walkthrough

Let's walk through a couple of examples to see how the program calculates the prime factors:

### Example 1:
- **Input**: `n = 6`
- **Calculation**:
  - Divide by 2: `6 / 2 = 3`, print `2`
  - Divide by 3: `3 / 3 = 1`, print `3`
- **Output**: `2 3`

### Example 2:
- **Input**: `n = 88`
- **Calculation**:
  - Divide by 2: `88 / 2 = 44`, print `2`
  - Divide by 2: `44 / 2 = 22`, print `2`
  - Divide by 2: `22 / 2 = 11`, print `2`
  - Divide by 11: `11 / 11 = 1`, print `11`
- **Output**: `2 2 2 11`

The outputs match the expected results as per the prime factorization algorithm.

## Summary

The program efficiently calculates the prime factors of a number by first dividing by the smallest primes (2 and 3) and then checking divisibility by larger primes up to the square root of the number. The key steps involve repeatedly dividing the number by prime factors and printing each factor until the number itself becomes a prime.

