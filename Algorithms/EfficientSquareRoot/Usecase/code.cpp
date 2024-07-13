#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid)   // If mid is a potential candidate for the square root
                left = mid + 1;   // Update left to search in the right half
            else
                right = mid;      // Update right to search in the left half
        }

        return left - 1;   // Return the largest integer whose square is less than or equal to x
    }
};

int main() {
    Solution solution;
    int num = 25, result = solution.mySqrt(num);
    cout << "Square root of " << num << " is: " << result << endl;
    return 0;
}
