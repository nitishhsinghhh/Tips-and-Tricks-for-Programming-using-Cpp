#include <iostream>
#include <array>
using namespace std;

template<typename T, size_t N>
class Solution {
public:
	void insertionSort(std::array<T, N>& arr) {
		for (size_t i = 1; i < N; ++i) {
			T key = arr[i];
			size_t j = i;

			while (j > 0 && arr[j - 1] > key) {
				arr[j] = arr[j - 1];
				--j;
			}
			arr[j] = key;
		}
	}
};

int main() {
	std::array<int, 6> arr = { 5,8,7,55,34,23 };

	Solution<int, 6> oSolution;
	oSolution.insertionSort(arr);

	for (const auto& element : arr)
		std::cout << element << " ";

	std::cout << std::endl;

	return 0;
}
