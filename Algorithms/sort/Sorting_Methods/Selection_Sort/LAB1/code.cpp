#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class SortMethod {
	Standard,
	StandardWithInbuilt
};

class SelectionSort {
public:
	static void sort(vector<int>& nums, SortMethod method) {
		switch (method) {
		case SortMethod::Standard:
			standardSort(nums);
			break;
		case SortMethod::StandardWithInbuilt:
			standardSortWithInbuilt(nums);
			break;
		}
	}

private:
	static void standardSort(vector<int>& nums) {
		int minInd, startInd, currInd, size = nums.size();
		if (size <= 1) return;
		for (startInd = 0; startInd < size - 1; startInd++) {
			for (currInd = startInd + 1, minInd = startInd; currInd < size; currInd++)
				if (nums[minInd] > nums[currInd])
					minInd = currInd;
			if (minInd != startInd)
				swap(nums[startInd], nums[minInd]);
		}
	}

	static void standardSortWithInbuilt(vector<int>& nums) {
		int minInd, startInd, size = nums.size();
		if (size <= 1) return;
		for (startInd = 0; startInd < size - 1; startInd++) {
			minInd = min_element(nums.begin() + startInd, nums.end()) - nums.begin();
			if (minInd != startInd)
				swap(nums[startInd], nums[minInd]);
		}
	}
};

int main() {
	vector<int> nums = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

	// Sort using standard selection sort
	SelectionSort::sort(nums, SortMethod::Standard);
	cout << "Sorting:  standard selection sort: { ";
	for (int num : nums) 
		cout << num << " ";
	cout << "}" << endl;

	// Sort using selection sort with inbuilt function
	SelectionSort::sort(nums, SortMethod::StandardWithInbuilt);
	cout << "Sorting:  standard selection sort with inbuilt function: { ";
	for (int num : nums) 
		cout << num << " ";
	cout << "}" << endl;

	system("pause");

	return 0;
}

/*
Output:
Sorting:  standard selection sort: { 1 1 2 3 3 4 5 5 5 6 9 }
Sorting:  standard selection sort with inbuilt function: { 1 1 2 3 3 4 5 5 5 6 9 }
*/
