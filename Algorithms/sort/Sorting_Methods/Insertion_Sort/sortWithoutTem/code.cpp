#include <iostream>
#include <array>
using namespace std;

class Solution {
public:
	void insertionSort(array<int, 6>& arr) {
		for (size_t i = 1; i < arr.size(); ++i) {
			int key = arr[i];
			size_t j = i;

			while (j > 0 && arr[j - 1] > key) {
				arr[j] = arr[j - 1];
				--j;
			}
			arr[j] = key;
		}
	}
};

void main() {
	std::array<int, 6> arr = { 5,8,7,55,34,23 };
	Solution oSolution;
	oSolution.insertionSort(arr);
	for (const auto& element : arr)
		std::cout << element << " ";
	std::cout << std::endl;
}
