#include <iostream>
class Solution {
public:
	int compareVersion(std::string version1, std::string version2) {
		int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
		while (i < n1 || j < n2) {
			int num1 = 0, num2 = 0;
			while (i < n1 && version1[i] != '.')
				num1 = num1 * 10 + (version1[i++] - '0');
			while (j < n2 && version2[j] != '.')
				num2 = num2 * 10 + (version2[j++] - '0');
			if (num1 > num2)
				return 1;
			else if (num1 < num2)
				return -1;

			i++;
			j++;
		}
		return 0;
	}
};

void main() {
	Solution solution;

	// Test case 1
	std::string version1 = "1.2.3";
	std::string version2 = "1.2.3";
	int result = solution.compareVersion(version1, version2);
	std::cout << "Test Case 1: " << result << std::endl;
	// Expected output: 0 (versions are equal)

	// Test case 2
	version1 = "1.2.3";
	version2 = "1.2.4";
	result = solution.compareVersion(version1, version2);
	std::cout << "Test Case 2: " << result << std::endl;
	// Expected output: -1 (version1 is smaller)

	// Test case 3
	version1 = "1.2.4";
	version2 = "1.2.3";
	result = solution.compareVersion(version1, version2);
	std::cout << "Test Case 3: " << result << std::endl;
	// Expected output: 1 (version1 is greater)

	// Test case 4
	version1 = "1.0.0";
	version2 = "1";
	result = solution.compareVersion(version1, version2);
	std::cout << "Test Case 4: " << result << std::endl;
	// Expected output: 0 (versions are equal)

	system("pause");
}

/**
* Test Case 1: 0
* Test Case 2: -1
* Test Case 3: 1
* Test Case 4: 0
* Press any key to continue . . .
**/
