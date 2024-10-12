#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        } while (slow != fast);

        return slow == 1;
    }

private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    Solution oSolution;
    
    // Test cases
    int testCases[] = {19, 7, 82, 68};

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        std::cout << testCases[i] << " is a"
                  << (oSolution.isHappy(testCases[i]) ? " happy" : "n unhappy")
                  << " number." << std::endl;
    }

    return 0;
}

/*
Output:
19 is a happy number.
7 is a happy number.
82 is a happy number.
68 is a happy number.
*/
