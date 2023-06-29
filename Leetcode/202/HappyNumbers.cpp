// https://leetcode.com/problems/happy-number/description/

#include <iostream>
#include <vector>
using namespace std;

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

    vector<int> happyNumbers, unhappyNumbers;

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) 
        if (oSolution.isHappy(testCases[i])) 
            happyNumbers.push_back(testCases[i]);
        else 
            unhappyNumbers.push_back(testCases[i]);

    cout << "Total happy numbers: " << happyNumbers.size() << endl;
    cout << "Total unhappy numbers: " << unhappyNumbers.size() << endl;

    cout << "Happy numbers: ";
    for (int i = 0; i < happyNumbers.size(); i++) 
        cout << happyNumbers[i] << " ";
    cout << endl;

    cout << "Unhappy numbers: ";
    for (int i = 0; i < unhappyNumbers.size(); i++)
        cout << unhappyNumbers[i] << " ";
    cout << endl;

    return 0;
}

/*
Output:
Total happy numbers: 13
Total unhappy numbers: 39
Happy numbers: 19 7 82 68 23 44 86 91 100 70 13 79 94 
Unhappy numbers: 76 39 33 56 8 14 69 95 47 30 98 71 50 93 80 27 59 16 84 36 60 88 67 21 75 51 62 35 48 64 12 87 40 83 52 90 74 99 18 
*/
