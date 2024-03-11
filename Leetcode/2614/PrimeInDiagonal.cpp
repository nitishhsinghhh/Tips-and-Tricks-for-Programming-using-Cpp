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

using namespace std;

// Paste the Solution class code here

int main() {
	Solution sol;

	// Example 1
	std::vector<std::vector<int>> nums1 = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11} };
	std::cout << "Example 1:\nInput: [[1, 2, 3], [5, 6, 7], [9, 10, 11]]\nOutput: " << sol.diagonalPrime(nums1) << std::endl;

	// Example 2
	vector<vector<int>> nums2 = { {1, 2, 3}, {5, 17, 7}, {9, 11, 10} };
	std::cout << "\nExample 2:\nInput: [[1, 2, 3], [5, 17, 7], [9, 11, 10]]\nOutput: " << sol.diagonalPrime(nums2) << std::endl;

	return 0;
}
