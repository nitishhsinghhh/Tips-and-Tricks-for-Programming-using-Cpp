#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int diagonalPrime(std::vector<std::vector<int>>& n) {
		int p = 0;
		for (int i = 0; i < n.size(); ++i)
			p = std::max({ p, isPrime(n[i][i]) * n[i][i],
				isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1] });
		return p;
	}
private:
	bool isPrime(int n) {
		if (n <= 2 || n % 2 == 0)
			return n == 2;
		for (int i = 3; i * i <= n; i += 2)
			if (n % i == 0)
				return false;
		return true;
	}
};

int main() {
	Solution sol;

	// Test Case 1
	std::vector<std::vector<int>> nums1 = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11} };
	std::cout << "Test Case 1:\nInput: [[1, 2, 3], [5, 6, 7], [9, 10, 11]]\nOutput: " << sol.diagonalPrime(nums1) << std::endl;

	// Test Case 2
	std::vector<std::vector<int>> nums2 = { {1, 2, 3}, {5, 17, 7}, {9, 11, 10} };
	std::cout << "\nTest Case 2:\nInput: [[1, 2, 3], [5, 17, 7], [9, 11, 10]]\nOutput: " << sol.diagonalPrime(nums2) << std::endl;

	return 0;
}

/**
Output:
Test Case 1:
Input: [[1, 2, 3], [5, 6, 7], [9, 10, 11]]
Output: 11

Test Case 2:
Input: [[1, 2, 3], [5, 17, 7], [9, 11, 10]]
Output: 17
**/
