#include <iostream>

/**
 * @class Solution
 * @brief Provides a method to compute minimum flips required to make (a OR b) == c.
 */
class Solution {
public:
    /**
     * @brief Calculates the minimum number of bit flips to make (a OR b) equal to c.
     *
     * This function checks each bit position of a, b, and c.
     * - If c's bit is 1, at least one of a or b must have a 1. If both are 0, one flip is needed.
     * - If c's bit is 0, both a and b must be 0. If either is 1, each 1 needs one flip to 0.
     *
     * @param a First integer operand.
     * @param b Second integer operand.
     * @param c Target result of a OR b.
     * @return int The minimum number of flips required.
     */
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a || b || c) {
            if (c & 1) {
                if ((a & 1) == 0 && (b & 1) == 0)
                    flips++;
            }
            else {
                if (a & 1)
                    flips++;
                if (b & 1)
                    flips++;
            }
            a >>= 1, b >>= 1, c >>= 1;
        }
        return flips;
    }
};

/**
 * @brief Entry point to test the minFlips function.
 * 
 * Runs several test cases and prints the result to the console.
 * 
 * @return int Exit code.
 */
int main() {
    Solution solution;

    // Test case 1
    int a1 = 2, b1 = 6, c1 = 5;
    std::cout << "Input: a = " << a1 << ", b = " << b1 << ", c = " << c1 << std::endl;
    int flips1 = solution.minFlips(a1, b1, c1);
    std::cout << "Output: " << flips1 << std::endl;

    // Test case 2
    int a2 = 4, b2 = 2, c2 = 7;
    std::cout << "\nInput: a = " << a2 << ", b = " << b2 << ", c = " << c2 << std::endl;
    int flips2 = solution.minFlips(a2, b2, c2);
    std::cout << "Output: " << flips2 << std::endl;

    // Test case 3
    int a3 = 1, b3 = 2, c3 = 3;
    std::cout << "\nInput: a = " << a3 << ", b = " << b3 << ", c = " << c3 << std::endl;
    int flips3 = solution.minFlips(a3, b3, c3);
    std::cout << "Output: " << flips3 << std::endl;

    system("pause");
    return 0;
}