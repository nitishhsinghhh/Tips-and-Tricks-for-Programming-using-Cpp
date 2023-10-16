#include <iostream>
#include <vector>
using namespace std;

enum class SortMethod { 
  Standard, 
  Random 
};

class QuickSort {
public:
	static void quickSort(vector<int>& nums, int low, int high, SortMethod method) {
		if (low >= high) return;
		int pivot;
		if (method == SortMethod::Standard) 
			pivot = partitionArray(nums, low, high);
		else {
			swap(nums[low + rand() % (high - low + 1)], nums[low]);
			pivot = partitionArray(nums, low, high);
		}
		quickSort(nums, low, pivot, method);
		quickSort(nums, pivot + 1, high, method);
	}
private:
	static int partitionArray(vector<int>& nums, int low, int high) {
		if (low >= high) return -1;
		int pivot = low, l = pivot + 1, r = high;
		while (l <= r)
			if (nums[l] < nums[pivot]) l++;
			else if (nums[r] >= nums[pivot]) r--;
			else swap(nums[l], nums[r]);
		swap(nums[pivot], nums[r]);
		return r;
	}
};

int main() {
	// Test standard quick sort
	vector<int> nums1 = { 3, 2, 5, 1, 6, 4 };
	QuickSort::quickSort(nums1, 0, nums1.size() - 1, SortMethod::Standard);
	cout << "Standard sorted array: { ";
	for (int num : nums1) 
		cout << num << " ";
	cout << "}"<<endl;

	// Test randomised quick sort
	vector<int> nums2 = { 3, 2, 5, 1, 6, 4 };
	QuickSort::quickSort(nums2, 0, nums2.size() - 1, SortMethod::Random);
	cout << "Randomised sorted array: {";
	for (int num : nums2) 
		cout << num << " ";
	cout << "}" << endl;

	system("pause");
	return 0;
}


/*
Output:
Standard sorted array: { 1 2 3 4 5 6 }
Randomised sorted array: {1 2 3 4 5 6 }
*/
