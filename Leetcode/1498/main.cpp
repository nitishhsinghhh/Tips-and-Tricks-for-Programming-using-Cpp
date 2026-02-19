#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;
using std::endl;
using std::cout;

class PowerCalculator {
    const int MOD = 1e9 + 7;
    vector<int> powers;

public:
    PowerCalculator(int size) {
        powers.resize(size, 1);
        for (int i = 1; i < size; ++i)
            powers[i] = (powers[i - 1] * 2) % MOD;
    }

    int getPower(int index) const {
        return powers[index];
    }
};

class SubsequenceCounter {
    const int MOD = 1e9 + 7;

public:
    int countValidSubsequences(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        PowerCalculator powerCalc(n);

        int left = 0, right = n - 1, result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + powerCalc.getPower(right - left)) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        SubsequenceCounter counter;
        return counter.countValidSubsequences(nums, target);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 5, 6, 7};
    int target1 = 9;
    assert(sol.numSubseq(nums1, target1) == 4);

    vector<int> nums2 = {3, 3, 6, 8};
    int target2 = 10;
    assert(sol.numSubseq(nums2, target2) == 6);

    vector<int> nums3 = {2, 3, 3, 4, 6, 7};
    int target3 = 12;
    assert(sol.numSubseq(nums3, target3) == 61);

    cout << "All test cases passed successfully! " << endl;
    return 0;
}