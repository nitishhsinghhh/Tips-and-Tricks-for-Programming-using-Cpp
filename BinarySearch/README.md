# Binary Search 
Binary search is an algorithm employed for searching in a sorted array by iteratively dividing the search range in half. The concept behind binary search is to leverage the sorted nature of the array to achieve a time complexity of O(log N).

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/51e0fc30-d69d-44f6-9e14-504b51840de0)

## Conditions for applying the Binary Search algorithm to a data structure:
1. The data structure must be sorted in ascending or descending order.
2. Accessing any element within the data structure must take constant time.

## Binary Search Algorithm:

1. Divide the search space into two halves by finding the middle index "mid".

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/9305617a-84d6-475b-a120-2bf6b4691821)

2. Compare the middle element of the search space with the key: <br>
   A. If the key is found at the middle element, the process is terminated. <br>
   B. If the key is not found at the middle element, choose which half will be used as the next search space. <br>
      - If the key is smaller than the middle element, then the left side is used for the next search. <br>
   - If the key is larger than the middle element, then the right side is used for the next search. <br>
3. This process is continued until the key is found or the total search space is exhausted.

### How to Implement Binary Search?

The Binary Search Algorithm can be implemented in the following two ways:

1. **Iterative Binary Search Algorithm:**
   Here we use a while loop to continue the process of comparing the key and splitting the search space in two halves.

2. **Recursive Binary Search Algorithm:**
   Create a recursive function and compare the mid of the search space with the key. And based on the result either return the index where the key is found or call the recursive function for the next search space.

### Complexity Analysis of Binary Search

**Time Complexity:**
- Best Case: O(1)
- Average Case: O(log N)
- Worst Case: O(log N)

**Auxiliary Space:** 
- O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).

**Advantages of Binary Search:**
- Binary search is faster than linear search, especially for large arrays.
- More efficient than other searching algorithms with a similar time complexity, such as interpolation search or exponential search.
- Well-suited for searching large datasets that are stored in external memory, such as on a hard drive or in the cloud.

**Drawbacks of Binary Search:**
- The array should be sorted.
- Requires that the data structure being searched be stored in contiguous memory locations.
- Requires that the elements of the array be comparable, meaning that they must be able to be ordered.

**Applications of Binary Search:**
- Can be used as a building block for more complex algorithms used in machine learning, such as algorithms for training neural networks or finding the optimal hyperparameters for a model.
- Used for searching in computer graphics such as algorithms for ray tracing or texture mapping.
- Can be used for searching a database.

### Implementation of Recursive  Binary Search Algorithm:

```cpp
#include <iostream>
#include <vector>
class BinarySearch {
public:
	int search(const std::vector<int>& arr, int x) {
		int l = 0, r = arr.size() - 1;
		while (r >= l) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == x)
				return mid;
			if (arr[mid] > x) 
				r = mid - 1;
			else 
				l = mid + 1;
		}
		return -1;
	}
};

int main() {
	std::vector<int> arr{ 2, 3, 4, 10, 40 };
	int x = 10;
	BinarySearch bs;
	int result = bs.search(arr, x);
	if (result == -1) 
		std::cout << "Element is not present in array";
	else 
		std::cout << "Element is present at index " << result;
	std::cout << std::endl;
	return 0;
}
```

### Implementation of Iterative  Binary Search Algorithm: 

```cpp
#include <iostream>
#include <vector>

class BinarySearch {
public:
	int search(const std::vector<int>& arr, int x) {
		int l = 0, r = arr.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (arr[m] == x) 
				return m;
			if (arr[m] < x) 
				l = m + 1;
			else 
				r = m - 1;
		}
		return -1;
	}
};

int main() {
	std::vector<int> arr{ 2, 3, 4, 10, 40 };
	int x = 10;
	BinarySearch bs;
	int result = bs.search(arr, x);
	if (result == -1) 
		std::cout << "Element is not present in array";
	else 
		std::cout << "Element is present at index " << result;
	std::cout << std::endl;
	system("pause");
	return 0;
}
```
# Edge Cases

When working with array search algorithms, it's important to consider the following edge cases:

1. **Non-existent Element**: It's crucial to handle the scenario where the element being searched for does not exist in the array. This requires preventing the search from accessing invalid indices and causing exceptions.

2. **Rightmost or Leftmost Target**: The target value may be located at the extreme ends of the array.

3. **Target in Different Positions**: The target value could be the first, middle, or any other position within the array.

4. **Duplicate Entries**: If the array contains duplicate entries, the algorithm may return the position of the first occurrence, which may not be suitable for all use cases.

It's important to consider and address these edge cases to ensure the robustness and accuracy of the array search algorithm.

### Binary Search in C++ Standard Template Library (STL)

The prototype for [Binary Search](https://en.cppreference.com/w/cpp/algorithm/binary_search) is : 

### binary_search (1)
```cpp
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value) {
    first = std::lower_bound(first, last, value);
    return (!(first == last) and !(value < *first));
}
```

### binary_search (2)
```cpp
template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp) {
    first = std::lower_bound(first, last, value, comp);
    return (!(first == last) and !(comp(value, *first)));
}
```

```cpp
binary_search(startaddress, 
              endaddress, valuetofind)
Parameters :
startaddress: the address of the first 
              element of the array.
endaddress: the address of the next contiguous 
            location of the last element of the array.
valuetofind: the target value which we have 
             to search for.
Returns :
true if an element equal to valuetofind is found, else false.
```
### C++ code example 1

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class VectorSearch {
private:
	std::vector<int> vec;

public:
	VectorSearch(const std::vector<int>& v) : vec(v) {}

	void show() {
		for (int i : vec) 
			std::cout << i << ",";
	}

	void sortVector() {
		std::sort(vec.begin(), vec.end());
	}

	bool binarySearch(int key) {
		return std::binary_search(vec.begin(), vec.end(), key);
	}
};

int main() {
	std::vector<int> vec = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	std::cout << "The vector is : ";
	VectorSearch vectorSearch(vec);
	vectorSearch.show();

	std::cout << "\n\nLet's say we want to search for 2 in the vector. So, we first sort the vector";
	vectorSearch.sortVector();
	std::cout << "\n\nThe vector after sorting is : ";
	vectorSearch.show();

	std::cout << "\n\nNow, we do the binary search";
	if (vectorSearch.binarySearch(2))
		std::cout << "\nElement found in the vector";
	else
		std::cout << "\nElement not found in the vector";

	std::cout << "\n\nNow, say we want to search for 10";
	if (vectorSearch.binarySearch(10))
		std::cout << "\nElement found in the vector \n";
	else
		std::cout << "\nElement not found in the vector \n";
	
	system("pause");
	return 0;
}
```

Output
```
The vector is : 1,5,8,9,6,7,3,4,2,0,

Let's say we want to search for 2 in the vector. So, we first sort the vector

The vector after sorting is : 0,1,2,3,4,5,6,7,8,9,

Now, we do the binary search
Element found in the vector

Now, say we want to search for 10
Element not found in the vector
```

### C++ code example 2
// GCC 13.1 (C++ 23)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> haystack{1, 3, 4, 5, 9};
    std::vector<int> needles{1, 2, 3};
 
    for (const auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';
        if (std::binary_search(haystack.begin(), haystack.end(), needle))
            std::cout << "Found " << needle << '\n';
        else
            std::cout << "No dice!\n";
    }
}
```

Output:
```
Searching for 1
Found 1
Searching for 2
no dice!
Searching for 3
Found 3
```


# Binary search leetcode
Blind top 5
[Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)<br>
[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/description/)<br>
[Counting Bits](https://leetcode.com/problems/counting-bits/description/)<br>
[Missing Number](https://leetcode.com/problems/missing-number/description/)<br>
[Reverse Bits](https://leetcode.com/problems/reverse-bits/description/)<br>


# Problems where its Difficult to figure out if Binary Search can be applied.

There are certain problem scenarios where it can be challenging to determine if binary search is applicable. In these cases, there is an array of length (n) and the task is to find the minimum value that satisfies a specific condition on the array. The runtime for these problems is typically nLog(m).

[Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)<br>
[Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)<br>
[Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)<br>
[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)<br>
[Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)<br>

```cpp
class Solution {
	bool isValid(vector<int>& bloomDay, int m, int k, int mid) {

		int count = 0, size = 0;
		for (int i = 0; i < bloomDay.size(); i++) {
			size = (bloomDay[i] <= mid) ? size+1 : 0;
			if (size == k) size = 0, count++;
			if (count == m)
				return true;
		}

		return false;
	}
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		if(bloomDay.size() == 0 || m == 0 || k == 0) return 0;
		if (m * k > bloomDay.size()) return -1;

		int l = INT_MAX, r = INT_MIN;
		for (int i = 0; i < bloomDay.size(); i++) {
			l = min(l, bloomDay[i]);
			r = max(r, bloomDay[i]);
		}

		while (l <= r) {
			int mid = l + (r-l)/2;

			if (isValid(bloomDay, m, k, mid))
				r = mid-1;
			else
				l = mid+1;
		}

		return l;
	}
};
```

## Tricky Binary Search
There are multiple conditions we need to figure out if we need to select left or if we need to select right.

[Find Peak Element](https://leetcode.com/problems/find-peak-element/)<br>
[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)<br>
[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)<br>
[Missing element in sorted array](https://leetcode.com/problems/missing-element-in-sorted-array/)<br>

```cpp
class Solution {

	int findPeakElementUtil(vector<int>& nums, int l, int r) {

		if (l > r) return -1;

		int m = l + (r-l)/2;

		if (((m > 0) && (nums[m] > nums[m-1])) &&
			((m < nums.size()-1) && (nums[m] > nums[m+1])))
			return m;

		if (m == 0 && nums.size() > 1 && nums[m] > nums[m+1])
			return m;

		if ((m == nums.size()-1) && (nums[m] > nums[m-1]))
			return m;

		int left = findPeakElementUtil(nums, l, m-1);
		int right = findPeakElementUtil(nums, m+1, r);

		if (left != -1)
			return left;
		else
			return right;
	}
public:
	int findPeakElement(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) return 0;

		return findPeakElementUtil(nums, 0, n-1);
	}
};
```

## Simple Binary Search
[Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)<br>
[Missing element in sorted array](https://leetcode.com/problems/missing-element-in-sorted-array/)<br>
[Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)<br>
[H-Index II](https://leetcode.com/problems/h-index-ii/)<br>
[Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)<br>
[First Bad Version](https://leetcode.com/problems/first-bad-version/)<br>

```cpp
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {

		int n = letters.size();
		int l = 0, r = n-1;

		if (target >= letters[n-1] || target < letters[0])
			return letters[0];

		int m = 0;
		while (l <= r) {
			m = l + (r-l)/2;

			if (m > 0 && (target >= letters[m-1] && target < letters[m]))
					return letters[m];
			else if (target >= letters[m])
					l = m+1;
			else	
					r = m-1;
		}

		return letters[m];
	}
};
```

## Using C++ STL upper bound for binary search
<br>
[Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)<br>
[Online Election](https://leetcode.com/problems/online-election/)<br>
[Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)<br>
[Find Right Interval](https://leetcode.com/problems/find-right-interval/)<br>

```cpp
class TimeMap {
	unordered_map<string, map<int, string>>hm;
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		hm[key].insert({timestamp, value});
	}

	string get(string key, int timestamp) {
		auto it = hm[key].upper_bound(timestamp);
		return (it == hm[key].begin()) ? "" : prev(it)->second;
	}
};
```

## Binary search based on condition on 2 arrays
[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)<br>

```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int n = nums1.size();
		int m = nums2.size();

		if (n > m)
			return findMedianSortedArrays(nums2, nums1);

		int k = (n+m-1)/2;

		int l = 0;
		int r = min(k, n);

		while (l < r) {
			int mid1 = l + (r-l)/2;
			int mid2 = k-mid1;

			if (nums1[mid1] > nums2[mid2])
				r = mid1;
			else
				l = mid1+1;
		}

		/* if (n+m) is odd, the median is the larger one between nums1[l-1] and nums2[k-l] */
		int a = max(l >= 1 ? nums1[l-1] : INT_MIN, k >= l ? nums2[k-l] : INT_MIN);
		if ((n+m) % 2 != 0)
			return a;

		/* in case (n+m) is even, take the average of mid 2 elements */
		int b =  min(l < n ? nums1[l] : INT_MAX, k-l+1 < m ? nums2[k-l+1] : INT_MAX);

		return (a+b)/2.0;
	}
};
```
