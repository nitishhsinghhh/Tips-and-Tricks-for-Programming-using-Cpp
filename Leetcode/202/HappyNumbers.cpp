// https://leetcode.com/problems/happy-number/description/

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
    int testCases[] = {19, 7, 82, 68, 23, 44, 86, 91, 76, 39, 100, 33, 56, 8, 70, 14, 69, 95, 47, 13, 30, 98, 71, 50, 93, 80, 27, 59, 16, 84, 36, 60, 88, 67, 21, 79, 75, 51, 94, 62, 35, 48, 64, 12, 87, 40, 83, 52, 90, 74, 99, 18};

    int happyCount = 0;
    int unhappyCount = 0;

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        if (oSolution.isHappy(testCases[i])) {
            happyCount++;
            std::cout << testCases[i] << " is a happy number." << std::endl;
        } else {
            unhappyCount++;
            std::cout << testCases[i] << " is an unhappy number." << std::endl;
        }
    }

    std::cout << "Total happy numbers: " << happyCount << std::endl;
    std::cout << "Total unhappy numbers: " << unhappyCount << std::endl;

    return 0;
}

/*
Output:
19 is a happy number.
7 is a happy number.
82 is a happy number.
68 is a happy number.
23 is a happy number.
44 is a happy number.
86 is a happy number.
91 is a happy number.
76 is an unhappy number.
39 is an unhappy number.
100 is a happy number.
33 is an unhappy number.
56 is an unhappy number.
8 is an unhappy number.
70 is a happy number.
14 is an unhappy number.
69 is an unhappy number.
95 is an unhappy number.
47 is an unhappy number.
13 is a happy number.
30 is an unhappy number.
98 is an unhappy number.
71 is an unhappy number.
50 is an unhappy number.
93 is an unhappy number.
80 is an unhappy number.
27 is an unhappy number.
59 is an unhappy number.
16 is an unhappy number.
84 is an unhappy number.
36 is an unhappy number.
60 is an unhappy number.
88 is an unhappy number.
67 is an unhappy number.
21 is an unhappy number.
79 is a happy number.
75 is an unhappy number.
51 is an unhappy number.
94 is a happy number.
62 is an unhappy number.
35 is an unhappy number.
48 is an unhappy number.
64 is an unhappy number.
12 is an unhappy number.
87 is an unhappy number.
40 is an unhappy number.
83 is an unhappy number.
52 is an unhappy number.
90 is an unhappy number.
74 is an unhappy number.
99 is an unhappy number.
18 is an unhappy number.
Total happy numbers: 13
Total unhappy numbers: 39
*/
