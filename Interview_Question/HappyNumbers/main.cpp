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
    Solution sol;

    // Test cases
    int test1 = 19;  // true
    int test2 = 2;   // false
    int test3 = 1;   // true
    int test4 = 7;   // true

    std::cout << "19 -> " << sol.isHappy(test1) << std::endl;
    std::cout << "2  -> " << sol.isHappy(test2) << std::endl;
    std::cout << "1  -> " << sol.isHappy(test3) << std::endl;
    std::cout << "7  -> " << sol.isHappy(test4) << std::endl;

    return 0;
}