#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(std::vector<int>& nums, int search_key) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == search_key) 
			return mid;
		else if (nums[mid] < search_key) 
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return -1;
}

int main() {
	std::vector<int> numbers{ 4, 6, 7, 12, 9, 3, 6, 7 };
	int search_key = 6;

	// Sort the given array before calling binary search
	std::sort(numbers.begin(), numbers.end());

	// Test case 1
	int res = binary_search(numbers, search_key);
	if (res == -1) 
		std::cout << "Element is not found\n";
	else 
		std::cout << "Element has been found at index " << res << "\n";

	// Test case 2
	res = binary_search(numbers, 5);
	if (res == -1) 
		std::cout << "Element is not found\n";
	else 
		std::cout << "Element has been found at index " << res << "\n";

	system("pause");
	return 0;
}
