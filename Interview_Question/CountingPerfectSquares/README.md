# Counting Perfect Squares Between Two Integers

## Problem Statement

Given two integers `a` and `b`, we need to count the number of perfect squares between these two integers, inclusive. A perfect square is an integer that is the square of an integer (e.g., 1, 4, 9, 16, etc.).

## Approach

To solve this problem efficiently, we can leverage the mathematical properties of perfect squares. Instead of iterating through every integer between `a` and `b` to check if it is a perfect square, we can directly find the range of integers whose squares fall between `a` and `b`.

### Steps

1. **Calculate the Start and End Points**:
    - Find the smallest integer `start` such that \(start^2 \geq a\). This can be done using the ceiling of the square root of `a`.
    - Find the largest integer `end` such that \(end^2 \leq b\). This can be done using the floor of the square root of `b`.

2. **Count the Perfect Squares**:
    - The number of perfect squares between `a` and `b` is the count of integers from `start` to `end`, inclusive.
    - This can be calculated as `(end - start) + 1`.

3. **Ensure Non-Negative Result**:
    - If `a` is greater than `b`, the result should be zero. This is handled by taking the maximum of `0` and the calculated count.

### Time Complexity

The time complexity of this approach is \(O(1)\) since it involves a constant number of mathematical operations, making it highly efficient.

## Solution

Here is the C++ implementation of the described approach:

```cpp
#include <iostream>
#include <cmath>

// Function to count perfect squares between a and b
int squares(int a, int b) {
    // Calculate the start and end points
    int start = std::ceil(std::sqrt(a));
    int end = std::floor(std::sqrt(b));
    
    // Calculate the number of perfect squares
    int res = (end - start) + 1;
    
    // Ensure the result is non-negative
    return std::max(0, res);
}

int main() {
    int a = 4, b = 16;
    std::cout << "Number of perfect squares between " << a << " and " << b << ": " << squares(a, b) << std::endl;
    return 0;
}
```
To solve the problem of counting perfect squares between two integers a and b without using built-in libraries like <cmath>, we can implement our own versions of sqrt and rounding functions.
```cpp
#include <iostream>

// Function to compute integer square root using binary search
int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;
    int low = 1, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Function to count perfect squares between a and b
int squares(int a, int b) {
    int start = integerSqrt(a);
    if (start * start < a) start++; // simulate ceil(sqrt(a))

    int end = integerSqrt(b); // simulate floor(sqrt(b))

    int res = (end - start) + 1;
    return res > 0 ? res : 0;
}

int main() {
    int a = 4, b = 16;
    std::cout << "Number of perfect squares between " << a << " and " << b << ": " << squares(a, b) << std::endl;
    return 0;
}
```
