#include <iostream>
#include <vector>

/**
 * @brief Enumeration to represent sorting methods.
 */
enum SortingMethod {
	ITERATIVE, ///< Iterative insertion sort
	RECURSIVE  ///< Recursive insertion sort
};

/**
 * @brief A class that provides both iterative and recursive insertion sort.
 */
class Sorting {
public:
	/**
	 * @brief Performs iterative insertion sort on the given array.
	 * 
	 * @param nums The array of integers to be sorted.
	 * @param sortingMethod Method type: only sorts if method is ITERATIVE.
	 */

	void iterativeInsertionSort(std::vector<int> &nums, const SortingMethod &sortingMethod) {
		
		if (sortingMethod != ITERATIVE) 
			return;

		int sortedInd, unsortedInd, key, size = nums.size();
		
		if (size <= 1) 
			return;

		for (unsortedInd = 1; unsortedInd < size; unsortedInd++) {
			key = nums[unsortedInd];
			sortedInd = unsortedInd;

			while (--sortedInd >= 0 && key < nums[sortedInd])
				nums[sortedInd + 1] = nums[sortedInd];

			nums[sortedInd + 1] = key;
		}
	}

	/**
	 * @brief Performs recursive insertion sort on the given array.
	 * 
	 * @param nums The array of integers to be sorted.
	 * @param sortingMethod Method type: only sorts if method is RECURSIVE.
	 */

	void recursiveInsertionSort(std::vector<int> &nums, const SortingMethod &sortingMethod) {
		if (sortingMethod != RECURSIVE) return;
		if (nums.size() <= 1) return;

		int last = nums.back();
		nums.pop_back();
		recursiveInsertionSort(nums, sortingMethod);
		recInsert(nums, last);
	}

private:
	/**
	 * @brief Recursive helper to insert an element into sorted array.
	 * 
	 * @param nums The sorted array.
	 * @param val The value to insert into correct position.
	 */
	
	void recInsert(std::vector<int> &nums, int val) {
		if (!nums.size() || nums.back() <= val) {
			nums.push_back(val);
			return;
		}

		int last = nums.back();
		nums.pop_back();
		recInsert(nums, val);
		nums.push_back(last);
	}
};

/**
 * @brief Main function to demonstrate iterative and recursive insertion sorts.
 * 
 * @return int Exit status.
 */

int main() {
	std::vector<int> nums = { 5, 2, 9, 1, 5, 6 };
	Sorting sorting;

	// Test iterative insertion sort
	sorting.iterativeInsertionSort(nums, ITERATIVE);
	std::cout << "Sorting: iterative insertion sort: { ";
	for (int num : nums) std::cout << num << " ";
	std::cout << "}" << std::endl;

	// Test recursive insertion sort
	nums = { 5, 2, 9, 1, 5, 6 };
	sorting.recursiveInsertionSort(nums, RECURSIVE);
	std::cout << "Sorting: recursive insertion sort: { ";
	for (int num : nums) std::cout << num << " ";
	std::cout << "}" << std::endl;

	return 0;
}
