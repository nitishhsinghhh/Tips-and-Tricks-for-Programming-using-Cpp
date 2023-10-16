#include <iostream>
#include <vector>
using namespace std;

enum MergeMethod {
	Outplace,
	Inplace
};

class MergeSort {
public:
	void outPlaceMerge(vector<int> &nums, int low, int mid, int high) {
		if (low >= high) return;
		int l = low, r = mid + 1, k = 0, size = high - low + 1;
		vector<int> sorted(size, 0);
		while (l <= mid and r <= high)
			sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
		while (l <= mid)
			sorted[k++] = nums[l++];
		while (r <= high)
			sorted[k++] = nums[r++];
		for (k = 0; k < size; k++)
			nums[k + low] = sorted[k];
	}

	void inPlaceMerge(vector<int> &nums, int low, int mid, int high) {
		if (low >= high) return;
		int l = low, r = mid + 1;
		while (l <= mid and r <= high) {
			if (nums[l] <= nums[r]) l++;
			else {
				int val = nums[r];
				for (int k = r++; k > l; k--)
					nums[k] = nums[k - 1];
				nums[l++] = val;
				mid++;
			}
		}
	}

	void mergeSort(vector<int> &nums, int low, int high, MergeMethod method) {
		if (low >= high) return;
		int mid = (high - low) / 2 + low;
		mergeSort(nums, low, mid, method);
		mergeSort(nums, mid + 1, high, method);
		if (method == Outplace)
			outPlaceMerge(nums, low, mid, high);
		else if (method == Inplace)
			inPlaceMerge(nums, low, mid, high);
	}
};

int main() {
	MergeSort mergeSort;
	vector<int> nums = { 5, 2, 4, 7, 1, 3, 2, 6 };
	cout << "Before sorting: {";
	for (int num : nums)
		cout << num << " ";
	cout<< "}" << endl;

	mergeSort.mergeSort(nums, 0, nums.size() - 1, Outplace);
	cout << "After outplace merging sort: {";
	for (int num : nums)
		cout << num << " ";
	cout << "}" << endl;

	nums = { 5, 2, 4, 7, 1, 3, 2, 6 };
	mergeSort.mergeSort(nums, 0, nums.size() - 1, Inplace);
	cout << "After inplace merging sort: {";
	for (int num : nums)
		cout << num << " ";
	cout << "}" << endl;

	system("pause");
	return 0;
}

/*
Output:
Before sorting: {5 2 4 7 1 3 2 6 }
After outplace merging sort: {1 2 2 3 4 5 6 7 }
After inplace merging sort: {1 2 2 3 4 5 6 7 }
*/
