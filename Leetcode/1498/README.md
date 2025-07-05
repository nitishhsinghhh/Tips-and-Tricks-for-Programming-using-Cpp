# Number of Subsequences That Satisfy the Given Sum Condition

# Topics
- Array
- Two Pointers
- Binary Search
- Sorting

## Problem Summary
You are given:

A list of numbers (like [3, 5, 6, 7])
A target number (like 9)

Your task is to count how many groups (subsequences) you can make from the list such that:

The smallest number in the group + the biggest number in the group ≤ target
You must return the answer modulo (10^9 + 7) 1,000,000,007 (this is just to keep the number small).

## What is a subsequence?
A subsequence is a group of elements you can pick from the list in the same order, but you can skip some elements.

For example, from [3, 5, 6], valid subsequences include:

- [3]
- [5, 6]
- [3, 6]
- [3, 5, 6]

## What does the condition mean?
For each group (subsequence), you check:

- What is the smallest number in the group?
- What is the largest number in the group?
Then check:
```
smallest + largest ≤ target

```
If it is, then this group is valid.

## Why modulo 1,000,000,007?
When counting all valid groups, the number can get very large. To keep it manageable and avoid overflow, we return the result modulo 
10^9 + 7, which is a common trick in programming.

### Example
Let’s say:

- List = [3, 5, 6, 7]
- Target = 9

Some valid groups:

- [3] → 3 + 3 = 6 ✅
- [3, 5] → 3 + 5 = 8 ✅
- [3, 6] → 3 + 6 = 9 ✅
- [3, 5, 6] → 3 + 6 = 9 ✅
- [5] → 5 + 5 = 10 ❌
- [6] → 6 + 6 = 12 ❌


## Step-by-Step Explanation of the Code

🔹 **Step 1: Sort the Numbers:** We sort the list so we can easily find the smallest and biggest numbers in any group.

🔹 **Step 2: Precompute Powers of 2:** We calculate powers of 2 because for a group of size n, there are 2^n ways to choose subsequences. We store them in a list called power.

🔹 **Step 3: Two Pointers (low and high):** We use two fingers (pointers) to check combinations:

- If the smallest + biggest number is too big, we move the high pointer left.
- If it’s okay, we count how many subsequences we can make between low and high and move low right.

Here's a clean and efficient C++ solution to solve the problem of counting valid subsequences where the sum of the smallest and largest number is less than or equal to the target:
```C++ []
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Step 1

        int size = nums.size(), mod = 1e9 + 7;
        vector<int> power(size, 1);  // Step 2
        for (int i = 1; i < size; ++i)
            power[i] = power[i - 1] * 2 % mod;

        int low = 0, high = size - 1, res = 0;
        while (low <= high) {  // Step 3
            if (nums[low] + nums[high] > target) 
                high--;  // Try a smaller number
            else {
                res = (res + power[high - low]) % mod;
                low++;  // Try next bigger number
            }
        }
        return res;
    }
};
```

## C++ Solution Using Custom Merge Sort + Two Pointers
```C++ []
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        mergeSort(nums, 0, nums.size() - 1);  // Custom merge sort

        int size = nums.size(), mod = 1e9 + 7;
        vector<int> power(size, 1);  // Precompute powers of 2
        for (int i = 1; i < size; ++i)
            power[i] = (power[i - 1] * 2) % mod;

        int low = 0, high = size - 1, res = 0;
        while (low <= high) {
            if (nums[low] + nums[high] > target) {
                high--;
            } else {
                res = (res + power[high - low]) % mod;
                low++;
            }
        }
        return res;
    }

private:
    // Merge function for merge sort
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];

        for (int i = 0; i < temp.size(); ++i)
            nums[left + i] = temp[i];
    }

    // Recursive merge sort
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
};
```

## Refactored Code Using SOLID Principles
Refactoring your C++ solution using SOLID principles means improving the design for better maintainability, readability, and testability.

```C++ []
#include <vector>
#include <algorithm>
using namespace std;

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
```

C++ code with test cases
```C++ []
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

    cout << "All test cases passed successfully! ✅" << endl;
    return 0;
}
```

## Table of C++ Concepts and STL Used

| Concept / API | Description | Example in Code |
|---------------|-------------|-----------------|
| vector<int> | A dynamic array that can grow or shrink | vector<int>& nums |
| sort() | Sorts the array in increasing order | sort(nums.begin(), nums.end()) |
| power[i] = power[i - 1] * 2 % mod | Precomputes powers of 2 modulo mod | Used in the for loop |

Leetocde Solution of the [problem](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/6899323/c-optimized-approach-sort-two-pointer-te-snrb/). 
