#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorting {
public:
	static void countingSort(vector<int> &nums, bool isAscending = true) {
		// Find the minimum and maximum values in the input array
		int minVal = *min_element(nums.begin(), nums.end());
		int maxVal = *max_element(nums.begin(), nums.end());

		// Determine the size of the frequency array and allocate memory
		int freqSize = maxVal - minVal + 1 + 1, size = nums.size();
		vector<int> freq(freqSize, 0), sorted(size, 0);

		// Count the frequency of each value in the input array
		for (int ind = 0; ind < size; ind++)
			freq[nums[ind] - minVal]++;

		// Compute the prefix sum of the frequency array, if sorting in ascending order
		if (isAscending)
			for (int ind = 1; ind < freqSize; ind++)
				freq[ind] += freq[ind - 1];
		// Compute the suffix sum of the frequency array, if sorting in descending order
		else
			for (int ind = freqSize - 2; ind >= 0; ind--)
				freq[ind] += freq[ind + 1];

		// Sort the input array using the frequency array
		for (int ind = size - 1; ind >= 0; ind--)
			sorted[freq[nums[ind] - minVal]-- - 1] = nums[ind];

		// Update the input array with the sorted values
		nums = sorted;
	}
};

int main() {
	// Declare an input array and print its initial values
	vector<int> nums = { 2, 5, 3, 0, 2, 3, 0, 3 };
	cout << "Input array: {";
	for (int num : nums)
		cout << num << " ";
	cout<< "}" << endl;

	// Sort the input array in ascending order and print the sorted values
	Sorting::countingSort(nums);
	cout << "Sorted array (ascending): {";
	for (int num : nums)
		cout << num << " ";
	cout << "}" << endl;

	// Sort the input array in descending order and print the sorted values
	Sorting::countingSort(nums, false);
	cout << "Sorted array (descending): {";
	for (int num : nums)
		cout << num << " ";
	cout << "}" << endl;

	system("pause");

	return 0;
}


/*
Output:
Input array: {2 5 3 0 2 3 0 3 }
Sorted array (ascending): {0 0 2 2 3 3 3 5 }
Sorted array (descending): {5 3 3 3 2 2 0 0 }
*/
