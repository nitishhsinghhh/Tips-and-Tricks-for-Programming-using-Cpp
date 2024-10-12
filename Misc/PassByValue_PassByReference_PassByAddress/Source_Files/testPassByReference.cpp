#include "testPassByReference.h"

void testPassByReference::run_tests() {
    passByReference oPassByValue;
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        {{1, 2, 3, 4, 5}, 1},
        {{5, 4, 3, 2, 1}, 1},
        {{10, 20, 30, 40, 50}, 10},
        {{-1, -2, -3, -4, -5}, -5},
        {{100, 200, 300, 400, 500}, 100},
        {{0, 0, 0, 0, 0}, 0},
        {{1}, 1},
        {{2, 2, 2, 2, 2}, 2},
        {{-10, 0, 10, -20, 20}, -20},
        {{1000, 2000, -3000, 4000, 5000}, -3000},
        {{-5, -4, -3, -2, -1}, -5},
        {{2, 3, 1, 5, 4}, 1},
        {{3, 3, 3, 3, 1}, 1},
        {{0, 5, -5, 10, -10}, -10},
        {{INT_MAX, INT_MIN, 0, -1, 1}, INT_MIN}
    };

    for (const auto& test_case : test_cases) {
        const std::vector<int>& vect = test_case.first;
        int expected = test_case.second;
        assert(oPassByValue.smallest_element(vect) == expected);
    }

    std::cout << "Pass by Reference: All test cases passed!" << std::endl;
}
