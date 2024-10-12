# Mathematical Concepts Behind the LCM Program

This document explains the mathematical concepts used in the program for calculating the Least Common Multiple (LCM) of two numbers.

## Least Common Multiple (LCM)

The Least Common Multiple (LCM) of two integers is the smallest positive integer that is divisible by both numbers. The relationship between the LCM and the Greatest Common Divisor (GCD) is fundamental to efficiently calculating the LCM.

### Relationship Between LCM and GCD

The relationship between the LCM and GCD of two numbers \(a\) and \(b\) is given by:
LCM(a, b) * GCD(a, b) = a * b

From this relationship, we can derive the formula for LCM:
LCM(a, b) = (a * b) / GCD(a, b)

### Euclidean Algorithm for GCD

The Euclidean algorithm is an efficient method for computing the GCD of two numbers. The steps of the Euclidean algorithm are as follows:

1. If the two numbers a and b are equal, then GCD(a, b) = a or b.
2. If either a or b is zero, then the GCD is the non-zero number.
3. Otherwise, replace the larger number by its remainder when divided by the smaller number and repeat the process.

Formally, the Euclidean algorithm can be expressed as:
- GCD(a, b) = GCD(b, a % b) if (a > b)
- GCD(a, b) = GCD(a, b % a) if (b > a)

## Implementation in the Program

In the provided code, the `gcd` function implements the Euclidean algorithm recursively. The `calcLCM` function then uses the GCD to compute the LCM. Here's a step-by-step explanation of the program:

1. **Class Definition**: The `LCM` class has private members `a` and `b` to store the two numbers. It also has private methods `gcd` to compute the GCD and `calcLCM` to compute the LCM.
2. **Constructor**: The constructor initializes the numbers `a` and `b`.
3. **LCM Calculation**:
   - **GCD Calculation**:
     - If `a` is zero, return `b`.
     - If `b` is zero, return `a`.
     - If `a` is equal to `b`, return `a` (or `b`).
     - If `a` is greater than `b`, recursively call `gcd(a % b, b)`.
     - If `b` is greater than `a`, recursively call `gcd(a, b % a)`.
   - **LCM Calculation**:
     - Calculate the product of `a` and `b`.
     - Divide the product by the GCD of `a` and `b` to get the LCM.

4. **Main Function**: The `main` function takes two numbers as input, creates an instance of the `LCM` class, and calls the `findLCM` method to compute and display the LCM.

## Example Walkthrough

Let's walk through a couple of examples to see how the program calculates the LCM:

### Example 1:
- **Input**: `a = 12, b = 8`
- **GCD Calculation**:
  - `gcd(12, 8)`
  - Since `12 > 8`, it calls `gcd(12 % 8, 8)` which is `gcd(4, 8)`
  - Since `8 > 4`, it calls `gcd(4, 8 % 4)` which is `gcd(4, 0)`
  - Since one of the numbers is zero, the GCD is `4`
- **LCM Calculation**:
  - \( \text{LCM}(12, 8) = \frac{|12 \times 8|}{4} = \frac{96}{4} = 24 \)
- **Output**: `24`

### Example 2:
- **Input**: `a = 4, b = 5`
- **GCD Calculation**:
  - `gcd(4, 5)`
  - Since `5 > 4`, it calls `gcd(4, 5 % 4)` which is `gcd(4, 1)`
  - Since `4 > 1`, it calls `gcd(4 % 1, 1)` which is `gcd(0, 1)`
  - Since one of the numbers is zero, the GCD is `1`
- **LCM Calculation**:
  - \( \text{LCM}(4, 5) = \frac{|4 \times 5|}{1} = \frac{20}{1} = 20 \)
- **Output**: `20`

The outputs match the expected results as per the Euclidean algorithm and the LCM formula.

## Summary

The program efficiently calculates the LCM of two numbers using the relationship between LCM and GCD. The key steps involve computing the GCD using the Euclidean algorithm and then using the GCD to calculate the LCM as per the formula \( \text{LCM}(a, b) = \frac{|a \times b|}{\text{GCD}(a, b)} \).

