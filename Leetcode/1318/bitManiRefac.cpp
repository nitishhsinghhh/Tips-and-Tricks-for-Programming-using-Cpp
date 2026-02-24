#include <iostream>
#include <memory>
#include <vector>
#include <tuple>
#include <bit> // Required for std::popcount

// Interface for Flip Calculator (ISP, DIP)
class IFlipCalculator {
public:
    virtual int calculateMinFlips(int a, int b, int c) const = 0;
    virtual ~IFlipCalculator() = default;
};

// O(1) Bitwise Implementation utilizing CPU Hardware Intrinsics
class OptimizedFlipCalculator : public IFlipCalculator {
public:
    int calculateMinFlips(int a, int b, int c) const override {
        // Cast to unsigned to prevent implementation-defined behavior with sign-extension
        unsigned int ua = static_cast<unsigned int>(a);
        unsigned int ub = static_cast<unsigned int>(b);
        unsigned int uc = static_cast<unsigned int>(c);

        // Case 1: Where uc bit is 0, but ua or ub have 1s.
        // If both ua and ub have 1s, it requires 2 flips, handled by adding (ua & ub & ~uc).
        unsigned int flipsForZeroTarget = (ua | ub) & ~uc;
        unsigned int doubleFlipsRequired = ua & ub & ~uc;

        // Case 2: Where uc bit is 1, but both ua and ub have 0s.
        unsigned int flipsForOneTarget = ~(ua | ub) & uc;

        // Total up set bits using compiler-optimized hardware instructions for population count (Hamming weight)
        return std::popcount(flipsForZeroTarget) + 
               std::popcount(doubleFlipsRequired) + 
               std::popcount(flipsForOneTarget);
    }
};

// Interface for Test Runner (ISP, DIP)
class ITestRunner {
public:
    virtual void runTests() const = 0;
    virtual ~ITestRunner() = default;
};

// Concrete Test Runner (SRP)
class FlipTestRunner : public ITestRunner {
private:
    std::shared_ptr<IFlipCalculator> calculator;
    std::vector<std::tuple<int, int, int, int>> testCases;

public:
    explicit FlipTestRunner(std::shared_ptr<IFlipCalculator> calc) 
        : calculator(std::move(calc)), 
          testCases({
              {2, 6, 5, 3},
              {4, 2, 7, 1},
              {1, 2, 3, 0}
          }) {}

    void runTests() const override {
        for (const auto& [a, b, c, expected] : testCases) {
            int result = calculator->calculateMinFlips(a, b, c);
            std::cout << "Input: a = " << a << ", b = " << b << ", c = " << c << "\n";
            std::cout << "Expected: " << expected << ", Got: " << result << "\n";
            std::cout << (result == expected ? "Passed" : "Failed") << "\n\n";
        }
    }
};

int main() {
    // Instantiating the O(1) implementation seamlessly via Dependency Injection
    std::shared_ptr<IFlipCalculator> calculator = std::make_shared<OptimizedFlipCalculator>();
    std::shared_ptr<ITestRunner> tester = std::make_shared<FlipTestRunner>(calculator);

    tester->runTests();

    return 0;
}