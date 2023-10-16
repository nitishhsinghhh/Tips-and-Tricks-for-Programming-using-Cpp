#include <iostream>
#include <vector>
using namespace std;

// Enum for two methods
enum SortingMethod {
	ITERATIVE,
	RECURSIVE
};

// Class with public methods
class Sorting {
public:
	// Iterative insertion sort
	void iterativeInsertionSort(vector<int> &nums, const SortingMethod &sortingMethod) {
		if (sortingMethod != ITERATIVE) return;
		int sortedInd, unsortedInd, key, size = nums.size();
		if (size <= 1) return;
		for (unsortedInd = 1; unsortedInd < size; unsortedInd++) {
			key = nums[unsortedInd], sortedInd = unsortedInd;
			while (--sortedInd >= 0 and key < nums[sortedInd])
				nums[sortedInd + 1] = nums[sortedInd];
			nums[sortedInd + 1] = key;
		}
	}

	// Recursive insertion sort
	void recursiveInsertionSort(vector<int> &nums, const SortingMethod &sortingMethod) {
		if (sortingMethod != RECURSIVE) return;
		if (nums.size() <= 1) return;
		int last = nums.back();
		nums.pop_back();
		recursiveInsertionSort(nums, sortingMethod);
		recInsert(nums, last);
	}

private:
	// Recursive helper function for recursiveInsertionSort
	void recInsert(vector<int> &nums, int val) {
		if (!nums.size() or nums.back() <= val)
			return nums.push_back(val);
		int last = nums.back();
		nums.pop_back();
		recInsert(nums, val);
		nums.push_back(last);
	}
};

// Test in main function
int main() {
	vector<int> nums = { 5, 2, 9, 1, 5, 6 };
	Sorting sorting;

	// Test iterative insertion sort
	sorting.iterativeInsertionSort(nums, ITERATIVE);
	cout << "Sorting: iterative insertion sort: { ";
	for (int num : nums) cout << num << " "; // Output: 1 2 5 5 6 9
	cout << "}" << endl;

	// Test recursive insertion sort
	nums = { 5, 2, 9, 1, 5, 6 };
	sorting.recursiveInsertionSort(nums, RECURSIVE);
	cout << "Sorting: recursive insertion sort: { ";
	for (int num : nums) cout << num << " "; // Output: 1 2 5 5 6 9
	cout << "}" << endl;

	return 0;
}

/*
Output:
Sorting: iterative insertion sort: { 1 2 5 5 6 9 }
Sorting: recursive insertion sort: { 1 2 5 5 6 9 }
*/
