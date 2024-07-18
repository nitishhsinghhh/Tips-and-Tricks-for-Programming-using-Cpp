# Mathematical Concepts Behind the GCD and LCM Program

This document explains the mathematical concepts used in the program for calculating the Greatest Common Divisor (GCD) and the Least Common Multiple (LCM) of two numbers.

## Greatest Common Divisor (GCD)

The Greatest Common Divisor (GCD) of two integers is the largest integer that divides both numbers without leaving a remainder. The program uses the Euclidean algorithm to calculate the GCD. Here's how the Euclidean algorithm works:

### Euclidean Algorithm

1. If \( b = 0 \), then ({GCD}(a, b) = a \).
2. Otherwise, ({GCD}(a, b) = {GCD}(b, a \% b) \).

This algorithm is based on the principle that the GCD of two numbers also divides their difference. It repetitively replaces the larger number by its remainder when divided by the smaller number until one of the numbers becomes zero.

## Least Common Multiple (LCM)

The Least Common Multiple (LCM) of two integers is the smallest positive integer that is divisible by both numbers. The relationship between GCD and LCM is given by:

[{LCM}(a, b) * {GCD}(a, b) = |a * b|]

From the above relation, we can derive the LCM if we know the GCD:

[{LCM}(a, b) = {|a * b|}/{{GCD}(a, b)]

## Implementation in the Program

The program implements these concepts in the following way:

- **Class `MathInterface`**: This serves as an abstract base class with pure virtual functions `gcd` and `lcm`.
- **Class `LCM`**: This class inherits from `MathInterface` and implements the methods to calculate GCD and LCM:
  - **`calculateGCD` Method**: Implements the Euclidean algorithm.
  - **`calculateLCM` Method**: Uses the GCD to compute the LCM as per the formula mentioned above.

## Example Walkthrough

Let's go through the example provided in the program:

1. **Input**: The user inputs two numbers, 8 and 12.
2. **GCD Calculation**:
    - Initial call: `calculateGCD(8, 12)`
    - Since 8 is not zero, and 12 is not zero, and 8 is less than 12, we calculate `calculateGCD(8, 12 % 8)` which is `calculateGCD(8, 4)`.
    - Next call: `calculateGCD(8, 4)`
    - Since 4 is not zero, we continue with `calculateGCD(4, 8 % 4)` which is `calculateGCD(4, 0)`.
    - Since the second parameter is now zero, the GCD is 4.
3. **LCM Calculation**:
    - Using the GCD found above, the LCM is calculated as:
    - ({LCM}(8, 12) = {|8 * 12|}/{4} = {96}/{4} = 24).

Thus, the output will correctly display:
- GCD of 8 and 12 is: 4
- LCM of 8 and 12 is: 24

