# Counting Perfect Squares Between Two Integers

## Problem Statement

Given two integers **a** and **b**, we need to count the number of perfect squares between these two integers, inclusive. A perfect square is an integer that is the square of an integer (e.g., 1, 4, 9, 16, etc.).

## Approach

To solve this problem efficiently, we can leverage the mathematical properties of perfect squares. Instead of iterating through every integer between**a** and **b** to check if it is a perfect square, we can directly find the range of integers whose squares fall between **a** and **b**.

### Steps

1. **Calculate the Start and End Points**:
    - Find the smallest integer **start** such that \(start^2 \geq a\). This can be done using the ceiling of the square root of **a**.
    - Find the largest integer **end** such that \(end^2 \leq b\). This can be done using the floor of the square root of **b**.

2. **Count the Perfect Squares**:
    - The number of perfect squares between **a** and **b** is the count of integers from **start** to **end**, inclusive.
    - This can be calculated as `(end - start) + 1`.

3. **Ensure Non-Negative Result**:
    - If **a** is greater than **b** , the result should be zero. This is handled by taking the maximum of `0` and the calculated count.

### Time Complexity

The time complexity of this approach is \(O(1)\) since it involves a constant number of mathematical operations, making it highly efficient.

## Solution

Here is the C++ implementation of the described approach:

```cpp
#include <iostream>
#include <cmath>

/**
 * @brief Counts the number of perfect squares within a given range [a, b].
 *
 * This function finds the first integer whose square is greater than or equal to `a` 
 * and the last integer whose square is less than or equal to `b`. It then computes 
 * how many integers in this range produce perfect squares within [a, b].
 *
 * @param a The lower bound of the range (inclusive).
 * @param b The upper bound of the range (inclusive).
 * @return int The number of perfect squares between a and b.
 */
int squares(int a, int b) {
    // Calculate the first integer whose square is >= a
    int start = std::ceil(std::sqrt(a));

    // Calculate the last integer whose square is <= b
    int end = std::floor(std::sqrt(b));
    
    // Calculate the count of perfect squares in range
    int res = (end - start) + 1;
    
    // Ensure the result is non-negative
    return std::max(0, res);
}

/**
 * @brief Entry point of the program.
 *
 * Demonstrates the use of the squares() function by counting the perfect 
 * squares in the range [4, 16].
 *
 * @return int Exit status code (0 for success).
 */
int main() {
    int a = 4, b = 16;

    std::cout << "Number of perfect squares between "
              << a << " and " << b << ": " << squares(a, b) << std::endl;

    return 0;
}
```
To solve the problem of counting perfect squares between two integers a and b without using built-in libraries like <cmath>, we can implement our own versions of sqrt and rounding functions.
```cpp
#include <iostream>

/**
 * @brief Computes the integer square root of a number using binary search.
 *
 * This function returns the floor value of the square root of `n`.
 * For example:
 * - integerSqrt(10) = 3
 * - integerSqrt(16) = 4
 *
 * @param n The number whose integer square root is to be computed.
 * @return int The largest integer `x` such that `x*x <= n`.
 */
int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;
    int low = 1, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid <= n / mid) { // Avoids overflow compared to (mid * mid <= n)
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

/**
 * @brief Counts the number of perfect squares within a given range [a, b].
 *
 * This function uses integer square root logic to avoid floating-point
 * operations. It adjusts the starting value to simulate ceil(sqrt(a))
 * and the ending value to simulate floor(sqrt(b)).
 *
 * @param a The lower bound of the range (inclusive).
 * @param b The upper bound of the range (inclusive).
 * @return int The number of perfect squares between a and b (inclusive).
 */
int squares(int a, int b) {
    int start = integerSqrt(a);
    if (start * start < a) start++; // Simulate ceil(sqrt(a))

    int end = integerSqrt(b); // Simulate floor(sqrt(b))

    int res = (end - start) + 1;
    return res > 0 ? res : 0;
}

/**
 * @brief Entry point of the program.
 *
 * Demonstrates the usage of the squares() function by counting
 * the perfect squares in the range [4, 16].
 *
 * @return int Exit status code (0 for success).
 */
int main() {
    int a = 4, b = 16;
    std::cout << "Number of perfect squares between "
              << a << " and " << b << ": " << squares(a, b) << std::endl;
    return 0;
}
```

# Refactored Code Using SOLID Principles
```cpp
#include <iostream>
#include <cassert>

/**
 * @brief Interface for square root calculation strategies.
 *
 * This abstract interface defines a method to calculate the integer
 * square root of a given number. Implementations may use different
 * algorithms (e.g., binary search, Newton's method, etc.).
 */
class ISquareRootCalculator {
public:
    /**
     * @brief Calculates the integer square root of a number.
     *
     * @param n The input number (non-negative integer).
     * @return int The largest integer x such that x*x <= n.
     */
    virtual int calculate(int n) const = 0;

    /// Virtual destructor for proper cleanup of derived classes.
    virtual ~ISquareRootCalculator() = default;
};

/**
 * @brief Concrete implementation of ISquareRootCalculator using binary search.
 *
 * This class finds the floor of the square root of an integer using
 * an iterative binary search approach.
 */
class BinarySearchSquareRoot : public ISquareRootCalculator {
public:
    /**
     * @copydoc ISquareRootCalculator::calculate
     */
    int calculate(int n) const override {
        if (n == 0 || n == 1) return n;
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid <= n / mid) { // Avoids overflow
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * @brief Class to count perfect squares within a given range.
 *
 * This class depends on an ISquareRootCalculator instance to compute
 * integer square roots, making it flexible for testing and swapping
 * different algorithms.
 */
class PerfectSquareCounter {
private:
    const ISquareRootCalculator& sqrtCalculator; ///< Square root calculation strategy.

public:
    /**
     * @brief Constructs a PerfectSquareCounter with the given square root calculator.
     * @param calculator Reference to an ISquareRootCalculator instance.
     */
    PerfectSquareCounter(const ISquareRootCalculator& calculator) : sqrtCalculator(calculator) {}

    /**
     * @brief Counts the number of perfect squares between a and b (inclusive).
     *
     * @param a The lower bound of the range (inclusive).
     * @param b The upper bound of the range (inclusive).
     * @return int The count of perfect squares in the range.
     */
    int count(int a, int b) const {
        int start = sqrtCalculator.calculate(a);
        if (start * start < a) start++; // Simulate ceil(sqrt(a))

        int end = sqrtCalculator.calculate(b); // floor(sqrt(b))

        int res = (end - start) + 1;
        return res > 0 ? res : 0;
    }
};

/**
 * @brief Unit test suite for PerfectSquareCounter.
 *
 * Contains multiple test cases using a mock square root calculator
 * to verify correctness without depending on actual sqrt implementation.
 */
class PerfectSquareCounterTests {
public:
    /**
     * @brief Runs all unit tests for PerfectSquareCounter.
     */
    void runAllTests() {
        testCountInRange();
        testNoPerfectSquares();
        testSinglePerfectSquare();
        testEdgeCases();
        std::cout << "✅ All unit tests passed!" << std::endl;
    }

private:
    /**
     * @brief Mock implementation of ISquareRootCalculator for controlled testing.
     */
    class MockSquareRootCalculator : public ISquareRootCalculator {
    public:
        int calculate(int n) const override {
            // Simple deterministic mock logic
            if (n == 4) return 2;
            if (n == 16) return 4;
            if (n == 5) return 2;
            if (n == 15) return 3;
            if (n == 1) return 1;
            if (n == 2 || n == 3) return 1;
            return 0;
        }
    };

    /// Tests counting perfect squares within a range containing multiple squares.
    void testCountInRange() {
        MockSquareRootCalculator mock;
        PerfectSquareCounter counter(mock);
        assert(counter.count(4, 16) == 3); // 4, 9, 16
    }

    /// Tests range containing no perfect squares.
    void testNoPerfectSquares() {
        MockSquareRootCalculator mock;
        PerfectSquareCounter counter(mock);
        assert(counter.count(2, 3) == 0);
    }

    /// Tests a range containing exactly one perfect square.
    void testSinglePerfectSquare() {
        MockSquareRootCalculator mock;
        PerfectSquareCounter counter(mock);
        assert(counter.count(1, 1) == 1);
    }

    /// Tests edge case ranges with only one square inside.
    void testEdgeCases() {
        MockSquareRootCalculator mock;
        PerfectSquareCounter counter(mock);
        assert(counter.count(5, 15) == 1); // 9
    }
};

/**
 * @brief Entry point of the program.
 *
 * Demonstrates the PerfectSquareCounter with a binary search
 * square root calculator and runs unit tests.
 *
 * @return int Exit code (0 for success).
 */
int main() {
    BinarySearchSquareRoot sqrtCalc;
    PerfectSquareCounter counter(sqrtCalc);

    int a = 4, b = 16;
    std::cout << "Number of perfect squares between "
              << a << " and " << b << ": "
              << counter.count(a, b) << std::endl;

    // Run unit tests
    PerfectSquareCounterTests tests;
    tests.runAllTests();

    return 0;
}
```
To incorporate smart pointers into your C++ code, we’ll use std::unique_ptr from the <memory> header. This ensures proper memory management and avoids manual delete calls, aligning with modern C++ best practices.

```cpp
#include <iostream>
#include <cassert>
#include <memory> // For smart pointers

// Interface for square root calculation
class ISquareRootCalculator {
public:
    virtual int calculate(int n) const = 0;
    virtual ~ISquareRootCalculator() = default;
};

// Concrete implementation using binary search
class BinarySearchSquareRoot : public ISquareRootCalculator {
public:
    int calculate(int n) const override {
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
};

// Class to count perfect squares
class PerfectSquareCounter {
private:
    std::unique_ptr<ISquareRootCalculator> sqrtCalculator;

public:
    PerfectSquareCounter(std::unique_ptr<ISquareRootCalculator> calculator)
        : sqrtCalculator(std::move(calculator)) {}

    int count(int a, int b) const {
        int start = sqrtCalculator->calculate(a);
        if (start * start < a) start++;

        int end = sqrtCalculator->calculate(b);
        int res = (end - start) + 1;
        return res > 0 ? res : 0;
    }
};

// Unit test class
class PerfectSquareCounterTests {
public:
    void runAllTests() {
        testCountInRange();
        testNoPerfectSquares();
        testSinglePerfectSquare();
        testEdgeCases();
        std::cout << "✅ All unit tests passed!" << std::endl;
    }

private:
    class MockSquareRootCalculator : public ISquareRootCalculator {
    public:
        int calculate(int n) const override {
            if (n == 4) return 2;
            if (n == 16) return 4;
            if (n == 5) return 2;
            if (n == 15) return 3;
            if (n == 1) return 1;
            if (n == 2 || n == 3) return 1;
            return 0;
        }
    };

    void testCountInRange() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(4, 16) == 3); // 4, 9, 16
    }

    void testNoPerfectSquares() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(2, 3) == 0); // none
    }

    void testSinglePerfectSquare() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(1, 1) == 1); // only 1
    }

    void testEdgeCases() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(5, 15) == 1); // only 9
    }
};

// Main function
int main() {
    auto sqrtCalc = std::make_unique<BinarySearchSquareRoot>();
    PerfectSquareCounter counter(std::move(sqrtCalc));

    int a = 4, b = 16;
    std::cout << "Number of perfect squares between " << a << " and " << b << ": "
              << counter.count(a, b) << std::endl;

    PerfectSquareCounterTests tests;
    tests.runAllTests();

    return 0;
}
```

Here is the complete modern C++ code, applying the following modern C++ principles:

- Interface-based design
- Smart pointers (std::unique_ptr)
- override, final, [[nodiscard]], noexcept
- Unit test class

```cpp
#include <iostream>
#include <cassert>
#include <memory>

// Interface for square root calculation
class ISquareRootCalculator {
public:
    [[nodiscard]] virtual int calculate(int n) const noexcept = 0;
    virtual ~ISquareRootCalculator() = default;
};

// Concrete implementation using binary search
class BinarySearchSquareRoot final : public ISquareRootCalculator {
public:
    [[nodiscard]] int calculate(int n) const noexcept override {
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
};

// Class to count perfect squares
class PerfectSquareCounter final {
private:
    std::unique_ptr<ISquareRootCalculator> sqrtCalculator;

public:
    explicit PerfectSquareCounter(std::unique_ptr<ISquareRootCalculator> calculator)
        : sqrtCalculator(std::move(calculator)) {}

    [[nodiscard]] int count(int a, int b) const noexcept {
        int start = sqrtCalculator->calculate(a);
        if (start * start < a) start++;

        int end = sqrtCalculator->calculate(b);
        int res = (end - start) + 1;
        return res > 0 ? res : 0;
    }
};

// Unit test class
class PerfectSquareCounterTests final {
public:
    void runAllTests() {
        testCountInRange();
        testNoPerfectSquares();
        testSinglePerfectSquare();
        testEdgeCases();
        std::cout << "✅ All unit tests passed!" << std::endl;
    }

private:
    class MockSquareRootCalculator final : public ISquareRootCalculator {
    public:
        [[nodiscard]] int calculate(int n) const noexcept override {
            if (n == 4) return 2;
            if (n == 16) return 4;
            if (n == 5) return 2;
            if (n == 15) return 3;
            if (n == 1) return 1;
            if (n == 2 || n == 3) return 1;
            return 0;
        }
    };

    void testCountInRange() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(4, 16) == 3); // 4, 9, 16
    }

    void testNoPerfectSquares() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(2, 3) == 0); // none
    }

    void testSinglePerfectSquare() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(1, 1) == 1); // only 1
    }

    void testEdgeCases() {
        auto mock = std::make_unique<MockSquareRootCalculator>();
        PerfectSquareCounter counter(std::move(mock));
        assert(counter.count(5, 15) == 1); // only 9
    }
};

// Main function
int main() {
    auto sqrtCalc = std::make_unique<BinarySearchSquareRoot>();
    PerfectSquareCounter counter(std::move(sqrtCalc));

    int a = 4, b = 16;
    std::cout << "Number of perfect squares between " << a << " and " << b << ": "
              << counter.count(a, b) << std::endl;

    PerfectSquareCounterTests tests;
    tests.runAllTests();

    return 0;
}
```

 ## Use override and final consistently

Why Use final and override Consistently?
- **override**
Ensures that a method is actually overriding a virtual method from the base class.
Helps catch bugs at compile time if the base method signature changes or is misspelled.
**Use override on all overridden methods in derived classes.**

- **final**
Prevents further inheritance or overriding.
Signals that a class or method is not intended to be extended.

- Use final when:
You want to lock down a class (e.g., BinarySearchSquareRoot) because it has no reason to be subclassed.
You want to prevent overriding of a method in derived classes.

## Use const & noexcept

- When to Use const
1. Member Functions
Use const when a member function does not modify the object’s state.
```cpp
int calculate(int n) const; // Good: doesn't modify any member variables
```
2. Function Parameters
Use const for:
    - Pointers or references to objects that shouldn't be modified.
    - Large objects passed by reference to avoid copying.
    ```cpp
    void process(const std::string& name); // avoids copying and protects input
    ```

- When to Use noexcept
Use noexcept when a function is **guaranteed not to throw exceptions**. This:

- Helps the compiler optimize
- Improves code clarity
- Enables better exception safety guarantees
```cpp
int calculate(int n) const noexcept; // Safe: no exceptions thrown
```

