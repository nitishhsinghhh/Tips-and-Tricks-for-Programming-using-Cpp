#include <iostream>
#include <string>
#include <vector>

#include "IncrementalSummation.hpp"
#include "FormulaBlock.hpp"

void runTest(
    const std::string& s,
    int expected,
    IncrementalSummationSolution& incrementalSolution,
    FormulaBlockSolution& formulaSolution
) {
    int result1 = incrementalSolution.numSub(s);
    int result2 = formulaSolution.numSub(s);

    std::cout << "Input: \"" << s << "\"\n";
    std::cout << "Expected: " << expected << "\n";

    std::cout << "IncrementalSummationSolution: " << result1
              << (result1 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "FormulaBlockSolution: " << result2
              << (result2 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "----------------------------------------\n";
}

int main() {
    IncrementalSummationSolution incrementalSolution;
    FormulaBlockSolution formulaSolution;

    std::vector<std::pair<std::string, int>> testCases = {
        {"0110111", 9},
        {"101", 2},
        {"111111", 21}
    };

    std::cout << "Testing LeetCode 1513: Number of Substrings With Only 1s\n";
    std::cout << "========================================================\n";

    for (const auto& testCase : testCases) {
        runTest(testCase.first, testCase.second, incrementalSolution, formulaSolution);
    }

    return 0;
}