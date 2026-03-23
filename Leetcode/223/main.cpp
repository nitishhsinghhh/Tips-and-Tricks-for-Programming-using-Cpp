#include <iostream>
#include <cassert>
#include "solution.hpp"
using namespace std;

void runTest(int ax1, int ay1, int ax2, int ay2,
             int bx1, int by1, int bx2, int by2,
             int expected) {
    Solution sol;
    int result = sol.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    cout << "Expected: " << expected << ", Got: " << result << endl;
    assert(result == expected);
}

int main() {
    runTest(-3, 0, 3, 4, 0, -1, 9, 2, 45);
    runTest(-2, -2, 2, 2, -2, -2, 2, 2, 16);
    runTest(-3, 0, -1, 2, 1, 0, 3, 2, 8);
    runTest(0, 0, 4, 4, 2, 2, 6, 6, 28);

    cout << "All tests passed successfully!" << endl;
    return 0;
}