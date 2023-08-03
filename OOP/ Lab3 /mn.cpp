// Program to calculate sum of numbers from m to n

#include <iostream>
using namespace std;

void main() {
	int m, n, sum = 0;
	cout << "Enter the first number: ";
	cin >> n;
	cout << "Enter the second number: ";
	cin >> m;
	if (n < m) {
		for (int x = n; x <= m; x++)
			sum += x;
		cout << "The sum of the integers between the two numbers is " << sum << ";" << endl;
	}
	else if (m < n)
		cout << "The sum of the integers between the two numbers is " << sum << ";" << endl;
	else if (m == n) {
		sum = n;
		cout << "The sum is " << sum << endl;
	}

	system("pause");
}
