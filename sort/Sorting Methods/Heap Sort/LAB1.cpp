#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
	static void heapifyDown(vector<int> &nums, int size, int rootInd, bool isMin = false) {
		if (size <= 1 or rootInd < 0 or rootInd >= size - 1) 
      return;
		int keyInd = rootInd, leftChildInd = 2 * rootInd + 1, rightChildInd = 2 * rootInd + 2;
		if (leftChildInd < size and (isMin ? nums[leftChildInd] < nums[keyInd] : nums[leftChildInd] > nums[keyInd]))
			keyInd = leftChildInd;
		if (rightChildInd < size and (isMin ? nums[rightChildInd] < nums[keyInd] : nums[rightChildInd] > nums[keyInd]))
			keyInd = rightChildInd;
		if (nums[keyInd] != nums[rootInd]) {
			swap(nums[rootInd], nums[keyInd]);
			heapifyDown(nums, size, keyInd, isMin);
		}
	}

	static void heapifyArray(vector<int> &nums, bool isMin = false) {
		int size = nums.size();
		if (size <= 1) 
      return;
		int tailRootInd = (size >> 1) - 1;
		for (int rootInd = tailRootInd; rootInd >= 0; rootInd--)
			heapifyDown(nums, size, rootInd, isMin);
	}

	static void heapSort(vector<int> &nums) {
		if (nums.size() <= 1) 
      return;
		heapifyArray(nums);
		for (int size = nums.size() - 1; size; size--) {
			swap(nums[size], nums[0]);
			heapifyDown(nums, size, 0);
		}
	}
};

int main() {
	vector<int> nums = { 4, 2, 9, 6, 5, 1, 3, 7, 8 };
	HeapSort::heapSort(nums);
	
	cout << "Heap Sort: { ";
	for (int num : nums) 
		cout << num << " ";
	cout <<"}"<< endl;

	system("pause");
	return 0;
}
