# Power of Two (and Related Powers) — Bit Manipulation Explained
This document explains multiple ways to determine whether a number is a power of two, along with related extensions (power of three, four, and k).  
The goal is not just correctness, but **understanding why the solution works**.

## Recursive version
While the recursive version is elegant, it’s not ideal for production or competitive programming due to stack overhead.

```
// Note: Recursive version may cause stack overflow for large n.

```

```C++ []
bool isPowerOfTwo(int n) {
    if (n <= 0) 
        return false;      
    if (n == 1) 
        return true;       
    if (n % 2 != 0) 
        return false;      
    return isPowerOfTwo(n / 2); 
}
```

## Iterative (and more efficient) alternative
```C++ []
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

## Powers of two in binary
A power of two is:
```
1, 2, 4, 8, 16, 32, ...
```

In binary, these look like:
```
1     -> 0001
2     -> 0010
4     -> 0100
8     -> 1000
16    -> 1 0000
```
Did you Notice the pattern?
- Every power of two has exactly one 1 bit and all the rest are 0s.

## What is n - 1 in binary?
Let’s take an example:
**n = 8 (1000 in binary)**
```
n      = 1000
n - 1  = 0111
```
For a power of two:
The single 1 in n becomes 0
All bits to the right of it become 1

## Why (n & (n - 1)) == 0 works
& means bitwise AND → it compares each bit:
1 & 1 → 1
1 & 0 → 0
0 & 1 → 0
0 & 0 → 0
Example 1 — n = 8 (power of two):
```
n      = 1000
n - 1  = 0111
----------------
n & (n-1) = 0000    equals 0
```
Example 2 — n = 6 (NOT a power of two):
```
n      = 0110
n - 1  = 0101
----------------
n & (n-1) = 0100    not 0
```

![SQL_Bootcamp (2).jpg](https://assets.leetcode.com/users/images/250879eb-5d56-481c-bb43-80aad6164617_1759620178.026966.jpeg)

## Final logic
If n is a power of two → (n & (n - 1)) will always be 0
If n is NOT a power of two → result will be non-zero
```C++ []
return n > 0 && (n & (n - 1)) == 0;
```
checks both:
1. n > 0 → rules out negatives and zero
2. (n & (n - 1)) == 0 → ensures exactly one bit is set

### Time and space Complexity
- O(1) time complexity — one bitwise operation and one comparison.
- O(1) space — no recursion or extra data structures.

## Generalized C++ Solution

```C++ []
bool isPowerOfTwo(int n) {
    if (n <= 0) 
        return false;
    while (n % 2 == 0)
        n /= 2;
    return n == 1;
}

bool isPowerOfThree(int n) {
    if (n <= 0) 
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

bool isPowerOfK(int n, int k) {
    if (n <= 0 || k <= 1) 
        return false;
    // k <= 1 is invalid because powers of 0/1 are not meaningful. 
    if (n == 1) return true; // k^0 = 1
    while (n % k == 0)
        n /= k;
    return n == 1;
}

```
## Relation to __builtin_popcount(n)
In GCC and Clang, [__builtin_popcount](https://en.cppreference.com/w/cpp/numeric/popcount.html)(n) is a compiler intrinsic — a built-in function that counts the number of 1s (set bits) in the binary representation of an integer n.

A power of two has exactly one set bit in its binary representation.
```__builtin_popcount(n) == 1```: Confirms only one bit is set.

## Checking for Power of Two
```C++ []
bool isPowerOfTwo(int n) {
    return n > 0 && __builtin_popcount(n) == 1;
}
```
## Extending to Power of Four
To check if a number is a power of four, we need to ensure:

1. It is a power of two (only one bit set).
2. That bit is located at an even position (0-based indexing).

This can be done using a bitmask: 0x55555555 → binary pattern 01010101... (bits set at even positions)

```C++ []
bool isPowerOfFour(int n) {
    return n > 0 && __builtin_popcount(n) == 1 && (n & 0x55555555);
}
```

## Bit Manipulation
```// 0x55555555 = 01010101... in binary (bits set at even positions)```

```C++ []
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}
```

## Precomputed Max Power Trick (for small bases)
For fixed bases like 3 or 5, you can precompute the maximum power that fits in int and check if it divides n.

## Code 
```C++ []
bool isPowerOfThree(int n) {
    const int maxPowerOf3 = 1162261467; // 3^19
    return n > 0 && maxPowerOf3 % n == 0;
}
```

## Bitset-based Check (C++20)
```C++ []
#include <iostream>
#include <bit>

bool isPowerOfTwo(int n) {
    return n > 0 && std::has_single_bit((unsigned int)n);
}

int main() {
    int testVals[] = { -8, -1, 0, 1, 2, 3, 4, 5, 8, 12, 16, 31, 32, 64, 100, 1024 };

    for (int n : testVals) 
        std::cout << n << " -> " << (isPowerOfTwo(n) ? "true" : "false") << std::endl;

    return 0;
}
```
std::has_single_bit (C++20) is literally designed for this check.

# Recursive version
While the recursive version is elegant, it’s not ideal for production or competitive programming due to stack overhead.

```
// Note: Recursive version may cause stack overflow for large n.

```

```C++ []
bool isPowerOfTwo(int n) {
    if (n <= 0) 
        return false;      
    if (n == 1) 
        return true;       
    if (n % 2 != 0) 
        return false;      
    return isPowerOfTwo(n / 2); 
}
```

# Iterative (and more efficient) alternative
```C++ []
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

## Powers of two in binary
A power of two is:
```
1, 2, 4, 8, 16, 32, ...
```

In binary, these look like:
```
1     -> 0001
2     -> 0010
4     -> 0100
8     -> 1000
16    -> 1 0000
```
Did you Notice the pattern?
- Every power of two has exactly one 1 bit and all the rest are 0s.

## What is n - 1 in binary?
Let’s take an example:
**n = 8 (1000 in binary)**
```
n      = 1000
n - 1  = 0111
```
For a power of two:
The single 1 in n becomes 0
All bits to the right of it become 1

## Why (n & (n - 1)) == 0 works
& means bitwise AND → it compares each bit:
1 & 1 → 1
1 & 0 → 0
0 & 1 → 0
0 & 0 → 0
Example 1 — n = 8 (power of two):
```
n      = 1000
n - 1  = 0111
----------------
n & (n-1) = 0000    equals 0
```
Example 2 — n = 6 (NOT a power of two):
```
n      = 0110
n - 1  = 0101
----------------
n & (n-1) = 0100    not 0
```

![SQL_Bootcamp (2).jpg](https://assets.leetcode.com/users/images/250879eb-5d56-481c-bb43-80aad6164617_1759620178.026966.jpeg)

## Final logic
If n is a power of two → (n & (n - 1)) will always be 0
If n is NOT a power of two → result will be non-zero
```C++ []
return n > 0 && (n & (n - 1)) == 0;
```
checks both:
1. n > 0 → rules out negatives and zero
2. (n & (n - 1)) == 0 → ensures exactly one bit is set

## Time and space Complexity
- O(1) time complexity — one bitwise operation and one comparison.
- O(1) space — no recursion or extra data structures.

## Generalized C++ Solution

```C++ []
bool isPowerOfTwo(int n) {
    if (n <= 0) 
        return false;
    while (n % 2 == 0)
        n /= 2;
    return n == 1;
}

bool isPowerOfThree(int n) {
    if (n <= 0) 
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

bool isPowerOfK(int n, int k) {
    if (n <= 0 || k <= 1) 
        return false;
    // k <= 1 is invalid because powers of 0/1 are not meaningful. 
    if (n == 1) return true; // k^0 = 1
    while (n % k == 0)
        n /= k;
    return n == 1;
}

```
## Relation to __builtin_popcount(n)
In GCC and Clang, [__builtin_popcount](https://en.cppreference.com/w/cpp/numeric/popcount.html)(n) is a compiler intrinsic — a built-in function that counts the number of 1s (set bits) in the binary representation of an integer n.

A power of two has exactly one set bit in its binary representation.
```__builtin_popcount(n) == 1```: Confirms only one bit is set.

## Checking for Power of Two
```C++ []
bool isPowerOfTwo(int n) {
    return n > 0 && __builtin_popcount(n) == 1;
}
```
## Power of Four — Bitmask Approach
To check if a number is a power of four, we need to ensure:

1. It is a power of two (only one bit set).
2. That bit is located at an even position (0-based indexing).

This can be done using a bitmask: 0x55555555 → binary pattern 01010101... (bits set at even positions)

```C++ []
bool isPowerOfFour(int n) {
    return n > 0 && __builtin_popcount(n) == 1 && (n & 0x55555555);
}
```

## Bit Manipulation
```// 0x55555555 = 01010101... in binary (bits set at even positions)```

```C++ []
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}
```

## Precomputed Max Power Trick (for small bases)
For fixed bases like 3 or 5, you can precompute the maximum power that fits in int and check if it divides n.

## Code 
```C++ []
bool isPowerOfThree(int n) {
    const int maxPowerOf3 = 1162261467; // 3^19
    return n > 0 && maxPowerOf3 % n == 0;
}
```

## Bitset-based Check (C++20)
```C++ []
#include <iostream>
#include <bit>

bool isPowerOfTwo(int n) {
    return n > 0 && std::has_single_bit((unsigned int)n);
}

int main() {
    int testVals[] = { -8, -1, 0, 1, 2, 3, 4, 5, 8, 12, 16, 31, 32, 64, 100, 1024 };

    for (int n : testVals) 
        std::cout << n << " -> " << (isPowerOfTwo(n) ? "true" : "false") << std::endl;

    return 0;
}
```
std::has_single_bit (C++20) is literally designed for this check.

## Recommended in Production
- Prefer `std::has_single_bit` (C++20+)
- Use `(n & (n - 1)) == 0` for pre-C++20 codebases
- Avoid recursion for this check

## Summary

| Approach               | Time Complexity | Space Complexity | Notes                    |
|------------------------|-----------------|------------------|--------------------------|
| Recursion              | O(log n)        | O(log n)         | Not production-safe      |
| Division Loop          | O(log n)        | O(1)             | Simple but slower        |
| Bitwise AND            | O(1)            | O(1)             | Most common approach     |
| `__builtin_popcount`   | O(1)            | O(1)             | Compiler-specific        |
| `std::has_single_bit`  | O(1)            | O(1)             | Best (C++20+)            |

## Key Takeaway
`A number is a power of two if and only if it has exactly one set bit.`
<bk> 
Understanding why this works matters more than memorizing the formula.
