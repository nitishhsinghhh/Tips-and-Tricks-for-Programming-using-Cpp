#include <vector>

class Solution {
    int findPeakElementUtil(std::vector<int>& nums, int l, int r) {
        if (l > r)
            return -1;

        int m = l + (r - l) / 2;

        if (((m > 0) && (nums[m] > nums[m - 1])) &&
            ((m < nums.size() - 1) && (nums[m] > nums[m + 1])))
            return m;

        if (m == 0 && nums.size() > 1 && nums[m] > nums[m + 1])
            return m;

        if ((m == nums.size() - 1) && nums[m] > nums[m - 1])
            return m;

        int left = findPeakElementUtil(nums, l, m - 1);
        int right = findPeakElementUtil(nums, m + 1, r);

        if (left != -1)
            return left;
        else
            return right;
    }

public:
    int findPeakElement(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        return findPeakElementUtil(nums, 0, n - 1);
    }
};