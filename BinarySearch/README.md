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

```
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

```
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

