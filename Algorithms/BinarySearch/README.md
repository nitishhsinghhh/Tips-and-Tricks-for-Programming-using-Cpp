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

# CPP code exmaple 

```cpp
/**
 * @file binary_search.cpp
 * @author Nitish Singh
 * @email me.singhnitish@yandex.com
 * @brief Demonstrates the use of the Binary Search algorithm in C++.
 * @date 2025
 *
 * @details
 * Binary Search is a divide-and-conquer algorithm used to efficiently find the position
 * of a target value in a sorted array. This implementation first sorts the input array
 * and then applies binary search to check whether a given key exists.
 * 
 * The program runs two test cases and prints the corresponding results.
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Performs binary search on a sorted array to find the index of a given key.
 * 
 * @param nums The sorted vector of integers.
 * @param search_key The value to search for.
 * @return int Index of the element if found; otherwise, -1.
 */
int binary_search(std::vector<int>& nums, int search_key) {
    int ans_index = -1;
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] == search_key) {
            ans_index = mid;
            break;
        }
        else if (nums[mid] < search_key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return ans_index;
}

/**
 * @brief Main function to demonstrate binary search.
 * 
 * @return int Exit status.
 */
int main() {
    std::vector<int> numbers = {4, 6, 7, 12, 9, 3, 6, 7};
    int search_key = 6;
    int res;

    // Sort the input array before performing binary search
    std::sort(numbers.begin(), numbers.end());

    // Test case 1: Search for 6
    res = binary_search(numbers, search_key);
    if (res == -1)
        std::cout << "Test Case 1: Element is not found\n";
    else
        std::cout << "Test Case 1: Element has been found\n";

    // Test case 2: Search for 5
    res = binary_search(numbers, 5);
    if (res == -1)
        std::cout << "Test Case 2: Element is not found\n";
    else
        std::cout << "Test Case 2: Element has been found\n";

    return 0;
}
```

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

## Meaning of "Monotonically"
- In mathematics and computer science, monotonic means something changes in one direction only — it either always increases or always decreases, but never reverses.
- For binary search:
    - The search space (the interval between left and right) always decreases in size at each step.
    - It never grows back or oscillates; it shrinks steadily until it becomes empty or reaches the answer.

### Binary Search and Monotonicity
- Binary search works because the condition you’re testing is monotonic.
- A monotonic function or predicate is one that changes in only one direction: once it becomes true (or false), it stays that way for the rest of the domain.

Formally:
Increasing: 𝑓(𝑎) ≤ 𝑓(𝑏) whenever 𝑎 < 𝑏.
Decreasing: 𝑓(𝑎) ≥ 𝑓(𝑏) whenever 𝑎 < 𝑏.

### In our mySqrt example
- We’re searching for the largest integer mid such that mid * mid ≤ x.
- The function 𝑓(𝑚𝑖𝑑)=𝑚𝑖𝑑^2 is monotonically increasing for non-negative integers.
- That monotonicity guarantees:
    - If 𝑚𝑖𝑑^2 > 𝑥, then all larger values will also be too large
    - If 𝑚𝑖𝑑^2 < 𝑥, then all smaller values will also be too small.
- This property allows binary search to safely discard half of the search space each step.

So yes — binary search relies on the fact that the function (or condition) being checked is monotonic. In our case, 𝑚𝑖𝑑^2 is a monotonically increasing function.

### Comparison with Linear Search

| Algorithm      | Worst-case Time | Best-case Time | Space |
|----------------|-----------------|----------------|-------|
| Linear search  | O(n)            | O(1)           | O(1)  |
| Binary search  | O(log n)        | O(1)           | O(1)  |

### Implementation of Recursive  Binary Search Algorithm:

```cpp
/**
 * @file binary_search_class_main.cpp
 * @brief Demonstrates Binary Search using a class-based implementation in C++.
 * @author Nitish Singh
 * @date 2025
 *
 * @details
 * This program defines a BinarySearch class containing a method to perform binary search
 * on a sorted array. It checks whether a given element exists in the array and prints
 * its index or an appropriate message if not found.
 */

#include <iostream>
#include <vector>

/**
 * @class BinarySearch
 * @brief A class that encapsulates binary search functionality.
 */
class BinarySearch {
public:
    /**
     * @brief Searches for a target value in a sorted vector using binary search.
     * 
     * @param arr A sorted vector of integers.
     * @param x The target value to search for.
     * @return int The index of the target if found, else -1.
     */
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

/**
 * @brief The main function to test the BinarySearch class.
 * 
 * @return int Exit status of the program.
 */
int main() {
    std::vector<int> arr{2, 3, 4, 10, 40};  // Sorted input array
    int x = 10;  // Element to be searched

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
/**
 * @file binary_search_class_iterative.cpp
 * @brief Implements Binary Search using a class in C++ (Iterative method).
 * @author Nitish Singh
 * @date 2025
 *
 * @details
 * This program demonstrates how to use the Binary Search algorithm inside a class-based structure.
 * It performs an efficient search for an element in a sorted array and returns the index if found.
 */

#include <iostream>
#include <vector>

/**
 * @class BinarySearch
 * @brief A class that encapsulates an iterative binary search algorithm.
 */
class BinarySearch {
public:
    /**
     * @brief Performs binary search on a sorted vector to find the target value.
     * 
     * @param arr A sorted vector of integers.
     * @param x The target value to search for.
     * @return int The index of the target if found, else -1.
     */
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

/**
 * @brief Main function to test the BinarySearch class.
 * 
 * @return int Exit status.
 */
int main() {
    std::vector<int> arr{2, 3, 4, 10, 40};  // Sorted input array
    int x = 10;  // Element to search

    BinarySearch bs;
    int result = bs.search(arr, x);

    if (result == -1)
        std::cout << "Element is not present in array\n";
    else
        std::cout << "Element is present at index " << result << '\n';

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

The prototype for [Binary Search](https://en.cppreference.com/w/cpp/algorithm/binary_search) is:

```cpp
template< class ForwardIt, class T >
bool binary_search( ForwardIt first, ForwardIt last, const T& value );
(until C++20) 
template< class ForwardIt, class T >
constexpr bool binary_search( ForwardIt first, ForwardIt last, const T& value );
(since C++20)
(2)	
template< class ForwardIt, class T, class Compare >
bool binary_search( ForwardIt first, ForwardIt last,
                    const T& value, Compare comp );
(until C++20)
template< class ForwardIt, class T, class Compare >
constexpr bool binary_search( ForwardIt first, ForwardIt last,
                              const T& value, Compare comp );
(since C++20)
```

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
### Vector Search with Sorting and Binary Search in C++

```cpp
/**
 * @file vector_search.cpp
 * @brief Demonstrates class-based vector operations: sorting and binary search
 * in C++.
 * @author Nitish Singh
 *
 * @details
 * This program defines a class `VectorSearch` that:
 * - Stores a vector of integers.
 * - Sorts the vector using `std::sort`.
 * - Searches for a value using `std::binary_search`.
 *
 * It also includes a demonstration in `main()` using hardcoded values.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @class VectorSearch
 * @brief A class to encapsulate vector operations: sorting and binary search.
 */
class VectorSearch {
private:
    std::vector<int> vec; ///< Internal vector to operate on

public:
    /**
     * @brief Constructor to initialize the vector.
     * @param v Input vector of integers.
     */
    VectorSearch(const std::vector<int>& v) : vec(v) {}

    /**
     * @brief Displays the contents of the vector.
     */
    void show() {
        for (int i : vec)
            std::cout << i << " ";
    }

    /**
     * @brief Sorts the vector in ascending order.
     */
    void sortVector() { std::sort(vec.begin(), vec.end()); }

    /**
     * @brief Performs binary search on the sorted vector.
     * @param key The value to search for.
     * @return true if the key is found, false otherwise.
     */
    bool binarySearch(int key) {
        return std::binary_search(vec.begin(), vec.end(), key);
    }
};

/**
 * @brief Main function to demonstrate the use of VectorSearch class.
 * @return int Exit status.
 */
int main() {
    std::vector<int> vec = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    std::cout << "The original vector is: ";
    VectorSearch vectorSearch(vec);
    vectorSearch.show();

    std::cout << "\n\nSorting the vector before performing binary search...";
    vectorSearch.sortVector();

    std::cout << "\n\nThe sorted vector is: ";
    vectorSearch.show();

    std::cout << "\n\nBinary Search for element 2:";
    if (vectorSearch.binarySearch(2))
        std::cout << "\n Element found in the vector.";
    else
        std::cout << "\n Element not found in the vector.";

    std::cout << "\n\nBinary Search for element 10:";
    if (vectorSearch.binarySearch(10))
        std::cout << "\n Element found in the vector.\n";
    else
        std::cout << "\n Element not found in the vector.\n";

    // Portable alternative to system("pause")
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    std::cin.get(); // one for leftover newline, one to pause

    return 0;
}
```

### C++ code example 2
```cpp
#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Entry point of the program.
 *
 * Initializes a sorted vector (`haystack`) and a set of target values
 * (`needles`), then performs binary search on each needle and prints the
 * result.
 *
 * @return int Exit code of the program.
 */
int main() {
    std::vector<int> haystack{1, 3, 4, 5, 9}; ///< Sorted vector to search in
    std::vector<int> needles{1, 2, 3}; ///< Elements to search for in haystack

    for (const auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';

        // Perform binary search
        if (std::binary_search(haystack.begin(), haystack.end(), needle))
            std::cout << "Found " << needle << '\n';
        else
            std::cout << "No dice!\n";
    }
}
```


# Binary search leetcode
Blind top 5<br>
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
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

/**
 * @class Solution
 * @brief Provides a method to find the minimum number of days required to make m bouquets from flowers.
 */
class Solution {
private:
    /**
     * @brief Checks whether it is possible to make 'm' bouquets by day 'mid'.
     * 
     * @param bloomDay Vector representing bloom days of flowers.
     * @param m Number of bouquets to make.
     * @param k Number of flowers required in each bouquet.
     * @param mid The day being tested as the maximum bloom day.
     * @return true If it is possible to make m bouquets by day 'mid'.
     * @return false Otherwise.
     */
    bool isValid(const std::vector<int>& bloomDay, int m, int k, int mid) {
        int count = 0, size = 0;
        for (int day : bloomDay) {
            size = (day <= mid) ? size + 1 : 0;
            if (size == k) {
                count++;
                size = 0;
            }
            if (count == m)
                return true;
        }
        return false;
    }

public:
    /**
     * @brief Finds the minimum number of days required to make 'm' bouquets of size 'k'.
     * 
     * @param bloomDay A vector containing the days each flower blooms.
     * @param m Number of bouquets required.
     * @param k Number of flowers per bouquet.
     * @return int Minimum number of days needed to fulfill the requirement, or -1 if impossible.
     */
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if (bloomDay.empty() || m == 0 || k == 0) return 0;
        if (static_cast<long long>(m) * k > bloomDay.size()) return -1;

        int l = INT_MAX, r = INT_MIN;
        for (int day : bloomDay) {
            l = std::min(l, day);
            r = std::max(r, day);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(bloomDay, m, k, mid))
                r = mid - 1;
            else
                l = mid + 1;
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

		if (l > r)
			return -1;

		int m = l + (r - l) / 2;

		if (((m > 0) && (nums[m] > nums[m - 1])) &&
			((m < nums.size() - 1) && (nums[m] > nums[m + 1])))
			return m;

		if (m == 0 && nums.size() > 1 && nums[m] > nums[m + 1])
			return m;

		if ((m == nums.size() - 1) && (nums[m] > nums[m - 1]))
			return m;

		int left = findPeakElementUtil(nums, l, m - 1);
		int right = findPeakElementUtil(nums, m + 1, r);

		if (left != -1)
			return left;
		else
			return right;
	}
public:
	int findPeakElement(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) return 0;

		return findPeakElementUtil(nums, 0, n - 1);
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
/**
 * @file next_greatest_letter.cpp
 * @brief Finds the smallest character in a sorted array that is greater than the target character.
 * @details
 * If no character is strictly greater than the target, the function wraps around and returns the first element.
 * This is a binary search-based solution with O(log n) time complexity.
 */

#include <vector>

using namespace std;

/**
 * @class Solution
 * @brief Implements binary search to find the next greatest letter.
 */
class Solution {
public:
    /**
     * @brief Returns the smallest character in letters that is strictly greater than target.
     * 
     * @param letters A vector of sorted characters (in non-decreasing order).
     * @param target The target character.
     * @return char The next greatest character, with wrap-around logic.
     */
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;

        // Binary search for the smallest character > target
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (letters[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }

        // If all characters are <= target, wrap around to the first character
        return letters[l % n];
    }
};
```

## Using C++ STL upper bound for binary search
[Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)<br>
[Online Election](https://leetcode.com/problems/online-election/)<br>
[Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)<br>
[Find Right Interval](https://leetcode.com/problems/find-right-interval/)<br>

```cpp
/**
 * @file time_map.cpp
 * @brief Implements a TimeMap class that stores key-value pairs with timestamps and supports time-based retrievals.
 * @details
 * Each key can store multiple values associated with increasing timestamps.
 * The `get` function returns the value with the greatest timestamp less than or equal to the given timestamp.
 * Uses:
 * - `unordered_map` to map keys to an ordered `map` of {timestamp → value}
 * - Efficient O(log n) retrieval using `upper_bound` and `prev`
 */

#include <unordered_map>
#include <map>
#include <string>

using namespace std;

/**
 * @class TimeMap
 * @brief A class to store time-based key-value pairs and retrieve them efficiently.
 */
class TimeMap {
private:
    unordered_map<string, map<int, string>> hm; ///< Maps key → map<timestamp, value>

public:
    /**
     * @brief Initializes the TimeMap data structure.
     */
    TimeMap() {}

    /**
     * @brief Stores the key with the given value and timestamp.
     * 
     * @param key The string key to be stored.
     * @param value The value associated with the key.
     * @param timestamp The time at which the value is set.
     */
    void set(string key, string value, int timestamp) {
        hm[key][timestamp] = value;
    }

    /**
     * @brief Retrieves the value for a given key at or before the provided timestamp.
     * 
     * @param key The string key whose value is to be retrieved.
     * @param timestamp The maximum timestamp allowed.
     * @return string The most recent value at or before the given timestamp; empty string if none exists.
     */
    string get(string key, int timestamp) {
        auto it = hm[key].upper_bound(timestamp);  // first element > timestamp
        if (it == hm[key].begin())
            return "";
        return prev(it)->second;  // move one step back to get <= timestamp
    }
};
```

## Binary search based on condition on 2 arrays
[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)<br>

```cpp
/**
 * @file find_median_sorted_arrays.cpp
 * @brief Efficiently finds the median of two sorted arrays using binary search partitioning.
 * @author 
 * @date 2025
 *
 * @details
 * This solution uses binary search on the smaller array to partition both arrays into two halves
 * such that all elements in the left half are less than or equal to all elements in the right half.
 * Time Complexity: O(log(min(n, m)))
 */

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/**
 * @class Solution
 * @brief Contains method to find the median of two sorted arrays.
 */
class Solution {
public:
    /**
     * @brief Finds the median of two sorted arrays.
     * 
     * @param nums1 First sorted array.
     * @param nums2 Second sorted array.
     * @return double Median value.
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Ensure nums1 is the smaller array
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int k = (n + m - 1) / 2;  // Left partition size
        int l = 0;
        int r = min(k, n);

        // Binary search on the smaller array to find the correct partition
        while (l < r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = k - mid1;

            if (nums1[mid1] > nums2[mid2])
                r = mid1;
            else
                l = mid1 + 1;
        }

        // Compute the left max (a)
        int a = max(
            l >= 1 ? nums1[l - 1] : INT_MIN,
            k >= l ? nums2[k - l] : INT_MIN
        );

        // If total length is odd, return the middle value
        if ((n + m) % 2 != 0)
            return a;

        // Compute the right min (b) for even total length
        int b = min(
            l < n ? nums1[l] : INT_MAX,
            k - l + 1 < m ? nums2[k - l + 1] : INT_MAX
        );

        return (a + b) / 2.0;
    }
};
```

## Two Pointers: The General Pattern
Maintain two indices (or bounds) over a sequence/number line—typically i and j—and move them based on some condition to converge on the answer.
Common variants:
- Opposite ends (e.g., sorted array pair-sum: move i up or j down).
- Sliding window (e.g., subarray with sum/property: move right to expand, left to shrink).
- Partitioning (e.g., Dutch flag, Lomuto/Hoare partition in quicksort).
- Same-direction pointers (e.g., slow/fast cycle detection).

## Binary Search as a Special Case of Two Pointers
Binary search maintains two pointers (left, right) bounding the candidate space and moves them based on a monotone predicate. The only difference vs. classic two-pointers is how the next step is chosen:

- Two-pointers normally move one end (e.g., left++ or right--) based on comparisons.
- Binary search moves one end after probing the midpoint (mid = (left + right)/2)—still two pointers; the midpoint is just a probe strategy that halves the search space each iteration.
