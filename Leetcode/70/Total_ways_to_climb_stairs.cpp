/*
    Leetcode: 70 (Climbing Stairs)
    Problem Link: https://leetcode.com/problems/climbing-stairs/description/
*/

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        // Number of ways to reach the current step by taking one step at a time
        int oneStep = 0;   
        // Number of ways to reach the current step by taking two steps at a time
        int twoStep = 1;   

        // Loop through each step to calculate the number of ways
        for (int i = 0; i < n; i++) {
            // Temporary variable to store the value of twoStep before updating it
            int tmp = twoStep;
            // Upadate twoStep by adding the ways to reach the current step (oneStep+twoStep)
            // As we can reach the current step either by oneStep from the previous step or twoSteps from the two steps back
            twoStep = oneStep + twoStep;

            // Update oneStep to the previous value of twoStep
            oneStep = tmp;
        }

        // The final value of twoStep represents the total number of ways to reach the top
        return twoStep;
    }
};

int main() {
    Solution solution;
    // n is the input of the number of given steps
    int n;
    // Result of total ways to reach the given number of steps
    int ways;
  
    // -----------testcase 1------------ 
    // Finding the number of ways to climb a staircase with 4 steps
    n = 4;
    ways = solution.climbStairs(n);

    // Print the result
    std::cout << "Number of ways to climb " << n << " steps: " << ways << std::endl;
    
    // -----------testcase 2------------ 
    // Finding the number of ways to climb a staircase with 10 steps
    n = 10;
    ways = solution.climbStairs(n);

    // Print the result
    std::cout << "Number of ways to climb " << n << " steps: " << ways << std::endl;
    
    return 0;
}

/*
========================OUTPUT SECTION===================================
[Test Case-1]
Input: n = 2
Output: Number of ways to climb 2 steps: 2
---------------------------------------------
[Test Case-2]
Input: n = 4
Output: Number of ways to climb 4 steps: 5
---------------------------------------------
[Test Case-3]
Input: n = 10
Output: Number of ways to climb 10 steps: 89

==========================================================================
*/
