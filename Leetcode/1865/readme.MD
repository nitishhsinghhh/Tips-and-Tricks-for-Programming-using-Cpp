# 📘 Understanding the Optimized `FindSumPairs` C++ Class

This document explains the optimized implementation of the `FindSumPairs` class in C++. The class is designed to efficiently support two operations:

1. `add(index, val)`: Adds a value to an element in the second array.
2. `count(tot)`: Counts the number of pairs `(i, j)` such that `nums1[i] + nums2[j] == tot`.

---

## ✅ Problem Constraints

- `1 <= nums1.length <= 1000`
- `1 <= nums2.length <= 10^5`

Due to the large size of `nums2`, we need an efficient way to perform the `count()` operation.

---

## 🚀 Optimized Approach

We use a **hash map** (`unordered_map`) to store the frequency of elements in `nums2`. This allows us to compute the count in **O(n)** time instead of **O(n * m)**.

---

## 🧠 Code Explanation

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqMap; // Frequency map for nums2

public:
    // Constructor: initializes nums1 and nums2, and builds the frequency map for nums2
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freqMap[num]++;
        }
    }

    // Adds val to nums2[index] and updates the frequency map
    void add(int index, int val) {
        if (index >= 0 && index < nums2.size()) {
            int oldVal = nums2[index];
            freqMap[oldVal]--;            // Decrease count of old value
            nums2[index] += val;          // Update the value
            freqMap[nums2[index]]++;      // Increase count of new value
        }
    }

    // Counts the number of pairs (i, j) such that nums1[i] + nums2[j] == tot
    int count(int tot) {
        int res = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freqMap.count(complement)) {
                res += freqMap[complement];
            }
        }
        return res;
    }
};
