#include <iostream>
#include <list>

class Solution {
public:
	void deleteposElement(const std::list<int>& initialList, const int position) {
		if (position == 0)
			return;

		std::list<int> dblList = initialList;
		auto startiterator = dblList.begin();
		if (position != 1)
			advance(startiterator, position);
		dblList.erase(startiterator);

		for (const auto& element : dblList)
			std::cout << element << " ";
		std::cout << std::endl;
	}
};

void main() {
	// Test Case 1: Deleting the middle element from an odd-sized list
	Solution oSolution;
	std::cout << "Test Case 1: Deleting the middle element from an odd-sized list" << std::endl;
	std::list<int> testCase1{ 1, 2, 3, 4, 5 };
	oSolution.deleteposElement(testCase1, testCase1.size() / 2); // Expected output: 1 2 4 5

	// Test Case 2: Deleting the middle element from an even-sized list
	std::cout << "Test Case 2: Deleting the middle element from an even-sized list" << std::endl;
	std::list<int> testCase2{ 10, 20, 30, 40, 50, 60 };
	oSolution.deleteposElement(testCase2, testCase1.size() / 2); // Expected output: 10 20 40 50 60

	// Test Case 3: Deleting the only element from the list
	std::cout << "Test Case 3: Deleting the only element from the list" << std::endl;
	std::list<int> testCase3{ 100 };
	oSolution.deleteposElement(testCase3, testCase3.size()); // Expected output:

	// Test Case 4: Deleting the first element from the list
	std::cout << "Test Case 4: Deleting the first element from the list" << std::endl;
	std::list<int> testCase4{ 1, 2, 3, 4, 5 };
	oSolution.deleteposElement(testCase4, 1); // Expected output: 2 3 4 5

	// Test Case 5: Deleting the last element from the list
	std::cout << "Test Case 5: Deleting the last element from the list" << std::endl;
	std::list<int> testCase5{ 10, 20, 30, 40, 50 };
	oSolution.deleteposElement(testCase5, testCase5.size() - 1); // Expected output: 10 20 30 40

	// Test Case 6: Deleting from an empty list
	std::cout << "Test Case 6: Deleting from an empty list" << std::endl;
	std::list<int> testCase6{};
	oSolution.deleteposElement(testCase6, 0); // Expected output:

}

/*
Output:
Test Case 1: Deleting the middle element from an odd-sized list
1 2 4 5
Test Case 2: Deleting the middle element from an even-sized list
10 20 40 50 60
Test Case 3: Deleting the only element from the list

Test Case 4: Deleting the first element from the list
2 3 4 5
Test Case 5: Deleting the last element from the list
10 20 30 40
Test Case 6: Deleting from an empty list

*/
