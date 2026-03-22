# Leetcode 189: Rotate Array

## Approach

Here is the concise explanation of the code.
**Step 1:** k = k % n; statement ensures that if k is larger than n, we only perform necessary rotations and n times rotation is the same of the original array.
**Step 2:** Reverse the entire array.
**Step 3:** Reverse the array elements from index 0 to index k-1.
**Step 4:** Reverse the array elements from index k to index n-1.
This is how we will have the k times rotated array.

**Time Complexity:** O(N) where N is the number of elements

**Space Complexity:** O(1) as we do not use any extra space.
