#include <iostream>
#include <vector>
#include <string>

#include "FrequencyMap.hpp"
#include "UnorderedSet.hpp"
#include "SpaceNeighbor.hpp"

void printVector(const std::vector<int>& nums) {
    std::cout << "[";
    for (std::size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i + 1 < nums.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void runTest(
    const std::vector<int>& nums,
    int expected,
    FrequencyMapSolution& freqSolution,
    UnorderedSetSolution& setSolution,
    SpaceNeighborSolution& spaceSolution
) {
    int result1 = freqSolution.repeatedNTimes(nums);
    int result2 = setSolution.repeatedNTimes(nums);
    int result3 = spaceSolution.repeatedNTimes(nums);

    std::cout << "Input: ";
    printVector(nums);
    std::cout << "\nExpected: " << expected << "\n";

    std::cout << "FrequencyMapSolution: " << result1
              << (result1 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "UnorderedSetSolution: " << result2
              << (result2 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "SpaceNeighborSolution: " << result3
              << (result3 == expected ? "  PASS" : "  FAIL") << "\n";

    std::cout << "----------------------------------------\n";
}

int main() {
    FrequencyMapSolution freqSolution;
    UnorderedSetSolution setSolution;
    SpaceNeighborSolution spaceSolution;

    std::vector<std::pair<std::vector<int>, int>> testCases = {
        {{1, 2, 3, 3}, 3},
        {{2, 1, 2, 5, 3, 2}, 2},
        {{5, 1, 5, 2, 5, 3, 5, 4}, 5}
    };

    std::cout << "Testing LeetCode 961: N-Repeated Element in Size 2N Array\n";
    std::cout << "========================================\n";

    for (const auto& testCase : testCases) {
        runTest(testCase.first, testCase.second, freqSolution, setSolution, spaceSolution);
    }

    return 0;
}