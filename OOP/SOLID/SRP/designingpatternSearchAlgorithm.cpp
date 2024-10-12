#include <iostream>
#include <vector>
#include <algorithm>

// Define an enumeration for search algorithms
enum class SearchAlgorithm {
	Linear,
	Binary
};

// Define a base class for search algorithms
class SearchAlgorithmBase {
public:
	virtual int search(const std::vector<int>& arr, int target) const = 0;
	virtual ~SearchAlgorithmBase() = default;
};

// Define a derived class for linear search
class LinearSearch : public SearchAlgorithmBase {
public:
	int search(const std::vector<int>& arr, int target) const override {
		// Iterate through the vector
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == target) {
				return i; // Target found
			}
		}
		return -1; // Target not found
	}
};

// Define a derived class for binary search
class BinarySearch : public SearchAlgorithmBase {
public:
	int search(const std::vector<int>& arr, int target) const override {
		// Set the left and right indexes
		int left = 0;
		int right = arr.size() - 1;

		// Perform binary search
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] == target) 
				return mid; // Target found
			else if (arr[mid] < target) 
				left = mid + 1; // Discard left half of the array
			else 
				right = mid - 1; // Discard right half of the array
		}

		return -1; // Target not found
	}
};

// Define a factory class for search algorithms
class SearchAlgorithmFactory {
public:
	static std::unique_ptr<SearchAlgorithmBase> createSearchAlgorithm(SearchAlgorithm algorithm) {
		switch (algorithm) {
		case SearchAlgorithm::Linear:
			return std::make_unique<LinearSearch>();
		case SearchAlgorithm::Binary:
			return std::make_unique<BinarySearch>();
		default:
			std::cerr << "Invalid search algorithm requested." << std::endl;
			return nullptr;
		}
	}
};

void main() {
	// Define the data to search
	std::vector<int> sortedData { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> unsortedData { 5, 2, 8, 1, 9, 3, 4, 7, 6, 10 };
	int target = 7;

	// Use the factory to create the desired search algorithm
	auto linearSearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Linear);
	auto binarySearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Binary);

	// Perform searches
	int res; 
	if (linearSearch) {
		int linearResult = linearSearch->search(unsortedData, target);
		cout << "Linear Search Result: " << linearResult << endl;
	}

	if (binarySearch) {
		int binaryResult = binarySearch->search(sortedData, target);
		cout << "Binary Search Result: " << binaryResult << endl;
	}

	system("pause");
}
