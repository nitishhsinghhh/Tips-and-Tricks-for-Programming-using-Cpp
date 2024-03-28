// Program to find whether the given number is a prime or not.

#include <iostream>
using namespace std;

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
	cout << "Enter the number: ";
	cin >> num;
	bool prime = oSolution.isPrime(num);
	if (prime)
		cout << num << " is a prime number." << endl;
	else
		cout << num << " is not a prime number." << endl;
	system("pause");

	return 0;
}
