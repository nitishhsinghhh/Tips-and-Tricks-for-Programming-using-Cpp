# Mathematical Concepts Behind the GCD Program

This document explains the mathematical concepts used in the program for calculating the Greatest Common Divisor (GCD) of two numbers.

## Greatest Common Divisor (GCD)

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both numbers without leaving a remainder. There are several algorithms to compute the GCD, and the program uses a variant of the **Euclidean algorithm**.

### Euclidean Algorithm

The Euclidean algorithm is an efficient method for computing the GCD of two numbers. It is based on the principle that the GCD of two numbers also divides their difference. The steps of the Euclidean algorithm are as follows:

1. If the two numbers n and m are equal, then GCD(n, m) = n or m.
2. If either n or m is zero, then the GCD is the non-zero number.
3. Otherwise, replace the larger number by its remainder when divided by the smaller number and repeat the process.

Formally, the Euclidean algorithm can be expressed as:
- GCD(n, m) = GCD(m, n % m)) if (n > m)
- GCD(n, m) = GCD(n, m % n) if (m > n)

## Implementation in the Program

In the provided code, the `calcGCD` function implements the Euclidean algorithm recursively. Here's a step-by-step explanation of the program:

1. **Class Definition**: The `GCD` class has private members `n` and `m` to store the two numbers. It also has a private method `calcGCD` to compute the GCD and a public method `findGCD` to display the result.
2. **Constructor**: The constructor initializes the numbers `n` and `m`.
3. **GCD Calculation**:
   - **Base Cases**:
     - If `n` is equal to `m`, the function returns `n` (or `m`).
     - If either `n` or `m` is zero, the function returns the non-zero number.
   - **Recursive Case**:
     - If `n` is greater than `m`, the function calls itself with the remainder of `n` divided by `m` and `m`.
     - If `m` is greater than `n`, the function calls itself with the remainder of `m` divided by `n` and `n`.

4. **Main Function**: The `main` function takes two numbers as input, creates an instance of the `GCD` class, and calls the `findGCD` method to compute and display the GCD.

## Example Walkthrough

Let's walk through a couple of examples to see how the program calculates the GCD:

### Example 1:
- **Input**: `a = 5, b = 4`
- **Calculation**:
  - `calcGCD(5, 4)`
  - Since `5 > 4`, it calls `calcGCD(5 % 4, 4)` which is `calcGCD(1, 4)`
  - Since `4 > 1`, it calls `calcGCD(4 % 1, 1)` which is `calcGCD(0, 1)`
  - Since one of the numbers is zero, the GCD is `1`
- **Output**: `1`

### Example 2:
- **Input**: `a = 7, b = 35`
- **Calculation**:
  - `calcGCD(7, 35)`
  - Since `35 > 7`, it calls `calcGCD(35 % 7, 7)` which is `calcGCD(0, 7)`
  - Since one of the numbers is zero, the GCD is `7`
- **Output**: `7`

The outputs match the expected results as per the Euclidean algorithm.

## Summary

The program efficiently calculates the GCD of two numbers using the Euclidean algorithm, which is a well-known method for this purpose. The key steps involve repeatedly replacing the larger number with the remainder of its division by the smaller number until one of the numbers becomes zero, at which point the non-zero number is the GCD.
