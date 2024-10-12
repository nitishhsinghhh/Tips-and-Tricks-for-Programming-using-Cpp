// Program to find whether the given number is a prime or not.

#include <iostream>

class Solution {
public:
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
	Solution oSolution;
	int num = 0;
	std::cout << "Enter the number: ";
	std::cin >> num;
	bool prime = oSolution.isPrime(num);
	if (prime)
		std::cout << num << " is a prime number." << std::endl;
	else
		std::cout << num << " is not a prime number." << std::endl;
	system("pause");

	return 0;
}
