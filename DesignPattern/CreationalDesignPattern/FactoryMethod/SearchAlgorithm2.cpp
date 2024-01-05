#include <iostream>
#include <vector>
#include <algorithm>

// Define an enumeration for search algorithms
enum class SearchAlgorithm {
	Linear,
	Binary,
	Interpolation,
	Jump
};

// Define a base class for search algorithms
class SearchAlgorithmBase {
public:
	virtual int search(const std::vector<int>& arr, int target) const = 0;
	virtual ~SearchAlgorithmBase() = default;
};

// Define a derived class for linear search
class LinearSearch : public SearchAlgorithmBase {
private:
	int search(const std::vector<int>& arr, int target) const override {
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] == target) 
				return i;
		return -1;
	}
};

// Define a derived class for binary search
class BinarySearch : public SearchAlgorithmBase {
private:
	int search(const std::vector<int>& arr, int target) const override {
		int left = 0, right = arr.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] == target)
				return mid;
			else if (arr[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
};

// Define a derived class for interpolation search
class InterpolationSearch : public SearchAlgorithmBase {
private:
	int search(const std::vector<int>& arr, int target) const override {
		int left = 0, right = arr.size() - 1;

		// Perform interpolation search
		while (left <= right && target >= arr[left] && target <= arr[right]) {
			int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
			if (arr[pos] == target) 
				return pos; 
			else if (arr[pos] < target) 
				left = pos + 1; 
			else 
				right = pos - 1;
		}

		return -1; // Target not found
	}
};

// Define a derived class for jump search
class JumpSearch : public SearchAlgorithmBase {
public:
	int search(const std::vector<int>& arr, int target) const override {
		int jump = sqrt(arr.size()), left = 0, right = jump - 1;
		while (right < arr.size() && arr[right] < target) {
			left = right;
			right += jump;
		}

		for (int i = left; i <= std::min(right, (int)arr.size() - 1); i++)
			if (arr[i] == target) 
				return i; 
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
		case SearchAlgorithm::Interpolation:
			return std::make_unique<InterpolationSearch>();
		case SearchAlgorithm::Jump:
			return std::make_unique<JumpSearch>();
		default:
			std::cerr << "Invalid search algorithm requested." << std::endl;
			return nullptr;
		}
	}
};

void main() {
	// Define the data to search
	std::vector<int> sortedData{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> unsortedData{ 5, 2, 8, 1, 9, 3, 4, 7, 6, 10 };
	int target = 7;

	// Use the factory to create the desired search 
	auto linearSearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Linear);
	auto binarySearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Binary);
	auto interpolationSearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Interpolation);
	auto jumpSearch = SearchAlgorithmFactory::createSearchAlgorithm(SearchAlgorithm::Jump);

	// Perform searches
	if (linearSearch)
		std::cout << "Linear Search Result: " << linearSearch->search(unsortedData, target) << std::endl;
	if (binarySearch)
		std::cout << "Binary Search Result: " << binarySearch->search(sortedData, target) << std::endl;
	if (interpolationSearch)
		std::cout << "Interpolation Search Result: " << interpolationSearch->search(sortedData, target) << std::endl;
	if (jumpSearch)
		std::cout << "Jump Search Result: " << jumpSearch->search(sortedData, target) << std::endl;
	system("pause");
}
/*
Linear Search Result: 7
Binary Search Result: 6
Interpolation Search Result: 6
Jump Search Result: 6
Press any key to continue . . .
*/
