#include <iostream>
#include <vector>
#include <tuple>

#include "RecursiveSubtraction.hpp"
#include "IterativeWhileLoop.hpp"
#include "OptimizedModulo.hpp"

void runTest(
    int num1,
    int num2,
    int expected,
    RecursiveSubtractionSolution& recursiveSolution,
    IterativeWhileLoopSolution& iterativeSolution,
    OptimizedModuloSolution& optimizedSolution
) {
    int result1 = recursiveSolution.countOperations(num1, num2);
    int result2 = iterativeSolution.countOperations(num1, num2);
    int result3 = optimizedSolution.countOperations(num1, num2);

    std::cout << "Input: num1 = " << num1 << ", num2 = " << num2 << "\n";
    std::cout << "Expected: " << expected << "\n";

    std::cout << "RecursiveSubtractionSolution: " << result1
              << (result1 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "IterativeWhileLoopSolution: " << result2
              << (result2 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "OptimizedModuloSolution: " << result3
              << (result3 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "----------------------------------------\n";
}

int main() {
    RecursiveSubtractionSolution recursiveSolution;
    IterativeWhileLoopSolution iterativeSolution;
    OptimizedModuloSolution optimizedSolution;

    std::vector<std::tuple<int, int, int>> testCases = {
        {2, 3, 3},
        {10, 10, 1},
        {0, 5, 0},
        {5, 0, 0},
        {1, 1, 1},
        {100, 1, 100}
    };

    std::cout << "Testing LeetCode 2169: Count Operations to Obtain Zero\n";
    std::cout << "======================================================\n";

    for (const auto& [num1, num2, expected] : testCases) {
        runTest(num1, num2, expected, recursiveSolution, iterativeSolution, optimizedSolution);
    }

    return 0;
}